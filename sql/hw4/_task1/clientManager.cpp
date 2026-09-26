#include "clientManager.h"

#include <iostream>
#include <tuple>
#include <vector>

clientManager::clientManager(const std::string& connectionString)
    : connection_(std::make_shared<pqxx::connection>(connectionString)) {}

void clientManager::createDatabase(const std::string& adminConnString,
                                   const std::string& dbName) {
    pqxx::connection admin{adminConnString};
    pqxx::nontransaction ntx{admin};

    pqxx::result r = ntx.exec_params(
        "SELECT 1 FROM pg_database WHERE datname = $1;", dbName);

    if (!r.empty()) {
        std::cout << "[SKIP] Database '" << dbName << "' already exists\n";
        return;
    }

    ntx.exec("CREATE DATABASE " + admin.quote_name(dbName));
    std::cout << "[OK] Database '" << dbName << "' created\n";
}

void clientManager::createTables() {
    pqxx::work txn(*connection_);
    txn.exec(R"(
        CREATE TABLE IF NOT EXISTS client (
            id SERIAL PRIMARY KEY,
            first_name VARCHAR(50) NOT NULL,
            last_name  VARCHAR(50) NOT NULL,
            email      VARCHAR(100) UNIQUE NOT NULL
        );
    )");
    txn.exec(R"(
        CREATE TABLE IF NOT EXISTS phone (
            id SERIAL PRIMARY KEY,
            client_id INTEGER NOT NULL REFERENCES client(id) ON DELETE CASCADE,
            phone     VARCHAR(20) NOT NULL
        );
    )");
    txn.commit();
    std::cout << "[OK] Tables created\n";
}

void clientManager::clearTables() {
    pqxx::work txn(*connection_);
    txn.exec("TRUNCATE phone, client RESTART IDENTITY CASCADE;");
    txn.commit();
    std::cout << "[OK] Tables cleared\n";
}

int clientManager::addClient(const std::string& firstName,
                             const std::string& lastName,
                             const std::string& email) {
    pqxx::work txn(*connection_);
    pqxx::result r = txn.exec_params(
        "INSERT INTO client (first_name, last_name, email) "
        "VALUES ($1, $2, $3) RETURNING id;",
        firstName, lastName, email);
    txn.commit();

    int id = r[0][0].as<int>();
    std::cout << "[OK] Client added, id=" << id << "\n";
    return id;
}

void clientManager::addPhone(int clientId, const std::string& phone) {
    pqxx::work txn(*connection_);
    txn.exec_params(
        "INSERT INTO phone (client_id, phone) VALUES ($1, $2);",
        clientId, phone);
    txn.commit();
    std::cout << "[OK] Phone added for client " << clientId << "\n";
}

void clientManager::updateClient(int clientId,
                                 const std::optional<std::string>& firstName,
                                 const std::optional<std::string>& lastName,
                                 const std::optional<std::string>& email) {
    std::string sql = "UPDATE client SET ";
    pqxx::params params;
    int idx = 1;
    bool first = true;

    auto append = [&](const std::string& col, const std::string& val) {
        if (!first) sql += ", ";
        sql += col + " = $" + std::to_string(idx++);
        params.append(val);
        first = false;
    };

    if (firstName) append("first_name", *firstName);
    if (lastName)  append("last_name",  *lastName);
    if (email)     append("email",      *email);

    if (first) {
        std::cout << "[SKIP] Nothing to update\n";
        return;
    }

    sql += " WHERE id = $" + std::to_string(idx) + ";";
    params.append(clientId);

    pqxx::work txn(*connection_);
    txn.exec_params(sql, params);
    txn.commit();
    std::cout << "[OK] Client " << clientId << " updated\n";
}

void clientManager::deletePhone(int clientId, const std::string& phone) {
    pqxx::work txn(*connection_);
    pqxx::result r = txn.exec_params(
        "DELETE FROM phone WHERE client_id = $1 AND phone = $2;",
        clientId, phone);
    txn.commit();
    std::cout << "[OK] Deleted " << r.affected_rows() << " phone(s)\n";
}

void clientManager::deleteClient(int clientId) {
    pqxx::work txn(*connection_);
    pqxx::result r = txn.exec_params(
        "DELETE FROM client WHERE id = $1;", clientId);
    txn.commit();
    std::cout << "[OK] Deleted " << r.affected_rows() << " client(s)\n";
}

void clientManager::findClient(const std::string& query) {
    std::vector<std::tuple<int, std::string, std::string, std::string>> clients;

    {
        pqxx::work txn(*connection_);
        pqxx::result r = txn.exec_params(R"(
            SELECT DISTINCT c.id, c.first_name, c.last_name, c.email
            FROM client c
            LEFT JOIN phone p ON p.client_id = c.id
            WHERE c.first_name ILIKE $1
               OR c.last_name  ILIKE $1
               OR c.email      ILIKE $1
               OR p.phone      ILIKE $1;
        )", "%" + query + "%");

        for (const auto& row : r) {
            clients.emplace_back(
                row["id"].as<int>(),
                row["first_name"].as<std::string>(),
                row["last_name"].as<std::string>(),
                row["email"].as<std::string>());
        }
        txn.commit();
    }

    if (clients.empty()) {
        std::cout << "[NOT FOUND] No clients matching: " << query << "\n";
        return;
    }

    std::cout << "[FOUND] " << clients.size() << " client(s):\n";
    for (const auto& [id, first, last, email] : clients) {
        std::cout << "  ID=" << id
                  << " | " << first << " " << last
                  << " | " << email << "\n";
        printPhones(id);
    }
}

void clientManager::printPhones(int clientId) {
    pqxx::work txn(*connection_);
    pqxx::result r = txn.exec_params(
        "SELECT phone FROM phone WHERE client_id = $1 ORDER BY id;",
        clientId);

    if (r.empty()) {
        std::cout << "    (no phones)\n";
        return;
    }
    for (const auto& row : r) {
        std::cout << "    phone: " << row["phone"].as<std::string>() << "\n";
    }
}
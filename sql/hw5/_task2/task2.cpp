#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>

#include <iostream>
#include <string>
#include <libpq-fe.h>

#include "publisher.h"
#include "book.h"
#include "shop.h"
#include "stock.h"
#include "sale.h"


void fillData(Wt::Dbo::Session& session) {
    Wt::Dbo::Transaction t(session);

    // Издатели
    auto pub1 = session.add(std::make_unique<publisher>());
    pub1.modify()->name = "Питер";

    auto pub2 = session.add(std::make_unique<publisher>());
    pub2.modify()->name = "Эксмо";

    auto pub3 = session.add(std::make_unique<publisher>());
    pub3.modify()->name = "АСТ";

    // Книги
    auto b1 = session.add(std::make_unique<book>());
    b1.modify()->title      = "Война и мир";
    b1.modify()->publisher_ = pub1;

    auto b2 = session.add(std::make_unique<book>());
    b2.modify()->title      = "Преступление и наказание";
    b2.modify()->publisher_ = pub1;

    auto b3 = session.add(std::make_unique<book>());
    b3.modify()->title      = "Мастер и Маргарита";
    b3.modify()->publisher_ = pub2;

    auto b4 = session.add(std::make_unique<book>());
    b4.modify()->title      = "Тихий Дон";
    b4.modify()->publisher_ = pub3;

    // Магазины
    auto s1 = session.add(std::make_unique<shop>());
    s1.modify()->name = "Москва, Тверская";

    auto s2 = session.add(std::make_unique<shop>());
    s2.modify()->name = "Санкт-Петербург, Невский";

    auto s3 = session.add(std::make_unique<shop>());
    s3.modify()->name = "Казань, Баумана";

    // Склад
    auto st1 = session.add(std::make_unique<stock>());
    st1.modify()->book_ = b1;
    st1.modify()->shop_ = s1;
    st1.modify()->count = 10;

    auto st2 = session.add(std::make_unique<stock>());
    st2.modify()->book_ = b2;
    st2.modify()->shop_ = s2;
    st2.modify()->count = 5;

    auto st3 = session.add(std::make_unique<stock>());
    st3.modify()->book_ = b1;
    st3.modify()->shop_ = s2;
    st3.modify()->count = 3;

    auto st4 = session.add(std::make_unique<stock>());
    st4.modify()->book_ = b3;
    st4.modify()->shop_ = s3;
    st4.modify()->count = 7;

    auto st5 = session.add(std::make_unique<stock>());
    st5.modify()->book_ = b4;
    st5.modify()->shop_ = s1;
    st5.modify()->count = 4;

    // Продажи
    auto sl1 = session.add(std::make_unique<sale>());
    sl1.modify()->stock_    = st1;
    sl1.modify()->price     = 1500;
    sl1.modify()->date_sale = "2025-01-10";
    sl1.modify()->count     = 2;

    auto sl2 = session.add(std::make_unique<sale>());
    sl2.modify()->stock_    = st3;
    sl2.modify()->price     = 1600;
    sl2.modify()->date_sale = "2025-01-12";
    sl2.modify()->count     = 1;

    t.commit();
    std::cout << "[OK] Тестовые данные добавлены\n";
}

void showShopsForPublisher(Wt::Dbo::Session& session,
                           const std::string& publisherQuery) {
    Wt::Dbo::Transaction t(session);

    Wt::Dbo::ptr<publisher> pub;

    try {
        int id = std::stoi(publisherQuery);
        pub = session.find<publisher>().where("id = ?").bind(id);
    } catch (const std::exception&) {
        // не число — ищем по имени
    }

    if (!pub) {
        pub = session.find<publisher>()
                     .where("name = ?")
                     .bind(publisherQuery);
    }

    if (!pub) {
        std::cout << "[NOT FOUND] Publisher '" << publisherQuery
                  << "' not found\n";
        return;
    }

    std::cout << "\nPublisher: id=" << pub.id()
              << ", name=\"" << pub->name << "\"\n";
    std::cout << "Shops selling its books:\n";

auto query = session.find<shop>()
    .where("shop.id IN ("
           "  SELECT s.id_shop_id "
           "  FROM stock s "
           "  JOIN book b ON b.id = s.id_book_id "
           "  WHERE b.id_publisher_id = ?"
           ")")
    .bind(pub.id());

    bool found = false;
    for (const auto& sh : query.resultList()) {
        std::cout << "  id=" << sh.id()
                  << ", name=\"" << sh->name << "\"\n";
        found = true;
    }

    if (!found) {
        std::cout << "  (no shops found)\n";
    }
}


int main() {
    const std::string dbName = "bookstore";

    const std::string adminConn =
        "host=localhost port=5432 dbname=postgres "
        "user=postgres password=postgres";

    const std::string targetConn =
        "host=localhost port=5432 dbname=" + dbName + " "
        "user=postgres password=postgres";

    try {
        {
            PGconn* conn = PQconnectdb(adminConn.c_str());
            if (PQstatus(conn) != CONNECTION_OK) {
                std::cerr << "Admin connect failed: " << PQerrorMessage(conn) << "\n";
                PQfinish(conn);
                return 1;
            }
            std::string checkSql =
                "SELECT 1 FROM pg_database WHERE datname = '" + dbName + "';";
            PGresult* res = PQexec(conn, checkSql.c_str());
            bool exists = (PQntuples(res) > 0);
            PQclear(res);

            if (!exists) {
                std::string createSql = "CREATE DATABASE " + dbName + ";";
                PGresult* cr = PQexec(conn, createSql.c_str());
                if (PQresultStatus(cr) != PGRES_COMMAND_OK) {
                    std::cerr << "CREATE DATABASE failed: "
                              << PQerrorMessage(conn) << "\n";
                    PQclear(cr);
                    PQfinish(conn);
                    return 1;
                }
                PQclear(cr);
                std::cout << "[OK] Database '" << dbName << "' created\n";
            } else {
                std::cout << "[SKIP] Database '" << dbName << "' already exists\n";
            }
            PQfinish(conn);
        }

        auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(targetConn);
        Wt::Dbo::Session session;
        session.setConnection(std::move(postgres));

        session.mapClass<publisher>("publisher");
        session.mapClass<book>     ("book");
        session.mapClass<shop>     ("shop");
        session.mapClass<stock>    ("stock");
        session.mapClass<sale>     ("sale");

        try {
            session.dropTables();
            std::cout << "[OK] Old tables dropped\n";
        } catch (const std::exception& e) {
            std::cout << "[SKIP] No tables to drop (" << e.what() << ")\n";
        }

        session.createTables();
        std::cout << "[OK] Tables created\n";

        {
            Wt::Dbo::Transaction t(session);
            int count = session.query<int>("SELECT COUNT(*) FROM publisher").resultValue();
            t.commit();
            if (count == 0) {
                fillData(session);
            } else {
                std::cout << "[SKIP] Data already present\n";
            }
        }

        std::cout << "\nEnter publisher name or id: ";
        std::string input;
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Empty input — exit\n";
            return 0;
        }

        showShopsForPublisher(session, input);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
#pragma once

#include <pqxx/pqxx>
#include <string>
#include <vector>
#include <tuple>

class clientManager {
public:
    explicit clientManager(const std::string& connectionString);

    static void createDatabase(const std::string& adminConnString,
                               const std::string& dbName);

    void createTables();
    void clearTables();

    int addClient(const std::string& firstName,
                  const std::string& lastName,
                  const std::string& email);

    void addPhone(int clientId, const std::string& phone);

    void updateClient(int clientId,
                      const std::optional<std::string>& firstName = std::nullopt,
                      const std::optional<std::string>& lastName  = std::nullopt,
                      const std::optional<std::string>& email     = std::nullopt);

    void deletePhone(int clientId, const std::string& phone);
    void deleteClient(int clientId);
    std::vector<std::tuple<int, std::string, std::string, std::string>> findClient(const std::string& query);
    void printPhones(int clientId);

private:
    std::shared_ptr<pqxx::connection> connection_;
};
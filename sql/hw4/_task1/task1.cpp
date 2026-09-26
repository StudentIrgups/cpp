#include "clientManager.h"

#include <iostream>

int main() {
    try {
        clientManager::createDatabase(
            "host=localhost port=5432 dbname=postgres "
            "user=postgres password=postgres",
            "clients_db");

        clientManager manager(
            "host=localhost port=5432 dbname=clients_db "
            "user=postgres password=postgres");

        manager.createTables();
        manager.clearTables();

        int alice = manager.addClient("Alice", "Ivanova", "alice@mail.ru");
        int bob   = manager.addClient("Bob",   "Petrov",  "bob@mail.ru");
        int carol = manager.addClient("Carol", "Sidorova","carol@mail.ru");

        manager.addPhone(alice, "+7-999-111-22-33");
        manager.addPhone(alice, "+7-999-444-55-66");
        manager.addPhone(bob,   "+7-888-777-66-55");

        manager.updateClient(bob, std::nullopt, std::nullopt, "bob.new@mail.ru");
        manager.deletePhone(alice, "+7-999-111-22-33");

        std::cout << "\n--- Search by name 'alice' ---\n";
        manager.findClient("alice");

        std::cout << "\n--- Search by phone '888' ---\n";
        manager.findClient("888");

        std::cout << "\n--- Search by email 'carol' ---\n";
        manager.findClient("carol");

        manager.deleteClient(carol);
        manager.deleteClient(alice);

        std::cout << "\n--- Search after deletion ---\n";
        manager.findClient("alice");

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
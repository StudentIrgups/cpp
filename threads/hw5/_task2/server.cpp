#include "server.h"

Server::Server() {
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);      
    if (sock < 0) {
        cout << "Ошибка создания сокета: " << strerror(errno) << std::endl;
        return;
    }      
    server_addr.sin_family = AF_INET;    
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port   = htons(server_port);

    int err_s = bind(sock, (sockaddr*)&server_addr,sizeof(server_addr));

    if (err_s < 0) {
        cout << "Сокет не создан" << std::endl;
        close(sock);
    }
}

Server::~Server(){
    close(sock);
}

void Server::recieve_and_answer() {    
    cout << "Ждём данные от клиента ..." << std::endl;

    if (listen(sock, BACKLOG) < 0) {
        std::cerr << "Ошибка listen: " << strerror(errno) << std::endl;
        return;
    }

    while (true) {   
        sockaddr_in client_addr{};

        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(sock, (sockaddr*)&client_addr, &client_len);

        if (client_sock < 0) {
            std::cerr << "Ошибка accept: " << strerror(errno) << std::endl;
            continue;
        }
        std::thread(clithread, client_sock, client_addr).detach();
    }

}

void Server::clithread(int client_sock, sockaddr_in client_addr) {
    char buffer[32] = {0};
    char client_ip[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
    cout << "Клиент подключён: " << client_ip << ":" << ntohs(client_addr.sin_port) << std::endl;
    ssize_t received;


    while (true) {
        received = recv(client_sock, buffer, 32, 0);
        if (received > 0) {
            buffer[received] = '\0';
            cout << "Получено от клиента:" << buffer << std::endl;

            std::string response = "Echo: " + std::string(buffer);
            send(client_sock, response.c_str(), response.size(), 0);
            
            size_t id_num = std::hash<std::thread::id>{}(std::this_thread::get_id());
            std::string id_str = std::to_string(id_num);

            cout << "Отправлено клиенту: " << response << id_str << std::endl;

        } else if (received == 0) {
            std::cout << "Клиент закрыл соединение" << std::endl;
            break;
        } else {
            std::cout << "Ошибка получения данныз" << std::endl;
            break;
        }
    }
    shutdown(client_sock, SHUT_RDWR);
    close(client_sock);
}


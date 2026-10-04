#pragma once
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

    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(sock, (sockaddr*)&client_addr, &client_len);

    if (client_sock < 0) {
        std::cerr << "Ошибка accept: " << strerror(errno) << std::endl;
        return;
    }

    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
    cout << "Клиент подключён: " << client_ip << ":" << ntohs(client_addr.sin_port) << std::endl;

    ssize_t received = recv(client_sock, buffer, 32, 0);
    if (received > 0) {
        buffer[received] = '\0';
        cout << "Получено от клиента:" << buffer << std::endl;

        std::string response = "Echo: " + std::string(buffer);
        send(client_sock, response.c_str(), response.size(), 0);
        cout << "Отправлено клиенту: " << response << std::endl;
    }
    close(client_sock);
}
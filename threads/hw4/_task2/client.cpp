#include "client.h"

Client::Client() {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Ошибка socket: " << strerror(errno) << std::endl;
        return;        
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port   = htons(server_port);

    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        std::cerr << "Неверный адрес: " << server_ip << std::endl;
        close(sock);
        return;
    }    

    if (connect(sock, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Ошибка connect: " << strerror(errno) << std::endl;
        close(sock);
        return;
    }
}

void Client::send_data() {
    std::cout << "Подключено к " << server_ip << ":" << server_port << std::endl;
    int pckg = 0;
    while (++pckg < 30) {
        std::ostringstream oss;
        oss << "Пакет " << pckg << "client num: ";
        std::string message = oss.str();
        send(sock, message.c_str(), message.size(), 0);

        char buffer[32] = {0};
        
        ssize_t received = recv(sock, buffer, sizeof(buffer), 0);
        if (received > 0) {
            buffer[received] = '\0';
            std::cout << "Ответ сервера: " << buffer << std::endl;
        } else if (received == 0) {
            std::cout << "Сервер закрыл соединение" << std::endl;
        } else {
            std::cerr << "Ошибка recv: " << strerror(errno) << std::endl;
        }
        sleep(10);        
    }
    shutdown(sock, SHUT_RDWR);
}

Client::~Client() {
    close(sock);
}

#pragma once
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

class Client {
    private:
        const char* server_ip = "127.0.0.1";
        const int server_port = 50001;
        int sock = 0;
        sockaddr_in server_addr{};
    public:
        Client();
        void send_data();
        ~Client();
};
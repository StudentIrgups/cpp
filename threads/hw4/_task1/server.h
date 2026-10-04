#pragma once
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
using std::cout;

class Server {
    private:
        int server_port = 50001;
        int sock;
        sockaddr_in server_addr{}, client_addr{};
        char* buffer = new char[32];
        static constexpr int BACKLOG = 5;
    public:
    Server();
    ~Server();
    void recieve_and_answer();
};
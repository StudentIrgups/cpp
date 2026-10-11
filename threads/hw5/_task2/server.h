#pragma once
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <future>
#include <vector>
#include <sstream>
using std::cout;

class Server {
    private:
        int server_port = 50001;
        int sock;
        sockaddr_in server_addr{};        
        static constexpr int BACKLOG = 5;
        int client_count = 0;
    public:
    Server();
    ~Server();
    void recieve_and_answer();
    static void clithread(int client_sock, sockaddr_in client_addr);
};
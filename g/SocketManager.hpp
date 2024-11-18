#pragma once

#include "ISocketManager.hpp"

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

using namespace std;
class SocketManager : public ISocketManager {

public:
    SocketManager(string host_ip, int host_port)
    : server_ip(host_ip), port(host_port), clientSocket(-1) {
        clientSocket = socket(AF_INET, SOCK_STREAM, 0);

        if (clientSocket < 0) {
            throw std::runtime_error("Failed to create socket!");
        }
        
        if (connectSocket() < 0) {
            throw std::runtime_error("Failed to connect to the server!");
        }
    };
    int connectSocket() override;
    
    ~SocketManager() {
        if (clientSocket >= 0) {
            close(clientSocket);
        }
    }

private:
    string server_ip;
    int port;
    int clientSocket;
};
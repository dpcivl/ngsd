#include "SocketManager.hpp"

int SocketManager::connectSocket() {
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);

    // IP 주소 변환
    if (inet_pton(AF_INET, server_ip.c_str(), &serverAddress.sin_addr) <= 0) {
        std::cerr << "Invalid address or address not supported!" << std::endl;
        return -1;
    }

    // 서버 연결
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Connection failed!" << std::endl;
        return -1;
    }

    std::cout << "Connected to server at " << server_ip << ":" << port << std::endl;
    return 0; // 연결 성공
}
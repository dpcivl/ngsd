#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class SocketClient {
private:
    int clientSocket;
    sockaddr_in serverAddress;

public:
    // 생성자: 소켓 생성 및 기본 설정
    SocketClient(const std::string& serverIP, int serverPort) {
        clientSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (clientSocket < 0) {
            throw std::runtime_error("Socket creation failed!");
        }

        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(serverPort);

        if (inet_pton(AF_INET, serverIP.c_str(), &serverAddress.sin_addr) <= 0) {
            throw std::runtime_error("Invalid address or address not supported!");
        }
    }

    // 소멸자: 소켓 닫기
    ~SocketClient() {
        close(clientSocket);
    }

    // 서버에 연결
    void connectToServer() {
        if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
            throw std::runtime_error("Connection to server failed!");
        }
        std::cout << "Connected to server successfully." << std::endl;
    }

    // 데이터 전송
    void sendData(const std::string& data) {
        if (send(clientSocket, data.c_str(), data.size(), 0) < 0) {
            throw std::runtime_error("Failed to send data!");
        }
        std::cout << "Data sent: " << data << std::endl;
    }

    // 데이터 수신
    std::string receiveData() {
        char buffer[1024] = {0};
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (bytesRead < 0) {
            throw std::runtime_error("Failed to receive data!");
        }
        return std::string(buffer, bytesRead);
    }
};

int main() {
    try {
        // 클라이언트 생성
        SocketClient client("127.0.0.1", 8080);

        // 서버 연결
        client.connectToServer();

        // 데이터 전송
        client.sendData("Hello, server!");

        // 데이터 수신
        std::string response = client.receiveData();
        std::cout << "Server response: " << response << std::endl;

    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}

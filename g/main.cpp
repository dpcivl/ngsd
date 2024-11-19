#include "SocketManager.hpp"

int main() {
    SocketManager socket_manager("192.168.0.12", 8080);

    socket_manager.connectSocket();
}
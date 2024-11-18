#include <gtest/gtest.h>

class SocketManager {

public:
    int connectSocket(std::string server_ip, int port) {
        return 1;
    }
};

TEST(SocketTest, SocketConnectTest) {
    int res;
    std::string server_ip("192.168.0.59");
    int port;

    SocketManager socket_manager;
    res = socket_manager.connectSocket(server_ip, port);

    ASSERT_EQ(res, 1);
}
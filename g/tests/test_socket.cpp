#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../SocketManager.hpp"

class MockSocketManager : public ISocketManager {
public:
    MOCK_METHOD(int, connectSocket, (), (override));
    MOCK_METHOD(int, sendToSocket, (const char* test_msg), (override));
};

using ::testing::Return;

TEST(SocketTest, SocketConnectTest) {
    MockSocketManager mockSocketManager;

    // Mock 동작 설정: connectSocket 호출 시 1 반환
    EXPECT_CALL(mockSocketManager, connectSocket())
        .Times(1)
        .WillOnce(Return(1));

    // 실제 호출
    int res = mockSocketManager.connectSocket();

    // 결과 검증
    ASSERT_EQ(res, 1);
}

TEST(SocketTest, SocketSendTest) {
    MockSocketManager mockSocketManager;
    const char* test_msg = "Hello, server!";

    EXPECT_CALL(mockSocketManager, sendToSocket(test_msg))
        .Times(1)
        .WillOnce(Return(1));

    int res = mockSocketManager.sendToSocket(test_msg);

    ASSERT_EQ(res, 1);
}
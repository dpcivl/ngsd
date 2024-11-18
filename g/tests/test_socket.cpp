#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../SocketManager.hpp"

class MockSocketManager : public ISocketManager {
public:
    MOCK_METHOD(int, connectSocket, (), (override));
};

using ::testing::Return;

TEST(SocketTest, SocketClientCreateTest) {

}
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
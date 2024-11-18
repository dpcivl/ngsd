cmake_minimum_required(VERSION 3.10)
project(SocketTest)

# 컴파일러 강제 지정
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

# GMock 및 GTest 헤더 경로 추가
include_directories(/usr/local/include)

# 테스트 실행 파일 생성
add_executable(SocketTest tests/test_socket.cpp)

# GMock 및 GTest 라이브러리 링크
target_link_libraries(SocketTest
    /usr/local/lib/libgmock.a
    /usr/local/lib/libgmock_main.a
    /usr/local/lib/libgtest.a
    /usr/local/lib/libgtest_main.a
    pthread
)

add_executable(SocketApp SocketManager.cpp main.cpp)
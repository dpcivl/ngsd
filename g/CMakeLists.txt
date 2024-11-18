cmake_minimum_required(VERSION 3.10)
project(project_g)

# 컴파일러 강제 지정
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

# Google Test 라이브러리 사용
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 테스트 파일
add_executable(SocketTest tests/test_socket.cpp)
target_link_libraries(SocketTest ${GTEST_BOTH_LIBRARIES} pthread)
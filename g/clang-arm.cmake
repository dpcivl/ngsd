set(CMAKE_SYSTEM_NAME Linux)          # 타겟 시스템 이름 (예: Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)       # 타겟 아키텍처 (예: arm)

# 크로스 컴파일러 설정
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_ASM_COMPILER clang)

# 크로스 컴파일러에 타겟 지정
set(CMAKE_C_FLAGS "--target=arm-linux-gnueabihf")
set(CMAKE_CXX_FLAGS "--target=arm-linux-gnueabihf")

# # sysroot 설정
# set(CMAKE_SYSROOT raspberrypi-sysroot)

# # 컴파일 플래그에 sysroot 포함
# set(CMAKE_C_FLAGS "--sysroot=${CMAKE_SYSROOT}")
# set(CMAKE_CXX_FLAGS "--sysroot=${CMAKE_SYSROOT}")
# set(CMAKE_EXE_LINKER_FLAGS "--sysroot=${CMAKE_SYSROOT}")

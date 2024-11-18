#pragma once
#include <string>

class ISocketManager {
public:
    virtual ~ISocketManager() = default;

    virtual int connectSocket() = 0;
};
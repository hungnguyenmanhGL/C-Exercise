#pragma once
#include <string>
#include <exception>
using namespace std;

class FullNameException :
    public exception
{
private:
    string msg;

public:
    FullNameException(const string msg) : msg(msg) {}

    const char* what() const noexcept {
        return msg.c_str();
    }
};


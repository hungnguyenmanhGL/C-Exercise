#pragma once
#include <string>
#include <exception>
using namespace std;

class EmailException : public exception
{
private:
    string msg;

public:
    EmailException(const string msg) : msg(msg) {}

    const char* what() const noexcept {
        return msg.c_str();
    }
};


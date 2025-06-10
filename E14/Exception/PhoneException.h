#pragma once
#include <string>
#include <exception>
using namespace std;
class PhoneException : public exception
{
private:
	string msg;

public:
    PhoneException(const string msg) : msg(msg) {}

    // Override what() method, marked noexcept for modern C++
    const char* what() const noexcept {
        return msg.c_str();
    }
};


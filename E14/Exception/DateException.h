#pragma once
#include <exception>
#include <string>
using namespace std;

class DateException : public exception {
private:
    string msg;

public:
    DateException(const string msg) : msg(msg) {}

    // Override what() method, marked noexcept for modern C++
    const char* what() const noexcept {
        return msg.c_str();
    }
};
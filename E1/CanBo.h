#pragma once
#include <string>
#include <stdio.h>
#include <unordered_map>
using namespace std;

static enum Gender { MALE, FEMALE, OTHER };

static unordered_map<Gender, string> genderMap{
    {MALE, "Male"},
    {FEMALE, "Female"},
    {OTHER, "Other"}
};

class CanBo
{
    protected:
        string firstName;
        string lastName;
        int age;
        Gender gender;
        string address;

    public:
        string GetFirstName() const;

        string GetLastName() const;

        virtual void ShowInfo();

        CanBo() {}

        CanBo(string firstName, string lastName, int age, Gender gender, string address);

        ~CanBo() {}
};



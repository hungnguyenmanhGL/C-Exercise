#include <iostream>
#include "Manager.h"

const string path = "Input/data.txt";

int main()
{
    Manager manager;
    manager.ReadFromFile(path);
    return 0;
}

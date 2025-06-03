#include "Worker.h"

Worker::Worker(string firstName, string lastName, int age, Gender gender, string address, int level) 
    : Officer(firstName, lastName, age, gender, address) {
    if (level < 1 || level > 10) {
        std::cout << "[CongNhan] CongNhan's level must be between 1 and 10. Level will be 1 by default" << endl;
        this->level = 1;
    }
    else this->level = level;
}

void Worker::ShowInfo() {
    Officer::ShowInfo();
    printf("Level: %d\n", level);
}

bool Worker::IsLevelValid(int level) {
    return level >= 1 && level <= 10;
}
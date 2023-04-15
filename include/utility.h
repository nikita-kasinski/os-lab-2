#pragma once
#include <cstdlib>

class Utility
{
private:

public:
    static size_t getMinimumIndexWithSleep(const int* array, size_t size);
    static size_t getMaximumIndexWithSleep(const int* array, size_t size);
    static size_t getAverageWithSleep(const int* array, size_t size);
}
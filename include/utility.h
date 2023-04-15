#pragma once
#include <cstdlib>

class Utility
{
private:

public:

    // returns -1 if size is zero
    static size_t getMinimumIndexWithSleep(const int* array, size_t size);

    // returns -1 if size is zero
    static size_t getMaximumIndexWithSleep(const int* array, size_t size);

    // returns -1 if size is zero
    static size_t getAverageWithSleep(const int* array, size_t size);
};
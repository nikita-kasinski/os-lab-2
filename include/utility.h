#pragma once
#include <cstdlib>

class Utility
{
private:
    static constexpr size_t minSleep = 7;
    static constexpr size_t maxSleep = minSleep;
    static constexpr size_t avgSleep = 12;

public:

    // returns -1 if size is zero
    static size_t getMinimumIndexWithSleep(const int* array, size_t size);

    // returns -1 if size is zero
    static size_t getMaximumIndexWithSleep(const int* array, size_t size);

    // sets ok to false when size is zero, returns 0 in such case
    static double getAverageWithSleep(const int* array, size_t size, bool& ok);
};
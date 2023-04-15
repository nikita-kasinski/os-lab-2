#include <windows.h>
#include "utility.h"

size_t Utility::getMinimumIndexWithSleep(const int* array, size_t size)
{
    if (size == 0)
    {
        return -1;
    }
    size_t minIndex = 0;
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] < array[minIndex])
        {
            minIndex = i;
            Sleep(Utility::minSleep);
        }
    }

    return minIndex;
}

size_t Utility::getMaximumIndexWithSleep(const int* array, size_t size)
{
    if (size == 0)
    {
        return -1;
    }
    size_t maxIndex = 0;
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] > array[maxIndex])
        {
            maxIndex = i;
            Sleep(Utility::maxSleep);
        }
    }

    return maxIndex;
}

double Utility::getAverageWithSleep(const int* array, size_t size, bool& ok)
{
    if (size == 0)
    {
        ok = false;
        return 0;
    }

    ok = true;
    int sum = 0;
    for (size_t i = 0; i < size; ++i)
    {
        sum += array[i];
        Sleep(Utility::avgSleep);
    }

    double ans = sum / static_cast<double>(size);

    return ans;
}
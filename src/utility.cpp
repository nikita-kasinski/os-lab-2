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
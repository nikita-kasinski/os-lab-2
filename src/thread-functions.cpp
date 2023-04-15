// author: Nikita Kasinski
#include <windows.h>
#include <iostream>
#include "arg-struct.h"
#include "utility.h"

DWORD WINAPI min_max(LPVOID args)
{
    minmax_args *args_pointer = (minmax_args *)args;
    CRITICAL_SECTION *iocs = args_pointer->iocs;

    args_pointer->indexMin = Utility::getMinimumIndexWithSleep(args_pointer->array, args_pointer->size);
    args_pointer->indexMax = Utility::getMaximumIndexWithSleep(args_pointer->array, args_pointer->size);

    if (args_pointer->indexMin == -1 || args_pointer->indexMax == -1)
    {
        EnterCriticalSection(iocs);
        std::cerr << "Array is empty. Exit thread minmax\n";
        LeaveCriticalSection(iocs);
        ExitThread(1);
    }

    int min = args_pointer->array[args_pointer->indexMin];
    int max = args_pointer->array[args_pointer->indexMax];

    EnterCriticalSection(iocs);
    std::cout << "Minimum : " << min << "\n";
    std::cout << "Maximum : " << max << "\n";
    LeaveCriticalSection(iocs);
}

DWORD WINAPI average(LPVOID args)
{
    average_args *args_pointer = (average_args *)args;
    CRITICAL_SECTION *iocs = args_pointer->iocs;

    bool ok;
    double real_average = Utility::getAverageWithSleep(args_pointer->array, args_pointer->size, ok);

    if (!ok)
    {
        EnterCriticalSection(iocs);
        std::cerr << "Array is empty. Exit thread average\n";
        LeaveCriticalSection(iocs);
        ExitThread(1);
    }


    args_pointer->average = static_cast<int>(real_average + 0.5F);
    int average = args_pointer->average;

    EnterCriticalSection(iocs);
    std::cout << "Average : " << real_average << "\n";
    std::cout << "Since source array is of integer type, average will be rounded to " << average << "\n";
    LeaveCriticalSection(iocs);
}
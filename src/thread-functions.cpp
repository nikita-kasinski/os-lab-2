//author: Nikita Kasinski
#include <windows.h>
#include <vector>
#include <iostream>
#include "arg-struct.h"

DWORD WINAPI min_max(LPVOID args)
{
    minmax_args *args_pointer = (minmax_args*)args;
    if (args_pointer -> size == 0)
    {
        std::cerr << "Array is empty. Exit thread\n";
        ExitThread(1);
    }
    else
    {
        int *array = args_pointer->array;
        const size_t size = args_pointer->size;
        int **min = &args_pointer->min;
        int **max = &args_pointer->max;
        *min = &array[0];
        *max = &array[0];
        for (size_t i = 0; i < size; ++i)
        {
            if (**min > array[i])
            {
                *min = &array[i];
                Sleep(7);
            }
            if (**max < array[i])
            {
                *max = &array[i];
                Sleep(7);
            }
        }
        std::cout << "Minimum : " << **min << "\n";
        std::cout << "Maximum : " << **max << "\n";
    }
}

DWORD WINAPI average(LPVOID args)
{
    average_args *args_pointer = (average_args*)args;
    if (args_pointer -> size == 0)
    {
        std::cerr << "Array is empty. Exit thread\n";
        ExitThread(1);
    }
    else
    {
        int *array = args_pointer->array;
        const size_t size = args_pointer->size;
        int *average = &args_pointer->average;
        int sum = 0;
        for (size_t i = 0; i < size; ++i)
        {
            sum += array[i];
        }
        double real_average = sum / (double)size;
        *average = (real_average + 0.5F);
        std::cout << "Average : " << real_average << "\n";
        std::cout << "Since source array is of integer type it will be rounded to " << *average << "\n";
    }
}
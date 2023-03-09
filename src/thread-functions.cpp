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
    }

}
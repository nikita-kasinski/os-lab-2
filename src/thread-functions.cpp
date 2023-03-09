//author: Nikita Kasinski
#include <windows.h>
#include <vector>
#include <iostream>
#include "arg-struct.h"

DWORD WINAPI min_max(LPVOID args)
{
    arg_struct *args_pointer = (arg_struct*)args;
    if (args_pointer -> size == 0)
    {
        std::cerr << "Array is empty. Exit thread\n";
        ExitThread(1);
    }
    else
    {
        int *array = args_pointer->array;
        const size_t size = args_pointer->size;
        args_pointer->return_values = new int*[2];
        args_pointer->return_size = 2;
        int **rarray = args_pointer->return_values;
        const int rsize = args_pointer->return_size;
        rarray[0] = &array[0]; //min
        rarray[1] = &array[0]; //max
        for (size_t i = 0; i < size; ++i)
        {
            if (*rarray[0] > array[i])
            {
                rarray[0] = &array[i];
                Sleep(7);
            }
            if (*rarray[1] < array[i])
            {
                rarray[1] = &array[i];
                Sleep(7);
            }
        }
    }

}
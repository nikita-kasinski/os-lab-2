//author: Nikita Kasinski
#pragma once

#include <cstdio>

class arg_struct
{
public:
    int* array;
    size_t size;
    int** return_values = nullptr;
    int return_size;
    ~arg_struct()
    {
        delete[] return_values;
    }
};
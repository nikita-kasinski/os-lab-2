//author: Nikita Kasinski
#pragma once

#include <cstdio>

struct arg_struct
{
    const int* array;
    const size_t* size;
    int* return_values;
    int return_size;
};
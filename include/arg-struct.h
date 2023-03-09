//author: Nikita Kasinski
#pragma once

#include <cstdio>

class minmax_args
{
public:
    int* array;
    size_t size;
    int* return_values[2] = {nullptr};
    int return_size = 0;
};

class average_args
{
public:
    int* array;
    size_t size;
    int average;
};
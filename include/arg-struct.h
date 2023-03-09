// author: Nikita Kasinski
#pragma once

#include <cstdio>

class minmax_args
{
public:
    int *array;
    size_t size;
    int *min, *max;
};

class average_args
{
public:
    int *array;
    size_t size;
    int average;
};
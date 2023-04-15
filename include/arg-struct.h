// author: Nikita Kasinski
#pragma once

class minmax_args
{
public:
    const int *array;
    size_t size;
    size_t indexMax, indexMin;
};

class average_args
{
public:
    const int *array;
    size_t size;
    int average;
};
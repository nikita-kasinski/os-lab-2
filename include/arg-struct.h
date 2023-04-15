// author: Nikita Kasinski
#pragma once
#include <windows.h>

class minmax_args
{
public:
    const int *array;
    size_t size;
    size_t indexMax, indexMin;
    CRITICAL_SECTION *iocs;
};

class average_args
{
public:
    const int *array;
    size_t size;
    int average;
    CRITICAL_SECTION *iocs;
};
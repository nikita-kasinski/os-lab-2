#include <gtest/gtest.h>
#include "utility.h"

TEST(TestGetMinimumIndex, TestFirstIndex)
{
    constexpr size_t size = 5;
    int array[size] = {1, 2, 3, 4, 5};
    EXPECT_EQ(Utility::getMinimumIndexWithSleep(array, size), 0);
}

TEST(TestGetMinimumIndex, TestStandartFlow)
{
    constexpr size_t size = 5;
    int array[size] = {5, 2, 3, 1, 4};
    EXPECT_EQ(Utility::getMinimumIndexWithSleep(array, size), 3);
}

TEST(TestGetMinimumIndex, TestEmptyArray)
{
    constexpr size_t size = 0;
    int *array = nullptr;
    EXPECT_EQ(Utility::getMinimumIndexWithSleep(array, size), -1);
}

TEST(TestGetMaximumIndex, TestFirstIndex)
{
    constexpr size_t size = 5;
    int array[size] = {5, 1, 6, 2, 3};
    EXPECT_EQ(Utility::getMaximumIndexWithSleep(array, size), 2);
}

TEST(TestGetMaximumIndex, TestStandartFlow)
{
    constexpr size_t size = 5;
    int array[size] = {8, 1, 5, 10, 7};
    EXPECT_EQ(Utility::getMaximumIndexWithSleep(array, size), 3);
}

TEST(TestGetMaximumIndex, TestEmptyArray)
{
    constexpr size_t size = 0;
    int *array = nullptr;
    EXPECT_EQ(Utility::getMaximumIndexWithSleep(array, size), -1);
}

TEST(TestGetAverage, TestEqualItems)
{
    constexpr size_t size = 5;
    int array[size] = {1, 1, 1, 1, 1};
    bool ok;
    EXPECT_EQ(Utility::getAverageWithSleep(array, size, ok), 1);
    EXPECT_TRUE(ok);
}

TEST(TestGetAverage, TestStandartFlow)
{
    constexpr size_t size = 4;
    int array[size] = {3, 5, 9, 4};
    bool ok;
    EXPECT_EQ(Utility::getAverageWithSleep(array, size, ok), 5.25);
    EXPECT_TRUE(ok);
}

TEST(TestGetAverage, TestEmptyArray)
{
    constexpr size_t size = 0;
    int *array = nullptr;
    bool ok;
    EXPECT_EQ(Utility::getAverageWithSleep(array, size, ok), 0);
    EXPECT_FALSE(ok);
}
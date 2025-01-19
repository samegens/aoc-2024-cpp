#include <gtest/gtest.h>
#include <vector>
#include <stdexcept>
#include "report.h"

// Test: Report with increasing levels within valid range
TEST(ReportIsSafeTest, IncreasingLevelsValid)
{
    Report report({1, 2, 3, 4, 5});
    EXPECT_TRUE(report.IsSafe());
}

// Test: Report with decreasing levels within valid range
TEST(ReportIsSafeTest, DecreasingLevelsValid)
{
    Report report({5, 4, 3, 2, 1});
    EXPECT_TRUE(report.IsSafe());
}

// Test: Report with levels differing by exactly 3
TEST(ReportIsSafeTest, LevelsDifferByThree)
{
    Report report({1, 4, 7, 10});
    EXPECT_TRUE(report.IsSafe());
}

// Test: Report with adjacent levels differing by less than 1
TEST(ReportIsSafeTest, LevelsDifferByLessThanOne)
{
    Report report({1, 1, 3, 4});
    EXPECT_FALSE(report.IsSafe());
}

// Test: Report with adjacent levels differing by more than 3
TEST(ReportIsSafeTest, LevelsDifferByMoreThanThree)
{
    Report report({1, 5, 9, 13});
    EXPECT_FALSE(report.IsSafe());
}

// Test: Report with mixed increasing and decreasing levels
TEST(ReportIsSafeTest, MixedLevels)
{
    Report report({1, 3, 2, 4});
    EXPECT_FALSE(report.IsSafe());
}

// Test: Report with single level
TEST(ReportIsSafeTest, SingleLevel)
{
    Report report({1});
    EXPECT_TRUE(report.IsSafe());
}

// Test: Report with no levels
TEST(ReportIsSafeTest, NoLevels)
{
    Report report({});
    EXPECT_TRUE(report.IsSafe());
}

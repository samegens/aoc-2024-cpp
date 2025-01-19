#include <gtest/gtest.h>
#include <vector>
#include <stdexcept>
#include "report_checker.h"

class ReportCheckerTest : public ::testing::Test
{
protected:
    ReportChecker report_checker;
};


TEST_F(ReportCheckerTest, IncreasingLevelsValid)
{
    // Arrange
    Report report({1, 2, 3, 4, 5});

    // Act
    bool result = report_checker.IsSafe(report);

    // Assert
    EXPECT_TRUE(result);
}

TEST_F(ReportCheckerTest, DecreasingLevelsValid)
{
    // Arrange
    Report report({5, 4, 3, 2, 1});

    // Act
    bool result = report_checker.IsSafe(report);

    // Assert
    EXPECT_TRUE(result);
}

TEST_F(ReportCheckerTest, LevelsDifferByThree)
{
    // Arrange
    Report report({1, 4, 7, 10});

    // Act
    bool result = report_checker.IsSafe(report);

    // Assert
    EXPECT_TRUE(result);
}

TEST_F(ReportCheckerTest, LevelsDifferByLessThanOne)
{
    // Arrange
    Report report({1, 1, 3, 4});

    // Act
    bool result = report_checker.IsSafe(report);

    // Assert
    EXPECT_FALSE(result);
}

TEST_F(ReportCheckerTest, LevelsDifferByMoreThanThree)
{
    // Arrange
    Report report({1, 5, 9, 13});

    // Act
    bool result = report_checker.IsSafe(report);

    // Assert
    EXPECT_FALSE(result);
}

TEST_F(ReportCheckerTest, MixedLevels)
{
    // Arrange
    Report report({1, 3, 2, 4});

    // Act
    bool result = report_checker.IsSafe(report);

    // Assert
    EXPECT_FALSE(result);
}

TEST_F(ReportCheckerTest, SingleLevel)
{
    // Arrange
    Report report({1});

    // Act
    bool result = report_checker.IsSafe(report);

    // Assert
    EXPECT_TRUE(result);
}

TEST_F(ReportCheckerTest, NoLevels)
{
    // Arrange
    Report report({});
    
    // Act
    bool result = report_checker.IsSafe(report);

    // Assert
    EXPECT_TRUE(result);
}

#include <gtest/gtest.h>
#include <vector>
#include "report.h"

TEST(ReportTest, ConstructorInitializesLevels)
{
    // Arrange
    std::vector<int> levels = {1, 2, 3, 4, 5};

    // Act
    Report report(levels);

    // Assert
    EXPECT_EQ(report.GetLevels(), levels);
}

TEST(ReportTest, GetLevelsReturnsLevels)
{
    // Arrange
    std::vector<int> levels = {10, 20, 30};
    Report report(levels);

    // Act
    const std::vector<int> &retrieved_levels = report.GetLevels();

    // Assert
    EXPECT_EQ(retrieved_levels, levels);
}

TEST(ReportTest, GetLevelsIsConst)
{
    // Arrange
    std::vector<int> levels = {1, 2, 3};
    const Report report(levels);

    // Act
    const std::vector<int> &retrieved_levels = report.GetLevels();

    // Assert
    EXPECT_EQ(retrieved_levels, levels);
}

TEST(ReportTest, EmptyReport)
{
    // Arrange
    std::vector<int> levels = {};

    // Act
    Report report(levels);

    // Assert
    EXPECT_EQ(report.GetLevels().size(), 0);
}

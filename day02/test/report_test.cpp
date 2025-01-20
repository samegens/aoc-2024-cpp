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

TEST(ReportTest, RemoveLevel_ValidIndex)
{
    // Arrange
    Report report({1, 2, 3, 4, 5});

    // Act
    Report new_report = report.RemoveLevel(2);

    // Assert
    EXPECT_EQ(new_report.GetLevels(), std::vector<int>({1, 2, 4, 5}));
    // Ensure original is unchanged.
    EXPECT_EQ(report.GetLevels(), std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(ReportTest, RemoveLevel_FirstIndex)
{
    // Arrange
    Report report({1, 2, 3, 4, 5});

    // Act
    Report new_report = report.RemoveLevel(0);

    // Assert
    EXPECT_EQ(new_report.GetLevels(), std::vector<int>({2, 3, 4, 5}));
}

TEST(ReportTest, RemoveLevel_LastIndex)
{
    // Arrange
    Report report({1, 2, 3, 4, 5});

    // Act
    Report new_report = report.RemoveLevel(4);

    // Assert
    EXPECT_EQ(new_report.GetLevels(), std::vector<int>({1, 2, 3, 4}));
}

TEST(ReportTest, RemoveLevel_SingleElement)
{
    // Arrange
    Report report({42});

    // Act
    Report new_report = report.RemoveLevel(0);

    // Assert
    EXPECT_EQ(new_report.GetLevels(), std::vector<int>());
}

TEST(ReportTest, RemoveLevel_EmptyReport)
{
    // Arrange
    Report report({});

    // Act & Assert
    EXPECT_THROW(report.RemoveLevel(0), std::out_of_range);
}

TEST(ReportTest, RemoveLevel_IndexOutOfRange)
{
    // Arrange
    Report report({1, 2, 3, 4, 5});

    // Act & Assert
    EXPECT_THROW(report.RemoveLevel(5), std::out_of_range);
    EXPECT_THROW(report.RemoveLevel(100), std::out_of_range);
    EXPECT_THROW(report.RemoveLevel(-1), std::out_of_range);
}

TEST(ReportTest, Equals_EqualReports)
{
    // Arrange
    Report report1({1, 2, 3, 4, 5});
    Report report2({1, 2, 3, 4, 5});

    // Act
    bool result = (report1 == report2);

    // Assert
    EXPECT_TRUE(result);
}

TEST(ReportTest, Equals_DifferentLengths)
{
    // Arrange
    Report report1({1, 2, 3, 4, 5});
    Report report2({1, 2, 3, 4});

    // Act
    bool result = (report1 == report2);

    // Assert
    EXPECT_FALSE(result);
}

TEST(ReportTest, Equals_DifferentElements)
{
    // Arrange
    Report report1({1, 2, 3, 4, 5});
    Report report2({5, 4, 3, 2, 1});

    // Act
    bool result = (report1 == report2);

    // Assert
    EXPECT_FALSE(result);
}

TEST(ReportTest, Equals_EmptyReports)
{
    // Arrange
    Report report1({});
    Report report2({});

    // Act
    bool result = (report1 == report2);

    // Assert
    EXPECT_TRUE(result);
}

TEST(ReportTest, Equality_SameObject)
{
    // Arrange
    Report report({1, 2, 3});

    // Act
    bool result = (report == report);

    // Assert
    EXPECT_TRUE(result);
}

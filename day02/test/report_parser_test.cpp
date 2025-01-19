#include <gtest/gtest.h>
#include <stdexcept>
#include "report_parser.h"
#include "report.h"

class ReportParserTest : public ::testing::Test
{
protected:
    ReportParser report_parser;
};

TEST_F(ReportParserTest, ValidInput)
{
    // Arrange
    std::string input = "1 2 3 4 5";

    // Act
    Report report = report_parser.Parse(input);

    // Assert
    std::vector<int> expected_levels = {1, 2, 3, 4, 5};
    EXPECT_EQ(report.GetLevels(), expected_levels);
}

TEST_F(ReportParserTest, EmptyInput)
{
    // Arrange
    std::string input = "";

    // Act & Assert
    EXPECT_THROW(report_parser.Parse(input), std::runtime_error);
}

TEST_F(ReportParserTest, InvalidInput)
{
    // Arrange
    std::string input = "1 2 three 4 5";

    // Act & Assert
    EXPECT_THROW(report_parser.Parse(input), std::runtime_error);
}

TEST_F(ReportParserTest, LeadingTrailingSpaces)
{
    // Arrange
    std::string input = "   1 2 3 4 5   ";

    // Act
    Report report = report_parser.Parse(input);

    // Assert
    std::vector<int> expected_levels = {1, 2, 3, 4, 5};
    EXPECT_EQ(report.GetLevels(), expected_levels);
}

TEST_F(ReportParserTest, MixedInput)
{
    // Arrange
    std::string input = "1 2 three";

    // Act & Assert
    EXPECT_THROW(report_parser.Parse(input), std::runtime_error);
}

TEST_F(ReportParserTest, SingleNumber)
{
    // Arrange
    std::string input = "42";

    // Act
    Report report = report_parser.Parse(input);

    // Assert
    std::vector<int> expected_levels = {42};
    EXPECT_EQ(report.GetLevels(), expected_levels);
}

TEST_F(ReportParserTest, ExtraSpacesBetweenNumbers)
{
    // Arrange
    std::string input = "1    2  3   4    5";

    // Act
    Report report = report_parser.Parse(input);

    // Assert
    std::vector<int> expected_levels = {1, 2, 3, 4, 5};
    EXPECT_EQ(report.GetLevels(), expected_levels);
}

TEST_F(ReportParserTest, NoNumbers)
{
    // Arrange
    std::string input = "   ";

    // Act & Assert
    EXPECT_THROW(report_parser.Parse(input), std::runtime_error);
}

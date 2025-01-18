#include "report.h"
#include <gtest/gtest.h>
#include <vector>
#include <stdexcept>

// Test: Parsing valid input
TEST(ReportParseTest, ValidInput) {
    std::string input = "1 2 3 4 5";
    Report report = Report::Parse(input);

    // Validate the parsed levels
    std::vector<int> expected_levels = {1, 2, 3, 4, 5};
    EXPECT_EQ(report.GetLevels(), expected_levels);
}

// Test: Parsing empty input
TEST(ReportParseTest, EmptyInput) {
    std::string input = "";

    // Expect a runtime error for empty input
    EXPECT_THROW(Report::Parse(input), std::runtime_error);
}

// Test: Parsing invalid input (non-integer)
TEST(ReportParseTest, InvalidInput) {
    std::string input = "1 2 three 4 5";

    // Expect a runtime error for invalid format
    EXPECT_THROW(Report::Parse(input), std::runtime_error);
}

// Test: Parsing input with leading/trailing spaces
TEST(ReportParseTest, LeadingTrailingSpaces) {
    std::string input = "   1 2 3 4 5   ";
    Report report = Report::Parse(input);

    // Validate the parsed levels
    std::vector<int> expected_levels = {1, 2, 3, 4, 5};
    EXPECT_EQ(report.GetLevels(), expected_levels);
}

// Test: Parsing input with mixed valid and invalid tokens
TEST(ReportParseTest, MixedInput) {
    std::string input = "1 2 three";

    // Expect a runtime error for invalid format
    EXPECT_THROW(Report::Parse(input), std::runtime_error);
}

// Test: Parsing input with single valid number
TEST(ReportParseTest, SingleNumber) {
    std::string input = "42";
    Report report = Report::Parse(input);

    // Validate the parsed levels
    std::vector<int> expected_levels = {42};
    EXPECT_EQ(report.GetLevels(), expected_levels);
}

// Test: Parsing input with extra spaces between numbers
TEST(ReportParseTest, ExtraSpacesBetweenNumbers) {
    std::string input = "1    2  3   4    5";
    Report report = Report::Parse(input);

    // Validate the parsed levels
    std::vector<int> expected_levels = {1, 2, 3, 4, 5};
    EXPECT_EQ(report.GetLevels(), expected_levels);
}

// Test: Parsing invalid input with no numbers
TEST(ReportParseTest, NoNumbers) {
    std::string input = "   ";
    
    // Expect a runtime error for invalid format
    EXPECT_THROW(Report::Parse(input), std::runtime_error);
}

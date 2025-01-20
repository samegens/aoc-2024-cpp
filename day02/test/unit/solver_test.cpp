#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "solver.h"

class MockReportParser : public IReportParser
{
public:
    MOCK_METHOD(Report, Parse, (const std::string &input), (const, override));
};

class MockReportChecker : public IReportChecker
{
public:
    MOCK_METHOD(bool, IsSafe, (const Report &report), (const, override));
    MOCK_METHOD(bool, IsSafeWithLevelRemoved, (const Report &report), (const, override));
};

TEST(SolverTest, SolvePart1)
{
    // Arrange
    std::string input = "unsafe_report\nsafe_report";
    MockReportParser parser;
    MockReportChecker checker;

    Report unsafe_report({1});
    Report safe_report({2});

    EXPECT_CALL(parser, Parse("unsafe_report")).WillOnce(::testing::Return(unsafe_report));
    EXPECT_CALL(parser, Parse("safe_report")).WillOnce(::testing::Return(safe_report));
    EXPECT_CALL(checker, IsSafe(unsafe_report)).WillOnce(::testing::Return(false));
    EXPECT_CALL(checker, IsSafe(safe_report)).WillOnce(::testing::Return(true));

    Solver solver(input, parser, checker);

    // Act
    int result = solver.SolvePart1();

    // Assert
    EXPECT_EQ(result, 1);
}

TEST(SolverTest, SolvePart2)
{
    // Arrange
    std::string input = "unsafe_report\nsafe_report\nsafe_report_after_removing";
    MockReportParser parser;
    MockReportChecker checker;

    Report unsafe_report({1});
    Report safe_report({2});
    Report safe_report_after_removing({3});

    EXPECT_CALL(parser, Parse("unsafe_report")).WillOnce(::testing::Return(unsafe_report));
    EXPECT_CALL(parser, Parse("safe_report")).WillOnce(::testing::Return(safe_report));
    EXPECT_CALL(parser, Parse("safe_report_after_removing")).WillOnce(::testing::Return(safe_report_after_removing));
    EXPECT_CALL(checker, IsSafe(unsafe_report)).WillOnce(::testing::Return(false));
    EXPECT_CALL(checker, IsSafeWithLevelRemoved(unsafe_report)).WillOnce(::testing::Return(false));
    EXPECT_CALL(checker, IsSafe(safe_report)).WillOnce(::testing::Return(true));
    EXPECT_CALL(checker, IsSafe(safe_report_after_removing)).WillOnce(::testing::Return(false));
    EXPECT_CALL(checker, IsSafeWithLevelRemoved(safe_report_after_removing)).WillOnce(::testing::Return(true));

    Solver solver(input, parser, checker);

    // Act
    int result = solver.SolvePart2();

    // Assert
    EXPECT_EQ(result, 2);
}

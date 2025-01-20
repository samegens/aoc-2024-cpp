#include <gtest/gtest.h>
#include "solver.h"

TEST(SolverIntegrationTest, SolvePart1) {
    // Arrange
    std::string input = R"(7 6 4 2 1
1 2 7 8 9
9 7 6 2 1
1 3 2 4 5
8 6 4 4 1
1 3 6 7 9)";
    ReportParser parser;
    ReportChecker checker;
    Solver solver(input, parser, checker);

    // Act
    int result = solver.SolvePart1();

    // Assert
    EXPECT_EQ(result, 2);
}

TEST(SolverIntegrationTest, SolvePart2) {
    // Arrange
    std::string input = R"(7 6 4 2 1
1 2 7 8 9
9 7 6 2 1
1 3 2 4 5
8 6 4 4 1
1 3 6 7 9)";
    ReportParser parser;
    ReportChecker checker;
    Solver solver(input, parser, checker);

    // Act
    int result = solver.SolvePart2();

    // Assert
    EXPECT_EQ(result, 4);
}

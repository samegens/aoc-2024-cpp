#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "solver.h"

std::string ReadAllTextFromPath(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file: " + filename);
    }
    return std::string((std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>());
}

int main()
{
    std::string input = ReadAllTextFromPath("input.txt");
    ReportParser parser;
    ReportChecker checker;
    Solver solver(input, parser, checker);
    std::cout << "Part 1: " << solver.SolvePart1() << std::endl;
    std::cout << "Part 2: " << solver.SolvePart2() << std::endl;

    return 0;
}

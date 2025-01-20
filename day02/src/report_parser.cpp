#include <stdexcept>
#include <sstream>
#include "report_parser.h"

ReportParser::ReportParser()
{
}

ReportParser::~ReportParser()
{
}

Report ReportParser::Parse(const std::string &line) const
{
    ValidateInput(line);
    std::vector<int> levels = ParseLevels(line);
    return Report(levels);
}

void ReportParser::ValidateInput(const std::string &line) const
{
    if (line.empty())
    {
        throw std::runtime_error("Input line is empty");
    }
}

std::vector<int> ReportParser::ParseLevels(const std::string &line) const
{
    std::vector<int> levels;
    std::istringstream stream(line);

    int number;
    while (stream >> number)
    {
        levels.push_back(number);
    }

    if (stream.fail() && !stream.eof())
    {
        throw std::runtime_error("Invalid input format: " + line);
    }

    if (levels.size() == 0)
    {
        throw std::runtime_error("Input line is empty");
    }

    return levels;
}

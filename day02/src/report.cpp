#include <sstream>
#include <stdexcept>
#include "report.h"

Report::Report(const std::vector<int> &levels)
    : levels_(levels)
{
}

Report::~Report()
{
}

Report Report::Parse(const std::string& text)
{
    ValidateInput(text);
    std::vector<int> levels = ParseLevels(text);
    return Report(levels);
}

void Report::ValidateInput(const std::string& text)
{
    if (text.empty()) {
        throw std::runtime_error("Input text is empty");
    }
}

std::vector<int> Report::ParseLevels(const std::string& text)
{
    std::vector<int> levels;
    std::istringstream stream(text);

    int number;
    while (stream >> number) {
        levels.push_back(number);
    }

    if (stream.fail() && !stream.eof()) {
        throw std::runtime_error("Invalid input format: " + text);
    }

    if (levels.size() == 0)
    {
        throw std::runtime_error("Input text is empty");
    }

    return levels;
}

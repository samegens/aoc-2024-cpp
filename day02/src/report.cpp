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

Report Report::Parse(const std::string &text)
{
    ValidateInput(text);
    std::vector<int> levels = ParseLevels(text);
    return Report(levels);
}

void Report::ValidateInput(const std::string &text)
{
    if (text.empty())
    {
        throw std::runtime_error("Input text is empty");
    }
}

std::vector<int> Report::ParseLevels(const std::string &text)
{
    std::vector<int> levels;
    std::istringstream stream(text);

    int number;
    while (stream >> number)
    {
        levels.push_back(number);
    }

    if (stream.fail() && !stream.eof())
    {
        throw std::runtime_error("Invalid input format: " + text);
    }

    if (levels.size() == 0)
    {
        throw std::runtime_error("Input text is empty");
    }

    return levels;
}

bool Report::IsSafe() const
{
    if (levels_.size() < 2)
    {
        return true; // A single level or no levels is trivially safe
    }

    bool increasing = true;
    bool decreasing = true;

    for (size_t i = 1; i < levels_.size(); ++i)
    {
        int diff = levels_[i] - levels_[i - 1];

        if (!IsAllowedDiff(diff))
        {
            return false;
        }

        if (diff < 0)
        {
            increasing = false;
        }
        else if (diff > 0)
        {
            decreasing = false;
        }
    }

    // A report is safe if it is either strictly increasing or strictly decreasing
    return increasing || decreasing;
}

bool Report::IsAllowedDiff(int diff) const
{
    return std::abs(diff) >= 1 && std::abs(diff) <= 3;
}

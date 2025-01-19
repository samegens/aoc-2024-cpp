#include <stdexcept>
#include "report.h"

Report::Report(const std::vector<int> &levels)
    : levels_(levels)
{
}

Report::~Report()
{
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

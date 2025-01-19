#include "report_checker.h"

ReportChecker::ReportChecker()
{
}

ReportChecker::~ReportChecker()
{
}

bool ReportChecker::IsSafe(const Report &report) const
{
    const std::vector<int> &levels = report.GetLevels();

    if (levels.size() < 2)
    {
        // A single level or no levels is trivially safe.
        return true;
    }

    bool increasing = true;
    bool decreasing = true;

    for (size_t i = 1; i < levels.size(); ++i)
    {
        int diff = levels[i] - levels[i - 1];

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

bool ReportChecker::IsSafeWithLevelRemoved(const Report &report) const
{
    for (int i = 0; i < report.GetLevels().size(); i++)
    {
        Report new_report = report.RemoveLevel(i);
        if (IsSafe(new_report))
        {
            return true;
        }
    }

    return false;
}

bool ReportChecker::IsAllowedDiff(int diff) const
{
    return std::abs(diff) >= 1 && std::abs(diff) <= 3;
}

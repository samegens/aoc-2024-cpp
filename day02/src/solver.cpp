#include "solver.h"
#include <sstream>
#include "report_checker.h"

Solver::Solver(const std::string &input, const IReportParser &parser, const IReportChecker &checker)
    : parser_(parser), checker_(checker), reports_(ParseReports(input, parser))
{
}

Solver::~Solver()
{
}

int Solver::SolvePart1()
{
    int count = 0;
    for (const auto& report: reports_)
    {
        if (checker_.IsSafe(report))
        {
            count++;
        }
    }
    return count;
}

int Solver::SolvePart2()
{
    int count = 0;
    for (const auto& report: reports_)
    {
        if (checker_.IsSafe(report) || checker_.IsSafeWithLevelRemoved(report))
        {
            count++;
        }
    }
    return count;
}

std::vector<Report> Solver::ParseReports(const std::string &input, const IReportParser &report_parser)
{
    std::istringstream stream(input);
    std::string line;
    std::vector<Report> reports;

    while (std::getline(stream, line))
    {
        reports.push_back(report_parser.Parse(line));
    }

    return reports;
}

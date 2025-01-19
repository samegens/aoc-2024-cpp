#include "solver.h"
#include <sstream>
#include "report_checker.h"

Solver::Solver(const std::string &input)
{
    ReportParser report_parser;
    reports_ = ParseReports(input, report_parser);
}

Solver::~Solver()
{
}

int Solver::SolvePart1()
{
    ReportChecker report_checker;
    int count = 0;
    for (const auto& report: reports_)
    {
        if (report_checker.IsSafe(report))
        {
            count++;
        }
    }
    return count;
}

int Solver::SolvePart2()
{
    return 0;
}

std::vector<Report> Solver::ParseReports(const std::string &input, const ReportParser &report_parser)
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

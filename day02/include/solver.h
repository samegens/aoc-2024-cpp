#ifndef SOLVER_H
#define SOLVER_H

#include <string>
#include <vector>
#include "report.h"
#include "report_parser.h"
#include "report_checker.h"

/// @brief Solver will take the puzzle input and solve both parts.
class Solver {
public:
    Solver(const std::string &input, const IReportParser &parser, const IReportChecker &checker);
    ~Solver();

    int SolvePart1();
    int SolvePart2();
    
private:
    /// @brief Takes a multiline string and uses the report parser to parse each separate line into a Report.
    /// @param input The multiline string containing levels on each line
    /// @param reportParser The parser to use on each separate line
    /// @return A list of reports
    static std::vector<Report> ParseReports(const std::string& input, const IReportParser& reportParser);

    const IReportParser& parser_;
    const IReportChecker& checker_;
    std::vector<Report> reports_;
};

#endif // SOLVER_H

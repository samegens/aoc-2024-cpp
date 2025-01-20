#ifndef REPORTS_PARSER_H
#define REPORTS_PARSER_H

#include "report.h"

/// @brief Abstract class IReportParser parses a single line report, for example '7 6 4 2 1'.
class IReportParser
{
public:
    virtual ~IReportParser() = default;

    /// @brief Parse a line of the form '7 6 4 2 1' and create a Report.
    /// @param input 
    /// @return 
    virtual Report Parse(const std::string &line) const = 0;
};

/// @brief Actual implementation of IReportParser.
class ReportParser : public IReportParser
{
public:
    ReportParser();
    ~ReportParser();

    Report Parse(const std::string &line) const;

private:
    void ValidateInput(const std::string &line) const;
    std::vector<int> ParseLevels(const std::string &line) const;
};

#endif // REPORTS_PARSER_H

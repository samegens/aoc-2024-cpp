#ifndef REPORTS_PARSER_H
#define REPORTS_PARSER_H

#include "report.h"

/// @brief ReportParser parses a single line report, for example '7 6 4 2 1'.
class ReportParser {
public:
    ReportParser();
    ~ReportParser();

    Report Parse(const std::string& text) const;

private:
    void ValidateInput(const std::string &text) const;
    std::vector<int> ParseLevels(const std::string &text) const;
};

#endif // REPORTS_PARSER_H

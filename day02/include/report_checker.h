#ifndef REPORTCHECKER_H
#define REPORTCHECKER_H

#include "report.h"

/// @brief ReportChecker is used to check if a report is safe.
class ReportChecker {
public:
    ReportChecker();
    ~ReportChecker();

    /// @brief Checks if a report is safe: the levels must either strictly increase or strictly decrease
    /// and the difference between any two adjacent levels must be 1, 2 or 3.
    /// @param report 
    /// @return true when the report is safe.
    bool IsSafe(const Report& report) const;
    
private:
    bool IsAllowedDiff(int diff) const;

};

#endif // REPORTCHECKER_H

#ifndef REPORTCHECKER_H
#define REPORTCHECKER_H

#include "report.h"

/// @brief Abstract class IReportChecker is used to check if a report is safe.
class IReportChecker
{
public:
    virtual ~IReportChecker() = default;

    /// @brief Checks if a report is safe: the levels must either strictly increase or strictly decrease
    /// and the difference between any two adjacent levels must be 1, 2 or 3.
    /// @param report
    /// @return true when the report is safe.
    virtual bool IsSafe(const Report &report) const = 0;

    /// @brief Checks if a report is safe when one level is removed from the report.
    /// @param report
    /// @return true when the report is safe with one level removed.
    virtual bool IsSafeWithLevelRemoved(const Report &report) const = 0;
};

/// @brief Actual implementation of IReportChecker.
class ReportChecker : public IReportChecker
{
public:
    ReportChecker();
    ~ReportChecker();

    bool IsSafe(const Report &report) const;

    bool IsSafeWithLevelRemoved(const Report &report) const;

private:
    bool IsAllowedDiff(int diff) const;
};

#endif // REPORTCHECKER_H

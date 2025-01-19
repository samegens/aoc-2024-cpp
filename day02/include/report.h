#ifndef REPORT_H
#define REPORT_H

#include <vector>
#include <string>

class Report
{
public:
    Report(const std::vector<int> &levels);
    ~Report();

    const std::vector<int> &GetLevels() const { return levels_; }

    bool IsSafe() const;

private:
    bool IsAllowedDiff(int diff) const;

    std::vector<int> levels_;
};

#endif // REPORT_H

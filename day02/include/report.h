#ifndef REPORT_H
#define REPORT_H

#include <vector>
#include <string>

/// @brief Report stores a report (a list of levels).
class Report
{
public:
    Report(const std::vector<int> &levels);
    ~Report();

    const std::vector<int> &GetLevels() const { return levels_; }

private:
    std::vector<int> levels_;
};

#endif // REPORT_H

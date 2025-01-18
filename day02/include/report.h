#ifndef REPORT_H
#define REPORT_H

#include <vector>
#include <string>

class Report
{
public:
    static Report Parse(const std::string &text);

    Report(const std::vector<int> &levels);
    ~Report();

    const std::vector<int> &GetLevels() const { return levels_; }

    bool IsSafe() const;

private:
    static void ValidateInput(const std::string &text);
    static std::vector<int> ParseLevels(const std::string &text);

    bool IsAllowedDiff(int diff) const;

    std::vector<int> levels_;
};

#endif // REPORT_H

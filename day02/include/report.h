#ifndef REPORT_H
#define REPORT_H

#include <vector>
#include <string>

class Report {
public:
    Report(const std::vector<int>& levels);
    ~Report();

    const std::vector<int>& GetLevels() const { return levels_; }

    static Report Parse(const std::string& text);

private:
    static void ValidateInput(const std::string& text);
    static std::vector<int> ParseLevels(const std::string& text);

    std::vector<int> levels_;
};

#endif // REPORT_H

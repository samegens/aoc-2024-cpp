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

    /// @brief Create a new Report without the element at the specified index.
    /// @param index 
    /// @return The new report
    Report RemoveLevel(size_t index) const;

    /// @brief Equality operator
    /// @param other 
    /// @return true of this report equals the passed report
    bool operator==(const Report& other) const;

private:
    std::vector<int> levels_;
};

#endif // REPORT_H

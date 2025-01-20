#include <stdexcept>
#include "report.h"

Report::Report(const std::vector<int> &levels)
    : levels_(levels)
{
}

Report::~Report()
{
}

Report Report::RemoveLevel(size_t index) const
{
    if (index >= levels_.size())
    {
        throw std::out_of_range("Index out of range");
    }

    std::vector<int> new_levels(levels_);
    new_levels.erase(new_levels.begin() + index);

    return Report(new_levels);
}

bool Report::operator==(const Report &other) const
{
    return levels_ == other.levels_;
}

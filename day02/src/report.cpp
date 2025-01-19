#include <stdexcept>
#include "report.h"

Report::Report(const std::vector<int> &levels)
    : levels_(levels)
{
}

Report::~Report()
{
}

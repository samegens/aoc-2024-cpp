#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>


int main() {
    std::ifstream file("input.txt");

    std::string line;
    std::vector<int> left;
    std::vector<int> right;
    while (std::getline(file, line)) {
        size_t pos;
        pos = line.find("   ", 0);
        int num = std::stoi(line.substr(0, pos));
        left.push_back(num);

        num = std::stoi(line.substr(pos + 3, line.length() - pos - 3));
        right.push_back(num);
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    int sum = 0;
    for (int i = 0; i < left.size(); i++) {
        sum += std::abs(left[i] - right[i]);
    }
    std::cout << "Part 1: " << sum << "\n";

    sum = 0;
    for (int i = 0; i < left.size(); i++) {
        sum += std::abs(left[i] * std::count(right.begin(), right.end(), left[i]));
    }
    std::cout << "Part 2: " << sum << "\n";

    file.close();

    return 0;
}

#include "listProblem.h"
#include <algorithm>
#include <cstdlib>

using namespace std;

void listProblem::insertSortedUnique(int num) {
    if (find(numbers.begin(), numbers.end(), num) == numbers.end()) {
        numbers.push_back(num);
        sort(numbers.begin(), numbers.end());
    }
}

void listProblem::parseRange(const std::string& token) {
    size_t dashPos = token.find('-');
    if (dashPos != std::string::npos) {
        int start = std::stoi(token.substr(0, dashPos));
        int end = std::stoi(token.substr(dashPos + 1));
        if (start > end) std::swap(start, end);
        for (int i = start; i <= end; ++i) {
            insertSortedUnique(i);
        }
    } else {
        int num = std::stoi(token);
        insertSortedUnique(num);
    }
}

const vector <int>& listProblem::getProblems() const {
    return numbers;
}
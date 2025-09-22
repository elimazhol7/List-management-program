#pragma once

#include <vector>
#include <string>

class listProblem {
private:
   std::vector<int> numbers;
   
public:
  void insertSortedUnique(int num);
  void parseRange(const std:: string& token);
  const std:: vector<int>& getProblems() const;

};
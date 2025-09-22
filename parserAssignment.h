#pragma once

#include <string>
#include "listProblem.h"

class parserAssignment {
    private :
        std::string setName;
    public:
        std::string parseSetName(std::string& input);
        void parseProblems(const std::string& input, listProblem& plist);
        void printProblems(const listProblem& plist) const;
};
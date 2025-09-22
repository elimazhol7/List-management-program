#include <iostream>
#include"listProblem.h"
#include "parserAssignment.h"
#include <algorithm>

using namespace std;

int main() {
    string input;
    cout << "Enter assignment list: ";
    getline(cin, input);

    // Remove spaces
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    parserAssignment parser;
    listProblem plist;

    string setName = parser.parseSetName(input);
    parser.parseProblems(input, plist);
    parser.printProblems(plist);

    return 0;
}
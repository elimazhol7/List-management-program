#include "parserAssignment.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

string parserAssignment::parseSetName(string& input) {
    string result;
    if (input[0] == '"' || input[0] == '\'') {
        char quote = input[0];
        size_t endQuote = input.find(quote, 1);
        result = input.substr(1, endQuote - 1);
        input = input.substr(endQuote + 1);
    } else {
        size_t pos = 0;
        while (pos < input.size() && !isdigit(input[pos])) ++pos;
        result = input.substr(0, pos);
        input = input.substr(pos);
    }
    setName = result;
    return result;
}

void parserAssignment::parseProblems(const string& input, listProblem& plist) {
    string token;
    stringstream ss(input);

    while (getline(ss, token, ',')) {
        if (!token.empty()) {
            plist.parseRange(token);
        }
    }
}

void parserAssignment::printProblems(const listProblem& plist) const {
    const vector<int>& problems = plist.getProblems();

    cout << "Do problem";
    if (problems.size() > 1) cout << "s";
    cout << " ";

    int lineLength = 12;
    for (size_t i = 0; i < problems.size(); i++) {
        string part;
        if (i == problems.size() - 1 && i > 0) part = "and " + to_string(problems[i]);
        else part = to_string(problems[i]);

        if (i < problems.size() - 1) part += ", ";

        if (lineLength + part.size() > 70) {
            cout << "\n   ";
            lineLength = 3;
        }
        cout << part;
        lineLength += part.size();
        if (i == problems.size() - 1) cout << " ";
    }
    cout << "of " << setName << "." << endl;
}
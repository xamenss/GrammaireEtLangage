#pragma once

#include <string>
#include <vector>
#include "lexer.h"
#include "automate.h"
using namespace std;

class TestCase {
public:
    static int runTestsPassed();
    static int runTestsFailed();
private:
    struct Case {
        string input;
        int expected;
        string description;
    };
};

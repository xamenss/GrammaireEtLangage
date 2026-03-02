#include <iostream>
#include <vector>
#include "TestCase.h"
#include "lexer.h"
#include "automate.h"

using namespace std;

int TestCase::runTestsPassed() {
    
    int currentTest = 1;
    vector<Case> tests = {
        {"100+50", 150, "addition"},
        {"10*35", 350, "multiplication"},
        {"(1+34)*123", 4305, "parentheses with addition and multiplication v1"},
        {"123*(1+34)", 4305, "parentheses with addition and multiplication v2"},
        {"((1+34)*123)", 4305, "parentheses with addition and multiplication v3"},
        {"42", 42, "single number"},
        {"2+3*4", 14, "operator precedence"},
        {"(1+34)+(2+4)", 41, "addition with expresion "},
        {"(1+34)*(120+3)", 4305, "multiplication of 2 addition with expresion "},
        {"(1*34)+(120*2)", 274, "addition of 2 multiplication with expresion "},
        {"(((1)))", 1, "parentheses"},

        
        
    };

    int passed = 0;
    for (const auto& test : tests) {
        Lexer l(test.input);
        Automate automate(&l);
        AnalyseResult result = automate.analyse();

        bool success = result.success && result.value == test.expected;
        
        cout << "Test n°" << currentTest << " :" ;
        cout << " input: " << test.input << ", expected: " << test.expected << ", result: " << result.value << ", desciption: " << test.description << endl;  
        cout << "Test n°" << currentTest << ": " ;
        if (success)
        {
            cout << "Succeed " << endl;
        }
        else
        {
            cout << "Failed " << endl;
        }
        
        if (success) passed++;
        currentTest++;
    }

    cout << "Results: " << passed << "/" << tests.size() << " tests passed" << endl;
    return passed;
}

int TestCase::runTestsFailed() {
    
    int currentTest = 1;
    vector<Case> tests = {
        {"((+2-1))", -1, "invalid unary operator in parentheses"},
        {"100-50", -1, "subtraction not supported"},
        {"10/35", -1, "division not supported"},
        {"(1+34)*", -1, "incomplete expression"},
        {"*123", -1, "expression starts with operator"},
        {"1++2", -1, "consecutive operators"},
        {"(1+34", -1, "missing closing parenthesis"},
        {"1+34)", -1, "missing opening parenthesis"},
    };

    int failed = 0;
    for (const auto& test : tests) {
        Lexer l(test.input);
        Automate automate(&l);
        AnalyseResult result = automate.analyse();

        bool success = !result.success ; //|| result.value == test.expected
        
        cout << "Test n°" << currentTest << " :" ;
        cout << " input: " << test.input << ", expected: " << test.expected << ", result: " << result.value << ", desciption: " << test.description << endl;  
        cout << "Test n°" << currentTest << ": " ;
        if (success)
        {
            cout << "Succeed, l'expression est bien consideré comme fausse " << endl;
        }
        else
        {
            cout << "Failed, l'expression n'a pas fait d'erreur " << endl;
        }
        
        if (success) failed++;
        currentTest++;
    }

    cout << "Results: " << failed << "/" << tests.size() << " tests failed" << endl;
    return failed;
}

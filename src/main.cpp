#include <iostream>
#include "lexer.h"
#include "automate.h"
#include "TestCase.h"

int main(void) {

   // string chaine("*123");
   // Lexer l(chaine);

   // Automate a(&l);
   // a.analyse();
   // return 0;
   TestCase::runTestsFailed();
   return TestCase::runTestsPassed();
}


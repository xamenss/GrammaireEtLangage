#include <iostream>
#include "lexer.h"
#include "automate.h"
#include "TestCase.h"

int main(void) {

   //main
   string chaine("*123");
   Lexer l(chaine);

   Automate a(&l);
   a.analyse();
   return 0;

   //main

   // Test unitaire

   // TestCase::runTestsFailed();
   // return TestCase::runTestsPassed();

   // Test unitaire
}


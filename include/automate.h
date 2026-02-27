#pragma once
#include "lexer.h"
#include "symbole.h"
#include "etat.h"
#include <iostream>

#include <stack>

class Symbole;
class Etat;
class Lexer;

class Automate {
public:
    void decalage(Symbole* s, Etat* e);
    void transitionsimple(Symbole* s, Etat* e);
    void reduction(int n, Symbole* s);

private:
    std::stack<Symbole*> symbolstack;
    std::stack<Etat*>    statestack;
    Lexer* lexer = nullptr;
};

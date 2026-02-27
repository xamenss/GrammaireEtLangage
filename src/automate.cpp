#include "automate.h"
#include <iostream>
#include <map>
#include <set>

using namespace std;

void Automate::decalage(Symbole* s, Etat* e) {
    symbolstack.push(s);
    statestack.push(e);
    lexer->Avancer();
}

void Automate::transitionsimple(Symbole* s, Etat* e) {
    symbolstack.push(s);
    statestack.push(e);
}

void Automate::reduction(int n, Symbole* s) {
    for (int i = 0; i < n; i++) {
        delete statestack.top();
        statestack.pop();
    }
    statestack.top()->transition(*this, s);
}

bool Automate::analyse() {
    while (true) {
        statestack.top()->transition(*this, lexer->Consulter());
    }
}

Symbole * Automate::popSymbol() {
    if (symbolstack.empty()) {
        return nullptr;
    }
    Symbole* s = symbolstack.top();
    symbolstack.pop();
    return s;
}

Symbole * Automate::popAndDestroySymbol() {
    if (symbolstack.empty()) {
        return nullptr;
    }
    Symbole* s = symbolstack.top();
    symbolstack.pop();
    delete s;
    return nullptr;
}
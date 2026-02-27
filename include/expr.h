#include "symbole.h"

class Expr : public Symbole {
    public:
        Expr(int v) : Symbole(EXPR), valeur(v) {};
        virtual ~Expr() {};
        protected:
        int valeur; 
    protected:
        int valeur;
        
};
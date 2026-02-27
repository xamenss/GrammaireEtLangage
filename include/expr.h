
#include "symbole.h"


class Expr : public Symbole {
    public:
        Expr() : Symbole(EXPR) {};
        virtual ~Expr() {};
        protected:
        int valeur; 
};
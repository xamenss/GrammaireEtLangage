#include <map>
#include <string>
#inlclude "symbole.h"
class expr : public symbole {
    public:
        expr() : symbole(expr) {};
        virtual ~expr() {};
        virtual double eval() const = 0; 
}
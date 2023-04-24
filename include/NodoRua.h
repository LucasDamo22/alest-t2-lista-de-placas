#ifndef NodoRua_h
#define NodoRua_h
#include "LinkedListOfPlaca.h"
class NodoRua{
    public:
        std::string rua;
        LinkedListOfPlaca placasNaRua;

        NodoRua* next;
        NodoRua* prev;

        NodoRua();
        NodoRua(std::string rua);
        NodoRua(std::string rua, NodoRua* next);

};
#endif
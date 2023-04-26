#ifndef NodoRua_h
#define NodoRua_h
#include "LinkedListOfPlaca.h"
class NodoRua{
    public:
        std::string rua;
        std::string tipoRua;
        LinkedListOfPlaca placasNaRua;

        NodoRua* next;
        NodoRua* prev;

        NodoRua();
        NodoRua(std::string rua,std::string tipoRua);
        NodoRua(std::string rua, std::string tipoRua, NodoRua* next);

};
#endif
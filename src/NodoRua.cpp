#include <string>
#include <sstream>

#include "NodoRua.h"

NodoRua::NodoRua(){
    this->next = nullptr;
}
NodoRua::NodoRua(std::string rua, std::string tipoRua){
    this->rua = rua;
    this->tipoRua = tipoRua;
    this->next = nullptr;
    this->prev = nullptr;
    this->placasNaRua = new LinkedListOfPlaca();
}

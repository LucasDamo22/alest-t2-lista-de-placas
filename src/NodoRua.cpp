#include <string>
#include <sstream>

#include "NodoRua.h"

NodoRua::NodoRua(){
    this->next = NULL;
}
NodoRua::NodoRua(std::string rua, std::string tipoRua){
    this->rua = rua;
    this->tipoRua = tipoRua;
    this->next = NULL;
}
NodoRua::NodoRua(std::string rua, std::string tipoRua, NodoRua* next){
    this->rua = rua;
    this->tipoRua = tipoRua;
    this->next = next;
}
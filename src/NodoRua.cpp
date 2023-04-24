#include <string>
#include <sstream>

#include "NodoRua.h"

NodoRua::NodoRua(){
    this->next = NULL;
}
NodoRua::NodoRua(std::string rua){
    this->rua = rua;
    this->next = NULL;
}
NodoRua::NodoRua(std::string rua, NodoRua* next){
    this->rua = rua;
    this->next = next;
}
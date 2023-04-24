#include <string>
#include <sstream>
#include "NodoPlaca.h"


NodoPlaca::NodoPlaca(){}

NodoPlaca::NodoPlaca(std::string tipoPlaca, std::string latitude, std::string longitude){
    
    this->tipoPlaca = tipoPlaca;
    this->latitude = latitude;
    this->latitude = latitude;
    this->next = NULL;
}
std::string NodoPlaca::to_String(){

    std::stringstream ss;
    ss << "tipo de Placa :"<< this->tipoPlaca<<std::endl;
    ss << "Longitude :"<< this->longitude<<std::endl;
    ss << "Latitude :"<< this->latitude<<std::endl;
    return ss.str();
}


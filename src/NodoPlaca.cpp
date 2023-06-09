#include <string>
#include <sstream>
#include "NodoPlaca.h"


NodoPlaca::NodoPlaca(){}

NodoPlaca::NodoPlaca(std::string tipoPlaca, std::string latitude, std::string longitude, std::string data){
    
    this->tipoPlaca = tipoPlaca;
    this->latitude = latitude;
    this->longitude = longitude;
    this->data = data;
    this->next = nullptr;
}
std::string NodoPlaca::toString(){

    std::stringstream ss;
    ss << "tipo de Placa :"<< this->tipoPlaca<<std::endl;
    ss << "Longitude :"<< this->longitude<<std::endl;
    ss << "Latitude :"<< this->latitude<<std::endl;
    ss << "Data de instalação :"<< this->data<<std::endl;
    //ss << "-------"<<std::endl;
    return ss.str();
}
std::string NodoPlaca::get_data(){
    return this->data;
}


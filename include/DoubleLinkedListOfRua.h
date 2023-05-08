#ifndef DoubleLinkedListOfRua_h
#define DoubleLinkedListOfRua_h
#include "NodoRua.h"
class DoubleLinkedListOfRua{
    NodoRua* head;
    NodoRua* tail;
    int count;
public:
    DoubleLinkedListOfRua();
    bool isEmpty();
    int size();
    void imprimeLista();
    int totalPLacas();
    NodoRua* get_head();
    NodoRua* get_tail();
    int placasNaRua(NodoRua* rua);
    std::string placasSemLatLong();
    void add(std::string rua,std::string tipoRua);
    void add(int index,std::string rua,std::string tipoRua);
    void add(std::string rua, std::string tipoRua,std::string tipoPlaca, std::string latitude, std::string longitude, std::string data);

};


#endif
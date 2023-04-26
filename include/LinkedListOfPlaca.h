#ifndef LinkedListOfPlaca_h
#define LinkedListOfPlaca_h
#include "NodoPlaca.h"
class LinkedListOfPlaca{
  NodoPlaca* head;
  NodoPlaca* tail;
  int count;
  public:
    LinkedListOfPlaca();
    void imprimeLista();
    bool isEmpty();
    int size();
    void clear();
    bool contains(std::string element);
    std::string toString();
    void add(std::string tipoPlaca, std::string latitude, std::string longitude,std::string data);

};
#endif
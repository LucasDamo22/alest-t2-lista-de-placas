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
    std::string semLatLong(std::string rua);
    std::string toString();
    NodoPlaca* get_head();
    NodoPlaca* get_tail();
    int compare_data(std::string target);
    void add(std::string tipoPlaca, std::string latitude, std::string longitude,std::string data);
    void addInOrder(std::string tipoPlaca, std::string latitude, std::string longitude,std::string data);

};
#endif
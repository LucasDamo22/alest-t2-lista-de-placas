#ifndef HELPERFUNC_H
#define HELPERFUNC_H
#include "NodoRua.h"
#include "DoubleLinkedListOfRua.h"

//separadores da string data
std::string dia(std::string data);

std::string mes(std::string data);

std::string ano(std::string data);

//compara se a dataPtr é "antes" da dataN
int compare1minor2(std::string dataPtr,std::string dataN);

void menu(DoubleLinkedListOfRua* Lista);
std::string menuNav(NodoRua* iterador);
NodoRua* navegador(NodoRua* iterador,NodoRua* head, NodoRua* tail);



#endif
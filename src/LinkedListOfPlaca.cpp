#include <string>
#include <iostream>


#include "LinkedListOfPlaca.h"

LinkedListOfPlaca::LinkedListOfPlaca(){
    head = NULL;
    tail = NULL;
    count  = 0;
}
void LinkedListOfPlaca::imprimeLista(){
    NodoPlaca* ptr;
    if(head==NULL){
        std::cout<<" --Lista de Placas desta rua está vazia;"<<std::endl;
        return;
    }
    ptr = head;
    do{
        std::cout<<ptr->to_String()<<std::endl;
        ptr = ptr->next;

    }while(ptr!=NULL);
}
void LinkedListOfPlaca::add(std::string tipoPlaca, std::string latitude, std::string longitude,std::string data){
    
    NodoPlaca *n = new NodoPlaca(tipoPlaca,latitude,longitude,data);
    if(head == NULL){
        head = n;
    }else{
        tail->next = n;
    }
    tail = n;
    count++;
    
}
void LinkedListOfPlaca::addInOrder(std::string tipoPlaca, std::string latitude, std::string longitude,std::string data){
    NodoPlaca *n = new NodoPlaca(tipoPlaca,latitude,longitude,data);
    NodoPlaca *ptr;
    std::string ptrDia;
    std::string ptrMes;
    std::string ptrAno;
    if(head == NULL){
        head = n;
        tail = n;
        return;
    }else{
        ptr = head;
        while(ptr!=NULL){
            ptrDia = ptr->data.substr(0,ptr->data.find("/"));
            ptrMes = ptr->data.substr(ptr->data.find("/")+1,ptr->data.find("/"));
            ptrAno = ptr->data.substr(ptr->data.find_last_of("/"),ptr->data.length());
            
        }
        

    }

}
bool LinkedListOfPlaca::isEmpty(){
    return (head == NULL);
}

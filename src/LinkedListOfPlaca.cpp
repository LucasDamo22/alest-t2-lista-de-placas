#include <string>
#include <iostream>

#include "HelperFunc.h"
#include "LinkedListOfPlaca.h"

LinkedListOfPlaca::LinkedListOfPlaca(){
    head = nullptr;
    tail = nullptr;
    count  = 0;
}
void LinkedListOfPlaca::imprimeLista(){
    NodoPlaca* ptr;
    if(head==nullptr){
        std::cout<<" --Lista de Placas desta rua está vazia;"<<std::endl;
        return;
    }
    ptr = head;
    do{
        std::cout<<ptr->to_String()<<std::endl;
        ptr = ptr->next;

    }while(ptr!=nullptr);
}
void LinkedListOfPlaca::add(std::string tipoPlaca, std::string latitude, std::string longitude,std::string data){
    
    NodoPlaca *n = new NodoPlaca(tipoPlaca,latitude,longitude,data);
    if(head == nullptr){
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
   
    //std::cout<<"init add order "<<tipoPlaca<<std::endl;
    if(head == nullptr){
        head = n;
        tail = n;
        return;
    }else{
        ptr = head;
        while(ptr->next!=nullptr){
            std::cout<<"========="<<std::endl;
            // std::cout<<ptr->data<<std::endl;
            // std::cout<<n->data<<std::endl;
            // std::cout<<"+++"<<std::endl;
            // std::cout<<compare1minor2(ptr->data,n->data)<<std::endl;
            // std::cout<<"+++"<<std::endl;

            std::cout<<"*****************"<<std::endl;
            std::cout<<ptr->data<<"  "<<n->data<<std::endl;
            std::cout<<ano(ptr->data)<<"  "<<ano(n->data)<<std::endl;
            std::cout<<mes(ptr->data)<<"  "<<mes(n->data)<<std::endl;
            std::cout<<dia(ptr->data)<<"  "<<dia(n->data)<<std::endl;
            std::cout<<compare1minor2(ptr->data,n->data)<<std::endl;



           if((compare1minor2(ptr->data,n->data)<=0) && compare1minor2(ptr->next->data,n->data)>0){
           std::cout<<"true"<<std::endl;
                break;
           }
        //    std::cout<< "isnt breaking"<<std::endl;
        //    std::cout<<ptr->tipoPlaca<<std::endl;
        //    std::cout<<n->tipoPlaca<<std::endl;
           ptr = ptr->next;
           std::cout<<"////////////////"<<std::endl;
        }
        std::cout<<"before if"<<std::endl;
        if(ptr->next==nullptr){
            ptr->next = n;
            tail = n;
            return;
        }
        std::cout<<"before next"<<std::endl;
        n->next = ptr->next;
        std::cout<<"after next"<<std::endl;
        ptr->next  = n ;
       
        
    }

}
bool LinkedListOfPlaca::isEmpty(){
    return (head == nullptr);
}



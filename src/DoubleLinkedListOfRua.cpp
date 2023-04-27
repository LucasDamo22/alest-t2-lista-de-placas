#include <string>
#include <sstream>
#include <iostream>
#include "DoubleLinkedListOfRua.h"
#define IndexOutOfBoundsException 0

DoubleLinkedListOfRua::DoubleLinkedListOfRua(){
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
}
void DoubleLinkedListOfRua::imprimeLista(){
    NodoRua *ptr;
    if (head == NULL)
    {
        // printf("--- Lista Vazia\n");
        return;
    }
    // Caso a lista nao esteja vazia
    ptr = head;
    while (true)
    {
        std::cout << ptr->rua << std::endl;
        ptr->placasNaRua.imprimeLista();
        ptr = ptr->next;
        if (ptr == NULL)
            break;
    }
    std::cout << "--- Fim da lista ---" << std::endl;
}
bool DoubleLinkedListOfRua::isEmpty(){
    if(head!=NULL)
        return true;
    else
        return false;
}
void DoubleLinkedListOfRua::add(std::string rua,std::string tipoRua){
    NodoRua *ptr;
    NodoRua *n = new NodoRua(rua,tipoRua);
    if(head==NULL){
        head = n;
        tail = n;
        count++;
    }else{
        ptr = head;

        while(true){
            if(rua == ptr->rua){
                delete n;
            }else{
                ptr = ptr->next;
            }
            if(ptr==NULL){
                break;
            }
        }
        tail->next = n;
        tail->next;
        count++;
    }

}
void DoubleLinkedListOfRua::add(std::string rua, std::string tipoRua, std::string tipoPlaca, std::string latitude, std::string longitude, std::string data){
    NodoRua *ptr;
    NodoRua *n = new NodoRua(rua,tipoRua);
 
    n->placasNaRua.add(tipoPlaca,latitude,longitude,data);
       
    if(head==NULL){
        
        head = n;
        tail = n;
        count++;
        return;
    }else{
        
        NodoRua *aux = head;
     
        for(int i=0;i<=count;i++){
            std::cout<<"abublué count"<<i<<std::endl;
            if(aux->rua == rua){
            std::cout<<"abublué pos if"<<std::endl;
            break;}
            std::cout<<"abublué if aux->rua"<<std::endl;
            if(aux->rua > rua){
                std::cout<<"abublué add rua"<<std::endl;
                add(i, rua,tipoRua);
                std::cout<<"abublué post add"<<std::endl;
                break;
            }
            aux = aux->next;
        }
        ptr = head;
        while(true){
            if(rua == ptr->rua){
                ptr->placasNaRua.add(tipoPlaca,longitude,latitude,data);
                delete n;
                return;
            }else{
                ptr = ptr->next;
            }
            if(ptr == NULL)
                break;
        }
        n->prev = tail;       
        tail->next = n;
        
        tail = n;
        count++;
    }
}

void DoubleLinkedListOfRua::add(int index,std::string rua,std::string tipoRua){
    if((index<0) || (index>count)){
        throw IndexOutOfBoundsException;
    }
    NodoRua *n = new NodoRua(rua,tipoRua);
    count++;
    if(index ==0){
        if (head == NULL)
        { // se a lista estiver vazia
            tail = n;
        }
        else
        { // se a lista não estiver vazia
            n->next = head;
            head->prev = n;
        }
        head = n;
    }else if(index == count){
        tail->next = n;
        n->prev = tail;
        tail = n;
    }else{//insere no meio
        NodoRua* ptr= head;
        for (int i =0;i<index-1;i++)
            ptr = ptr->next;//caminha até onde inserir
        //faz a inserção e correcao dos pointers
        n->next = ptr->next;
        ptr->next = n;
        n->prev = ptr;
        n->next->prev = n;
    }

}
#include <string>
#include <sstream>
#include "DoubleLinkedListOfRua.h"
#define IndexOutOfBoundsException 0

DoubleLinkedListOfRua::DoubleLinkedListOfRua(){
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
}

bool DoubleLinkedListOfRua::isEmpty(){
    if(head!=NULL)
        return true;
    else
        return false;
}
void DoubleLinkedListOfRua::add(std::string rua){
    NodoRua *ptr;
    NodoRua *n = new NodoRua(rua);

}
void DoubleLinkedListOfRua::add(std::string rua, std::string tipoPlaca, std::string latitude, std::string longitude, std::string data){
    NodoRua *ptr;
    NodoRua *n = new NodoRua(rua);
    n->placasNaRua.add(tipoPlaca,latitude,longitude,data);
    if(head!=NULL){
        head = n;
        tail = n;
        count++;
        return;
    }else{
        NodoRua *aux = head;
        for(int i=0;i<count;i++){

            if(aux->rua == rua)
            break;

            if(aux->rua > rua){
                add(i, rua);
                break;
            }
        }

    }
}

void DoubleLinkedListOfRua::add(int index,std::string rua){
    if((index<0) || (index>count)){
        throw IndexOutOfBoundsException;
    }
    NodoRua *n = new NodoRua(rua);
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
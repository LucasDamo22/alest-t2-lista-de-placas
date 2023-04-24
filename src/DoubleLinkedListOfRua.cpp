#include <string>
#include <sstream>
#include "DoubleLinkedListOfRua.h"

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
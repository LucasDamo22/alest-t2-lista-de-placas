#include <string>
#include <iostream>
#include <sstream>
#include "HelperFunc.h"
#include "LinkedListOfPlaca.h"

LinkedListOfPlaca::LinkedListOfPlaca()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}
void LinkedListOfPlaca::imprimeLista()
{
    NodoPlaca *ptr;
    if (head == nullptr)
    {
        std::cout << " --Lista de Placas desta rua está vazia;" << std::endl;
        return;
    }
    ptr = head;
    do
    {
        std::cout << ptr->toString() << std::endl;
        ptr = ptr->next;

    } while (ptr != nullptr);
}
void LinkedListOfPlaca::add(std::string tipoPlaca, std::string latitude, std::string longitude, std::string data)
{

    NodoPlaca *n = new NodoPlaca(tipoPlaca, latitude, longitude, data);
    if (head == nullptr)
    {
        head = n;
    }
    else
    {
        tail->next = n;
    }
    tail = n;
    count++;
}
void LinkedListOfPlaca::addInOrder(std::string tipoPlaca, std::string latitude, std::string longitude, std::string data)
{
    NodoPlaca *n = new NodoPlaca(tipoPlaca, latitude, longitude, data);
    NodoPlaca *ptr;
    count++;

    if (head == nullptr)
    {
        head = n;
        tail = n;

        return;
    }
    else
    {
        ptr = head;
        if ((compare1minor2(ptr->data, n->data) > 0) /*&& compare1minor2(ptr->next->data,n->data)>0*/)
        {
            n->next = head;
            head = n;

            return;
        }

        while (ptr->next != nullptr)
        {

            if ((compare1minor2(ptr->data, n->data) <= 0) && compare1minor2(ptr->next->data, n->data) > 0)
            {

                break;
            }

            ptr = ptr->next;
        }
        if (ptr->next == nullptr)
        {
            ptr->next = n;
            tail = n;
            return;
        }
        n->next = ptr->next;
        ptr->next = n;
    }
}
bool LinkedListOfPlaca::isEmpty()
{
    return (head == nullptr);
}

int LinkedListOfPlaca::size()
{
    return count;
}
NodoPlaca *LinkedListOfPlaca::get_head()
{
    return head;
}
NodoPlaca *LinkedListOfPlaca::get_tail()
{
    return tail;
}

int LinkedListOfPlaca::compare_data(std::string target){
    NodoPlaca* ptr = head;
    int count = 0;
    
    if(head == nullptr){
        
        return count;
    }
    while(ptr!=nullptr){
        if(target == ptr->data){
            // std::cout<< target <<" -- "<<ptr->data<<std::endl;
            count++;
        }
        // if(compare1minor2(target,ptr->data)>0){
        //     break;
        // }
        ptr = ptr->next;    
    }
    return count;
}

std::string LinkedListOfPlaca::semLatLong(std::string rua, int &meucont){
    NodoPlaca* ptr=head;
    std::stringstream ss;
    std::stringstream ssS;
    int count = 0;
    if(head==nullptr){
        
        return ss.str();
    }else{
        
        while(ptr!=nullptr){
            if(ptr->latitude==""||ptr->longitude==""){
                ssS<<ptr->toString()<<std::endl;
                count++;
                meucont++;
            }

            ptr =  ptr->next;
        }
        if(count==0){
            return ss.str();
        }else{
            ss<<"Placas sem Lat ou Long na rua: "<<rua<<std::endl<<"---"<<std::endl;
            ss << ssS.str();
            return ss.str();

        }
    }

}
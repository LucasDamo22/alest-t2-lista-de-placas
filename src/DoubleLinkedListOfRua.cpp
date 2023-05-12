#include <string>
#include <sstream>
#include <iostream>
#include <list>
#include <algorithm>
#include "HelperFunc.h"
#include "DoubleLinkedListOfRua.h"
#define IndexOutOfBoundsException 0

DoubleLinkedListOfRua::DoubleLinkedListOfRua()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->count = 0;
}
void DoubleLinkedListOfRua::imprimeLista()
{
    NodoRua *ptr;
    if (head == nullptr)
    {
        // printf("--- Lista Vazia\n");
        return;
    }
    // Caso a lista nao esteja vazia
    ptr = head;
    while (true)
    {
        std::cout << ptr->rua << std::endl;
        ptr->placasNaRua->imprimeLista();
        ptr = ptr->next;
        std::cout << "===============" << std::endl;
        if (ptr == nullptr)
            break;
    }
    std::cout << "--- Fim da lista ---" << std::endl;
}
bool DoubleLinkedListOfRua::isEmpty()
{
    if (head != nullptr)
        return true;
    else
        return false;
}
// void DoubleLinkedListOfRua::add(std::string rua,std::string tipoRua){
//     NodoRua *ptr;
//     NodoRua *n = new NodoRua(rua,tipoRua);
//     if(head==nullptr){
//         head = n;
//         tail = n;
//         count++;
//     }else{
//         ptr = head;

//         while(true){
//             if(rua == ptr->rua){
//                 delete n;
//             }else{
//                 ptr = ptr->next;
//             }
//             if(ptr==nullptr){
//                 break;
//             }
//         }
//         tail->next = n;
//         tail->next;
//         count++;
//     }
// }

void DoubleLinkedListOfRua::add(std::string rua, std::string tipoRua, std::string tipoPlaca, std::string latitude, std::string longitude, std::string data)
{
    NodoRua *ptr;
    NodoRua *n = new NodoRua(rua, tipoRua);

    n->placasNaRua->add(tipoPlaca, latitude, longitude, data);

    if (head == nullptr)
    {

        head = n;
        tail = n;
        count++;
        return;
    }
    else
    {

        NodoRua *aux = head;

        for (int i = 0; i < count; i++)
        {

            // se for igual a rua ja existe, sai do loop
            if (aux->rua == rua)
            {
                break;
            }

            if (aux->rua > rua)
            {
                add(i, rua, tipoRua); //
                break;
            }
            aux = aux->next;
        }
        ptr = head;

        // se a rua ja existe, adiciona as infos na lista de placas
        while (ptr != nullptr)
        {
            if (rua == ptr->rua)
            {
                ptr->placasNaRua->addInOrder(tipoPlaca, longitude, latitude, data);
                delete n;
                return;
            }
            else
            {
                ptr = ptr->next;
            }
        }
        // ajusta tail;
        n->prev = tail;
        tail->next = n;

        tail = n;
        count++;
    }
}

void DoubleLinkedListOfRua::add(int index, std::string rua, std::string tipoRua)
{
    if ((index < 0) || (index > count))
    {
        throw IndexOutOfBoundsException;
    }
    NodoRua *n = new NodoRua(rua, tipoRua);
    count++;
    if (index == 0)
    {
        if (head == nullptr)
        { // se a lista estiver vazia
            tail = n;
        }
        else
        { // se a lista não estiver vazia
            n->next = head;
            head->prev = n;
        }
        head = n;
    }
    else if (index == count)
    {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
    else
    { // insere no meio
        NodoRua *ptr = head;
        for (int i = 0; i < index - 1; i++)
            ptr = ptr->next; // caminha até onde inserir
        // faz a inserção e correcao dos pointers
        n->next = ptr->next;
        ptr->next = n;
        n->prev = ptr;
        n->next->prev = n;
    }
}

// int DoubleLinkedListOfRua::totalPLacas(){
//     int placas = 0;
//     NodoRua* ptr;
//     if(head==nullptr){
//         std::cout<<"lista vazia!"<<std::endl;
//         return 0;
//     }else{
//         ptr = head;
//         while(ptr!=nullptr){
//             placas+=ptr->placasNaRua.size();
//             ptr = ptr->next;
//         }
//         return placas;
//     }
// }
int DoubleLinkedListOfRua::totalPLacas()
{
    int placas = 0;
    NodoRua *ptr;
    if (head == nullptr)
    {
        std::cout << "lista vazia!" << std::endl;
        return 0;
    }
    else
    {
        ptr = head;
        while (ptr != nullptr)
        {
            placas += placasNaRua(ptr);
            ptr = ptr->next;
        }

        return placas;
    }
}

int DoubleLinkedListOfRua::placasNaRua(NodoRua *rua)
{
    return rua->placasNaRua->size();
}

int DoubleLinkedListOfRua::size()
{
    return count;
}

NodoRua *DoubleLinkedListOfRua::get_head()
{
    return head;
}
NodoRua *DoubleLinkedListOfRua::get_tail()
{
    return tail;
}

std::string DoubleLinkedListOfRua::diasComMaisPlacas()
{
    std::string datas_vet[10][2];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            datas_vet[i][j] = "0";
        }
    }
    std::list<std::string> datasVerificadas;

    NodoRua *ruaSelec = head;
    NodoPlaca *dataSelec;
    NodoRua *ptr;
    NodoPlaca *placaPtr;

    std::string data_temp;

    if (head == nullptr)
    {
        return 0;
    }

    while (ruaSelec != nullptr) // iterador passando de rua em rua para selecionar as datas a serem comparadas
    {
        std::cout<<ruaSelec->rua<<std::endl;

        dataSelec = ruaSelec->placasNaRua->get_head();
        while (dataSelec != nullptr) // iterador passando de data em data para selecionar a data da vez
        {

            int aparicoes = 0;

            data_temp = dataSelec->get_data();
            ptr = ruaSelec;
             if (std::find(datasVerificadas.begin(), datasVerificadas.end(), data_temp) != datasVerificadas.end())
                    {
                        break;
                    }
            while (ptr != nullptr) // iterador que passa em todas as ruas para comparar com a data escolhida
            {
                // partindo da ultima rua testada
                placaPtr = ptr->placasNaRua->get_head();
                //while (placaPtr != nullptr) // iterador que passa em todas as placas para comparar com a data escolhida
                //{

                   

                    aparicoes += ptr->placasNaRua->compare_data(data_temp);

                    std::cout<<aparicoes<<std::endl;
                    std::cout<<data_temp<<std::endl;
                    std::cout<<"*****************"<<std::endl;
                    //placaPtr = placaPtr->next;
                //}
                    
                if (ptr->next == nullptr)
                {
                    
                    // comparando com as 10 maiores após chegar no final das ruas
                    for (int i = 0; i < 10; i++)
                    {
                        
                        
                        if (std::stoi(datas_vet[i][1]) < aparicoes)
                        {
                               
                            substitui_menor(datas_vet, aparicoes, data_temp);
                        }
                        
                    }
                }
                ptr = ptr->next;

            }
            datasVerificadas.push_back(dataSelec->get_data());
            dataSelec = dataSelec->next;
        }
        
        ruaSelec = ruaSelec->next;
    }
    

    for(auto it : datasVerificadas){
        std::cout<< it <<std::endl;
    }

    std::stringstream ss;
    ss << "Datas que mais acontecem" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        ss << i+1 << "-" << datas_vet[i][0] << " => " << datas_vet[i][1] << std::endl;
    }
    return ss.str();
}
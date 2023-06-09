#include <iostream>
#include <string>
#include <sstream>

#include "HelperFunc.h"
#include "NodoRua.h"
using std::cin;
using std::cout;
using std::endl;

std::string dia(std::string data)
{
    return data.substr(0, data.find("/"));
}

std::string mes(std::string data)
{
    return data.substr(data.find("/") + 1, data.find("/"));
}

std::string ano(std::string data)
{
    return data.substr(data.find_last_of("/") + 1, data.length());
}

// compara se a dataPtr é "antes" da dataN
int compare1minor2(std::string dataPtr, std::string dataN)
{

    if (dataPtr == dataN)
    {
        return 0;
    }
    if (ano(dataPtr) < ano(dataN))
    {
        return -1;
    }
    if ((mes(dataPtr) < mes(dataN)) && (ano(dataPtr) <= ano(dataN)))
    {
        return -1;
    }
    if ((dia(dataPtr) < dia(dataN)) && (mes(dataPtr) <= mes(dataN)) && (ano(dataPtr) <= ano(dataN)))
    {
        return -1;
    }
    return 1;
}
std::string menuSelect()
{
    std::stringstream ss;
    ss << "====================================================================" << endl;
    ss << " 1 para imprimir a lista inteira" << endl;
    ss << " 2 para entrar no modo de navegação" << endl;
    ss << " 3 para o relatório dos 10 dias com mais obras" << endl;
    ss << " 4 para o relatório de sinalizações sem latitude e longitude" << endl;
    ss << " 9 para encerrar a aplicação" << endl;
    ss << "====================================================================" << endl;
    return ss.str();
}

std::string menuNav(NodoRua *iterador)
{
    std::stringstream ss;
    ss << "====================================================================" << endl;
    ss << "--------------------" << endl;
    ss << "  " << iterador->tipoRua << " " << iterador->rua << endl;
    ss << "--------------------" << endl
       << endl;
    ss << "  1 para avançar 1 rua" << endl;
    ss << "  2 para avançar 10 ruas" << endl;
    ss << "  3 para avançar 100 ruas" << endl;
    ss << "  4 para avançar 1000 ruas" << endl;
    ss << "  --------------------------------------- " << endl;
    ss << "  5 para informações da rua: " << iterador->rua << endl;
    ss << "  6 para lista de todas as placas da rua: " << endl;
    ss << "  --------------------------------------- " << endl;
    ss << "  7 para retroceder 1 rua" << endl;
    ss << "  8 para retroceder 10 rua" << endl;
    ss << "  9 para retroceder 100 rua" << endl;
    ss << "  0 para retroceder 1000 rua" << endl;
    ss << "  --------------------------------------- " << endl;
    ss << "  11 para ir para a primeira rua" << endl;
    ss << "  99 para ir para a ultima rua" << endl;
    ss << "  999 para voltar ao menu principal" << endl;
    ss << "====================================================================" << endl;

    return ss.str();
}
std::string infos(NodoRua *iterador, int totalPlacas)
{
    std::stringstream ss;
    float placasnarua = iterador->placasNaRua->size();

    
    
    float qtd_percent = (100*placasnarua)/(totalPlacas);
    
    ss.precision(2);
    
    ss << "Nome da rua: " << iterador->rua << endl;
    ss << "Quantidade de placas: " << iterador->placasNaRua->size() << endl;
       
    ss <<"Corresponde a "<< qtd_percent << "% de todas as placas"<<endl <<endl;

    ss << "Primeira placa na rua: " << endl;
    ss << iterador->placasNaRua->get_head()->toString() << endl;
    ss << "--------------------" << endl
       << endl;

    ss << "Ultima placa:" << endl;
    ss << iterador->placasNaRua->get_tail()->toString() << endl;
    ss << "--------------------" << endl
       << endl;

    return ss.str();
}

NodoRua *navegador(NodoRua *iterador, NodoRua *head, NodoRua *tail, int totalPlacas)
{
    int numSelect = 0;
    do
    {
        cout << menuNav(iterador) << endl;
        cin >> numSelect;
        if (numSelect == 1)
        {
            if (iterador->next != nullptr)
                iterador = iterador->next;
            else
                cout << " fim da lista" << endl;
        }

        else if (numSelect == 2)
        {
            for (int i = 0; i < 10; i++)
            {
                
                if (iterador->next == nullptr)
                {
                    cout << " fim da Lista!" << endl;
                    break;
                }
                iterador = iterador->next;
            }
        }
        else if (numSelect == 3)
        {
            for (int i = 0; i < 100; i++)
            {
                
                if (iterador->next == nullptr)
                {
                    cout << " fim da Lista!" << endl;
                    break;
                }
                iterador = iterador->next;
            }
        }
        else if (numSelect == 4)
        {   
            
            for (int i = 0; i < 1000; i++)
            {
                
                if (iterador->next == nullptr)
                {
                    cout << " fim da Lista!" << endl;
                    break;
                }
                iterador = iterador->next;
            }
        }
        else if (numSelect == 5)
        {
            cout << infos(iterador, totalPlacas) << endl;
        }
        else if (numSelect == 6)
        {
            cout << "--------------------" << endl
                 << endl;
            iterador->placasNaRua->imprimeLista();
            cout << "--------------------" << endl
                 << endl;
        }

        else if (numSelect == 7)
        {
            if (iterador->prev != nullptr)
                iterador = iterador->prev;
            else
                cout << " fim da lista" << endl;
        }

        else if (numSelect == 8)
        {
            for (int i = 0; i < 10; i++)
            {
                
                if (iterador->prev == nullptr)
                {
                    cout << " fim da Lista!" << endl;
                    break;
                }
                iterador = iterador->prev;
            }
        }
        else if (numSelect == 9)
        {
            for (int i = 0; i < 100; i++)
            {
                
                if (iterador->prev == nullptr)
                {
                    cout << " fim da Lista!" << endl;
                    break;
                }
                iterador = iterador->prev;
            }
        }
        else if (numSelect == 0)
        {
            for (int i = 0; i < 1000; i++)
            {
                
                if (iterador->prev == nullptr)
                {
                    cout << " fim da Lista!" << endl;
                    break;
                }
                iterador = iterador->prev;
            }
        }
        else if (numSelect == 11)
        {
            iterador = head;
        }
        else if (numSelect == 99)
        {
            iterador = tail;
        }

    } while (numSelect != 999);
    return iterador;
}

void menu(DoubleLinkedListOfRua *Lista)
{

    NodoRua *iterador = Lista->get_head();
    int numSelect = 0;

    while (numSelect != 9)
    {
        cout << menuSelect() << endl;

        cin >> numSelect;

        if (numSelect == 1)
        {
            Lista->imprimeLista();
        }
        else if (numSelect == 2)
        {
            iterador = navegador(iterador, Lista->get_head(), Lista->get_tail(), Lista->get_total_placas());
        }
        else if (numSelect == 3)
        {
            std::cout << "" << std::endl;
            std::cout << Lista->diasComMaisPlacas();
        }
        else if (numSelect == 4)
        {
            std::cout << "" << std::endl;
            std::cout << Lista->placasSemLatLong();
        }
    }
}

void substitui_menor(std::string vet[][2], int element, std::string data)
{

    int menor_valor = std::stoi(vet[0][1]);
    int pos = 0;

    for (int i = 0; i < 10; i++)
    {
        if (std::stoi(vet[i][1]) < menor_valor)
        {
            menor_valor = std::stoi(vet[i][1]);
            pos = i;
        }
    }

    vet[pos][1] = std::to_string(element);

    vet[pos][0] = data;
}

void ordena(std::string vet[][2]){
    for (int i =0;i<10;i++){
        std::string tempSup = vet[i][0];
        std::string tempinf = vet[i][1];
        int j=i;
            while(j>0 && tempinf > vet[j-1][1]){
                vet[j][0]=vet[j-1][0];
                vet[j][1]=vet[j-1][1];
                j = j-1;
                vet[j][0]=tempSup;
                vet[j][1]=tempinf;
            }
    }
}

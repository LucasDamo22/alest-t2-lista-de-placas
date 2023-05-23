#include<iostream>
#include<fstream>
#include<sstream>
#include "HelperFunc.h"
#include "DoubleLinkedListOfRua.h"

#define DATA_EXTRACAO 0
#define DESCRICAO 1
#define	ESTADO 2
#define	COMPLEMENTO 3	
#define IMPLANTACAO 4
#define LOGRADOURO_NOME 5
#define	NUM_INICIAL 6
#define	NUM_FINAL 7
#define	DEFRONTE 8
#define	CRUZAMENTO_NOME 9
#define	LADO 10
#define FLUXO 11
#define	LOCAL_DE_INSTAL 12
#define	LATITUDE 13
#define	LONGITUDE 14

using namespace std;


void read_record(DoubleLinkedListOfRua *l){
	// ponteiro para o arquivo
	fstream fin;
    std::cout<<"1"<<std::endl;
	// abre o arquivo
	fin.open("./data/data.csv", ios::in);

	// strings auxiliares para leitura
	string line, word, temp;

    // primeira leitura, para eliminar o cabeçalho
    getline(fin, line);

    // enquanto nao for o fim do arquivo... segue lendo...
	while (!fin.eof()) {

		// pega uma linha do arquivo e coloca dentro de "line"
		getline(fin, line);


		// transforma essa linha em um fluxo
		stringstream s(line);

		// lê cada coluna, ou seja, até chegar no ";"
		// e coloca o conteudo dentro de "word"
        int index = 0;
        std::string rua;
        std::string tipoPlaca;
        std::string latitude;
        std::string longitude;
        std::string data;
        std::string tipoRua;
		while (getline(s, word, ';')) {          
            switch(index){
                case(DATA_EXTRACAO):                   
                    break;
                case(DESCRICAO):                   
                    tipoPlaca = word;                  
                    break;
                case (ESTADO):
                    break;
                case (COMPLEMENTO):                   
                    break;
                case (IMPLANTACAO):
                    data = word;                  
                    break;
                case (LOGRADOURO_NOME):
                    {
                    string s = word;
                    tipoRua = s.substr(0, s.find(" "));
                    rua  =s.substr(s.find(" ")+1, s.length());                   
                    }
                    break;
                case (NUM_INICIAL):                    
                    break;
                case (NUM_FINAL):                   
                    break;
                case (DEFRONTE):                   
                    break;
                case (CRUZAMENTO_NOME):                  
                    break;
                case (LADO ):                 
                    break;
                case (FLUXO ):                  
                    break;
                case (LOCAL_DE_INSTAL ):                   
                    break;
                case (LATITUDE ):
                    latitude = word;                   
                    break;
                case (LONGITUDE ):
                    longitude = word;                   
                    break;
                default:
                    break;
            }
            index++;
            
		}
        if(rua!=""){
            l->add(rua,tipoRua,tipoPlaca,latitude,longitude,data);
        }
        
   
	}
    
}

int main(void){

    DoubleLinkedListOfRua* listaRuas = new DoubleLinkedListOfRua();
    
    read_record(listaRuas);
    
 
    menu(listaRuas);
    //std::cout<<listaRuas->totalPLacas()<<std::endl;
    
    
    return 0;
}
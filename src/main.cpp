#include<iostream>
#include<fstream>
#include<sstream>
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

// void read_record(){
// 	// ponteiro para o arquivo
// 	fstream fin;

// 	// abre o arquivo
// 	fin.open("./data/sample.csv", ios::in);

// 	// strings auxiliares para leitura
// 	string line, word, temp;

//     // primeira leitura, para eliminar o cabeçalho
//     getline(fin, line);

//     // enquanto nao for o fim do arquivo... segue lendo...
// 	while (!fin.eof()) {

// 		// pega uma linha do arquivo e coloca dentro de "line"
// 		getline(fin, line);


// 		// transforma essa linha em um fluxo
// 		stringstream s(line);

// 		// lê cada coluna, ou seja, até chegar no ";"
// 		// e coloca o conteudo dentro de "word"
//         cout<<"================================="<<endl;
//         int index = 0;
// 		while (getline(s, word, ';')) {
            
//             switch(index){
//                 case(DATA_EXTRACAO):
//                     cout << "Data de Extracao: " << word << endl;
//                     break;
//                 case(DESCRICAO):
//                     cout << "Descricao: " << word << endl;
//                     break;
//                 case (ESTADO):
//                     cout << "Estado: " << word << endl;
//                     break;
//                 case (COMPLEMENTO):
//                     cout << "Complemento: " << word << endl;
//                     break;
//                 case (IMPLANTACAO):
//                     cout << "Implantação: " << word << endl;
//                     break;
//                 case (LOGRADOURO_NOME):
//                     {
//                     string s = word;
//                     string sType = s.substr(0, s.find(" "));
//                     string logradouro  =s.substr(s.find(" ")+1, s.length());
//                     cout << "Logradouro: " << logradouro <<"  tipo: "<< sType << endl;}
//                     break;
//                 case (NUM_INICIAL):
//                     cout << "Numero Inicial: " << word << endl;
//                     break;
//                 case (NUM_FINAL):
//                     cout << "Numero Final: " << word << endl;
//                     break;
//                 case (DEFRONTE):
//                     cout << "Defronte: " << word << endl;
//                     break;
//                 case (CRUZAMENTO_NOME):
//                     cout << "Nome do Cruzamento: " << word << endl;
//                     break;
//                 case (LADO ):
//                     cout << "Lado: " << word << endl;
//                     break;
//                 case (FLUXO ):
//                     cout << "Fluxo : " << word << endl;
//                     break;
//                 case (LOCAL_DE_INSTAL ):
//                     cout << "Local de Instalação: " << word << endl;
//                     break;
//                 case (LATITUDE ):
//                     cout << "Latitude: " << word << endl;
//                     break;
//                 case (LONGITUDE ):
//                     cout << "Longitude: " << word << endl;
//                     break;
//                 default:
//                     break;
//             }
//             index++;
// 		}
//         // cout << "Pressione Enter para continuar..." << endl;
//         // cin.ignore();
// 	}
    
//}
void read_record(DoubleLinkedListOfRua *l){
	// ponteiro para o arquivo
	fstream fin;

	// abre o arquivo
	fin.open("./data/sample.csv", ios::in);

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
        cout<<"================================="<<endl;
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
                    std::cout<<"dataextra"<<std::endl;
                    break;
                case(DESCRICAO): 
                    std::cout<<"tipoPlaca"<<"word"<<std::endl;
                    tipoPlaca = word;                  
                    break;
                case (ESTADO):
                    break;
                case (COMPLEMENTO):                   
                    break;
                case (IMPLANTACAO):
                    data = word;
                    std::cout<<"data"<<word<<std::endl;
                    break;
                case (LOGRADOURO_NOME):
                    {
                    string s = word;
                    tipoRua = s.substr(0, s.find(" "));
                    rua  =s.substr(s.find(" ")+1, s.length());
                    std::cout<<"rua"<<word<<std::endl;
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
                    std::cout<<"lat"<<word<<std::endl;
                    break;
                case (LONGITUDE ):
                    longitude = word;
                    std::cout<<"long"<<word<<std::endl;
                    break;
                default:
                    break;
            }
            index++;
            
		}
        l->add(rua,tipoRua,tipoPlaca,latitude,longitude,data);
        // cout << "Pressione Enter para continuar..." << endl;
        // cin.ignore();
	}
    
}

int main(void){

    DoubleLinkedListOfRua listaRuas;
    read_record(&listaRuas);
    //listaRuas.imprimeLista();

    //  string s = "TRAV GERMANO GARCIA";
    //  string sId = s.substr(0, s.find(" "));
    //  string token = s.substr(s.find(" ")+1, s.length());
    //  cout << s << endl;
    //  cout << sId << endl;
    //  cout << token << endl;

    // string s1 = "Ipiranga";
    // string s2 = "Bento Goncalves";
    // if(s1.compare(s2) < 0)
    //     cout << s1 << " vem antes de " << s2 << endl;
    // else if(s1.compare(s2) > 0)
    //     cout << s2 << " vem antes de " << s1 << endl;
    // else
    //     cout << s2 << " eh igual a " << s1 << endl;


    return 0;
}
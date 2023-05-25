# alest-t2-lista-de-placas

Para compilar o código use o comando "make" na pasta raiz do projeto.

Para executar acesse o executavel através da pasta raiz do projeto : "./bin/main"

Para remover o executável use o comando "make clean" na pasta raiz do projeto;

## requirements
Built and tested on linux CentOS 7 and Ubuntu 22.04 LTS with C++ 11, and GCC 11.2.1

## alteração de BD
Para alterar o arquivo que o programa faz a consulta é necessário trocar na função "read_record()" no arquivo main.cpp

## observações importantes

Algumas funções do programa imprimem grandes quantidades de dados, como a imprime lista, e o relatorio de sinalizações sem latitude e longitude. Em execução, parece que o programa entrou em loop infinito, entretanto é devido a grande quantidade informações que essas funções geram.


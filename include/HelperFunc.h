#ifndef HELPERFUNC_H
#define HELPERFUNC_H

#include <string>

std::string dia(std::string data){
    return data.substr(0,data.find("/"));
}


std::string mes(std::string data){
    return data.substr(data.find("/")+1,data.find("/"));
}


std::string ano(std::string data){
    return data.substr(data.find_last_of("/")+1,data.length());
}


int compare1minor2(std::string dataPtr,std::string dataN){
    
    if(dataPtr == dataN){
        return 0;
    }
    if(ano(dataPtr) < ano(dataN)){
        return -1;

    }
    if((mes(dataPtr)< mes(dataN)) && (ano(dataPtr) <= ano(dataN))){
        return -1;
    }
    if ((dia(dataPtr) < dia(dataN)) && (mes(dataPtr)<= mes(dataN)) && (ano(dataPtr) <= ano(dataN))){
        return -1;
    }
    return 1;
}


#endif
#ifndef NodoPlaca_h
#define NodoPLaca_h

class NodoPlaca{
    public:
    NodoPlaca* next;
    std::string tipoPlaca;
    std::string latitude;
    std::string longitude;
    std::string data;

    std::string toString();
    NodoPlaca();
    NodoPlaca(std::string tipoPlaca, std::string latitude, std::string longitude, std::string data);
};

#endif
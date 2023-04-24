#ifndef NodoPlaca_h
#define NodoPLaca_h

class NodoPlaca{
    public:
    NodoPlaca* next;
    std::string tipoPlaca;
    std::string latitude;
    std::string longitude;
    NodoPlaca();
    NodoPlaca(std::string tipoPlaca, std::string latitude, std::string longitude);
};

#endif
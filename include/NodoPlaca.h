#ifndef NodoPlaca_h
#define NodoPLaca_h

class NodoPlaca{
    public:
    NodoPlaca* next;
    std::string tipoPlaca;
    std::string latitude;
    std::string longitude;

    std::string to_String();
    NodoPlaca();
    NodoPlaca(std::string tipoPlaca, std::string latitude, std::string longitude);
};

#endif
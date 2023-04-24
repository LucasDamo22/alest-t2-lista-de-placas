
class LinkedListOfPlaca{
  NodoPlaca* head;
  NodoPlaca* tail;
  int count;
  public:
    LinkedListOfPLaca();
    void imprimeLista();
    bool isEmpty();
    int size();
    void clear();
    bool contains(std::string element);
    std::string toString();
    void add(std::string tipoPlaca, std::string latitude, std::string longitude);

};
#include "NodoDobleCircular.h"

class ListaDCircular{
private:
    NodoDobleCircular *cabeza;
public:
    //Constructor
    ListaDCircular();

    //Metodos
    void add_f(string _nCarnet, string _nDPI, string _nombre, string _carrera, string _correo,
               string _password, int _creditos, int _edad);

    void delNodo(string _nDPI);

    void imprimir();

    NodoDobleCircular *encontradoUpdate(string _nDPI);

    NodoDobleCircular *getCabeza();

    void setCabeza(NodoDobleCircular *_cabeza);
};
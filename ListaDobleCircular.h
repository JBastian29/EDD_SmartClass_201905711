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
    void graficarDobleCircular();
    string generarReporte();

    void imprimir();

    NodoDobleCircular *encontradoUpdate(string _nDPI);

    NodoDobleCircular *getCabeza();

    bool verificarDPI(string _nDPI);
    bool verificarCarnet(string _carnet);
    bool verificarCorreo(string _correo);
    bool existeCarnet(string _carnet);

    void setCabeza(NodoDobleCircular *_cabeza);
};
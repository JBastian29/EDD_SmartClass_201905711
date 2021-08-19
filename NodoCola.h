#include <iostream>
#include <string>

using namespace std;

class NodoCola{
private:
    int idError;
    string tipo;
    string descripcion;
    NodoCola *siguiente;
public:
    NodoCola(int _idError, string _tipo, string _descripcion);

    int getIdError();
    string getTipo();
    string getDescripcion();
    NodoCola *getSiguiente();

    void setIdError(int _idError);
    void setTipo(string _tipo);
    void setDescripcion(string _descripcion);
    void setSiguiente(NodoCola *_siguiente);
};


#include <iostream>
#include <string>

using namespace std;

class NodoDobleCircular{
private:
    string nCarnet;
    string nDPI;
    string nombre;
    string carrera;
    string correo;
    string password;
    int creditos;
    int edad;
    NodoDobleCircular *siguiente;
    NodoDobleCircular *anterior;
    bool primero;
public:
    //Constructor
    NodoDobleCircular(string _nCarnet, string _nDPI, string _nombre, string _carrera, string _correo, string _password,
                      int _creditos, int _edad, NodoDobleCircular *_siguiente, NodoDobleCircular *_anterior);

    //Getters
    string getnCarnet();
    string getnDPI();
    string getNombre();
    string getCarrera();
    string getCorreo();
    string getPassword();
    int getCreditos();
    int getEdad();
    NodoDobleCircular *getSiguiente();
    NodoDobleCircular *getAnterior();
    bool getPrimero();

    //Setters
    void setnCarnet(string _nCarnet);
    void setnDPI(string _nDPI);
    void setNombre(string _nombre);
    void setCarrera(string _carrera);
    void setCorreo(string _correo);
    void setPassword(string _password);
    void setCreditos(int _creditos);
    void setEdad(int _edad);
    void setSiguiente(NodoDobleCircular *_siguiente);
    void setAnterior(NodoDobleCircular *_anterior);
    void setPrimero(bool _primero);

};
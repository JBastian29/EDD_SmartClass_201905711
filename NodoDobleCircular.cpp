#include "NodoDobleCircular.h"

//Constructor
NodoDobleCircular ::NodoDobleCircular(string _nCarnet, string _nDPI, string _nombre, string _carrera, string _correo,
                                      string _password, int _creditos, int _edad, NodoDobleCircular *_siguiente,
                                      NodoDobleCircular *_anterior) {
    this->nCarnet=_nCarnet;
    this->nDPI=_nDPI;
    this->nombre=_nombre;
    this->carrera=_carrera;
    this->correo=_correo;
    this->password=_password;
    this->creditos=_creditos;
    this->edad=_edad;
    this->siguiente=_siguiente;
    this->anterior=_anterior;
    this->primero=false;
}

//Getters
string NodoDobleCircular::getnCarnet() {
    return this->nCarnet;
}
string NodoDobleCircular::getnDPI() {
    return this->nDPI;
}
string NodoDobleCircular::getNombre() {
    return this->nombre;
}
string NodoDobleCircular::getCarrera() {
    return this->carrera;
}
string NodoDobleCircular::getCorreo() {
    return this->correo;
}
string NodoDobleCircular::getPassword() {
    return this->password;
}
int NodoDobleCircular::getCreditos() {
    return this->creditos;
}
int NodoDobleCircular::getEdad() {
    return this->edad;
}
NodoDobleCircular *NodoDobleCircular::getSiguiente() {
    return this->siguiente;
}
NodoDobleCircular *NodoDobleCircular::getAnterior() {
    return this->anterior;
}
bool NodoDobleCircular::getPrimero() {
    return this->primero;
}

//Setters
void NodoDobleCircular::setnCarnet(string _nCarnet) {
    this->nCarnet=_nCarnet;
}
void NodoDobleCircular::setnDPI(string _nDPI) {
    this->nDPI=_nDPI;
}
void NodoDobleCircular::setNombre(string _nombre) {
    this->nombre=_nombre;
}
void NodoDobleCircular::setCarrera(string _carrera) {
    this->nombre=_carrera;
}
void NodoDobleCircular::setCorreo(string _correo) {
    this->correo=_correo;
}
void NodoDobleCircular::setPassword(string _password) {
    this->password=_password;
}
void NodoDobleCircular::setCreditos(int _creditos) {
    this->creditos=_creditos;
}
void NodoDobleCircular::setEdad(int _edad) {
    this->edad=_edad;
}
void NodoDobleCircular::setSiguiente(NodoDobleCircular *_siguiente) {
    this->siguiente=_siguiente;
}
void NodoDobleCircular::setAnterior(NodoDobleCircular *_anterior) {
    this->anterior=_anterior;
}
void NodoDobleCircular::setPrimero(bool _primero) {
    this->primero=_primero;
}
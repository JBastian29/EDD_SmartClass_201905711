//
// Created by Sebas on 20/08/2021.
//

#include "NodoDoble.h"

NodoDoble ::NodoDoble(int _id, string _indice , string _carnet, string _nombreTarea, string _descripcion, string _materia, string _fecha,
                      string _hora, string _estado) {
    this->idTarea=_id;
    this->indice=_indice;
    this->carnet=_carnet;
    this->nombreTarea=_nombreTarea;
    this->descripcion=_descripcion;
    this->materia=_materia;
    this->fecha=_fecha;
    this->hora=_hora;
    this->estado=_estado;
    this->siguiente=NULL;
    this->anterior=NULL;
}

/*NodoDoble ::NodoDoble(int _id, NodoMatriz *elementoMatriz) {
    this->idTarea=_id;
    this->elementoMatriz=elementoMatriz;
}*/

int NodoDoble::getIdTarea() {
    return this->idTarea;
}
string NodoDoble::getCarnet() {
    return this->carnet;
}
string NodoDoble::getNombretarea() {
    return this->nombreTarea;
}
string NodoDoble::getDescripcion() {
    return this->descripcion;
}
string NodoDoble::getMateria() {
    return this->materia;
}
string NodoDoble::getFecha() {
    return this->fecha;
}
string NodoDoble::getHora() {
    return this->hora;
}
string NodoDoble::getEstado() {
    return this->estado;
}
string NodoDoble::getIndice() {
    return this->indice;
}
NodoDoble *NodoDoble::getSiguiente() {
    return this->siguiente;
}
NodoDoble *NodoDoble::getAnterior() {
    return this->anterior;
}
/*NodoMatriz *NodoDoble::getElementodeMatriz() {
    return this->elementoMatriz;
}*/


void NodoDoble::setIdTarea(int _ID) {
    this->idTarea=_ID;
}
void NodoDoble::setCarnet(string _carnet) {
    this->carnet=_carnet;
}
void NodoDoble::setNombretarea(string _nombreTarea) {
    this->nombreTarea=_nombreTarea;
}
void NodoDoble::setDescripcion(string _descripcion) {
    this->descripcion=_descripcion;
}
void NodoDoble::setMateria(string _materia) {
    this->materia=_materia;
}
void NodoDoble::setFecha(string _fecha) {
    this->fecha=_fecha;
}
void NodoDoble::setHora(string _hora) {
    this->hora=_hora;
}
void NodoDoble::setEstado(string _estado) {
    this->estado=_estado;
}
void NodoDoble::setIndice(string _indice) {
    this->indice=_indice;
}
void NodoDoble::setSiguiente(NodoDoble *_siguiente) {
    this->siguiente=_siguiente;
}
void NodoDoble::setAnterior(NodoDoble *_anterior) {
    this->anterior=_anterior;
}
/*void NodoDoble::setElementdeMatriz(NodoMatriz *_elementoMatriz) {
    this->elementoMatriz=_elementoMatriz;
}*/
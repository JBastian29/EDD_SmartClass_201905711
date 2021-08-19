//
// Created by Sebas on 18/08/2021.
//

#include "NodoCola.h"

NodoCola ::NodoCola(int _idError, string _tipo, string _descripcion) {
    this->idError=_idError;
    this->tipo=_tipo;
    this->descripcion=_descripcion;
    this->siguiente=NULL;
}

int NodoCola::getIdError() {
    return this->idError;
}
string NodoCola::getTipo() {
    return this->tipo;
}
string NodoCola::getDescripcion() {
    return this->descripcion;
}
NodoCola *NodoCola::getSiguiente() {
    return this->siguiente;
}

void NodoCola::setIdError(int _idError) {
    this->idError=_idError;
}
void NodoCola::setTipo(string _tipo) {
    this->tipo=_tipo;
}
void NodoCola::setDescripcion(string _descripcion) {
    this->descripcion=_descripcion;
}
void NodoCola::setSiguiente(NodoCola *_siguiente) {
    this->siguiente=_siguiente;
}
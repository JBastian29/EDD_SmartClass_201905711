//
// Created by Sebas on 21/08/2021.
//
#include "NodoMatriz.h"

NodoMatriz ::NodoMatriz(string _mes,string _dia, string _hora,string _carnet, string _nombre, string _descripcion,string _materia, string _fecha, string _estado) {
    this->mes=_mes;
    this->dia=_dia;
    this->hora=_hora;
    this->carnet=_carnet;
    this->nombre=_nombre;
    this->descripcion=_descripcion;
    this->materia=_materia;
    this->fecha=_fecha;
    this->estado=_estado;
}

string NodoMatriz::getMes() {
    return this->mes;
}
string NodoMatriz::getDia() {
    return this->dia;
}
string NodoMatriz::getHora() {
    return this->hora;
}
string NodoMatriz::getCarnet() {
    return this->carnet;
}
string NodoMatriz::getNombre() {
    return this->nombre;
}
string NodoMatriz::getDescripcion() {
    return this->descripcion;
}
string NodoMatriz::getMateria() {
    return this->materia;
}
string NodoMatriz::getFecha() {
    return this->fecha;
}
string NodoMatriz::getEstado() {
    return this->estado;
}

void NodoMatriz::setMes(string _mes) {
    this->mes=_mes;
}
void NodoMatriz::setDia(string _dia) {
    this->dia=_dia;
}
void NodoMatriz::setHora(string _hora) {
    this->hora=_hora;
}
void NodoMatriz::setCarnet(string _carnet) {
    this->carnet=_carnet;
}
void NodoMatriz::setNombre(string _nombre) {
    this->nombre=_nombre;
}
void NodoMatriz::setDescripcion(string _descripcion) {
    this->descripcion=_descripcion;
}
void NodoMatriz::setMateria(string _materia) {
    this->materia=_materia;
}
void NodoMatriz::setFecha(string _fecha) {
    this->fecha=_fecha;
}
void NodoMatriz::setEstado(string _estado) {
    this->estado=_estado;
}
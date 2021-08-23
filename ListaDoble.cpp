//
// Created by Sebas on 21/08/2021.
//

#include "ListaDoble.h"
#include "ListaDobleCircular.h"
#include <regex>

ListaDoble ::ListaDoble() {
    setCabeza(NULL);
}

void ListaDoble::add_f(int _id, string _carnet, string _nombreTarea, string _descripcion, string _materia,
                       string _fecha, string _hora, string _estado) {
    NodoDoble *nuevo = new NodoDoble(_id,_carnet,_nombreTarea,_descripcion,_materia,_fecha,_hora,_estado);
    if(getCabeza()==NULL){
        setCabeza(nuevo);
    }else{
        NodoDoble *aux = getCabeza();
        while(aux->getSiguiente()!=NULL){
            aux=aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
        nuevo->setAnterior(aux);
    }
}

bool ListaDoble::verificarMes(string _mes) {
    const regex pattern("^(0?[7-9]|1[01])$");
    return regex_match(_mes,pattern);
}

bool ListaDoble::verificarDia(string _dia) {
    const regex pattern("^(0?[1-9]|[12][0-9]|30)$");
    return regex_match(_dia,pattern);
}

bool ListaDoble::verificarHora(string _hora) {
    const regex pattern("^(0?[8-9]|1[0-6])$");
    return regex_match(_hora,pattern);
}

bool ListaDoble::verificarFecha(string _fecha) {
    const regex pattern("^\\d{4}\\/(0?[7-9]|1[01])\\/(0?[1-9]|[12][0-9]|30)$");
    return regex_match(_fecha,pattern);
}

void ListaDoble::imprimir() {
    NodoDoble *aux = getCabeza();
    while(aux != NULL){
        cout << "==================" << endl;
        cout << "ID              :" << aux->getIdTarea() << endl;
        cout << "Carnet          :" << aux->getCarnet() << endl;
        cout << "Nombre de tarea :" << aux->getNombretarea() << endl;
        cout << "Descripcion     :" << aux->getDescripcion() << endl;
        cout << "Materia         :" << aux->getMateria() << endl;
        cout << "Fecha           :" << aux->getFecha() << endl;
        cout << "Hora            :" << aux->getHora() << endl;
        cout << "Estado          :" << aux->getEstado() << endl;
        aux=aux->getSiguiente();
    }
}


NodoDoble *ListaDoble::getCabeza() {
    return this->cabeza;
}
void ListaDoble::setCabeza(NodoDoble *_cabeza) {
    this->cabeza=_cabeza;
}
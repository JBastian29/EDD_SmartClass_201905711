//
// Created by Sebas on 21/08/2021.
//

#include "ListaDoble.h"
#include "ListaDobleCircular.h"
#include <regex>

ListaDoble ::ListaDoble() {
    setCabeza(NULL);
}

void ListaDoble::add_f(int _id, string _indice, string _carnet, string _nombreTarea, string _descripcion, string _materia,
                       string _fecha, string _hora, string _estado) {
    NodoDoble *nuevo = new NodoDoble(_id,_indice,_carnet,_nombreTarea,_descripcion,_materia,_fecha,_hora,_estado);
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

/*void ListaDoble::add_f(int _id,NodoMatriz *_elementoMatriz) {
    NodoDoble *nuevo = new NodoDoble(_id,_elementoMatriz);
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
}*/

NodoDoble *ListaDoble::encontradoUpdate(int _indice) {
    NodoDoble *aux = getCabeza();
    while(aux!=NULL){
        if(stoi(aux->getIndice())==_indice){
            return aux;
        }
        aux=aux->getSiguiente();
    }
    return false;
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

int ListaDoble::calcularIndice(int _mes, int _dia, int _hora) {
    int indice=0;
    indice=_dia+30*(_hora+9*_mes);
    return indice;
}

bool ListaDoble::verificarIndiceExiste(string _indice) {
    int indice= stoi(_indice);
    NodoDoble *aux = getCabeza();
    while(aux!=NULL){
        if(stoi(aux->getIndice())==indice){
            return true;
        }else{
            return false;
        }
    }
}


int ListaDoble::horaGeneral(string _hora) {
    switch (stoi(_hora)) {
        case 0:
            return 8;
            case 1:
                return 9;
                case 2:
                    return 10;
                    case 3:
                        return 11;
                        case 4:
                            return 12;
                            case 5:
                                return 13;
                                case 6:
                                    return 14;
                                    case 7:
                                        return 15;
                                        case 8:
                                            return 16;
                                            default:
                                                return -1;
    }
}

void ListaDoble::imprimir() {
    NodoDoble *aux = getCabeza();
    while(aux != NULL){
        cout << "==================" << endl;
        cout << "ID              :" << aux->getIdTarea() << endl;
        cout << "Indice          :" << aux->getIndice() << endl;
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
//
// Created by Sebas on 18/08/2021.
//

#include "Cola.h"

Cola::Cola() {
    setCabeza(NULL);
    setUltimo(NULL);
}

void Cola::encolar(int _idError, string _tipo, string _descripcion) {
    NodoCola *nuevo = new NodoCola(_idError,_tipo,_descripcion);
    if(getCabeza()==NULL){
        setCabeza(nuevo);
        setUltimo(nuevo);
    }else{
        getUltimo()->setSiguiente(nuevo);
        setUltimo(nuevo);
    }
}

NodoCola *Cola::desencolar() {
    NodoCola *salida= getCabeza();
    if(getCabeza()==NULL){
        return NULL;
    }else{
        salida=getCabeza();
        setCabeza(getCabeza()->getSiguiente());
    }
    return salida;
}

void Cola::imprimir() {
    NodoCola *aux=getCabeza();
    while(aux!=NULL){
        cout<<aux->getIdError()<<" <-" ;
        aux=aux->getSiguiente();
    }

}

NodoCola *Cola::getCabeza() {
    return this->cabeza;
}
void Cola::setCabeza(NodoCola *_cabeza) {
    this->cabeza=_cabeza;
}

NodoCola *Cola::getUltimo() {
    return this->ultimo;
}
void Cola::setUltimo(NodoCola *_ultimo) {
    this->ultimo=_ultimo;
}
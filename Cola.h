//
// Created by Sebas on 18/08/2021.
//

#ifndef EDD_SMARTCLASS_201905711_COLA_H
#define EDD_SMARTCLASS_201905711_COLA_H

#endif //EDD_SMARTCLASS_201905711_COLA_H

#include "NodoCola.h"

class Cola{
private:
    NodoCola *cabeza;
    NodoCola *ultimo;
public:
    Cola();

    void encolar(int _idError, string _tipo, string _descripcion);
    NodoCola *desencolar();
    void imprimir();
    void graficarCola();

    NodoCola *getCabeza();
    NodoCola *getUltimo();

    void setCabeza(NodoCola *_cabeza);
    void setUltimo(NodoCola *_ultimo);

};
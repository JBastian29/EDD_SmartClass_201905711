//
// Created by Sebas on 21/08/2021.
//

#ifndef EDD_SMARTCLASS_201905711_LISTADOBLE_H
#define EDD_SMARTCLASS_201905711_LISTADOBLE_H

#endif //EDD_SMARTCLASS_201905711_LISTADOBLE_H
#include "NodoDoble.h"

class ListaDoble{
private:
    NodoDoble *cabeza;
public:
    //CONSTRUCTOR
    ListaDoble();

    //METODOS
    void add_f(int _id, string _indice, string _carnet, string _nombreTarea, string _descripcion, string _materia, string _fecha,
               string _hora, string _estado);
    //void add_f(int _id, NodoMatriz *elementoMatriz);

    void delNodo();
    void imprimir();
    NodoDoble *encontradoUpdate(int _indice);

    NodoDoble *getCabeza();

    bool verificarFecha(string _fecha);
    bool verificarHora(string _hora);
    bool verificarDia(string _dia);
    bool verificarMes(string _mes);
    bool verificarIndiceExiste(string _indice);
    void setCabeza(NodoDoble *_cabeza);
    void asignarIndice(int _mes, int _dia, int _hora);
    int calcularIndice(int _mes, int _dia, int _hora);
    int horaGeneral(string _hora);
};
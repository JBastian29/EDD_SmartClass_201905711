//
// Created by Sebas on 20/08/2021.
//

#ifndef EDD_SMARTCLASS_201905711_NODODOBLE_H
#define EDD_SMARTCLASS_201905711_NODODOBLE_H

#endif //EDD_SMARTCLASS_201905711_NODODOBLE_H

#include <iostream>
#include <string>

using namespace std;

class NodoDoble{
private:
    int idTarea;
    string carnet;
    string nombreTarea;
    string descripcion;
    string materia;
    string fecha;
    string hora;
    string estado;
    string indice;
    NodoDoble *siguiente;
    NodoDoble *anterior;
public:
    NodoDoble(int _id,string _carnet, string _nombreTarea, string _descripcion, string _materia, string _fecha, string _hora, string _estado);

    //Getters
    int getIdTarea();
    string getCarnet();
    string getNombretarea();
    string getDescripcion();
    string getMateria();
    string getFecha();
    string getHora();
    string getEstado();
    string getIndice();
    NodoDoble *getSiguiente();
    NodoDoble *getAnterior();

    //SETTERS
    void setIdTarea(int _ID);
    void setCarnet(string _carnet);
    void setNombretarea(string _nombreTarea);
    void setDescripcion(string _descripcion);
    void setMateria(string _materia);
    void setFecha(string _fecha);
    void setHora(string _hora);
    void setEstado(string _estado);
    void setIndice(string _indice);
    void setSiguiente(NodoDoble *_siguiente);
    void setAnterior(NodoDoble *_anterior);

};
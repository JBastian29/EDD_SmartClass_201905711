//
// Created by Sebas on 21/08/2021.
//

#ifndef EDD_SMARTCLASS_201905711_NODOMATRIZ_H
#define EDD_SMARTCLASS_201905711_NODOMATRIZ_H

#endif //EDD_SMARTCLASS_201905711_NODOMATRIZ_H
#include <iostream>
#include <string>

using namespace std;

class NodoMatriz{
private:
    string mes;
    string dia;
    string hora;
    string carnet;
    string nombre;
    string descripcion;
    string materia;
    string fecha;
    string estado;
public:
    NodoMatriz(string _mes, string _dia, string _hora,string _carnet, string _nombre, string _descripcion, string _materia, string _fecha, string _estado);

    string getMes();
    string getDia();
    string getHora();
    string getCarnet();
    string getNombre();
    string getDescripcion();
    string getMateria();
    string getFecha();
    string getEstado();

    void setMes(string _mes);
    void setDia(string _dia);
    void setHora(string _hora);
    void setCarnet(string _carnet);
    void setNombre(string _nombre);
    void setDescripcion(string _descripcion);
    void setMateria(string _materia);
    void setFecha(string _fecha);
    void setEstado(string _estado);

};
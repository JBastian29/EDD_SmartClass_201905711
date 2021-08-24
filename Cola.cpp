//
// Created by Sebas on 18/08/2021.
//

#include "Cola.h"
#include <fstream>

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

int contAr=0;
void Cola::graficarCola(){
    NodoCola *aux=getCabeza();
    string node_data = "";
    string edge_data = "";
    string graph = "digraph List {\nrankdir=LR;\nnode [shape = record, color=black, style=filled, fillcolor=antiquewhite1];Inicio [shape = plaintext,fillcolor=white,label= \"\"];Final [shape = plaintext,fillcolor=white,label= \"\"];\n";
    int counter = 0;
    int otrocont=0;
    bool casoPrimero = true;
    while(aux != NULL){
        //cout<<aux->getNombretarea()<<endl;
        node_data += "Node" + to_string(counter) + "[label=\""
                + "ID           : "+ to_string(aux->getIdError())
                + "\\nTipo           : "+aux->getTipo()
                + "\\nDescripcion        : "+aux->getDescripcion() + "\"];\n";
        counter++;
        aux = aux->getSiguiente();
    }
    graph += node_data;
    counter=counter-1;
    edge_data += "Inicio->Node" + to_string(counter) + ";\n";
    while(counter!=0){
        edge_data += "Node" + to_string(counter) + "->Node" + to_string(counter-1) + ";\n";
        counter= counter-1;
    }
    edge_data += "Node0->Final" ";\n";

    graph += edge_data;
    graph += "\n}";
    //-------------------------------------
    try{
        //Esta variable debe ser modificada para agregar su path de creacion de la Grafica

        ofstream file;
        file.open("QuintoReporte"+ to_string(contAr) +".dot", ios::out);

        if(file.fail()){
            exit(1);
        }
        file<<graph;
        file.close();
        string command = "dot -Tpng QuintoReporte"+ to_string(contAr) +".dot -o QuintoReporte"+ to_string(contAr) +".png";
        system(command.c_str());
        cout<<"****REPORTE DE ERRORES GENERADO CON EXITO****"<<endl;
    }catch(exception e){
        cout<<"Fallo detectado"<<endl;
    }

    contAr=contAr+1;
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
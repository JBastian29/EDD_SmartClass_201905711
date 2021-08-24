#include "ListaDobleCircular.h"
#include<regex>
#include <fstream>


ListaDCircular::ListaDCircular() {          //CONSTRUCTOR
    setCabeza(NULL);
}

void ListaDCircular::add_f(string _nCarnet, string _nDPI, string _nombre, string _carrera, string _correo,      //AGREGAR ELEMENTO A LA LISTA
                           string _password, int _creditos, int _edad) {
    NodoDobleCircular *nuevo= new NodoDobleCircular(_nCarnet,_nDPI,_nombre,_carrera,_correo,_password,_creditos,_edad,NULL,NULL);
    if(getCabeza()==NULL){
        setCabeza(nuevo);
        nuevo->setPrimero(true);
    }else if(getCabeza()->getSiguiente()==NULL){
        NodoDobleCircular *aux = getCabeza();
        aux->setSiguiente(nuevo);
        aux->setAnterior(nuevo);
        nuevo->setAnterior(aux);
        nuevo->setSiguiente(aux);
    }else{
        NodoDobleCircular *aux = getCabeza();
        NodoDobleCircular *ultimo =aux->getAnterior();
        aux->setAnterior(nuevo);
        ultimo->setSiguiente(nuevo);
        nuevo->setSiguiente(aux);
        nuevo->setAnterior(ultimo);
    }
}

void ListaDCircular::delNodo(string _nDPI) {
    if(getCabeza()->getnDPI()==_nDPI){
        setCabeza(getCabeza()->getSiguiente());
        if(getCabeza()!=NULL){
            getCabeza()->setPrimero(true);
            getCabeza()->getAnterior()->getAnterior()->setSiguiente(getCabeza());
            getCabeza()->setAnterior(getCabeza()->getAnterior()->getAnterior());
            if(getCabeza()->getSiguiente()->getPrimero()){
                getCabeza()->setSiguiente(NULL);
                getCabeza()->setAnterior(NULL);
            }
        }
    }else{
        NodoDobleCircular *aux = getCabeza();
        while(!aux->getSiguiente()->getPrimero()){
            if(aux->getSiguiente()->getnDPI() == _nDPI){
                aux->setSiguiente(aux->getSiguiente()->getSiguiente());
                aux->getSiguiente()->setAnterior(aux);
                if(getCabeza()->getSiguiente()->getPrimero()){
                    getCabeza()->setSiguiente(NULL);
                    getCabeza()->setAnterior(NULL);
                    break;
                }
            }
            aux=aux->getSiguiente();
        }
    }
}

/*void ListaDCircular::updateNodo(string _nDPI) {

}*/

NodoDobleCircular *ListaDCircular::encontradoUpdate(string _nDPI) {
    NodoDobleCircular *aux = getCabeza();
    bool casoPrimero = true;
    while(aux!=NULL && (casoPrimero || !aux->getPrimero())){
        if(aux->getnDPI()==_nDPI){
            //ENCONTRADO
            casoPrimero=false;
            return aux;
        }else if(aux->getPrimero()){
            casoPrimero=false;
        }
        aux=aux->getSiguiente();
    }
    return false;
}

void ListaDCircular::imprimir() {
    bool casoPrimero = true;
    for (NodoDobleCircular *actual = getCabeza(); actual != NULL && (casoPrimero || !actual->getPrimero()); actual = actual->getSiguiente()) {
        casoPrimero = false;
        cout << "==================" << endl;
        cout << "Carnet   :" << actual->getnCarnet() << endl;
        cout << "DPI      :" << actual->getnDPI() << endl;
        cout << "Nombre   :" << actual->getNombre() << endl;
        cout << "Carrera  :" << actual->getCarrera() << endl;
        cout << "Password :" << actual->getPassword() << endl;
        cout << "Creditos :" << actual->getCreditos() << endl;
        cout << "Edad     :" << actual->getEdad() << endl;
        cout << "Correo   :" << actual->getCorreo() << endl;
        //cout<<actual->getnCarnet()<<" "<< actual->getnDPI()<<" "<< actual->getNombre()<<" "<< actual->getCarrera()<<" "<< actual->getCorreo()<<" "<< actual->getPassword()<<" "<< actual->getCreditos()<<" "<< actual->getEdad()<<endl;

    }
    casoPrimero = true;
    /*for (NodoDobleCircular *actual = getCabeza(); actual != NULL && (casoPrimero || !actual->getPrimero()); actual = actual->getSiguiente()) {
        casoPrimero = false;
        cout<<actual->getnCarnet()<<" "<< actual->getnDPI()<<" "<< actual->getNombre()<<" "<< actual->getCarrera()<<" "<< actual->getCorreo()<<" "<< actual->getPassword()<<" "<< actual->getCreditos()<<" "<< actual->getEdad()<<endl;
    }*/
}

bool ListaDCircular::verificarDPI(string _nDPI) {
    if(_nDPI.length()<13 || _nDPI.length()>13){
        return false;
    }else{
        return true;
    }
}

bool ListaDCircular::verificarCarnet(string _carnet) {
    if(_carnet.length()<9 || _carnet.length()>9){
        return false;
    }else{
        return true;
    }
}

bool ListaDCircular::existeCarnet(string _carnet) {
    NodoDobleCircular *aux=getCabeza();
    bool casoPrimero = true;
    while(aux!=NULL && (casoPrimero || !aux->getPrimero())){
        if(aux->getnCarnet()==_carnet){
            //ENCONTRADO
            casoPrimero=false;
            return true;
        }else if(aux->getPrimero()){
            casoPrimero=false;
        }
        aux=aux->getSiguiente();
    }
    return false;
}

int contArch=0;
void ListaDCircular::graficarDobleCircular() {
    NodoDobleCircular *aux= getCabeza();
    string node_data = "";
    string edge_data = "";
    string graph = "digraph List {\nconcentrate=true;\nrankdir=LR;\nnode [shape = record, color=black, style=filled, fillcolor=antiquewhite1];\n";
    int counter = 0;
    bool casoPrimero = true;
    while(aux != NULL &&  casoPrimero){
        //cout<<aux->getNombretarea()<<endl;
        node_data += "Node" + to_string(counter) + "[label=\""
                + "Carnet           : "+aux->getnCarnet() + "\n"
                + "\\nDPI           : "+aux->getnDPI()
                + "\\nNombre        : "+aux->getNombre()
                + "\\nCarrera       : "+aux->getCarrera()
                + "\\nPassword      : "+aux->getPassword()
                + "\\nCreditos      : "+to_string(aux->getCreditos())
                + "\\nEdad          : "+to_string(aux->getEdad())+ "\"];\n";
        if(!aux->getSiguiente()->getPrimero()){
            edge_data += "Node" + to_string(counter) + "->Node" + to_string(counter+1) + "[dir=both];\n";
        }if(aux->getSiguiente()->getPrimero()){
            edge_data += "Node" + to_string(counter) + "->Node" + to_string(0) + "[dir=both];\n";
            casoPrimero=false;
            break;
        }
        counter++;
        aux = aux->getSiguiente();
    }
    graph += node_data;
    graph += edge_data;
    graph += "\n}";
    //-------------------------------------
    try{
        //Esta variable debe ser modificada para agregar su path de creacion de la Grafica

        ofstream file;
        file.open("PrimerReporte"+ to_string(contArch) +".dot", ios::out);

        if(file.fail()){
            exit(1);
        }
        file<<graph;
        file.close();
        string command = "dot -Tpng PrimerReporte"+ to_string(contArch) +".dot -o PrimerReporte"+ to_string(contArch) +".png";
        system(command.c_str());
        cout<<"****REPORTE DE ESTUDIANTES GENERADO CON EXITO****"<<endl;
    }catch(exception e){
        cout<<"Fallo detectado"<<endl;
    }

    contArch=contArch+1;
}



bool ListaDCircular::verificarCorreo(string _correo) {
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(_correo,pattern);
}

NodoDobleCircular *ListaDCircular::getCabeza() {
    return this->cabeza;
}
void ListaDCircular::setCabeza(NodoDobleCircular *_cabeza) {
    this->cabeza=_cabeza;
}
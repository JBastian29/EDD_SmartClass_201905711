#include "ListaDobleCircular.h"
#include<regex>



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
        cout<<actual->getnCarnet()<<" "<< actual->getnDPI()<<" "<< actual->getNombre()<<" "<< actual->getCarrera()<<" "<< actual->getCorreo()<<" "<< actual->getPassword()<<" "<< actual->getCreditos()<<" "<< actual->getEdad()<<endl;

    }
    casoPrimero = true;
    for (NodoDobleCircular *actual = getCabeza(); actual != NULL && (casoPrimero || !actual->getPrimero()); actual = actual->getSiguiente()) {
        casoPrimero = false;
        cout<<actual->getnCarnet()<<" "<< actual->getnDPI()<<" "<< actual->getNombre()<<" "<< actual->getCarrera()<<" "<< actual->getCorreo()<<" "<< actual->getPassword()<<" "<< actual->getCreditos()<<" "<< actual->getEdad()<<endl;
    }
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
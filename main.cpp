#include <iostream>
#include <string>
#include "ListaDobleCircular.h"
#include "Cola.h"
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <filesystem>
#define NOMBRE_ARCHIVO "Estudiantes.csv"


void menuPrincipal();
void cargaUsuarios();
void cargaTareas();
void ingresoManual();
void reportes();
void menuUsuarios();
void menuTareas();
void manualUsuarios();
void manualTareas();
void ingresarUsuarios();
void modificarUsuarios();
void eliminarUsuarios();
void ingresarTareas();
void modificarTareas();
void eliminarTareas();


using namespace std;

int main() {
    /*ListaDCircular *lista = new ListaDCircular();
    lista->add_f("34421","48371718","Sebastian","Sistemas","si@si.com","sebas123",56,12);
    lista->add_f("12341","17184837","Juan","Sistemas","no@no.com","Juan123",56,12);
    lista->add_f("45123","11122233","Alexis","Sistemas","si@si.com","sebas123",56,12);
    lista->add_f("55521","33333311","Carlos","Sistemas","si@si.com","sebas123",56,12);
    lista->imprimir();
    lista->delNodo("17184837");
    cout<<"Se imprime de nuevo: "<<endl;
    lista->imprimir();*/

    /*Cola *colita = new Cola();
    colita->encolar(1,"error","Hola buenas");
    colita->encolar(2,"error2","Hola buenas");
    colita->encolar(3,"error3","Hola buenas");
    colita->imprimir();
    cout<<endl<<"DESENCOLANDO: "<<endl;
    colita->desencolar();
    colita->imprimir();*/
    menuPrincipal();
    return 0;
}

void menuPrincipal() {
    int a, b;

    do{
        cout<<"******MENU PRINCIPAL******"<<endl;
        cout<<"1-Carga de usuarios"<<endl;
        cout<<"2-Carga de tareas"<<endl;
        cout<<"3-Ingreso manual"<<endl;
        cout<<"4-Reportes"<<endl;
        cin>>a;

        switch (a) {
            case 1:
                cargaUsuarios();
                break;
                case 2:
                    cargaTareas();
                    break;
                    case 3:
                        ingresoManual();
                        break;
                        case 4:
                            reportes();
                            break;
        }
    }
    while(a!=4);
    system("pause");
}

ListaDCircular *listaCircu = new ListaDCircular();
Cola *colaErrores = new Cola();
int contErrores = 0;

void cargaUsuarios(){
    string ruta;
    cout<<"******CARGA DE USUARIOS******"<<endl;
    cout<<"Ingresa la ruta del archivo .csv: "<<endl;
    cin>>ruta;
    getline(cin, ruta);
    ifstream archivo("D:\\Sebastian"+ruta);
    string linea;
    char delim = ',';
    getline(archivo, linea);
    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        string carnet,DPI,nombre,carrera,password,creditos,edad,correo;
        getline(stream, carnet, delim);
        getline(stream, DPI, delim);
        getline(stream, nombre, delim);
        getline(stream, carrera, delim);
        getline(stream, password, delim);
        getline(stream, creditos, delim);
        getline(stream, edad, delim);
        getline(stream, correo, delim);

        if(listaCircu->verificarDPI(DPI) && listaCircu->verificarCorreo(correo) && listaCircu->verificarCarnet(carnet)){
            // Imprimir
            cout << "==================" << endl;
            cout << "carnet: " << carnet << endl;
            cout << "DPI: " << DPI << endl;
            cout << "nombre: " << nombre << endl;
            cout << "carrera: " << carrera << endl;
            cout << "password: " << password << endl;
            cout << "creditos: " << creditos << endl;
            cout << "edad: " << edad << endl;
            cout << "correo: " << correo << endl;
            listaCircu->add_f(carnet,DPI,nombre,carrera,correo,password,std::stoi(creditos),std::stoi(edad));
        }else if(!listaCircu->verificarDPI(DPI) && listaCircu->verificarCorreo(correo) && listaCircu->verificarCarnet(carnet)){
            cout << "==================" << endl;
            contErrores=contErrores+1;
            colaErrores->encolar(contErrores,"Estudiante","El DPI no presenta formato debido.");
            cout<<"Hay problemas con el DPI, agregado a cola de errores"<<endl;
        }else if(listaCircu->verificarDPI(DPI) && !listaCircu->verificarCorreo(correo) && listaCircu->verificarCarnet(carnet)){
            cout << "==================" << endl;
            contErrores=contErrores+1;
            colaErrores->encolar(contErrores,"Estudiante","El correo no presenta formato debido.");
            cout<<"Hay problemas con el correo electronico, agregado a cola de errores"<<endl;
        }else if(listaCircu->verificarDPI(DPI) && listaCircu->verificarCorreo(correo) && !listaCircu->verificarCarnet(carnet)){
            cout << "==================" << endl;
            contErrores=contErrores+1;
            colaErrores->encolar(contErrores,"Estudiante","El carnet no presenta formato debido.");
            cout<<"Hay problemas con el carnet, agregado a cola de errores"<<endl;
        }
    }
    archivo.close();
    //listaCircu->imprimir();
    colaErrores->imprimir();
    system("pause");
}

void ingresoManual(){
    int a, b;
    do{
        cout<<"******INGRESO MANUAL******"<<endl;
        cout<<"1-Usuarios"<<endl;
        cout<<"2-Tareas"<<endl;
        cout<<"3-Volver al menu principal"<<endl;
        cin>>a;

        switch (a) {
            case 1:
                menuUsuarios();
                break;
                case 2:
                    menuTareas();
                    break;
                    case 3:
                        cout<<"Volviendo al menu principal..."<<endl;
                        break;
        }
    }
    while(a!=3);
    system("pause");
}

void menuUsuarios(){
    int a, b;
    do{
        cout<<"******MENU USUARIOS******"<<endl;
        cout<<"1-Ingresar"<<endl;
        cout<<"2-Modificar"<<endl;
        cout<<"3-Eliminar"<<endl;
        cout<<"4-Salir"<<endl;
        cin>>a;

        switch (a) {
            case 1:
                ingresarUsuarios();
                break;
                case 2:
                    modificarUsuarios();
                    break;
                    case 3:
                        eliminarUsuarios();
                        break;
                        case 4:
                            cout<<"Volviendo al menu anterior..."<<endl;
                            break;
        }
    }
    while(a!=3);
    system("pause");
}



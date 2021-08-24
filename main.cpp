#include <iostream>
#include <string>
#include "ListaDobleCircular.h"
#include "Cola.h"
#include "NodoMatriz.h"
#include "ListaDoble.h"
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
void imprimirUsuario(string carnet, string dpi, string nombre, string carrera, string correo, string password, int creditos, int edad);


using namespace std;

ListaDCircular *listaCircu = new ListaDCircular();
Cola *colaErrores = new Cola();
int contErrores = 0;
NodoMatriz *matrizT[5][30][9];
ListaDoble *listaDoble = new ListaDoble();
int contaTareas=0;

int getIndexMes(string _mes){
    switch (stoi(_mes)) {
        case 7:
            return 0;
            case 8:
                return 1;
                case 9:
                    return 2;
                    case 10:
                        return 3;
                        case 11:
                            return 4;
                            default:
                                return -1;
    }
}
int getIndexHora(string _hora){
    switch (stoi(_hora)) {
        case 8:
            return 0;
            case 9:
                return 1;
                case 10:
                    return 2;
                    case 11:
                        return 3;
                        case 12:
                            return 4;
                            case 13:
                                return 5;
                                case 14:
                                    return 6;
                                    case 15:
                                        return 7;
                                        case 16:
                                            return 8;
                                            default:
                                                return -1;
    }
}                 //mes-dia-hora


int main() {
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
                            //reportes();
                            break;
        }
    }
    while(a!=4);
    system("pause");
    return 0;
}

void imprimirUsuario(string carnet, string dpi, string nombre, string carrera, string correo, string password, int creditos, int edad){
    cout << "==================" << endl;
    cout << "Carnet   :" << carnet << endl;
    cout << "DPI      :" << dpi << endl;
    cout << "Nombre   :" << nombre << endl;
    cout << "Carrera  :" << carrera << endl;
    cout << "Password :" << password << endl;
    cout << "Creditos :" << creditos << endl;
    cout << "Edad     :" << edad << endl;
    cout << "Correo   :" << correo << endl;
}


void menuPrincipal() {

}



void cargaUsuarios(){
    string ruta;
    cout<<"******CARGA DE USUARIOS******"<<endl;
    cout<<"Ingresa la ruta del archivo .csv: "<<endl;
    cin.ignore();
    getline(cin, ruta);
    ifstream archivo(ruta);
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
            imprimirUsuario(carnet, DPI, nombre, carrera, correo, password, std::stoi(creditos), std::stoi(edad));
            listaCircu->add_f(carnet,DPI,nombre,carrera,correo,password,std::stoi(creditos),std::stoi(edad));
        }else if(!listaCircu->verificarDPI(DPI)){
            cout << "==================" << endl;
            contErrores=contErrores+1;
            colaErrores->encolar(contErrores,"Estudiante","El DPI no presenta formato debido.");
            cout<<"Hay problemas con el DPI, agregado a cola de errores"<<endl;
        }else if(!listaCircu->verificarCorreo(correo)){
            cout << "==================" << endl;
            contErrores=contErrores+1;
            colaErrores->encolar(contErrores,"Estudiante","El correo no presenta formato debido.");
            cout<<"Hay problemas con el correo electronico, agregado a cola de errores"<<endl;
        }else if(!listaCircu->verificarCarnet(carnet)){
            cout << "==================" << endl;
            contErrores=contErrores+1;
            colaErrores->encolar(contErrores,"Estudiante","El carnet no presenta formato debido.");
            cout<<"Hay problemas con el carnet, agregado a cola de errores"<<endl;
        }
    }
    archivo.close();
    //listaCircu->imprimir();
    //colaErrores->imprimir();
    if (listaCircu->getCabeza()!=NULL){
        cout<<"***USUARIOS AGREGADOS CON EXITO***"<<endl;
    }else{
        cout<<"***FAVOR DE REVISAR DATOS***"<<endl;
    }
    main();
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
                        main();
                        break;
        }
    }
    while(a!=3);
    system("pause");
}

void menuUsuarios(){
    int a, b;
    do{
        cout<<"******MENU USUARIOS MANUAL******"<<endl;
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
                            ingresoManual();
                            break;
        }
    }
    while(a!=4);
    system("pause");
}

void ingresarUsuarios(){
    string carnet, dpi, nombre, carrera, correo, password;
    int creditos=0, edad=0;
    cout<<"******INGRESAR ESTUDIANTES MANUALMENTE******"<<endl;
    cout<<"Por favor ingresa el NUMERO DE CARNET del estudiante: "<<endl;
    cin>>carnet;
    if(carnet.length()==9){
        cout<<"Por favor ingresa el DPI del estudiante: "<<endl;
        cin>>dpi;
        cin.ignore();
        if(dpi.length()==13){
            cout<<"Por favor ingresa el NOMBRE del estudiante: "<<endl;
            getline(cin, nombre);
            cout<<"Por favor ingresa la CARRERA del estudiante: "<<endl;
            getline(cin, carrera);
            cout<<"Por favor ingresa el CORREO del estudiante: "<<endl;
            cin>>correo;
            if(listaCircu->verificarCorreo(correo)){
                cout<<"Por favor ingresa el PASSWORD del estudiante: "<<endl;
                cin>>password;
                cout<<"Por favor ingresa los CREDITOS del estudiante: "<<endl;
                cin>>creditos;
                cout<<"Por favor ingresa la EDAD del estudiante: "<<endl;
                cin>>edad;

                imprimirUsuario(carnet, dpi, nombre, carrera, correo, password, creditos, edad);
                listaCircu->add_f(carnet,dpi,nombre,carrera,correo,password,creditos,edad);

            }else{
                cout << "==================" << endl;
                contErrores=contErrores+1;
                colaErrores->encolar(contErrores,"Estudiante Manual","El correo no presenta formato debido.");
                cout<<"Hay problemas con el correo electronico, agregado a cola de errores"<<endl;
            }
        }else{
            cout << "==================" << endl;
            contErrores=contErrores+1;
            colaErrores->encolar(contErrores,"Estudiante Manual","El DPI no presenta formato debido.");
            cout<<"Hay problemas con el DPI, agregado a cola de errores"<<endl;
        }
    }else{
        cout << "==================" << endl;
        contErrores=contErrores+1;
        colaErrores->encolar(contErrores,"Estudiante Manual","El carnet no presenta formato debido.");
        cout<<"Hay problemas con el carnet, agregado a cola de errores"<<endl;
    }
}

void modificarUsuarios(){
    string carnet, dpi, nombre, carrera, correo, password;
    int creditos=0, edad=0;
    cout<<"******MODIFICAR ESTUDIANTES******"<<endl;
    cout<<"Por favor ingresa el DPI del estudiante a modificar: "<<endl;
    cin>>dpi;
    if(listaCircu->encontradoUpdate(dpi)){
        NodoDobleCircular *encontrado = listaCircu->encontradoUpdate(dpi);
        string nDPI;
        int a;
        do{
            cout<<"******¿QUE CAMPO DESEAS MODIFICAR?******"<<endl;
            cout<<"1-Numero de carnet"<<endl;
            cout<<"2-DPI"<<endl;
            cout<<"3-Nombre"<<endl;
            cout<<"4-Carrera"<<endl;
            cout<<"5-Correo"<<endl;
            cout<<"6-Password"<<endl;
            cout<<"7-Creditos"<<endl;
            cout<<"8-Edad"<<endl;
            cout<<"9-Salir"<<endl;
            cin>>a;
            switch (a) {
                case 1:
                    cout<<"Ingrese el nuevo NUMERO DE CARNET:"<<endl;
                    cin>>carnet;
                    if(carnet.length()==9){
                        listaCircu->encontradoUpdate(dpi)->setnCarnet(carnet);
                        cout<<"NUMERO DE CARNET actualizado con exito"<<endl;
                    }else{
                        cout<<"****NUMERO DE CARNET no permitido, por favor revisa tus datos**** "<<endl;
                    }
                    imprimirUsuario(encontrado->getnCarnet(), encontrado->getnDPI(), encontrado->getNombre(), encontrado->getCarrera(), encontrado->getCorreo(), encontrado->getPassword(), encontrado->getCreditos(), encontrado->getEdad());
                    break;
                    case 2:
                        cout<<"Ingrese el nuevo DPI:"<<endl;
                        cin>>nDPI;
                        if(dpi.length()==13){
                            listaCircu->encontradoUpdate(dpi)->setnDPI(nDPI);
                            cout<<"DPI actualizado con exito"<<endl;
                        }else{
                            cout<<"****DPI no permitido, por favor revisa tus datos**** "<<endl;
                        }
                        imprimirUsuario(encontrado->getnCarnet(), encontrado->getnDPI(), encontrado->getNombre(), encontrado->getCarrera(), encontrado->getCorreo(), encontrado->getPassword(), encontrado->getCreditos(), encontrado->getEdad());
                        break;
                        case 3:
                            cout<<"Ingrese el nuevo NOMBRE:"<<endl;
                            cin.ignore();
                            getline(cin,nombre);
                            listaCircu->encontradoUpdate(dpi)->setNombre(nombre);
                            cout<<"NOMBRE actualizado con exito"<<endl;
                            imprimirUsuario(encontrado->getnCarnet(), encontrado->getnDPI(), encontrado->getNombre(), encontrado->getCarrera(), encontrado->getCorreo(), encontrado->getPassword(), encontrado->getCreditos(), encontrado->getEdad());
                            break;
                            case 4:
                                cout<<"Ingrese la nueva CARRERA:"<<endl;
                                cin.ignore();
                                getline(cin,carrera);
                                listaCircu->encontradoUpdate(dpi)->setCarrera(carrera);
                                cout<<"CARRERA actualizada con exito"<<endl;
                                imprimirUsuario(encontrado->getnCarnet(), encontrado->getnDPI(), encontrado->getNombre(), encontrado->getCarrera(), encontrado->getCorreo(), encontrado->getPassword(), encontrado->getCreditos(), encontrado->getEdad());
                                break;
                                case 5:
                                    cout<<"Ingrese el nuevo CORREO:"<<endl;
                                    cin>>correo;
                                    if(listaCircu->verificarCorreo(correo)){
                                        listaCircu->encontradoUpdate(dpi)->setCorreo(correo);
                                        cout<<"CORREO actualizado con exito"<<endl;
                                    }else{
                                        cout<<"****CORREO no permitido, por favor revisa tus datos**** "<<endl;
                                    }
                                    imprimirUsuario(encontrado->getnCarnet(), encontrado->getnDPI(), encontrado->getNombre(), encontrado->getCarrera(), encontrado->getCorreo(), encontrado->getPassword(), encontrado->getCreditos(), encontrado->getEdad());
                                    break;
                                    case 6:
                                        cout<<"Ingrese el nuevo PASSWORD:"<<endl;
                                        cin>>password;
                                        listaCircu->encontradoUpdate(dpi)->setPassword(password);
                                        cout<<"PASSWORD actualizado con exito"<<endl;
                                        imprimirUsuario(encontrado->getnCarnet(), encontrado->getnDPI(), encontrado->getNombre(), encontrado->getCarrera(), encontrado->getCorreo(), encontrado->getPassword(), encontrado->getCreditos(), encontrado->getEdad());
                                        break;
                                        case 7:
                                            cout<<"Ingrese los nuevos CREDITOS:"<<endl;
                                            cin>>creditos;
                                            listaCircu->encontradoUpdate(dpi)->setCreditos(creditos);
                                            cout<<"CREDITOS actualizados con exito"<<endl;
                                            imprimirUsuario(encontrado->getnCarnet(), encontrado->getnDPI(), encontrado->getNombre(), encontrado->getCarrera(), encontrado->getCorreo(), encontrado->getPassword(), encontrado->getCreditos(), encontrado->getEdad());
                                            break;
                                            case 8:
                                                cout<<"Ingrese la nueva EDAD:"<<endl;
                                                cin>>edad;
                                                listaCircu->encontradoUpdate(dpi)->setEdad(edad);
                                                cout<<"EDAD actualizada con exito"<<endl;
                                                imprimirUsuario(encontrado->getnCarnet(), encontrado->getnDPI(), encontrado->getNombre(), encontrado->getCarrera(), encontrado->getCorreo(), encontrado->getPassword(), encontrado->getCreditos(), encontrado->getEdad());
                                                break;
                case 9:
                    menuUsuarios();
                    break;
            }
        }
        while(a!=9);
        system("pause");
    }else{
        cout<<"****DPI no encontrado, por favor revisa tus datos**** "<<endl;
        menuUsuarios();
    }
}

void eliminarUsuarios(){
    string desicion, dpi, nombre;
    cout<<"******ELIMINAR ESTUDIANTES******"<<endl;
    cout<<"Por favor ingresa el DPI del estudiante a eliminar: "<<endl;
    cin>>dpi;
    if(listaCircu->encontradoUpdate(dpi)){
        cout<<"ESTUDIANTE ENCONTRADO, esta seguro que desea eliminarlo?"<<endl;
        cin>> desicion;
        if(desicion == "si"){
            listaCircu->delNodo(dpi);
            listaCircu->imprimir();
        }else{
            menuUsuarios();
        }
    }else{
        cout<<"****DPI no encontrado, por favor revisa tus datos**** "<<endl;
    }
}


void cargaTareas(){
    string ruta;
    string linea;
    char delim = ',';
    int indice=0;
    for (int i=0;i<5;i++){
        for(int j=0;j<30;j++){
            for(int k=0;k<9;k++){
                matrizT[i][j][k]=NULL;
            }
        }
    }
    cout<<"******CARGA DE TAREAS******"<<endl;
    cout<<"Ingresa la ruta del archivo .csv: "<<endl;
    cin.ignore();
    getline (cin, ruta);
    ifstream archivo(ruta);
    getline(archivo, linea);
    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        string mes,dia,hora,carnet,nombre,descripcion,materia,fecha,estado;
        getline(stream, mes, delim);
        getline(stream, dia, delim);
        getline(stream, hora, delim);
        getline(stream, carnet, delim);
        getline(stream, nombre, delim);
        getline(stream, descripcion, delim);
        getline(stream, materia, delim);
        getline(stream, fecha, delim);
        getline(stream, estado, delim);
        if(listaDoble->verificarMes(mes)&&listaDoble->verificarDia(dia)&&listaDoble->verificarHora(hora)&&listaDoble->verificarFecha(fecha)&&listaCircu->existeCarnet(carnet)){
            matrizT[getIndexMes(mes)][stoi(dia)-1][getIndexHora(hora)] = new NodoMatriz(to_string(getIndexMes(mes)),
                                                                                        to_string(stoi(dia)-1),
                                                                                        to_string(getIndexHora(hora)),carnet,nombre,descripcion,materia,fecha,estado);
        }else if(!listaDoble->verificarMes(mes)){
            cout << "==================" << endl;
            contErrores=contErrores+1;
            colaErrores->encolar(contErrores,"Tarea","Mes ingresado : " + mes + " no permitido.");
            cout<<"El mes ingresado esta fuera de rango, agregado a cola de errores"<<endl;
        }else if(!listaDoble->verificarDia(dia)){
            cout << "==================" << endl;
            contErrores=contErrores+1;
            colaErrores->encolar(contErrores,"Tarea","Dia ingresado : " + dia + " no permitido.");
            cout<<"El dia ingresado esta fuera de rango, agregado a cola de errores"<<endl;
        }else if(!listaDoble->verificarHora(hora)){
            cout << "==================" << endl;
            contErrores=contErrores+1;
            colaErrores->encolar(contErrores,"Tarea","Hora ingresada : " + hora + " no permitida.");
            cout<<"La hora ingresada esta fuera de rango, agregado a cola de errores"<<endl;
        }else if(!listaCircu->existeCarnet(carnet)){
            cout << "==================" << endl;
            contErrores=contErrores+1;
            colaErrores->encolar(contErrores,"Tarea","El numero de carnet: "+ carnet +" no se encuentra registrado.");
            cout<<"Numero de carnet no encontrado, agregado a cola de errores"<<endl;
        }else if(!listaDoble->verificarFecha(fecha)){
            cout << "==================" << endl;
            contErrores=contErrores+1;
            colaErrores->encolar(contErrores,"Tarea","Fecha ingresada : " + fecha + " no permitida.");
            cout<<"La fecha ingresada esta fuera de rango, agregado a cola de errores"<<endl;
        }
    }

    for (int i=0;i<5;i++){  //[5][30][9]
        // cout<<"Cara: "<<i<<endl;
        for(int j=0;j<9;j++){
            for(int k=0;k<30;k++){
                //cout<<"Fila: "<< j <<" Columna: "<<k<<" Elemento: "<< matrizT[i][j][k]<<endl;
                //cout<<"|"<<matrizT[i][j][k]<<"|";
                if(matrizT[i][k][j]!=NULL){
                    indice=listaDoble->calcularIndice(i,k,j);
                    listaDoble->add_f(contaTareas, to_string(indice),matrizT[i][k][j]->getCarnet(),matrizT[i][k][j]->getNombre(),
                                      matrizT[i][k][j]->getDescripcion(), matrizT[i][k][j]->getMateria(),
                                      matrizT[i][k][j]->getFecha(),to_string(listaDoble->horaGeneral(matrizT[i][k][j]->getHora())),matrizT[i][k][j]->getEstado());
                    contaTareas=contaTareas+1;
                }
            }
            //cout<<" "<<endl;
        }
    }
    listaDoble->imprimir();
    if (listaDoble->getCabeza()!=NULL){
        cout<<"***TAREAS AGREGADAS Y LINEALIZADAS CON EXITO***"<<endl;
    }else{
        cout<<"***FAVOR DE REVISAR DATOS***"<<endl;
    }

    archivo.close();
    main();
}

void menuTareas(){
    int a, b;
    do{
        cout<<"******MENU TAREAS MANUAL******"<<endl;
        cout<<"1-Ingresar"<<endl;
        cout<<"2-Modificar"<<endl;
        cout<<"3-Eliminar"<<endl;
        cout<<"4-Salir"<<endl;
        cin>>a;
        switch (a) {
            case 1:
                ingresarTareas();
                break;
                case 2:
                    //modificarTareas();
                    break;
                    case 3:
                        //eliminarTareas();
                        break;
                        case 4:
                            cout<<"Volviendo al menu anterior..."<<endl;
                            ingresoManual();
                            break;
        }
    }
    while(a!=4);
    system("pause");
}


void ingresarTareas(){
    string mes,dia,hora,carnet,nombre,descripcion,materia,fecha,estado;
    int indice=0;
    cout<<"******INGRESAR TAREAS MANUALMENTE******"<<endl;
    cout<<"Por favor ingresa el MES de la tarea: "<<endl;
    cin>>mes;
    if(listaDoble->verificarMes(mes)){
        cout<<"Por favor ingresa el DIA de la tarea: "<<endl;
        cin>>dia;
        if(listaDoble->verificarDia(dia)){
            cout<<"Por favor ingresa la HORA de la tarea: "<<endl;
            cin>>hora;
            indice=listaDoble->calcularIndice(getIndexMes(mes),stoi(dia)-1, getIndexHora(hora));
            if(!listaDoble->verificarIndiceExiste(to_string(indice)) && matrizT[getIndexMes(mes)][stoi(dia)-1][getIndexHora(hora)]==NULL){
                if(listaDoble->verificarHora(hora)){
                    cout<<"Por favor ingresa el CARNET del estudiante: "<<endl;
                    cin>>carnet;
                    if(listaCircu->existeCarnet(carnet)){
                        cout<<"Por favor ingresa el NOMBRE de la tarea: "<<endl;
                        cin.ignore();
                        getline(cin,nombre);
                        cout<<"Por favor ingresa la DESCRIPCION de la tarea: "<<endl;
                        getline(cin,descripcion);
                        cout<<"Por favor ingresa la MATERIA de la tarea: "<<endl;
                        getline(cin,materia);
                        cout<<"Por favor ingresa la FECHA de la tarea: "<<endl;
                        cin>>fecha;
                        cout<<"Por favor ingresa el ESTADO de la tarea: "<<endl;
                        cin.ignore();
                        getline(cin,estado);
                        matrizT[getIndexMes(mes)][stoi(dia)-1][getIndexHora(hora)] = new NodoMatriz(to_string(getIndexMes(mes)),
                                                                                                    to_string(stoi(dia)-1),
                                                                                                    to_string(getIndexHora(hora)),carnet,nombre,descripcion,materia,fecha,estado);
                        listaDoble = new ListaDoble();
                        contaTareas = 0;
                        for (int i=0;i<5;i++){  //[5][30][9]
                            for(int j=0;j<9;j++){
                                for(int k=0;k<30;k++){
                                    if(matrizT[i][k][j]!=NULL){
                                        int indi2=listaDoble->calcularIndice(i,k,j);
                                        listaDoble->add_f(contaTareas, to_string(indi2),matrizT[i][k][j]->getCarnet(),matrizT[i][k][j]->getNombre(),
                                                          matrizT[i][k][j]->getDescripcion(), matrizT[i][k][j]->getMateria(),
                                                          matrizT[i][k][j]->getFecha(),to_string(listaDoble->horaGeneral(matrizT[i][k][j]->getHora())),matrizT[i][k][j]->getEstado());
                                        contaTareas=contaTareas+1;
                                    }
                                }
                            }
                        }
                        listaDoble->imprimir();
                    }else{
                        cout << "==================" << endl;
                        contErrores=contErrores+1;
                        colaErrores->encolar(contErrores,"Tarea Manual","El numero de carnet: "+ carnet +" no se encuentra registrado.");
                        cout<<"Numero de carnet no encontrado, agregado a cola de errores"<<endl;
                    }
                }else{
                    cout << "==================" << endl;
                    contErrores=contErrores+1;
                    colaErrores->encolar(contErrores,"Tarea Manual","Hora ingresada : " + hora + " no permitida.");
                    cout<<"La hora ingresada esta fuera de rango, agregado a cola de errores"<<endl;
                }
            }else{
                cout << "==================" << endl;
                contErrores=contErrores+1;
                colaErrores->encolar(contErrores,"Tarea Manual","Indice calculado : " + to_string(indice) + " ya ocupado.");
                cout<<"El indice calculado: "<< to_string(indice) <<" ya esta ocupado, agregado a cola de errores"<<endl;
            }
        }else{
            cout << "==================" << endl;
            contErrores=contErrores+1;
            colaErrores->encolar(contErrores,"Tarea","Dia ingresado : " + dia + " no permitido.");
            cout<<"El dia ingresado esta fuera de rango, agregado a cola de errores"<<endl;
        }
    }else{
        cout << "==================" << endl;
        contErrores=contErrores+1;
        colaErrores->encolar(contErrores,"Tarea","Mes ingresado : " + mes + " no permitido.");
        cout<<"El mes ingresado esta fuera de rango, agregado a cola de errores"<<endl;
    }
    menuTareas();
}

void modificarTareas(){
    string indice;
    cout<<"******MODIFICAR TAREAS******"<<endl;
    cout<<"Por favor ingresa el indice de la tarea a modificar: "<<endl;
    cin>>indice;
    for (int i=0;i<5;i++){  //[5][30][9]
        for(int j=0;j<9;j++){
            for(int k=0;k<30;k++){
                if(matrizT[i][k][j]!=NULL){
                    int indi2=listaDoble->calcularIndice(i,k,j);
                    listaDoble->add_f(contaTareas, to_string(indi2),matrizT[i][k][j]->getCarnet(),matrizT[i][k][j]->getNombre(),
                                      matrizT[i][k][j]->getDescripcion(), matrizT[i][k][j]->getMateria(),
                                      matrizT[i][k][j]->getFecha(),to_string(listaDoble->horaGeneral(matrizT[i][k][j]->getHora())),matrizT[i][k][j]->getEstado());
                    contaTareas=contaTareas+1;
                }
            }
        }
}


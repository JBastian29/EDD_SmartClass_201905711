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
void imprimirTarea(string indice,string mes,string dia,string hora,string carnet,string nombre,string descripcion,string materia,string fecha,string estado);
void reporte1();
void reporte2();
void reporte3();
void reporte4();
void reporte5();
void reporte6();

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
                            reportes();
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

void imprimirTarea(string indice,string mes,string dia,string hora,string carnet,string nombre,string descripcion,string materia,string fecha,string estado){
    cout << "==================" << endl;
    cout << "Indice      :" << indice << endl;
    cout << "Mes         :" << mes << endl;
    cout << "Dia         :" << dia << endl;
    cout << "Hora        :" << hora   << endl;
    cout << "Carnet      :" << carnet << endl;
    cout << "Nombre      :" << nombre << endl;
    cout << "Descripcion :" << descripcion << endl;
    cout << "Materia     :" << materia << endl;
    cout << "Fecha       :" << fecha << endl;
    cout << "Estado      :" << estado << endl;
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
                    modificarTareas();
                    break;
                    case 3:
                        eliminarTareas();
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
    string  indice,mes,dia,hora,carnet,nombre,descripcion,materia,fecha,estado;
    int posiI=0, posiJ=0,posiK=0;
    bool siesta=false;
    cout<<"******MODIFICAR TAREAS******"<<endl;
    cout<<"Por favor ingresa el indice de la tarea a modificar: "<<endl;
    cin>>indice;
    for (int i=0;i<5;i++){  //[5][30][9]
        for(int j=0;j<9;j++){
            for(int k=0;k<30;k++){
                if(matrizT[i][k][j]!=NULL){
                    int indi2=listaDoble->calcularIndice(i,k,j);
                    if(indi2 == stoi(indice) && listaDoble->encontradoUpdate(stoi(indice))){
                        posiI=i;
                        posiK=j;
                        posiJ=k;
                        siesta = true;
                        break;
                    }else{
                        siesta=false;
                    }
                }
            }
            if(siesta){
                break;
            }
        }
        if(siesta){
            break;
        }
    }
    if(siesta){
        int a;
        do{
            cout<<"******INDICE ENCONTRADO, QUE DESEAS MODIFICAR?******"<<endl;
            cout<<"1-Mes"<<endl;
            cout<<"2-Dia"<<endl;
            cout<<"3-Hora"<<endl;
            cout<<"4-Carnet"<<endl;
            cout<<"5-Nombre"<<endl;
            cout<<"6-Descripcion"<<endl;
            cout<<"7-Materia"<<endl;
            cout<<"8-Fecha"<<endl;
            cout<<"9-Estado"<<endl;
            cout<<"10-Salir"<<endl;
            cin>>a;
            switch (a) {
                case 1:
                    cout<<"Ingrese el nuevo MES:"<<endl;
                    cin>>mes;
                    if(listaDoble->verificarMes(mes) && !listaDoble->verificarIndiceExiste(to_string(listaDoble->calcularIndice(getIndexMes(mes),posiJ,posiK)))){
                        matrizT[getIndexMes(mes)][posiJ][posiK]=new NodoMatriz(to_string(getIndexMes(mes)),
                                                                                                                          matrizT[posiI][posiJ][posiK]->getDia(),
                                                                                                                          matrizT[posiI][posiJ][posiK]->getHora(),matrizT[posiI][posiJ][posiK]->getCarnet(),matrizT[posiI][posiJ][posiK]->getNombre(),matrizT[posiI][posiJ][posiK]->getDescripcion(),matrizT[posiI][posiJ][posiK]->getMateria(),matrizT[posiI][posiJ][posiK]->getFecha(),matrizT[posiI][posiJ][posiK]->getEstado());
                        matrizT[posiI][posiJ][posiK]=NULL;
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
                    }else if(!listaDoble->verificarMes(mes)){
                        cout << "==================" << endl;
                        cout<<"****MES fuera de rango, por favor revisa tus datos****"<<endl;
                    }else if(listaDoble->verificarIndiceExiste(to_string(listaDoble->calcularIndice(getIndexMes(mes),posiJ,posiK)))){
                        cout << "==================" << endl;
                        cout<<"****INDICE ocupado, por favor revisa tus datos****"<<endl;
                    }
                    menuTareas();
                    break;
                case 2:
                    cout<<"Ingrese el nuevo DIA:"<<endl;
                    cin>>dia;
                    if(listaDoble->verificarDia(dia) && !listaDoble->verificarIndiceExiste(to_string(listaDoble->calcularIndice(posiI,
                                                                                                                                stoi(dia)-1,posiK)))){
                        matrizT[posiI][stoi(dia)-1][posiK]=new NodoMatriz(matrizT[posiI][posiJ][posiK]->getMes(),
                                                                          to_string(stoi(dia)-1),
                                                                               matrizT[posiI][posiJ][posiK]->getHora(),matrizT[posiI][posiJ][posiK]->getCarnet(),matrizT[posiI][posiJ][posiK]->getNombre(),matrizT[posiI][posiJ][posiK]->getDescripcion(),matrizT[posiI][posiJ][posiK]->getMateria(),matrizT[posiI][posiJ][posiK]->getFecha(),matrizT[posiI][posiJ][posiK]->getEstado());
                        matrizT[posiI][posiJ][posiK]=NULL;
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
                    }else if(!listaDoble->verificarDia(dia)){
                        cout << "==================" << endl;
                        cout<<"****DIA fuera de rango, por favor revisa tus datos****"<<endl;
                    }else if(listaDoble->verificarIndiceExiste(to_string(listaDoble->calcularIndice(posiI,stoi(dia)-1,posiK)))){
                        cout << "==================" << endl;
                        cout<<"****INDICE ocupado, por favor revisa tus datos****"<<endl;
                    }
                    menuTareas();
                    break;
                case 3:
                    cout<<"Ingrese la nueva HORA:"<<endl;
                    cin>>hora;
                    if(listaDoble->verificarHora(hora) && !listaDoble->verificarIndiceExiste(to_string(listaDoble->calcularIndice(posiI,
                                                                                                                                posiJ,
                                                                                                                                  getIndexHora(hora))))){
                        matrizT[posiI][posiJ][getIndexHora(hora)]=new NodoMatriz(matrizT[posiI][posiJ][posiK]->getMes(),
                                                                                 matrizT[posiI][posiJ][posiK]->getDia(),
                                                                                 to_string(getIndexHora(hora)),matrizT[posiI][posiJ][posiK]->getCarnet(),matrizT[posiI][posiJ][posiK]->getNombre(),matrizT[posiI][posiJ][posiK]->getDescripcion(),matrizT[posiI][posiJ][posiK]->getMateria(),matrizT[posiI][posiJ][posiK]->getFecha(),matrizT[posiI][posiJ][posiK]->getEstado());
                        matrizT[posiI][posiJ][posiK]=NULL;
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
                    }else if(!listaDoble->verificarHora(hora)){
                        cout << "==================" << endl;
                        cout<<"****HORA fuera de rango, por favor revisa tus datos****"<<endl;
                    }else if(listaDoble->verificarIndiceExiste(to_string(listaDoble->calcularIndice(posiI,posiJ,
                                                                                                    getIndexHora(hora))))){
                        cout << "==================" << endl;
                        cout<<"****INDICE ocupado, por favor revisa tus datos****"<<endl;
                    }
                    menuTareas();
                    break;
                case 4:
                    cout<<"Ingrese el nuevo CARNET:"<<endl;
                    cin>>carnet;
                    if(listaCircu->existeCarnet(carnet)){
                        matrizT[posiI][posiJ][posiK]->setCarnet(carnet);
                        listaDoble->encontradoUpdate(stoi(indice))->setCarnet(carnet);
                        imprimirTarea(listaDoble->encontradoUpdate(stoi(indice))->getIndice(),matrizT[posiI][posiJ][posiK]->getMes(),matrizT[posiI][posiJ][posiK]->getDia(),matrizT[posiI][posiJ][posiK]->getHora(),matrizT[posiI][posiJ][posiK]->getCarnet(),matrizT[posiI][posiJ][posiK]->getNombre(),matrizT[posiI][posiJ][posiK]->getDescripcion(),matrizT[posiI][posiJ][posiK]->getMateria(),matrizT[posiI][posiJ][posiK]->getFecha(),matrizT[posiI][posiJ][posiK]->getEstado());
                    }else{
                        cout << "==================" << endl;
                        cout<<"****CARNET no registrado, por favor revisa tus datos****"<<endl;
                    }
                    menuTareas();
                    break;
                case 5:
                    cout<<"Ingrese el nuevo NOMBRE:"<<endl;
                    cin.ignore();
                    getline(cin,nombre);
                    matrizT[posiI][posiJ][posiK]->setNombre(nombre);
                    listaDoble->encontradoUpdate(stoi(indice))->setNombretarea(nombre);
                    imprimirTarea(listaDoble->encontradoUpdate(stoi(indice))->getIndice(),matrizT[posiI][posiJ][posiK]->getMes(),matrizT[posiI][posiJ][posiK]->getDia(),matrizT[posiI][posiJ][posiK]->getHora(),matrizT[posiI][posiJ][posiK]->getCarnet(),matrizT[posiI][posiJ][posiK]->getNombre(),matrizT[posiI][posiJ][posiK]->getDescripcion(),matrizT[posiI][posiJ][posiK]->getMateria(),matrizT[posiI][posiJ][posiK]->getFecha(),matrizT[posiI][posiJ][posiK]->getEstado());
                    menuTareas();
                    break;
                case 6:
                    cout<<"Ingrese la nueva DESCRIPCION:"<<endl;
                    cin.ignore();
                    getline(cin,nombre);
                    matrizT[posiI][posiJ][posiK]->setDescripcion(descripcion);
                    listaDoble->encontradoUpdate(stoi(indice))->setDescripcion(descripcion);
                    imprimirTarea(listaDoble->encontradoUpdate(stoi(indice))->getIndice(),matrizT[posiI][posiJ][posiK]->getMes(),matrizT[posiI][posiJ][posiK]->getDia(),matrizT[posiI][posiJ][posiK]->getHora(),matrizT[posiI][posiJ][posiK]->getCarnet(),matrizT[posiI][posiJ][posiK]->getNombre(),matrizT[posiI][posiJ][posiK]->getDescripcion(),matrizT[posiI][posiJ][posiK]->getMateria(),matrizT[posiI][posiJ][posiK]->getFecha(),matrizT[posiI][posiJ][posiK]->getEstado());
                    menuTareas();
                    break;
                case 7:
                    cout<<"Ingrese la nueva MATERIA:"<<endl;
                    cin.ignore();
                    getline(cin,materia);
                    matrizT[posiI][posiJ][posiK]->setMateria(materia);
                    listaDoble->encontradoUpdate(stoi(indice))->setMateria(materia);
                    imprimirTarea(listaDoble->encontradoUpdate(stoi(indice))->getIndice(),matrizT[posiI][posiJ][posiK]->getMes(),matrizT[posiI][posiJ][posiK]->getDia(),matrizT[posiI][posiJ][posiK]->getHora(),matrizT[posiI][posiJ][posiK]->getCarnet(),matrizT[posiI][posiJ][posiK]->getNombre(),matrizT[posiI][posiJ][posiK]->getDescripcion(),matrizT[posiI][posiJ][posiK]->getMateria(),matrizT[posiI][posiJ][posiK]->getFecha(),matrizT[posiI][posiJ][posiK]->getEstado());
                    menuTareas();
                    break;
                case 8:
                    cout<<"Ingrese la nueva FECHA:"<<endl;
                    cin>>fecha;
                    if(listaDoble->verificarFecha(fecha)){
                        matrizT[posiI][posiJ][posiK]->setFecha(fecha);
                        listaDoble->encontradoUpdate(stoi(indice))->setFecha(fecha);
                        imprimirTarea(listaDoble->encontradoUpdate(stoi(indice))->getIndice(),matrizT[posiI][posiJ][posiK]->getMes(),matrizT[posiI][posiJ][posiK]->getDia(),matrizT[posiI][posiJ][posiK]->getHora(),matrizT[posiI][posiJ][posiK]->getCarnet(),matrizT[posiI][posiJ][posiK]->getNombre(),matrizT[posiI][posiJ][posiK]->getDescripcion(),matrizT[posiI][posiJ][posiK]->getMateria(),matrizT[posiI][posiJ][posiK]->getFecha(),matrizT[posiI][posiJ][posiK]->getEstado());
                    }else{
                        cout << "==================" << endl;
                        cout<<"****FECHA con formato incorrecto, por favor revisa tus datos****"<<endl;
                    }
                    menuTareas();
                    break;
                case 9:
                    cout<<"Ingrese el nuevo ESTADO:"<<endl;
                    cin.ignore();
                    getline(cin,estado);
                    matrizT[posiI][posiJ][posiK]->setEstado(estado);
                    listaDoble->encontradoUpdate(stoi(indice))->setEstado(estado);
                    imprimirTarea(listaDoble->encontradoUpdate(stoi(indice))->getIndice(),matrizT[posiI][posiJ][posiK]->getMes(),matrizT[posiI][posiJ][posiK]->getDia(),matrizT[posiI][posiJ][posiK]->getHora(),matrizT[posiI][posiJ][posiK]->getCarnet(),matrizT[posiI][posiJ][posiK]->getNombre(),matrizT[posiI][posiJ][posiK]->getDescripcion(),matrizT[posiI][posiJ][posiK]->getMateria(),matrizT[posiI][posiJ][posiK]->getFecha(),matrizT[posiI][posiJ][posiK]->getEstado());
                    menuTareas();
                    break;
                case 10:
                    menuUsuarios();
                    break;
            }
        }while(a!=10);
    }else{
        cout<<"****INDICE no encontrado, por favor revisa tus datos**** "<<endl;
        menuUsuarios();
    }
}

void eliminarTareas(){
    string indice, desicion;
    int posiI=0, posiJ=0,posiK=0;
    bool siesta=false;
    cout<<"******ELIMINAR TAREAS******"<<endl;
    cout<<"Por favor ingresa el indice de la tarea a eliminar: "<<endl;
    cin>>indice;
    for (int i=0;i<5;i++){  //[5][30][9]
        for(int j=0;j<9;j++){
            for(int k=0;k<30;k++){
                if(matrizT[i][k][j]!=NULL){
                    int indi2=listaDoble->calcularIndice(i,k,j);
                    if(indi2 == stoi(indice) && listaDoble->encontradoUpdate(stoi(indice))){
                        posiI=i;
                        posiK=j;
                        posiJ=k;
                        siesta = true;
                        break;
                    }else{
                        siesta=false;
                    }
                }
            }
            if(siesta){
                break;
            }
        }
        if(siesta){
            break;
        }
    }
    if(siesta){
        imprimirTarea(listaDoble->encontradoUpdate(stoi(indice))->getIndice(),matrizT[posiI][posiJ][posiK]->getMes(),matrizT[posiI][posiJ][posiK]->getDia(),matrizT[posiI][posiJ][posiK]->getHora(),matrizT[posiI][posiJ][posiK]->getCarnet(),matrizT[posiI][posiJ][posiK]->getNombre(),matrizT[posiI][posiJ][posiK]->getDescripcion(),matrizT[posiI][posiJ][posiK]->getMateria(),matrizT[posiI][posiJ][posiK]->getFecha(),matrizT[posiI][posiJ][posiK]->getEstado());
        cout<<"TAREA ENCONTRADA, esta seguro que desea eliminarla?"<<endl;
        cin>> desicion;
        if(desicion == "si"){
            matrizT[posiI][posiJ][posiK]=NULL;
            listaDoble->delNodo(indice);
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
            menuUsuarios();
        }
    }else{
        cout<<"****INDICE no encontrado, por favor revisa tus datos**** "<<endl;
    }

}

void reportes(){
    int a;
    do{
        cout<<"******MENU PRINCIPAL******"<<endl;
        cout<<"1-Reporte sobre lista de estudiantes"<<endl;
        cout<<"2-Reporte sobre lista de tareas linealizadas"<<endl;
        cout<<"3-Busqueda en estructura linealizada"<<endl;
        cout<<"4-Busqueda de posicion en lista linealizada"<<endl;
        cout<<"5-Cola de Errores"<<endl;
        cout<<"6-Codigo generado de salida"<<endl;
        cin>>a;

        switch (a) {
            case 1:
                reporte1();
                break;
                case 2:
                    reporte2();
                    break;
                    case 3:
                        reporte3();
                        break;
                        case 4:
                            reporte4();
                            break;
                            case 5:
                                reporte5();
                                break;
                                case 6:
                                    //reporte6();
                                    break;
        }
    }
    while(a!=6);
    system("pause");
}

void reporte1(){
    cout<<"******GENERANDO REPORTE SOBRE LISTA DE ESTUDIANTES******"<<endl;
    listaCircu->graficarDobleCircular();
    main();
}

void reporte2(){
    cout<<"******GENERANDO REPORTE SOBRE LISTA DE TAREAS******"<<endl;
    listaDoble->graficarDoble();
    main();
}

void reporte3(){
    int i,j,k;
    cout<<"******BUSQUEDA DE TAREA POR COMPONENTES******"<<endl;
    cout<<"Ingrese la componente i(mes): "<<endl;
    cin>>i;
    cout<<"Ingrese la componente j(dia: "<<endl;
    cin>>j;
    cout<<"Ingrese la componente k(hora): "<<endl;
    cin>>k;
    if(listaDoble->encontradoUpdate(listaDoble->calcularIndice(getIndexMes(to_string(i)),j-1,getIndexHora(to_string(k))))){
        cout<<"******TAREA ENCONTRADA******"<<endl;
        cout << "==================" << endl;
        cout << "ID          :" << listaDoble->encontradoUpdate(listaDoble->calcularIndice(getIndexMes(to_string(i)),j-1,getIndexHora(to_string(k))))->getIdTarea() << endl;
        cout << "Indice      :" << listaDoble->encontradoUpdate(listaDoble->calcularIndice(getIndexMes(to_string(i)),j-1,getIndexHora(to_string(k))))->getIndice() << endl;
        cout << "Carnet      :" << listaDoble->encontradoUpdate(listaDoble->calcularIndice(getIndexMes(to_string(i)),j-1,getIndexHora(to_string(k))))->getCarnet() << endl;
        cout << "Nombre      :" << listaDoble->encontradoUpdate(listaDoble->calcularIndice(getIndexMes(to_string(i)),j-1,getIndexHora(to_string(k))))->getNombretarea() << endl;
        cout << "Descripcion :" << listaDoble->encontradoUpdate(listaDoble->calcularIndice(getIndexMes(to_string(i)),j-1,getIndexHora(to_string(k))))->getDescripcion() << endl;
        cout << "Materia     :" << listaDoble->encontradoUpdate(listaDoble->calcularIndice(getIndexMes(to_string(i)),j-1,getIndexHora(to_string(k))))->getMateria() << endl;
        cout << "Fecha       :" << listaDoble->encontradoUpdate(listaDoble->calcularIndice(getIndexMes(to_string(i)),j-1,getIndexHora(to_string(k))))->getFecha() << endl;
        cout << "Hora        :" << listaDoble->encontradoUpdate(listaDoble->calcularIndice(getIndexMes(to_string(i)),j-1,getIndexHora(to_string(k))))->getHora()  << endl;
        cout << "Estado      :" << listaDoble->encontradoUpdate(listaDoble->calcularIndice(getIndexMes(to_string(i)),j-1,getIndexHora(to_string(k))))->getEstado() << endl;
    }else{
        cout<<"****INDICE no encontrado, por favor revisa tus datos**** "<<endl;
    }
    main();
}

void reporte4(){
    int i,j,k;
    cout<<"******BUSQUEDA DE ID POR COMPONENTES******"<<endl;
    cout<<"Ingrese la componente i(mes): "<<endl;
    cin>>i;
    cout<<"Ingrese la componente j(dia: "<<endl;
    cin>>j;
    cout<<"Ingrese la componente k(hora): "<<endl;
    cin>>k;
    if(listaDoble->encontradoUpdate(listaDoble->calcularIndice(getIndexMes(to_string(i)),j-1,getIndexHora(to_string(k))))){
        cout<<"******TAREA ENCONTRADA******"<<endl;
        cout << "==================" << endl;
        cout << "Iniciando la cuenta desde 0, encontramos la tarea en la posicion: "<< listaDoble->encontradoUpdate(listaDoble->calcularIndice(getIndexMes(to_string(i)),j-1,getIndexHora(to_string(k))))->getIdTarea() <<" de la lista linealizada."<< endl;
        cout << "Iniciando la cuenta desde 1, encontramos la tarea en la posicion: "<< listaDoble->encontradoUpdate(listaDoble->calcularIndice(getIndexMes(to_string(i)),j-1,getIndexHora(to_string(k))))->getIdTarea()+1<<" de la lista linealizada." << endl;
    }else{
        cout<<"****INDICE no encontrado, por favor revisa tus datos**** "<<endl;
    }
    main();
}

void reporte5(){
    cout<<"******GENERANDO REPORTE DE ERRORES******"<<endl;
    colaErrores->graficarCola();
    main();
}
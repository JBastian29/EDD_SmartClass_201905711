#include <iostream>
#include "ListaDobleCircular.h"
#include "Cola.h"
#include <stdlib.h>


void menuPrincipal();

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
                cout<<"OPCION1"<<endl;
                break;
                case 2:
                    cout<<"OPCION2"<<endl;
                    break;
                    case 3:
                        cout<<"OPCION3"<<endl;
                        break;
                        case 4:
                            cout<<"OPCION4"<<endl;
                            break;
        }

    }
    while(a!=4);
    system("pause");
}



#include <iostream>
#include "videogame.h"

using namespace std;

int main() {
    int op;
    VideoGame vg;
    Civilizacion c;
    size_t n;
    string nombre;
    Civilizacion *ptr;
    int aux;
    do {
        cout<<endl<<"1) Nombre de Usuario"<<endl;
        cout<<"2) Agregar civilizacion"<<endl;
        cout<<"3) Insertar civilizacion"<<endl;
        cout<<"4) Crear civilizaciones"<<endl;
        cout<<"5) Primera civilizacion"<<endl;
        cout<<"6) Ultima civilizacion"<<endl;
        cout<<"7) Ordenar"<<endl;
        cout<<"8) Eliminar civilizacion"<<endl;
        cout<<"9) Buscar"<<endl;
        cout<<"10) Modificar"<<endl;
        cout<<"11) Resumen"<<endl;
        cout<<"12) Salir"<<endl;
        cin>>op;
        cin.ignore();

        switch(op) {
            case 1:
                cout<<"Nombre de usuario: ";
                getline(cin, nombre);
                vg.setNombreUsuario(nombre);
                break;

            case 2:
                cin>>c;
                vg.agregarCivilizacion(c);
                break;

            case 3:
                cin>>c;
                cout<<"Posicion: ";
                cin>>n;
                cin.ignore();

                if(n >= vg.total())
                    cout<<"Posicion invalida"<<endl;
                else
                    vg.insertar(c, n);
                break;

            case 4:
                cin>>c;
                cout<<"n: ";
                cin>>n;
                cin.ignore();
                vg.inicializar(c, n);
                break;

            case 5:
                if(vg.total() > 0) {
                    c = vg.primeraCivilizacion();
                    cout<<c;
                }
                else
                    cout<<"Posicion invalida"<<endl;
                break;

            case 6:
                if(vg.total() > 0) {
                    c = vg.ultimaCivilizacion();
                    cout<<c;
                }
                else
                    cout<<"Posicion invalida"<<endl;
                break;

            case 7:
                cout<<"1) Por nombre"<<endl;
                cout<<"2) Por posicion en x"<<endl;
                cout<<"3) Por posicion en y"<<endl;
                cout<<"4) Por puntuacion"<<endl;
                cin>>op;
                cin.ignore();
                switch (op) {
                    case 1:
                        vg.ordenarNombre();
                        break;
                    
                    case 2:
                        vg.ordenarUbiX();
                        break;
                    
                    case 3:
                        vg.ordenarUbiY();
                        break;

                    case 4:
                        vg.ordenarPuntuacion();
                        break;
                    
                    default:
                        cout<<"Opcion no valida"<<endl;
                        break;
                }
                break;
        
            case 8:
                cout<<"Nombre: ";
                getline(cin, nombre);
                vg.eliminar(nombre);
                break;

            case 9:
                cout<<"Nombre: ";
                getline(cin, nombre);
                c.setNombre(nombre);
                ptr = vg.buscar(c);
                
                if(ptr == nullptr)
                    cout<<"No encontrado"<<endl;
                
                else
                    cout<<*ptr<<endl;
                break;

            case 10:
                cout<<"Nombre: ";
                getline(cin, nombre);
                c.setNombre(nombre);
                ptr = vg.buscar(c);
                
                if(ptr == nullptr)
                    cout<<"No encontrado"<<endl;
                
                else {
                    cout<<*ptr<<endl;
                    cout<<"1) Modificar nombre"<<endl;
                    cout<<"2) Modificar posicion en x"<<endl;
                    cout<<"3) Modificar posicion en y"<<endl;
                    cout<<"4) Modificar puntuacion"<<endl;
                    cin>>op;
                    cin.ignore();
                    switch (op) {
                    case 1:
                        cout<<"Nuevo nombre: ";
                        getline(cin, nombre);
                        ptr->setNombre(nombre);
                        break;

                    case 2:
                        cout<<"Nueva ubicacion en x: ";
                        cin>>aux;
                        cin.ignore();
                        ptr->setUbicacionEnX(aux);
                        break;

                    case 3:
                        cout<<"Nueva ubicacion en y: ";
                        cin>>aux;
                        cin.ignore();
                        ptr->setUbicacionEnY(aux);
                        break;

                    case 4:
                        cout<<"Nueva puntuacion: ";
                        cin>>aux;
                        cin.ignore();
                        ptr->setPuntuacion(aux);
                        break;
                    
                    default: 
                        cout<<"Opcion no valida"<<endl;
                        break;
                    }
                }
                break;

            case 11:
                vg.mostrar();
                break;

            case 12:
                cout<<"Hasta luego"<<endl<<endl;
                break;

            default:
                cout<<"Opcion invalida"<<endl<<endl;
                break;
        }
    }while(op != 12);

    return 0;
}
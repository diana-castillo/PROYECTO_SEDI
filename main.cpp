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
    Aldeano a;
    Aldeano *ptrA;
    int aux;
    do {
        cout<<endl<<"Nombre de usuario: "<<vg.getNombreUsuario()<<endl;
        cout<<"1) Nombre de Usuario"<<endl;
        cout<<"2) Agregar civilizacion"<<endl;
        cout<<"3) Insertar civilizacion"<<endl;
        cout<<"4) Crear civilizaciones"<<endl;
        cout<<"5) Primera civilizacion"<<endl;
        cout<<"6) Ultima civilizacion"<<endl;
        cout<<"7) Ordenar"<<endl;
        cout<<"8) Eliminar civilizacion"<<endl;
        cout<<"9) Buscar civilizacion"<<endl;
        cout<<"10) Modificar"<<endl;
        cout<<"11) Resumen"<<endl;
        cout<<"12) Salir"<<endl;
        cout<<"13) Respaldar"<<endl;
        cout<<"14) Recuperar"<<endl;
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
                    cout<<left<<setw(11)<<"NOMBRE"<<setw(17)<<"UBICACION EN X"<<setw(17)<<"UBICACION EN Y"<<setw(6)<<"PUNTUACION"<<endl;
                    cout<<c;
                }
                else
                    cout<<"Posicion invalida"<<endl;
                break;

            case 6:
                if(vg.total() > 0) {
                    c = vg.ultimaCivilizacion();
                    cout<<left<<setw(11)<<"NOMBRE"<<setw(17)<<"UBICACION EN X"<<setw(17)<<"UBICACION EN Y"<<setw(6)<<"PUNTUACION"<<endl;
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
                
                else {
                    cout<<left<<setw(11)<<"NOMBRE"<<setw(17)<<"UBICACION EN X"<<setw(17)<<"UBICACION EN Y"<<setw(6)<<"PUNTUACION"<<endl;
                    cout<<*ptr<<endl;
                    do{
                        cout<<"1) Agregar aldeano"<<endl;
                        cout<<"2) Eliminar aldeano"<<endl;
                        cout<<"3) Clasificar aldeanos"<<endl;
                        cout<<"4) Buscar aldeano"<<endl;
                        cout<<"5) Modificar aldeano"<<endl;
                        cout<<"6) Mostrar aldeanos"<<endl;
                        cout<<"7) Salir"<<endl;
                        cin>>op;
                        cin.ignore();
                        switch (op) {
                        case 1:
                            cin>>a;
                            cout<<endl<<"1) Agregar aldeano al inicio"<<endl;
                            cout<<"2) Agregar aldeano al final"<<endl;
                            cin>>op;
                            cin.ignore();
                            switch (op) {
                            case 1:
                                ptr->agregarAldeanoInicio(a);
                                ptr->setPuntuacion(ptr->getPuntuacion()+100);
                                break;

                            case 2:
                                ptr->agregarAldeanoFinal(a);
                                ptr->setPuntuacion(ptr->getPuntuacion()+100);
                                break;
                            
                            default:
                                cout<<"Opcion no valida"<<endl;
                                break;
                            }
                            break;

                        case 2:
                            cout<<"1) Eliminar por nombre"<<endl;
                            cout<<"2) Eliminar aldeanos donde su salud sea menor a x"<<endl;
                            cout<<"3) Eliminar aldeanos donde su edad sea mayor igual a 60"<<endl;
                            cin>>op;
                            cin.ignore();
                            switch (op) {
                            case 1:
                                cout<<"Nombre: ";
                                getline(cin, nombre);
                                ptr->eliminarPorNombre(nombre);
                                cout<<endl;
                                break;
                            
                            case 2:
                                cout<<"x: ";
                                cin>>aux;
                                cin.ignore();
                                ptr->eliminarPorSalud(aux);
                                cout<<endl;
                                break;

                            case 3:
                                 ptr->eliminarPorEdad();
                                break;

                            default:
                                cout<<"Opcion no valida"<<endl;
                                break;
                            }
                            break;

                        case 3:
                            cout<<"1) Clasificar lista de aldeanos por nombre"<<endl;
                            cout<<"2) Clasificar lista de aldeanos por edad"<<endl;
                            cout<<"3) Clasificar lista de aldeanos por salud"<<endl;
                            cin>>op;
                            cin.ignore();
                            switch (op) {
                            case 1:
                                 ptr->ordenarPorNombre();
                                break;
                            
                            case 2:
                                 ptr->ordenarPorEdad();
                                break;
                            
                            case 3:
                                 ptr->ordenarPorSalud();
                                break;
                            
                            default:
                                cout<<"Opcion no valida"<<endl;
                                break;
                            }
                            break;

                        case 4:
                            cout<<"Nombre: ";
                            getline(cin, nombre);
                            a.setNombre(nombre);
                            ptrA =  ptr->buscarAldeano(a);
                            
                            if(ptrA == nullptr)
                                cout<<"No encontrado"<<endl;
                            
                            else
                                cout<<left<<setw(11)<<"NOMBRE"<<setw(10)<<"EDAD"<<setw(10)<<"GENERO"<<setw(6)<<"SALUD"<<endl;
                                cout<<*ptrA<<endl;
                            break;

                        case 5:
                            cout<<"Nombre: ";
                            getline(cin, nombre);
                            a.setNombre(nombre);
                            ptrA =  ptr->buscarAldeano(a);
                            
                            if(ptrA == nullptr)
                                cout<<"No encontrado"<<endl;
                            
                            else {
                                cout<<left<<setw(11)<<"NOMBRE"<<setw(10)<<"EDAD"<<setw(10)<<"GENERO"<<setw(6)<<"SALUD"<<endl;
                                cout<<*ptrA<<endl;
                                cout<<"1) Modificar nombre"<<endl;
                                cout<<"2) Modificar edad"<<endl;
                                cout<<"3) Modificar genero"<<endl;
                                cout<<"4) Modificar salud"<<endl;
                                cin>>op;
                                cin.ignore();
                                switch (op) {
                                case 1:
                                    cout<<"Nuevo nombre: ";
                                    getline(cin, nombre);
                                    ptrA->setNombre(nombre);
                                    cout<<endl;
                                    break;
                                
                                case 2:
                                    cout<<"Nueva edad: ";
                                    cin>>aux;
                                    cin.ignore();
                                    ptrA->setEdad(aux);
                                    cout<<endl;
                                    break;
                                
                                case 3:
                                    cout<<"Nuevo genero: ";
                                    getline(cin, nombre);
                                    ptrA->setGenero(nombre);
                                    cout<<endl;
                                    break;
                                
                                case 4:
                                    cout<<"Nueva salud: ";
                                    cin>>aux;
                                    cin.ignore();
                                    ptrA->setSalud(aux);
                                    cout<<endl;
                                    break;
                                
                                default:
                                    cout<<"Opcion no valida"<<endl;
                                    break;
                                }
                            }
                            break;

                        case 6:
                            ptr->mostrarAldeanos();
                            break;
                        
                        default: 
                            break;
                        }
                    }
                    while(op != 7);
                }
                break;

            case 10:
                cout<<"Nombre: ";
                getline(cin, nombre);
                c.setNombre(nombre);
                ptr = vg.buscar(c);
                
                if(ptr == nullptr)
                    cout<<"No encontrado"<<endl;
                
                else {
                    cout<<left<<setw(11)<<"NOMBRE"<<setw(17)<<"UBICACION EN X"<<setw(17)<<"UBICACION EN Y"<<setw(6)<<"PUNTUACION"<<endl;
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

            case 13:
                vg.respaldar();
                break;
            
            case 14:
                vg.recuperar();
                break;

            default:
                cout<<"Opcion invalida"<<endl<<endl;
                break;
        }
    }while(op != 12);

    return 0;
}
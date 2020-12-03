#include "civilizacion.h"

Civilizacion::Civilizacion() { }

Civilizacion::Civilizacion(const string &nombre, const int &ubicacionEnX, const int &ubicacionEnY, const int &puntuacion)
{
    this->nombre = nombre;
    this->ubicacionEnX = ubicacionEnX;
    this->ubicacionEnY = ubicacionEnY;
    this->puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string &v) {
    nombre = v;
}

string Civilizacion::getNombre() {
    return nombre;
}

void Civilizacion::setUbicacionEnX(const int &v) {
    ubicacionEnX = v;
}

int Civilizacion::getUbicacionEnX() {
    return ubicacionEnX;
}

void Civilizacion::setUbicacionEnY(const int &v) {
    ubicacionEnY = v;
}

int Civilizacion::getUbicacionEnY() {
    return ubicacionEnY;
}

void Civilizacion::setPuntuacion(const int &v) {
    puntuacion = v;
}

int Civilizacion::getPuntuacion(){
    return puntuacion;
}

void Civilizacion::agregarAldeanoInicio(const Aldeano &a) {
    aldeanos.push_front(a);
}

void Civilizacion::agregarAldeanoFinal(const Aldeano &a) {
    aldeanos.push_back(a);
}

void Civilizacion::eliminarPorNombre(const string &nombre) {
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;
        if(nombre == a.getNombre()) {
            aldeanos.erase(it);
            break;
        }
    }
}

void Civilizacion::eliminarPorSalud(const int &x) {
    aldeanos.remove_if([x](const Aldeano &a){ return a.getSalud() < x;});
}

void Civilizacion::eliminarPorEdad() {
    aldeanos.remove_if([](const Aldeano &a){ return a.getEdad() >= 60;});
}

void Civilizacion::mostrarAldeanos() {
    cout<<left;
    cout<<setw(11)<<"NOMBRE";
    cout<<setw(10)<<"EDAD";
    cout<<setw(10)<<"GENERO";
    cout<<setw(6)<<"SALUD";
    cout<<endl;
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++)
        cout<<*it;
    cout<<endl;
}

void Civilizacion::ordenarPorNombre() {
    aldeanos.sort();
}

void Civilizacion::ordenarPorEdad() {
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getEdad() > a2.getEdad();});
}

void Civilizacion::ordenarPorSalud() {
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getSalud() > a2.getSalud();});
}

Aldeano* Civilizacion::buscarAldeano(const Aldeano &a) {
    auto it = find(aldeanos.begin(), aldeanos.end(), a);
    if (it == aldeanos.end())
        return nullptr;
    
    else
        return &(*it);
}

void Civilizacion::respaldarAldeanos() {
    ofstream archivo(getNombre() + ".txt", ios::out);
    
    if (archivo.is_open())
        for (auto it = aldeanos.begin(); it != aldeanos.end(); ++it) {
            Aldeano &a = *it; 
            archivo<<a.getNombre()<<endl;
            archivo<<a.getEdad()<<endl;
            archivo<<a.getGenero()<<endl;
            archivo<<a.getSalud()<<endl;
        }
    archivo.close();
}

void Civilizacion::recuperarAldeanos() {
    ifstream archivo(getNombre() + ".txt");
    if (archivo.is_open()) {
        string temp;
        int aux;
        Aldeano a;

        while(true) {
            getline(archivo, temp);
            if(archivo.eof()) {
                break;
            }
            a.setNombre(temp);

            getline(archivo, temp);
            aux = stoi(temp);
            a.setEdad(aux);

            getline(archivo, temp);
            a.setGenero(temp);

            getline(archivo, temp);
            aux = stoi(temp);
            a.setSalud(aux);

            agregarAldeanoFinal(a);
        }
    }
    archivo.close();
}

void Civilizacion::anular() {
    aldeanos.clear();
}
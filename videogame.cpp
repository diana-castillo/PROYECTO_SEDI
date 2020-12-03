#include "videogame.h"
#include <fstream>
#include <algorithm>

VideoGame::VideoGame() { }

void VideoGame::setNombreUsuario(const string &v) {
    nombreUsuario = v;
}

string VideoGame::getNombreUsuario() {
    return nombreUsuario;
}

void VideoGame::mostrar() {
    cout<<left;
    cout<<setw(11)<<"NOMBRE";
    cout<<setw(17)<<"UBICACION EN X";
    cout<<setw(17)<<"UBICACION EN Y";
    cout<<setw(6)<<"PUNTUACION";
    cout<<endl;
    for(size_t i=0; i<civilizaciones.size(); i++){
        Civilizacion &c = civilizaciones[i];
        cout<<c;
    } 
}

void VideoGame::agregarCivilizacion(const Civilizacion &c) {
    civilizaciones.push_back(c);
}

void VideoGame::insertar(const Civilizacion &c, size_t pos) {
    civilizaciones.insert(civilizaciones.begin()+pos, c);
}

void VideoGame::inicializar(const Civilizacion &c, size_t n) {
    civilizaciones = vector<Civilizacion>(n, c);
}

Civilizacion VideoGame::primeraCivilizacion() {
    return civilizaciones.front();
}

Civilizacion VideoGame::ultimaCivilizacion() {
    return civilizaciones.back();
}

void VideoGame::ordenarNombre() {
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2){return c1.getNombre() > c2.getNombre();});
}

void VideoGame::ordenarUbiX() {
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2){return c1.getUbicacionEnX() > c2.getUbicacionEnX();});
}

void VideoGame::ordenarUbiY() {
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2){return c1.getUbicacionEnY() > c2.getUbicacionEnY();});
}

void VideoGame::ordenarPuntuacion() {
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() > c2.getPuntuacion();});
}

void VideoGame::eliminar(const string &nombre) {
    for (auto it = civilizaciones.begin(); it != civilizaciones.end(); it++){
        Civilizacion &c = *it;
        if(nombre == c.getNombre()) {
            civilizaciones.erase(it);
            break;
        }
    }
}

Civilizacion* VideoGame::buscar(const Civilizacion &c) {
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);
    if (it == civilizaciones.end())
        return nullptr;
    
    else
        return &(*it);
}

size_t VideoGame::total() {
    return civilizaciones.size();
}
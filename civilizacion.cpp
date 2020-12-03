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
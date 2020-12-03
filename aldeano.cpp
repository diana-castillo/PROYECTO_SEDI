#include "aldeano.h"

Aldeano::Aldeano() { }

Aldeano::Aldeano(const string &nombre, const int &edad, const string &genero, const int &salud) {
    this->nombre = nombre;
    this->edad = edad;
    this->genero = genero;
    this->salud = salud;
}

void Aldeano::setNombre(const string &v) {
    nombre = v;
}

string Aldeano::getNombre() {
    return nombre;
}

void Aldeano::setEdad(const int &v) {
    edad = v;
}

int Aldeano::getEdad() const {
    return edad;
}

void Aldeano::setGenero(const string &v) {
    genero = v;
}

string Aldeano::getGenero() {
    return genero;
}

void Aldeano::setSalud(const int &v) {
    salud = v;
}

int Aldeano::getSalud() const {
    return salud;
}
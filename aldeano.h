#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <iomanip>

using namespace std;

class Aldeano
{
    private:
        string nombre;
        int edad;
        string genero;
        int salud;

    public:
        Aldeano();
        Aldeano(const string &nombre, const int &edad, const string &genero, const int &salud);

        void setNombre(const string&);
        string getNombre();

        void setEdad(const int&);
        int getEdad() const;

        void setGenero(const string&);
        string getGenero();

        void setSalud(const int&);
        int getSalud() const;

        friend ostream& operator<<(ostream &out, const Aldeano &a) {
            out<< left;
            out<< setw(11) <<a.nombre;
            out<< setw(10) <<a.edad;
            out<< setw(10) <<a.genero;
            out<< setw(6) <<a.salud;
            out<< endl;
            return out;
        }

        friend istream& operator>>(istream &in, Aldeano &a) {
            cout<<"Nombre: ";
            getline(cin, a.nombre);
            cout<<"Edad: ";
            cin>>a.edad;
            cin.ignore();
            cout<<"Genero: ";
            getline(cin, a.genero);
            cout<<"Salud: ";
            cin>>a.salud;
            cin.ignore();
            return in;
        }

        bool operator==(const Aldeano& a) {
            return nombre == a.nombre;
        }
        bool operator==(const Aldeano& a) const {
            return nombre == a.nombre;
        }
        bool operator<(const Aldeano& a) {
            return nombre < a.nombre;
        }
        bool operator<(const Aldeano& a) const {
            return nombre < a.nombre;
        }
};

#endif
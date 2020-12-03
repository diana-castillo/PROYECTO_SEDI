#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>

using namespace std;

class Civilizacion
{
    private:
        string nombre;
        int ubicacionEnX;
        int ubicacionEnY;
        int puntuacion;

    public:
        Civilizacion();
        Civilizacion(const string &nombre, const int &ubicacionEnX, const int &ubicacionEnY, const int &puntuacion);

        void setNombre(const string&);
        string getNombre();
        
        void setUbicacionEnX(const int&);
        int getUbicacionEnX();
        
        void setUbicacionEnY(const int&);
        int getUbicacionEnY();

        void setPuntuacion(const int&);
        int getPuntuacion();

        friend ostream& operator<<(ostream &out, const Civilizacion &c) {
            out<< left;
            out<< setw(11) <<c.nombre;
            out<< setw(17) <<c.ubicacionEnX;
            out<< setw(17) <<c.ubicacionEnY;
            out<< setw(6) <<c.puntuacion;
            out<< endl;
            return out;
        }

        friend istream& operator>>(istream &in, Civilizacion &c) {
            cout<<"Nombre: ";
            getline(cin, c.nombre);
            cout<<"Ubicacion en X: ";
            cin>>c.ubicacionEnX;
            cout<<"Ubicacion en Y: ";
            cin>>c.ubicacionEnY;
            cout<<"Puntuacion: ";
            cin>>c.puntuacion;
            cin.ignore();
            return in;
        }

        bool operator==(const Civilizacion& c) {
            return nombre == c.nombre;
        }
        bool operator==(const Civilizacion& c) const {
            return nombre == c.nombre;
        }
        bool operator<(const Civilizacion& c) {
            return nombre < c.nombre;
        }
        bool operator<(const Civilizacion& c) const {
            return nombre < c.nombre;
        }
};
#endif
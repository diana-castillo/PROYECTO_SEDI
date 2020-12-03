#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"
#include <vector>

class VideoGame
{
    private:
        string nombreUsuario;
        vector<Civilizacion> civilizaciones;
    
    public:
        VideoGame();
        void setNombreUsuario(const string&);
        string getNombreUsuario();

        void mostrar();
        void agregarCivilizacion(const Civilizacion&);
        void insertar(const Civilizacion&, size_t);
        void inicializar(const Civilizacion&, size_t);
        Civilizacion primeraCivilizacion();
        Civilizacion ultimaCivilizacion();
        void ordenarNombre();
        void ordenarUbiX();
        void ordenarUbiY();
        void ordenarPuntuacion();
        void eliminar(const string&);
        Civilizacion* buscar(const Civilizacion&);
        size_t total();

        friend VideoGame& operator<<(VideoGame &v, const Civilizacion &c) {
            v.agregarCivilizacion(c);
            return v;
        }
};

#endif
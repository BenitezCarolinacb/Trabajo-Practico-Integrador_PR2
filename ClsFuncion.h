#ifndef CLSFUNCION_H_INCLUDED
#define CLSFUNCION_H_INCLUDED

#include "ClsFecha.h"
#include "ClsPelicula.h"
#include "FGenerales.h"
#include "ClsSala.h"

class Funcion {

private:
    Pelicula _IDPelicula;
    Sala _IDSala;
    int _IDFuncion;
    Fecha _fecha;
    float _Precio;
    bool _estado;

public:

    Funcion() {}

    void setIDFuncion(int f) {
        if (f >= 1) {
            _IDFuncion = f;
        }
    }

    void setIDPelicula(Pelicula p) {
        if (p.getIDPelicula() >= 1) {
            _IDPelicula = p;
        }
    }
    void setPrecio(float p) {
           if (p > 0) {
                _Precio = p;
                    }
                }

    void setFecha(Fecha fe) {
        _fecha = fe;
    }

    void setIDSala(Sala s) {
        if (s.getIDSala() >= 1) {
            _IDSala = s;
        }
    }

    void setEstado(bool e) {
        if(e==true || e== false) _estado=e;
    }
    Sala getIDSala() {return _IDSala;}
    Pelicula getIDPelicula() {return _IDPelicula;}
    int getIDFuncion() {return _IDFuncion;}
    Fecha getFecha() {return _fecha;}
    bool getEstado() {return _estado;}
    float getPrecio() {return _Precio;}


    void Cargar() {
        cout << "\n Ingrese Precio: ";
        _Precio=ValidarIngresoFloat();
        cout << "Ingrese información sobre la fecha: ";
        cout << endl;
        _fecha.Cargar();
        _estado = true;
    }
void Mostrar() {
    if (getEstado()) {
        cout << "************************************" << endl;
        cout << "* ID FUNCION: " << _IDFuncion << " " << endl;
        cout << "* ID SALA: " << _IDSala.getIDSala() << " " << endl;
        cout << "* ID PELICULA: " << _IDPelicula.getIDPelicula() << "  " << endl;
        cout << "* Precio: " << _Precio << " " << endl;
        cout << "* Fecha (MM/DD/YY): " << _fecha.getMes() << "/" << _fecha.getDia() << "/" << _fecha.getAnio()<< endl;
        cout << "************************************" << endl;
    }
}

    ~Funcion() {}
};



#endif // CLSFUNCION_H_INCLUDED

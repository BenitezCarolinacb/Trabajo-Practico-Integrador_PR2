#ifndef CLSSALA_H_INCLUDED
#define CLSSALA_H_INCLUDED

#include "FGenerales.h"

class Sala {

private:
    int _IDSala;
    int _CantidadButacas;
    bool _estado;

public:

    Sala() {}

    void setCantidadButacas(int c) {
        if (c > 0) {
            _CantidadButacas = c;
        }
    }


    void setIDSala(int s) {
     if (s >= 1) {
            _IDSala = s;
        }
    }

    void setEstado(bool e) {
        if(e==true || e== false) _estado=e;
    }


    int getIDSala() { return _IDSala; }
    bool getEstado() { return _estado; }
    int getCantidadButacas() { return _CantidadButacas; }


    void Cargar() {
        cout << "\n Ingrese cantidad de butacas: ";
        cin>>_CantidadButacas;
        _estado = true;
    }

    void Mostrar() {
        if (getEstado()) {
            cout << "*************************************************" << endl;
            cout << "ID de SALA: #" << _IDSala << " "<<endl;
            cout << "Cantidad de Butacas: " << _CantidadButacas << " " << endl;
            cout << "*************************************************" << endl;
        }
    }

    ~Sala() {}
};


#endif // CLSSALA_H_INCLUDED

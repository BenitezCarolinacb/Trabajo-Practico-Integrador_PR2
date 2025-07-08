#ifndef CLSCLIENTE_H_INCLUDED
#define CLSCLIENTE_H_INCLUDED

#include "ClsPersona.h"
class Cliente : public Persona {
private:
    int _IDCliente;
    bool _estado;

public:
    Cliente() {}

    void setIDCliente(int n) {
        if (n >= 1) {
            _IDCliente = n;
        }
    }

    void setEstado(bool e) {
        if(e==true || e== false) _estado=e;
    }

    void Cargar() {
        Persona::Cargar();
        _estado = true;
    }

    void Mostrar() {
        if (getEstado()) {
            cout <<"ID DE CLIENTE:"<< _IDCliente << endl;
            Persona::Mostrar();
        }
    }


    int getIDCliente() { return _IDCliente; }
    bool getEstado() { return _estado; }


    ~Cliente() {}
};


#endif // CLSCLIENTE_H_INCLUDED

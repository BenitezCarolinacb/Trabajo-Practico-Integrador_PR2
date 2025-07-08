#ifndef CLSVENDEDOR_H_INCLUDED
#define CLSVENDEDOR_H_INCLUDED

#include "ClsPersona.h"
#include "FGenerales.h"

class Vendedor : public Persona {
private:
    int IDVendedor;
    float sueldo;
    bool estado;

public:

    Vendedor(int nroVendedor=0, float s=0){
    IDVendedor=nroVendedor;
    sueldo=s;
    }

    int getIDVendedor() {return IDVendedor;}
    bool getEstado() {return estado;}
    float getSueldo(){return sueldo;}

    void setSueldo(int s){sueldo=s;}
    void setIDVendedor(int n) {IDVendedor=n;}
    void setEstado(bool e) {estado=e;}

    void Cargar(){
    cout<<"\n Ingrese sueldo: ";
    sueldo=ValidarIngresoFloat();
    Persona::Cargar();
    estado=true;
    }
    void Mostrar()
    {
        if(getEstado())
        {
        cout << "*************************************************" << endl;
        cout<< "ID DE VENDEDOR: "<<IDVendedor<<" "<<endl;
        cout<< "Sueldo del vendedor: "<<sueldo<<" "<<endl;
        Persona::Mostrar();
        }
    }

    ~Vendedor() {}

};


#endif // CLSVENDEDOR_H_INCLUDED

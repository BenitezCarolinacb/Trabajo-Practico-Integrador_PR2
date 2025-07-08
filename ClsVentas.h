#ifndef CLSVENTAS_H_INCLUDED
#define CLSVENTAS_H_INCLUDED


#include "ArchFuncion.h"
#include "ClsFecha.h"
#include "FGenerales.h"
#include "ClsVendedor.h"
#include "ClsPelicula.h"


class Venta {
private:
    int _IDVenta;
    Funcion _funcion;
    Vendedor _vendedor;
    char _medioDePago[20];
    Fecha _fecha;
    int _CantidadEntradas;
    float _Imp;
    bool _estado;

public:
    Venta() {}

    void setIDVenta(int v) {
        if (v > 0) {
            _IDVenta = v;
        }
    }

    void setFuncion(Funcion f) {
        if (f.getIDFuncion() > 0) {
            _funcion = f;
        }
    }

    void setVendedor(Vendedor v) {
        if (v.getIDVendedor() > 0) {
            _vendedor = v;
        }
    }

    void setFecha(Fecha fe) {
        _fecha = fe;
    }

    void setMedioDePago(const char* mp) {
         strcpy(_medioDePago, mp);
        }

    void setCantidadEntradas(int ce) {
        if (ce > 0) {
            _CantidadEntradas = ce;
        }
    }

    void setImp(float im) {
        if (im >= 0) {
            _Imp = im;
        }
    }

    void setEstado(bool e) {
         if(e==true || e== false) _estado=e;
    }

    int getIDVenta() { return _IDVenta; }
    int getIDFuncion() { return _funcion.getIDFuncion(); }
    int getIDVendedor() { return _vendedor.getIDVendedor(); }
    const char* getmedioDePago() { return _medioDePago; }
    int getCantidadEntradas() { return _CantidadEntradas; }
    float getImp() { return _Imp; }
    Fecha getFecha() { return _fecha; }
    bool getEstado() { return _estado; }


    void Cargar() {
        cout << "Ingrese cantidad de entradas que compra: ";
        cin >> _CantidadEntradas;
        cout << "Ingrese medio de pago: ";
        cargarCadena(_medioDePago, 20); // Validar medio de pago si es necesario
        _fecha = DevolverFecha(_funcion.getIDFuncion());
        _Imp = calcularimporte(_funcion.getIDFuncion(), _CantidadEntradas);
        _estado = true;
    }

    void Mostrar() {
    if (getEstado()) {
        cout << "*************************************************" << endl;
        cout << "ID de venta: " << _IDVenta << " " << endl;
        cout << "ID Vendedor: " << _vendedor.getIDVendedor() << " " << endl;
        cout << "ID Funcion: " <<  _funcion.getIDFuncion() << " " << endl;
        cout << "Cantidad de entradas: " << _CantidadEntradas << " " << endl;
        cout << "Forma de pago: " << _medioDePago << " *" << endl;
        cout << "Fecha (MM/DD/YY): " << _fecha.getMes() << "/" << _fecha.getDia() << "/" << _fecha.getAnio() << " " << endl;
        cout << "Precio: "  << _Imp << " " << endl;
        cout << "*************************************************" << endl;
    }
}


    ~Venta() {}
};

#endif // CLSVENTAS_H_INCLUDED

#ifndef CLSPERSONA_H_INCLUDED
#define CLSPERSONA_H_INCLUDED
#include <string.h>
#include <iostream>
using namespace std;
#include "FGenerales.h"

class Persona {
protected:
    char _nombre[50];
    char _apellido[50];
    int _DNI;
    int _numeroTelefono;
    char _email[50];

public:
    void setNombre(const char* n) {
        strcpy(_nombre, n);
    }

    void setApellido(const char* n) {
        strcpy(_apellido, n);
    }

    void setEmail(const char* e) {
        strcpy(_email, e);
    }

    void setDNI(int n) {
        if (n > 0) {
            _DNI = n;
        }
    }

    void setNumeroTelefono(int nt) {
        if (nt > 0) {
            _numeroTelefono = nt;
        }

    }

    const char* getNombre() { return _nombre; }
    const char* getApellido() { return _apellido; }
    const char* getEmail() { return _email; }
    int getDNI() { return _DNI; }
    int getNumeroTelefono() { return _numeroTelefono; }

    void Cargar() {
        cout << "\n Ingrese nombre: ";
        cargarCadena(_nombre, 50);
        cout << "\n Ingrese apellido: ";
        cargarCadena(_apellido, 50);
        cout << "\n Ingrese N# de DNI: ";
        cin>>_DNI;
        cout << "\n Ingrese número de teléfono: ";
        cin>>_numeroTelefono;
        cout << "\n Ingrese email: ";
        cargarCadena(_email, 50);

    }

    void Mostrar() {
                    cout << "*************************************************" << endl;
        cout << _nombre << " ";
        cout << _apellido << " | ";
        cout << "DNI: " << _DNI << " | ";
        cout << "Número de telefono: " << _numeroTelefono << " | ";
        cout << _email << endl;
        cout << "*************************************************" << endl;
    }
};
#endif // CLSPERSONA_H_INCLUDED

#ifndef CLSPELICULA_H_INCLUDED
#define CLSPELICULA_H_INCLUDED

#include <cstring>
#include <iomanip>
#include "FGenerales.h"


class Pelicula {

private:
    int _IDPelicula;
    char _TituloPelicula[50];
    int _Duracion;
    char _Genero[20];
    bool _estado;
public:

    Pelicula(){}

    //set
    void setEstado(bool e) {
                _estado=e;}

    void setIDPelicula(int id){
                if(id>=1)_IDPelicula=id;}

    void setTituloPelicula(const char * t){
     strcpy(_TituloPelicula,t);}

    bool setDuracion(int d){
                    if(d>=90 && d<=400){
                       _Duracion=d;
                       return true;
                    }
                    else {
                    return false;
                    }

                    }

    void setGenero(const char * g){
    strcpy(_Genero,g);}

    // get
     int getIDPelicula(){return _IDPelicula;}
     int getDuracion(){ return _Duracion;}
     bool getEstado() {return _estado;}
     const char * getTituloPelicula(){return _TituloPelicula;}
     const char* getGenero(){return _Genero;}

    bool Cargar() {
        cout<<"Ingrese titulo de la pelicula: ";
        cargarCadena(_TituloPelicula,50);
        cout<<"Ingrese duracion de la pelicula (en minutos): ";
        cin>>_Duracion;
        int validar=setDuracion(_Duracion);
        cout<<"Ingrese genero de la pelicula: ";
        cargarCadena(_Genero, 20);
        _estado=true;
        return validar;

    }


    void Mostrar() {
        if(getEstado()==true)
        {
    cout << "*************************************************" << endl;
    cout << "ID PELICULA: " << _IDPelicula << " " << endl;
    cout << "Titulo: " << _TituloPelicula << "" << endl;
    cout << "Duracion: " << _Duracion << "" << endl;
    cout << "Genero: " << _Genero << "" << endl;
    cout << "*************************************************" << endl;
    cout << endl;



        }
    }

     ~Pelicula() {}


};

#endif // CLSPELICULA_H_INCLUDED

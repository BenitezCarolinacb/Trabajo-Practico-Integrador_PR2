///EJERCICIO:
///AUTOR:DEK
///FECHA:


#include<iostream>
using namespace std;
// aca van funciones que modifiquen algo
#include "ClsVendedor.h"
#include "ArchVendedor.h"

#include "ClsFuncion.h"
#include "ArchFuncion.h"

#include "ClsFecha.h"

#include "ArchPelicula.h"
#include "ClsPelicula.h"

#include "ArchSala.h"
#include "ClsSala.h"

#include "ArchCliente.h"
#include "ClsCliente.h"

bool EliminarUnVendedor(){
    Vendedor obj;
    ArchivoVendedor objarchi;

    int IDvendedor, pos;

    cout << "Ingresar ID del vendedor: " << endl;
    cin >> IDvendedor;
    pos = objarchi.buscarID(IDvendedor, obj);
    if (pos == -1) {
        cout << "Vendedor no encontrado." << endl;
        return false;
    }
    obj=objarchi.leerRegistro(pos);
    obj.setEstado(false);
    if (objarchi.modificarRegistro(pos, obj)) {
        return true;
    }
    return false;
}



bool  EliminarPeliculas(){
Pelicula obj;
ArchivoPelicula objArchiP;
 int id;
    cout<<"Ingresar ID: "<<endl;cin>>id;
    int pos=objArchiP.buscarID(id, obj);
    if(pos==-1){
                return false;
    }
    obj=objArchiP.leerRegistro(pos);
    obj.setEstado(false);
    if(objArchiP.modificarRegistro(pos, obj)){
                MostrarTexto("BORRADO CON EXITO");
                system("pause");
                cout<<obj.getEstado();
                  return true;
    }
     return false;
    }



  bool EliminarFunciones() {
    Funcion obj;
    ArchivosFuncion ObjArchiF;
    int id;
    cout << "Ingresar ID: " << endl;
    cin >> id;
    int pos = ObjArchiF.buscarIDPorPosicion(id, obj);
    if (pos == -1) {
        return false;
    }
    ObjArchiF.leerRegistro(pos, obj);
    obj.setEstado(false);
    if (ObjArchiF.modificarRegistro(pos, obj)) {
        MostrarTexto("BORRADO CON EXITO");
        return true;
    }
    return false;
}

    bool EliminarSalas(){
    Sala obj;
    ArchivoSala ObjArchiSala;
    int id;
    cout<<"Ingresar ID: "<<endl;cin>>id;
    int pos=ObjArchiSala.buscarID(id, obj);
    if(pos==-1){
                return false;
    }
    obj=ObjArchiSala.leerRegistro(pos);
    obj.setEstado(false);
    if(ObjArchiSala.modificarRegistro(pos, obj)){
                MostrarTexto("BORRADO CON EXITO");
                  return true;
    }
     return false;
    }

    bool Eliminarcliente (){
    Cliente obj;
    ArchivoCliente objarchi;

    int IDcliente,pos;

    cout<<"Ingresar ID: "<<endl;cin>>IDcliente;

    pos=objarchi.buscarID(IDcliente,obj);
    if(pos==-1){
        return false;
    }
    obj=objarchi.leerRegistro(pos);
    obj.setEstado(false);

    if(objarchi.modificarRegistro(pos, obj)){
        MostrarTexto("BORRADO CON EXITO");
                  return true;
    }

    return false;

    }


bool ModificarFechaFuncion() {
    Fecha nuevo;
    Funcion objFuncion;
    ArchivosFuncion ObjArchivoFuncion;
    int ID;
    MostrarTexto("Ingresar ID Funcion");
    cin >> ID;

    int pos = ObjArchivoFuncion.buscarIDPorPosicion(ID, objFuncion);
    if (pos == -1) {
        return false;
    }
    ObjArchivoFuncion.leerRegistro(pos,objFuncion);
    cout << "Ingrese la nueva fecha:" << endl;
     nuevo.Cargar();
    objFuncion.setFecha(nuevo);
    if (ObjArchivoFuncion.modificarRegistro(pos, objFuncion)) {
        return true;
    }

    return false;
}
///SECCION MODIFICACION FUNCION
bool ModificarPrecioFuncion() {
    Funcion objFuncion;
    ArchivosFuncion ObjArchivoFuncion;
    int ID;
    float nuevoPrecio;
    MostrarTexto("Ingresar ID Funcion");
    cin >> ID;

    int pos = ObjArchivoFuncion.buscarIDPorPosicion(ID, objFuncion);
    if (pos == -1) {
        return false;
    }

    ObjArchivoFuncion.leerRegistro(pos,objFuncion);
    cout << "Ingrese el nuevo precio :" << endl;
    cin>>nuevoPrecio;
    objFuncion.setPrecio(nuevoPrecio);
    if (ObjArchivoFuncion.modificarRegistro(pos, objFuncion)) {
        return true;
    }

    return false;
}



///seccion de modificacion SALA
bool ModificarButacasSala() {
    Sala obj;
    ArchivoSala objarchi;
    int id, pos, butacas;
    cout << "Ingresa ID: " << endl;
    cin >> id;

    pos = objarchi.buscarID(id, obj);
    if (pos == -1) {
        MostrarTexto("ID de sala no encontrado.");
        return false;
    }
    obj=objarchi.leerRegistro(pos);
    cout << "Ingresa la nueva cantidad de butacas para la sala: " << endl;
    cin >> butacas;
    obj.setCantidadButacas(butacas);
    if (objarchi.modificarRegistro(pos, obj)) {
        return true;
    }

    return false;
}


///seccion de modificacion PELICULA
bool ModificarTituloPeliculas() {
    Pelicula obj;
    ArchivoPelicula objarchi;
    int id, pos;
    char titulo[50];
    cout << "Ingresa ID: " << endl;
    cin >> id;

    pos = objarchi.buscarID(id, obj);
    if (pos == -1) {
        MostrarTexto("ID de película no encontrado.");
        return false;
    }

    cout << "Ingresa el nuevo titulo para la pelicula: " << endl;
    cin.ignore();
    cin.getline(titulo, 50);
    obj.setTituloPelicula(titulo);
    if (objarchi.modificarRegistro(pos, obj)) {
        MostrarTexto("Se cambió correctamente.");
        return true;
    }

    return false;
}

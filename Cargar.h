#ifndef CARGAR_H_INCLUDED
#define CARGAR_H_INCLUDED


#include "ClsPelicula.h"
#include "ArchPelicula.h"
#include "ClsFuncion.h"
#include "ArchFuncion.h"
#include "ArchPelicula.h"
#include "ClsPelicula.h"
#include "ArchSala.h"
#include "ClsSala.h"
#include "ArchCliente.h"
#include "ClsCliente.h"
#include "ArchVendedor.h"
#include "ClsVendedor.h"
#include "ClsVentas.h"
#include "ArchVentas.h"

int CantidadparaCargar() {
    int r;
    cout<<"Ingrese la cantidad de registros a cargar: ";
    cin>>r;
    return r;
}


int CargarCliente(){
int reg=CantidadparaCargar();
for(int i=0;i<reg;i++){
     Cliente RegCliente;
     ArchivoCliente objClientearchivo;
     RegCliente.Cargar();
     RegCliente.setIDCliente(objClientearchivo.ultimoID()+1);
     if(objClientearchivo.grabarRegistro(RegCliente)){
     MostrarTexto("se escribio correctamente");
                }
}
return 0;
}
int CargarPelicula(){
  int reg = CantidadparaCargar();
    for(int i = 0; i < reg; i++) {
        Pelicula RegPelicula;
        ArchivoPelicula ObjPeliculaArchivo;
        int validar=RegPelicula.Cargar();
        if(validar==true){
           RegPelicula.setIDPelicula(ObjPeliculaArchivo.ultimoID()+1);
        if(ObjPeliculaArchivo.grabarRegistro(RegPelicula)) {
            MostrarTexto("se escribio correctamente");
        }
        }else {
        cout<<"No se pudo";
        }
    }
    return 0;
}

int CargarFuncion(){
  int reg = CantidadparaCargar();
  int idpel, idsal;
    for(int i = 0; i < reg; i++) {
        Funcion RegFuncion;
        ArchivosFuncion objFuncionArchivo;
        Pelicula RegPelicula;
        ArchivoPelicula objArchivoPelicula;
        Sala RegSala;
        ArchivoSala ObjArchivoSala;
        RegFuncion.Cargar();
        MostrarTexto("ID Pelicula Disponibles: ");
        objArchivoPelicula.ListarRegistro();
        cin>>idpel;
        if(objArchivoPelicula.buscarID(idpel, RegPelicula)){
          RegFuncion.setIDPelicula(RegPelicula);
         }
         MostrarTexto("ID Sala Disponibles: ");
         ObjArchivoSala.ListarRegistro();
         cin>>idsal;
         if(ObjArchivoSala.buscarID(idsal, RegSala)){
                RegFuncion.setIDSala(RegSala);
        }
        RegFuncion.setIDFuncion(objFuncionArchivo.ultimoID()+1);
        system("pause");
        if(objFuncionArchivo.grabarRegistro(RegFuncion)) {
            MostrarTexto("se escribio correctamente");
        }

    }
    return 0;
}

int AgregarVendedor(){
  int reg = CantidadparaCargar();
    for(int i = 0; i < reg; i++) {
        Vendedor RegVendedor;
        ArchivoVendedor objVendedorArchivo;
        RegVendedor.Cargar();
        RegVendedor.setIDVendedor(objVendedorArchivo.ultimoID()+1);
        if(objVendedorArchivo.grabarRegistro(RegVendedor)) {
            MostrarTexto("se escribio correctamente");
        }
    }
    return 0;
}

int CargarSala(){
  int reg = CantidadparaCargar();
    for(int i = 0; i < reg; i++) {
        Sala RegSala;
        ArchivoSala objSalaArchivo;
        RegSala.Cargar();
        RegSala.setIDSala(objSalaArchivo.ultimoID()+1);
        if(objSalaArchivo.grabarRegistro(RegSala)) {
            MostrarTexto("se escribio correctamente");
        }
    }
    return 0;
}

int CargarVenta() {
    int reg = CantidadparaCargar();
    for (int i = 0; i < reg; i++) {
        Venta RegVenta;
        ArchivoVenta objVentaArchivo;

        RegVenta.Cargar();
        RegVenta.setIDVenta(objVentaArchivo.ultimoID() + 1);
        if (objVentaArchivo.grabarRegistro(RegVenta)) {
            MostrarTexto("Venta registrada correctamente.");
        } else {
            MostrarTexto("Error al registrar la venta.");
        }
    }
    return 0;
}

#endif // CARGAR_H_INCLUDED

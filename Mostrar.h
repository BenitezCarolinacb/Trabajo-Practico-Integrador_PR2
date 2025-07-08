#ifndef MOSTRAR_H_INCLUDED
#define MOSTRAR_H_INCLUDED

#include "ArchPelicula.h"
#include "ClsPelicula.h"
#include "ArchVentas.h"
#include "ClsVentas.h"
#include "ArchFuncion.h"
#include "ClsFuncion.h"
#include "ArchSala.h"
#include "ClsSala.h"
#include "ArchCliente.h"
#include "ClsCliente.h"
#include "FGenerales.h"
#include "FMenus.h"


void ListarPeliculas(){
ArchivoPelicula archiP;
archiP.ListarRegistro();
}



void ListarVentas(){
ArchivoVenta ArchiV;
ArchiV.ListarRegistro();
}


void ListarFunciones(){
ArchivosFuncion archiF;
archiF.ListarRegistro();
}


void ListarSalas(){
ArchivoSala archiS;
archiS.ListarRegistro();
}


void ListarVendedores(){
ArchivoVendedor archiVen;
archiVen.ListarRegistro();
}


void Listados(){
system("cls");
cout<<" MENU DE LISTADOS" <<endl;
cout<<" (1) LISTADO DE CLIENTES CARGADOS EN EL SISTEMA "<<endl;
cout<<" (2) LISTADO DE VENDEDORES CARGADOS EN EL SISTEMA"<<endl;
cout<<" (3) LISTADO DE PELICULAS CARGADAS EN EL SISTEMA "<<endl;
cout<<" (4) LISTADO DE SALAS CARGADAS EN EL SISTEMA"<<endl;
cout<<" (5) LISTADO DE FUNCIONES CARGADAS EN EL SISTEMA "<<endl;
cout<<" (6) LISTADO DE VENTAS CARGADAS EN EL SISTEMA"<<endl;
}


void ListarClientes(){
ArchivoCliente archC;
archC.ListarRegistro();
}

void MostrarMenuConfiguracion(){
cout<<" (1) Realizar copia de seguridad de clientes"<<endl;
cout<<" (2) Realizar copia de seguridad de funciones"<<endl;
cout<<" (3) Realizar copia de seguridad de peliculas"<<endl;
cout<<" (4) Realizar copia de seguridad de ventas"<<endl;
cout<<" (5) Realizar copia de seguridad de salas "<<endl;
cout<<" (6) Realizar copia de seguridad de vendedores"<<endl;
cout<<" (7) Realizar copia de seguridad de todos los archivos"<<endl;
cout<<" (0) Menú Principal     "<<endl;

}

void MostrarMenuRestaurar(){
cout<<" (1) Restaurar copia de seguridad de clientes"<<endl;
cout<<" (2) Restaurar copia de seguridad de funciones"<<endl;
cout<<" (3) Restaurar copia de seguridad de peliculas"<<endl;
cout<<" (4) Restaurar copia de seguridad de ventas"<<endl;
cout<<" (5) Restaurar copia de seguridad de salas "<<endl;
cout<<" (6) Restaurar copia de seguridad de vendedores"<<endl;
cout<<" (7) Restaurar copia de seguridad de todos los archivos"<<endl;
cout<<" (0) Menú Principal     "<<endl;


}

void MostrarMenuInforme(){
cout<<" INFORMES DE RECAUDACION: "<<endl;
cout<<" (1) Informe de Recaudacion Anual "<<endl;
cout<<" (2) Informe de Recaudacion por Vendedor "<<endl;
cout<<" (3) Informe de Recaudacion por Pelicula "<<endl;
cout<<" (4) Informe de Recaudacion por Funcion "<<endl;
cout<<" (5) Informe de Recaudacion por Medio de Pago "<<endl;
}


void MostrarMenuClientes(){
cout<<"................................................"<<endl;
cout<<" 1 LISTAR PELICULAS DISPONIBLES"<<endl;
cout<<" 2 BUSCAR FUNCIONES DISPONIBLES "<<endl;
cout<<" 3 CONSULTAR PRECIOS DE UNA FUNCION "<<endl;
cout<<" 4 REALIZAR COMPRA "<<endl;
cout<<" 5 CONSULTAR COMPRA "<<endl;
cout<<" 0 Salir del programa"<<endl;
cout<<" ................................................"<<endl;
}

void MostrarMenuADM(){
cout<<" AREA ADMINISTRATIVA "<<endl;
cout<<" ........................."<<endl;
cout<<" (1) CARGAR PELICULA EN CARTELERA "<<endl;
cout<<" (2) CARGAR SALAS" <<endl;
cout<<" (3) CARGAR FUNCIONES"<<endl;
cout<<" (4) MODIFICAR FECHA DE FUNCION"<<endl;
cout<<" (5) MODIFICAR PRECIO DE FUNCION"<<endl;
cout<<" (6) MODIFICAR CANTIDAD DE BUTACAS EN SALAS "<<endl;
cout<<" (7) MODIFICAR TITULO DE PELICULA"<<endl;
cout<<" (8) LISTADOS "<<endl; /// VER
cout<<" (9) BAJAS "<<endl; /// VER
cout<<" (10) INFORMES DE RECAUDACION"<<endl;
cout<<" (11) CONFIGURACIONES"<<endl;
cout<<" (0) MENU PRINCIPAL"<<endl;
}

void MostrarMenuBajas(){
cout<<" MENU DE BAJAS (ELIMINAR UN REGISTRO" <<endl;
cout<<" (1) BAJA VENDEDORES"<<endl;
cout<<" (2) BAJA PELICULAS"<<endl;
cout<<" (3) BAJA FUNCIONES"<<endl;
cout<<" (4) BAJA SALAS "<<endl;
cout<<" (5) BAJA CLIENTES "<<endl;
}


#endif // MOSTRAR_H_INCLUDED

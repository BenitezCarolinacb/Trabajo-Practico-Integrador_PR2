///EJERCICIO:
///AUTOR:DEK
///FECHA:


#include<iostream>
using namespace std;
#include "FGenerales.h"
#include "ClsCliente.h"
#include "ArchCliente.h"
#include "Cargar.h"
#include "Mostrar.h"
#include "FModificarRegistros.h"
#include "FConfiguraciones.h"
#include "FMenus.h"

bool Clientesinicio(int opc){
Cliente RegCliente;
ArchivoCliente objClientearchivo;
int IDCliente;
  if(opc==1){
    MostrarTexto("\t Ingresa tu ID de Cliente:");
    cin >> IDCliente;
    if (objClientearchivo.buscarID(IDCliente, RegCliente)) {
        if (RegCliente.getEstado()) {
            return true;
        } else {
            return false;
        }
    } else {
        MostrarTexto("Cliente no encontrado. Registrandote ahora...");
        RegCliente.Cargar();
        RegCliente.setIDCliente(objClientearchivo.ultimoID() + 1);
        if (objClientearchivo.grabarRegistro(RegCliente)) {
            return true;
        } else {
            MostrarTexto("Cliente no válido.");
            return false;
        }
    }
    system("pause");
    }
return false;
}


bool Empleadosinicio(int opc){
Vendedor RegVendedor;
ArchivoVendedor objVendedorarch;
int IDVendedor;
  if(opc==2){
    MostrarTexto("\t Ingresa tu ID de Empleado:");
    cin >> IDVendedor;
    if (objVendedorarch.buscarID(IDVendedor, RegVendedor)) {
        if (RegVendedor.getEstado()) {
            return true;
        } else {
            MostrarTexto("Empleado no válido.");
            return false;
        }
    } else {
        MostrarTexto("Empleado no encontrado. Registrandote ahora...");
        RegVendedor.Cargar();
        RegVendedor.setIDVendedor(objVendedorarch.ultimoID() + 1);
        if (objVendedorarch.grabarRegistro(RegVendedor)) {
            return true;
        } else {
            MostrarTexto("Hubo un error al registrar al Empleado.");
            return false;
        }
    }
    system("pause");
    }
return false;
}

void MenuPrincipal() {
    int opc;
    MostrarTexto("\t ................................................");
    MostrarTexto("\t Sistema de Gestion de Archivos - Cine El Dorado");
    MostrarTexto("\t Ingresa a que area queres acceder");
    MostrarTexto("\t 1 Clientes \n\t 2 Empleados");
    cin>>opc;
    if(Clientesinicio(opc)){
         MenuClientes();
    }
    else if(Empleadosinicio(opc)){
    MenuEmpleados();
    }

}


void MenuClientes() {
    system("cls");
    Cliente obj;
    int op;
            MostrarTexto("BIENVENIDO CLIENTE ");
            cout<<endl; cout<<obj.getNombre(); // que aparezca el nombre
            MostrarMenuClientes();
            cin >> op;
            switch (op) {
                case 1: ListarPeliculas();
                    system("pause");
                    MenuClientes();
                    break;
                case 2:
                    FuncionesDisponibles();
                     system("pause");
                    MenuClientes();
                    break;
                case 3:
                    ConsultarPrecioFuncion();
                     system("pause");
                    MenuClientes();
                    break;
                case 4:
                    RealizarCompra();
                    break;
                case 5:
                    ConsultarCompra();
                     system("pause");
                    MenuClientes();
                    break;
                case 0:
                    system("cls");
                    MenuPrincipal();
                    break;
                default:
                    MostrarTexto("Opción no válida.");
                    break;
            }
        }




  void BajasDeArchivos(){
    system("cls");
    MostrarMenuBajas();
     int opc;
     cin>>opc;
     switch (opc){

    case 1:
                    EliminarUnVendedor();
                    break;
    case 2:
                    EliminarPeliculas();
                    break;
    case 3:
                    EliminarFunciones();
                    break;
    case 4:
                    EliminarSalas();
                    break;
    case 5:
                    Eliminarcliente();
                    break;
    case 0:
                    MenuEmpleados();
                    break;
    default:
             MostrarTexto("Opción no válida.");
                    break;

     }
  }



void MenuEmpleados(){
system("cls");
int opc;
MostrarMenuADM();
     cin>>opc;
     switch (opc){

     case 1:
                     CargarPelicula();
                     system("pause");
                     MenuEmpleados();
                break;
     case 2:
                     CargarSala();
                     system("pause");
                     MenuEmpleados();
                break;
     case 3:
                     CargarFuncion();
                     system("pause");
                     MenuEmpleados();
                break;
     case 4:
                     ModificarFechaFuncion();
                break;
     case 5:
                     ModificarPrecioFuncion();
                break;
     case 6:
                     ModificarButacasSala();
                break;
     case 7:
                     ModificarTituloPeliculas();
                break;

     case 8:
                     MostrarListados();
                break;
     case 9:
                     BajasDeArchivos();
                break;
     case 10:
                     Informes();
                break;
     case 11:
                     MenuConfiguracion();
                break;
     case 0:
                system("cls");
                MenuPrincipal();
                break;

     }

     }


     /// ver

     void MostrarListados(){
     int opc;
     Listados();
     cin>> opc;

     switch(opc){

     case 1:        ListarClientes();
                     break;
     case 2:        ListarVendedores();
                break;

     case 3:        ListarPeliculas();
                break;
     case 4:        ListarSalas();
                break;
     case 5:
                     ListarFunciones();
                break;
     case 6:
                     ListarVentas();
                break;
     case 0:
                MenuEmpleados();
                break;

     }


     }

     void Informes(){
     int opc;
     system("cls");
     MostrarMenuInforme();
     cin>>opc;
     switch(opc){
     case 1:
                     recaudacionAnual();

                break;
     case 2:
                     RecaudacionPorVendedor();
                break;

     case 3:
                     RecaudacionPorPelicula();
                break;
     case 4:
                     RecaudacionPorFuncion();
                break;
     case 5:
                     RecaudacionPorMedioDePago();
                break;
     case 0:
                     MenuEmpleados();
                break;

     }
     }
     void ConfRestaurarCopiaSeguridad(){
                     int opc;
                     MostrarMenuRestaurar();cin>>opc;
                     switch(opc){
                case 1:
                                RestaurarClientes();
                                break;
                case 2:
                                RestaurarFunciones();
                                break;
                case 3:
                                RestaurarPeliculas();
                                break;
                case 4:
                                RestaurarVentas();
                                break;
                case 5:
                                RestaurarVendedores();
                                break;
                case 6: if(RestaurarTodos()){
                                MostrarTexto("Copia realizada con exito.");
                                } else {
                                                MostrarTexto("No se pudo realizar la copia.");

                                                }
                                break;
                case 0:
                                MenuPrincipal();
                                break;
                default:
                                MostrarTexto("Opción no válida.");
                    break;
                                }
                }


void ConfCopiaSeguridad(){
int opc;
MostrarMenuConfiguracion();
cin>>opc;
switch(opc){
    case 1:
        CrearCopiaClientes();
        break;
    case 2:
        CrearCopiaFunciones();
        break;
    case 3:
        CrearCopiaPeliculas();
        break;
    case 4:
        CrearCopiaVentas();
        break;
    case 5:
        CrearCopiaSalas();
      break;
    case 6:
       CrearCopiaVendedores();
     break;
    case 7:if(CopiaTodos()){
                MostrarTexto("Copia realizada con exito.");
        } else {
        MostrarTexto("No se pudo realizar la copia.");
        }
        break;
    case 0:
        MenuPrincipal();
        break;
    default:
       MostrarTexto("Opción no válida.");
                    break;

    }
  }



void MenuConfiguracion(){
                system("cls");
        int op;
        MostrarTexto("Configuracion");
        MostrarTexto("(1) Realizar copia de seguridad");
        MostrarTexto("(2) Realizar copia de seguridad");
        cin>>op;
        switch(op){
   case 1: ConfCopiaSeguridad();
        break;
   case 2: ConfRestaurarCopiaSeguridad();
        break;
    case 0:
        MenuPrincipal();
        break;
    default:
   MostrarTexto("Opción no válida.");
                    break;

    }
  }



// vero

// acomodar con un menu con informes
// menu listado (todos los archivos juntos) -
// menu de informes (todos los archivos juntos) -
// fecha la traiga de la función
// Autoincrementable (todos los ID's)
// Corroborar que la función exista
// plataforma que funcione como hoyts
// validacion de todos las clases

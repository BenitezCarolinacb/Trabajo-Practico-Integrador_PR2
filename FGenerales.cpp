///EJERCICIO:
///AUTOR:DEK
///FECHA:


#include<iostream>
using namespace std;

#include "ArchFuncion.h"
#include "ClsFuncion.h"
#include "ClsFecha.h"
#include "ArchVentas.h"
#include "ClsVentas.h"
#include "ArchPelicula.h"
#include "ArchVendedor.h"
#include "ClsVendedor.h"

#include "FGenerales.h"


void cargarCadena(char* pal, int tam) {
    int i;
    fflush(stdin);
    for (i = 0; i < tam; i++) {
        pal[i] = cin.get();
        if (pal[i] == '\n') break;
    }
    pal[i] = '\0';
    fflush(stdin);
}


void MostrarTexto(const char* mensaje){
cout<<mensaje<<endl;
}


int ValidarIngresoFloat(){
int op;
    while(!(cin>>op))
    { MostrarTexto("Coloca un valor numerico. ");
       cin.clear(); //limpia lo que ingresaste
       cin.ignore();
     }
    return op;
}



Fecha DevolverFecha(int IDFuncion) {
    ArchivosFuncion objarchivo;
    Funcion objfuncion;
    int pos = objarchivo.buscarID(IDFuncion, objfuncion);
    if (pos != -1) {
        return objfuncion.getFecha();
    } else {
        MostrarTexto("No se encontro la fecha.");
    }
}

bool FuncionesDisponibles() {
    ArchivosFuncion objFuncionArchivo;
    Funcion funcion;
    Pelicula objPelicula;
    Fecha aux;
    int pos = 0;
    bool FuncionDisponible = false;

    MostrarTexto("Ingrese fecha para buscar si esta disponible la función (dia/mes/año):");
    aux.Cargar();
    while (objFuncionArchivo.leerRegistro(pos, funcion)) {
        if (funcion.getFecha() == aux && funcion.getEstado()) {
            funcion.Mostrar();
            FuncionDisponible = true;
        }
        pos++;
    }
    if (!FuncionDisponible) {
        MostrarTexto("No hay funciones disponibles con esa fecha.");
    }
}



bool ConsultarPrecioFuncion() {
    ArchivosFuncion objFuncionArchivo;
    Funcion funcion;
    int precio;
    bool seEncontro = false;
    int pos = 0;
    MostrarTexto("Ingrese el precio de la funcion a buscar");
    cin >> precio;

    while (objFuncionArchivo.leerRegistro(pos, funcion)) {
        if (funcion.getPrecio() == precio && funcion.getEstado()) {
            funcion.Mostrar();
            seEncontro = true;
        }
        pos++;
    }

    if (!seEncontro) {
         MostrarTexto("No  se encontraron funciones con ese precio");
    }

    return seEncontro;
}

bool ConsultarCompra(){
ArchivoVenta ObjArchivoVenta;
Venta venta;
int IDventa;
int pos=0;
bool encontrado=false;
MostrarTexto("Ingrese ID de la venta para buscar");
cin>>IDventa;

while(ObjArchivoVenta.leerRegistro(pos, venta)){
                if(venta.getIDVenta()==IDventa&& venta.getEstado()){
                                venta.Mostrar();
                                encontrado=true;
                }
                pos++;
} if(!encontrado){
                MostrarTexto("No se encontro la venta");
}

return encontrado;
}


int calcularimporte(int IDFuncion, int CantidadEntradas){
ArchivosFuncion objarchivo;
Funcion objfuncion;
    if (!objarchivo.buscarID(IDFuncion,objfuncion)){
    return objfuncion.getPrecio()*CantidadEntradas;
    }
    return 0;
     }


// te registras como cliente, despues elegis la pelicula > fecha > horario >
//te muestra lo que vas a compras > confirmas > te muestra el ticket > elegis
//el numero de butaca (fijarse si esta disponible) después pagas.

bool RealizarCompra() {
    system("cls");
    ArchivoPelicula ObjArchivoPelicula;
    Pelicula RegPelicula;
    ArchivoVenta objVentaArchivo;
    Venta RegVenta;
    ArchivoVendedor objArchivoVendedor;
    Vendedor RegVendedor;
    ArchivosFuncion ObjArchivoFuncion;
    Funcion RegFuncion;

    // CARGAR
    RegVenta.Cargar();

    int IDP, idVendedor, idfuncion;
    MostrarTexto("Listado de Peliculas Disponibles");
    ObjArchivoPelicula.ListarRegistro();
    MostrarTexto("Selecciona el ID de la pelicula que vas a ver");
    cin >> IDP;
    cout << endl;

    if (ObjArchivoPelicula.buscarID(IDP, RegPelicula)) {
        cout << endl;
        cout << "Seleccionaste la pelicula: " << RegPelicula.getTituloPelicula() << endl;
        RegVenta.setIDVenta(objVentaArchivo.ultimoID() + 1);
        objArchivoVendedor.ListarRegistro();
        MostrarTexto("Ingrese el ID del vendedor: ");
        cin >> idVendedor;
        if (objArchivoVendedor.buscarID(idVendedor, RegVendedor)) {
            RegVenta.setVendedor(RegVendedor);
        } else {
            MostrarTexto("Vendedor no encontrado.");
            return false;
        }
        ObjArchivoFuncion.ListarRegistro();
        MostrarTexto("Selecciona el ID de la funcion que queres");
        cin >> idfuncion;
        if (ObjArchivoFuncion.buscarID(idfuncion, RegFuncion)) {
            RegVenta.setFuncion(RegFuncion);
        } else {
            return false;
        }

        if (objVentaArchivo.grabarRegistro(RegVenta)) {
            MostrarTexto("Venta registrada correctamente.");
        } else {
            return false;
        }
        system("pause");

        // Mostrar Ticket
        MostrarTexto("***********************************************");
        cout << "|                Ticket                        |" << endl;
        cout << "***********************************************" << endl;
        cout << "ID Pelicula: " << RegPelicula.getIDPelicula() << " |" << endl;
        cout << "Titulo: " <<RegPelicula.getTituloPelicula() << " |" << endl;
        cout << "Duracion: " << RegPelicula.getDuracion() << " minutos" << " |" << endl;
        RegVenta.Mostrar();
        return true;
    } else {
        MostrarTexto("Pelicula no encontrada.");
        return false;
    }
}


bool validarAnio(int anio, int anioActual) {
    if (anio > anioActual) {
        cout << "No es posible calcular la recaudación para un año a futuro" << endl;
        return false;
    }
    return true;
}


void recaudacionAnual() {
    Venta obj;
    ArchivoVenta objArchivoVenta;
    float acuRecaudado = 0;
    int anio, pos = 0, cantEnt = 0;
    int anioActual;

    MostrarTexto("Ingrese el año actual para verificar la recaudación: ");
    cin >> anioActual;
    MostrarTexto("Ingrese el año sobre el cual quiera calcular la recaudación: ");
    cin >> anio;
    cin.ignore();

  if(!validarAnio(anio,anioActual)){
    return ;
  }

    while (objArchivoVenta.leerRegistro(pos, obj)) {
        if (obj.getFecha().getAnio() == anio) {
            acuRecaudado += obj.getImp();
            cantEnt += obj.getCantidadEntradas();

        }
        pos++;
    }
    if (acuRecaudado != 0) {
        cout << endl << "El monto de recaudación registrado para el año ";
        cout << anio;
        cout << ", es de ";
        cout << "$" << acuRecaudado;
        cout << ", el cual corresponde a ";
        cout << cantEnt;
        cout << " entradas vendidas." << endl << endl << endl;
    } else {
        cout << endl << "No ha habido recaudación alguna para el año ";
        cout << anio << endl;
        cout << endl;
    }

}

void RecaudacionPorVendedor() {
    Venta objventa;
    ArchivoVenta ObjArchivoVentas;
    float recaudado = 0;
    int IDvendedor, pos = 0, cantidadentradas = 0;
    MostrarTexto("\t\n Ingrese el ID del vendedor sobre el cual quiera calcular la recaudación: ");
    cin >> IDvendedor;

    while (ObjArchivoVentas.leerRegistro(pos++, objventa)) {
        if (objventa.getIDVendedor() == IDvendedor) {
            cantidadentradas += objventa.getCantidadEntradas();
            recaudado += objventa.getImp();
        }
    }

    if (recaudado != 0) {
        cout << "\t\n El VENDEDOR con ID: " << IDvendedor << endl;
        cout << "\t\n tiene una recaudacion de: $" << recaudado << endl;
        cout << "\t\n por la cantidad de: " << cantidadentradas << " entradas" << endl;
    } else {
        cout << "\t\n El VENDEDOR no recaudo nada" << endl;

    }
}



void RecaudacionPorPelicula(){
Pelicula objPelicula;
ArchivoPelicula ObjArchivoPelicula;
Venta objVenta;
ArchivoVenta objArchivoVenta;
int idp, pos=0, cantEntradas=0;
float recaudadopel=0;
MostrarTexto("Ingresar el ID  de la pelicula para buscar su recaudacion: ");
cin>>idp;
 while(objArchivoVenta.leerRegistro(pos++, objVenta)){
                if(ObjArchivoPelicula.buscarID(idp, objPelicula)){
                if(objPelicula.getIDPelicula()==idp){
                                cantEntradas+=objVenta.getCantidadEntradas();
                                recaudadopel+=objVenta.getImp();
                }
                }


 }

 if(recaudadopel!=0){
cout << "\t\n La Pelicula: " << idp << endl;
cout << "\t\n tiene una recaudacion de: $" << recaudadopel << endl;
cout << "\t\n por la cantidad de: " << cantEntradas << " entradas" << endl;

 } else {
 MostrarTexto("La pelicula no recaudo nada. ");

 }


}

void RecaudacionPorMedioDePago(){
Venta objVenta;
ArchivoVenta ObjArchivoVenta;

float recaudacion=0;
char mediop[20];
MostrarTexto("Ingrese el medio de pago a buscar para hacer la recaudacion: ");
cargarCadena(mediop,20);
int CantVentas=ObjArchivoVenta.ContarRegistros();
for(int i=0; i<CantVentas;i++){
                if(ObjArchivoVenta.leerRegistro(i, objVenta)){
                                if(objVenta.getEstado()&& strcmp(objVenta.getmedioDePago(), mediop)==0){
                                       recaudacion+=objVenta.getImp();
                                }
                }
}
if(recaudacion!=0){
                MostrarTexto("La recaudacion total con el medio de pago : ");
                cout<<mediop<<endl<<recaudacion<<endl;
} else {
MostrarTexto("No hay recaudacion por ese medio de pago");

}


}

void RecaudacionPorFuncion(){
Venta objVenta;
ArchivoVenta ObjArchivoVenta;
int idF, cantEntradas=0, pos=0;
float recaudacionF=0;
MostrarTexto("Ingrese ID de funcion para buscar su recaudacion");
cin>>idF;
while(ObjArchivoVenta.leerRegistro(pos++, objVenta)){
                if(objVenta.getIDFuncion()==idF){
                                cantEntradas+=objVenta.getCantidadEntradas();
                                recaudacionF+=objVenta.getImp();
                }
}
if(recaudacionF!=0){
        cout << "\t\n La Funcion: " << idF << endl;
        cout << "\t\n tiene una recaudacion de: $" << recaudacionF << endl;
        cout << "\t\n por la cantidad de: " << cantEntradas << " entradas" << endl;
} else {
MostrarTexto("La funcion no recaudo nada");
}
}



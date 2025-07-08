///EJERCICIO:
///AUTOR:DEK
///FECHA:


#include<iostream>
using namespace std;

// copias de seguridad
#include "ClsCliente.h"
#include "ClsFuncion.h"
#include "ClsPelicula.h"
#include "ClsVendedor.h"
#include "ClsSala.h"
#include "ClsVentas.h"
#include "FConfiguraciones.h"

bool CrearCopiaClientes() {
    Cliente obj;
    FILE* CopiarReg = fopen("Datos/clientes.dat", "rb");
    FILE* AcaSeCopia = fopen("Copia de seguridad/clientes.bkp", "wb");
    if (CopiarReg == NULL || AcaSeCopia == NULL) {
        return false;
    }

    while (fread(&obj, sizeof(Cliente), 1, CopiarReg) == 1) {
        fwrite(&obj, sizeof(Cliente), 1, AcaSeCopia);
    }
    fclose(CopiarReg);
    fclose(AcaSeCopia);
    return true;
}


bool CrearCopiaVendedores(){
   Vendedor obj;
   FILE* CopiarReg = fopen("Datos/vendedores.dat", "rb");
   FILE* AcaSeCopia = fopen("Copia de seguridad/vendedores.bkp", "wb");
    if(CopiarReg == NULL || AcaSeCopia == NULL){
        return false;
    }

    while(fread(&obj, sizeof(Vendedor), 1, CopiarReg) == 1){
        fwrite(&obj, sizeof(Vendedor), 1, AcaSeCopia);

    }
    fclose(CopiarReg);
    fclose(AcaSeCopia);
    return true;
}


bool CrearCopiaSalas(){
   Sala obj;
   FILE* CopiarReg = fopen("Datos/salas.dat", "rb");
   FILE* AcaSeCopia = fopen("Copia de seguridad/salas.bkp", "wb");
    if(CopiarReg == NULL || AcaSeCopia == NULL){
        return false;
    }

    while(fread(&obj, sizeof(Sala), 1, CopiarReg) == 1){
        fwrite(&obj, sizeof(Sala), 1, AcaSeCopia);

    }
    fclose(CopiarReg);
    fclose(AcaSeCopia);
    return true;
}



bool CrearCopiaPeliculas(){
   Pelicula obj;
   FILE* CopiarReg = fopen("Datos/peliculas.dat", "rb");
   FILE* AcaSeCopia = fopen("Copia de seguridad/peliculas.bkp", "wb");
    if(CopiarReg == NULL || AcaSeCopia == NULL){
        return false;
    }

    while(fread(&obj, sizeof(Pelicula), 1, CopiarReg) == 1){
        fwrite(&obj, sizeof(Pelicula), 1, AcaSeCopia);

    }
    fclose(CopiarReg);
    fclose(AcaSeCopia);
    return true;
}



bool CrearCopiaVentas(){
   Venta obj;
   FILE* CopiarReg = fopen("Datos/ventas.dat", "rb");
   FILE* AcaSeCopia = fopen("Copia de seguridad/ventas.bkp", "wb");
    if(CopiarReg == NULL || AcaSeCopia == NULL){
        return false;
    }

    while(fread(&obj, sizeof(Venta), 1, CopiarReg) == 1){
        fwrite(&obj, sizeof(Venta), 1, AcaSeCopia);

    }
    fclose(CopiarReg);
    fclose(AcaSeCopia);
    return true;
}



bool CrearCopiaFunciones(){
   Funcion obj;
   FILE* CopiarReg = fopen("Datos/funciones.dat", "rb");
   FILE* AcaSeCopia = fopen("Copia de seguridad/funciones.bkp", "wb");
    if(CopiarReg == NULL || AcaSeCopia == NULL){
        return false;
    }

    while(fread(&obj, sizeof(Funcion), 1, CopiarReg) == 1){
        fwrite(&obj, sizeof(Funcion), 1, AcaSeCopia);

    }
    fclose(CopiarReg);
    fclose(AcaSeCopia);
    cout << endl;
    return true;
}



bool CopiaTodos(){ // ver porque no se puede copiar a todos

                if(CrearCopiaClientes()){
                                if(CrearCopiaPeliculas()){
                                                if(CrearCopiaVentas()){
                                                                if(CrearCopiaFunciones()){
                                                                                                if(CrearCopiaSalas()){
                                                                                                                if(CrearCopiaVendedores()){
                                                                                                                     return true;
                                                                                                                }
                                                                                                }

                                                                }
                                                }
                                }
                }


 return false;
}



bool RestaurarClientes(){
   Cliente obj;
   FILE* CopiarReg = fopen("clientes.bkp", "rb");
   FILE* AcaSeCopia = fopen("Datos/clientes.dat", "wb");

    if(CopiarReg == NULL || AcaSeCopia == NULL){
        return false;
    }

    while(fread(&obj, sizeof(Cliente), 1, CopiarReg) == 1){
        fwrite(&obj, sizeof(Cliente), 1, AcaSeCopia);

    }
    fclose(CopiarReg);
    fclose(AcaSeCopia);
    return true;
}

bool RestaurarFunciones(){
   Funcion obj;
   FILE* CopiarReg = fopen("funcion.bkp", "rb");
   FILE* AcaSeCopia = fopen("Datos/funcion.dat", "wb");

    if(CopiarReg == NULL || AcaSeCopia == NULL){
        return false;
    }

    while(fread(&obj, sizeof(Funcion), 1, CopiarReg) == 1){
        fwrite(&obj, sizeof(Funcion), 1, AcaSeCopia);

    }
    fclose(CopiarReg);
    fclose(AcaSeCopia);
    return true;
}

bool RestaurarPeliculas(){
   Pelicula obj;
   FILE* CopiarReg = fopen("pelicula.bkp", "rb");
   FILE* AcaSeCopia = fopen("Datos/peliculas.dat", "wb");

    if(CopiarReg == NULL || AcaSeCopia == NULL){
        return false;
    }

    while(fread(&obj, sizeof(Pelicula), 1, CopiarReg) == 1){
        fwrite(&obj, sizeof(Pelicula), 1, AcaSeCopia);

    }
    fclose(CopiarReg);
    fclose(AcaSeCopia);
    return true;
}

bool RestaurarSalas(){
   Sala obj;
   FILE* CopiarReg = fopen("sala.bkp", "rb");
   FILE* AcaSeCopia = fopen("Datos/salas.dat", "wb");

    if(CopiarReg == NULL || AcaSeCopia == NULL){
        return false;
    }

    while(fread(&obj, sizeof(Sala), 1, CopiarReg) == 1){
        fwrite(&obj, sizeof(Sala), 1, AcaSeCopia);

    }
    fclose(CopiarReg);
    fclose(AcaSeCopia);
    return true;
}


bool RestaurarVendedores(){
   Vendedor obj;
   FILE* CopiarReg = fopen("vendedor.bkp", "rb");
   FILE* AcaSeCopia = fopen("Datos/vendedores.dat", "wb");

    if(CopiarReg == NULL || AcaSeCopia == NULL){
        return false;
    }

    while(fread(&obj, sizeof(Vendedor), 1, CopiarReg) == 1){
        fwrite(&obj, sizeof(Vendedor), 1, AcaSeCopia);

    }
    fclose(CopiarReg);
    fclose(AcaSeCopia);
    return true;
}


bool RestaurarVentas(){
   Venta obj;
   FILE* CopiarReg = fopen("ventas.bkp", "rb");
   FILE* AcaSeCopia = fopen("Datos/ventas.dat", "wb");

    if(CopiarReg == NULL || AcaSeCopia == NULL){
        return false;
    }

    while(fread(&obj, sizeof(Venta), 1, CopiarReg) == 1){
        fwrite(&obj, sizeof(Venta), 1, AcaSeCopia);

    }
    fclose(CopiarReg);
    fclose(AcaSeCopia);
    return true;
}




bool RestaurarTodos(){
                if(RestaurarClientes()){
                                if(RestaurarFunciones()){
                                                if(RestaurarPeliculas()){
                                                                if(RestaurarSalas()){
                                                                         if(RestaurarVendedores()){
                                                                           return true;

                                                 }
                                                                        }
                                                }
                                }
                }


 return false;
}

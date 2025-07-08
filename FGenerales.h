#ifndef FGENERALES_H_INCLUDED
#define FGENERALES_H_INCLUDED
#include "ClsFecha.h"

void cargarCadena(char* pal, int tam);

void MostrarTexto(const char* mensaje);

Fecha DevolverFecha(int IDFuncion);


bool FuncionesDisponibles();

bool ConsultarPrecioFuncion();

bool ConsultarCompra();

int calcularimporte(int IDFuncion, int CantidadEntradas);


bool RealizarCompra();


bool validarAnio(int anio, int anioActual);
int ValidarIngresoFloat();



void recaudacionAnual();

void RecaudacionPorVendedor();

void recaudacionMensual();

void RecaudacionPorPelicula();

void RecaudacionPorMedioDePago();

void RecaudacionPorFuncion();




#endif // FGENERALES_H_INCLUDED

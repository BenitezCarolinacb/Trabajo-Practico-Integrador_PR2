#ifndef ARCHVENTAS_H_INCLUDED
#define ARCHVENTAS_H_INCLUDED

#include "ClsVentas.h"
class ArchivoVenta{
private:
                char nombre[30];
public:
                ArchivoVenta() {
                                strcpy(nombre, "Datos/ventas.dat");
                      }
                bool leerRegistro(int pos, Venta &reg){
                FILE *pVenta=fopen(nombre,"rb");
                if(pVenta==NULL)return false;
                fseek(pVenta, pos * sizeof (Venta), SEEK_SET);
                if (fread(&reg, sizeof(Venta), 1, pVenta) != 1) {
                fclose(pVenta);
                return false; }
                fclose(pVenta);
                return true;
                 }
                bool grabarRegistro(Venta reg){
                FILE *pVenta;
                pVenta=fopen(nombre, "ab");
                if(pVenta==NULL) return false;
                int escribio=fwrite(&reg, sizeof reg, 1 , pVenta);
                fclose(pVenta);
                return escribio;
                }
                bool buscarID(int id, Venta &reg){
                FILE *pVenta=fopen(nombre, "rb");
                if(pVenta==NULL){
                return false;
                }
                while (fread(&reg, sizeof (Venta), 1, pVenta)){
                                if(reg.getIDVenta()==id){
                                                fclose(pVenta);
                                                return true;
                                }
                }
                fclose(pVenta);
                 return false;
                }
                int ContarRegistros(){
                FILE *pVenta;
                Venta reg;
                pVenta=fopen(nombre, "rb");
                if(pVenta==NULL) return false;
                fseek(pVenta,0, SEEK_END);
                int cantbyte=ftell(pVenta);
                fclose(pVenta);
                return cantbyte / sizeof(Venta);
                }
                bool ListarRegistro(){
                Venta reg;
                FILE *pVenta;
                pVenta=fopen(nombre, "rb");
                if(pVenta==NULL)return false;
                while(fread(&reg, sizeof (Venta),1,pVenta)==1){
                                reg.Mostrar();
                }
               fclose(pVenta);
               return true;
                }
                int ultimoID() {
                int Idcontenedor=0;
                Venta venta;
                FILE* archivo = fopen(nombre, "rb");
                if (archivo == nullptr) return false;
                while(fread(&venta, sizeof(Venta), 1, archivo)){
                 Idcontenedor=venta.getIDVenta();
                }
                fclose(archivo);
                return Idcontenedor;
                }
                bool modificarRegistro(int pos, Venta &ventas) {
                FILE *archivo = fopen(nombre, "rb+");
                if (archivo == nullptr) return false;
                fseek(archivo, sizeof(Venta) * pos, SEEK_SET);
                bool res = fwrite(&ventas, sizeof(Venta), 1, archivo);
                fclose(archivo);
                return res;

                }

                };

#endif // ARCHVENTAS_H_INCLUDED

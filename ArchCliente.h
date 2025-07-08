#ifndef ARCHCLIENTE_H_INCLUDED
#define ARCHCLIENTE_H_INCLUDED

#include "ClsCliente.h"
#include <cstring>

class ArchivoCliente{
private:
                char nombre[30];
public:
                  ArchivoCliente() {
                  strcpy(nombre, "Datos/clientes.dat");
                      }
                bool grabarRegistro(Cliente reg){
                FILE *pCliente;
                pCliente=fopen(nombre, "ab");
                if(pCliente==NULL) return false;
                int escribio=fwrite(&reg, sizeof reg, 1 , pCliente);
                fclose(pCliente);
                return escribio;
                }
                Cliente leerRegistro(int pos){
                Cliente reg;
                FILE *pCliente=fopen(nombre,"rb");
                if(pCliente==NULL){
                                return reg;
                }
                fseek(pCliente, pos * sizeof reg, 0);
                fread (&reg, sizeof reg, 1, pCliente);
                fclose(pCliente);
                return reg;
                }
                bool buscarID(int id, Cliente &reg) {
                FILE *pCliente = fopen(nombre, "rb");
                if (pCliente == NULL) {
                return false;
                }
                while (fread(&reg, sizeof(Cliente), 1, pCliente) == 1) {
                if (reg.getIDCliente() == id) {
                fclose(pCliente);
                return true;
               }
                 }

               fclose(pCliente);
               reg.setEstado(false);
               return false;
                }

                bool ListarRegistro(){
                Cliente reg;
                FILE *pCliente;
                pCliente=fopen(nombre, "rb");
                if(pCliente==NULL)return false;
                while(fread(&reg, sizeof (Cliente),1,pCliente)==1){
                                reg.Mostrar();
                }
                fclose(pCliente);
                return true;
                }
                bool modificarRegistro(int pos,  Cliente& clienteobj) {
                FILE* archivo = fopen(nombre, "rb+");
                if (archivo == NULL) return false;
                fseek(archivo, sizeof(Cliente) * pos, SEEK_SET);
                bool res = fwrite(&clienteobj, sizeof(Cliente), 1, archivo);
                fclose(archivo);
                return res;
                }
                int ultimoID() {
                int bandera_id = 0;
                Cliente cliente;
                FILE* archivo = fopen(nombre, "rb");
                if (archivo == nullptr) return 0;
                while (fread(&cliente, sizeof(Cliente), 1, archivo)) {
                if (cliente.getIDCliente() > bandera_id) {
                bandera_id = cliente.getIDCliente();
                }
                 }
                fclose(archivo);
                return bandera_id;
                }


                };

                /*int SobreEscribeRegistro(Cliente reg, int pos){
                FILE *pCliente;
                pCliente=fopen(nombre, "ab");
                if(pCliente==NULL)return -1;
                int valor=fwrite(&reg, sizeof reg, 1, pCliente);
                fclose(pCliente);
                return valor;
                }*/



#endif // ARCHCLIENTE_H_INCLUDED

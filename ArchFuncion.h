#ifndef ARCHFUNCION_H_INCLUDED
#define ARCHFUNCION_H_INCLUDED

#include <cstring>
#include "ClsFuncion.h"
class ArchivosFuncion {
private:
    char nombre[30];

public:
    ArchivosFuncion() {
        strcpy(nombre, "Datos/funciones.dat");
    }
    bool leerRegistro(int pos, Funcion &reg) {
        FILE* pFuncion = fopen(nombre, "rb");
        if (pFuncion == NULL) {
            return false;
        }
        fseek(pFuncion, pos * sizeof(Funcion), SEEK_SET);
        if (fread(&reg, sizeof(Funcion), 1, pFuncion) != 1) {
            fclose(pFuncion);
            return false;
        }
        fclose(pFuncion);
        return true;
    }
    bool grabarRegistro(Funcion reg) {
        FILE* pFuncion = fopen(nombre, "ab");
        if (pFuncion == NULL) {
            return false;
        }
        int escribio = fwrite(&reg, sizeof(Funcion), 1, pFuncion);
        fclose(pFuncion);
        return escribio;
    }
    bool buscarID(int id, Funcion &reg) {
        FILE* pFuncion = fopen(nombre, "rb");
        if (pFuncion == NULL) {
            return false;
        }
        while (fread(&reg, sizeof(Funcion), 1, pFuncion)) {
            if (reg.getIDFuncion() == id) {
                fclose(pFuncion);
                return true;
            }
        }

        fclose(pFuncion);
        reg.setEstado(false);
        return false;
    }

    int buscarIDPorPosicion(int id, Funcion &reg) {
    FILE* pFuncion = fopen(nombre, "rb");
    if (pFuncion == NULL) {
        return -1;
    }
    int pos = 0;
    while (fread(&reg, sizeof(Funcion), 1, pFuncion)) {
        if (reg.getIDFuncion() == id) {
            fclose(pFuncion);
            return pos;
        }
        pos++;
    }

    fclose(pFuncion);
    return -1;
}
    bool ListarRegistro() {
         Funcion reg;
    FILE* pFuncion = fopen(nombre, "rb");
    if (pFuncion == NULL) {
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    while (fread(&reg, sizeof(Funcion), 1, pFuncion) == 1) {
        reg.Mostrar();
    }

    fclose(pFuncion);
    return true;
}

bool modificarRegistro(int pos, Funcion &funcion) {
        FILE *archivo = fopen(nombre, "rb+");
        if (archivo == NULL) return false;
        fseek(archivo, sizeof(Funcion) * pos, SEEK_SET);
        bool res = fwrite(&funcion, sizeof(Funcion), 1, archivo);
        fclose(archivo);
        return res;
    }

    int ultimoID() {
        int bandera_id = 0;
        Funcion fun;
        FILE* archivo = fopen(nombre, "rb");
        if (archivo == NULL) {
            return 0;
        }
        while (fread(&fun, sizeof(Funcion), 1, archivo)) {
            bandera_id = fun.getIDFuncion();
        }

        fclose(archivo);
        return bandera_id;
    }




};

#endif // ARCHFUNCION_H_INCLUDED

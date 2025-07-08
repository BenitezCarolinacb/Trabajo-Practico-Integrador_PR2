#ifndef ARCHSALA_H_INCLUDED
#define ARCHSALA_H_INCLUDED

#include "ClsSala.h"
class ArchivoSala {
private:
    char nombre[30];

public:
    ArchivoSala() {
        strcpy(nombre, "Datos/salas.dat");
    }
  bool grabarRegistro(Sala reg) {
    FILE* pSala = fopen(nombre, "ab");
    if (pSala == NULL) return false;
    int escribio = fwrite(&reg, sizeof reg, 1, pSala);
    fclose(pSala);
    return escribio;
}

Sala leerRegistro(int pos) {
    Sala reg;
    FILE* pSala = fopen(nombre, "rb");
    if (pSala == NULL) {
        return reg;
    }
    fseek(pSala, pos * sizeof reg, 0);
    fread(&reg, sizeof reg, 1, pSala);
    fclose(pSala);
    return reg;
}

bool buscarID(int id, Sala& reg) {
    FILE* pSala = fopen(nombre, "rb");
    if (pSala == NULL) {
        return false;
    }
    while (fread(&reg, sizeof(Sala), 1, pSala) == 1) {
        if (reg.getIDSala() == id) {
            fclose(pSala);
            return true;
        }
    }
    fclose(pSala);
    reg.setEstado(false);
    return false;
}

bool ListarRegistro() {
    Sala reg;
    FILE* pSala = fopen(nombre, "rb");
    if (pSala == NULL) return false;
    while (fread(&reg, sizeof(Sala), 1, pSala) == 1) {
        reg.Mostrar();
    }
    fclose(pSala);
    return true;
}

bool modificarRegistro(int pos, Sala& salaObj) {
    FILE* archivo = fopen(nombre, "rb+");
    if (archivo == NULL) return false;
    fseek(archivo, sizeof(Sala) * pos, 0);
    bool res = fwrite(&salaObj, sizeof(Sala), 1, archivo);
    fclose(archivo);
    return res;
}

int ultimoID() {
    int bandera_id = 0;
    Sala sala;
    FILE* archivo = fopen(nombre, "rb");
    if (archivo == NULL) return 0;
    while (fread(&sala, sizeof(Sala), 1, archivo)) {
        if (sala.getIDSala() > bandera_id) {
            bandera_id = sala.getIDSala();
        }
    }
    fclose(archivo);
    return bandera_id;
}

bool SobreEscribeRegistro(Sala reg, int pos) {
    FILE* pSala = fopen(nombre, "rb+");
    if (pSala == NULL) return false;
    fseek(pSala, sizeof(Sala) * pos, SEEK_SET);
    bool valor = fwrite(&reg, sizeof(Sala), 1, pSala);
    fclose(pSala);
    return valor;
}
};


#endif // ARCHSALA_H_INCLUDED

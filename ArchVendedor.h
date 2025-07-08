#ifndef ARCHVENDEDOR_H_INCLUDED
#define ARCHVENDEDOR_H_INCLUDED
#include "ClsVendedor.h"
class ArchivoVendedor {
private:
    char nombre[30];
public:
    ArchivoVendedor() {
        strcpy(nombre, "Datos/vendedores.dat");
    }
bool grabarRegistro(Vendedor reg) {
    FILE* pVendedor = fopen(nombre, "ab");
    if (pVendedor == NULL) return false;
    int escribio = fwrite(&reg, sizeof reg, 1, pVendedor);
    fclose(pVendedor);
    return escribio;
}

Vendedor leerRegistro(int pos) {
    Vendedor reg;
    FILE* pVendedor = fopen(nombre, "rb");
    if (pVendedor == NULL) {
        return reg;
    }
    fseek(pVendedor, pos * sizeof reg, 0);
    fread(&reg, sizeof reg, 1, pVendedor);
    fclose(pVendedor);
    return reg;
}

bool buscarID(int id, Vendedor& reg) {
    FILE* pVendedor = fopen(nombre, "rb");
    if (pVendedor == NULL) {
        return false;
    }
    while (fread(&reg, sizeof(Vendedor), 1, pVendedor) == 1) {
        if (reg.getIDVendedor() == id) {
            fclose(pVendedor);
            return true;
        }
    }
    fclose(pVendedor);
    reg.setEstado(false);
    return false;
}

bool ListarRegistro() {
    Vendedor reg;
    FILE* pVendedor = fopen(nombre, "rb");
    if (pVendedor == NULL) return false;
    while (fread(&reg, sizeof(Vendedor), 1, pVendedor) == 1) {
        reg.Mostrar();
    }
    fclose(pVendedor);
    return true;
}

bool modificarRegistro(int pos, Vendedor& vendedorObj) {
    FILE* archivo = fopen(nombre, "rb+");
    if (archivo == NULL) return false;
    fseek(archivo, sizeof(Vendedor) * pos, SEEK_SET);
    bool res = fwrite(&vendedorObj, sizeof(Vendedor), 1, archivo);
    fclose(archivo);
    return res;
}

int ultimoID() {
    int bandera_id = 0;
    Vendedor vendedor;
    FILE* archivo = fopen(nombre, "rb");
    if (archivo == NULL) return 0;
    while (fread(&vendedor, sizeof(Vendedor), 1, archivo)) {
        if (vendedor.getIDVendedor() > bandera_id) {
            bandera_id = vendedor.getIDVendedor();
        }
    }
    fclose(archivo);
    return bandera_id;
}

};



#endif // ARCHVENDEDOR_H_INCLUDED

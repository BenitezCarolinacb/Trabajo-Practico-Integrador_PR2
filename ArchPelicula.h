#ifndef ARCHPELICULA_H_INCLUDED
#define ARCHPELICULA_H_INCLUDED

class ArchivoPelicula {
private:
    char nombre[30];

public:
    ArchivoPelicula() {
        strcpy(nombre, "Datos/peliculas.dat");
    }

   bool grabarRegistro(Pelicula reg) {
    FILE* pPelicula = fopen(nombre, "ab");
    if (pPelicula == NULL) return false;
    int escribio = fwrite(&reg, sizeof reg, 1, pPelicula);
    fclose(pPelicula);
    return escribio;
}

Pelicula leerRegistro(int pos) {
    Pelicula reg;
    FILE* pPelicula = fopen(nombre, "rb");
    if (pPelicula == NULL) {
        return reg;
    }
    fseek(pPelicula, pos * sizeof reg, 0);
    fread(&reg, sizeof reg, 1, pPelicula);
    fclose(pPelicula);
    return reg;
}

int  buscarID(int id, Pelicula& reg) {
    FILE* pPelicula = fopen(nombre, "rb");
    int pos=0;
    if (pPelicula == NULL) {
        cout<<"no existe el archivo"<<endl;
        return -1;
    }
    while (fread(&reg, sizeof(Pelicula), 1, pPelicula) == 1) {
        if (reg.getIDPelicula() == id) {
            fclose(pPelicula);
            return pos;
        }
        pos++;
    }
    fclose(pPelicula);
    return -1;
}

bool ListarRegistro() {
    Pelicula reg;
    FILE* pPelicula = fopen(nombre, "rb");
    if (pPelicula == NULL) return false;
    while (fread(&reg, sizeof(Pelicula), 1, pPelicula) == 1) {
        reg.Mostrar();
    }
    fclose(pPelicula);
    return true;
}

bool modificarRegistro(int pos, Pelicula& peliculaObj) {
    FILE* archivo = fopen(nombre, "rb+");
    if (archivo == NULL) return false;
    fseek(archivo, sizeof(Pelicula) * pos, SEEK_SET);
    bool res = fwrite(&peliculaObj, sizeof(Pelicula), 1, archivo);
    fclose(archivo);
    return res;
}

int ultimoID() {
    int bandera_id = 0;
    Pelicula pelicula;
    FILE* archivo = fopen(nombre, "rb");
    if (archivo == NULL) return 0;
    while (fread(&pelicula, sizeof(Pelicula), 1, archivo)) {
        if (pelicula.getIDPelicula() > bandera_id) {
            bandera_id = pelicula.getIDPelicula();
        }
    }
    fclose(archivo);
    return bandera_id;
}


};

#endif // ARCHPELICULA_H_INCLUDED

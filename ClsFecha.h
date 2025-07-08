#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha {
private:
    int _dia;
    int _mes;
    int _anio;
public:
    Fecha(int d=0, int m=0, int a=0) {
        _dia = d;
        _mes = m;
        _anio = a;
    }
    void setDia(int d){
                  if(d>=1 && d<32)
                _dia=d;
        }
    void setMes(int m) {
                    if(m>=1 && m<13) _mes = m;
                }
    void setAnio(int a){
                      _anio=a;
                    }

    int getDia() {return _dia;}
    int getMes() {return _mes;}
    int getAnio() {return _anio;}

    void Cargar() {
        cin>>_dia;cin>>_mes;cin>>_anio;
    }

    void Mostrar() {
        cout<<_dia<<"/"<<_mes<<"/"<<_anio<<endl;
    }

    bool operator==(Fecha aux) {
        if(_dia != aux._dia) return false;
        if(_mes != aux._mes) return false;
        if(_anio != aux._anio) return false;
        return true;
    }

    ~Fecha() {}



    };

#endif // CLSFECHA_H_INCLUDED

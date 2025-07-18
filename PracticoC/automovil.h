#ifndef AUTOMOVIL_H_INCLUDED
#define AUTOMOVIL_H_INCLUDED

enum estado {excelente, muyBueno, bueno, regular, malo};

typedef struct patente{
    char letras[3];
    int numeros[3];
};

typedef struct automovil{
    char marca[20];
    char nombreModelo[40];
    int modelo;
    enum estado estado;
    struct patente patente;
    int precio;
};

#endif // AUTOMOVIL_H_INCLUDED

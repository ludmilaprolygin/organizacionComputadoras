#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

enum sexo {F, M};
enum especificaciones {torre, piso, departamento};
enum estudios {primarios, secundarios, terciarios, universitarios, posgrado};
enum estadoCivil {soltero, casado, viudo, divorciado};

typedef struct domicilio{
    char calle[40];
    int numero;
    enum especificaciones especificacion;
};

typedef struct empleado{
    char apellido[40];
    char nombre[40];
    struct domicilio domicilio;
    int telefono;
    enum sexo sexo;
    int edad;
    enum estudios estudiosCursados;
    enum estadoCivil estado;
};

#endif // EMPLEADO_H_INCLUDED

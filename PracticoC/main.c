#include <stdio.h>
#include <stdlib.h>
#include "automovil.h"
#include "empleado.h"

struct automovil coche;
struct empleado empleado;
typedef struct alumno{
    int nroLegajo;
    char calificacion;
} *alumnoCurso;

//EJERCICIO3: Para modificar los tipos, deber�an definirse archivo con extensi�n .c y all� implementar las funciones requeridas.
//EJERCICIO4: Hacer esa asignaci�n hace una copia ""en profundidad"" (no existe tal t�rmino ac�); se copian los bytes de uno al
//      otro.
//EJERCICIO5: 1() Deber�a devolver un puntero mejor pero ta bien.
//            2() Falta asignar espacio en memoria con malloc() y, al no estar inicializado, no puedo acceder a esas variables
//                      que representan nombre y apellido. �Como accedo a algo que no tiene ese lugar? Ta mal porque quiz�s no
//                      contiene las cosas que busco; quiz�s aka muy probablemente xdxd
//            3() No libera el espacio reservado con malloc().
//            4() Se retorna un puntero a un espacio en memoria que se deja de utilizar porque es una variable local.

void ejercicio6(int *nrosLibreta, char *calificaciones, int cantAlumnos, char *rutaArchivo){
    FILE *f = fopen(rutaArchivo, "r");
    int i=0;
    while(!feof(f) && i<cantAlumnos){
        fscanf(f, "%i %c", &nrosLibreta[i], &calificaciones[i]);
        i++;
    }
    fclose(f);
}

void ejercicio7(char *rutaArchivo, struct alumno *alumnos, int cantAlumnos){
    FILE *f = fopen(rutaArchivo, "r");
    int i=0;
    while(!feof(f) && i<cantAlumnos){
        fscanf(f, "%i %c", &alumnos[i].nroLegajo, &alumnos[i].calificacion);
        i++;
    }
    fclose(f);
}

int main()
{
    int cantAlumnos;
    printf("Ingresar la cantidad de alumnos del curso \n");
    scanf("%i", &cantAlumnos);
    /*
    int nrosLibreta[cantAlumnos];
    char calificaciones[cantAlumnos];
    */
    char rutaArchivo[50];
    printf("Ingrese el nombre de archivo \n");
    scanf("%s", &rutaArchivo);
    struct alumno alumnos[cantAlumnos];
    //ejercicio6(&nrosLibreta, &calificaciones, cantAlumnos, &rutaArchivo);
    ejercicio7(&rutaArchivo, &alumnos, cantAlumnos);
    for(int i=0; i<cantAlumnos; i++){
        //printf("Alumno: %i Calificacion: %c \n", nrosLibreta[i], calificaciones[i]);
        printf("Alumno: %i Calificacion: %c \n", alumnos[i].nroLegajo, alumnos[i].calificacion);
    }
}

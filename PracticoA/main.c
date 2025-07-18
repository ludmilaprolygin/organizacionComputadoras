#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
 * Dise˜nar un programa que, dados tres enteros dia, mes, a˜no, analice si la fecha que representan es valida, e indique el resultado por pantalla.
 */
void ejercicio1()
{
    int dia, mes, anio, valida, bisiesto;

    printf("Ingrese una fecha de formato dd/mm/aaaa \n");
    scanf("%i %i %i", &dia, &mes, &anio);
    printf("%i/%i/%i \n", dia, mes, anio);

    bisiesto = (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;

    valida = (mes>0 && mes<13) && (dia>0 && dia<32) && anio>0 ? 1 : 0;
    if(valida!=0)
    {
        if(mes==4||mes==6||mes==9||mes==11)
            valida = dia<31 ? 1 : 0;
        else if(mes==2)
        {
            if(bisiesto!=0)
                valida = dia<30;
            else
                valida = dia<29;
        }

    }
    if(valida!=0)
        printf("La fecha ingresada es valida");
    else
        printf("La fecha ingresada es invalida");
}

/*
 * Dise˜nar un programa que, dado un entero largo (long) que representa una cantidad de segundos, convierta y muestre dicha cantidad de segundos en
 * el siguiente formato de tiempo: hh:mm:ss.
 */
void ejercicio2()
{
    long int convertir;
    int horas, minutos, segundos;
    printf("Ingrese una cantidad de segundos a convertir \n");
    scanf("%i", &convertir);

    segundos = convertir%60;
    minutos = convertir/60;

    horas = minutos/60;
    minutos = minutos%60;

    printf("%i:%i:%i", horas, minutos, segundos);
}

void ejercicio3()
{

    float Celsius, Fahrenheit;
    printf("Ingrese grados Celsius \n");
    scanf("%f", &Celsius);
    Fahrenheit = Celsius*33.8f;
    printf("%f Celsius corresponde a %f Fahrenheit", Celsius, Fahrenheit);


    float millasHora, kilometrosMinuto;
    printf("Ingrese millas/hora \n");
    scanf("%f", &millasHora);
    kilometrosMinuto = (millasHora*1.609344)/60;
    printf("Usted hace %f millas/horas, equivalente a %f kilometros/minuto", millasHora, kilometrosMinuto);


    float litrosK, millasG;
    printf("Ingrese litros/100kilometros \n");
    scanf("%f", &litrosK);
    millasG = 100/(0.264172052*1.60934*litrosK);
    printf("La conversion de %f litros/100kilometros a millas por galon es de %f", litrosK, millasG);
}

/*
 * Implementar un programa que lea n numeros enteros largos (long) y muestre por pantalla el mayor, el menor y el promedio de la serie ingresada.
 */
void ejercicio4()
{
    long int n, cursor, mayor, menor;
    float promedio;
    printf("Ingrese cuantos numeros ingresara \n");
    scanf("%i", &n);
    if(n!=0)
    {
        printf("Ingrese un numero \n");
        scanf("%i", &cursor);
        mayor = menor = cursor;
        promedio = cursor;
        if(n>0)
        {
            for(int i=1; i<n; i++)
            {
                printf("Ingrese un numero \n");
                scanf("%i", &cursor);
                mayor = mayor<cursor ? cursor : mayor;
                menor = menor>cursor ? cursor : menor;
                promedio += cursor;
            }
            promedio/=n;
        }
        printf("El mayor es %i, el menor %i y el promedio %f", mayor, menor, promedio);
    }
    else
        printf("No se ingreso ningun numero");
}

/*
 * Dise˜nar un programa que, dado un numero entero en notacion binaria, convierta dicho numero a su valor asociado bajo el sistema numerico decimal,
 * y lo muestre por pantalla.
 */
void ejercicio5()
{
    long int binario, decimal, contador, resto;
    contador = decimal = 0;
    printf("Ingrese un numero binario a convertir \n");
    scanf("%i", &binario);
    while(binario>0)
    {
        resto = binario%10;
        decimal+=resto*pow(2, contador);
        contador++;
        binario/=10;
    }
    printf("El numero decimal equivalente es %i", decimal);
}

/*
 * Implementar un programa que, a partir de una cadena de dıgitos hexadecimales terminada en ENTER ingresada por el usuario,
 * retorne su valor equivalente como entero en base diez. Se debe contemplar que los dıgitos permitidos van del 0 al 9 y de
 * A a F (mayusculas y minusculas incluidas).
 */
void ejercicio6()
{
    int numeroHexa;
    printf("Ingrese un numero en notacion hexagesimal \n");
    scanf("%x", &numeroHexa);
    printf("El numero es %i", (int) numeroHexa);
}

void ejercicio7()
{
    int cantDigitos, numero1;
    printf("Ingrese que numero quiere evaluar \n");
    scanf("%i", &numero1);
    cantDigitos = f_cantDigitos(numero1);
    printf("El numero %i tiene %i digitos", numero1, cantDigitos);


    int numero2, digito, cantApariciones;
    printf("Ingrese el digito que quiere contar y el numero donde quiere hacerlo separados por una coma \n");
    scanf("%i, %i", &digito, &numero2);
    cantApariciones = f_cantApariciones(numero2, digito);
    printf("El digito %i aparece %i veces en el numero %i", digito, cantApariciones, numero2);

    int numero3, cantVeces;
    printf("Ingrese el numero que quiere evaluar \n");
    scanf("%i", &numero3);
    cantVeces = f_paresImpares(numero3);
    printf("La apariciones de digitos pares en posiciones impares en el numero %i es de %i", numero3, cantVeces);
}

int f_cantDigitos(int numero)
{
    /* CB: Si un numero tiene un solo digito, la cantidad de digitos es 1.
     * CR: Si un numero tiene mas de un digito, la cantidad de digitos es la cantidad de digitos de n', con n' igual a n sin
     * su ultimo digito, incrementado en uno.
     */
    int toReturn;
    if(numero<10)
        toReturn = 1;
    else
        toReturn = f_cantDigitos(numero/10)+1;
    return toReturn;
}

int f_cantApariciones(int numero, int d)
{
    /* CB: Si n tiene un solo digito, si el digito buscado es igual a n, el digito tiene una aparicion. Si el numero no es
     * igual al digito buscado, el digito tiene cero apariciones.
     * CR: Si d tiene mas de un digito, si el ultimo digito de n es igual al digito buscado, la cantidad de apariciones del
     * digito buscado es la cantidad de apariciones del digito buscado en n', con n' igual a n sin su ultimo digito incrementado
     * en uno. Si el ultimo digito de n no es igual al digito buscado, la cantidad de apariciones del digito buscado en n, es
     * la cantidad de aparciciones del digito buscado en n'.
     */
    int toReturn;
    if(numero<10)
        if(numero==d)
            toReturn = 1;
        else
            toReturn = 0;
    else
        if(numero%10==d)
            toReturn = f_cantApariciones(numero/10, d)+1;
        else
            toReturn = f_cantApariciones(numero/10, d);
    return toReturn;
}

int f_paresImpares(int numero)
{
    /* CB: Si n tiene menos de 3 digitos, si el ultimo digito de n es par, entonces la cantidad de apariciones de digitos pares
     * en posiciones impares en el numero n es una. Si no, es cero.
     * CR: Si n tiene al menos 3 digitos, la cantidad de apariciones de digitos pares en posiciones impares sera igual a la
     * cantidad de apariciones de digitos pares en posiciones impares en n', con n' igual a n sin sus ultimos dos digitos,
     * incrementado en uno si el ultimo digito de n es par.
     */
    int toReturn;
    if(numero<99)
        if(numero%2==0)
            toReturn = 1;
        else
            toReturn = 0;
    else
        if((numero%10)%2==0)
            toReturn = f_paresImpares(numero/100)+1;
        else
            toReturn = f_paresImpares(numero/100);
    return toReturn;
}

/*
 * Denominaremos mediano de un numero entero largo positivo al numero que se obtiene de sumar todos los dıgitos que ocupan
 * posiciones impares y de restar todos los que ocupan posiciones pares. Por ejemplo, el mediano de 318547 es
 * 7−4+5−8+1−3 = −2. Teniendo esto en cuenta, dise˜nar e implementar un planteo recursivo que permita determinar el mediano de
 * un entero largo ingresado por el usuario.
 */
void ejercicio8()
{
    int numero, mediano;
    printf("Ingrese el numero del que desea calcular el mediano \n");
    scanf("%i", &numero);
    mediano = f_mediano(numero, 1);
    printf("El mediano de %i es %i", numero, mediano);
}

int f_mediano(int numero, int parImpar) //Par será 0, impar 1.
{
    /* CB: Si el numero tiene un solo digito y la posicion es par, el mediano sera su negativo. Si es impar, es el numero.
     * CR: Si el numero tiene mas de un digito, el mediano sera el mediano de n', con n' igual a n sin su ultimo digito. Si el
     * ultimo digito esta en posicion par, se restara al mediano, caso contrario se sumara.
     */
    int toReturn;
    if(numero<10)
        if(parImpar==0)
            toReturn = -numero;
        else
            toReturn = numero;
    else
        if(parImpar==0)
            toReturn = f_mediano(numero/10, 1)-numero%10;
        else
            toReturn = f_mediano(numero/10, 0)+numero%10;
    return toReturn;
}

/*
 * Un numero entero se dice prolijo si los dıgitos que lo componen aparecen en orden estrictamente ascendente o descendente.
 * Teniendo esto en cuenta, dise˜nar e implementar un plateo recursivo que permita determinar si un entero largo n es o no
 * un numero prolijo.
 */
void ejercicio9()
{
    int numero, prolijo, aux; //Prolijo será 0 si es falso, 1 si es verdadero.
    printf("Ingrese el numero a evaluar \n");
    scanf("%i", &numero);
    prolijo = f_prolijo(numero);
    if(prolijo==0)
        printf("El numero %i no es prolijo", numero);
    else
        printf("El numero %i es prolijo", numero);
}

int f_prolijo(int numero)
{
   /* CB: Si el numero tiene un digito, es prolijo.
    * CR: Si el numero tiene mas de un digito, es prolijo si el ultimo digito de n es menor que el ultimo digito de n', con n'
    * igual a n sin su ultimo digito y, n' es prolijo descendente. Si el numero tiene mas de un digito, es prolijo si el ultimo
    * digito de n es mayor que el ultimo digito de n', con n'igual a n sin su ultimo digito y, n' es prolijo asscendente. De
    * otra forma n no es prolijo.
    */
   int toReturn;
   if(numero<10)
        toReturn = 1;
   else
        if((numero/10)%10>numero%10)
            toReturn = f_prolijoAux(numero, 0);
        else
            toReturn = f_prolijoAux(numero, 1);
   return toReturn;
}

int f_prolijoAux(int numero, int ascDes) //ascDes será 0 si es descendente, 1 si es ascendente.
{
    int toReturn;
    if(ascDes==0)
        if(numero<100)
            toReturn=numero%10<(numero/10)%10;
        else
            toReturn=numero%10<(numero/10)%10 ? f_prolijoAux(numero/10, ascDes) : 0;
    else
        if(numero<100)
            toReturn=numero%10>(numero/10)%10;
        else
            toReturn=numero%10>(numero/10)%10 ? f_prolijoAux(numero/10, ascDes) : 0;
    return toReturn;
}

/* Diremos que una palabra es palındroma, si la misma puede leerse de igual forma de izquierda a derecha que de derecha a
 * izquierda. Teniendo esto en cuenta, dise˜nar e implementar un planteo recursivo que a partir de una secuencia de caracteres
 * ingresada por el usuario que representa la palabra, determine si esta es palındroma.
 */
void ejercicio10()
{
    char cadena[100];
    int palindroma, tamanio;
    printf("Ingrese una palabra para determinar si es palindroma. Debe tener un maximo de 100 caracteres \n");
    scanf("%s", &cadena);
    printf("Cadena: %s \n", cadena);
    tamanio=0;
    while(cadena[tamanio]!='\0')
        tamanio++;
    palindroma = f_palindroma(cadena, 0, tamanio-1);
    if(palindroma==0)
        printf("La palabra %s no es palindroma", cadena);
    else
        printf("La palabras %s es palindroma", cadena);
}

int f_palindroma(char cadena[], int i, int j)
{
    /* CB: Si la palabra tiene una sola letra es palindroma. Si tiene dos y son iguales es palindromas.
     * CR: Si la palabra tiene mas de una letra, es palindroma si sus extremos son iguales y si L', con L' igual a la cadena
     * sin sus extremos, es palindroma. Caso contrario no lo es.
     */
    int toReturn;
    if(i==j)
        toReturn=1;
    else if(i<j && i==j-1)
        toReturn=cadena[i]==cadena[j];
    else if(i<j)
        toReturn=cadena[i]==cadena[j] && f_palindroma(cadena, i+1, j-1);
    return toReturn;
}

main()
{
    //ejercicio1();
    //ejercicio2();
    //ejercicio3();
    //ejercicio4();
    //ejercicio5();
    //ejercicio6();
    //ejercicio7();
    //ejercicio8();
    //ejercicio9();
    //ejercicio10();
    //ejercicio11(); sorpresa3 calcula el inverso del numero, sorpresa2 calcula la cantidad de digitos, sorpresa1 calcula la potencia.
    //ejercicio12(); da vuelta las palabras.
}

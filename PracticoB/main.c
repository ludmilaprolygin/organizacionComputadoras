#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void arregloRandom(int arreglo[], int n){
    for(int i=0; i<n; i++)
        arreglo[i] = rand();
}

void arregloOrdenar(int arreglo[], int n){
    int ultimoChequeo=n-1;
    int huboIntercambios=1;
    int aux;
    while(huboIntercambios==1)
    {
        huboIntercambios=0;
        for(int i=0; i<ultimoChequeo; i++)
        {
            if(arreglo[i]>arreglo[ultimoChequeo])
            {
                aux=arreglo[ultimoChequeo];
                arreglo[ultimoChequeo]=arreglo[i];
                arreglo[i]=aux;
                huboIntercambios=1;
            }
        }
        ultimoChequeo--;
    }
}

int arregloOrdenado(int arreglo[], int n){
    int toReturn = 1;
    for(int i=0; i<n-1 && toReturn==1; i++)
        toReturn = arreglo[i]<=arreglo[i+1] ? 1 : 0;
    return toReturn;
}

void intercalar(int *arreglo1, int *arreglo2, int cant1, int cant2, int *intercalado){
    int c1=0;
    int c2=0;
    int c=0;
    if(arreglo1[c1]<arreglo2[c2]){
        intercalado[c]=arreglo1[c1];
        c++; c1++;
    }
    else{
        intercalado[c]=arreglo2[c2];
        c++; c2++;
    }
    while(c1<cant1 && c2<cant2){
        if(arreglo1[c1]<arreglo2[c2] && arreglo1[c1]>intercalado[c-1]){
            intercalado[c]=arreglo1[c1];
            c1++; c++;
        } else if(arreglo2[c2]<arreglo1[c1] && arreglo2[c2]>intercalado[c-1]){
            intercalado[c]=arreglo2[c2];
            c2++; c++;
        } else if(arreglo1[c1]==arreglo2[c2] && arreglo1[c1]>intercalado[c-1]){
            intercalado[c]=arreglo1[c1];
            c1++; c2++; c++;
        } else{c1++; c2++;}
    }
    while(c1<cant1){
        if(arreglo1[c1]>intercalado[c-1])
            intercalado[c++]=arreglo1[c1];
        c1++;
    }
    while(c2<cant2){
        if(arreglo2[c2]>intercalado[c-1])
            intercalado[c++]=arreglo2[c2];
        c2++;
    }
}

void arregloIntercalar(int *arreglo1, int *arreglo2, int length1, int length2, int *intercalado){
    arregloOrdenar(arreglo1, length1);
    arregloOrdenar(arreglo2, length2);
    intercalar(arreglo1, arreglo2, length1, length2, intercalado);
}

void reemplazar1(int arr [], int a, int n){ //Funciona bien lo que hace pero flasha el length
    int length = sizeof(arr)/sizeof(arr[0]);
    printf("Length: %i", length);
    for(int i=0; i<length; i++)
    {
        if(arr[i]==a)
            arr[i]=n;
    }
}

void reemplazar2(int *arr, int a, int n, int size){ //Funciona todo piolitahhhh :pPPP
    for(int i=0; i<size; i++)
    {
        if(*(arr+i)==a)
            *(arr+i)=n;
    }
}

void ejercicio7(int * arr [], int size){
    int i=0;
    int f=size-1;
    int* aux;
    while(i<f)
    {
        aux=arr[i];
        arr[i]=arr[f];
        arr[f]=aux;
        i++; f--;
    }
}

void ejercicio9(char f1[], char f2[]){
    char linea1[100]="\0", linea2[100]="\0";
    FILE *fp1 = fopen(f1, "r");
    FILE *fp2 = fopen(f2, "w+");
    char *puntero1, *puntero2;
    while(puntero1!=NULL){
        printf("%s", linea1);
        fprintf(fp2, "%s", linea1);
        puntero1=fgets(linea1,100,fp1);
    }
    fclose(fp1);
    rewind(fp2);
    printf("\n");
    while(puntero2!=NULL){
        printf("%s", linea2);
        puntero2=fgets(linea2,100,fp2);
    }
    fclose(fp2);
}

void ejercicio10(char f1[], char palabra[]){
    FILE *fp=fopen(f1,"r");
    char *puntero, *encontre=NULL;
    char linea[100]="\0";
    while(puntero!=NULL && encontre==NULL){
        puntero=fgets(linea,100,fp);
        encontre=strstr(linea,palabra);
    }
    if(encontre!=NULL)
        printf("%s", linea);
    else
        printf("%s", "La palabra no esta en el texto");
    fclose(fp);
}

void ejercicio11(char f1[]){
    FILE *fp1 = fopen(f1, "r+");
    FILE *fp2 = fopen("Ejercicio11-Auxiliar.txt", "w+");
    char *puntero, *punteroAux;
    char linea[100]="\0", lineaAux[100]="\0";
    int nroLinea=1;
    int yaTa=0;
    while(puntero!=NULL){
        if(yaTa!=0){
            fprintf(fp2, "%i: %s", nroLinea, linea);
            nroLinea++;
        }
        puntero=fgets(linea,100,fp1);
        yaTa=1;
    }
    rewind(fp1); rewind(fp2);
    while(punteroAux!=NULL){
        fprintf(fp1, "%s",lineaAux);
        punteroAux=fgets(lineaAux,100,fp2);
    }
    fclose(fp1); fclose(fp2);
    remove("Ejercicio11-Auxiliar.txt");
}

int main(){
    char rutaLeer[1024], rutaEscribir[1024];
    printf("Ingrese la ruta del archivo que desea abrir\n");
    scanf("%s", &rutaLeer);
    /*
    printf("Ingrese la ruta del archivo que desea escribir\n");
    scanf("%s", &rutaEscribir);
    */
    ejercicio11(rutaLeer);
}

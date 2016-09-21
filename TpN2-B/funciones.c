#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>



int menu()
{
    int opcion;
    printf("\n\nMenu de opciones. ");
    printf("\n\n 1. Agregar una persona. ");
    printf("\n 2. Borrar una persona.");
    printf("\n 3. Imprimir lista ordenada por nombre.");
    printf("\n 4. Imprimir grafico de edades.");
    printf("\n 5. Salir");

    printf("\n\nIngrese una opcion: ");
    scanf("%d", &opcion);

    while(opcion<1 || opcion>5)
    {
        printf("Error. Debe ingresar un numero entre 1 y 5. Reingrese: ");
        scanf("%d", &opcion);
    }

    return opcion;
}
int validarnombre(char auxcad[], int tam)
{
    int esvalidar=0;
    if(strlen(auxcad)<tam)
    {
        esvalidar=1;
    }

    return esvalidar;
}
void altas(epersona gente[],int tam)
{
    int indice;
    int dni;
    int indice2;
    char auxcad[50];
    int edad;

    indice=buscarLibre(gente, tam);

    if(indice==-1)
    {
        printf("\n No hay lugar disponible.");

    }
    else{
        printf("\n Ingrese DNI de la persona: ");
        scanf("%d", &dni);
        indice2=buscarPersona(gente, tam, dni);
        if(indice2!=-1)
        {
            printf("\n La persona ya esta ingresada en el sistema.");
        }
        else{
            gente[indice].dni=dni;

            printf("Ingrese nombre de la persona: ");
            fflush(stdin);
            gets(auxcad);

            while(!validarnombre(auxcad, 20))
            {
                printf("Nombre demaciado largo. Reingrese: ");
                gets(auxcad);
            }
            strcpy(gente[indice].nombre, auxcad);

            printf("\n Ingrese edad de la persona: ");
            scanf("%d", &edad);
            while(!validaredad(edad, 0, 120))
            {
                printf("Edad invalida. Reingrese: ");
                scanf("%d", &edad);
            }
            gente[indice].edad=edad;

            gente[indice].flag=1;
        }
    }


}

int buscarLibre(epersona gente[], int tam)
{
    int indice=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(gente[i].flag==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int buscarPersona(epersona gente[], int tam, int dni)
{
    int indice=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(gente[i].dni==dni)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
void inicializarPersona(epersona persona[], int tam)
{
    int i;
     for(i=0;i<5;i++)
    {

    persona[i].flag=0;
    }


}

void modificarPersona(epersona gente[], int tam)
{
    int dni;
    int opcion;
    int indice;
    printf("\n Ingrese dni de la persona a modificar: ");
    scanf("%d", &dni);

    indice=buscarPersona(gente, tam, dni);

    if(indice!=-1)
    {
        opcion=menuModificar();
        switch(opcion)
        {
        case 1:
            printf("\n Ingrese nuevo nombre: ");
            gets(gente[indice].nombre);
            break;
        case 2:
            printf("\n Ingrese nueva edad: ");
            scanf("%d", &gente[indice].edad);
            break;
        case 3:
            printf("\n Ingrese nuevo DNI: ");
            scanf("%d", &gente[indice].dni);
            break;
        }

    }

}
int menuModificar()
{
    int opcion;
    printf("\n Menu de opciones: ");
    printf("\n 1. Nombre");
    printf("\n 2. Edad");
    printf("\n 3. DNI");

    printf("\n Ingrese opcion a modificar: ");
    scanf("%d", &opcion);

    return opcion;
}
void borrarPersona(epersona gente[], int tam)
{
    int dni;
    int indice;
    char borrar;

    printf("\n Ingrese dni de la persona a borrar: ");
    scanf("%d", &dni);

    indice=buscarPersona(gente, tam, dni);

    if(indice!=-1)
    {  if(gente[indice].flag==0)
    {
        printf("\n\nLa persona ya fue borrada");

    }
    else{
        mostrarPersona(gente[indice]);
        printf("\n\nConfirma borrar?");
        fflush(stdin);
        scanf("%c", &borrar);
        if(borrar=='s')
        {
          gente[indice].flag=0;
          printf("\n\nBorrado exitoso!");
        }
        else{
            printf("\n\nLa baja fue cancelada.");
        }
    }}
    else{
        printf("\n La persona no esta ingresada");
    }

}
void ordenarPersonas(epersona gente[], int tam)
{
    int i;
    int j;
    epersona auxiliar;

  for(i=0; i<tam-1; i++)
  {
      for(j=i+1; j<tam; j++)
      {
          if(strcmp(gente[i].nombre, gente[j].nombre)>0)
          {
              auxiliar=gente[i];
              gente[i]=gente[j];
              gente[j]=auxiliar;

          }

      }
  }
}
void mostrarPersonas(epersona gente[], int tam)
{   int i;

    printf("\n\n Nombre      Edad      DNI");
    for(i=0; i<tam; i++)
    {   if(gente[i].flag==1)
    {


        mostrarPersona(gente[i]);
    }
    }

}
void mostrarPersona(epersona gente)
{
    if(gente.flag==1)
    {

    printf("\n %10s    %5d     %8d", gente.nombre, gente.edad, gente.dni);
    }
}
int validaredad(int edad, int inf, int sup)
{
    int esvalidar=0;
    if(edad>=inf && edad<=sup)
    {
        esvalidar=1;
    }
    return esvalidar;
}

void graficarpersonas(epersona persona[], int tam)
{
    int i;
    int mayor;
    int hasta18=0;
    int de19a35=0;
    int mayorDe35=0;
    int flag=0;

      for (i=0; i<tam; i++)
       {
           if(persona[i].flag==1)
           {

           if(persona[i].edad<=18)
           {
               hasta18=hasta18+1;
           }
           else{
            if(persona[i].edad>=19 && persona[i].edad<=35)
            {
               de19a35 =de19a35+1;
            }
            else{
                mayorDe35=mayorDe35+1;
            }
           }
       }
       }

       if(hasta18 >= de19a35 && hasta18 >= mayorDe35){
        mayor = hasta18;
    }else{
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else{
        mayor = mayorDe35;
        }
    }
   system("pause");
    for(i=mayor; i>0; i--){
        if(i<10){
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= hasta18){
            printf("*");
        }
        if(i<= de19a35){
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }

    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d", hasta18, de19a35, mayorDe35);
}

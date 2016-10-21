#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define TAM_PELICULA   3
#include "Funciones.h"


int main()
{
   movie peliculas[TAM_PELICULA];
   int opcion;
   char seguir='s';
   char confirma;
   int id=1000;
   int Agregado;
   int i;
   int cantidadEscrita;
   char NombreArchivo[]="Peliculas_web";

   inicializarPelicula(peliculas, TAM_PELICULA);

   while(seguir=='s')
   {

     opcion=Menu();

     switch(opcion)
       {
        case 1:
             Agregado=AgregarPelicula(peliculas, TAM_PELICULA, id);
             if(Agregado==1)
               {
                id=id+1;
              }
             break;
        case 2:
              BorrarPelicula(peliculas, TAM_PELICULA);
              break;
        case 3:
              ModificarPelicula(peliculas, TAM_PELICULA);
              break;
        case 4:
              GenerarPagina(peliculas, TAM_PELICULA, NombreArchivo);
              break;
        case 5:
              printf("\n\n Confirma que desea salir? s/n");
              confirma=getche();
              while(confirma!='s' && confirma!='n')
                {
                   printf("\n ERROR. Debe ingresar s/n. Reingrese:");
                   confirma=getche();
                 }
              if(confirma=='s')
                 {
                   seguir='n';
                 }
              break;
        default:
            printf("ERROR. Debe ingresar un valor entre 1 y 5. Reingrese: ");
            break;
         }

    FILE *archivo1 = fopen("Peliculas.bin", "wb");
    if (archivo1 == NULL)
      {
        printf("Error al abrir el archivo!\n");
        exit(1);
      }

    for(i=0; i<TAM_PELICULA; i++)
      {
       if(peliculas[i].Estado==1)
          {

            cantidadEscrita = fwrite(&peliculas[i], sizeof(movie), 1, archivo1);
            if(cantidadEscrita<1)
              {
                printf("\n Error al escribir el archivo.");

              }
          }
      }
       fclose(archivo1);

   }

    return 0;
}

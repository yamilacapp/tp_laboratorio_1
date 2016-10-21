
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define TAM_PELICULA   3
#include "Funciones.h"



int Menu()
{   int opcion;
    printf("\n\nMenu de opciones: ");
    printf("\n\n 1. Agregar pelicula");
    printf("\n 2. Borrar pelicula");
    printf("\n 3. Modificar pelicula");
    printf("\n 4. Generar pagina web");
    printf("\n 5. Salir");
    printf("\n\n Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int AgregarPelicula(movie peliculas[],int TAM, int id)
{   int Agregado=0;
    char Titulo[100];
    char Genero[50];
    char Descripcion[1000];
    char Link[200];
    int Puntaje;
    int Duracion;
    int indice=BuscarLibre(peliculas, TAM);

    if(indice==-1)
      {
       printf("No hay espacio en el sistema.");
      }
    else{

      peliculas[indice].idPelicula=id;
      fflush(stdin);
      printf("\n Ingrese Titulo de la pelicula:");
      gets(Titulo);
      while(strlen(Titulo)>50)
        {
          printf("\n Titulo de la pelicula demaciado largo. Reingrese: ");
          gets(Titulo);
        }

      strcpy(peliculas[indice].titulo, Titulo);

      printf("\n Ingrese Puntaje de la pelicula: ");
      scanf("%d", &Puntaje);
      while(Puntaje<0 || Puntaje>100)
        {
          printf("\nPuntaje incorrecto. Ingrese un valor del 0 al 100: ");
          scanf("%d", &Puntaje);
        }
      peliculas[indice].puntaje=Puntaje;

      fflush(stdin);
      printf("\n Ingrese Genero de la pelicula:");
      gets(Genero);
      while(strlen(Genero)>19)
        {
          printf("\n ERROR. Genero demaciado largo. Reingrese:");
          gets(Genero);
        }
      strcpy(peliculas[indice].genero, Genero);

      printf("\n Ingrese duracion de la pelicula:");
      scanf("%d", &Duracion);
      while(Duracion<30 || Duracion>5000)
        {
          printf("\n Error. Demaciado tiempo. Reingrese:");
          scanf("%d", &Duracion);
        }
      peliculas[indice].duracion=Duracion;


      fflush(stdin);
      printf("\n Ingrese descripcion de la pelicula: ");
      gets(Descripcion);
      while(strlen(Descripcion)>499)
        {
          printf("\n Error. Descripcion demaciado larga. Reingrese:");
          gets(Descripcion);
        }

      strcpy(peliculas[indice].descripcion, Descripcion);

      printf("\n Ingrese link de la imagen de la pelicula: ");
      gets(Link);
      while(strlen(Link)>149)
        {
          printf("\nError. Link demaciado largo. Reingrese: ");
          gets(Link);
        }

      strcpy(peliculas[indice].linkimagen, Link);

      peliculas[indice].Estado=1;

      Agregado=1;


    }

   return Agregado;

}

void inicializarPelicula(movie peliculas[],int TAM)
{
   int i;

   for(i=0; i<TAM; i++)
     {
        peliculas[i].Estado=0;
     }

}

int BuscarLibre(movie peliculas[],int TAM)
{
    int indice=-1;
    int i;

    for(i=0; i<TAM; i++)
    {
        if(peliculas[i].Estado==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void BorrarPelicula(movie peliculas[],int TAM)
{
    int ID;
    char si;

    MostrarPeliculas(peliculas, TAM);

    printf("\n Ingrese ID de la pelicula que quiere borrar: ");
    scanf("%d", &ID);

    int indice=BuscarPelicula(peliculas, TAM, ID);

    if(indice==-1)
       {
        printf("\n El ID que ingreso no se encuentra en el sistema.");
       }
      else{

         printf("\n Confirma que desea borrar? s/n");
         si=getche();
         while(si!='s' && si!='n')
          {
            printf("\n Error. Debe ingresar s/n. Reingrese: ");
            si=getche();
          }

         if(si=='s')
            {

               peliculas[indice].Estado=0;
               printf("\n\n ¡Se borro exitosamente!");

            }
            else{
                   printf("\n\n Se cancelo la baja de la pelicula!");
                }


         }


}

int BuscarPelicula(movie peliculas[],int TAM,int ID)
{
    int i;
    int indice=-1;

    for(i=0; i<TAM; i++)
       {
         if(peliculas[i].idPelicula==ID && peliculas[i].Estado==1)
            {
               indice=i;
            }

       }

     return indice;

}

void MostrarPeliculas(movie peliculas[],int TAM)
{
    int i;

    printf("\n\nId                  Titulo                              Genero   Puntaje  Duracion ");

    for(i=0; i<TAM;i++)
       {
           if(peliculas[i].Estado==1)
              {
                  printf("\n %d          %25s          %10s    %5d   %5d ", peliculas[i].idPelicula, peliculas[i].titulo, peliculas[i].genero, peliculas[i].puntaje, peliculas[i].duracion);
              }
       }

}


void ModificarPelicula(movie peliculas[],int TAM)
{
   int ID;
   int indice;
   int opcion;
   char si;
   char Titulo[100];
   char Genero[50];
   char Descripcion[1000];
   char Link[200];
   int Puntaje;
   int Duracion;

   MostrarPeliculas(peliculas, TAM);

   printf("\n Ingrese Id de la pelicula que quiere modificar: ");
   scanf("%d", &ID);

   indice=BuscarPelicula(peliculas, TAM, ID);
   if(indice==-1)
     {
         printf("\n El Id ingresado no se encuentra en el sistema. ");
     }
    else{
           printf("\n Menu de opciones: ");
           printf("\n 1. Titulo");
           printf("\n 2. Genero");
           printf("\n 3. Puntaje");
           printf("\n 4. Duracion");
           printf("\n 5. Descripcion");
           printf("\n 6. Link de la imagen");
           printf("\n\n Ingrese la opcion que desea modificar: ");
           scanf("%d", &opcion);

           while(opcion<1 || opcion>6)
             {
               printf("\n OPCION NO VALIDA. Reingrese un valor entre 1 y 6: ");
               scanf("%d", &opcion);
             }

           printf("\n\n Confirma que desea modificar? s/n");
           si=getche();
           while(si!='s' && si!= 'n')
              {
                printf("\n Error. Debe ingresar s/n. Reingrese:");
                si=getche();
              }

           if(si=='s')
             {

               switch(opcion)
                 {
                    case 1:
                        fflush(stdin);
                        printf("\n Ingrese el nuevo Titulo de la pelicula: ");
                        fflush(stdin);
                        gets(Titulo);
                         while(strlen(Titulo)>99)
                           {
                              printf("\n Titulo de la pelicula demaciado largo. Reingrese: ");
                              gets(Titulo);
                           }

                        strcpy(peliculas[indice].titulo, Titulo);

                        printf("\n Modificacion exitosa!");

                        break;

                    case 2:
                        fflush(stdin);
                        printf("\n Ingrese Nuevo Genero de la pelicula:");
                        gets(Genero);
                         while(strlen(Genero)>49)
                           {
                               printf("\n ERROR. Genero demaciado largo. Reingrese:");
                               gets(Genero);
                            }
                        strcpy(peliculas[indice].genero, Genero);
                        printf("\n Modificacion exitosa!");

                        break;

                    case 3:
                        printf("\n Ingrese Nuevo Puntaje de la pelicula: ");
                        scanf("%d", &Puntaje);
                         while(Puntaje<0 || Puntaje>100)
                           {
                             printf("\nPuntaje incorrecto. Ingrese un valor del 0 al 100: ");
                             scanf("%d", &Puntaje);
                           }
                        peliculas[indice].puntaje=Puntaje;
                        printf("\n Modificacion exitosa!");

                        break;
                    case 4:
                        printf("\n Ingrese duracion de la pelicula:");
                        scanf("%d", &Duracion);
                         while(Duracion<30 || Duracion>5000)
                           {
                              printf("\n Error. Demaciado tiempo. Reingrese:");
                              scanf("%d", &Duracion);
                            }
                        peliculas[indice].duracion=Duracion;

                        printf("\n Modificacion exitosa!");
                        break;

                    case 5:
                        fflush(stdin);
                        printf("\n Ingrese descripcion de la pelicula: ");
                        gets(Descripcion);
                         while(strlen(Descripcion)>999)
                           {
                            printf("\n Error. Descripcion demaciado larga. Reingrese:");
                            gets(Descripcion);
                            }

                        strcpy(peliculas[indice].descripcion, Descripcion);

                        printf("\n Modificacion exitosa!");
                        break;
                    case 6:
                        printf("\n Ingrese link de la imagen de la pelicula: ");
                        gets(Link);
                         while(strlen(Link)>199)
                           {
                            printf("\nError. Link demaciado largo. Reingrese: ");
                             gets(Link);
                            }

                         strcpy(peliculas[indice].linkimagen, Link);

                         printf("\n Modificacion exitosa!");
                         break;

                 }
            }
            else{
                printf("\n Se cancelo modificacion!");
            }
         }

}
void GenerarPagina(movie peliculas[],int TAM,char NombreArchivo[])
{   int cantidadEscrita;
    int i;
    int Longitud;
    char lineaTitulo[1000];
    char lineaDuracion[500];
    char lineaPuntaje[500];
    char lineaDescripcion[1000];
    char lineaGenero[500];
    char lineaLink[500];
    char CadenaInicio[]="<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'><!-- Repetir esto para cada pelicula -->";

   char lineaHeaderIni[] = "<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='";
    char lineaHeaderFin[] = "' alt=''></a>";
    char lineaTituloIni[]="<h3><a href='#'>";
    char lineaTituloFin[]="</a></h3>";
    char lineaIniGenero[]="<ul><li>Genero: ";
    char lineaFinGenero[]="</li>";
    char lineaPuntajeIni[]="<li>Puntaje: ";
    char lineaPuntajeFin[]="</li>";
    char puntaje[10];
    char duracion[10];
    char lineaDuracionIni[]="<li>Duracion: ";
    char lineaDuracionFin[]="</li></ul>";
    char lineaDescripcionIni[]="<p>Descripcion: ";
    char lineaDescripcionFin[]="</p></article>";
    char lineaCadenaFin[]="</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>";

    // Creo el archivo y lo abro
    FILE *Archivo= fopen(NombreArchivo, "w");
     if(Archivo==NULL)
       {
         printf("\n ERROR. El programa se cerrará");
         exit(1);
       }


    Longitud=strlen(CadenaInicio);
    //escribo la cabecera del archivo
    cantidadEscrita=fwrite(CadenaInicio, sizeof(char), Longitud, Archivo);

     if(cantidadEscrita<Longitud)
       {
         printf("Error al escribir el archivo");
         exit(1);
       }

    for(i=0; i<TAM; i++)
       {

         if(peliculas[i].Estado==1)
           {
              // inicializo el vector
              lineaLink[0]='\0';
              strcat(lineaLink, lineaHeaderIni);
              strcat(lineaLink, peliculas[i].linkimagen);
              strcat(lineaLink, lineaHeaderFin);
              //lineaLink contiene el texto a ser grabado
              Longitud=strlen(lineaLink);

              //escribo en el archivo el texto del link de la imagen
              cantidadEscrita=fwrite(lineaLink, sizeof(char), Longitud, Archivo);

               if(cantidadEscrita<Longitud)
                 {
                   printf("Error al escribir el archivo");
                   exit(1);
                  }

              lineaTitulo[0]='\0';
              strcat(lineaTitulo, lineaTituloIni);
              strcat(lineaTitulo, peliculas[i].titulo);
              strcat(lineaTitulo, lineaTituloFin);

              Longitud=strlen(lineaTitulo);


              cantidadEscrita=fwrite(lineaTitulo, sizeof(char), Longitud, Archivo);

              if(cantidadEscrita<Longitud)
                 {
                   printf("Error al escribir el archivo");
                   exit(1);
                 }



              lineaGenero[0]='\0';
              strcat(lineaGenero, lineaIniGenero);
              strcat(lineaGenero, peliculas[i].genero);
              strcat(lineaGenero, lineaFinGenero);

              Longitud=strlen(lineaGenero);

              cantidadEscrita=fwrite(lineaGenero, sizeof(char), Longitud, Archivo);

               if(cantidadEscrita<Longitud)
                  {
                    printf("Error al escribir el archivo");
                    exit(1);
                   }


              lineaPuntaje[0]='\0';
              sprintf(puntaje, "%d", peliculas[i].puntaje);
              strcat(lineaPuntaje, lineaPuntajeIni);
              strcat(lineaPuntaje, puntaje);
              strcat(lineaPuntaje, lineaPuntajeFin);

              Longitud=strlen(lineaPuntaje);

              cantidadEscrita=fwrite(lineaPuntaje, sizeof(char), Longitud, Archivo);

               if(cantidadEscrita<Longitud)
                 {
                    printf("Error al escribir el archivo");
                    exit(1);
                  }

             sprintf(duracion, "%d", peliculas[i].duracion);

             lineaDuracion[0]='\0';
             strcat(lineaDuracion, lineaDuracionIni);
             strcat(lineaDuracion, duracion);
             strcat(lineaDuracion, lineaDuracionFin);
             Longitud=strlen(lineaDuracion);

             cantidadEscrita=fwrite(lineaDuracion, sizeof(char), Longitud, Archivo);

              if(cantidadEscrita<Longitud)
                 {
                   printf("Error al escribir el archivo");
                   exit(1);
                  }

              lineaDescripcion[0]='\0';
              strcat(lineaDescripcion, lineaDescripcionIni);
              strcat(lineaDescripcion, peliculas[i].descripcion);
              strcat(lineaDescripcion, lineaDescripcionFin);
              Longitud=strlen(lineaDescripcion);

              cantidadEscrita=fwrite(lineaDescripcion, sizeof(char), Longitud, Archivo);

                if(cantidadEscrita<Longitud)
                  {
                     printf("Error al escribir el archivo");
                     exit(1);
                   }


           }
       }
    //escribo el final del archivo
    Longitud=strlen(lineaCadenaFin);
    cantidadEscrita=fwrite(lineaCadenaFin, sizeof(char), Longitud, Archivo);

      if(cantidadEscrita<Longitud)
        {
           printf("Error al escribir el archivo");
           exit(1);
        }

     printf("\nSe creo correctamente el archivo.");
     //Cierro el archivo
     fclose(Archivo);

}


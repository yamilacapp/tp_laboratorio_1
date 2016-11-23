#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int serializarLista(char* Path, ArrayList* Lista)
{
int cargo;
int serializo=-1;
int i;
    FILE* Archivo;
    if(Lista!=NULL && Path!=NULL)
    {

    Archivo=fopen(Path, "wb");
    if(Archivo!=NULL)
    {  serializo=1;
        for(i=0; i<Lista->len(Lista); i++)
        {

              cargo= fwrite(Lista->pElements[i], sizeof(Employee), 1, Archivo);
               if (cargo!=1)
               {
                   printf("\n Error al cargar!");
                   exit(1);
               }



        }
    }

    }
    fclose(Archivo);
    return serializo;
}

ArrayList* DeserializarLista(char* Path, ArrayList* lista)
{
    FILE* Archivo;
    Employee* pAux;
   // Employee* pAux2;
    int leyo;
    int returnAux=-1;
   // int i;
if(Path!=NULL)

   {//printf("\n Abriendo Archivo");
       Archivo=fopen(Path, "rb");
       if(Archivo!=NULL)
        {  // printf("\n Cargando Archivo");
            while(!feof(Archivo))
              {
                pAux=(Employee*)malloc(sizeof(Employee));
               // printf("\n Tomo memoria con malloc");
                if(pAux!=NULL)
                 {
                    //printf("\n Leyendo Archivo");
                   leyo= fread(pAux, sizeof(Employee), 1, Archivo);
                    //printf("\n Leyengo archivo..");
                   if(leyo==1)
                    {
                    // printf("\n Leyo!");
                   /* for(i=0; i<lista->len(lista);i++)
                    {  pAux2=(Employee*)lista->get(lista, i);
                       if(pAux2->id==pAux->id)
                       {
                           pAux->id=lista->size+1;
                       }
                    }*/
                     lista->add(lista, pAux);
                    }


                  }
              }
           returnAux=1;
           fclose(Archivo);
         }
     }
     return returnAux;
}




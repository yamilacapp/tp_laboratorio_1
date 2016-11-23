#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"
#include "Validaciones.h"
#include "Archivo.h"

int menu();

int main()
{
    char seguir = 's';
    char confirma;
    int i;
    char Nombre[50];
    Employee* pEmpleado;
    Employee* pAux;
    ArrayList* lista;
    FILE* pFile;
    int indice;
    int indice2;
    int id;
    Employee* nuevoEmpleado;
    ArrayList* lista2;
    ArrayList* SubLista;
    int band=0;
    int band2=0;
    int band3=0;
    char* Path={"Persona.data"};
    int serializo;


    do
    {
        switch(menu())
        {
        case 1:
            if(band==0)
            {
                lista = al_newArrayList();
                band=1;
            }
            pFile = fopen("data.csv", "r");
            if(pFile == NULL)
            {
             printf("No se pudo abrir el archivo\n");
             exit(1);
            }
            printf("\n Se abrio el archivo");
            system("PAUSE");

            if(parserEmployee(pFile, lista))
            {

                printf("Parseo exitoso\n\n");
                fclose(pFile);
            }
            else
                 printf("Problema al Parsear\n\n");

            system("pause");
            break;


        case 2:
            if(band!=0)
            {//Cargo Empleados en el Archivo
                serializo=serializarLista(Path,lista);
              if(serializo==1)
               {
                  printf("\n Carga exitosa del Archivo!");
                  system("PAUSE");
                }
            }
            else{
                printf("\n La lista no esta cargada");
                system("PAUSE");
            }

            break;
        case 3:
            if(band==0)
            {
                 lista = al_newArrayList();
                 band=1;
            }
            if(DeserializarLista(Path, lista))
            {   printf("\n Array cargado con exito!");
                printf("\n Imprimo lista2\n");


                for(i=0; i<lista->len(lista); i++)
                 {
                   pAux=(Employee*)lista->get(lista, i);
                  employee_print(pAux, i);

                  }
            }

            else{
                printf("\nError. Hubo un problema con la lectura del Archivo");
                system("PAUSE");
            }
            system("PAUSE");
            break;
        case 4:
             if(band!=0)
             {


                for(i=0; i< lista->len(lista); i++)
                 {
                 pEmpleado =(Employee*) lista->get(lista, i);
                  employee_print(pEmpleado, i);

                   if(!(i%50))
                   {
                    system("pause");
                   }
                 }system("pause");
             }
            else{
                printf("\n LA lista todavia no esta cargada");
                system("PAUSE");
              }
            break;
        case 7:
            if(band!=0)
              {


                nuevoEmpleado = employee_new();

                system("cls");
                printf("Agregar un Empleado\n\n");
                printf("Ingrese id:");
                scanf("%d", &id);
                while(IsId(lista, id)!=0)
                 {
                  printf("\n El id ya esta ingresado. Reintente:");
                   scanf("%d", &id);
                 }

            //Validar Id
               if(employee_setId(nuevoEmpleado, id)==-1)
                 {
                  printf("\n Hubo un Error. Vuelva a intentarlo.");
                  break;

                 }
              printf("Ingrese nombre:");
              fflush(stdin);
              gets(Nombre);
              //Validar Nombre
              if(employee_setName(nuevoEmpleado, Nombre)==-1)
               {
                 printf("\n Hubo un Error. Vuelva a intentarlo.");
                  break;
               }
              printf("Ingrese apellido:");
              //system("PAUSE");
              fflush(stdin);
              gets(Nombre);
              system("PAUSE");
              if(employee_setLastName(nuevoEmpleado, Nombre)==-1)
                {
                  printf("\n Hubo un Error. Vuelva a intentarlo.");
                  break;
                }
               printf("\n Ingrese Indice:");
              scanf("%d", &indice);
              while(indice<0 || indice>lista->len(lista))
                {
                  printf("\n Indice ingresado no es valido. Reingrese:");
                  scanf("%d", &indice);
                }
              if(!lista->push(lista, indice, nuevoEmpleado))
                {
                   printf("\n Empleado agregado en indice ingresado!");
                   system("PAUSE");
                }

           }
            else{
                printf("\n La lista no esta creada!");
               }
            break;
        case 5:
            if(band!=0)
            {

              lista->sort(lista, employee_compare, 1); /* Puedo crear otra opcion que me diga ordenar en orden descendente..*/
            }
            else{
                printf("\n La lista no esta creada.");
                system("PAUSE");
            }
            break;

        case 6:
            if(band==0)
            {
                lista = al_newArrayList();
                band=1;
            }


            nuevoEmpleado = employee_new();

            system("cls");
            printf("Agregar un Empleado\n\n");
            printf("Ingrese id:");
            scanf("%d", &id);
            if(IsId(lista, id)==0)
            {
            //Validar Id
             if(employee_setId(nuevoEmpleado, id)==-1)
                 {
                 printf("\n Hubo un Error. Vuelva a intentarlo.");
                 break;

                }
              printf("Ingrese nombre:");
              fflush(stdin);
              gets(Nombre);
            //Validar Nombre
              if(employee_setName(nuevoEmpleado, Nombre)==-1)
               {
                printf("\n Hubo un Error. Vuelva a intentarlo.");
                break;
               }
              printf("Ingrese apellido:");
            //system("PAUSE");
              fflush(stdin);
              gets(Nombre);
              system("PAUSE");
              if(employee_setLastName(nuevoEmpleado, Nombre)==-1)
                {
                printf("\n Hubo un Error. Vuelva a intentarlo.");
                break;
                }

              lista->add(lista, nuevoEmpleado);

              printf("\n\nEmpleado agregado con exito\n\n");
              system("PAUSE");
           }
            else{
                if(IsId(lista, id)==1)
                  {
                    printf("\n El id ya esta ingresado");
                    system("PAUSE");
                  }
                else{
                    printf("\n Hubo un Error. Vuelva a intentarlo! (ERROR DE ID)");
                    system("PAUSE");
                }
            }


            break;
        case 8:
            if(band!=0)
             {


                printf("Ingrese indice: ");
                scanf("%d", &indice);
                pEmpleado =(Employee*) lista->get(lista, indice);

               if(pEmpleado!=NULL)
                {
                  employee_print(pEmpleado, indice);
                  printf("\nConfirma borrado?: ");
                  fflush(stdin);
                  scanf("%c", &confirma);
                  if(confirma == 's' || confirma == 'S')
                   {

                    employee_delete(pEmpleado, lista);
                    printf("\n Borrado exitoso!");
                   }
                }
                else{
                     printf("\n ERROR!");
                    }

               system("pause");
            }
            else{
                printf("\n La lista no esta creada.");
                system("PAUSE");
                }
            break;
        case 9:
            if(band!=0)
             {

               printf("\n Listar empleados desde:\n Ingrese indice:");
               scanf("%d", &indice);
               printf("\n Listar empleados hasta:\n Ingrese indice:");
               scanf("%d", &indice2);
               while(!validarIndice(indice, indice2, lista))
                {
                 printf("\n Error al ingresar indices. Reingrese.");
                  printf("\n Listar empleados desde:\n Ingrese indice:");
                 scanf("%d", &indice);
                 printf("\n Listar empleados hasta:\n Ingrese indice:");
                 scanf("%d", &indice2);

                }


               for(i=indice; i<=indice2; i++)
                {
                   pEmpleado=(Employee*)lista->get(lista, i);


                    employee_print(pEmpleado, i);
                    fflush(stdin);

                 if(!(i%50))
                   {
                    system("pause");
                   }
                }
               system("PAUSE");
            }
            else{
                printf("\n La lista no esta cargada.");
                system("PAUSE");
               }

            break;
        case 10:
             if(band!=0)
              {

                lista2=lista->clone(lista);
                if(lista2!=NULL &&lista->containsAll(lista, lista2)==1)
                 {   band2=1;
                     printf("\n Copia exitosa!");
                     system("PAUSE");
                  }
                else{
                    printf("\n Error al copiar lista");
                    system("PAUSE");
                   }
             }
             else{
                printf("\n La lista todavia no fue creada");
               }
            break;
        case 11:
            if(band2==1)
              {

                for(i=0; i< lista2->len(lista2); i++)
                 {
                     pEmpleado =(Employee*) lista2->get(lista2, i);

                      employee_print(pEmpleado, i);

                   if(!(i%50))
                    {
                       system("pause");
                    }
                  }
               system("PAUSE");
            }
            else{
                printf("\n La lista no fue clonada.");
                system("PAUSE");
            }
            break;
        case 12:
              if(band!=0)
              {

                 printf("\n Clonar empleados desde:\n Ingrese indice:");
                 scanf("%d", &indice);
                 printf("\n Clonar empleados hasta:\n Ingrese indice:");
                 scanf("%d", &indice2);
                  while(!validarIndice(indice, indice2, lista))
                   {
                    printf("\n Error al ingresar indices. Reingrese.");
                    printf("\n Clonar empleados desde:\n Ingrese indice:");
                    scanf("%d", &indice);
                    printf("\n Clonar empleados hasta:\n Ingrese indice:");
                    scanf("%d", &indice2);

                  }
                 fflush(stdin);
                 SubLista=lista->subList(lista, indice, indice2);
                 fflush(stdin);
                 system("PAUSE");
                 if(SubLista!=NULL)
                 {   band3=1;
                     printf("\n Sublista creada!");
                     system("PAUSE");

                 }
             }
              else{
                printf("\n La lista todavia no fue creada");
                system("PAUSE");
               }
            break;
        case 13:
            if(band3==1)
            {

               for(i=0; i< SubLista->len(SubLista); i++)
                 {   fflush(stdin);
                     pEmpleado =(Employee*) SubLista->get(SubLista, i);


                        fflush(stdin);
                    employee_print(pEmpleado, i);
               // system("PAUSE");


                    if(!(i%50))
                  {
                    system("pause");
                  }
               }
              system("PAUSE");
            }
            else{
                printf("\n La sublista no fue creada");
                system("PAUSE");
            }
            break;
        case 14:
            if(band!=0)
              {

                printf("\n Confirma que desea limpiar lista?");
                confirma = getche();
                 if(confirma=='s' || confirma=='S')
                  {
                      lista->clear(lista);
                      if(lista->isEmpty(lista))
                       {
                          printf("\n Borrado exitoso!");
                          system("PAUSE");
                        }
                 }
                 else{
                      printf("\n Borrado cancelado!");
                      system("PAUSE");
                      }
            }
            else{
                printf("\n La lista no esta creada");
                system("PAUSE");
            }
            break;
        case 15:
            if(band!=0 && band2!=0)
            {

                printf("\n Ingrese indice del empleado que desea cambiar de lista: ");
                scanf("%d", &indice);
                 while(indice<0 || indice>=lista->len(lista))
                   {
                      printf("\n Indice mal ingresado. Reingrese: ");
                       scanf("%d", &indice);
                   }
                 pEmpleado=lista->pop(lista, indice);
                  if(pEmpleado!=NULL)
                   {
                     if(!lista2->add(lista2, pEmpleado))
                       {
                          printf("\n Cambio de lista exitoso!");
                          system("PAUSE");

                       }
                        else{
                           printf("\n No se pudo hacer cambio de lista");
                           system("PAUSE");
                          }
                 }
           }
            else{
                printf("\n Alguna de las listas todavia no fue creada");
                system("PAUSE");
              }
            break;
        case 16:
            printf("\n Confirma que desea salir?");
            confirma = getche();
            if(confirma=='s' || confirma=='S')
              {
                lista->deleteArrayList(lista);
                printf("\n Memoria liberada. Se puede ir.");
                system("PAUSE");
                seguir='n';
              }
              else{
                printf("\n Salida cancelada!");
                system("PAUSE");
            }

            break;

        }

    }while(seguir =='s');

    return 0;
}


int menu()
{
    int opcion;
    system("cls");
      printf("Menu de Opciones\n\n");
      printf("1. Parse del archivo data.csv\n");
      printf("2. Crear archivo binario\n");
      printf("3. Cargar Array desde el archivo binario\n");
      printf("4. Listar Empleados\n");
      printf("5. Ordenar por nombre\n");
      printf("6. Agregar un empleado\n");
      printf("7. Insertar empleado en Indice\n");
      printf("8. Eliminar un empleado\n");
      printf("9. Listar Empleados (Desde/Hasta)\n");
      printf("10. Clonar toda la lista de empleados\n");
      printf("11. Mostrar lista clonada\n");
      printf("12. Crear sublista de empleados\n");
      printf("13. Mostrar Sublista\n");
      printf("14. Limpiar lista de empleados\n");
      printf("15. Pasar un empleado de la lista 1 a la lista clonada\n");
      printf("16. Salir\n");
      printf("Ingrese opcion: ");
      scanf("%d", &opcion);

      return opcion;
}






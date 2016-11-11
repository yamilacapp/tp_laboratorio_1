#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"
#include "Validaciones.h"

int menu();

int main()
{
    char seguir = 's';
    char confirma;
    int i;
    Employee* pEmpleado;
    ArrayList* lista;
    lista = al_newArrayList();
    FILE* pFile;
    int indice;
    int indice2;
    Employee* nuevoEmpleado;

    do
    {
        switch(menu())
        {
        case 1:
            pFile = fopen("data.csv", "r");
            if(pFile == NULL)
            {
             printf("No se pudo abrir el archivo\n");
             exit(1);
            }

            if(parserEmployee(pFile, lista))
                printf("Parseo exitoso\n\n");
            else
                 printf("Problema al Parsear\n\n");

            system("pause");
            break;
        case 2:


            for(i=0; i< lista->len(lista); i++)
            {
                pEmpleado =(Employee*) lista->get(lista, i);
                if(pEmpleado->isEmpty == 0)
                employee_print(pEmpleado);

                if(!(i%50))
                {
                    system("pause");
                }
            }


            break;
        case 3:
            lista->sort(lista, employee_compare, 1);
            break;

        case 4:

            nuevoEmpleado = employee_new();

            system("cls");
            printf("Agregar un Empleado\n\n");
            printf("Ingrese id:");
            scanf("%d", &nuevoEmpleado->id);
            printf("Ingrese nombre:");
            fflush(stdin);
            gets(nuevoEmpleado->name);
            printf("Ingrese apellido:");
            fflush(stdin);
            gets(nuevoEmpleado->lastName);
            nuevoEmpleado->isEmpty = 0;

            lista->add(lista, nuevoEmpleado);

            printf("\n\nEmpleado agregado con exito\n\n");



            break;
        case 5:
              printf("Ingrese indice: ");
            scanf("%d", &indice);
            pEmpleado =(Employee*) lista->get(lista, indice);
            employee_print(pEmpleado);
            printf("\nConfirma borrado?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's' || confirma == 'S')
            {
                pEmpleado->isEmpty = 1;
                 printf("\nBorrado exitoso\n");
            }
            else
            {
                printf("\nOperacion cancelada\n");
            }
            system("pause");
            break;
        case 6:
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
                if(pEmpleado->isEmpty==0)
                    {
                    employee_print(pEmpleado);
                    fflush(stdin);
                   }
                 if(!(i%50))
                   {
                    system("pause");
                   }
            }

            break;
        case 7:
            seguir='n';
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
      printf("2. Listar Empleados\n");
      printf("3. Ordenar por nombre\n");
      printf("4. Agregar un elemento\n");
      printf("5. Elimina un elemento\n");
      printf("6. Listar Empleados (Desde/Hasta)\n");
      printf("7. Salir\n");
      printf("Ingrese opcion: ");
      scanf("%d", &opcion);

      return opcion;
}






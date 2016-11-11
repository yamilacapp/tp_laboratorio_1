
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    int todoOk =0;
     Employee* unEmpleado;

     char buffer[4][50];

     fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

         unEmpleado = employee_new();

         unEmpleado->id = atoi(buffer[0]);
         strcpy(unEmpleado->name, buffer[1]);
         strcpy(unEmpleado->lastName, buffer[2]);
         if(strcmp(buffer[3], "true")==0)
           {
             unEmpleado->isEmpty = 1;
           }
         else
           {
             unEmpleado->isEmpty = 0;
           }

           pArrayListEmployee->add(pArrayListEmployee, unEmpleado);

          // employee_print(unEmpleado);
    }
    todoOk = 1;

    return todoOk;
}

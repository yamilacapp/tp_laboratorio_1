
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{int todoOk =0;
Employee* unEmpleado;
int i=0;
int id;

char buffer[4][50];
if(pFile!=NULL && pArrayListEmployee!=NULL)
  {


       fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

       while(!feof(pFile))
         {
           fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

            unEmpleado = employee_new();

            id = atoi(buffer[0]);

            if(IsId(pArrayListEmployee, id)==1)
             {
                id=pArrayListEmployee->size+1;
             }

           unEmpleado->id=id;
           strcpy(unEmpleado->name, buffer[1]);
           strcpy(unEmpleado->lastName, buffer[2]);
           printf("\n Leyendo archivo...%d", i);
           printf("\n Reservedsize: %d", pArrayListEmployee->reservedSize);
           printf("\n Size: %d", pArrayListEmployee->size);
           system("PAUSE");
            i++;
           pArrayListEmployee->add(pArrayListEmployee, unEmpleado);


          // employee_print(unEmpleado);
         }
    todoOk = 1;
   }

    return todoOk;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    Employee* empleadoA = (Employee*)pEmployeeA;
    Employee* empleadoB = (Employee*)pEmployeeB;

    return strcmp(empleadoA->name, empleadoB->name);

    //return strcmp(((Employee*)pEmployeeA)->name, ((Employee*)pEmployeeB)->name);
}


void employee_print(Employee* this)
{
      printf("Id: %d  Nombre: %s %s\n", this->id, this->name, this->lastName);
}


Employee* employee_new(void)
{

    Employee* returnAux = (Employee*)malloc(sizeof(Employee));

    return returnAux;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}




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


void employee_print(Employee* this, int indice)
{
      printf("Indice: %d  Id: %d  Nombre: %s %s\n",indice, this->id, this->name, this->lastName);
}


Employee* employee_new(void)
{

    Employee* returnAux = (Employee*)malloc(sizeof(Employee));

    return returnAux;

}

void employee_delete(Employee* this, ArrayList* pList)
{  int indice;
   indice=pList->indexOf(pList, this);
   if(!pList->remove(pList, indice))
   {
       printf("\n Borrado exitoso!");
   }

}

int employee_setId(Employee* this, int id)
{   int retorno=-1;
    if(this!=NULL && id>0 && id<99999999)
    {
        this->id=id;
        retorno=0;
    }

    return retorno;

}
 int employee_setName(Employee* this,char* Name)
 {
     int retorno=-1;
     if(this!=NULL && Name!=NULL && strlen(Name)<50 && strlen(Name)>0)
     {
         strcpy(this->name, Name);
         retorno=0;
     }
     return retorno;
 }

 int employee_setLastName(Employee* this,char* Name)
 {
     int retorno=-1;
     if(this!=NULL && Name!=NULL && strlen(Name)<50 && strlen(Name)>0)
     {
         strcpy(this->lastName, Name);
         retorno=0;
     }
     return retorno;
 }


int employee_getId(Employee* this)
{
int retorno=-1;
   if(this!=NULL)
   {
       retorno=this->id;
   }

return retorno;

}


int IsId(ArrayList* pList, int id)
{
int i;
int returnAux=-1;
Employee* pEmployee;
if(pList!=NULL && id>0 && id<999999999)
   {   returnAux=0;
    for(i=0; i<pList->len(pList); i++)
    {
         pEmployee=(Employee*)pList->get(pList, i);
         if(pEmployee->id==id)
         {
             returnAux=1;
         }

    }
}
    return returnAux;
}

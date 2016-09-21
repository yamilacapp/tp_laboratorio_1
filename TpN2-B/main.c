#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

int main()

{
     int opcion;
    epersona persona[20];

    char seguir='s';
    char confirma;



    inicializarPersona(persona, 20);


    while(seguir=='s')
    {

    opcion=menu();



   switch(opcion)
   {
   case 1:

       altas(persona, 20);

    break;
   case 2:
       borrarPersona(persona, 20);
    break;
   case 3:

ordenarPersonas(persona, 20);
mostrarPersonas(persona, 20);

    break;
   case 4:

graficarpersonas(persona, 20);




    break;
   case 5:
       printf("\nConfirma que desea salir? ");
       confirma=getche();
       confirma=tolower(confirma);
       while(confirma!='s' && confirma!='n')
       {
           printf("Error. Debe ingresar s/n. Reingrese: ");
          confirma=getche();

       }
       if(confirma=='s')
       {
           seguir='n';
       }




    break;
   }
   }
    return 0;
}

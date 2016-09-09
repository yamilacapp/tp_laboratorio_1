#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "menu.h"


int main()
{float num1;
float num2;
char confirma;
char seguir='s';
int opcion;
int flag1=0;
int flag2=0;
int Rinf=1;
int Rsup=9;

    do{

        system("cls");

        opcion=menu(num1, num2, flag1, flag2);



       while(verificar(opcion, Rinf, Rsup)==0)
       {
           printf("ERROR. Debe ingresar una opción del 1 al 9. Reingrese: ");
           scanf("%d", &opcion);
       }
     printf("La opcion elegida es %d", opcion);
   printf("\n\n");
   system("pause");
    switch(opcion)
       {
       case 1:
           printf("Ingrese numero 1: ");
           scanf("%f", &num1);
           flag1=1;
           break;
       case 2:
            printf("Ingrese numero 2: ");
           scanf("%f", &num2);
           flag2=1;
           break;
       case 3:
           if(flag1==1 && flag2==1)
           {

           printf("%.2f", sumar(num1,num2));
            printf("\n\n");
          system("pause");
          }
           else {
            printf("Error. Debe ingresar un operando/operador");
            printf("\n\n");
          system("pause");}
           break;
       case 4:
           if(flag1==1 && flag2==1)
           {
           printf("%.2f", restar(num1,num2));
           printf("\n\n");
           system("pause");
           }
           else {
            printf("Error. Debe ingresar un operando/operador");
             printf("\n\n");
           system("pause");}
           break;
       case 5:
           if(flag1==1 && flag2==1)
           {
          printf("%.2f", multiplicacion(num1,num2));
           printf("\n\n");
          system("pause");
          }
           else {
            printf("Error. Debe ingresar un operando/operador");
             printf("\n\n");
          system("pause");}
           break;
       case 6:
           if(flag1==1 && flag2==1)
           {  if(num2!=0){
          printf("%.2f", division(num1,num2));
           printf("\n\n");
          system("pause");
          }else
          { printf("No se puede dividir por cero");
           printf("\n\n");
          system("pause");
          }}
           else {
            printf("Error. Debe ingresar un operando/operador");
             printf("\n\n");
           system("pause");}
           break;
       case 7:
           if(flag1==1 && flag2==1)
           {
          printf("%.2f", factorial(num1));
          printf("\n%.2f", factorial(num2));

           printf("\n\n");
           system("pause"); }
           else {

            printf("Error. Debe ingresar un operando/operador");
             printf("\n\n");
           system("pause");}
           break;
       case 8:
           if(flag1==1 && flag2==1)
           {
          printf("%.2f", sumar(num1, num2));

          printf("\n%.2f", restar(num1, num2));

          printf("\n%.2f", multiplicacion(num1, num2));
          printf("\n%.2f", division(num1, num2));
          printf("\n%.2f   %.2f", factorial(num1), factorial(num2));
           printf("\n\n");
          system("pause");
          }
           else {
            printf("Error. Debe ingresar un operando/operador");
             printf("\n\n");
         system("pause");}
           break;
       case 9:
           printf("¿Confirma salir?s/n");
           fflush(stdin);
           confirma=getche();
           confirma=tolower(confirma);

           if(confirma=='s')
           {
               seguir='n';

           }
        break;

       } system("cls");
}while(seguir=='s');


    return 0;

}

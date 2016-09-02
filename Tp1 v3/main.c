#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
//float sumar(float num1, float num2);
//float restar(float num1, float num2);
//float multiplicacion(float num1, float num2);
//float division(float num1, float num2);
//float factorial(float num1, float num2);

int main()
{float num1;
float num2;
char confirma;
char seguir='s';
int opcion;
int flag1=0;
int flag2=0;
    do{
        system("cls");
        printf("Menu de opciones: ");
       if(flag1==0)
       {
       printf("\n\n 1.Ingresar 1er operando (A=X)");}
       else{
        printf("\n\n 1.Ingresar 1er operando (A=%.2f)", num1);
       }
       if(flag2==0)
       {
       printf("\n 2.Ingresar 2do operando (B=Y)");}
       else{
        printf("\n 2.Ingresar 2do operando (B=%.2f)", num2);
       }
       printf("\n 3.Calcular la suma (A+B)");
       printf("\n 4.Calcular la resta (A-B)");
       printf("\n 5.Calcular multiplicacion (A*B)");
       printf("\n 6.Calcular division (A/B)");
       printf("\n 7.Calcular el factorial");
       printf("\n 8.Calcular todas las operaciones");
       printf("\n 9.Salir");

       printf("\n\n Ingrese una opcion");
       scanf("%d", &opcion);
       while(opcion<1 || opcion>9)
       {
           printf("ERROR. Debe ingresar una opción del 1 al 9. Reingrese: ");
           scanf("%d", &opcion);
       }



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
           system("pause");
           }
           else {
            printf("Error. Debe ingresar un valor");
           }
           break;
       case 4:
           if(flag1==1 && flag2==1)
           {
           printf("%.2f", restar(num1,num2));
           system("pause");
           }
           else {
            printf("Error. Debe ingresar un valor");
           }
           break;
       case 5:
           if(flag1==1 && flag2==1)
           {
          printf("%.2f", multiplicacion(num1,num2));
          system("pause");
          }
           else {
            printf("Error. Debe ingresar un valor");
           }
           break;
       case 6:
           if(flag1==1 && flag2==1)
           {  if(num2!=0){
          printf("%.2f", division(num1,num2));
          system("pause");
          }else
          { printf("No se puede dividir por cero");
          }}
           else {
            printf("Error. Debe ingresar un valor");
           }
           break;
       case 7:
           if(flag1==1 && flag2==1)
           {
          //printf("%.2f", factorial(num1,num2));
          }
           else {
            printf("Error. Debe ingresar un valor");
           }
           break;
       case 8:
           if(flag1==1 && flag2==1)
           {
          printf("%.2f", sumar(num1, num2));

          printf("\n%.2f", restar(num1, num2));

          printf("\n%.2f", multiplicacion(num1, num2));
          printf("\n%.2f", division(num1, num2));
          system("pause");
          }
           else {
            printf("Error. Debe ingresar un valor");
           }
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

       }
}while(seguir=='s');


    return 0;
}

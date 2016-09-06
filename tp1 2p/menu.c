int menu(float num1, float num2, int flag1, int flag2 )
{
int opcion;
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

       printf("\n\n Ingrese una opcion: ");
       scanf("%d", &opcion);

       return opcion;
}

int verificar(int x)
{
    int rta=1;
    if(x<1 || x>9)
    {
        rta=0;
    }
    return rta;

}
float sumar(float x, float y)
{

    float suma;
    suma= x+y;
    return suma;

}

float restar(float x, float y)
{

    float resta;
resta=x-y;
return resta;



}

float multiplicacion(float x, float y)
{
  float multiplicacion;
  multiplicacion=x*y;
  return multiplicacion;


}
float division(float x, float y)
{
float dividir;
    if(y!=0)
    {


    dividir=x/y;

    }
    else{
        printf("No se puede dividir por cero");
    }
    return dividir;
}

float factorial(int x)
{
    if(x==1)
    {
        return 1;
    }
   return x*factorial(x-1);
}

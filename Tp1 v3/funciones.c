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

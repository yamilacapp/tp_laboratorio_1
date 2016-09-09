/** \brief Valida un rango de entero.
 *
 * \param entero a validar
 * \param limite inferior del rango
 * \param limite superior del rango
 * \return retorna 1 si el entero esta dentro del rango, y 0 si esta fuera de ese rango.
 *
 */
int verificar(int, int, int);

/** \brief muestra la lista de opciones del menú
 *
 * \param flotante que ingreso el usuario(operando)
 * \param flotante que ingreso el usuario(operador)
 * \param entero que cumple la función de bandera del operando
 * \param entero que cumple la funcion de bandera del operador
 * \return retorna el numero de la opcion que ingresó el usuario
 *
 */

int menu(float num1, float num2, int flag1, int flag2);

/** \brief realiza la suma entre los numeros ingresados por el usuario
 *
 * \param numero operando ingresado por el usuario
 * \param numero operador ingresado por el usuario
 * \return retorna el resultado de la suma
 *
 */
float sumar(float x, float y);
/** \brief realiza la resta entre los numeros ingresados por el usuario
 *
 * \param numero operando ingresado por el usuario
 * \param numero operador ingresado por el usuario
 * \return retorna el resultado de la resta
 *
 */

float restar(float x, float y);
/** \brief realiza la multiplicacion entre los numeros ingresados por el usuario
 *
 * \param numero operando ingresado por el usuario
 * \param numero operador ingresado por el usuario
 * \return retorna el resultado de la multiplicacion
 *
 */

float multiplicacion(float x, float y);
/** \brief realiza la division entre los numeros ingresados por el usuario
 *
 * \param numero operando ingresado por el usuario
 * \param numero operador ingresado por el usuario
 * \return retorna el resultado de la division
 *
 */
float division(float x, float y);
/** \brief Calcula el factorial del numero ingresado por el usuario
 *
 * \param numero ingresado por el usuario
 * \return retorna el resultado de la operacion factorial
 *
 */
float factorial(int x);

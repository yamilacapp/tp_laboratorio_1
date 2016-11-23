
#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
struct
{
    int id;
    char name[51];
    char lastName[51];

}typedef Employee;

/** \brief Compara dos elementos
 *
 * \param puntero a elemento void
 * \param puntero a elemento void
 * \return retorna 1 si pEmployeeA es mayor que pEmployeeB, 0 si son iguales y -1 si pEmployeeA es menor que pEmployeeB
 *
 */

int employee_compare(void* pEmployeeA,void* pEmployeeB);
/** \brief Muestra un elemento en el indice indicado
 *
 * \param puntero a elemento void
 * \param indice del elemento
 * \return void
 *
 */

void employee_print(Employee* this, int indice);
/** \brief crea espacio para un elemento Employee
 *
 * \param void

 * \return el puntero al elemento Employee creado
 *
 */

Employee* employee_new(void);
/** \brief Elimina un elemento del ArrayList
 *
 * \param puntero a elemento Employee
 * \param puntero a ArrayList
 * \return void
 *
 */

void employee_delete(Employee* this,ArrayList* pList );
/** \brief ingresa el valor de id en el campo id del elemento Employee
 * \param puntero a Employee
 * \param id
 * \return retorna -1 si hay error o 0 si esta bien
 *
 */

int employee_setId(Employee* this, int id);
/** \brief Consigue el id de un elemento Employee
 *
 * \param puntero a elemento Employee
 * \param
 * \return retorna -1 si hay error o el valor de id si esta bien
 *
 */

int employee_getId(Employee* this);
/** \brief Ingresa el nombre que se le pasa por parametro en el campo nombre de una estructura Employee
 *
 * \param pùntero a estructura Employee
 * \param nombre o cadena a ingresar
 * \return retorna -1 si hay error o 0 si esta bien
 *
 */

int employee_setName(Employee* this,char* Name);
/** \brief revisa si en el ArrayList ya hay ingresado un valor de id que se pasa como parametro
 *
 * \param puntero a ArrayList
 * \param id
 * \return retorna -1 si hay error, 0 si no esta y 1 si el is ya esta ingresado
 *
 */

int IsId(ArrayList* pList, int id);
/** \brief Ingresa el nombre que se le pasa por parametro en el campo lastName de una estructura Employee
 *
 * \param pùntero a estructura Employee
 * \param nombre o cadena a ingresar
 * \return retorna -1 si hay error o 0 si esta bien
 *
 */
int employee_setLastName(Employee* this,char* Name);
#endif // _EMPLOYEE_H


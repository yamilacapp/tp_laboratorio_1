#ifndef __ARRAYLIST
#define __ARRAYLIST
struct ArrayList{
    int size;
    void **pElements;
    int reservedSize;

    int     (*add)();
    int     (*len)();
    int     (*contains)();
    int     (*set)();
    int     (*remove)();
    int     (*clear)();
    int     (*push)();
    int     (*indexOf)();
    int     (*isEmpty)();
    void*   (*get)();
    void*   (*pop)();
    int     (*containsAll)();
    int     (*sort)();
    struct ArrayList* (* clone)();
    struct ArrayList* (*subList)();
    int     (*deleteArrayList)();

}typedef ArrayList;
#endif


/** \brief Genera un nuevo arrayList con AL_INITIAL_VALUE elementos.
 * \param void
 * \return Retorna NULL si no hay memoria, o retorna el puntero a ArrayList creado.
 *
 */
ArrayList* al_newArrayList(void);


/** \brief  Agrega un elemento al arrayList, y lo agranda de ser necesario.
 *
 * \param puntero a ArrayList (pList)
 * \param puntero a un elemento void (pElement)
 * \return Retorna -1 si hay error, o 0 si no hay error.
 *
 */
int al_add(ArrayList* pList,void* pElement);


/** \brief  Elimina el ArraiList
 * \param puntero a ArrayList (pList)
 * \return retorna -1 si hay error o 0 si no hay error.
 *
 */
int al_deleteArrayList(ArrayList* pList);


/** \brief  Determina el tamaño del ArrayList (size)
 * \param puntero a ArrayList (pList)
 * \return retorna tamaño del ArrayList o -1 si hay error.
 *
 */
int al_len(ArrayList* pList);


/** \brief  Consigue un elemento del ArrayList
 * \param puntero a ArrayList (pList)
 * \param indice del elemento a determinar (int)
 * \return retorna NULL si hay error o devuelve el puntero a elemento void del indice
  */
void* al_get(ArrayList* pList , int index);


/** \brief  Revisa si el ArrayList contiene al menos un elemento pasado por parametro(pELement)
 * \param puntero a ArrayList (pList)
 * \param puntero a elemento de tipo void (pElement)
 * \return retorna (-1)si hay error
 *                  - ( 0) si no esta el elemento
 *                  - ( 1)si contiene el elemento
 *
 */
int al_contains(ArrayList* pList, void* pElement);


/** \brief ubica un elemento en el indice pasado como parametro
 * \param puntero a ArrayList (pList)
 * \param indice del elemento
 * \param puntero a elemento void
 * \return retorna (-1) si hay error
 *                  - ( 0) si esta bien
 *
 */
int al_set(ArrayList* pList, int index,void* pElement);


/** \brief  Elimina un elemento del ArrayList y reubica los otros
 * \param puntero a ArrayList (pLis)
 * \param indice del elemento a remover
 * \return retorna(-1) si hay error
 *                  - ( 0) si esta bien
 */
int al_remove(ArrayList* pList,int index);



/** \brief Elimina todos los elementos del ArraList
 * \param puntero a ArrayList (pList)
 * \return retorna (-1) si hay error
 *                  - ( 0) si esta bien
 */
int al_clear(ArrayList* pList);


/** \brief returna un puntero a ArrayList que contiene los mismos elementos del ArrayList pasado como parametro
 * \param puntero a ArrayList (pList)
 * \return retorna (NULL) si hay error
 *                 -Nuevo puntero ArrayList
 */
ArrayList* al_clone(ArrayList* pList);


/** \brief inserta un elemento en la posicion indicada
 * \param puntero a ArrayList (pList)
 * \param indice del elemento
 * \param puntero a elemento void que se va a insertar
 * \return retorna (-1) si hay error
 *                  - ( 0) si esta bien
 */
int al_push(ArrayList* pList, int index, void* pElement);



/** \brief retorna el indice del elemento que se le pasa como parametro
 * \param puntero a ArrayList (pList)
 * \param puntero a elemento void
 * \return retorna (-1) si hay error - o indice del elemento
 */
int al_indexOf(ArrayList* pList, void* pElement);



/** \brief Se fija si el ArraList esta vacio
 * \param puntero a ArrayList (pList)
 * \return retorna(-1) si hay error o (0) si no esta vacio- (1) si esta vacio
 */
int al_isEmpty(ArrayList* pList);



/** \brief elimina un elemento en la posicion indicada y lo retorna
 * \param puntero a ArrayList
 * \param indice del elemento a remover
 * \return retorna (NULL) si hay error o
 *                 - puntero al elemento eliminado
 */
void* al_pop(ArrayList* pList,int index);



/** \brief Crea un nuevo ArrayList que contiene solo una parte del ArrayList pasado por parametro
 * \param puntero a ArrayList (pList)
 * \param indice inicial (from)
 * \param indice final (to)
 * \return returna (NULL) si hay error o
 *                  - puntero al nuevo ArrayList creado
 */
ArrayList* al_subList(ArrayList* pList,int from,int to);



/** \brief Revisa que pList contenga todos los elementos de pList2
 * \param puntero a ArrayList (pList)
 * \param puntero a ArrayList (pList2)
 * \return retorna (-1) si hay error
 *                  - (0) si no contiene todos- (1)si contiene todos
 */
int al_containsAll(ArrayList* pList,ArrayList* pList2);


/** \brief Ordena los elementos del ArrayList por orden alfabetico
 * \param puntero a ArrayList (pList)
 * \param puntero a la funcion que compara dos elementos (pFunc)
 * \param 1 para indicar ascendente o 0 para indicar descendente
 * \return retorna (-1) si hay error
 *                  - (0) si esta bien
 */
int al_sort(ArrayList* pList, int (*pFunc)(void* ,void*), int order);



/** \brief Aumenta el espacio reservado del ArrayList en AL_INCREMENT elementos.
 * \param puntero a ArrayList (pList)
 * \return retorna (-1) si hay error
 *                  - (0) si esta bien
 */
int resizeUp(ArrayList* pList);


/** \brief  Expande el ArrayList
 * \param puntero a ArrayList
 * \param indice del elemento
 * \return retorna (-1) si hay error
 *                  - ( 0) si esta bien
 */
int expand(ArrayList* pList,int index);


/** \brief Contrae el ArrayList
 * \param puntero a ArrayList
 * \param indice del elemento
 * \return retorna (-1) si hay error
 *                  - ( 0) si esta bien
 */
int contract(ArrayList* pList,int index);


// Private function
int resizeUp(ArrayList* pList);
int expand(ArrayList* pList,int index);
int contract(ArrayList* pList,int index);
//___________________

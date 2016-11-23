/** \brief Crea un archivo binario con los datos del ArrayList
 *
 * \param nombre del Archivo (Path)
 * \param puntero a ArrayList
 * \return retorna -1 si hay error o 1 si esta todo bien
 *
 */

int serializarLista(char* Path, ArrayList* Lista);

/** \brief Carga elementos del Archivo binario al ArrayList
 *
 * \param nombre del Archivo binario
 * \param puntero a ArrayList
 * \return retorna NULL si hay error o puntero a ArrayList cargado
 *
 */

ArrayList* DeserializarLista(char* Path, ArrayList* lista);

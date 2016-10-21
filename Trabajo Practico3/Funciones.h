#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{    int idPelicula;
    char titulo[51];
    char genero[20];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkimagen[150];
    int Estado;
} movie;

/** \brief Busca el primer lugar libre en el array
 *
 * \param array de peliculas de tipo movie
 * \param tamaño del array de tipo int
 * \return retorna el primer indice disponible si lo hay, y si no devuelve -1
 *
 */

int BuscarLibre(movie peliculas[],int TAM);

/** \brief Muestra las opciones del menu del programa
 *
 * \return retorna la opcion ingresada por el usuario
 *
 */

int Menu();

/** \brief Ingresa un elemento nuevo al array de peliculas
 *
 * \param array de peliculas de tipo movie
 * \param tamaño del array de tipo int
 * \param  id del proximo elemento a ingresar
 * \return retorna 1 si la pelicula fue agregada o 0 si no se pudo agregar
 *
 */

int AgregarPelicula(movie peliculas[],int TAM, int id);


/** \brief Inicializa el campo estado del array en cero
 *
 * \param array de peliculas de tipo movie
 * \param tamaño del array de tipo int
 * \return retorna void
 */

void inicializarPelicula(movie peliculas[],int TAM);


/** \brief Busca un indice del array con el campo de estado en cero (libre)
 *
 * \param array de peliculas de tipo movie
 * \param tamaño del array de tipo int
 * \return retorna el indice de la primera posicion del array libre
 *
 */

int BuscarLibre(movie peliculas[],int TAM);


/** \brief Muestra los elementos cargados en el array cuyo campo de estado sea 1.
 *
 * \param array de peliculas de tipo movie
 * \param tamaño del array de tipo int
 * \return retorna void
 */

void MostrarPeliculas(movie peliculas[],int TAM);


/** \brief Busca en el array de peliculas un idpelicula que coincida con el ID ingresado por el usuario
 *
 * \param array de peliculas de tipo movie
 * \param tamaño del array int
 * \param id ingresado por el usuario int
 * \return retorna la posicion en el array con el ID buscado o -1 si no lo encuentra
 *
 */

int BuscarPelicula(movie peliculas[],int TAM,int ID);


/** \brief Borra un elemento del array pasando el estado a 0
 *
 * \param array de peliculas de tipo movie
 * \param tamaño del array int
 * \return retorna void
 *
 */

void BorrarPelicula(movie peliculas[],int TAM);


/** \brief Modifica algun dato del array de peliculas
 *
 * \param array de peliculas de tipo movie
 * \param  tamaño del array de tipo int
 * \return retorna void
 *
 */

void ModificarPelicula(movie peliculas[],int TAM);


/** \brief Genera un archivo de texto con los datos del array
 *
 * \param array de peliculas de tipo movie
 * \param tanaño del array de tipo int
 * \param Nombre del archivo de texto a crear
 * \return retorna void
 *
 */

void GenerarPagina(movie peliculas[],int TAM,char NombreArchivo[]);



#endif // FUNCIONES_H_INCLUDED

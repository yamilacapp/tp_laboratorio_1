
typedef struct
{
    char nombre[20];
    int edad;
    int dni;
    int flag;
}epersona;
int menu();
int validarnombre(char[], int);
void altas(epersona[],int);
int buscarLibre(epersona[], int);
int  buscarPersona(epersona[], int, int);
void inicializarPersona(epersona[], int);
void modificarPersona(epersona[], int);
int menuModificar();
void borrarPersona(epersona[], int);
void ordenarPersonas(epersona[], int);
void mostrarPersonas(epersona[], int);
void mostrarPersona(epersona);
int validaredad(int, int, int);
void graficarpersonas(epersona[], int);


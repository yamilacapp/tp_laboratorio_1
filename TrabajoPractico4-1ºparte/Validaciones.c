#include "ArrayList.h"



int validarIndice(int indice1, int indice2, ArrayList* lista)
{  int valid=0;
    if(indice1>=0 && indice1<lista->len(lista) && indice2>=0 && indice2<lista->len(lista) && indice1<=indice2)
    {
        valid=1;
    }
    return valid;
}

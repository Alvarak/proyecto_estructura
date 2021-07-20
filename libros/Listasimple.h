#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED
#include"Nodo.h"

typedef nodo *listasimple;

listasimple Crear_listasimple();

void Insertanodo_listasimple(listasimple lista,nodo *nuevo);

void Eliminar_listasimple(listasimple lista);


#endif // LISTASIMPLE_H_INCLUDED

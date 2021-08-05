#ifndef TDA_PILA_H_INCLUDED
#define TDA_PILA_H_INCLUDED
#include "Listasimple.h"
typedef listasimple pila_tda;

typedef listaautores pila_autores;

void elimina_pila(pila_tda p);

void push (nodo*n ,pila_tda p);

nodo *pop(pila_tda p);

nodo *top (pila_tda p);
#endif // TDA_PILA_H_INCLUDED

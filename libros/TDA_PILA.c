#include <stdio.h>
#include "TDA_PILA.h"

void elimina_pila(pila_tda p){

    Eliminar_listasimple(p);
}

void push (nodo*n ,pila_tda p){
    Insertarnodo_listasimple(p, n);
}

nodo *pop(pila_tda p){
    nodo *nodo_sgte=Crearnodo();
  pila_tda temporal=NULL;

  if(p==NULL){
    printf("LA PILA ESTA VACIA");
    return NULL;
  }

  if(p!=NULL)
  {
    if(p->siguiente==NULL){
        nodo_sgte=p;
        p=NULL;
        return nodo_sgte;
    }
    temporal=p;
    while (temporal->siguiente!=NULL)
    {
      nodo_sgte = temporal->siguiente;
      if(nodo_sgte->siguiente==NULL){
        temporal->siguiente=NULL;
        break;
        }
      temporal=nodo_sgte;
    }
    ///devolver el nodo

    return nodo_sgte;
  }
}

nodo *top (pila_tda p){
  if(p==NULL){
    printf("LA PILA ESTA VACIA");
    return NULL;
  }
     if(p!=NULL)
 {
  nodo *ultimo_nodo=Crearnodo();
  ultimo_nodo=pop(p);

  push(ultimo_nodo, p);
  return ultimo_nodo;
 }
}

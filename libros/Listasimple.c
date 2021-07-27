#include "Listasimple.h"
#include<stdlib.h>

listasimple Crear_listasimple()
{
  listasimple L=NULL;
  if (L==NULL)
  {
    L=Crearnodo();
  }
  if(L!=NULL)
    L->siguiente=NULL;
  return L;
}

void Eliminar_listasimple(listasimple L)

{
  nodo *nodo_sgte=NULL;
  if(L!=NULL)
  {
    while (L->siguiente!=NULL)
    {
      nodo_sgte = L->siguiente;
      L->siguiente=NULL;
      eliminarnodo(L);
      L=nodo_sgte;
    }
    eliminarnodo(L);
  }

}

void Insertarnodo_listasimple (listasimple L, nodo *nuevo)
{
    nodo *nodo_actual=NULL;
  int contador=0;
  if(L!=NULL && nuevo!=NULL)
  {
    nodo_actual=(nodo *)L;
    while(nodo_actual->siguiente !=NULL)
    {
      contador++;
      nodo_actual=nodo_actual->siguiente;
    }

    if(contador==0 && nodo_actual->ptrlibro==NULL)//Primer elemento de la lista
    {
        L=nuevo;
      //L->libro=nuevo->libro;
      //L->siguiente=nuevo->siguiente;

    }
    else
    {
    nodo_actual->siguiente=nuevo;
    nuevo->siguiente=NULL;
    }

  /*nodo *nodo_actual=NULL;
  if(L!=NULL && nuevo!=NULL)
  {
    nodo_actual=L;
    while(nodo_actual->siguiente !=NULL)
    {
      nodo_actual=nodo_actual->siguiente;
    }
    nodo_actual->siguiente=nuevo;
    nuevo->siguiente=NULL;

  }*/

}
}

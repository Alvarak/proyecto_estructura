#include"Nodo.h"
#include<stdlib.h>

nodo * Crearnodo(){
    nodo*nuevo;
    nuevo= (nodo*)malloc(sizeof(nodo));
    nuevo->libro=NULL;
    nuevo->siguiente=NULL;
    return nuevo;
}

void eliminarnodo(nodo*n){
    if(n!=NULL){
        free(n);
    }
}

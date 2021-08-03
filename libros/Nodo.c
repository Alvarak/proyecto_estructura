#include"Nodo.h"
#include<stdlib.h>

nodo * Crearnodo(){
    nodo*nuevo;
    nuevo= (nodo*)malloc(sizeof(nodo));
    nuevo->ptrlibro=NULL;
    nuevo->siguiente=NULL;
    nuevo->libro.nodos_autores=(autores*)malloc(sizeof(autores));
    return nuevo;
}

void eliminarnodo(nodo*n){
    if(n!=NULL){
        free(n);
    }
}

autores * Crearautores(autores *char_autores){
    char_autores= (autores*)malloc(sizeof(autores));
    char_autores->siguiente=NULL;
    return char_autores;
}

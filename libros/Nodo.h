#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
struct Libro{
    char ISBN[20];
    char titulo[50];
    char edicion[20];
    char idioma[20];
    char year[4];
    char editorial[30];

};
struct nodo_tda{
    struct Libro libro;
    struct Libro *ptrlibro;
    struct nodo_tda*siguiente;
};

typedef struct nodo_tda nodo;

nodo* Crearnodo();

void eliminarnodo(nodo*n);


#endif // NODO_H_INCLUDED

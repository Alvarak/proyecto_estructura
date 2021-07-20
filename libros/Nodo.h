#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
struct Libro{
    char ISBN;
    char titulo;
    char edicion;
    char idioma;
    char year;
    char editorial;
    char autores;
};
struct nodo_tda{
    struct Libro *libro;
    struct nodo_tda*siguiente;
};

typedef struct nodo_tda nodo;

nodo* Crearnodo();

void eliminarnodo(nodo*n);


#endif // NODO_H_INCLUDED

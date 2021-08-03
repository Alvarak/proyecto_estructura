#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
struct Libro{
    char ISBN[20];
    char titulo[50];
    char edicion[20];
    char idioma[20];
    char year[20];
    char editorial[30];
    struct autores nodos_autores;
};
struct nodo_tda{
    struct Libro libro;
    struct Libro *ptrlibro;
    struct nodo_tda*siguiente;
};
struct nodo_tda_autores{
    char autor[50];
    struct nodo_tda_autores*siguiente;
};

typedef struct nodo_tda nodo;

typedef struct nodo_tda_autores autores;

nodo* Crearnodo();

void eliminarnodo(nodo*n);

autores * Crearautores();

#endif // NODO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include"TDA_PILA.h"
#include<string.h>

int main()
{
  pila_tda tienda=NULL;
  tienda=Crear_listasimple();
  menu(tienda);
  return 0;
}

void menu(pila_tda p)
{

  do{

    printf("Tienda de Libros\n\n");
    verificaciones(p);
    char opcion_menu;
    printf("---Menu--- \n\nSeleccione una opcion\n");
    printf("1: Agregar libro\n");
    printf("2: ------------\n");
    printf("3: Salir\n");
    printf("Su opcion es: ");
    scanf("%s",&opcion_menu);
    if(opcion_menu=='1'){
      agregar_libro(p);
      break;
    }
    else if(opcion_menu=='2'){
      break;
    }
    else if(opcion_menu=='3'){
      printf("Escogio salir\n");
      break;
    }
    else
    {
      printf("Opcion invalida\n\n");
      system("cls");
    }
  }while(1);
  printf("saliendo del menu\n");
}

void agregar_libro(pila_tda p){
printf("Ingrese los datos del libro\n\n");
nodo *nodonuevo;
nodonuevo=Crearnodo();
nodonuevo->ptrlibro=&nodonuevo->libro;
puts("ISBN:");
scanf("%s",nodonuevo->libro.ISBN);
puts("Titulo:");
scanf("%s",nodonuevo->libro.titulo);
puts("Edicion:");
scanf("%s",nodonuevo->libro.edicion);
puts("Idioma:");
scanf("%s",nodonuevo->libro.idioma);
puts("Year:");
scanf("%s",nodonuevo->libro.year);
puts("Editorial:");
scanf("%s",nodonuevo->libro.editorial);
push(nodonuevo,p);
menu(p);
}
void imprimir_libro(nodo *n){
printf("%s\n",n->libro.ISBN);
}

void verificaciones(pila_tda p){
pila_tda temp;
temp=p;
if(p->ptrlibro==NULL){
    printf("No hay libros en este momento\n\n");
}else{
    while(temp->ptrlibro!=NULL){
        imprimir_libro(temp);
    }
temp=temp->siguiente;
}
}

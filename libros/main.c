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
  verificaciones(p);
  do{

  printf("Tienda de Libros\n\n");



    char opcion_menu;
    printf("Menu. Seleccione una opcion\n");
    printf("1: Agregar libro\n");
    printf("2: ");
    printf("3: Salir\n");
    printf("Su opcion es: ");
    scanf("%s",&opcion_menu);
    if(opcion_menu=='1'){
      agregar_libro();
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

void agregar_libro(){
printf("Ingrese los datos del libro\n\n");
nodo *nodonuevo;
nodonuevo=Crearnodo();
puts("ISBN:");
scanf("%s",nodonuevo->libro.ISBN);
imprimir_libro(nodonuevo);


}
void imprimir_libro(nodo *n){
printf("%s\n",n->libro.ISBN);
}

void verificaciones(pila_tda p){
if(p->ptrlibro==NULL){
    printf("No hay libros en este momento\n\n");
}
}

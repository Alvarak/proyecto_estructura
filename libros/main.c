#include <stdio.h>
#include <stdlib.h>
#include"TDA_PILA.h"
#include<string.h>

int main()
{
  menu();
  return 0;
}

void menu()
{
  do{
    char opcion_menu;
    printf("Menu. Seleccione una opcion\n");
    printf("1: Agregar estanteria\n");
    printf("2: Agregar libro\n");
    printf("3: Salir\n");
    printf("Su opcion es: ");
    scanf("%s",&opcion_menu);
    if(opcion_menu=='1'){
      agregar_estanteria();
      break;
    }
    else if(opcion_menu=='2'){
      agregar_libro();
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

void agregar_estanteria(){

}

void agregar_libro(){

}

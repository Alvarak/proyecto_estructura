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
  system("cls");
  do{

    printf("Tienda de Libros\n\n");
    verificaciones(p);
    int opcion_menu;
    printf("---Menu--- \n\nSeleccione una opcion\n");
    printf("1: Agregar libro\n");
    printf("2: ------------\n");
    printf("3: Salir\n");
    printf("Su opcion es: ");
    scanf("%d",&opcion_menu);
    if(len(opcion_menu)>1){
        printf("Ingrese una opcion valida\n")
        system("pause");
        break;
    }
    else if(opcion_menu== 1){
      agregar_libro(p);
      break;
    }
    else if(opcion_menu== 2){
      break;
    }
    else if(opcion_menu== 3){
      printf("Escogio salir\n");
      break;
    }
    else
    {
      printf("Opcion invalida\n\n");
      system("pause");
      system("cls");
    }
  }while(1);
  printf("saliendo del menu\n");
}

void agregar_libro(pila_tda p){
printf("Ingrese los datos del libro\n");
nodo *nodonuevo;
nodonuevo=Crearnodo();
nodonuevo->ptrlibro=&nodonuevo->libro;
printf("ISBN: ");
fgets(nodonuevo->libro.ISBN,10,stdin);
printf("Titulo: ");
fgets(nodonuevo->libro.ISBN,50,stdin);
printf("Edicion: ");
gets(nodonuevo->libro.edicion);
printf("Idioma: ");
gets(nodonuevo->libro.idioma);
printf("Year: ");
gets(nodonuevo->libro.year);
printf("Editorial: ");
gets(nodonuevo->libro.editorial);
printf("%s   %s   %s   %s   %s   %s\n",nodonuevo->libro.ISBN,nodonuevo->libro.titulo,nodonuevo->libro.edicion,nodonuevo->libro.idioma,nodonuevo->libro.year,nodonuevo->libro.editorial);
system("pause");
push(nodonuevo,p);
system("pause");
menu(p);
}
void imprimir_libro(nodo *n){
printf("%s   %s   %s   %s   %s   %s\n",n->libro.ISBN,n->libro.titulo,n->libro.edicion,n->libro.idioma,n->libro.year,n->libro.editorial);
/*printf("%s\n",n->libro.titulo);
printf("%s\n",n->libro.edicion);
printf("%s\n",n->libro.idioma);
printf("%s\n",n->libro.year);
printf("%s\n",n->libro.editorial);*/
}

void verificaciones(pila_tda p){
int cont=0;
pila_tda temp;
temp=p;
if(p->ptrlibro==NULL){
    printf("No hay libros en este momento\n\n");
}else{
    do{
        imprimir_libro(temp);
        temp=temp->siguiente;
    }while(temp!=NULL);
}
}

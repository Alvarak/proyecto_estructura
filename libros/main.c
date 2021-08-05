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
  int opcion_menu;
  char temp[10];
  do{

    printf("Tienda de Libros\n\n");
    verificaciones(p);
    printf("---Menu--- \n\nSeleccione una opcion\n");
    printf("1: Agregar libro\n");
    printf("2: ------------\n");
    printf("3: Salir\n");
    printf("Su opcion es: ");
    fflush(stdin);
    fgets(temp,10,stdin);
    opcion_menu=atoi(temp);
    if(opcion_menu==1){
      agregar_libro(p);
      break;
    }
    else if(opcion_menu==2){
      break;
    }
    else if(opcion_menu==3){
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
system("cls");
printf("Ingrese los datos del libro\n");
nodo *nodonuevo;
nodonuevo=Crearnodo();
nodonuevo->ptrlibro=&nodonuevo->libro;
printf("ISBN(Ingrese 9 digitos): ");
comprobrar_tamano_string(nodonuevo->libro.ISBN,20,9,1);
printf("Titulo: ");
comprobrar_tamano_string(nodonuevo->libro.titulo,60,50,2);
printf("Edicion: ");
comprobrar_tamano_string(nodonuevo->libro.edicion,30,20,3);
printf("Idioma: ");
comprobrar_tamano_string(nodonuevo->libro.idioma,30,50,4);
printf("Year: ");
comprobrar_tamano_string(nodonuevo->libro.year,10,4,5);
printf("Editorial: ");
comprobrar_tamano_string(nodonuevo->libro.editorial,40,30,6);
nodonuevo->libro.nodos_autores=Crearautores();
printf("Ingrese autor o autores:");
agregar_autores(nodonuevo->libro.nodos_autores);
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
void comprobrar_tamano_string(char *cadena, int espacio,int max,int tipomensaje){
    int verificado=0;
    do{
    tipomensaje=tipomensaje;
    fflush(stdin);
    fgets(cadena,espacio,stdin);
    strtok(cadena,"\n");
    int tamano=strlen(cadena);
    switch(tipomensaje){
    case 1:
        if(tamano!=max){
            printf("Error El ISBN debe tener %d digitos\nIntente de nuevo: ",max-1);
            break;

        }else{
            verificado=1;
            break;
        }
    case 2:
        if(tamano>max){
            printf("Error El Titulo debe tener menos de %d caracteres\nIntente de nuevo: ",max-1);
            break;
        }else{
            verificado=1;
            break;
        }
    case 3:
        if(tamano>max){
            printf("Error La Edicion debe tener menos de %d caracteres\nIntente de nuevo: ",max-1);
            break;

        }else{
            verificado=1;
            break;
        }
    case 4:
        if(tamano>max){
            printf("Error El Idioma debe tener menos de %d caracteres\nIntente de nuevo: ",max-1);
            break;

        }else{
            verificado=1;
            break;
        }
    case 5:
        if(tamano>max){
            printf("Error El Year debe tener menos de %d caracteres\nIntente de nuevo: ",max-1);
            break;

        }else{
            verificado=1;
            break;
        }
    case 6:
        if(tamano>max){
            printf("Error La Editorial debe tener menos de %d caracteres\nIntente de nuevo: ",max-1);
            break;

        }else{
            verificado=1;
            break;
        }
    }
    }while(verificado!=1);
}
void agregar_autores(autores *pa){
    char resp=NULL;
    int veri_resp=0;
    do{
        autores *autor_actual=Crearautores;
        printf("Ingrese Autor: ");
        fflush(stdin);
        fgets(autor_actual->autor,60,stdin);
        strtok(autor_actual->autor,"\n");
        pa->autor=autor_actual->autor;
        printf("Desea ingresar otro autor (y/n)");
        scanf("%c",&resp);
        do{
            if(resp=='y'){
                break;
            }else if(resp=='n'){
                break;
                veri_resp=1;
            }else{
                printf("Respuesta no valida");
                system("pause");
            }
        }while(1);
    }while(veri_resp!=1);


}

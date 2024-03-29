#include <stdio.h>
#include <stdlib.h>
#include"TDA_PILA.h"
#include<string.h>

int main()
{

  pila_tda tienda=NULL;
  tienda=Crear_listasimple();
  menu(tienda);
}


void menu(pila_tda p)
{
  system("cls");
  int opcion_menu;
  char temp[10];
  do{

    printf("Tienda de Libros\n\n");
    printf("---Menu--- \n\nSeleccione una opcion\n");
    printf("1: Agregar libro\n");
    printf("2: Buscar libro por ISBN\n");
    printf("3: Buscar libros por Titulo\n");
    printf("4: Buscar libros por Autor\n");
    printf("5: Mostrar libros\n");
    printf("6: Salir\n");
    printf("Su opcion es: ");
    fflush(stdin);
    fgets(temp,10,stdin);
    opcion_menu=atoi(temp);
    if(opcion_menu==1){
      agregar_libro(p);
      break;
    }
    else if(opcion_menu==2){
      buscar_isbn(p);
      break;
    }
    else if(opcion_menu==3){
      buscar_titulo(p);
      break;
    }
    else if(opcion_menu==4){
      buscar_autor(p);
      break;
    }
    else if(opcion_menu==5){
      verificaciones(p);
      break;
    }else if(opcion_menu==6){
        printf("saliendo del menu\n");
        return 0;
    }
    else
    {
      printf("Opcion invalida\n\n");
      system("pause");
      system("cls");
    }
  }while(1);
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
nodonuevo->libro.autores = Crearautor();
printf("Ingrese autor o autores\n");
agregar_autores(nodonuevo->libro.autores);
push(nodonuevo,p);
system("pause");
menu(p);
}
void imprimir_libro(nodo *n){
nodoautor *tempautores;
tempautores=n->libro.autores;
printf("-ISBN: %s\n",n->libro.ISBN);
printf("-Titulo: %s\n",n->libro.titulo);
printf("-Edicion: %s\n",n->libro.edicion);
printf("-Idioma: %s\n",n->libro.idioma);
printf("-Year: %s\n",n->libro.year);
printf("-Editorial: %s\n",n->libro.editorial);
printf("-Autores:\n");
printf("    Nombres y Apellidos:\n");
do{
if(tempautores->siguiente==NULL){
    printf("    %s\n\n",tempautores->autor);
    break;
}else{
    printf("    %s\n",tempautores->autor);
    tempautores=tempautores->siguiente;
}
}while(tempautores!=NULL);
/*printf("%s\n",n->libro.titulo);
printf("%s\n",n->libro.edicion);
printf("%s\n",n->libro.idioma);
printf("%s\n",n->libro.year);
printf("%s\n",n->libro.editorial);*/
}

void verificaciones(pila_tda p){
pila_tda temp;
temp=p;
if(p->ptrlibro==NULL){
    system("cls");
    printf("No hay libros en este momento\n\n");
    system("pause");
}else{
    system("cls");
    do{
        imprimir_libro(temp);
        temp=temp->siguiente;
    }while(temp!=NULL);
    printf("\n");
    system("pause");

}
menu(p);
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
            printf("Error El ISBN debe tener %d digitos\nIntente de nuevo: ",max);
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
void agregar_autores(nodoautor *autores){
    char resp=NULL;
    int veri_resp=0;
    int contador=0;
    nodoautor *autor_actual=NULL;
    printf("Ingrese Autor: ");
    fflush(stdin);
    fgets(autores->autor,60,stdin);
    strtok(autores->autor,"\n");
    while(veri_resp!=1){
    do{
        printf("Desea ingresar otro autor (y/n): ");
        scanf("%c",&resp);
        if(resp=='y'){
            nodoautor *nuevoautor=Crearautor();
            autor_actual=(nodoautor*)autores;
            printf("Ingrese Autor: ");
            fflush(stdin);
            fgets(nuevoautor->autor,60,stdin);
            strtok(nuevoautor->autor,"\n");
            while(autor_actual->siguiente !=NULL){
                contador++;
                autor_actual=autor_actual->siguiente;
            }
            if(contador==0 && autor_actual->siguiente==NULL)//Primer elemento de la lista
            {
                autores->siguiente=nuevoautor;
                //L->libro=nuevo->libro;
                //L->siguiente=nuevo->siguiente;

            }else{
                autor_actual->siguiente=nuevoautor;
                nuevoautor->siguiente=NULL;
            }
        }else if(resp=='n'){
            veri_resp=1;
            break;
        }else{
            printf("Respuesta no valida\n");
            fflush(stdin);
            break;
        }

    }while(1);
    }
}
void buscar_isbn(pila_tda p){
system("cls");
int encontro=0;
char ISBN[20];
printf("Ingrese el ISBN del libro: ");
fflush(stdin);
fgets(ISBN,10,stdin);
strtok(ISBN,"\n");
pila_tda temp;
temp=p;
do{
    int iguales=strcmp(ISBN,temp->libro.ISBN);
    if(iguales==0){
        encontro=1;
        imprimir_libro(temp);
    }
    temp=temp->siguiente;
}while(temp!=NULL);
if(encontro==0){
    printf("No se ha encontrado el libro\n");
}
system("pause");
menu(p);
}
void buscar_titulo(pila_tda p){
system("cls");
int encontro=0;
char titulo[50];
printf("Ingrese el Titulo del libro: ");
fflush(stdin);
fgets(titulo,60,stdin);
strtok(titulo,"\n");
pila_tda temp;
temp=p;
do{
    int iguales=strcmpi(titulo,temp->libro.titulo);
    if(iguales==0){
        encontro=1;
        imprimir_libro(temp);
    }
    temp=temp->siguiente;
}while(temp!=NULL);
if(encontro==0){
    printf("No se ha encontrado el libro\n");
}
system("pause");
menu(p);
}

void buscar_autor(pila_tda p){
system("cls");
int encontro=0;
char autor[50];
printf("Ingrese el Autor del libro: ");
fflush(stdin);
fgets(autor,60,stdin);
strtok(autor,"\n");
pila_tda temp;
temp=p;
nodoautor *tempautores;
do{
    tempautores=temp->libro.autores;
    do{
        int iguales=strcmpi(autor,tempautores->autor);
        if(iguales==0){
            encontro=1;
            imprimir_libro(temp);
            break;
        }else{
            tempautores=tempautores->siguiente;
        }
    }while(tempautores!=NULL);
    temp=temp->siguiente;
}while(temp!=NULL);
if(encontro==0){
    printf("No se ha encontrado el libro\n");
}
system("pause");
menu(p);
}

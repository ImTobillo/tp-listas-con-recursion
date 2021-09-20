#include <stdio.h>
#include <stdlib.h>

/// ESTRUCTURAS

typedef struct nodo
{
    int dato;
    struct nodo* sig;
}nodo;


/// FUNCIONES

void inicLista (nodo** lista)
{
    *lista = NULL;
}

nodo* crearNodo (int dato)
{
    nodo* aux = (nodo*)malloc(sizeof(nodo));
    aux->dato = dato;
    aux->sig = NULL;
    return aux;
}

void agregarNodo (nodo** lista, int dato)
{
    nodo* agreg = crearNodo(dato);

    if (*lista)
    {
        nodo* aux = *lista;

        while (aux->sig)
            aux = aux->sig;

        aux->sig = agreg;
    }
    else
        *lista = agreg;
}

void mostrarLista (nodo* lista)
{
    if (lista)
    {
        printf("%i\t", lista->dato);
        mostrarLista(lista->sig);
    }
}

void mostrarListaInvert (nodo* lista)
{
    if (lista)
    {
        mostrarListaInvert(lista->sig);
        printf("%i\t", lista->dato);
    }
}

int retSumaLista (nodo* lista)
{
    if (lista)
        return lista->dato + retSumaLista(lista->sig);
    else
        return 0;
}

/// MAIN

int main()
{
    nodo* lista;
    inicLista(&lista);

    agregarNodo(&lista, 4);
    agregarNodo(&lista, 6);
    agregarNodo(&lista, 3);
    agregarNodo(&lista, 2);
    agregarNodo(&lista, 7);
    agregarNodo(&lista, 1);

    mostrarLista(lista);
    printf("\n");
    mostrarListaInvert(lista);
    printf("\n");

    printf("\nLa suma de los datos de la lista es: %i\n", retSumaLista(lista));


    return 0;
}

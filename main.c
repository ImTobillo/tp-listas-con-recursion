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
        mostrarListaInvert(lista->sig); // llamada recursiva y acercamiento
        printf("%i\t", lista->dato);
    }
}

int retSumaLista (nodo* lista)
{
    if (lista)
        return lista->dato + retSumaLista(lista->sig); // llamada recursiva y acercamiento
    else  // condicion de corte (lista == null)
        return 0; // solucion trivial
}

void mostrarListaSoloPares (nodo* lista, int contador) // contador inicializado en 1
{
    if (lista)
    {
        if (contador % 2 == 0)
            printf("%i\t", lista->dato);

        mostrarListaSoloPares(lista->sig, ++contador);
    }
}

void agregarNodoAlFinal (nodo** lista, nodo* agreg)
{
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

void agregarNodoAlPrincipio (nodo** lista, nodo* agreg)
{
    if (*lista)
    {
        agreg->sig = *lista;

        *lista = agreg;
    }
    else
        *lista = agreg;
}

void invertirListaRec (nodo** lista, nodo* listaAux) // aux inicializado en NULL
{
    nodo* aux;

    if (*lista)
    {
        aux = *lista; // guardo nodo de lista

        *lista = (*lista)->sig; // avanzo en lista  ----  acercamiento (¿??)

        aux->sig = listaAux; // agrego nodo a lista invertida

        listaAux = aux; // actualizo lista invertida

        invertirListaRec(lista, listaAux); // llamada recursiva
    }
    else // corte
        *lista = listaAux; // solucion trivial
}

void borrarNodoRec (nodo** lista, nodo** ant, nodo** act, int dato)
{
    nodo* aux;

    if ((*lista)->dato == dato) // 1er condicion de corte (¿?)
    {
        aux = *lista;
        *lista = *act;     // 1ra solucion trivial (¿?)
        free(ant);
    }
    else if (*act)
    {
        if ((*act)->dato == dato) // 2da condicion de corte
        {
            aux = *act;
            (*ant)->sig = (*act)->sig;    // 2da solucion trivial
            free(aux);
        }
        else
            borrarNodoRec(lista, &(*ant)->sig, &(*act)->sig, dato); // llamada recursiva y acercamientos
    }
}

void insertarOrdenadoRec (nodo** lista, nodo** ant, nodo** act, int dato)
{
    if (dato < (*lista)->dato)
    {
        nodo* aux = crearNodo(dato);
        aux->sig = *lista;
        *lista = aux;
    }
    else if (*act)
    {
        if (dato < (*act)->dato)
        {
            nodo* aux = crearNodo(dato);
            aux->sig = *act;
            (*ant)->sig = aux;
        }
        else
            insertarOrdenadoRec(lista, &(*ant)->sig, &(*act)->sig, dato);
    }
    else
        (*ant)->sig = crearNodo(dato);
}

/// MAIN

int main()
{
    nodo* lista;
    inicLista(&lista);

    agregarNodo(&lista, 9);
    agregarNodo(&lista, 8);
    agregarNodo(&lista, 6);
    agregarNodo(&lista, 5);
    agregarNodo(&lista, 2);
    agregarNodo(&lista, 1);

    mostrarLista(lista);
    printf("\n");
    mostrarListaInvert(lista);
    printf("\n");

    printf("\nLa suma de los datos de la lista es: %i\n", retSumaLista(lista));

    printf("\n");
    mostrarListaSoloPares(lista, 1);

    printf("\nLISTA SIN INVERTIR\n");
    mostrarLista(lista);
    printf("\nLISTA INVERTIDA\n");
    invertirListaRec(&lista, NULL);
    mostrarLista(lista);

    printf("\nDESPUES DE BORRAR EL 7\n");
    borrarNodoRec(&lista, &lista, &lista->sig, 7);
    mostrarLista(lista);

    printf("\nDESPUES DE INSERTAR\n");
    insertarOrdenadoRec(&lista, &lista, &lista->sig, 3);
    mostrarLista(lista);
    return 0;
}

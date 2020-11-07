#include "columnas_compu.h"
#include <iostream>
#include "string.h"
#include "map_str.h"

using namespace std;

void map_str_nodo :: mirar ()
{
    columnas_compu_nodo * pr = ptr; // puntero que recorre

    while (pr != NULL)
    {
        cout << "\t\tptr: " << pr->data << endl;
        pr = pr->next;
    }
}

map_str :: map_str  (char * nombre)
{
    // constructor

    name = new char [strlen (nombre) + 1];
    strcpy (name, nombre);
    inicio = NULL;
}

map_str :: ~map_str ()
{
    // destructor

    map_str_nodo * pr = inicio; // puntero que recorre

    while (inicio != NULL)
    {
        pr = pr->next;
        delete inicio;
        inicio = pr;
    }

    delete name;
}

void map_str :: agregar_compu (char * idx, columnas_compu * nueva_compu)
{
    map_str_nodo * nodo;
    columnas_compu_nodo * nuevo_nodo_compu = new columnas_compu_nodo;
    nuevo_nodo_compu->data = nueva_compu;

    nodo = buscar_compu (idx);
    if (nodo != NULL)
    {
        nuevo_nodo_compu->next = nodo->ptr;
        nodo->ptr = nuevo_nodo_compu;
    }
    else
    {
        nodo = new map_str_nodo;
        
        nodo->idx = idx;
        nodo->ptr = nuevo_nodo_compu;
        nuevo_nodo_compu->next = NULL;

        nodo->next=inicio;
        inicio=nodo;
    }
}

columnas_compu_nodo * map_str :: borrar_compu (char * idx)
{
    columnas_compu_nodo * borrar_compu;

    map_str_nodo * pr_prev = inicio; // puntero que recorre en la posicion anterior
    map_str_nodo * pr      = inicio->next; // puntero que recorre

    if (strcmp (inicio->idx, idx) == 0)
    {
        // es el primer elemento
        borrar_compu = inicio->ptr;
        delete inicio;
        inicio = pr;
        return borrar_compu;
    }
    else
    {
        // NO es el primer elemento   

        while (pr != NULL)
        {
            if (strcmp (pr->idx, idx) == 0)
            {
                map_str_nodo * pr_next = pr->next;

                borrar_compu = pr->ptr;
                delete pr;
                pr_prev->next = pr_next;
                return borrar_compu;
            }

            pr = pr->next;
            pr_prev = pr_prev->next;
        }
    }

    return NULL;
}

map_str_nodo * map_str :: buscar_compu (char * idx)
{
    map_str_nodo * pr = inicio; // puntero que recorre

    while (pr != NULL)
    {
        if (strcmp (pr->idx, idx) == 0)
        {
            return pr;
        }

        pr = pr->next;
    }

    return NULL;
}

void map_str :: mirar ()
{
    map_str_nodo * pr = inicio; // puntero que recorre

    cout << "map_str " << name << ":" << endl;
    while (pr != NULL)
    {
        cout << "\tidx: " << pr->idx << ":" << endl;
        pr->ptr->mirar ();

        pr = pr->next;
    }
}

void map_str :: mirar (char * idx)
{
    map_str_nodo * pi; // puntero al indice

    pi = buscar_compu (idx);
    
    cout << "map_str " << name << ":" << endl;
    cout << "\tidx: " << pi->idx << ":" << endl;
    pi->mirar ();
}
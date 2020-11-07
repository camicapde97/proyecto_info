#include "columnas_compu.h"
#include <iostream>
#include "string.h"
#include "map_int.h"

using namespace std;

void map_int_nodo :: mirar ()
{
    columnas_compu_nodo * pr = ptr; // puntero que recorre
    
    while (pr != NULL)
    {
        cout << "\t\tptr: " << pr->data << endl;
        pr = pr->next;
    }
}

map_int :: map_int  (char * nombre)
{
    // constructor

    name = new char [strlen (nombre) + 1];
    strcpy (name, nombre);
    inicio = NULL;
}

map_int :: ~map_int ()
{
    // destructor

    map_int_nodo * pr = inicio; // puntero que recorre

    while (inicio != NULL)
    {
        pr = pr->next;
        delete inicio;
        inicio = pr;
    }

    delete name;
}

void map_int :: agregar_compu (int idx, columnas_compu * nueva_compu)
{
    map_int_nodo * nodo;
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
        nodo = new map_int_nodo;
        
        nodo->idx = idx;
        nodo->ptr = nuevo_nodo_compu;
        nuevo_nodo_compu->next = NULL;

        nodo->next=inicio;
        inicio=nodo;
    }
}

columnas_compu_nodo * map_int :: borrar_compu (int idx)
{
    columnas_compu_nodo * borrar_compu;

    map_int_nodo * pr_prev = inicio; // puntero que recorre en la posicion anterior
    map_int_nodo * pr      = inicio->next; // puntero que recorre

    if (inicio->idx == idx)
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
            if (pr->idx == idx)
            {
                map_int_nodo * pr_next = pr->next;

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

map_int_nodo * map_int :: buscar_compu (int idx)
{
    map_int_nodo * pr = inicio; // puntero que recorre

    while (pr != NULL)
    {
        if (pr->idx == idx)
        {
            return pr;
        }

        pr = pr->next;
    }

    return NULL;
}

void map_int :: mirar ()
{
    map_int_nodo * pr = inicio; // puntero que recorre

    cout << "map_int " << name << ":" << endl;
    while (pr != NULL)
    {
        cout << "\tidx: " << pr->idx << ":" << endl;
        pr->ptr->mirar ();

        pr = pr->next;
    }
}

void map_int :: mirar (int idx)
{
    map_int_nodo * pi; // puntero al indice

    pi = buscar_compu (idx);
    
    cout << "map_int " << name << ":" << endl;
    cout << "\tidx: " << pi->idx << ":" << endl;
    pi->mirar ();
}
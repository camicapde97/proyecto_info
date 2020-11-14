#include "Tabla_Compus.h"
#include <iostream>
#include "string.h"

using namespace std;


Tabla_Compus :: Tabla_Compus ()
{
    inicio = NULL;
}

Tabla_Compus :: ~Tabla_Compus ()
{
    Fila_Compu_Nodo * aux = inicio;

    while (inicio != NULL)
    {
        aux = aux->next;
        delete inicio;
        inicio = aux;
    }
}

void Tabla_Compus::agregar (Fila_Compu * fila_compu)
{
    Fila_Compu_Nodo * nueva_compu = new Fila_Compu_Nodo;

    nueva_compu->data = fila_compu;
    nueva_compu->next = inicio;
    inicio = nueva_compu;
}

Fila_Compu_Nodo * Tabla_Compus::buscar_por_id (int compu_id)
{
    Fila_Compu_Nodo * pr = inicio;

    while (pr != NULL)
    {
        if (pr->data->compu_id == compu_id)
        {
            return pr;
        }

        pr = pr->next;
    }
    
    return NULL;
}

Fila_Compu_Nodo * Tabla_Compus::buscar_por_posicion (int posicion)
{
    int i = 0;
    Fila_Compu_Nodo * pr = inicio;

    while (pr != NULL)
    {
        if (i == posicion)
        {
            return pr;
        }

        pr = pr->next;
        i++;
    }
    
    return NULL;
}

void Tabla_Compus::borrar (Fila_Compu_Nodo * fila_compu_nodo)
{
    Fila_Compu_Nodo * pr = inicio;

    if (inicio == fila_compu)
    {
        pr = pr->next;
        delete inicio;
        inicio = pr;
    }
    else
    {
        while (pr != NULL && pr->next != fila_compu)
        {
            pr = pr->next;
        }
        if (pr->next == fila_compu)
        {
            pr->next = fila_compu_nodo->next;
            delete fila_compu_nodo;
        }
    }
}

void Tabla_Compus::ordenar_por_nro_serie (bool invertir)
{
    Fila_Compu_Nodo *i, *j;
    Fila_Compu * aux;

    if (inicio == NULL || inicio->next == NULL)
    {
        return;
    }

    for (i = inicio; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (invertir)
            {
                if (i->data->nro_serie < j->data->nro_serie)
                {
                    aux     = i->data;
                    i->data = j->data;
                    j->data = aux;
                }
            }
            else
            {
                if (i->data->nro_serie > j->data->nro_serie)
                {
                    aux     = i->data;
                    i->data = j->data;
                    j->data = aux;
                }
            }
        }
    }
}

void Tabla_Compus::ordenar_por_encriptada (bool invertir)
{
    Fila_Compu_Nodo *i, *j;
    Fila_Compu * aux;

    if (inicio == NULL || inicio->next == NULL)
    {
        return;
    }

    for (i = inicio; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (invertir)
            {
                if (i->data->encriptada > j->data->encriptada)
                {
                    aux     = i->data;
                    i->data = j->data;
                    j->data = aux;
                }
            }
            else
            {
                if (i->data->encriptada < j->data->encriptada)
                {
                    aux     = i->data;
                    i->data = j->data;
                    j->data = aux;
                }
            }
        }
    }
}

#include "map_str.h"
#include <iostream>

using namespace std;

int main ()
{
    cout << "START" << endl;

    columnas_compu * compu;
    map_str_nodo * nodo;
    map_str mapa ("mapa de prueba");

    mapa.mirar ();

    compu = new columnas_compu;
    mapa.agregar_compu ("1", compu);

    compu = new columnas_compu;
    mapa.agregar_compu ("13", compu);

    compu = new columnas_compu;
    mapa.agregar_compu ("67", compu);

    mapa.mirar ();

    nodo = mapa.buscar_compu ("15");
    if (nodo)
    {
        cout << "la compu 15 existe (MAL)" << endl;
        nodo->mirar ();
    }
    else
    {
        cout << "la compu 15 NO existe (BIEN)" << endl;
    }

    nodo = mapa.buscar_compu ("67");
    if (nodo)
    {
        cout << "la compu 67 existe (BIEN)" << endl;
        nodo->mirar ();
    }
    else
    {
        cout << "la compu 67 NO existe (MAL)" << endl;
    }

    columnas_compu_nodo * compu_nodo;
    compu_nodo = mapa.borrar_compu ("67");

    columnas_compu_nodo * aux = compu_nodo;
    while (compu_nodo != NULL)
    {
        aux = aux->next;
        compu_nodo->mirar ();
        delete compu_nodo->data;
        delete compu_nodo;
        compu_nodo = aux;
    }

    cout << "END" << endl;

    return 0;
}
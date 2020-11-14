#ifndef TABLA_COMPUS_H
#define TABLA_COMPUS_H

#include "Fila_Compu.h"
#include "map_int.h"
#include "map_str.h"

using namespace std;

class Tabla_Compus
{
    public:
        Fila_Compu_Nodo * inicio;

        Tabla_Compus ();
        ~Tabla_Compus ();

        void agregar (Fila_Compu * fila_compu);

        Fila_Compu_Nodo * buscar_por_id (int compu_id);
        Fila_Compu_Nodo * buscar_por_posicion (int posicion);
        void borrar (Fila_Compu_Nodo * fila_compu_nodo);
        void ordenar_por_nro_serie (bool invertir);
        void ordenar_por_encriptada (bool invertir);
};

#endif // TABLA_COMPUS_H
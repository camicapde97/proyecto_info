#include "columnas_compu.h"

class map_int_nodo
{
    public:
        int idx;
        columnas_compu_nodo * ptr;
        map_int_nodo * next;

        void mirar ();
};

class map_int
{
    public:
        char * name;
        map_int_nodo * inicio;

        map_int  (char * nombre);
        ~map_int ();
        
        void                  mirar         ();
        void                  mirar         (int idx);
        void                  agregar_compu (int idx, columnas_compu * nueva_compu);
        columnas_compu_nodo * borrar_compu  (int idx);
        map_int_nodo *        buscar_compu  (int idx);
};
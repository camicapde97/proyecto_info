#include "columnas_compu.h"

class map_str_nodo
{
    public:
        char * idx;
        columnas_compu_nodo * ptr;
        map_str_nodo * next;

        void mirar ();
};

class map_str
{
    public:
        char * name;
        map_str_nodo * inicio;

        map_str  (char * nombre);
        ~map_str ();
        
        void                  mirar         ();
        void                  mirar         (char * idx);
        void                  agregar_compu (char * idx, columnas_compu * nueva_compu);
        columnas_compu_nodo * borrar_compu  (char * idx);
        map_str_nodo *        buscar_compu  (char * idx);
};
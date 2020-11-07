#ifndef TABLA_COMPUS_H_
#define TABLA_COMPUS_H_

#include "columnas_compu.h"
#include "map_int.h"
#include "map_str.h"

using namespace std;

class tabla_compus
{
    public:
        columnas_compu_nodo * filas_compu;

        map_str by_nro_serie;
        map_str by_modelo;
        map_int by_estado;
        map_int by_encriptada;
        map_int by_garantia;
        map_str by_usuario;
        map_int by_docusing_checklist;
        map_int by_docusing_entrega;
        map_int by_docusing_devolucion;

        tabla_compus ();
        ~tabla_compus ();

        void agregar (
            string nro_serie,
            string modelo,
            int    estado,
            bool   encriptada,
            bool   garantia,
            string usuario,
            int    docusing_checklist,
            int    docusing_entrega,
            int    docusing_devolucion,
            time_t fecha_de_entrega,
            time_t fecha_de_devolucion,
            time_t fecha_de_docusing);

        void agregar (
            string nro_serie,
            string modelo);

        // TODO:
        void borrar ();
        void ordenar ();
};

#endif // TABLA_COMPUS_H_
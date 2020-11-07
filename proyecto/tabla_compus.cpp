#include "tabla_compus.h"
#include <iostream>

using namespace std;


tabla_compus :: tabla_compus ()
{
    filas_compu = NULL;

}

tabla_compus :: ~tabla_compus ()
{
    columnas_compu_nodo * aux = filas_compu;

    while (filas_compu != NULL)
    {
        aux = aux->next;
        delete filas_compu;
        filas_compu = aux;
    }
}

void tabla_compus::agregar (
    string nro_serie,
    string modelo,
    estado_compu_t estado,
    bool   encriptada,
    bool   garantia,
    string usuario,
    estado_docusing_t docusing_checklist,
    estado_docusing_t docusing_entrega,
    estado_docusing_t docusing_devolucion,
    time_t fecha_de_entrega,
    time_t fecha_de_devolucion,
    time_t fecha_de_docusing)
{
    columnas_compu_nodo * nueva_compu = new columnas_compu_nodo;

    nueva_compu->data.nro_serie             = nro_serie;
    nueva_compu->data.modelo                = modelo;
    nueva_compu->data.estado                = estado;
    nueva_compu->data.encriptada            = encriptada;
    nueva_compu->data.garantia              = garantia;
    nueva_compu->data.usuario               = usuario;
    nueva_compu->data.docusing_checklist    = docusing_checklist;
    nueva_compu->data.docusing_entrega      = docusing_entrega;
    nueva_compu->data.docusing_devolucion   = docusing_devolucion;
    nueva_compu->data.fecha_de_entrega      = fecha_de_entrega;
    nueva_compu->data.fecha_de_devolucion   = fecha_de_devolucion;
    nueva_compu->data.fecha_de_docusing     = fecha_de_docusing;

    by_nro_serie           .agregar_compu (nro_serie,           nueva_compu);
    by_modelo              .agregar_compu (modelo,              nueva_compu);
    by_estado              .agregar_compu (estado,              nueva_compu);
    by_encriptada          .agregar_compu (encriptada,          nueva_compu);
    by_garantia            .agregar_compu (garantia,            nueva_compu);
    by_usuario             .agregar_compu (usuario,             nueva_compu);
    by_docusing_checklist  .agregar_compu (docusing_checklist,  nueva_compu);
    by_docusing_entrega    .agregar_compu (docusing_entrega,    nueva_compu);
    by_docusing_devolucion .agregar_compu (docusing_devolucion, nueva_compu);

    nueva_compu->next = filas_compu;
    filas_compu = nueva_compu;
}

void tabla_compus::agregar (
        string nro_serie,
        string modelo)
{
    agregar (
        /*nro_serie*/           nro_serie,
        /*modelo*/              modelo,
        /*estado*/              DISPONIBLE,
        /*encriptada*/          true,
        /*garantia*/            true,
        /*usuario*/             "",
        /*docusing_checklist*/  SIN_ENVIAR,
        /*docusing_entrega*/    SIN_ENVIAR,
        /*docusing_devolucion*/ SIN_ENVIAR,
        /*fecha_de_entrega*/    0,
        /*fecha_de_devolucion*/ 0,
        /*fecha_de_docusing*/   0);
}
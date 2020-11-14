#include "Fila_Compu.h"
#include <iostream>

using namespace std;

Fila_Compu::Fila_Compu (
    char * _nro_serie,
    char * _modelo,
    int    _estado,
    bool   _encriptada,
    bool   _garantia,
    char * _usuario,
    int    _docusing_checklist,
    int    _docusing_entrega,
    int    _docusing_devolucion,
    time_t _fecha_de_entrega,
    time_t _fecha_de_devolucion,
    time_t _fecha_de_docusing)
{
    strcpy (nro_serie,      _nro_serie);
    strcpy (modelo,         _modelo);
    estado                = _estado;
    encriptada            = _encriptada;
    garantia              = _garantia;
    strcpy (usuario,        _usuario);
    docusing_checklist    = _docusing_checklist;
    docusing_entrega      = _docusing_entrega;
    docusing_devolucion   = _docusing_devolucion;
    fecha_de_entrega      = _fecha_de_entrega;
    fecha_de_devolucion   = _fecha_de_devolucion;
    fecha_de_docusing     = _fecha_de_docusing;
}

void Fila_Compu::mirar ()
{
    cout << "nro_serie: "           << nro_serie           << endl;
    cout << "modelo: "              << modelo              << endl;
    cout << "estado: "              << estado              << endl;
    cout << "encriptada: "          << encriptada          << endl;
    cout << "garantia: "            << garantia            << endl;
    cout << "usuario: "             << usuario             << endl;
    cout << "docusing_checklist: "  << docusing_checklist  << endl;
    cout << "docusing_entrega: "    << docusing_entrega    << endl;
    cout << "docusing_devolucion: " << docusing_devolucion << endl;
    cout << "fecha_de_entrega: "    << fecha_de_entrega    << endl;
    cout << "fecha_de_devolucion: " << fecha_de_devolucion << endl;
    cout << "fecha_de_docusing: "   << fecha_de_docusing   << endl;
}

Fila_Compu_Nodo :: Fila_Compu_Nodo  ()
{
    data = NULL;
    next = NULL;
}

void Fila_Compu_Nodo::mirar ()
{
    if (data != NULL)
    {
        data->mirar ();
    }
}

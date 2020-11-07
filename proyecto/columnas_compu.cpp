#include "columnas_compu.h"
#include <iostream>

using namespace std;

void columnas_compu::mirar ()
{
    cout << "nro_serie: " << nro_serie << endl;
    cout << "modelo: " << modelo << endl;
    cout << "estado: " << estado << endl;
    cout << "encriptada: " << encriptada << endl;
    cout << "garantia: " << garantia << endl;
    cout << "usuario: " << usuario << endl;
    cout << "docusing_checklist: " << docusing_checklist << endl;
    cout << "docusing_entrega: " << docusing_entrega << endl;
    cout << "docusing_devolucion: " << docusing_devolucion << endl;
    cout << "fecha_de_entrega: " << fecha_de_entrega << endl;
    cout << "fecha_de_devolucion: " << fecha_de_devolucion << endl;
    cout << "fecha_de_docusing: " << fecha_de_docusing << endl;
}

columnas_compu_nodo :: columnas_compu_nodo  ()
{
    data = NULL;
    next = NULL;
}

void columnas_compu_nodo::mirar ()
{
    data->mirar ();
}

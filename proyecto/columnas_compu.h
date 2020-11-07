#ifndef FILA_COMPU_H_
#define FILA_COMPU_H_

#include <string>

using namespace std;

// Estado:
#define DISPONIBLE 0
#define PRESTADA   1
#define ROTA       2

// Docusing
#define SIN_ENVIAR 0
#define FIRMADO    1
#define ENVIADO    2

class columnas_compu
{
    public:
        int    compu_id; // key
        string nro_serie;
        string modelo;
        int    estado;
        bool   encriptada;
        bool   garantia;
        string usuario;
        int    docusing_checklist;
        int    docusing_entrega;
        int    docusing_devolucion;
        time_t fecha_de_entrega;
        time_t fecha_de_devolucion;
        time_t fecha_de_docusing; // fecha del docusing de entrega

        void mirar ();
};

class columnas_compu_nodo
{
    public:
        columnas_compu * data;
        columnas_compu_nodo * next;

        columnas_compu_nodo  ();

        void mirar ();
};

#endif // FILA_COMPU_H_
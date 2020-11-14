#ifndef FILA_COMPU_H
#define FILA_COMPU_H

// Estado:
#define DISPONIBLE 0
#define PRESTADA   1
#define ROTA       2

// Docusing
#define SIN_ENVIAR 0
#define FIRMADO    1
#define ENVIADO    2

#define STR_LEN 128

class Fila_Compu
{
    public:
        int    compu_id; // key
        char   nro_serie [STR_LEN];
        char   modelo [STR_LEN];
        int    estado;
        bool   encriptada;
        bool   garantia;
        char   usuario [STR_LEN];
        int    docusing_checklist;
        int    docusing_entrega;
        int    docusing_devolucion;
        time_t fecha_de_entrega; // fecha de entrega de la compu
        time_t fecha_de_devolucion;
        time_t fecha_de_docusing; // fecha del docusing de entrega

        Fila_Compu (
            char * nro_serie,
            char * modelo,
            int    estado,
            bool   encriptada,
            bool   garantia,
            char * usuario,
            int    docusing_checklist,
            int    docusing_entrega,
            int    docusing_devolucion,
            time_t fecha_de_entrega,
            time_t fecha_de_devolucion,
            time_t fecha_de_docusing);
            
        void mirar ();
};

class Fila_Compu_Nodo
{
    public:
        Fila_Compu * data;
        Fila_Compu_Nodo * next;

        Fila_Compu_Nodo  ();

        void mirar ();
};

#endif // FILA_COMPU_H

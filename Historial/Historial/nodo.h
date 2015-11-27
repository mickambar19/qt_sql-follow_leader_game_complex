#ifndef NODO_H
#define NODO_H

#include "ganador.h"

class Nodo
{
public:
    Ganador g;
    Nodo *siguiente;
    Nodo *anterior;
};

typedef Nodo *pnodo;
#endif // NODO_H

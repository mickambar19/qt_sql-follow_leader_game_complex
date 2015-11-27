#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>

class Lista
{
public:
    pnodo inicio, fin;
    int tam;
public:
    Lista();
    void Ins_Vacia ();
    void CargarDatos ();
    void Mostrar1 ();
    void Mostrar2 ();
    void Buscar ();
    bool Vacio ();
    void SupInicio ();
    void Destruir ();
    void Burbuja ();
    void QuickSort(pnodo izq, pnodo der);
    void BusquedaBinaria();
};


#endif // LISTA_H

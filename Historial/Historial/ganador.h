#ifndef GANADOR_H
#define GANADOR_H

#include <iostream>
#include <fstream>

using namespace std;

class Ganador {
public:
    char NombreJugador[20];
    char NombreOponente[20];
    char NombreGanador[20];
    int puntos;

public:
    void Capturar();
    void Mostrar();
};


#endif // GANADOR_H

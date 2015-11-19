#include <iostream>
#include "ventanaPartida.h"
using namespace std;
int main(int argc, char const *argv[])
{
    VentanaPartida *ventanaPartida;
    ventanaPartida = new VentanaPartida;
    ventanaPartida->obtenerNombreDeJugador();
    ventanaPartida->obtenerNombreDeOponente();
    ventanaPartida->obtenerSecuencias();
    ventanaPartida->mostrarVentanaIniciar();
	return 0;
}

#include <iostream>
#include "ventanaPrincipal.h"
#include "ventanaPartida.h"
using namespace std;
int main(int argc, char const *argv[])
{
    VentanaPrincipal *ventanaPrincipal;
    ventanaPrincipal = new VentanaPrincipal;
    ventanaPrincipal.mostrar();
	return 0;
}

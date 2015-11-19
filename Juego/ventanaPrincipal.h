#ifndef __VENTANAPRINCIPAL_H
#define __VENTANAPRINCIPAL_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 
#include <cstdlib>
#include <string>
#include "ventanaPartida.h"
#define ANCHO_PANTALLA 640
#define ALTO_PANTALLA 480
using namespace std;

enum Superficies
{
	TITULO_SUPERFICIE,
	INICIAR_SUPERFICIE,
	MPUNTUACION_SUPERFICIE,
	HISTORIAL_SUPERFICIE,
	INICIAR_B_SUPERFICIE,
	MPUNTUACION_B_SUPERFICIE,
	HISTORIAL_B_SUPERFICIE,
	TOTAL_SUPERFICIE
};
class VentanaPrincipal
{
private:
	SDL_Window *ventana;
	SDL_Surface *fondo;
	SDL_Surface *imagenPNG[7];
	SDL_Rect posicionIMGS[4];
	VentanaPartida *ventanaPartida;
public:
	VentanaPrincipal();
	bool inicializar();
	void cerrar();
	bool cargarImagenes();
	SDL_Surface* cargarDifFormat(std::string ruta);
	void pintar();
	void mostrar();
	void clickEnOpcionJugar();
};

#endif /*__VENTANAPRINCIPAL_H*/
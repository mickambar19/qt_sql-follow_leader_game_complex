#ifndef __VENTANAPRINCIPAL_H
#define __VENTANAPRINCIPAL_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 
#include <cstdlib>
#include <string>
#define VENTANAPOS_X 0 
#define VENTANAPOS_Y 0
#define ANCHO_PANTALLA 640
#define ALTO_PANTALLA 480
using namespace std;
class VentanaPrincipal
{
private:
	SDL_Window *ventana;
	SDL_Surface *fondo;
	SDL_Surface *imagenPNG[7];
	SDL_Rect posicionIMGS[4];
public:
	VentanaPrincipal();
	bool inicializar();
	void cerrar();
	bool cargarImagenes();
	SDL_Surface* cargarDifFormat(std::string ruta);
	void pintar();
};

#endif /*__VENTANAPRINCIPAL_H*/
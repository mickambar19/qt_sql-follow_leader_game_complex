#ifndef __VENTANAPARTIDA_H
#define __VENTANAPARTIDA_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_ttf.h> 
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#define VENTANAPOS_X 0 
#define VENTANAPOS_Y 0
#define ANCHO_PANTALLA_PART 640
#define ALTO_PANTALLA_PART 480
#define SECUENCIAS_MAXIMAS 15
#define COLUMNAS_MAXIMAS 9
using namespace std;

enum
{
	FONT_LEVEN = 0,
	FONT_MADERITA,
	FONT_BOMBA,
	FONT_ORANGE_JUICE,
	TOTAL_FONTS
};

enum 
{
	INICIO = 0,
	BTN1,
	BTN2,
	BTN3,
	BTN4,
	BTN5,
	BTN6,
	BTN7,
	BTN8,
	BTN9,
	FONDO,
	TITULO,
	ERROR,
	CORRECTA,
	FONDO_NOMBRE,
	FONDO_OPONENTE,
	FONDO_SECUENCIAS_BUENAS,
	VIDAS_3,
	VIDAS_2,
	VIDAS_1,
	TOTAL
};

enum 
{
	POSICION_TITULO = 0,
	POSICION_BTN1,
	POSICION_BTN2,
	POSICION_BTN3,
	POSICION_BTN4,
	POSICION_BTN5,
	POSICION_BTN6,
	POSICION_BTN7,
	POSICION_BTN8,
	POSICION_BTN9,
	POSICION_NOMBRE,
	POSICION_OPONENTE,
	POSICION_VIDAS,
	POSICION_SECUENCIAS_BUENAS,
	POSICION_FONDO_OPONENTE,
	POSICION_FONDO_NOMBRE,
	POSICION_FONDO_SECUENCIAS_BUENAS,
	TOTAL_POSICIONES
};
enum
{
	TEXTO_NOMBRE = 0,
	TEXTO_OPONENTE,
	TEXTO_VIDAS,
	TEXTO_SECUENCIAS_BUENAS,
	TOTAL_TEXTOS
};

class VentanaPartida
{
private:
	string nombreJugador;
	string nombreOponente;
	SDL_Window *ventana;
	SDL_Renderer *ventanaRender;
	SDL_Texture *fondo;
	SDL_Texture *imagenPNG[TOTAL];
	SDL_Rect posicionIMGS[TOTAL_POSICIONES];
	int secuencias[SECUENCIAS_MAXIMAS][COLUMNAS_MAXIMAS];
	int vidas;
	int secuenciasCorrectas;
	int numeroFila;
	int numeroColumna;
	int componentesCorrecto;
	int componentesEnSecuencia[SECUENCIAS_MAXIMAS];
	TTF_Font *font[TOTAL_FONTS];
	SDL_Color colorNegro;
	SDL_Texture *textures[TOTAL_TEXTOS];
	SDL_Surface *textSurfaces[TOTAL_TEXTOS];
public:
	VentanaPartida(string nombreJ, string nombreO, int secs[][COLUMNAS_MAXIMAS]);
	bool inicializar();
	void cerrar();
	bool cargarImagenes();
	SDL_Texture* cargarDifFormat(std::string ruta, SDL_Renderer *aRenderizar);
	void pintar();
	void pintarBoton(int aPintar);
	void mostrarSecuencia(int fila);
	void pintarRespuestaIncorrecta(int aPintar);
	void pintarRespuestaCorrecta(int aPintar);
	bool cargarFuentes();
	void pintarSecuenciasBuenas(int secuenciasBuenas);
	void pintarVidasRestantes(int vidasRestantes);
	int jugar();
	void repintar();
};

#endif /*__VENTANAPARTIDA_H*/
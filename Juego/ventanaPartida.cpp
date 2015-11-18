#include "ventanaPartida.h"

const char *archivos[TOTAL] = {
	"",
	"imgbtns/button1.png",
	"imgbtns/button2.png",
	"imgbtns/button3.png",
	"imgbtns/button4.png",
	"imgbtns/button5.png",
	"imgbtns/button6.png",
	"imgbtns/button7.png",
	"imgbtns/button8.png",
	"imgbtns/button9.png",
	"imgbtns/fondoPartida.png",
	"imgbtns/titulo.png",
	"imgbtns/buttonError2.png",
	"imgbtns/felix.png",
	"imgbtns/fondoNombre.png",
	"imgbtns/fondoOponente.png",
	"imgbtns/fondoSecuencias.png",
	"imgbtns/vidas3.png",
	"imgbtns/vidas2.png",
	"imgbtns/vidas1.png"
};
const char *archivosFonts[TOTAL_FONTS] = {
	"ttf/leven/reg.ttf",
	"ttf/maderita.ttf",
	"ttf/bomba.TTF",
	"ttf/orangejuice.ttf"
};

VentanaPartida::VentanaPartida(string nombreJ, string nombreO, int secs[][COLUMNAS_MAXIMAS])
{
	//int i = 0;
	/*Se recibe la secuencia y la copiamos a la memoria de el arreglo de esta clase*/
	nombreJugador = nombreJ;
	nombreOponente = nombreO;
	memcpy(secuencias, secs, sizeof(secuencias));
	for (int i = 0; i < 15; i++)
    {
    	cout<<"entraste al for:"<<i<<endl;
    	for (int g = 0; g < 9; g++)
    	{
    		
    		
    		cout<<"i:"<<i<<" g:"<<g<<" "<<secuencias[i][g]<<endl;
    	}
    }
  	numeroFila = 0;
  	numeroColumna = 0;
    vidas = 3;
    secuenciasCorrectas = 0;
	 if(TTF_Init()==-1) {
	   cout<<"Error_Init()";
	}
    if(!inicializar())
	{
		perror("Error en Inicializar()");
	}
	else
	{
		if(!cargarImagenes())
		{
			perror("Error en cargarImagenes()");
		}
		else
		{
			if(!cargarFuentes())
			{
				perror("Error en cargarFuentes()");
			}		
		}
	}
}

bool VentanaPartida::inicializar()
{
	
	ventana = NULL;
    fondo = NULL;

    for (int i = 0; i < TOTAL; ++i)
    {
    	imagenPNG[i]=NULL;
    }
	bool exito = true;

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		perror("Error en SDL_Init");
		exito = false;
	}
	else
	{
		ventana = SDL_CreateWindow("Titulo Ventana", VENTANAPOS_X,VENTANAPOS_Y,ANCHO_PANTALLA_PART,ALTO_PANTALLA_PART,SDL_WINDOW_SHOWN);
		ventanaRender = SDL_CreateRenderer(ventana,-1,SDL_RENDERER_ACCELERATED);
		if(ventana == NULL)
		{
			perror("Error en SDL_CreateWindow");
			exito = false;
		}	
		else
		{
			int banderasImagen = IMG_INIT_PNG;
			if(!(IMG_Init(banderasImagen)&banderasImagen))
			{
				perror("Error en IMG_Init");
				exito = false;
			}
			else
			{
				
			}			
		}		
	}
	colorNegro.r = 0;
	colorNegro.g = 0;
	colorNegro.b = 0;
	colorNegro.a = 255;
	
	posicionIMGS[POSICION_BTN1].x = 50;
	posicionIMGS[POSICION_BTN1].y = 100;
	posicionIMGS[POSICION_BTN1].w = 170;
	posicionIMGS[POSICION_BTN1].h = 100;

	posicionIMGS[POSICION_BTN2].x = 220;
	posicionIMGS[POSICION_BTN2].y = 100;
	posicionIMGS[POSICION_BTN2].w = 170;
	posicionIMGS[POSICION_BTN2].h = 100;

	posicionIMGS[POSICION_BTN3].x = 400;
	posicionIMGS[POSICION_BTN3].y = 100;
	posicionIMGS[POSICION_BTN3].w = 170;
	posicionIMGS[POSICION_BTN3].h = 100;

	posicionIMGS[POSICION_BTN4].x = 50;
	posicionIMGS[POSICION_BTN4].y = 210;
	posicionIMGS[POSICION_BTN4].w = 170;
	posicionIMGS[POSICION_BTN4].h = 100;

	posicionIMGS[POSICION_BTN5].x = 220;
	posicionIMGS[POSICION_BTN5].y = 210;
	posicionIMGS[POSICION_BTN5].w = 170;
	posicionIMGS[POSICION_BTN5].h = 100;
 
	posicionIMGS[POSICION_BTN6].x = 400;
	posicionIMGS[POSICION_BTN6].y = 210;
	posicionIMGS[POSICION_BTN6].w = 170;
	posicionIMGS[POSICION_BTN6].h = 100;

	posicionIMGS[POSICION_BTN7].x = 50;
	posicionIMGS[POSICION_BTN7].y = 320;
	posicionIMGS[POSICION_BTN7].w = 170;
	posicionIMGS[POSICION_BTN7].h = 100;

	posicionIMGS[POSICION_BTN8].x = 220;
	posicionIMGS[POSICION_BTN8].y = 320;
	posicionIMGS[POSICION_BTN8].w = 170;
	posicionIMGS[POSICION_BTN8].h = 100;

	posicionIMGS[POSICION_BTN9].x = 400;
	posicionIMGS[POSICION_BTN9].y = 320;
	posicionIMGS[POSICION_BTN9].w = 170;
	posicionIMGS[POSICION_BTN9].h = 100;

	posicionIMGS[POSICION_NOMBRE].x = 30;
	posicionIMGS[POSICION_NOMBRE].y = 5;


	posicionIMGS[POSICION_SECUENCIAS_BUENAS].x = 280;
	posicionIMGS[POSICION_SECUENCIAS_BUENAS].y = 50;
	
	posicionIMGS[POSICION_OPONENTE].x = 450;
	posicionIMGS[POSICION_OPONENTE].y = 5;


	posicionIMGS[POSICION_FONDO_NOMBRE].x = 10;
	posicionIMGS[POSICION_FONDO_NOMBRE].y = 5;
	posicionIMGS[POSICION_FONDO_NOMBRE].w = 200;
	posicionIMGS[POSICION_FONDO_NOMBRE].h = 40;
	
	posicionIMGS[POSICION_FONDO_SECUENCIAS_BUENAS].x = 260;
	posicionIMGS[POSICION_FONDO_SECUENCIAS_BUENAS].y = 50;
	posicionIMGS[POSICION_FONDO_SECUENCIAS_BUENAS].w = 90;
	posicionIMGS[POSICION_FONDO_SECUENCIAS_BUENAS].h = 40;

	posicionIMGS[POSICION_FONDO_OPONENTE].x = 430;
	posicionIMGS[POSICION_FONDO_OPONENTE].y = 5;
	posicionIMGS[POSICION_FONDO_OPONENTE].w = 200;
	posicionIMGS[POSICION_FONDO_OPONENTE].h = 40;
		/**/
	posicionIMGS[POSICION_VIDAS].x = 260;
	posicionIMGS[POSICION_VIDAS].y = 5;
	posicionIMGS[POSICION_VIDAS].w = 90;
	posicionIMGS[POSICION_VIDAS].h = 40;

	return exito;
}

bool VentanaPartida::cargarImagenes()
{
	bool exito = true;
	cout<<"Entre a cargarImagenes()"<<endl;

	for (int i = 1; i < TOTAL; ++i)
	{
		string archivo;
		archivo.assign(archivos[i]);
		cout<<archivo<<endl;
		imagenPNG[i] = cargarDifFormat(archivo,ventanaRender);
		if(imagenPNG[i] == NULL)
		{
			perror("Error en cargarDifFormat");
			exito = false;
		}
	}
	cout<<"Saldre de cargarImagenes()"<<endl;
	return exito;
}

void VentanaPartida::cerrar()
{
	for (int i = 0; i < TOTAL; ++i)
    {
    	SDL_DestroyTexture(imagenPNG[i]);
    	imagenPNG[i]=NULL;
    }
	SDL_DestroyWindow(ventana);
	ventana = NULL;
	SDL_Quit();
}

SDL_Texture* VentanaPartida::cargarDifFormat(std::string ruta, SDL_Renderer *aRenderizar)
{
	SDL_Texture* imgAux = NULL;
	SDL_Surface* imgCargada = IMG_Load(ruta.c_str());
	if(imgCargada == NULL)
	{
		perror("Error en IMG_Load");
	}
	else
	{
		imgAux = SDL_CreateTextureFromSurface(aRenderizar, imgCargada);
		if(imgAux == NULL)
		{
			perror("Error en SDL_ConvertSurface");
		}
		SDL_FreeSurface(imgCargada);
	}
	return imgAux;
}

void VentanaPartida::pintar()
{	    
	//TTF_Font *font2=TTF_OpenFont("ttf/leven/reg.ttf",50);
	//TTF_Font *font3=TTF_OpenFont("ttf/maderita.ttf",30);	
	/*Se pinta el background ademas de el nombre de jugador*/
	
	SDL_RenderCopy(ventanaRender,imagenPNG[FONDO],NULL,NULL);
	SDL_RenderCopy(ventanaRender,imagenPNG[FONDO_NOMBRE],NULL,&posicionIMGS[POSICION_FONDO_NOMBRE]);
	SDL_RenderCopy(ventanaRender,imagenPNG[FONDO_OPONENTE],NULL,&posicionIMGS[POSICION_FONDO_OPONENTE]);
	SDL_RenderCopy(ventanaRender,imagenPNG[FONDO_SECUENCIAS_BUENAS],NULL,&posicionIMGS[POSICION_FONDO_SECUENCIAS_BUENAS]);

	//SDL_Surface *surface = TTF_RenderText_Solid(font2,"Alexis Miguel", color2);
	//SDL_Texture *text2 = SDL_CreateTextureFromSurface(ventanaRender,surface);
	//cout<<"valor de font:"<<((void*)font[FONT_LEVEN])<<endl;
	//cout<<"valor de font:"<<((void*)font[FONT_MADERITA])<<endl;
	
	textSurfaces[TEXTO_OPONENTE] = TTF_RenderText_Solid(font[FONT_MADERITA],nombreOponente.c_str(), colorNegro);
	textSurfaces[TEXTO_NOMBRE] = TTF_RenderText_Solid(font[FONT_MADERITA],nombreJugador.c_str(), colorNegro);
	textSurfaces[TEXTO_SECUENCIAS_BUENAS] = TTF_RenderText_Solid(font[FONT_ORANGE_JUICE],"S# 0", colorNegro);

	textures[TEXTO_NOMBRE] = SDL_CreateTextureFromSurface(ventanaRender,textSurfaces[TEXTO_NOMBRE]);
	textures[TEXTO_OPONENTE] = SDL_CreateTextureFromSurface(ventanaRender,textSurfaces[TEXTO_OPONENTE]);
	textures[TEXTO_SECUENCIAS_BUENAS] = SDL_CreateTextureFromSurface(ventanaRender,textSurfaces[TEXTO_SECUENCIAS_BUENAS]);

	//SDL_QueryTexture(textJugador,0,0,&posicionIMGS[TITULO].w,&posicionIMGS[TITULO].h);
	//SDL_RenderCopy(ventanaRender,textJugador,NULL,&posicionIMGS[TITULO]);	

	SDL_QueryTexture(textures[TEXTO_OPONENTE],0,0,&posicionIMGS[POSICION_OPONENTE].w,&posicionIMGS[POSICION_OPONENTE].h);
	SDL_RenderCopy(ventanaRender,textures[TEXTO_OPONENTE],NULL,&posicionIMGS[POSICION_OPONENTE]);	

	SDL_QueryTexture(textures[TEXTO_NOMBRE],0,0,&posicionIMGS[POSICION_NOMBRE].w,&posicionIMGS[POSICION_NOMBRE].h);
	SDL_RenderCopy(ventanaRender,textures[TEXTO_NOMBRE],NULL,&posicionIMGS[POSICION_NOMBRE]);

	SDL_QueryTexture(textures[TEXTO_SECUENCIAS_BUENAS],0,0,&posicionIMGS[POSICION_SECUENCIAS_BUENAS].w,&posicionIMGS[POSICION_SECUENCIAS_BUENAS].h);
	SDL_RenderCopy(ventanaRender,textures[TEXTO_SECUENCIAS_BUENAS],NULL,&posicionIMGS[POSICION_SECUENCIAS_BUENAS]);
	pintarVidasRestantes(vidas);
}

void VentanaPartida::pintarBoton(int aPintar)
{
	switch(aPintar)
	{
		case BTN1:
			SDL_RenderCopy(ventanaRender,imagenPNG[BTN1],NULL,&posicionIMGS[BTN1]);
			break;
		case BTN2:
			SDL_RenderCopy(ventanaRender,imagenPNG[BTN2],NULL,&posicionIMGS[BTN2]);
			break;
		case BTN3:
			SDL_RenderCopy(ventanaRender,imagenPNG[BTN3],NULL,&posicionIMGS[BTN3]);
		break;
		case BTN4:
			SDL_RenderCopy(ventanaRender,imagenPNG[BTN4],NULL,&posicionIMGS[BTN4]);
		break;
		case BTN5:
			SDL_RenderCopy(ventanaRender,imagenPNG[BTN5],NULL,&posicionIMGS[BTN5]);
		break;
		case BTN6:
			SDL_RenderCopy(ventanaRender,imagenPNG[BTN6],NULL,&posicionIMGS[BTN6]);
		break;
		case BTN7:
			SDL_RenderCopy(ventanaRender,imagenPNG[BTN7],NULL,&posicionIMGS[BTN7]);
		break;
		case BTN8:
			SDL_RenderCopy(ventanaRender,imagenPNG[BTN8],NULL,&posicionIMGS[BTN8]);
		break;
		case BTN9:
			cout<<"holaquemira"<<endl;
			SDL_RenderCopy(ventanaRender,imagenPNG[BTN9],NULL,&posicionIMGS[BTN9]);
		break;
	}
	SDL_RenderPresent(ventanaRender);
}

void VentanaPartida::mostrarSecuencia(int fila)
{
	int numeroEnSecuencia = 0;
	int contador = 0;
	while(1)
	{
		numeroEnSecuencia = secuencias[fila][contador];
		if(numeroEnSecuencia==0 || contador==9)break;
		pintarBoton(numeroEnSecuencia);
		SDL_Delay(300);
		contador++;
		cout<<"mostrarSecuencia() numeroEnSecuencia:"<<numeroEnSecuencia<<endl;
	}
	componentesEnSecuencia[fila] = contador;
	cout<<"mostrarSecuencia() componentesEnSecuencia:"<<contador<<endl;
}

void VentanaPartida::pintarRespuestaCorrecta(int aPintar){
	switch(aPintar)
	{
		case BTN1:
			SDL_RenderCopy(ventanaRender,imagenPNG[CORRECTA],NULL,&posicionIMGS[BTN1]);
			break;
		case BTN2:
			SDL_RenderCopy(ventanaRender,imagenPNG[CORRECTA],NULL,&posicionIMGS[BTN2]);
			break;
		case BTN3:
			SDL_RenderCopy(ventanaRender,imagenPNG[CORRECTA],NULL,&posicionIMGS[BTN3]);
		break;
		case BTN4:
			SDL_RenderCopy(ventanaRender,imagenPNG[CORRECTA],NULL,&posicionIMGS[BTN4]);
		break;
		case BTN5:
			SDL_RenderCopy(ventanaRender,imagenPNG[CORRECTA],NULL,&posicionIMGS[BTN5]);
		break;
		case BTN6:
			SDL_RenderCopy(ventanaRender,imagenPNG[CORRECTA],NULL,&posicionIMGS[BTN6]);
		break;
		case BTN7:
			SDL_RenderCopy(ventanaRender,imagenPNG[CORRECTA],NULL,&posicionIMGS[BTN7]);
		break;
		case BTN8:
			SDL_RenderCopy(ventanaRender,imagenPNG[CORRECTA],NULL,&posicionIMGS[BTN8]);
		break;
		case BTN9:
			SDL_RenderCopy(ventanaRender,imagenPNG[CORRECTA],NULL,&posicionIMGS[BTN9]);
		break;
	}
	SDL_RenderPresent(ventanaRender);
}

void VentanaPartida::pintarRespuestaIncorrecta(int aPintar){
	switch(aPintar)
	{
		case BTN1:
			SDL_RenderCopy(ventanaRender,imagenPNG[ERROR],NULL,&posicionIMGS[BTN1]);
			break;
		case BTN2:
			SDL_RenderCopy(ventanaRender,imagenPNG[ERROR],NULL,&posicionIMGS[BTN2]);
			break;
		case BTN3:
			SDL_RenderCopy(ventanaRender,imagenPNG[ERROR],NULL,&posicionIMGS[BTN3]);
		break;
		case BTN4:
			SDL_RenderCopy(ventanaRender,imagenPNG[ERROR],NULL,&posicionIMGS[BTN4]);
		break;
		case BTN5:
			SDL_RenderCopy(ventanaRender,imagenPNG[ERROR],NULL,&posicionIMGS[BTN5]);
		break;
		case BTN6:
			SDL_RenderCopy(ventanaRender,imagenPNG[ERROR],NULL,&posicionIMGS[BTN6]);
		break;
		case BTN7:
			SDL_RenderCopy(ventanaRender,imagenPNG[ERROR],NULL,&posicionIMGS[BTN7]);
		break;
		case BTN8:
			SDL_RenderCopy(ventanaRender,imagenPNG[ERROR],NULL,&posicionIMGS[BTN8]);
		break;
		case BTN9:
			SDL_RenderCopy(ventanaRender,imagenPNG[ERROR],NULL,&posicionIMGS[BTN9]);
		break;
	}
	SDL_RenderPresent(ventanaRender);
}

bool VentanaPartida::cargarFuentes()
{
	bool exito=true;
	cout<<"Ejecuto:cargarFuentes";
	//SDL_RenderClear(ventanaRender);
	for (int i = 0; i < TOTAL_FONTS; ++i)
	{
		font[i] = TTF_OpenFont(archivosFonts[i],30);
		if(font[i] == NULL){
		cout<<"huboerror";
		exito = false;
		}
	}

	cout<<"Salio:cargarFuentes";
    return exito;
}

void VentanaPartida::pintarSecuenciasBuenas(int secuenciasBuenas)
{
	cout<<"Entre en pintarSecuenciasBuenas()\n";
	cout<<secuenciasBuenas<<endl;
	stringstream secuenciasBuenasFromateado;
	string secuenciasBuenasString;
	string palabraSecuencias ="S#: ";
	
	secuenciasBuenasFromateado<<secuenciasBuenas;
	secuenciasBuenasString = secuenciasBuenasFromateado.str();
	secuenciasBuenasString = palabraSecuencias + secuenciasBuenasString;
	cout<<secuenciasBuenasString<<endl;

	textSurfaces[TEXTO_SECUENCIAS_BUENAS] = TTF_RenderText_Solid(font[FONT_ORANGE_JUICE],secuenciasBuenasString.c_str(), colorNegro);
	textures[TEXTO_SECUENCIAS_BUENAS] = SDL_CreateTextureFromSurface(ventanaRender,textSurfaces[TEXTO_SECUENCIAS_BUENAS]);

	SDL_RenderCopy(ventanaRender,imagenPNG[FONDO_SECUENCIAS_BUENAS],NULL,&posicionIMGS[FONDO_SECUENCIAS_BUENAS]);

	SDL_QueryTexture(textures[TEXTO_SECUENCIAS_BUENAS],0,0,&posicionIMGS[POSICION_SECUENCIAS_BUENAS].w,&posicionIMGS[POSICION_SECUENCIAS_BUENAS].h);
	SDL_RenderCopy(ventanaRender,textures[TEXTO_SECUENCIAS_BUENAS],NULL,&posicionIMGS[POSICION_SECUENCIAS_BUENAS]);
	SDL_RenderPresent(ventanaRender);
	cout<<"Salir de pintarSecuenciasBuenas()\n";
}

void VentanaPartida::pintarVidasRestantes(int vidasRestantes)
{
	cout<<"Entre en pintarVidasRestantes()\n";
	switch(vidasRestantes)
	{
		case 0:
			/*Pendiente: que mostrar cuando pierda*/
			break;
		case 1:
			
			SDL_RenderCopy(ventanaRender,imagenPNG[VIDAS_1],NULL,&posicionIMGS[POSICION_VIDAS]);
			SDL_RenderPresent(ventanaRender);
			break;
		case 2:
			
			SDL_RenderCopy(ventanaRender,imagenPNG[VIDAS_2],NULL,&posicionIMGS[POSICION_VIDAS]);
			SDL_RenderPresent(ventanaRender);
			break;
		case 3:
			
			SDL_RenderCopy(ventanaRender,imagenPNG[VIDAS_3],NULL,&posicionIMGS[POSICION_VIDAS]);
			SDL_RenderPresent(ventanaRender);
			break;

	}
	cout<<"Salir de pintarVidasRestantes()\n";
}

int VentanaPartida::jugar()
{
	bool quiereSalir = false;
	SDL_Event e;	
	//SDL_FillRect(fondo,0,SDL_MapRGB(fondo->format,255,255,255));
	pintar();
	mostrarSecuencia(numeroFila);
	componentesCorrecto = 0;
	while(!quiereSalir)
	{
		while(SDL_PollEvent(&e)!=0)
		{

			if(e.type == SDL_QUIT)
			{
				quiereSalir = true;
			}
			else if(e.type==SDL_KEYDOWN)
			{
				switch(e.key.keysym.sym)
				{
					case SDLK_1:
						if(secuencias[numeroFila][numeroColumna]==BTN1)
						{
							pintarRespuestaCorrecta(BTN1);
							numeroColumna++;
							componentesCorrecto++;
							
						}
						else
						{
							pintarRespuestaIncorrecta(BTN1);
							vidas--;
							numeroFila++;
							pintarVidasRestantes(vidas);
							 //SDL_Delay(2000);
							repintar();
							mostrarSecuencia(numeroFila);;

						}
					break;
					case SDLK_2:
						if(secuencias[numeroFila][numeroColumna]==BTN2)
						{
							pintarRespuestaCorrecta(BTN2);
							numeroColumna++;
							componentesCorrecto++;
							
						}
						else
						{
							pintarRespuestaIncorrecta(BTN2);
							vidas--;
							pintarVidasRestantes(vidas);
							 //SDL_Delay(2000);
							repintar();
							mostrarSecuencia(numeroFila);
						}
					break;
					case SDLK_3:
						if(secuencias[numeroFila][numeroColumna]==BTN3)
						{
							pintarRespuestaCorrecta(BTN3);
							numeroColumna++;
							componentesCorrecto++;
							
						}
						else
						{
							pintarRespuestaIncorrecta(BTN3);
							vidas--;
							pintarVidasRestantes(vidas);
							 //SDL_Delay(2000);
							repintar();
							mostrarSecuencia(numeroFila);
						}
					break;
					case SDLK_4:
						if(secuencias[numeroFila][numeroColumna]==BTN4)
						{
							pintarRespuestaCorrecta(BTN4);
							numeroColumna++;
							componentesCorrecto++;
							
						}
						else
						{
							pintarRespuestaIncorrecta(BTN4);
							vidas--;
							pintarVidasRestantes(vidas);
							 //SDL_Delay(2000);
							repintar();
							mostrarSecuencia(numeroFila);
						}
					break;
					case SDLK_5:
						if(secuencias[numeroFila][numeroColumna]==BTN5)
						{
							pintarRespuestaCorrecta(BTN5);
							numeroColumna++;
							componentesCorrecto++;
							
						}
						else
						{
							pintarRespuestaIncorrecta(BTN5);
							vidas--;
							pintarVidasRestantes(vidas);
							 //SDL_Delay(2000);
							repintar();
							mostrarSecuencia(numeroFila);
						}
					break;
					case SDLK_6:
						if(secuencias[numeroFila][numeroColumna]==BTN6)
						{
							pintarRespuestaCorrecta(BTN6);
							numeroColumna++;
							componentesCorrecto++;
							
						}
						else
						{
							pintarRespuestaIncorrecta(BTN6);
							vidas--;
							pintarVidasRestantes(vidas);
							 //SDL_Delay(2000);
							repintar();
							mostrarSecuencia(numeroFila);
						}
					break;
					case SDLK_7:
						if(secuencias[numeroFila][numeroColumna]==BTN7)
						{
							pintarRespuestaCorrecta(BTN7);
							numeroColumna++;
							componentesCorrecto++;
							
						}
						else
						{
							pintarRespuestaIncorrecta(BTN7);
							vidas--;
							pintarVidasRestantes(vidas);
							 //SDL_Delay(2000);
							repintar();
							mostrarSecuencia(numeroFila);
						}
					break;
					case SDLK_8:
						if(secuencias[numeroFila][numeroColumna]==BTN8)
						{
							pintarRespuestaCorrecta(BTN8);
							numeroColumna++;
							componentesCorrecto++;
							
						}
						else
						{
							pintarRespuestaIncorrecta(BTN8);
							vidas--;
							pintarVidasRestantes(vidas);
							 //SDL_Delay(2000);
							repintar();
							mostrarSecuencia(numeroFila);
						}
					break;
					case SDLK_9:
						if(secuencias[numeroFila][numeroColumna]==BTN9)
						{
							pintarRespuestaCorrecta(BTN9);
							numeroColumna++;
							componentesCorrecto++;
							
						}
						else
						{
							pintarRespuestaIncorrecta(BTN9);
							vidas--;
							pintarVidasRestantes(vidas);
							 //SDL_Delay(2000);
							repintar();
							mostrarSecuencia(numeroFila);
						}
					break;
				}

				if (componentesCorrecto == componentesEnSecuencia[numeroFila])
				{
					cout<<"componentesCorrecto="<<componentesCorrecto<<endl;
					componentesCorrecto=0;
					/*
						Se supone que si el jugador ya siguio la 
						secuencia  ejemplo: secuencia [0] ->  1 4 3 6
						tiene como numero de componentes 4
						si el jugador ya tiene en su componentesCorrecto 4 ya tiene una secuencia completa
					*/
					cout<<"secuenciasCorrectas="<<secuenciasCorrectas<<endl;
					secuenciasCorrectas++;
					repintar();
					pintarSecuenciasBuenas(secuenciasCorrectas);
					numeroFila++;	
					mostrarSecuencia(numeroFila);
				}
			}		
		}							
	}
	return secuenciasCorrectas;
}

void VentanaPartida::repintar()
{	    
	//TTF_Font *font2=TTF_OpenFont("ttf/leven/reg.ttf",50);
	//TTF_Font *font3=TTF_OpenFont("ttf/maderita.ttf",30);	
	/*Se pinta el background ademas de el nombre de jugador*/
	
	SDL_RenderCopy(ventanaRender,imagenPNG[FONDO],NULL,NULL);
	SDL_RenderCopy(ventanaRender,imagenPNG[FONDO_NOMBRE],NULL,&posicionIMGS[POSICION_FONDO_NOMBRE]);
	SDL_RenderCopy(ventanaRender,imagenPNG[FONDO_OPONENTE],NULL,&posicionIMGS[POSICION_FONDO_OPONENTE]);
	SDL_RenderCopy(ventanaRender,imagenPNG[FONDO_SECUENCIAS_BUENAS],NULL,&posicionIMGS[POSICION_FONDO_SECUENCIAS_BUENAS]);

	//SDL_Surface *surface = TTF_RenderText_Solid(font2,"Alexis Miguel", color2);
	//SDL_Texture *text2 = SDL_CreateTextureFromSurface(ventanaRender,surface);
	cout<<"valor de font:"<<((void*)font[FONT_LEVEN])<<endl;
	cout<<"valor de font:"<<((void*)font[FONT_MADERITA])<<endl;
	textSurfaces[TEXTO_OPONENTE] = TTF_RenderText_Solid(font[FONT_MADERITA],nombreOponente.c_str(), colorNegro);
	textSurfaces[TEXTO_NOMBRE] = TTF_RenderText_Solid(font[FONT_MADERITA],nombreJugador.c_str(), colorNegro);
	//textSurfaces[TEXTO_SECUENCIAS_BUENAS] = TTF_RenderText_Solid(font[FONT_ORANGE_JUICE],"0", colorNegro);

	textures[TEXTO_NOMBRE] = SDL_CreateTextureFromSurface(ventanaRender,textSurfaces[TEXTO_NOMBRE]);
	textures[TEXTO_OPONENTE] = SDL_CreateTextureFromSurface(ventanaRender,textSurfaces[TEXTO_OPONENTE]);
	//textures[TEXTO_SECUENCIAS_BUENAS] = SDL_CreateTextureFromSurface(ventanaRender,textSurfaces[TEXTO_SECUENCIAS_BUENAS]);

	//SDL_QueryTexture(textJugador,0,0,&posicionIMGS[TITULO].w,&posicionIMGS[TITULO].h);
	//SDL_RenderCopy(ventanaRender,textJugador,NULL,&posicionIMGS[TITULO]);	

	SDL_QueryTexture(textures[TEXTO_OPONENTE],0,0,&posicionIMGS[POSICION_OPONENTE].w,&posicionIMGS[POSICION_OPONENTE].h);
	SDL_RenderCopy(ventanaRender,textures[TEXTO_OPONENTE],NULL,&posicionIMGS[POSICION_OPONENTE]);	

	SDL_QueryTexture(textures[TEXTO_NOMBRE],0,0,&posicionIMGS[POSICION_NOMBRE].w,&posicionIMGS[POSICION_NOMBRE].h);
	SDL_RenderCopy(ventanaRender,textures[TEXTO_NOMBRE],NULL,&posicionIMGS[POSICION_NOMBRE]);

	SDL_QueryTexture(textures[TEXTO_SECUENCIAS_BUENAS],0,0,&posicionIMGS[POSICION_SECUENCIAS_BUENAS].w,&posicionIMGS[POSICION_SECUENCIAS_BUENAS].h);
	SDL_RenderCopy(ventanaRender,textures[TEXTO_SECUENCIAS_BUENAS],NULL,&posicionIMGS[POSICION_SECUENCIAS_BUENAS]);
	pintarVidasRestantes(vidas);
	pintarSecuenciasBuenas(secuenciasCorrectas);
}

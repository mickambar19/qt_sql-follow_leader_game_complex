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
	"imgbtns/vidas1.png",
	"imgbtns/fondoBlanco.png",
	"imgbtns/iniciar.png",
	"imgbtns/iniciarb.png",
	"imgbtns/historial.png",
	"imgbtns/historialb.png",
	"imgbtns/puntuacion.png",
	"imgbtns/puntuacionb.png",
	"imgbtns/conectar.png",
	"imgbtns/conectarA.png",
	"imgbtns/linea.png",
	"imgbtns/esperando.png",
	"imgbtns/copa.png"
};
const char *archivosFonts[TOTAL_FONTS] = {
	"ttf/leven/reg.ttf",
	"ttf/maderita.ttf",
	"ttf/bomba.TTF",
	"ttf/orangejuice.ttf",
	"ttf/Pacifico.ttf",
	"ttf/orangejuice.ttf"

};

VentanaPartida::VentanaPartida()
{
	memset(&secuencias,0,sizeof(secuencias));
	
	//int i = 0;
	cout<<"Aqui estas";
	nombreJugador = "";
	nombreOponente = "";
	memset(&secuencias, 0, sizeof(secuencias));
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


VentanaPartida::VentanaPartida(string nombreJ, string nombreO, int secs[][COLUMNAS_MAXIMAS])
{
	cout<<"estas en ventanaPartida despues del for:"<<endl;
  	numeroFila = 0;
  	numeroColumna = 0;
    vidas = 3;
    secuenciasCorrectas = 0;
	 if(TTF_Init()==-1) {
	   cout<<"Error_Init()";
	}
	cout<<"Estas despues TTF_INIT!"<<endl;
    if(!inicializar())
	{
		perror("Error en Inicializar()");
	}
	else
	{
		cout<<"Estas despues de else inicializar!"<<endl;
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
	ventanaJuego = NULL;
	ventanaIniciar = NULL;
	ventanaPrincipal = NULL;
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

		/*
		* Creamos la venta Juego y su render correspondiente
		*/
		ventanaJuego = SDL_CreateWindow("Ventana Sigue al lider (Juego)", VENTANAPOS_X,VENTANAPOS_Y,ANCHO_PANTALLA_PART,ALTO_PANTALLA_PART,SDL_WINDOW_SHOWN);
		cout<<"valor de ventana:"<<((void*)ventanaJuego)<<endl;
		//cout<<"Estas dentro de inicializar 2!"<<endl;
		if(ventanaJuego==0){
			cout<<"au revoir"<<endl;
			SDL_GetError();
		}
		ventanaJuegoRender = SDL_CreateRenderer(ventanaJuego,-1,SDL_RENDERER_ACCELERATED);
		if(ventanaJuegoRender==NULL){
			cout<<"au revoir"<<endl;
			SDL_GetError();
		}
		cout<<"Estas dentro de inicializar 3!"<<endl;
		
		/*
		* Verificamos que ninguna ventana sea NULL o su render 
		*/
		if(ventanaJuego == NULL)
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

		}		
	}

	colorNegro.r = 0;
	colorNegro.g = 0;
	colorNegro.b = 0;
	colorNegro.a = 255;
	
	posicionIMGS[POSICION_TITULO].x = 161;
	posicionIMGS[POSICION_TITULO].y = 10;
	posicionIMGS[POSICION_TITULO].w = 270;
	posicionIMGS[POSICION_TITULO].h = 100;

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


	posicionIMGS[POSICION_SECUENCIAS_BUENAS].x = 260;
	posicionIMGS[POSICION_SECUENCIAS_BUENAS].y = 50;
	
	posicionIMGS[POSICION_OPONENTE].x = 450;
	posicionIMGS[POSICION_OPONENTE].y = 5;


	posicionIMGS[POSICION_FONDO_NOMBRE].x = 10;
	posicionIMGS[POSICION_FONDO_NOMBRE].y = 5;
	posicionIMGS[POSICION_FONDO_NOMBRE].w = 250;
	posicionIMGS[POSICION_FONDO_NOMBRE].h = 40;
	
	posicionIMGS[POSICION_FONDO_SECUENCIAS_BUENAS].x = 250;
	posicionIMGS[POSICION_FONDO_SECUENCIAS_BUENAS].y = 50;
	posicionIMGS[POSICION_FONDO_SECUENCIAS_BUENAS].w = 130;
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

	posicionIMGS[POSICION_BOTON_INICIAR_PARTIDA].x = 192;
	posicionIMGS[POSICION_BOTON_INICIAR_PARTIDA].y = 116;
	posicionIMGS[POSICION_BOTON_INICIAR_PARTIDA].w = 250;
	posicionIMGS[POSICION_BOTON_INICIAR_PARTIDA].h = 100;

	
	posicionIMGS[POSICION_BOTON_INICIAR_PARTIDA_PRESIONADO].x = 192;
	posicionIMGS[POSICION_BOTON_INICIAR_PARTIDA_PRESIONADO].y = 116;
	posicionIMGS[POSICION_BOTON_INICIAR_PARTIDA_PRESIONADO].w = 250;
	posicionIMGS[POSICION_BOTON_INICIAR_PARTIDA_PRESIONADO].h = 100;


	posicionIMGS[POSICION_BOTON_HISTORIAL].x = 192;
	posicionIMGS[POSICION_BOTON_HISTORIAL].y = 213;
	posicionIMGS[POSICION_BOTON_HISTORIAL].w = 250;
	posicionIMGS[POSICION_BOTON_HISTORIAL].h = 100;

	
	posicionIMGS[POSICION_BOTON_HISTORIAL_PRESIONADO].x = 192;
	posicionIMGS[POSICION_BOTON_HISTORIAL_PRESIONADO].y = 213;
	posicionIMGS[POSICION_BOTON_HISTORIAL_PRESIONADO].w = 250;
	posicionIMGS[POSICION_BOTON_HISTORIAL_PRESIONADO].h = 100;

	posicionIMGS[POSICION_BOTON_MEJOR_PUNTUACION].x = 192;
	posicionIMGS[POSICION_BOTON_MEJOR_PUNTUACION].y = 310;
	posicionIMGS[POSICION_BOTON_MEJOR_PUNTUACION].w = 250;
	posicionIMGS[POSICION_BOTON_MEJOR_PUNTUACION].h = 100;

	posicionIMGS[POSICION_BOTON_MEJOR_PUNTUACION_PRESIONADO].x = 192;
	posicionIMGS[POSICION_BOTON_MEJOR_PUNTUACION_PRESIONADO].y = 310;
	posicionIMGS[POSICION_BOTON_MEJOR_PUNTUACION_PRESIONADO].w = 250;
	posicionIMGS[POSICION_BOTON_MEJOR_PUNTUACION_PRESIONADO].h = 100;

	posicionIMGS[POSICION_INGRESA_IP].x=40;
	posicionIMGS[POSICION_INGRESA_IP].y = 250;

	posicionIMGS[POSICION_INGRESA_PUERTO].x=40;
	posicionIMGS[POSICION_INGRESA_PUERTO].y = 300;
	
	posicionIMGS[POSICION_INSTRUCCION_NOMBRE].x=130;
	posicionIMGS[POSICION_INSTRUCCION_NOMBRE].y = 110;

	posicionIMGS[POSICION_NOMBRE_INGRESADO].x = 200;
	posicionIMGS[POSICION_NOMBRE_INGRESADO].y = 210;
	

	posicionIMGS[POSICION_LINEA].x = 150;
	posicionIMGS[POSICION_LINEA].y = 250;
	posicionIMGS[POSICION_LINEA].w = 320;
	posicionIMGS[POSICION_LINEA].h = 10;
	

	posicionIMGS[POSICION_BOTON_CONECTAR].x = 160;
	posicionIMGS[POSICION_BOTON_CONECTAR].y = 350;
	posicionIMGS[POSICION_BOTON_CONECTAR].w = 250;
	posicionIMGS[POSICION_BOTON_CONECTAR].h = 100;

	posicionIMGS[POSICION_GANADOR].x=260;
	posicionIMGS[POSICION_GANADOR].y=60;

	posicionIMGS[POSICION_PUNTAJE_GANADOR].x=260;
	posicionIMGS[POSICION_PUNTAJE_GANADOR].y=120;
	
	posicionIMGS[POSICION_MOTIVO_ESPERANDO].x=5;
	posicionIMGS[POSICION_MOTIVO_ESPERANDO].y=10;

	posicionIMGS[POSICION_COPA].x=20;
	posicionIMGS[POSICION_COPA].y=20;
	posicionIMGS[POSICION_COPA].w = 250;
	posicionIMGS[POSICION_COPA].h = 100;


	
	


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
		imagenPNG[i] = cargarDifFormat(archivo, ventanaJuegoRender);
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
	SDL_DestroyRenderer(ventanaJuegoRender);
	SDL_DestroyRenderer(ventanaPrincipalRender);
	SDL_DestroyRenderer(ventanaIniciarRender);
	SDL_DestroyWindow(ventanaJuego);
	SDL_DestroyWindow(ventanaIniciar);
	SDL_DestroyWindow(ventanaPrincipal);

	ventanaJuegoRender = NULL;
	ventanaIniciarRender = NULL;
	ventanaPrincipalRender = NULL;

	ventanaJuego = NULL;
	ventanaIniciar = NULL;
	ventanaPrincipal = NULL;
	SDL_Quit();
	IMG_Quit();
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

void VentanaPartida::pintarVentanaJuego()
{	 
	pintadoActual=2;
	//TTF_Font *font2=TTF_OpenFont("ttf/leven/reg.ttf",50);
	//TTF_Font *font3=TTF_OpenFont("ttf/maderita.ttf",30);	
	/*Se pinta el background ademas de el nombre de jugador*/
	
	SDL_RenderCopy(ventanaJuegoRender,imagenPNG[FONDO],NULL,NULL);
	SDL_RenderCopy(ventanaJuegoRender,imagenPNG[FONDO_NOMBRE],NULL,&posicionIMGS[POSICION_FONDO_NOMBRE]);
	SDL_RenderCopy(ventanaJuegoRender,imagenPNG[FONDO_OPONENTE],NULL,&posicionIMGS[POSICION_FONDO_OPONENTE]);
	SDL_RenderCopy(ventanaJuegoRender,imagenPNG[FONDO_SECUENCIAS_BUENAS],NULL,&posicionIMGS[POSICION_FONDO_SECUENCIAS_BUENAS]);
    cout<<"pintarventanajuego1;"<<endl;
	//SDL_Surface *surface = TTF_RenderText_Solid(font2,"Alexis Miguel", color2);
	//SDL_Texture *text2 = SDL_CreateTextureFromSurface(ventanaRender,surface);
	//cout<<"valor de font:"<<((void*)font[FONT_LEVEN])<<endl;
	cout<<"valor de font:"<<((void*)font[FONT_MADERITA])<<endl;
	
	textSurfaces[TEXTO_OPONENTE] = TTF_RenderText_Solid(font[FONT_MADERITA],nombreOponente.c_str(), colorNegro);
	cout<<"pintarventanajuego2;"<<endl;
	textSurfaces[TEXTO_NOMBRE] = TTF_RenderText_Solid(font[FONT_MADERITA],nombreJugador.c_str(), colorNegro);
	cout<<"pintarventanajuego2;"<<endl;
	textSurfaces[TEXTO_SECUENCIAS_BUENAS] = TTF_RenderText_Solid(font[FONT_ORANGE_JUICE],"S# 0", colorNegro);
	cout<<"pintarventanajuego2;"<<endl;
	textures[TEXTO_NOMBRE] = SDL_CreateTextureFromSurface(ventanaJuegoRender,textSurfaces[TEXTO_NOMBRE]);
	textures[TEXTO_OPONENTE] = SDL_CreateTextureFromSurface(ventanaJuegoRender,textSurfaces[TEXTO_OPONENTE]);
	textures[TEXTO_SECUENCIAS_BUENAS] = SDL_CreateTextureFromSurface(ventanaJuegoRender,textSurfaces[TEXTO_SECUENCIAS_BUENAS]);
	cout<<"pintarventanajuego3;"<<endl;
	//SDL_QueryTexture(textJugador,0,0,&posicionIMGS[TITULO].w,&posicionIMGS[TITULO].h);
	//SDL_RenderCopy(ventanaRender,textJugador,NULL,&posicionIMGS[TITULO]);	

	SDL_QueryTexture(textures[TEXTO_OPONENTE],0,0,&posicionIMGS[POSICION_OPONENTE].w,&posicionIMGS[POSICION_OPONENTE].h);
	SDL_RenderCopy(ventanaJuegoRender,textures[TEXTO_OPONENTE],NULL,&posicionIMGS[POSICION_OPONENTE]);	

	SDL_QueryTexture(textures[TEXTO_NOMBRE],0,0,&posicionIMGS[POSICION_NOMBRE].w,&posicionIMGS[POSICION_NOMBRE].h);
	SDL_RenderCopy(ventanaJuegoRender,textures[TEXTO_NOMBRE],NULL,&posicionIMGS[POSICION_NOMBRE]);

	SDL_QueryTexture(textures[TEXTO_SECUENCIAS_BUENAS],0,0,&posicionIMGS[POSICION_SECUENCIAS_BUENAS].w,&posicionIMGS[POSICION_SECUENCIAS_BUENAS].h);
	SDL_RenderCopy(ventanaJuegoRender,textures[TEXTO_SECUENCIAS_BUENAS],NULL,&posicionIMGS[POSICION_SECUENCIAS_BUENAS]);
	cout<<"pintarventanajuego4;"<<endl;
	pintarVidasRestantes(vidas);
	cout<<"pintarventanajuego5;"<<endl;
}

void VentanaPartida::pintarBoton(int aPintar)
{
	switch(aPintar)
	{
		case BTN1:
			SDL_RenderCopy(ventanaJuegoRender,imagenPNG[BTN1],NULL,&posicionIMGS[BTN1]);
			break;
		case BTN2:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[BTN2],NULL,&posicionIMGS[BTN2]);
			break;
		case BTN3:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[BTN3],NULL,&posicionIMGS[BTN3]);
		break;
		case BTN4:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[BTN4],NULL,&posicionIMGS[BTN4]);
		break;
		case BTN5:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[BTN5],NULL,&posicionIMGS[BTN5]);
		break;
		case BTN6:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[BTN6],NULL,&posicionIMGS[BTN6]);
		break;
		case BTN7:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[BTN7],NULL,&posicionIMGS[BTN7]);
		break;
		case BTN8:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[BTN8],NULL,&posicionIMGS[BTN8]);
		break;
		case BTN9:
			//cout<<"holaquemira"<<endl;
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[BTN9],NULL,&posicionIMGS[BTN9]);
		break;
	}
	SDL_RenderPresent( ventanaJuegoRender);
}

void VentanaPartida::mostrarSecuencia(int fila)
{
	componentesCorrecto=0;
	numeroColumna=0;
	int numeroEnSecuencia = 0;
	int contador = 0;
	cout<<"Entraste en mostrar secuencias\n\n\n";
	while(1){
		if(secuencias[fila][contador]!=0)
		{
			pintarBoton(secuencias[fila][contador]);
			SDL_Delay(700);
			contador++;
		}else
		{
			break;
		}
	}
	componentesEnSecuencia[fila] = contador;

	cout<<"mostrarSecuencia() componentesEnSecuencia:"<<contador<<endl;
}

void VentanaPartida::pintarRespuestaCorrecta(int aPintar){
	switch(aPintar)
	{
		case BTN1:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[CORRECTA],NULL,&posicionIMGS[BTN1]);
			break;
		case BTN2:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[CORRECTA],NULL,&posicionIMGS[BTN2]);
			break;
		case BTN3:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[CORRECTA],NULL,&posicionIMGS[BTN3]);
		break;
		case BTN4:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[CORRECTA],NULL,&posicionIMGS[BTN4]);
		break;
		case BTN5:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[CORRECTA],NULL,&posicionIMGS[BTN5]);
		break;
		case BTN6:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[CORRECTA],NULL,&posicionIMGS[BTN6]);
		break;
		case BTN7:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[CORRECTA],NULL,&posicionIMGS[BTN7]);
		break;
		case BTN8:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[CORRECTA],NULL,&posicionIMGS[BTN8]);
		break;
		case BTN9:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[CORRECTA],NULL,&posicionIMGS[BTN9]);
		break;
	}
	SDL_RenderPresent( ventanaJuegoRender);
}

void VentanaPartida::pintarRespuestaIncorrecta(int aPintar){
	switch(aPintar)
	{
		case BTN1:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[ERROR],NULL,&posicionIMGS[BTN1]);
			break;
		case BTN2:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[ERROR],NULL,&posicionIMGS[BTN2]);
			break;
		case BTN3:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[ERROR],NULL,&posicionIMGS[BTN3]);
		break;
		case BTN4:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[ERROR],NULL,&posicionIMGS[BTN4]);
		break;
		case BTN5:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[ERROR],NULL,&posicionIMGS[BTN5]);
		break;
		case BTN6:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[ERROR],NULL,&posicionIMGS[BTN6]);
		break;
		case BTN7:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[ERROR],NULL,&posicionIMGS[BTN7]);
		break;
		case BTN8:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[ERROR],NULL,&posicionIMGS[BTN8]);
		break;
		case BTN9:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[ERROR],NULL,&posicionIMGS[BTN9]);
		break;
	}
	SDL_RenderPresent( ventanaJuegoRender);
	SDL_Delay(200);
}

bool VentanaPartida::cargarFuentes()
{
	bool exito=true;
	cout<<"Ejecuto:cargarFuentes";
	//SDL_RenderClear( ventanaJuegoRender);
	for (int i = 0; i < TOTAL_FONTS; ++i)
	{
		if(i==FONT_MADERITA)
		{
			font[i] = TTF_OpenFont(archivosFonts[i],30);
		}else if(i==FONT_ORANGE_JUICE_PEQUE)
		{
			font[i] = TTF_OpenFont(archivosFonts[i],25);
		}else
		{
			font[i] = TTF_OpenFont(archivosFonts[i],50);	
		}
		
		if(font[i] == NULL)
		{
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
	textures[TEXTO_SECUENCIAS_BUENAS] = SDL_CreateTextureFromSurface( ventanaJuegoRender,textSurfaces[TEXTO_SECUENCIAS_BUENAS]);
	SDL_RenderCopy( ventanaJuegoRender,imagenPNG[FONDO_SECUENCIAS_BUENAS],NULL,&posicionIMGS[FONDO_SECUENCIAS_BUENAS]);
	SDL_QueryTexture(textures[TEXTO_SECUENCIAS_BUENAS],0,0,&posicionIMGS[POSICION_SECUENCIAS_BUENAS].w,&posicionIMGS[POSICION_SECUENCIAS_BUENAS].h);
	SDL_RenderCopy( ventanaJuegoRender,textures[TEXTO_SECUENCIAS_BUENAS],NULL,&posicionIMGS[POSICION_SECUENCIAS_BUENAS]);
	SDL_RenderPresent( ventanaJuegoRender);
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
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[VIDAS_1],NULL,&posicionIMGS[POSICION_VIDAS]);
			SDL_RenderPresent( ventanaJuegoRender);
			break;
		case 2:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[VIDAS_2],NULL,&posicionIMGS[POSICION_VIDAS]);
			SDL_RenderPresent( ventanaJuegoRender);
			break;
		case 3:
			SDL_RenderCopy( ventanaJuegoRender,imagenPNG[VIDAS_3],NULL,&posicionIMGS[POSICION_VIDAS]);
			SDL_RenderPresent( ventanaJuegoRender);
			break;
	}
	cout<<"Salir de pintarVidasRestantes()\n";
}

void VentanaPartida::repintarVentanaJuego()
{	    
	
	SDL_RenderCopy( ventanaJuegoRender,imagenPNG[FONDO],NULL,NULL);
	SDL_RenderCopy( ventanaJuegoRender,imagenPNG[FONDO_NOMBRE],NULL,&posicionIMGS[POSICION_FONDO_NOMBRE]);
	SDL_RenderCopy( ventanaJuegoRender,imagenPNG[FONDO_OPONENTE],NULL,&posicionIMGS[POSICION_FONDO_OPONENTE]);
	SDL_RenderCopy( ventanaJuegoRender,imagenPNG[FONDO_SECUENCIAS_BUENAS],NULL,&posicionIMGS[POSICION_FONDO_SECUENCIAS_BUENAS]);

	cout<<"valor de font:"<<((void*)font[FONT_LEVEN])<<endl;
	cout<<"valor de font:"<<((void*)font[FONT_MADERITA])<<endl;
	textSurfaces[TEXTO_OPONENTE] = TTF_RenderText_Solid(font[FONT_MADERITA],nombreOponente.c_str(), colorNegro);
	textSurfaces[TEXTO_NOMBRE] = TTF_RenderText_Solid(font[FONT_MADERITA],nombreJugador.c_str(), colorNegro);
	
	textures[TEXTO_NOMBRE] = SDL_CreateTextureFromSurface( ventanaJuegoRender,textSurfaces[TEXTO_NOMBRE]);
	textures[TEXTO_OPONENTE] = SDL_CreateTextureFromSurface( ventanaJuegoRender,textSurfaces[TEXTO_OPONENTE]);
	
	SDL_QueryTexture(textures[TEXTO_OPONENTE],0,0,&posicionIMGS[POSICION_OPONENTE].w,&posicionIMGS[POSICION_OPONENTE].h);
	SDL_RenderCopy( ventanaJuegoRender,textures[TEXTO_OPONENTE],NULL,&posicionIMGS[POSICION_OPONENTE]);	
	SDL_QueryTexture(textures[TEXTO_NOMBRE],0,0,&posicionIMGS[POSICION_NOMBRE].w,&posicionIMGS[POSICION_NOMBRE].h);
	SDL_RenderCopy( ventanaJuegoRender,textures[TEXTO_NOMBRE],NULL,&posicionIMGS[POSICION_NOMBRE]);

	SDL_QueryTexture(textures[TEXTO_SECUENCIAS_BUENAS],0,0,&posicionIMGS[POSICION_SECUENCIAS_BUENAS].w,&posicionIMGS[POSICION_SECUENCIAS_BUENAS].h);
	SDL_RenderCopy( ventanaJuegoRender,textures[TEXTO_SECUENCIAS_BUENAS],NULL,&posicionIMGS[POSICION_SECUENCIAS_BUENAS]);
	pintarVidasRestantes(vidas);
	pintarSecuenciasBuenas(secuenciasCorrectas);
}

void VentanaPartida::obtenerNombreDeJugador(){
	
}

void VentanaPartida::obtenerNombreDeOponente(){
	
}

void VentanaPartida::pintarVentanaIniciar()
{	    
	pintadoActual=0;
	
	SDL_RenderClear(ventanaJuegoRender);
	SDL_RenderCopy(ventanaJuegoRender,imagenPNG[FONDO_BLANCO],NULL,NULL);
	SDL_RenderCopy(ventanaJuegoRender,imagenPNG[TITULO],NULL,&posicionIMGS[POSICION_TITULO]);
	SDL_RenderCopy(ventanaJuegoRender,imagenPNG[BOTON_INICIAR_PARTIDA],NULL,&posicionIMGS[POSICION_BOTON_INICIAR_PARTIDA]);
	SDL_RenderCopy(ventanaJuegoRender,imagenPNG[BOTON_HISTORIAL],NULL,&posicionIMGS[POSICION_BOTON_HISTORIAL]);
	SDL_RenderCopy(ventanaJuegoRender,imagenPNG[BOTON_MEJOR_PUNTUACION],NULL,&posicionIMGS[POSICION_BOTON_MEJOR_PUNTUACION]);
	SDL_RenderPresent(ventanaJuegoRender);
    
}
void VentanaPartida::pintarVentanaResultados()
{	    
	
    
	SDL_RenderClear(ventanaJuegoRender);
	SDL_RenderCopy(ventanaJuegoRender,imagenPNG[FONDO_BLANCO],NULL,NULL);
	
	textSurfaces[TEXTO_GANADOR] = TTF_RenderText_Solid(font[FONT_ORANGE_JUICE],nombreGanador.c_str(), colorNegro);
	textures[TEXTO_GANADOR] = SDL_CreateTextureFromSurface( ventanaJuegoRender,textSurfaces[TEXTO_GANADOR]);
	SDL_QueryTexture(textures[TEXTO_GANADOR],0,0,&posicionIMGS[POSICION_GANADOR].w,&posicionIMGS[POSICION_GANADOR].h);
	SDL_RenderCopy( ventanaJuegoRender,textures[TEXTO_GANADOR],NULL,&posicionIMGS[POSICION_GANADOR]);	

	stringstream formateado;
	formateado<<puntajeGanador;
	string stringPuntaje;
	stringPuntaje = formateado.str();

	textSurfaces[TEXTO_PUNTAJE_GANADOR] = TTF_RenderText_Solid(font[FONT_ORANGE_JUICE],stringPuntaje.c_str(), colorNegro);
	textures[TEXTO_PUNTAJE_GANADOR] = SDL_CreateTextureFromSurface( ventanaJuegoRender,textSurfaces[TEXTO_GANADOR]);
	SDL_QueryTexture(textures[TEXTO_PUNTAJE_GANADOR],0,0,&posicionIMGS[POSICION_PUNTAJE_GANADOR].w,&posicionIMGS[POSICION_PUNTAJE_GANADOR].h);
	SDL_RenderCopy( ventanaJuegoRender,textures[TEXTO_PUNTAJE_GANADOR],NULL,&posicionIMGS[POSICION_PUNTAJE_GANADOR]);	

	SDL_RenderPresent(ventanaJuegoRender);
}

void VentanaPartida::mostrarVentanaIniciar()
{
	
	string cadena;
	cadena="";
	int opcionDeEscritura = 0;
	bool quiereSalir = false;
	SDL_Event e;	
	pintarVentanaIniciar();
	while(!quiereSalir)
	{
		while(SDL_PollEvent(&e)!=0)
		{
			/*Iniciar*/
			if(pintadoActual==0)
			{
				if(e.type == SDL_QUIT)
				{
					quiereSalir = true;
				}
				if(e.motion.x>195 && e.motion.x<449 && e.motion.y>116 && e.motion.y<177 )
				{
					pintarVentanaIniciar();
					SDL_RenderCopy(ventanaJuegoRender,imagenPNG[BOTON_INICIAR_PARTIDA_PRESIONADO],NULL,&posicionIMGS[POSICION_BOTON_INICIAR_PARTIDA_PRESIONADO]);
					SDL_RenderPresent(ventanaJuegoRender);
					
				}else
				if(e.motion.x>195 && e.motion.x<449 && e.motion.y>213 && e.motion.y<277 )
				{
					pintarVentanaIniciar();
					SDL_RenderCopy(ventanaJuegoRender,imagenPNG[BOTON_HISTORIAL_PRESIONADO],NULL,&posicionIMGS[POSICION_BOTON_HISTORIAL_PRESIONADO]);
					SDL_RenderPresent(ventanaJuegoRender);
				}else
				if(e.motion.x>195 && e.motion.x<449 && e.motion.y>310 && e.motion.y< 377 )
				{
					pintarVentanaIniciar();
					SDL_RenderCopy(ventanaJuegoRender,imagenPNG[BOTON_MEJOR_PUNTUACION_PRESIONADO],NULL,&posicionIMGS[POSICION_BOTON_MEJOR_PUNTUACION_PRESIONADO]);
					SDL_RenderPresent(ventanaJuegoRender);
				}else{
					pintarVentanaIniciar();
				}
				if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x>195 && e.motion.x<449 && e.motion.y>116 && e.motion.y<177 )
				{
					pintarVentanaPrincipal();
				}
				if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x>195 && e.motion.x<449 && e.motion.y>213 && e.motion.y<277 )
				{
					cerrar();
					system("./Historial");

				}
			}

			/*Fin de Iniciar*/			
			/*Principal*/
			if(pintadoActual==1)
			{
				switch(e.type)
				{
					case SDL_QUIT:

					break;

					case SDL_KEYDOWN:
						if(opcionDeEscritura==0)
						{
							cout<<"Presionastes algo"<<endl;
							switch(e.key.keysym.sym)
							{
								case SDLK_a:
									cout<<"a";
									cadena+="a";
								break;
								case SDLK_b:
									cout<<"b";
									cadena+="b";
								break;
								case SDLK_c:
									cout<<"c";
									cadena+="c";
								break;
								case SDLK_d:
									cout<<"d";
									cadena+="d";
								break;
								case SDLK_e:
									cout<<"e";
									cadena+="e";
								break;
								case SDLK_f:
									cout<<"f";
									cadena+="f";
								break;
								case SDLK_g:
									cout<<"g";
									cadena+="g";					
								break;
								case SDLK_h:
								cout<<"h";
									cadena+="h";
								break;
								case SDLK_i:
								cout<<"i";
									cadena+="i";
								break;
								case SDLK_j:
								cout<<"j";
									cadena+="j";
								break;
								case SDLK_k:
								cout<<"k";
									cadena+="k";
								break;
								case SDLK_l:
								cout<<"l";
									cadena+="l";
								break;
								case SDLK_m:
								cout<<"m";
									cadena+="m";
								break;
								case SDLK_n:
								cout<<"n";
									cadena+="n";
								break;
								case SDLK_o:
								cout<<"o";
									cadena+="o";
								break;
								case SDLK_p:
								cout<<"p";
									cadena+="p";
								break;
								case SDLK_q:
								cout<<"q";
									cadena+="q";
								break;
								case SDLK_r:
								cout<<"r";
									cadena+="r";
								break;
								case SDLK_s:
								cout<<"s";
									cadena+="s";
								break;
								case SDLK_t:
								cout<<"t";
									cadena+="t";
								break;
								case SDLK_u:
								cout<<"u";
									cadena+="u";
								break;
								case SDLK_v:
								cout<<"v";
									cadena+="v";
								break;
								case SDLK_w:
								cout<<"w";
									cadena+="w";
								break;
								case SDLK_x:
								cout<<"x";
									cadena+="x";
								break;
								case SDLK_y:
								cout<<"y";
									cadena+="y";
								break;
								case SDLK_z:
								cout<<"z";
									cadena+="z";
								break;
								case SDLK_BACKSPACE:
									cout<<"seRegreso\n\n";
									cadena = cadena.substr(0,cadena.length()-1);
								break;
								case SDLK_RETURN:
									opcionDeEscritura++;
									cout<<"PresionasteEnter\n";
									cadena = "";
									break;

							}
							if(opcionDeEscritura==0){
							nombreJugador = cadena;
							pintarVentanaPrincipal();	
							}
							
						}else if(opcionDeEscritura == 1)//ip
						{
							cout<<"Presionastes algo para tu IP"<<endl;
							switch(e.key.keysym.sym)
							{
								case SDLK_PERIOD:
									cout<<".";
									cadena+=".";
								break;
								case SDLK_0:
									cout<<"0";
									cadena+="0";
								break;
								case SDLK_1:
									cout<<"1";
									cadena+="1";
								break;
								case SDLK_2:
									cout<<"2";
									cadena+="2";
								break;
								case SDLK_3:
									cout<<"3";
									cadena+="3";
								break;
								case SDLK_4:
									cout<<"4";
									cadena+="4";
								break;
								case SDLK_5:
									cout<<"5";
									cadena+="5";					
								break;
								case SDLK_6:
								cout<<"6";
									cadena+="6";
								break;
								case SDLK_7:
								cout<<"7";
									cadena+="7";
								break;
								case SDLK_8:
								cout<<"8";
									cadena+="8";
								break;
								case SDLK_9:
								cout<<"9";
									cadena+="9";
								break;
								case SDLK_BACKSPACE:
									cout<<"seRegreso\n\n";
									cadena = cadena.substr(0,cadena.length()-1);
								break;
								case SDLK_RETURN:
									opcionDeEscritura++;		
									cout<<"PresionasteEnter\n";
									cadena="";
								break;					
							}
							if(opcionDeEscritura==1)
							{
							ip_ingresada = cadena;
							pintarVentanaPrincipal();	
							}
						}else if(opcionDeEscritura == 2)//puerto
						{
							cout<<"Presionastes algo para tu Puerto"<<endl;
							switch(e.key.keysym.sym)
							{
								case SDLK_PERIOD:
									cout<<".";
									cadena+=".";
								break;
								case SDLK_0:
									cout<<"0";
									cadena+="0";
								break;
								case SDLK_1:
									cout<<"1";
									cadena+="1";
								break;
								case SDLK_2:
									cout<<"2";
									cadena+="2";
								break;
								case SDLK_3:
									cout<<"3";
									cadena+="3";
								break;
								case SDLK_4:
									cout<<"4";
									cadena+="4";
								break;
								case SDLK_5:
									cout<<"5";
									cadena+="5";					
								break;
								case SDLK_6:
								cout<<"6";
									cadena+="6";
								break;
								case SDLK_7:
								cout<<"7";
									cadena+="7";
								break;
								case SDLK_8:
								cout<<"8";
									cadena+="8";
								break;
								case SDLK_9:
								cout<<"9";
									cadena+="9";
								break;		
								case SDLK_BACKSPACE:
									cout<<"seRegreso";
									cadena = cadena.substr(0,cadena.length()-1);
								break;
								case SDLK_RETURN:
									opcionDeEscritura++;
									puerto = atoi(cadena.c_str());
									cadena="";
								break;					
							}
							if(opcionDeEscritura==2){
							cadena_puerto=cadena;
							pintarVentanaPrincipal();	
							}
							if(opcionDeEscritura==3)
							{
								pintarVentanaEsperar(1);
								if(mandarBCC()<0)
								{
									quiereSalir=true;
								}else
								{
									pintadoActual=2;
									
									vidas=3;
									cout<<vidas<<endl;
									componentesCorrecto = 0;
									numeroFila=0;
									numeroColumna=0;
									pintarVentanaJuego();
									mostrarSecuencia(numeroFila);
									pintarVidasRestantes(vidas);
								}
							}
						}

					break;
				}

				if(e.type == SDL_QUIT)
				{
					quiereSalir = true;
				
				}
			}
			/*Fin de Principal*/

			/*Inicio de Jugar*/
			if(pintadoActual==2)
			{
				switch(e.type)
				{
					case SDL_QUIT:
						quiereSalir = true;
						cout<<"Presiono quit\n";
						cerrar();
						cout<<quiereSalir<<endl;
						break;
					case SDL_KEYDOWN:
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
						            repintarVentanaJuego();
									mostrarSecuencia(numeroFila);
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
									numeroFila++;
									repintarVentanaJuego();
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
									numeroFila++;
									pintarVidasRestantes(vidas);
									 //SDL_Delay(2000);
									repintarVentanaJuego();
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
									numeroFila++;
									pintarVidasRestantes(vidas);
									 //SDL_Delay(2000);
									repintarVentanaJuego();
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
									numeroFila++;
									pintarVidasRestantes(vidas);
									 //SDL_Delay(2000);
									repintarVentanaJuego();
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
									numeroFila++;
									pintarVidasRestantes(vidas);
									 //SDL_Delay(2000);
									repintarVentanaJuego();
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
									numeroFila++;
									pintarVidasRestantes(vidas);
									 //SDL_Delay(2000);
									repintarVentanaJuego();
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
									numeroFila++;
									pintarVidasRestantes(vidas);
									 //SDL_Delay(2000);
									repintarVentanaJuego();
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
									numeroFila++;
									pintarVidasRestantes(vidas);
									 //SDL_Delay(2000);
									repintarVentanaJuego();
									mostrarSecuencia(numeroFila);
								}
							break;
						}
					if(vidas==0 ||secuenciasCorrectas==SECUENCIAS_MAXIMAS-1)
					{
						cout<<"secuenciasCorrectas Sin vidas="<<secuenciasCorrectas<<endl;
						cout<<"Tus vidas se acabaron";
						pintadoActual=4;
						pintarVentanaEsperar(2);
						if(mandarBSB()>0)
						{
							pintadoActual=5;
							pintarVentanaResultados();
						};//
					}
					
					if(componentesCorrecto == componentesEnSecuencia[numeroFila])
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
						repintarVentanaJuego();
						pintarSecuenciasBuenas(secuenciasCorrectas);
						numeroFila++;	
						mostrarSecuencia(numeroFila);
					}

				}
				
			}
			if(pintadoActual==4)
			{
				switch(e.type)
				{
					case SDL_QUIT:
					cerrar();
					break;
				}

			}
			if(pintadoActual==5)
			{
				switch(e.type)
				{
					case SDL_QUIT:
					cerrar();
					break;
					case SDL_KEYDOWN:
						string cadena;
						cadena="";
						int opcionDeEscritura = 0;
						bool quiereSalir = false;
						SDL_Event e;
						pintarVentanaIniciar();
					break;
				}

			}
		}
		/*Fin de Jugar*/
	}
}


void VentanaPartida::pintarVentanaPrincipal()
{	    
	/*Se pinta el background ademas de el nombre de jugador*/
	pintadoActual=1;
	SDL_RenderClear(ventanaJuegoRender);
	textSurfaces[TEXTO_INGRESO] = TTF_RenderText_Solid(font[FONT_PACIFICO],"Ingresa tu nombre:", colorNegro);
	textures[TEXTO_INGRESO] = SDL_CreateTextureFromSurface( ventanaJuegoRender,textSurfaces[TEXTO_INGRESO]);
	SDL_QueryTexture(textures[TEXTO_INGRESO],0,0,&posicionIMGS[POSICION_INSTRUCCION_NOMBRE].w,&posicionIMGS[POSICION_INSTRUCCION_NOMBRE].h);
 	cout<<"Vamos en ip";
	textSurfaces[TEXTO_INGRESA_IP] = TTF_RenderText_Solid(font[FONT_PACIFICO],"IP:", colorNegro);
	textures[TEXTO_INGRESA_IP] = SDL_CreateTextureFromSurface( ventanaJuegoRender,textSurfaces[TEXTO_INGRESA_IP]);
	SDL_QueryTexture(textures[TEXTO_INGRESA_IP],0,0,&posicionIMGS[POSICION_INGRESA_IP].w,&posicionIMGS[POSICION_INGRESA_IP].h);
	cout<<"Vamos en puerto";	
	textSurfaces[TEXTO_INGRESA_PUERTO] = TTF_RenderText_Solid(font[FONT_PACIFICO],"Puerto:", colorNegro);
	textures[TEXTO_INGRESA_PUERTO] = SDL_CreateTextureFromSurface( ventanaJuegoRender,textSurfaces[TEXTO_INGRESA_PUERTO]);
	SDL_QueryTexture(textures[TEXTO_INGRESA_PUERTO],0,0,&posicionIMGS[POSICION_INGRESA_PUERTO].w,&posicionIMGS[POSICION_INGRESA_PUERTO].h);
	SDL_RenderCopy(ventanaJuegoRender,imagenPNG[FONDO_BLANCO],NULL,NULL);
	SDL_RenderCopy(ventanaJuegoRender,imagenPNG[TITULO],NULL,&posicionIMGS[POSICION_TITULO]);
	SDL_RenderCopy(ventanaJuegoRender,imagenPNG[LINEA],NULL,&posicionIMGS[POSICION_LINEA]);
	SDL_RenderCopy( ventanaJuegoRender,textures[TEXTO_INGRESO],NULL,&posicionIMGS[POSICION_INSTRUCCION_NOMBRE]);
	SDL_RenderCopy( ventanaJuegoRender,textures[TEXTO_INGRESA_IP],NULL,&posicionIMGS[POSICION_INGRESA_IP]);
	SDL_RenderCopy( ventanaJuegoRender,textures[TEXTO_INGRESA_PUERTO],NULL,&posicionIMGS[POSICION_INGRESA_PUERTO]);
	pintarNombreEnVentanaPrincipal();
	pintarIpIngresadaEnVentanaPrincipal();
	pintarPuertoIngresadoEnVentanaPrincipal();
	SDL_RenderPresent(ventanaJuegoRender);	
}


void VentanaPartida::pintarNombreEnVentanaPrincipal()
{	 

	cout<<"valor de font:"<<((void*)font[FONT_LEVEN])<<endl;
	cout<<"valor de font:"<<((void*)font[FONT_MADERITA])<<endl;
	textSurfaces[TEXTO_NOMBRE] = TTF_RenderText_Solid(font[FONT_ORANGE_JUICE],nombreJugador.c_str(), colorNegro);
	textures[TEXTO_NOMBRE] = SDL_CreateTextureFromSurface( ventanaJuegoRender,textSurfaces[TEXTO_NOMBRE]);
	SDL_QueryTexture(textures[TEXTO_NOMBRE],0,0,&posicionIMGS[POSICION_NOMBRE_INGRESADO].w,&posicionIMGS[POSICION_NOMBRE_INGRESADO].h);
	SDL_RenderCopy( ventanaJuegoRender,textures[TEXTO_NOMBRE],NULL,&posicionIMGS[POSICION_NOMBRE_INGRESADO]);	
	SDL_RenderPresent(ventanaJuegoRender);
	
}
void VentanaPartida::pintarIpIngresadaEnVentanaPrincipal()
{	    
	cout<<"valor de font:"<<((void*)font[FONT_LEVEN])<<endl;
	cout<<"valor de font:"<<((void*)font[FONT_MADERITA])<<endl;
    posicionIMGS[POSICION_IP].x=200;
    posicionIMGS[POSICION_IP].y=280;
	textSurfaces[TEXTO_IP] = TTF_RenderText_Solid(font[FONT_ORANGE_JUICE],ip_ingresada.c_str(), colorNegro);
	textures[TEXTO_IP] = SDL_CreateTextureFromSurface( ventanaJuegoRender,textSurfaces[TEXTO_IP]);
	SDL_QueryTexture(textures[TEXTO_IP],0,0,&posicionIMGS[POSICION_IP].w,&posicionIMGS[POSICION_IP].h);
	SDL_RenderCopy( ventanaJuegoRender,textures[TEXTO_IP],NULL,&posicionIMGS[POSICION_IP]);	
	SDL_RenderPresent(ventanaJuegoRender);
	
}
void VentanaPartida::pintarPuertoIngresadoEnVentanaPrincipal()
{	    
	posicionIMGS[POSICION_PUERTO].x=200;
    posicionIMGS[POSICION_PUERTO].y=340;	
	cout<<"valor de font:"<<((void*)font[FONT_LEVEN])<<endl;
	cout<<"valor de font:"<<((void*)font[FONT_MADERITA])<<endl;
	textSurfaces[TEXTO_PUERTO] = TTF_RenderText_Solid(font[FONT_ORANGE_JUICE],cadena_puerto.c_str(), colorNegro);
	textures[TEXTO_PUERTO] = SDL_CreateTextureFromSurface( ventanaJuegoRender,textSurfaces[TEXTO_PUERTO]);
	SDL_QueryTexture(textures[TEXTO_PUERTO],0,0,&posicionIMGS[POSICION_PUERTO].w,&posicionIMGS[POSICION_PUERTO].h);
	SDL_RenderCopy( ventanaJuegoRender,textures[TEXTO_PUERTO],NULL,&posicionIMGS[POSICION_PUERTO]);	
	SDL_RenderPresent(ventanaJuegoRender);
}
void VentanaPartida::pintarVentanaEsperar(int tipo)
{
	SDL_RenderClear(ventanaJuegoRender);
	SDL_RenderCopy(ventanaJuegoRender,imagenPNG[FONDO_ESPERANDO],NULL,NULL);
	cout<<"Tipo de esperar"<<tipo<<endl;
	switch(tipo)
	{
		case 1:
		textSurfaces[TEXTO_MOTIVO_ESPERANDO] = TTF_RenderText_Solid(font[FONT_ORANGE_JUICE_PEQUE],"Esperando secuencias y oponente...", colorNegro);
		textures[TEXTO_MOTIVO_ESPERANDO] = SDL_CreateTextureFromSurface( ventanaJuegoRender,textSurfaces[TEXTO_MOTIVO_ESPERANDO]);
		SDL_QueryTexture(textures[TEXTO_MOTIVO_ESPERANDO],0,0,&posicionIMGS[POSICION_MOTIVO_ESPERANDO].w,&posicionIMGS[POSICION_MOTIVO_ESPERANDO].h);
		SDL_RenderCopy( ventanaJuegoRender,textures[TEXTO_MOTIVO_ESPERANDO],NULL,&posicionIMGS[POSICION_MOTIVO_ESPERANDO]);	

		break;
		case 2:
		textSurfaces[TEXTO_MOTIVO_ESPERANDO] = TTF_RenderText_Solid(font[FONT_ORANGE_JUICE_PEQUE],"Esperando ganador...", colorNegro);
		textures[TEXTO_MOTIVO_ESPERANDO] = SDL_CreateTextureFromSurface( ventanaJuegoRender,textSurfaces[TEXTO_MOTIVO_ESPERANDO]);
		SDL_QueryTexture(textures[TEXTO_MOTIVO_ESPERANDO],0,0,&posicionIMGS[POSICION_MOTIVO_ESPERANDO].w,&posicionIMGS[POSICION_MOTIVO_ESPERANDO].h);
		SDL_RenderCopy( ventanaJuegoRender,textures[TEXTO_MOTIVO_ESPERANDO],NULL,&posicionIMGS[POSICION_MOTIVO_ESPERANDO]);	
		break;
	}

	
	
	SDL_RenderPresent(ventanaJuegoRender);

}

/*Funciones para conectar con el servidor y demas*/
int VentanaPartida::mandarBCC()
{
	int fd_socket;
	struct sockaddr_in cliente;
	struct sockaddr_in servidorAddr;
	int rc;
	char buffer[512],server[256];
	socklen_t add_size;
	add_size = sizeof cliente;
	strcpy(server,ip_ingresada.c_str());
	cout<<"IP ingresada"<<server<<endl;
	fd_socket = socket(AF_INET,SOCK_DGRAM,0);
	if(fd_socket < 0)
	{
		perror("Error en cuncion socket()");
		return -1;
	}
	

	inet_pton(AF_INET,server,&cliente.sin_addr.s_addr);
	cliente.sin_family=AF_INET;
	cliente.sin_port=htons (2432);

	memset(&buffer,0,sizeof(buffer));
	strcat(buffer,"AJR");//NombreProto
	strcat(buffer,"0");
	strcat(buffer,nombreJugador.c_str());
	for (int i = 0; i < (10-nombreJugador.length()); ++i)
	{
		strcat(buffer,"0");
	}
	strcat(buffer,"0");//secuencias buenas
	


	sendto (fd_socket, buffer, strlen(buffer), 0, (struct sockaddr *) &cliente, sizeof (cliente));
	
	rc=recvfrom(fd_socket,buffer, TAM_BUFFER, 0, (struct sockaddr *) &servidorAddr,&add_size);
	buffer[rc-1]='\0';
    if (rc<0)
    {
        perror("Error funcion recvfrom");
        return -1;
    }	
	  
	
    

    cout<<"Buffer recibido:"<<buffer<<endl;
    int status;
    status = verificar(buffer, fd_socket, &servidorAddr);    
    if(rc<0)
    {

        perror("Error funcion sendto");
        return -1;
    }
 
    if(fd_socket!=-1)
    {
        close(fd_socket);
    }
    return status;

}

int VentanaPartida::verificar(char *mensaje,int sd, struct sockaddr_in* servidorAddr)
{

	int exito = -1;
    cout<<"Este es el mensj"<<mensaje<<endl;
    cout<<"mensaje en pos 3:"<<mensaje[3]<<endl;
    /*
    *  AJR      -0-2      NombreProto
    *  #          -3      Bandera
    *  char*    -4-13     NombreJ
    *  #          -14     SucecionesBuenas
    *  int**      -15->    Secuencias 
    */
    char nombreProtocolo[3];
    char banderasEnMensaje;
    char nombreDeJugador[10];
    char sucesionesBuenas;
    char auxNombreOponente[10];

    strncpy(nombreProtocolo,mensaje,3);
    banderasEnMensaje=mensaje[3];
    
    sucesionesBuenas = mensaje[14];
    
    nombreDeJugador[10]='\0';
    cout<<"Nom:"<<nombreProtocolo<<endl;
    cout<<"banderasEnMensaje:"<<banderasEnMensaje<<endl;
    cout<<"nombreDeJugador:"<<nombreDeJugador<<endl;
    cout<<"sucesionesBuenas:"<<sucesionesBuenas<<endl;
    cout<<"mensaje:"<<mensaje<<endl;
    
   	int posicionActual=15;
   	int enteroDChar;

    switch(banderasEnMensaje)
    {
        case '0':    
            //Guardar la ip del que se conecto        
        break;
        case '1':
            //Ya tenemos jugador vas a JUGAR Las secuencias estan en el mensaje
        	strncpy(nombreDeJugador,&mensaje[4],10);
        	memset(&secuencias,0,sizeof(secuencias));
        	cout<<"NombreQue mandoServidor"<<nombreDeJugador<<endl;
        	cout << "Datos del server:\n" << mensaje << endl;
			cout<<"Secuencias obtenidas del servidor"<<endl;
			for (int i = 14; i < strlen(mensaje); ++i)
			{
				if (mensaje[i]=='\0')
				{
					break;
				}
				cout<<(int)mensaje[i]-'0'<<"#";
				cout<<mensaje[i]<<" ";
			}
			cout<<endl<<"Aqui se copian\n";
			posicionActual=14;

			for (int i = 0; i < SECUENCIAS_MAXIMAS; i++)
			{
				cout<<"fila"<<i<<":";
				for (int j = 0; j < COLUMNAS_MAXIMAS; j++)
				{
					
					if (mensaje[posicionActual]!='0')
					{
						
						enteroDChar=(int)mensaje[posicionActual]-'0';
						secuencias[i][j]=enteroDChar;
						cout<<secuencias[i][j]<<" ";	
						//cout<<(int)mensaje[posicionActual]-'0'<<" ";	
						posicionActual++;
					}


				}
				cout<<endl;
				posicionActual++;
			}
			posicionActual=0;

			for (int i = 0; i < 10; ++i)
			{
				if(nombreDeJugador[i]==48)
				{
					break;
				}
				else{
					cout<<"LetraDeNombre"<<nombreDeJugador[i]<<endl;
				   auxNombreOponente[posicionActual]=nombreDeJugador[i];
				   posicionActual++;	
				}
			}
			nombreOponente="";
			nombreOponente.assign(auxNombreOponente);
			nombreOponente = nombreOponente.substr(0,posicionActual);
			cout<<nombreOponente<<endl;
			exito=1;
			/*Verificar que secuencias esten copiadas bien*/
		break;
        case '2':
            //Fin de Juego sacarle secuenciasBuenas

        break;
        case '3':
            //Mandar Ganador y puntuacion viene desde el server 
        	strncpy(nombreDeJugador,&mensaje[4],10);//aqui se refiere al ganador
        	for (int i = 0; i < 10; ++i)
        	{
        		if(mensaje[i+4]=='0')
        		{
        			break;
        		}else
        		{
					nombreDeJugador[i] = mensaje[i+4];
        		}
        		
        	}
        	nombreGanador.assign(nombreDeJugador);
        	
        	puntajeGanador=mensaje[14];
        	cout<<"nombreGanador"<<nombreGanador<<endl;
        	cout<<"puntajeGanador"<<puntajeGanador<<endl;
        	cout<<"Mensajeenviadodeserver:"<<mensaje<<endl;
        	exito = 1;
        break;
    }    
    
    return exito;
}

int VentanaPartida::mandarBSB()
{
	int fd_socket;
	struct sockaddr_in cliente;
	struct sockaddr_in servidorAddr;
	int rc;
	char buffer[512],server[256];
	socklen_t add_size;
	add_size = sizeof cliente;
	strcpy(server,ip_ingresada.c_str());
	cout<<"IP ingresada"<<server<<endl;
	fd_socket = socket(AF_INET,SOCK_DGRAM,0);
	if(fd_socket < 0)
	{
		perror("Error en cuncion socket()");
		return -1;
	}
	

	inet_pton(AF_INET,server,&cliente.sin_addr.s_addr);
	cliente.sin_family=AF_INET;
	cliente.sin_port=htons (2432);

	memset(&buffer,0,sizeof(buffer));
	strcat(buffer,"AJR");//NombreProto
	strcat(buffer,"2");//enviar bandera de Secuencias Buenas
	strcat(buffer,nombreJugador.c_str());

	for (int i = 0; i < (10-nombreJugador.length()); ++i)
	{
		strcat(buffer,"0");
	}
	char caracterSecuenciasBuenas = secuenciasCorrectas;
	buffer[14]=caracterSecuenciasBuenas;
	cout<<"BSBcreada:"<<buffer<<endl;
	cout<<"Numero de secuencias enviadas:"<<buffer[14]<<":"<<(int)buffer[14]<<":"<<caracterSecuenciasBuenas<<":"<<endl;


	sendto (fd_socket, buffer, strlen(buffer), 0, (struct sockaddr *) &cliente, sizeof (cliente));
	
	rc=recvfrom(fd_socket,buffer, TAM_BUFFER, 0, (struct sockaddr *) &servidorAddr,&add_size);
	buffer[rc]='\0';	
	cout<<"Esperando\n";
	
	
	
    if (rc<0)
    {
        perror("Error funcion recvfrom");
        return -1;
    }	
	  
	
    

    cout<<"Buffer recibido:"<<buffer<<endl;
    int status;
    status = verificar(buffer, fd_socket, &servidorAddr);    
    if(rc<0)
    {

        perror("Error funcion sendto");
        return -1;
    }
 
    if(fd_socket!=-1)
    {
        close(fd_socket);
    }
    return status;

}
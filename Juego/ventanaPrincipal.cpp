#include "ventanaPrincipal.h"

VentanaPrincipal::VentanaPrincipal()
{
	//int i = 0;
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
	}
	
}

bool VentanaPrincipal::inicializar()
{
	ventana = NULL;
    fondo = NULL;
    for (int i = 0; i < 7; ++i)
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
		ventana = SDL_CreateWindow("Titulo Ventana", VENTANAPOS_X,VENTANAPOS_Y,ANCHO_PANTALLA,ALTO_PANTALLA,SDL_WINDOW_SHOWN);
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
				fondo = SDL_GetWindowSurface(ventana);
			}
			
		}
		posicionIMGS[TITULO_SUPERFICIE].x = 161;
		posicionIMGS[TITULO_SUPERFICIE].y = 10;
		posicionIMGS[INICIAR_SUPERFICIE].x = 192;
		posicionIMGS[INICIAR_SUPERFICIE].y = 116;
		posicionIMGS[HISTORIAL_SUPERFICIE].x = 192;
		posicionIMGS[HISTORIAL_SUPERFICIE].y = 213;
		posicionIMGS[MPUNTUACION_SUPERFICIE].x = 192;
		posicionIMGS[MPUNTUACION_SUPERFICIE].y = 310;

	}
	return exito;
}
bool VentanaPrincipal::cargarImagenes()
{
	bool exito = true;
	
	imagenPNG[TITULO_SUPERFICIE] = cargarDifFormat("imgbtns/titulo.png");
	if(imagenPNG == NULL)
	{
		perror("Error en cargarDifFormat");
		exito = false;
	}
	imagenPNG[INICIAR_SUPERFICIE] = cargarDifFormat("imgbtns/iniciar.png");
	if(imagenPNG == NULL)
	{
		perror("Error en cargarDifFormat");
		exito = false;
	}
	imagenPNG[MPUNTUACION_SUPERFICIE] = cargarDifFormat("imgbtns/puntuacion.png");
	if(imagenPNG == NULL)
	{
		perror("Error en cargarDifFormat");
		exito = false;
	}
	imagenPNG[HISTORIAL_SUPERFICIE] = cargarDifFormat("imgbtns/historial.png");
	if(imagenPNG == NULL)
	{
		perror("Error en cargarDifFormat");
		exito = false;
	}
	imagenPNG[INICIAR_B_SUPERFICIE] = cargarDifFormat("imgbtns/iniciarb.png");
	if(imagenPNG == NULL)
	{
		perror("Error en cargarDifFormat");
		exito = false;
	}
	imagenPNG[MPUNTUACION_B_SUPERFICIE] = cargarDifFormat("imgbtns/puntuacionb.png");
	if(imagenPNG == NULL)
	{
		perror("Error en cargarDifFormat");
		exito = false;
	}
	imagenPNG[HISTORIAL_B_SUPERFICIE] = cargarDifFormat("imgbtns/historialb.png");
	if(imagenPNG == NULL)
	{
		perror("Error en cargarDifFormat");
		exito = false;
	}
	
	return exito;
}

void VentanaPrincipal::cerrar()
{
	for (int i = 0; i < 7; ++i)
    {
    	SDL_FreeSurface(imagenPNG[i]);
    	imagenPNG[i]=NULL;
    }
	SDL_DestroyWindow(ventana);
	ventana = NULL;
	SDL_Quit();
}

SDL_Surface* VentanaPrincipal::cargarDifFormat(std::string ruta)
{
	SDL_Surface* imgAux = NULL;
	SDL_Surface* imgCargada = IMG_Load(ruta.c_str());
	if(imgCargada == NULL)
	{
		perror("Error en IMG_Load");
	}
	else
	{
		imgAux = SDL_ConvertSurface(imgCargada, fondo->format,0);
		if(imgAux == NULL)
		{
			perror("Error en SDL_ConvertSurface");
		}
		SDL_FreeSurface(imgCargada);
	}
	return imgAux;
}

void VentanaPrincipal::pintar()
{
	SDL_BlitSurface(imagenPNG[TITULO_SUPERFICIE],NULL,fondo,&posicionIMGS[TITULO_SUPERFICIE]);
	SDL_BlitSurface(imagenPNG[INICIAR_SUPERFICIE],NULL,fondo,&posicionIMGS[INICIAR_SUPERFICIE]);
	SDL_BlitSurface(imagenPNG[HISTORIAL_SUPERFICIE],NULL,fondo,&posicionIMGS[HISTORIAL_SUPERFICIE]);
	SDL_BlitSurface(imagenPNG[MPUNTUACION_SUPERFICIE],NULL,fondo,&posicionIMGS[MPUNTUACION_SUPERFICIE]);
	SDL_UpdateWindowSurface(ventana);
}

void VentanaPrincipal::mostrar(){

			bool quiereSalir = false;
			SDL_Event e;	
			SDL_FillRect(fondo,0,SDL_MapRGB(fondo->format,255,255,255));
			pintar();
			while(!quiereSalir)
			{

				while(SDL_PollEvent(&e)!=0)
				{

					if(e.type == SDL_QUIT)
					{
						quiereSalir = true;
					}
					if(e.motion.x>195 && e.motion.x<449 && e.motion.y>116 && e.motion.y<177 )
					{
						pintar();
						SDL_BlitSurface(imagenPNG[INICIAR_B_SUPERFICIE],NULL,fondo,&posicionIMGS[INICIAR_SUPERFICIE]);
						SDL_UpdateWindowSurface(ventana);
						
					}else
					if(e.motion.x>195 && e.motion.x<449 && e.motion.y>213 && e.motion.y<277 )
					{
						pintar();
						SDL_BlitSurface(imagenPNG[HISTORIAL_B_SUPERFICIE],NULL,fondo,&posicionIMGS[HISTORIAL_SUPERFICIE]);
						SDL_UpdateWindowSurface(ventana);
					}else
					if(e.motion.x>195 && e.motion.x<449 && e.motion.y>310 && e.motion.y< 377 )
					{
						pintar();
						SDL_BlitSurface(imagenPNG[MPUNTUACION_B_SUPERFICIE],NULL,fondo,&posicionIMGS[MPUNTUACION_SUPERFICIE]);
						SDL_UpdateWindowSurface(ventana);
					}else{
						pintar();
					}
					if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x>195 && e.motion.x<449 && e.motion.y>116 && e.motion.y<177 )
					{
						
						
						clickEnOpcionJugar();

					}

				}							
			}
}


void VentanaPrincipal::clickEnOpcionJugar(){
     cout<<"e:"<<endl;
    int numeros[15][9];

    for (int i = 0; i < 15; i++)
    {
    	cout<<"entraste al for version 2:"<<i<<endl;
    	for (int g = 0; g < 9; g++)
    	{
    		
    		numeros[i][g] = g+1;
    		cout<<"i:"<<i<<" g:"<<g<<" "<<g+1<<endl;
    	}
    }
    
    string nom = " YO ";
    string opon = " Alex ";
    cout<<"Aqui estas"<<endl;
    SDL_HideWindow(ventana); 
    ventanaPartida = new VentanaPartida(nom,opon,numeros);
    cout<<"qui estas2"<<endl;
    //ventanaPartida(nom,opon,numeros);
   ventanaPartida->jugar();

}
#include "ganador.h"



void Ganador::Capturar()
{/*
    strcpy(gan.NombreJugador,"Alexis");
    strcpy(gan.NombreOponente,"Jordano");
    strcpy(gan.NombreGanador,"Roberto");
    gan.puntos=40;

    ofstream escribir ("historial.txt", ios::app);

    escribir.write((char*)&gan, sizeof(gan));
    escribir.close();*/
}

void Ganador::Mostrar()
{

            cout << endl << "Nombre Jugador: " << NombreJugador << endl;
            cout << "Nombre Oponente: " << NombreOponente << endl;
            cout << "Nombre Ganador: " << NombreGanador << endl;
            cout << "Puntos: " << puntos << endl;

}

bool operator<(const Ganador &a,const Ganador &b)
{
    return (a.puntos<b.puntos);
}
bool operator>(const Ganador &a,const Ganador &b)
{
    return (a.puntos>b.puntos);
}
bool operator==(const Ganador &a,const Ganador &b)
{
    return (a.puntos==b.puntos);
}
bool operator!=(const Ganador &a,const Ganador &b)
{
    return (a.puntos!=b.puntos);
}
bool operator<=(const Ganador &a,const Ganador &b)
{
    return (a.puntos<=b.puntos);
}
bool operator>=(const Ganador &a,const Ganador &b)
{
    return (a.puntos>=b.puntos);
}

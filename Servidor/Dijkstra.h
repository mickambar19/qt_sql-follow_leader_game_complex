//
//  Dijkstra.h
//  Juego
//
//  Created by Rob's on 10/11/15.
//  Copyright (c) 2015 Durán Parra José Roberto. All rights reserved.
//

#ifndef Juego_Dijkstra_h
#define Juego_Dijkstra_h

#include<iostream>
#define INFINITO 999

using namespace std;

class Dijkstra{
public:
    int Matrix[15][15];
    int predecesor[15], distancia[15];
    bool visitado[15];
    int inicio, fin;
    int numNodos;
    char secuencia[150];
    int cont;
public:
    void ObtenerGrafo();
    void Inicializar();
    int NodoMasCercano();
    void Alg_Dijkstra();
    void Mostrar();
    void MostrarCamino(int);
};


void Dijkstra::ObtenerGrafo()
{
    srand (time(NULL));
    
    numNodos = 9;
    
    cout << endl << " Numero de nodos: " << numNodos << endl;;
    
    cout << endl <<"Ingrese el peso para la aristas: " << endl;
    
    for (int i = 0; i < numNodos; i++)
    {
        for (int j=0;j<numNodos;j++)
        {
            if ( i == j)
                Matrix[i][j] = 0;
            
            else
            {
                Matrix[i][j] = rand() % 50;
            }
            
        }
    }
    
    for (int i = 0; i < numNodos; i++)
    {
        for (int j=0;j<numNodos;j++)
        {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    inicio = rand () % 9 + 1;
    fin = rand () % 9 + 1;
    cout << endl << "Ingrese el nodo de inicio: " << inicio << endl;
    
    while (fin == inicio)
    {
        fin = rand () % 9 +1;
    }
    
    cout << "Ingrese el nodo de fin: " << fin << endl;
    
    inicio -= 1; fin -= 1;
}


void Dijkstra::Inicializar()
{
    for (int i = 0; i < numNodos; i++)
    {
        visitado[i] = false;
        predecesor[i] = -1;
        distancia[i] = INFINITO;
    }
    
    distancia[inicio] = 0;
}

int Dijkstra::NodoMasCercano()
{
    int distanciamin = INFINITO;
    int nodocercano;
    
    for (int i = 0; i < numNodos; i++)
    {
        if((!visitado[i]) && (distanciamin >= distancia[i])) {
            distanciamin = distancia[i];
            nodocercano = i;
        }
    }
    return nodocercano;
}


void Dijkstra::Alg_Dijkstra()
{
    Inicializar();
    
    int nodocercano;
    int contador = 0;
    
    while (contador < numNodos)
    {
        nodocercano = NodoMasCercano();
        
        visitado[nodocercano] = true;
        
        for(int i = 0; i < numNodos; i++)
        {
            if ( (!visitado[i]) && (Matrix[nodocercano][i] > 0) )
            {
                if(distancia[i] > distancia[nodocercano]+Matrix[nodocercano][i])
                {
                    distancia[i] = distancia[nodocercano]+Matrix[nodocercano][i];
                    predecesor[i] = nodocercano;
                }
            }
        }
        contador++;
    }
}


void Dijkstra::MostrarCamino(int nodo)
{
    if(nodo == inicio)
    {
        cout << "[" << nodo+1 <<"]---[";
    }
    else if(predecesor[nodo] == -1)
    {
        cout<<"No hay conexion de [ " << inicio << "]---["<< nodo+1 << "]" << endl;
    }
    else
    {
        MostrarCamino(predecesor[nodo]);
        
        cout << nodo+1 <<"]---[";
    }
    
    secuencia[cont] = nodo+ 1 +'0';
    cont++;
}


void Dijkstra::Mostrar()
{
    
    MostrarCamino(fin);
    
    cout << " Peso total: " << distancia[fin] << " ]" << endl;
    
    cout << "Secuencia copiada: " << endl;
    
    cout<<secuencia<<endl;
    
    cout<<"\ncont"<<cont<<endl<<endl;
    secuencia[cont] = 0+'0';
    cont++;

    //cout<<"\nsecuenciaCaracter:"<<secuencia[cont]<<endl;
    //cout<<"\nsecuenciaIntCaracter:"<<(int)secuencia[cont]<<endl;


    
}

#endif

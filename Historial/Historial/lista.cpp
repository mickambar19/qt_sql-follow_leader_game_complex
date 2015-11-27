#include "lista.h"


Lista::Lista ()
{
    inicio = NULL;
    fin = NULL;
    tam = 0;
}

bool Lista::Vacio()
{
    if (tam == 0)
        return true;
    else
        return false;
}

void Lista::Ins_Vacia()
{
    pnodo nuevo = new Nodo ();
    Ganador g;

    g.Capturar();

    nuevo->g = g;

    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    inicio = nuevo;
    fin = nuevo;
    tam++;
}

void Lista::CargarDatos()
{
    Ganador gan;
    ifstream leer ("historial.txt");

    if (!leer.good())
    {
        cout << "No existe el archivo." << endl;
    }
    else
    {

        while (!leer.eof())
        {
            leer.read((char *)&gan, sizeof(gan));
            if(leer.eof())break;

            if (Vacio())
            {
                pnodo nuevo = new Nodo ();

                strcpy(nuevo->g.NombreJugador, gan.NombreJugador);
                strcpy(nuevo->g.NombreOponente, gan.NombreOponente);
                strcpy(nuevo->g.NombreGanador, gan.NombreGanador);
                nuevo->g.puntos = gan.puntos;

                nuevo->siguiente = NULL;
                nuevo->anterior = NULL;
                inicio = nuevo;
                fin = nuevo;
                tam++;
            }

            else
            {
                pnodo actual = fin, nuevo = new Nodo ();

                strcpy(nuevo->g.NombreJugador, gan.NombreJugador);
                strcpy(nuevo->g.NombreOponente, gan.NombreOponente);
                strcpy(nuevo->g.NombreGanador, gan.NombreGanador);
                nuevo->g.puntos = gan.puntos;

                actual->siguiente = nuevo;
                nuevo->siguiente = NULL;
                nuevo->anterior = actual;
                fin = nuevo;
                tam++;
            }
        }
    }
}

void Lista::Mostrar1()
{
    if (!Vacio())
    {
        pnodo actual;
        actual = inicio;

        while (actual != NULL)
        {
            actual->g.Mostrar();
            actual = actual->siguiente;
            cout << endl;
        }

    }

    else
        cout << endl << "No hay datos." << endl;
}

void Lista::Mostrar2()
{
    if (!Vacio())
    {
        pnodo actual = fin;

        while (actual != NULL)
        {
            actual->g.Mostrar();
            actual = actual->anterior;
            cout << endl;
        }
    }

    else
        cout << endl << "No hay datos." << endl;
}

void Lista::SupInicio()
{
    pnodo sup = inicio;
    inicio = inicio->siguiente;

    if (tam == 1)
        fin = NULL;
    else
        inicio->anterior = NULL;

    free (sup);
    tam--;
}

void Lista::Destruir()
{
    if (Vacio()) {}

    else
    {
        while (tam > 0)
        {
            SupInicio();
        }
    }
}


void Lista::Burbuja()
{
    pnodo actual, sig;
    Ganador temp;

    actual = inicio;

    while (actual != NULL)
    {
        sig = actual->siguiente;

        while (sig != NULL)
        {
            if (strcmp(actual->g.NombreOponente, sig->g.NombreOponente) > 0)
            {
                temp = sig->g;
                sig->g = actual->g;
                actual->g = temp;

            }

            sig = sig->siguiente;
        }

        actual = actual->siguiente;
    }
}

void Lista::QuickSort(pnodo izq, pnodo der)
{
    pnodo comienzo, actual;
    Ganador aux;

    //Si los punteros 'izq' y 'der' son iguales, entonces termina.
    if (izq == der)
        return;

    //Establece el inicio y punteros del elemento actual.
    comienzo = izq;
    actual = comienzo->siguiente;

    //Ciclo infinito hasta que lleguemos a la derecha.
    while (1)
    {
        //Si el elemento del comienzo es menos al de la derecha.
        if (strcmp(comienzo->g.NombreOponente, actual->g.NombreOponente) < 0)
        {
            //Intercambio de Elementos.
            aux = actual->g;
            actual->g = comienzo->g;
            comienzo->g = aux;
        }

        //Verifica si llegamos a la derecha.
        if (actual == der) break;

        //Mueve al siguiente elemento de la lista.
        actual = actual->siguiente;
    }

    //Intercambia el elemento inicial y actual.
    aux = izq->g;
    izq->g = actual->g;
    actual->g = aux;

    //Guarda el elemento actual.
    pnodo ant;
    ant = actual;

    //Verifica si tenemos que ordenar el lado izquierdo respecto al punto actual.
    actual = actual->anterior;
    if (actual != NULL)
    {
        if ((izq->anterior != actual) && (actual->siguiente != izq))
            QuickSort(izq, actual);
    }

    //Verifica si tenemos que ordenar el lado derecho respecto al punto actual.
    actual = ant;
    actual = actual->siguiente;
    if (actual != NULL)
    {
        if ((actual->anterior != der) && (der->siguiente != actual))
            QuickSort(actual, der);
    }

}

void Lista::BusquedaBinaria()
{
    char  nombreP[20];

    cout<<"Dame el Nombre a Buscar "<<endl;
    cin.getline(nombreP, 20); cin.getline(nombreP, 20);

    pnodo busq,aux[tam];
    busq = inicio;
    int cont,bandera,i,j,medio;
    i = 0;
    j = tam-1;
    bandera = false;

    for(cont=0; cont<tam; cont++)
    {
        aux[cont] = busq;
        busq = busq->siguiente;
    }

    while(i <= j)
    {
        medio = (i+j)/2;
        if(strcmp(nombreP,aux[medio]->g.NombreJugador)==0)
        {
            cout<<"Encontrado"<<endl;
            aux[medio]->g.Mostrar();
            bandera=true;
        }
        if(strcmp(nombreP,aux[medio]->g.NombreJugador) < 0)
        {
            j=medio-1;
        }
        else
        {
            i=medio+1;
        }
    }
    if(bandera == false)
    {
        cout<<"Nombre no encontrado"<<endl;
    }
}

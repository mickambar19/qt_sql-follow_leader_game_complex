#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <cstring>
#include <string>
#include <arpa/inet.h>
#include "Dijkstra.h"
#define TAM_BUFFER 200
using namespace std;
struct sockaddr_in JugadoresAdd[2];
char nombreAux[10];
int jugadoresAceptados=0;
int secuenciasBuenas=0;
void verificar(char *mensaje,int sd, struct sockaddr_in* clienteA);
void crearSecuencias();
Dijkstra G;
int main()
{
    /**/
    int sd=-1, rc;
    char buffer[TAM_BUFFER];
    struct sockaddr_in servidorA;
    struct sockaddr_in clienteA;
    socklen_t clienteLen = sizeof(clienteA);

    /*sd = descriptor de socket punto final*/
    sd = socket(AF_INET, SOCK_DGRAM,0);
    if (sd < 0)
    {
        perror("Error funcion socket()");
        
    }
    /*bind() obtiene un nombre unico para el socket sera el rc*/
    memset(&servidorA,0,sizeof(servidorA));
    memset(&JugadoresAdd[0],0,sizeof(JugadoresAdd[0]));
    memset(&JugadoresAdd[1],0,sizeof(JugadoresAdd[1]));
    servidorA.sin_family      = AF_INET;
    servidorA.sin_port        = htons(2432);
    servidorA.sin_addr.s_addr = INADDR_ANY;

    rc = bind(sd,(struct sockaddr *)&servidorA,sizeof(servidorA));

    if(rc<0)
    {
        perror("Error funcion bind()");
    }

    do
    {/*recibiremos informacionde alguien */
        /**/
        rc = recvfrom(sd,buffer,TAM_BUFFER,0,(struct sockaddr*)&clienteA,&clienteLen);
        if (rc<0)
        {
            perror("Error funcion recvfrom");
            break;
        }
    
        cout<<"Buffer recibido:"<<buffer<<endl;
        char clienteAIP[TAM_BUFFER];
        /*
        * int inet_pton(int af, const char *src, void *dst);
        * return 1 en exitos
        */
        inet_ntop(AF_INET,&clienteA.sin_addr.s_addr,clienteAIP,sizeof(clienteAIP));
        cout<<"Desde el puerto:"   <<ntohs(clienteA.sin_port)<<endl;
        cout<<"Desde la direccion:"<<clienteAIP<<endl;
        /*
        * sendto(int sockfd, const void *buf, size_t len, int flags,
        * const struct sockaddr *dest_addr, socklen_t addrlen);
        */
        buffer[rc+1]='\0';
        verificar(buffer, sd, &clienteA);
        
        if(rc<0)
        {

            perror("Error funcion sendto");
            break;
        }
    }while(1);

    

    
    if(sd!=-1)
    {
        close(sd);
    }
    return 0;
}

void verificar(char *mensaje,int sd, struct sockaddr_in* clienteA)
{

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
    char secuencias[150];

    strncpy(nombreProtocolo,mensaje,3);
    banderasEnMensaje=mensaje[3];
    strncpy(nombreDeJugador,&mensaje[4],10);
    sucesionesBuenas = mensaje[14];
    
    nombreDeJugador[10]='\0';
    cout<<"Nom:"<<nombreProtocolo<<endl;
    cout<<"banderasEnMensaje:"<<banderasEnMensaje<<endl;
    cout<<"nombreDeJugador:"<<nombreDeJugador<<endl;
    cout<<"sucesionesBuenas:"<<sucesionesBuenas<<endl;
    cout<<"mensaje:"<<mensaje<<endl;
    
   
    switch(banderasEnMensaje)
    {
        case '0':
        {
            
            //QuiereConectarseYEsperaraUnJuga   dor sacarle el nombre
            cout<<"Entraste en 0"<<endl;
            if(jugadoresAceptados==1)
                {
                    crearSecuencias();
                    cout<<"Secs antes de enviar\n";
                    for (int i = 0; i < G.cont; ++i)
                    {
                        cout<<G.secuencia[i]<<" ";
                    }
                    cout<<endl;
                    strncpy(&mensaje[14],G.secuencia,strlen(G.secuencia));
                    mensaje[G.cont+14-1]='\0';
                    memcpy(&JugadoresAdd[jugadoresAceptados],clienteA,sizeof(*clienteA));
                    mensaje[3]='1';
                    cout << "msj al primer cliente: " << mensaje << endl;
                    sendto(sd,mensaje,strlen(mensaje),0,(struct sockaddr*)&JugadoresAdd[0],sizeof(JugadoresAdd[0]));
                    memcpy(&mensaje[4],nombreAux,sizeof(nombreAux));
                 
                    cout<<"Mensaje al segudno cliente: " << mensaje<<endl;
                    sendto(sd,mensaje,strlen(mensaje),0,(struct sockaddr*)&JugadoresAdd[1],sizeof(JugadoresAdd[1]));
                    jugadoresAceptados=0;
                }else{
                    memcpy(&JugadoresAdd[jugadoresAceptados],clienteA,sizeof(*clienteA));
                    cout<<"Mensaje al primer cliente: " << mensaje<<endl;
                    strncpy(nombreAux,&mensaje[4],10);
                    
                    jugadoresAceptados++;
            }
            
            //Guardar la ip del que se conecto
        }
        break;
        case '1':
            //Ya tenemos jugador vas a JUGAR Las secuencias estan en el mensaje
        break;
        case '2':
         if(jugadoresAceptados==1)
                {
                  int secuenciasBuenas2;
                    cout<<"Secs antes de enviar\n";
                    
                    memcpy(&JugadoresAdd[jugadoresAceptados],clienteA,sizeof(*clienteA));
                    mensaje[3]='3';
                    cout << "msj al primer cliente: " << mensaje << endl;
                    secuenciasBuenas2=(int)mensaje[14]*17;
                    cout << "Secuencias buenas del segundo homie: " << secuenciasBuenas2 << endl;
                    if(secuenciasBuenas==secuenciasBuenas2){
                    strncpy(nombreAux,"EMPATE",10);
                     mensaje[14]=secuenciasBuenas;
                        }else if(secuenciasBuenas>secuenciasBuenas2){
                         memcpy(&mensaje[4],nombreAux,sizeof(nombreAux));
                         mensaje[14]=secuenciasBuenas;
                        }else if(secuenciasBuenas<secuenciasBuenas2){
                        mensaje[14]=secuenciasBuenas2;
                        }
                   
                    sendto(sd,mensaje,strlen(mensaje),0,(struct sockaddr*)&JugadoresAdd[0],sizeof(JugadoresAdd[0]));
                   
                 
                    cout<<"Mensaje al segudno cliente: " << mensaje<<endl;
                    sendto(sd,mensaje,strlen(mensaje),0,(struct sockaddr*)&JugadoresAdd[1],sizeof(JugadoresAdd[1]));
                }else{
                    memcpy(&JugadoresAdd[jugadoresAceptados],clienteA,sizeof(*clienteA));
                                       cout<<"Mensaje al primer cliente: " << mensaje<<endl;
                    strncpy(nombreAux,&mensaje[4],10);
                    secuenciasBuenas=(int)mensaje[14]*17;
                    cout <<"Secuencias buenas del primer homie: " << secuenciasBuenas << endl;
                    
                    jugadoresAceptados++;
            }
            
            //Fin de Juego sacarle secuenciasBuenas
        break;
        case '3':
            //Mandar Ganador y puntuacion
        break;
    }    
    
}

void crearSecuencias(){
    cout << "\t Algoritmo de Dijkstra*** " << endl;
    G.cont = 0;
    G.ObtenerGrafo();
    G.Alg_Dijkstra();
    G.Mostrar();
    char opc = 0;
    
    while (opc < 15)
    {
            G.inicio = rand () % 9 + 1;
            G.fin = rand () % 9 + 1;
            
            while (G.fin == G.inicio)
            {
                cout << endl << "El nodo fue igual" << endl;
                G.fin = rand () % 9 +1;
            }
            
            cout << "Nodo de inicio: " << G.inicio << endl;
            cout << "Nodo de fin: " << G.fin << endl;
            cout << endl;
            
            G.inicio -= 1; G.fin -= 1;
            
            G.Alg_Dijkstra();
            G.Mostrar();
        
        opc++;
    }
    
    cout << endl << "Chico banderas: " << endl;
    
   /* for (int i = 0; i < G.cont; i++){
        cout << (int)G.secuencia[i] << " ";
    }
    cout<<endl;*/
}

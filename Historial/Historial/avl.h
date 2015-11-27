#ifndef AVL_H
#define AVL_H

#include <iostream>
#include "nododoble.h"
#include <cstdlib>
using namespace std;
template <class T>
class AVL{
    public:
        NodoDoble<T>* raiz;
        void InsertaBalanceado(T dato,NodoDoble<T>* Apunt, int *band);
        NodoDoble<T>* HI_HI(NodoDoble<T>* Apunt,NodoDoble<T>* ApAux1);
        NodoDoble<T>* HD_HD(NodoDoble<T>* Apunt,NodoDoble<T>* ApAux1);
        NodoDoble<T>* HI_HD(NodoDoble<T>* Apunt,NodoDoble<T>* ApAux1);
        NodoDoble<T>* HD_HI(NodoDoble<T>* Apunt,NodoDoble<T>* ApAux1);
        NodoDoble<T>* buscar_real(NodoDoble<T>* donde,T dato);
        void preOrden_real(NodoDoble<T> *a);
        void enOrden_real(NodoDoble<T> *a);
        void posOrden_real(NodoDoble<T> *a);
        int profundidad_real(NodoDoble<T> *donde);
    public:
        AVL();
        bool vacio();
        void insertar();
        void inicializa();
        void insertar(T dato);
        NodoDoble<T>* buscar(T dato);
        void preOrden(NodoDoble<T> *a);
        void preOrden();
        void enOrden();
        void posOrden();
        int profundidad();
        NodoDoble<T>* padre(NodoDoble<T>* raiz,NodoDoble<T>* hijo);
        bool es_hoja(NodoDoble<T>* pos);
        void eliminar(NodoDoble<T> *pos);
        NodoDoble<T>* mayor(NodoDoble<T> *pos);
        NodoDoble<T>* menor(NodoDoble<T> *pos);
        NodoDoble<T>* RestructuraI(NodoDoble<T>* Nodo, int *Aviso);
        NodoDoble<T>* RestructuraD(NodoDoble<T>* Nodo, int *Aviso);
        void Sustituye(NodoDoble<T>*Nodo,NodoDoble<T>*ApAux, int *Avisa);
        void EliminacionBalanceado(NodoDoble<T>* Apunt,NodoDoble<T>* ApAnt, int *Avisa, T Dato);
        };

        template <class T>
AVL<T>::AVL(){
    inicializa();}
    template <class T>
bool AVL<T>::vacio(){
 if(raiz==NULL){ return true;}
 else return false;
}
    template <class T>
void AVL<T>::inicializa(){
    raiz=NULL;
    }


    template<class T>
NodoDoble<T>* AVL<T>::buscar(T dato){
   return buscar_real(raiz,dato);
    }
    template<class T>
NodoDoble<T>* AVL<T>::buscar_real(NodoDoble<T>* donde,T dato){
    if(donde==NULL){
        return NULL;
    }
    if(donde->getDato()==dato){
        return donde;
    }
    if(dato<donde->getDato()){
        return buscar_real(donde->getIzq(),dato);
    }else{
        return buscar_real(donde->getDer(),dato);
    }
    }
    template<class T>
void AVL<T>::preOrden(){
   preOrden_real(raiz);
    }
    template<class T>
void AVL<T>::preOrden_real(NodoDoble<T> *donde){
if(donde!=NULL){
    cout<<donde->getDato()<<". ";
    preOrden_real(donde->getIzq());
    preOrden_real(donde->getDer());
}
}
    template<class T>
void AVL<T>::enOrden(){
   enOrden_real(raiz);
    }
    template<class T>
void AVL<T>::enOrden_real(NodoDoble<T> *donde){
if(donde!=NULL){
       enOrden_real(donde->getIzq());
       cout<<donde->getDato()<<". ";
       enOrden_real(donde->getDer());
}
}
    template<class T>
void AVL<T>::posOrden(){
   posOrden_real(raiz);
    }
    template<class T>
void AVL<T>::posOrden_real(NodoDoble<T> *donde){
if(donde!=NULL){
       posOrden_real(donde->getIzq());
       posOrden_real(donde->getDer());
       cout<<donde->getDato()<<". ";
       }
}
    template<class T>
int AVL<T>::profundidad(){
  int a;
   a=profundidad_real(raiz);
   return a;
    }
    template<class T>
int AVL<T>::profundidad_real(NodoDoble<T> *donde){
     int profIzq;
     int profDer;
if(donde==NULL){
        return 0;}
   else{
       profIzq=profundidad_real(donde->getIzq());
       profDer=profundidad_real(donde->getDer());
       if(profIzq>profDer){
        return profIzq+1;
       }else{
        return profDer+1;
        }
   }
}
    template <class T>
NodoDoble<T>* AVL<T>::padre(NodoDoble<T>* raiz,NodoDoble<T>* hijo){
if(raiz==NULL) return NULL;
 if(raiz->getDer()==hijo||raiz->getIzq()==hijo)
    return raiz;
if(hijo->getDato()<raiz->getDato()){
    return padre(raiz->getIzq(),hijo);
}else{
    return padre(raiz->getDer(),hijo); }
}
    template<class T>
bool AVL<T>::es_hoja(NodoDoble<T>* pos){
    if(pos->getDer()==NULL && pos->getIzq()==NULL) return true;
    else return false;
}
    template<class T>
void AVL<T>::eliminar(NodoDoble<T> *pos){
    if(pos==NULL){} //exception;
    NodoDoble<T> *p;
    if(pos==raiz && es_hoja(pos)){
        raiz=NULL;
        delete pos;
    }else if (es_hoja(pos)){
        p=padre(raiz,pos);
        if(p->getDer()==pos){
            p->setDer(NULL);
        }else{p->setIzq(NULL);
        }delete pos;
    }else{
    if(pos->getDer()!=NULL){
        p=menor(pos->getDer());
        pos->setDato(p->getDato());
        eliminar(p);
    }else{
        p=mayor(pos->getIzq());
        pos->setDato(p->getDato());
        eliminar(p);
    }
  }
}
    template<class T>
NodoDoble<T>* AVL<T>::mayor(NodoDoble<T> *pos){
if(pos==NULL) return NULL;
   while(pos->getDer()!=NULL){
    pos=pos->getDer();
   }
   return pos;
}
    template<class T>
NodoDoble<T>* AVL<T>::menor(NodoDoble<T> *pos){
if(pos==NULL) return NULL;
   while(pos->getIzq()!=NULL){
    pos=pos->getIzq();
   }
   return pos;
}

        template <class T>
NodoDoble<T>* AVL<T>::HI_HI(NodoDoble<T>* Apunt,NodoDoble<T>* ApAux1){
        Apunt->setIzq(ApAux1->getDer());
        ApAux1->setDer(Apunt);
        Apunt->setFE(0);
        cout<<"Rotacion Simple Izquierda\n";
        return ApAux1;
        }
        template <class T>
NodoDoble<T>* AVL<T>::HD_HD(NodoDoble<T>* Apunt,NodoDoble<T>* ApAux1){
        Apunt->setDer(ApAux1->getIzq());
        ApAux1->setIzq(Apunt);
        Apunt->setFE(0);
        cout<<"Rotacion Simple Derecha\n";
        return ApAux1;
        }

        template <class T>
        NodoDoble<T>* AVL<T>::HI_HD(NodoDoble<T>* Apunt,NodoDoble<T>* ApAux1){
        NodoDoble<T>* ApAux2;
        ApAux2=ApAux1->getDer();
        Apunt->setIzq(ApAux2->getDer());
        ApAux2->setDer(Apunt);
        ApAux1->setDer(ApAux2->getIzq());
        ApAux2->setIzq(ApAux1);
        if(ApAux2->getFE()==-1){
                Apunt->setFE(1);
        }else{
            Apunt->setFE(0);
        }

        if(ApAux2->getFE()==1){
            ApAux1->setFE(-1);
        }else{
            ApAux1->setFE(0);
        }
        cout<<"Rotacion Doble Derecha\n";
        return ApAux2;
         }
         template <class T>
        NodoDoble<T>* AVL<T>::HD_HI(NodoDoble<T>* Apunt,NodoDoble<T>* ApAux1){
        NodoDoble<T>* ApAux2;
        ApAux2=ApAux1->getIzq();
        Apunt->setDer(ApAux2->getIzq());
        ApAux2->setIzq(Apunt);
        ApAux1->setIzq(ApAux2->getDer());
        ApAux2->setDer(ApAux1);
        if(ApAux2->getFE()==-1){
                Apunt->setFE(1);
        }else{
            Apunt->setFE(0);
        }

        if(ApAux2->getFE()==1){
            ApAux1->setFE(-1);
        }else{
            ApAux1->setFE(0);
        }
        cout<<"Rotacion Doble Izquierda\n";
        return ApAux2;
         }

         /*Metodo que inserta un nuevo elemento en un arbol balanceado
         Recibe como parametros el dato a insertar, un puntero al nodo a visitar
         la primer vez es la raiz, y un entero band que la primera vez trae el valor 0*/
         template <class T>
         void AVL<T>::InsertaBalanceado(T dato, NodoDoble<T>* Apunt, int *band){
         NodoDoble<T> *ApAux1,*ApAux2;
            if(Apunt!=NULL){
                    if(dato<Apunt->getDato()){
                /*Se invoca el metodo con el subArbol izquierdo */
                InsertaBalanceado(dato,Apunt->getIzq(),band);
                Apunt->setIzq(raiz);
                if(0<*band){
                    /*verifica si crecio el subarbol izquierdo*/
                    switch(Apunt->getFE()){
                case 1:
                    Apunt->setFE(0);
                    *band=0;
                    break;
                case 0:
                    Apunt->setFE(-1);
                    break;
                case -1:
                    ApAux1=Apunt->getIzq();
                    if(ApAux1->getFE()<=0)
                        Apunt=HI_HI(Apunt,ApAux1);
                    else
                        Apunt=HI_HD(Apunt,ApAux1);
                    Apunt->setFE(0);
                    *band=0;
                    }
                  }
                }else{
                  if(dato>Apunt->getDato()){
                        /*Se invoca el metodo con el subArbol izquierdo */
                    InsertaBalanceado(dato,Apunt->getDer(),band);
                    Apunt->setDer(raiz);
                    if(0<*band){
                        /*verifica si crecio el subarbol izquierdo*/
                        switch(Apunt->getFE()){
                    case -1:
                        Apunt->setFE(0);
                        *band=0;
                        break;
                    case 0:
                        Apunt->setFE(1);
                        break;
                    case 1:
                        ApAux1=Apunt->getDer();
                        if(ApAux1->getFE()>=0)
                            Apunt=HD_HD(Apunt,ApAux1);
                        else
                            Apunt=HD_HI(Apunt,ApAux1);
                        Apunt->setFE(0);
                        *band=0;
                        }
                    }

               }
            }
            raiz=Apunt;
          }else{
              /*Inserta un nuevo nodo y actualiza el valor de band
              indicando que el arbol creio*/
              ApAux2=new NodoDoble<T>(dato);
              ApAux2->setFE(0);
              *band=1;
              raiz=ApAux2;
          }
        }
         template <class T>
void AVL<T>::insertar(T dato){
  int *band;
  band=new int;
  *band=0;
    InsertaBalanceado(dato,raiz,band);
    delete band;
    }


    /*Metodo auxiliar del metodo eliminado balanceado
        que reestructura el arbol cuando la altura de la rama izquierda a disminuido*/
        template <class T>
        NodoDoble<T>* AVL<T>::RestructuraI(NodoDoble<T>* Nodo, int *Aviso){
        NodoDoble<T>* ApAux;
        if(*Aviso>0){
             switch(Nodo->getFE()){
         case -1:
            Nodo->setFE(0);
            break;
         case 0:
            Nodo->setFE(1);
            *Aviso=0;
            break;
         case 1:
            ApAux=Nodo->getDer();
            if(ApAux->getFE()>=0){//Rotacion HD-HD
            Nodo->setDer(ApAux->getIzq());
            ApAux->setIzq(Nodo);
                switch(ApAux->getFE()){
            case 0:
                Nodo->setFE(1);
                ApAux->setFE(-1);
                *Aviso=0;
                break;
            case 1:
                Nodo->setFE(0);
                ApAux->setFE(0);
                break;
                }
                Nodo=ApAux;
            }else{//rotacion HD_HI
                Nodo=HD_HI(Nodo,ApAux);
                Nodo->setFE(0);

            }
            break;
            }
          }
          return Nodo;
        }
         /*Metodo auxiliar del metodo eliminado balanceado
        que reestructura el arbol cuando la altura de la rama derecha a disminuido*/
        template <class T>
        NodoDoble<T>* AVL<T>::RestructuraD(NodoDoble<T>* Nodo, int *Aviso){
        NodoDoble<T>* ApAux;
        if(*Aviso>0){
             switch(Nodo->getFE()){
         case 1:
            Nodo->setFE(0);
            break;
         case 0:
            Nodo->setFE(-1);
            *Aviso=0;
            break;
         case -1:
            ApAux=Nodo->getIzq();
            if(ApAux->getFE()<=0){//Rotacion HD-HD
            Nodo->setIzq(ApAux->getDer());
            ApAux->setDer(Nodo);
                switch(ApAux->getFE()){
            case 0:
                Nodo->setFE(-1);
                ApAux->setFE(1);
                *Aviso=0;
                break;
            case -1:
                Nodo->setFE(0);
                ApAux->setFE(0);
                break;
                }
                Nodo=ApAux;
            }else{//rotacion HI_HD
                Nodo=HI_HD(Nodo,ApAux);
                Nodo->setFE(0);
            }
            break;
            }
          }
          return Nodo;
        }
        /*Metodo auxiliar del metodo eliminacion balanceado que sustituye el
        elemento que se desea eliminar por el que se encuentra mas a la
        derecha del subarbol izquierdo*/
         template<class T>
        void AVL<T>::Sustituye(NodoDoble<T>*Nodo,NodoDoble<T>*ApAux, int *Avisa){
        if(Nodo->getDer()!=NULL){
            Sustituye(Nodo->getDer(),ApAux,Avisa);
            if(ApAux->getIzq()==NULL){
                Nodo->setIzq(NULL);
            }else{
            Nodo->setDer(ApAux->getIzq());
            Nodo=RestructuraD(Nodo,Avisa);
            }
        }else{
        ApAux->setDato(Nodo->getDato());
        Nodo=Nodo->setIzq();
        *Avisa=1;
        }
        ApAux->setIzq(Nodo);
        }
        /*Metodo que elimina un elemento de un arbol balanceado.
        Luego de la eliminacion se actualizan los factores de equilibrio
        de cada nodo hasta la raiz y se reestructura el arbol si fuera necesario*/
        template <class T>
        void AVL<T>::EliminacionBalanceado(NodoDoble<T>* Apunt,NodoDoble<T>* ApAnt, int *Avisa, T Dato){
        NodoDoble<T>* ApAux;
        int Bandera;
        if(Apunt!=NULL){
            if(Dato<Apunt->getDato()){
                if(*Avisa>0){
                    Bandera=1;}
                else if(*Avisa!=0){
                    Bandera=-1;}
                *Avisa=-1;
                EliminacionBalanceado(Apunt->getIzq(),Apunt,Avisa,Dato);
                Apunt=RestructuraI(Apunt,Avisa);
                if(ApAnt!=NULL){
                switch(Bandera){
                case -1:
                    ApAnt->setIzq(Apunt);
                    break;
                case 1:
                    ApAnt->setDer(Apunt);
                    break;
                default:
                    break;
               }
            }else{
             raiz=Apunt;}
         }else if(Dato>Apunt->getDato()){
                if(*Avisa<0){
                    Bandera=-1;}
                else if(*Avisa!=0){
                    Bandera=1;}
                *Avisa=-1;
                EliminacionBalanceado(Apunt->getDer(),Apunt,Avisa,Dato);
                Apunt=RestructuraD(Apunt,Avisa);
                if(ApAnt!=NULL){
                switch(Bandera){
                case -1:
                    ApAnt->setIzq(Apunt);
                    break;
                case 1:
                    ApAnt->setDer(Apunt);
                    break;
                default:
                    break;
               }
            }else{
             raiz=Apunt;}
            }else{
                ApAux=Apunt;
            if(ApAux->getDer()==NULL){
                Apunt=ApAux->getIzq();
                if(*Avisa!=0)
                    if(*Avisa<0)
                    ApAnt->setIzq(Apunt);
                    else
                    ApAnt->setDer(Apunt);
                else
                    if(Apunt==NULL)
                    raiz=NULL;
                    else
                        raiz=Apunt;
                    *Avisa=1;
           }else if(ApAux->getIzq()==NULL)
                {
                    Apunt=ApAux->getDer();
                    if(*Avisa!=0)
                       if(*Avisa<0)
                          ApAnt->setIzq(Apunt);
                       else
                       ApAnt->setDer(Apunt);
                    else
                       if(Apunt==NULL)
                          raiz=NULL;
                       else
                        raiz=Apunt;
                    *Avisa=1;
                }
                else{
                    Sustituye(ApAux->getIzq(),ApAux,Avisa);
                    Apunt=RestructuraI(Apunt,Avisa);
                    if(ApAnt!=NULL)
                        if(*Avisa<=0)
                            ApAnt->setIzq(Apunt);
                        else
                            ApAnt->setDer(Apunt);
                    else
                        raiz=Apunt;
                }
            }
        }
        else
            cout<<"El dato a eliminar no se encuentra reistrado."<<endl;

        }

#endif // AVL_H

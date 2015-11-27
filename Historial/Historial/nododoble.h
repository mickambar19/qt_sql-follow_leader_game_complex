#ifndef NODODOBLE_H
#define NODODOBLE_H
#include <iostream>

using namespace std;
template <class T>
class NodoDoble{
private:
   T elemento;
   NodoDoble<T>* izq;
   NodoDoble<T>* der;
   int FE;
public:
    NodoDoble(T elemento);
    NodoDoble(NodoDoble<T>* a,T elemento,NodoDoble<T>* d);
    void setDato(T a);
    void setIzq(NodoDoble<T>* a);
    void setDer(NodoDoble<T>* a);
    void setFE(int a);
    int getFE();
    T getDato();
    NodoDoble<T>* getIzq();
    NodoDoble<T>* getDer();
    };

template <class T>
NodoDoble<T>::NodoDoble(T elemento){
   this->elemento=elemento;
  der=izq=NULL;}

template <class T>
NodoDoble<T>::NodoDoble(NodoDoble<T>* a,T elemento,NodoDoble<T>* d){
   this->elemento=elemento;
   der=d;
   izq=a;}

template <class T>
T NodoDoble<T>::getDato(){
    return elemento;}
template <class T>
void NodoDoble<T>::setDato(T a){
    elemento=a;
}
template <class T>
NodoDoble<T>* NodoDoble<T>::getDer(){
    return der;}

template <class T>
NodoDoble<T>* NodoDoble<T>::getIzq(){
    return izq;}

template <class T>
void NodoDoble<T>::setDer(NodoDoble<T>* a){
     der=a;}

template <class T>
void NodoDoble<T>::setIzq(NodoDoble<T>* a){
     izq=a;}

template <class T>
void NodoDoble<T>::setFE(int a){
    FE=a;
    }

template <class T>
int NodoDoble<T>::getFE(){
    return FE;
    }


#endif // NODODOBLE_H

#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"
using namespace std;

template <class T>
Queue<T>::Queue() {
    frente = nullptr;
    final = nullptr;
    cantidad = 0;
}

template <class T>
Queue<T>::~Queue() {
    clear();
}

template <class T>
bool Queue<T>::isEmpty() const {
    return frente == nullptr;
}

template <class T>
int Queue<T>::size() const {
    return cantidad;
}

template <class T>
void Queue<T>::push(T valor) {
    Nodo<T>* nuevo = new Nodo<T>(valor);
    if (isEmpty()) {
        frente = nuevo;
        final = nuevo;
    } else {
        final->setSiguiente(nuevo);
        final = nuevo;
    }
    cantidad++;
}

template <class T>
T Queue<T>::pop() {
    if (isEmpty()) {
        throw runtime_error("No se puede desencolar: la cola esta vacia.");
    }
    Nodo<T>* aEliminar = frente;
    T valor = aEliminar->getValor();

    frente = frente->getSiguiente();
    if (frente == nullptr) {
        final = nullptr; // la cola quedo vacia
    }

    delete aEliminar;
    cantidad--;
    return valor;
}

template <class T>
T Queue<T>::front() const {
    if (isEmpty()) {
        throw runtime_error("No se puede consultar el frente: la cola esta vacia.");
    }
    return frente->getValor();
}

template <class T>
void Queue<T>::clear() {
    while (!isEmpty()) {
        pop();
    }
}

template <class T>
Nodo<T>* Queue<T>::getFrenteNodo() const {
    return frente;
}

#endif
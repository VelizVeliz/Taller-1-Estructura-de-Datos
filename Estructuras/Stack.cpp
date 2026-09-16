#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"
using namespace std;

template <class T>
Stack<T>::Stack() {
    tope = nullptr;
    cantidad = 0;
}

template <class T>
Stack<T>::~Stack() {
    clear();
}

template <class T>
bool Stack<T>::isEmpty() const {
    return tope == nullptr;
}

template <class T>
int Stack<T>::size() const {
    return cantidad;
}

template <class T>
void Stack<T>::push(T valor) {
    Nodo<T>* nuevo = new Nodo<T>(valor);
    nuevo->setSiguiente(tope);
    tope = nuevo;
    cantidad++;
}

template <class T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw runtime_error("No se puede desapilar: la pila esta vacia.");
    }
    Nodo<T>* aEliminar = tope;
    T valor = aEliminar->getValor();

    tope = tope->getSiguiente();
    delete aEliminar;
    cantidad--;
    return valor;
}

template <class T>
T Stack<T>::top() const {
    if (isEmpty()) {
        throw runtime_error("No se puede consultar el tope: la pila esta vacia.");
    }
    return tope->getValor();
}

template <class T>
void Stack<T>::clear() {
    while (!isEmpty()) {
        pop();
    }
}

template <class T>
Nodo<T>* Stack<T>::getTopeNodo() const {
    return tope;
}

#endif
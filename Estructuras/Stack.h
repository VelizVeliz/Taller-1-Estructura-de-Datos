#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include "Nodo.h"


template <class T>
class Stack {
private:
    Nodo<T>* tope;
    int cantidad;

public:
    Stack();
    ~Stack();

    bool isEmpty() const;
    int size() const;

    void push(T valor);   
    T pop();               
    T top() const;         
    void clear();           

    
    Nodo<T>* getTopeNodo() const;
};

#include "Stack.cpp"

#endif
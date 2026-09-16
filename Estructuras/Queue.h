#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>
#include "Nodo.h"


template <class T>
class Queue {
private:
    Nodo<T>* frente;
    Nodo<T>* final;
    int cantidad;

public:
    Queue();
    ~Queue();

    bool isEmpty() const;
    int size() const;

    void push(T valor);   
    T pop();               
    T front() const;       
    void clear();           

    
    Nodo<T>* getFrenteNodo() const;
};


#include "Queue.cpp"

#endif
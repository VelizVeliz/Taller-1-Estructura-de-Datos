#ifndef NODO_H
#define NODO_H


template <class T>
class Nodo {
private:
    T valor;
    Nodo<T>* siguiente;

public:
    Nodo(T valor) {
        this->valor = valor;
        this->siguiente = nullptr;
    }

    T getValor() const {
        return valor;
    }

    Nodo<T>* getSiguiente() const {
        return siguiente;
    }

    void setValor(T valor) {
        this->valor = valor;
    }

    void setSiguiente(Nodo<T>* siguiente) {
        this->siguiente = siguiente;
    }

    ~Nodo() {}
};

#endif
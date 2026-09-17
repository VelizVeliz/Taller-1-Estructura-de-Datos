#include "Servicio.h"
#include <iostream>
using namespace std;

Servicio::Servicio(string nombre) {
    this->nombre = nombre;
    this->listaPacientes = nullptr;
    this->cantidadPacientes = 0;
}

Servicio::~Servicio() {
    // Recorremos la lista liberando cada nodo Y el paciente que contiene,
    // ya que el Servicio es quien "recibe" al paciente definitivamente.
    Nodo<Paciente*>* cursor = listaPacientes;
    while (cursor != nullptr) {
        Nodo<Paciente*>* siguiente = cursor->getSiguiente();
        delete cursor->getValor(); // libera el Paciente
        delete cursor;             // libera el nodo
        cursor = siguiente;
    }
    listaPacientes = nullptr;
}

string Servicio::getNombre() const {
    return nombre;
}

int Servicio::getCantidadPacientes() const {
    return cantidadPacientes;
}

bool Servicio::isEmpty() const {
    return listaPacientes == nullptr;
}

// Inserta el paciente al final de la lista enlazada del servicio,
// respetando el orden en que fueron llegando (insertLast manual).
void Servicio::agregarPaciente(Paciente* p) {
    if (p== nullptr){
        return;
    }
    
    Nodo<Paciente*>* nuevo = new Nodo<Paciente*>(p);

    if (listaPacientes == nullptr) {
        listaPacientes = nuevo;
    } else {
        Nodo<Paciente*>* cursor = listaPacientes;
        while (cursor->getSiguiente() != nullptr) {
            cursor = cursor->getSiguiente();
        }
        cursor->setSiguiente(nuevo);
    }
    cantidadPacientes++;
}

// Busca un paciente por su id recorriendo la lista enlazada.
// Retorna nullptr si no fue encontrado (estructura vacia o sin coincidencias).
Paciente* Servicio::buscarPaciente(string id) const {
    Nodo<Paciente*>* cursor = listaPacientes;
    while (cursor != nullptr) {
        if (cursor->getValor()->getId() == id) {
            return cursor->getValor();
        }
        cursor = cursor->getSiguiente();
    }
    return nullptr;
}

void Servicio::mostrarPacientes() const {
    cout << "Pacientes en el departamento de " << nombre << ": "
         << cantidadPacientes << endl;

    Nodo<Paciente*>* cursor = listaPacientes;
    while (cursor != nullptr) {
        Paciente* p = cursor->getValor();
        cout << p->getNombre() << " (" << p->getEdad() << ")" << endl;
        cursor = cursor->getSiguiente();
    }
}
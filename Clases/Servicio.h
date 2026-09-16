#ifndef SERVICIO_H
#define SERVICIO_H

#include <string>
#include "../Estructuras/Nodo.h"
#include "Paciente.h"
using namespace std;


class Servicio {
private:
    string nombre;
    Nodo<Paciente*>* listaPacientes; 
    int cantidadPacientes;

public:
    Servicio(string nombre = "");
    ~Servicio();

    string getNombre() const;
    int getCantidadPacientes() const;
    bool isEmpty() const;

    void agregarPaciente(Paciente* p);
    Paciente* buscarPaciente(string id) const;
    void mostrarPacientes() const;
};

#endif
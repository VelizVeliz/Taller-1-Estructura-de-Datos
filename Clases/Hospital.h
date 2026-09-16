#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>
#include "../Estructuras/Nodo.h"
#include "Servicio.h"
#include "Paciente.h"
#include "../Estructuras/Queue.h"
#include "../Estructuras/Stack.h"
using namespace std;

const int CANTIDAD_SERVICIOS = 8;

class Hospital {
private:
    Nodo<Servicio*>* listaServicios;
    Queue<Paciente*> colaPendientes;
    Stack<string> historial;

    // Busca el nodo del servicio cuyo nombre coincide (recorrido de la lista enlazada)
    Servicio* buscarServicio(string nombreServicio) const;

public:
    Hospital();
    ~Hospital();

    // Crea los 8 servicios fijos del hospital y arma la lista enlazada principal
    void inicializarServicios();

    // Carga los pacientes desde un archivo de texto (usando LectorArchivo)
    // y los va incorporando a la cola de pendientes respetando el orden de llegada
    bool cargarPacientesDesdeArchivo(string nombreArchivo);

    // Muestra la cola de pacientes que aun esperan ser atendidos.
    void mostrarColaPendientes() const;

    // Atiende hasta "cantidad" pacientes de la cola: los retira
    // los deriva a su servicio correspondiente y registra la atencion en el historial
    void atenderPacientes(int cantidad);

    // Muestra el listado de los 8 departamentos o servicios disponibles
    void mostrarServicios() const;

    // Muestra el estado (pacientes actuales) de un servicio en particular
    void mostrarDepartamento(string nombreServicio) const;

    // Muestra el historial completo de atenciones 
    void mostrarHistorial() const;

    bool colaVacia() const;
    int cantidadPacientesEnEspera() const;
};

#endif
#include "Hospital.h"
#include "LectorArchivo.h"
#include <iostream>
using namespace std;

Hospital::Hospital() {
    listaServicios = nullptr;
    inicializarServicios();
}

Hospital::~Hospital() {
    while (!colaPendientes.isEmpty()) {
    Paciente* paciente = colaPendientes.pop();
    delete paciente;
}
    
    Nodo<Servicio*>* cursor = listaServicios;
    while (cursor != nullptr) {
        Nodo<Servicio*>* siguiente = cursor->getSiguiente();
        delete cursor->getValor(); // libera el Servicio
        delete cursor;             // libera el nodo
        cursor = siguiente;
    }
    listaServicios = nullptr;
    
}


void Hospital::inicializarServicios() {
    string nombresServicios[CANTIDAD_SERVICIOS] = {
        "Urgencias", "Medicina General", "Cardiologia", "Neurologia",
        "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"
    };

    string* puntero = nombresServicios;          // puntero al primer nombre
    Nodo<Servicio*>* cola = nullptr;               // ultimo nodo insertado

    for (int i = 0; i < CANTIDAD_SERVICIOS; i++) {
        Servicio* nuevoServicio = new Servicio(*puntero); // *puntero = nombre actual
        Nodo<Servicio*>* nuevoNodo = new Nodo<Servicio*>(nuevoServicio);

        if (listaServicios == nullptr) {
            listaServicios = nuevoNodo;
        } else {
            cola->setSiguiente(nuevoNodo);
        }
        cola = nuevoNodo;

        puntero++; // avanza al siguiente nombre del arreglo 
    }
}

Servicio* Hospital::buscarServicio(string nombreServicio) const {
    Nodo<Servicio*>* cursor = listaServicios;
    while (cursor != nullptr) {
        if (cursor->getValor()->getNombre() == nombreServicio) {
            return cursor->getValor();
        }
        cursor = cursor->getSiguiente();
    }
    return nullptr;
}

Paciente* Hospital::buscarPaciente(string id) const {
    Nodo<Paciente*>* cursorPendientes = colaPendientes.getFrenteNodo();

    while (cursorPendientes != nullptr) {
        Paciente* paciente = cursorPendientes->getValor();

        if (paciente->getId() == id) {
            return paciente;
        }

        cursorPendientes = cursorPendientes->getSiguiente();
    }

    Nodo<Servicio*>* cursorServicios = listaServicios;

    while (cursorServicios != nullptr) {
        Servicio* servicio = cursorServicios->getValor();

        Paciente* paciente = servicio->buscarPaciente(id);

        if (paciente != nullptr) {
            return paciente;
        }

        cursorServicios = cursorServicios->getSiguiente();
    }

    return nullptr;
}




bool Hospital::cargarPacientesDesdeArchivo(string nombreArchivo) {
    LectorArchivo lector;
    int cantidad = 0;
    Paciente** pacientes = lector.cargarPacientes(nombreArchivo, cantidad);

    if (pacientes == nullptr) {
        return false; 
    }

    Paciente** cursor = pacientes; // cursor apunta al primer Paciente* del arreglo
    for (int i = 0; i < cantidad; i++) {
        colaPendientes.push(*cursor); // *cursor = el Paciente* en esa posicion
        cursor++;                      // avanza al siguiente puntero del arreglo
    }

    delete[] pacientes; // solo se libera el arreglo de punteros, no los Paciente
                         // (ahora son responsabilidad de la cola/servicios)
    return true;
}

bool Hospital::colaVacia() const {
    return colaPendientes.isEmpty();
}

int Hospital::cantidadPacientesEnEspera() const {
    return colaPendientes.size();
}

void Hospital::mostrarColaPendientes() const {
    if (colaPendientes.isEmpty()) {
        cout << "No hay pacientes en espera." << endl;
        return;
    }

    cout << "=== PACIENTES EN ESPERA ===" << endl;
    int posicion = 1;
    Nodo<Paciente*>* cursor = colaPendientes.getFrenteNodo();
    while (cursor != nullptr) {
        Paciente* p = cursor->getValor();
        cout << posicion << ". " << p->getId() << " - " << p->getNombre() << endl;
        cursor = cursor->getSiguiente();
        posicion++;
    }
}


void Hospital::atenderPacientes(int cantidad) {
    if (colaPendientes.isEmpty()) {
        cout << "No hay pacientes pendientes por atender." << endl;
        return;
    }

    cout << "=== ATENDIENDO PACIENTES ===" << endl;
    int atendidos = 0;
    while (atendidos < cantidad && !colaPendientes.isEmpty()) {
        Paciente* p = colaPendientes.pop(); // 1. se retira de la cola

        cout << "ID: " << p->getId() << endl;
        cout << "Nombre: " << p->getNombre() << endl;
        cout << "Edad: " << p->getEdad() << endl;
        cout << "Servicio: " << p->getServicio() << endl;

        Servicio* servicio = buscarServicio(p->getServicio()); // 2. se identifica el servicio
        if (servicio != nullptr) {
            servicio->agregarPaciente(p); // 3. se incorpora al servicio
            cout << "Paciente enviado a " << servicio->getNombre() << "." << endl;

            // 4. se registra la atencion en el historial
            string evento = "Nombre: " + p->getNombre() +
                             " | Edad: " + to_string(p->getEdad()) +
                             " | Departamento: " + servicio->getNombre();
            historial.push(evento);
        } else {
            // Caso borde: servicio invalido (no deberia ocurrir si LectorArchivo
            // ya valido el servicio al cargar, pero se controla de todas formas).
            cout << "Error: no existe el servicio '" << p->getServicio()
                 << "'. Paciente no pudo ser derivado." << endl;
            delete p; // evitamos fuga de memoria si el paciente no fue asignado a nadie
        }

        atendidos++;
    }
}

void Hospital::mostrarServicios() const {
    cout << "=== DEPARTAMENTOS/SERVICIOS ===" << endl;
    int numero = 1;
    Nodo<Servicio*>* cursor = listaServicios;
    while (cursor != nullptr) {
        cout << numero << ". " << cursor->getValor()->getNombre() << endl;
        cursor = cursor->getSiguiente();
        numero++;
    }
}

void Hospital::mostrarDepartamento(string nombreServicio) const {
    Servicio* servicio = buscarServicio(nombreServicio);
    if (servicio == nullptr) {
        cout << "Error: el servicio '" << nombreServicio << "' no existe." << endl;
        return;
    }

    cout << "=== ESTADO " << servicio->getNombre() << " ===" << endl;
    servicio->mostrarPacientes();
}

void Hospital::mostrarHistorial() const {
    if (historial.isEmpty()) {
        cout << "Aun no se ha atendido a ningun paciente." << endl;
        return;
    }

    cout << "=== HISTORIAL DE ULTIMAS ATENCIONES DEL HOSPITAL ===" << endl;
    
    Nodo<string>* cursor = historial.getTopeNodo();
    while (cursor != nullptr) {
        cout << cursor->getValor() << endl;
        cursor = cursor->getSiguiente();
    }
}
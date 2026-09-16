#include <iostream>
#include <string>
#include "Clases/Hospital.h"
using namespace std;

int main() {
    Hospital hospital;

    string nombreArchivo = "pacientes.txt";
    if (!hospital.cargarPacientesDesdeArchivo(nombreArchivo)) {
        cout << "No se pudieron cargar pacientes. Verifique el archivo '"
             << nombreArchivo << "'." << endl;
    }

    int opcion = -1;
    while (opcion != 4) {
        cout << endl << "=== HOSPITAL MARMAJA ===" << endl;
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver departamento" << endl;
        cout << "3. Revisar historial de atencion" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccionar opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Opcion invalida." << endl;
            continue;
        }

        switch (opcion) {
            case 1: {
                if (hospital.colaVacia()) {
                    cout << "No hay pacientes en espera." << endl;
                    break;
                }
                hospital.mostrarColaPendientes();
                cout << "Indique la cantidad de pacientes a atender: ";
                int cantidad;
                cin >> cantidad;
                if (cin.fail() || cantidad <= 0) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Cantidad invalida." << endl;
                    break;
                }
                hospital.atenderPacientes(cantidad);
                break;
            }
            case 2: {
                hospital.mostrarServicios();
                cout << "Seleccionar opcion: ";
                int numero;
                cin >> numero;
                // Vuelve a armar el nombre segun el orden fijo declarado en Hospital.
                string nombres[CANTIDAD_SERVICIOS] = {
                    "Urgencias", "Medicina General", "Cardiologia", "Neurologia",
                    "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"
                };
                if (cin.fail() || numero < 1 || numero > CANTIDAD_SERVICIOS) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Opcion invalida." << endl;
                    break;
                }
                hospital.mostrarDepartamento(nombres[numero - 1]);
                break;
            }
            case 3:
                hospital.mostrarHistorial();
                break;
            case 4:
                cout << "Hasta luego." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    }

    return 0;
}
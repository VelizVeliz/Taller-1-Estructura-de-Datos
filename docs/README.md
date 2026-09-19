# Sistema de Gestión Hospitalaria

Proyecto en C++ que simula la atención de pacientes en un hospital, utilizando estructuras de datos manuales (listas enlazadas, colas y pilas) y programación orientada a objetos.

---

## Estructura del proyecto

- Clases principales
  - Clase Persona → Clase base para representar datos generales.
  - Clase Paciente → Hereda de la clase Persona, incluye ID, edad y servicio asignado.
  - Clase Servicio → Representa un departamento del hospital, con lista enlazada de pacientes.
  - Clase Hospital → Controlador principal que gestiona servicios, cola de espera y historial.
  - Clase LectorArchivo → Carga pacientes desde archivo de texto.

- Estructuras genéricas
  - Clase Nodo → Nodo genérico para listas enlazadas.
  - Clase Queue → Cola para pacientes en espera.
  - Clase Stack → Pila para historial de atenciones.

- Archivos
  - main.cpp → Menú interactivo.
  - pacientes.txt → Archivo de entrada con pacientes iniciales.

---

## Formato del archivo pacientes.txt

Cada línea representa un paciente (ID;Nombre;Edad;Servicio)

Ejemplo:

001;Juan Perez;25;Cardiologia
002;Maria Soto;67;Urgencias

---

## Cómo compilar y ejecutar

1. Abrir terminal en la carpeta del proyecto.
2. Compilar con g++:

```bash
g++ main.cpp Clases/*.cpp Estructuras/*.cpp -o hospital

Ejecutar:

./hospital

Opciones del menú

-Atender pacientes → Atiende N pacientes de la cola y los deriva a su servicio.
-Ver departamento → Muestra pacientes actuales en un servicio específico.
-Revisar historial de atención → Lista las últimas atenciones registradas.
-Buscar paciente → Busca por ID en cola y servicios.
-Salir → Termina el programa.

Checklist de pruebas

[] Cargar pacientes desde pacientes.txt.
[] Atender varios pacientes y verificar que se mueven a su servicio.
[] Revisar que el historial se actualiza correctamente.
[] Buscar pacientes por ID en cola y servicios.
[] Probar entradas inválidas (IDs inexistentes, opciones fuera de rango).
[] Confirmar que al salir se libera toda la memoria.

Autores
Maximiliano Castillo
Vicente Veliz
Christian Mardones
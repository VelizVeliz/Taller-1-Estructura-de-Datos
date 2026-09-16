# Taller-1-Estructura-de-Datos

## Compilación y ejecución

### Compilar

Desde la raíz del proyecto (`Taller-1-Estructura-de-Datos`), ejecuta:

```powershell
g++ -Wall -Wextra -g3 main.cpp Clases/Hospital.cpp Clases/Servicio.cpp Clases/LectorArchivo.cpp Clases/Paciente.cpp Clases/Persona.cpp -o output/main.exe
```

> Nota: `Queue.cpp` y `Stack.cpp` no se agregan al comando de compilación porque son clases genéricas (templates); su implementación ya se incluye automáticamente desde `Queue.h` y `Stack.h`.

Alternativa en VS Code: presionar `Ctrl+Shift+B` (usa la tarea `Build Hospital` configurada en `.vscode/tasks.json`).

### Ejecutar

```powershell
./output/main.exe
```

El programa carga automáticamente el archivo `pacientes.txt` ubicado en la raíz del proyecto. Si se desea usar otro archivo, reemplazar ese archivo o modificar el nombre en `main.cpp`.
# Instalación de MSYS2 y la Biblioteca GMP en Windows


## Paso 1: Instalar MSYS2

1. **Descargar el Instalador de MSYS2**
   - Visitar el sitio web oficial de MSYS2: [msys2.org](https://www.msys2.org).
   - hacer clic en **"Download the installer"** para descargar el instalador (`msys2-x86_64-<version>.exe`).

2. **Ejecutar el Instalador**
   - Abrir el archivo instalador descargado.
   - Seguir las instrucciones en pantalla:
     - Aceptar los términos de la licencia.
     - Elegir el directorio de instalación (por defecto es `C:\msys64\`).
     - Haz clic en **"Next"** para continuar.

3. **Actualizar MSYS2**
   - Una vez instalado, abrir **MSYS2** desde el menú de inicio de Windows.
   - En la terminal de MSYS2, ejecutar los siguientes comandos para actualizar el sistema:
     ```sh
     pacman -Syu
     ```
   - Si se te solicita cerrar la terminal después de la actualización, hazlo.
   - Vuelve a abrir la terminal de **MSYS2** y ejecuta:
     ```sh
     pacman -Su
     ```

## Paso 2: Instalar la Biblioteca GMP

1. **Abrir la Terminal de MSYS2**
   - Abre la terminal **MSYS2 MinGW 64-bit** si estás trabajando en un entorno de 64 bits, o **MSYS2 MinGW 32-bit** para un entorno de 32 bits.

2. **Instalar la Biblioteca GMP**
   - Ejecuta uno de los siguientes comandos dependiendo de tu arquitectura:
     - Para **64 bits**:
       ```sh
       pacman -S mingw-w64-x86_64-gmp
       ```
     - Para **32 bits**:
       ```sh
       pacman -S mingw-w64-i686-gmp
       ```

3. **Verificar la Instalación**
   - Verifica que el archivo `gmp.h` esté instalado ejecutando:
     ```sh
     find / -name "gmp.h"
     ```
   - Deberías ver una salida similar a:
     ```
     /mingw64/include/gmp.h  (para 64 bits)
     /mingw32/include/gmp.h  (para 32 bits)
     ```


## Solución de Problemas

- **Problema**: El comando `gcc` no se reconoce.
  - **Solución**: Asegurarse de haber abierto la terminal de MSYS2 correcta (MinGW 64-bit o MinGW 32-bit) y que el paquete `gcc` esté instalado.
- **Problema**: Error al encontrar `gmp.h`.
  - **Solución**: Verificar que se ha instalado el paquete `mingw-w64-x86_64-gmp` o `mingw-w64-i686-gmp` dependiendo de tu sistema y que las rutas de inclusión y biblioteca sean correctas.

- Solucion a problema de gmp.h no encontrado en visual studio Code

    - **Abrir el Archivo de Configuración de `c_cpp_properties.json`**
   - En Visual Studio Code, abre la **Paleta de Comandos** (presiona `Ctrl + Shift + P` o `Cmd + Shift + P` en Mac).
   - Escribe **"C/C++: Editar Configuraciones"** y selecciona la opción para abrir `c_cpp_properties.json`.

    - **Actualizar `includePath`**
   - Agrega las rutas de los archivos de encabezado de MSYS2 a la sección `"includePath"` de tu archivo `c_cpp_properties.json`:
   ```json
   {
     "configurations": [
       {
         "name": "Win32",
         "includePath": [
           "${workspaceFolder}/**",
           "C:/msys64/mingw64/include",  // Para 64 bits
           "C:/msys64/usr/include"
         ],
         "defines": [],
         "windowsSdkVersion": "10.0.19041.0",
         "compilerPath": "C:/msys64/mingw64/bin/gcc.exe",  // Ruta al compilador GCC
         "cStandard": "c11",
         "cppStandard": "c++17",
         "intelliSenseMode": "windows-gcc-x64"
       }
     ],
     "version": 4
   }
   ```

## Paso 3: Compilar proyecto

1. **Compilar el Programa del proyecto**
   - Compilar programa utilizando `gcc` en la terminal:
     ```sh
     gcc -o Proyecto02_CalculoPi_Chudnovsky Proyecto02_CalculoPi_Chudnovsky.c -lgmp -fopenmp
     ```

2. **Ejecutar el Programa**
   - Ejecuta el programa compilado:
     ```sh
     ./Proyecto02_CalculoPi_Chudnovsky
     ```
  
   

## Integrantes

- Jonathan Zacarias
- Ihan Marroquin
- Diego Patzan

 

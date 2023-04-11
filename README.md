# Primer Proyecto - Laboratorio de Estructura de Datos - My Spotify
**Marco Jose Munguia Alva 201931804**
*** 
Este es el repositorio para el primer proyecto del laboratorio de Estructura de Datos, My Spotify. A continuación, se describen los pasos para instalar las dependencias, compilar el proyecto y ejecutarlo.

## Instrucciones de instalación y compilación

1. Abre la línea de comandos e instala make:

```bash
   sudo apt install make
```

2. Dirígete a la carpeta donde están los archivos del proyecto y dale permisos al script:

```bash
   chmod +x InitProject.sh
```

3. A continuación, puedes ejecutar los siguientes comandos:

- Para iniciar el script encargado de instalar las dependencias del proyecto y moverlas a las carpetas necesarias para que el makefile funcione correctamente. Posteriormente, compilará con las reglas dadas en el makefile:

  ```
  make InitProject
  ```

- Para únicamente compilar los archivos fuente y obtener la salida del programa:

  ```
  make
  ```

- Para borrar el programa de salida `my_spotify` y la carpeta `obj` que contiene los archivos `.o` de los archivos `.cpp` compilados:

  ```
  make clean
  ```

4. Una vez compilado el programa, puedes ejecutar en la línea de comandos esta orden para que inicie el programa:

```bash
    ./my_spotify
```


# Primer Proyecto - Laboratorio de Estructura de Datos - My Spotify
**Marco Jose Munguia Alva 201931804**

Este es el repositorio para el primer proyecto del laboratorio de Estructura de Datos, My Spotify. A continuación, se describen los pasos para instalar las dependencias, compilar el proyecto y ejecutarlo.

***
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
***

##Informacion adicional
El proyecto esta estructurado de la siguiente manera:

```bash

  .PrimerProyecto
├── fmodstudioapi20213linux.tar.gz
├── InitProject.sh
├── makefile
├── Musica
│   ├── 50 Cent  Many Men.mp3
│   ├── Arcangel YOVNGCHIMI - La Ruta.mp3
│   ├── Black Sabbath - God Is Dead.mp3
│   ├── CRO Neo Pistea Lucho SSJ Obie Wanshot - WOW.mp3
│   ├── Feid Young Miko - Classy 101.mp3
│   ├── Fuerza Regida X Edgardo Nuñez - Billete Grande.mp3
│   ├── Fuerza Regida X Edgardo Nuñez - Billete Grande.ogg
│   ├── Fuerza Regida x Grupo Frontera - Bebe Dame.mp3
│   ├── Kanye West  Good Morning.mp3
│   ├── Limp Bizkit  Nookie.mp3
│   ├── Marilyn Manson - The Beautiful People.mp3
│   ├── Matando - Gueros 97.mp3
│   ├── Megadeth - Train Of Consequences.mp3
│   ├── MF DOOM - Doomsday.mp3
│   ├── Outkast - Roses.mp3
│   ├── Pantera - Cemetery Gates.mp3
│   ├── Pantera - Im Broken Official.mp3
│   ├── Pantera  - This Love.mp3
│   ├── Peso Pluma Raul Vega El Belicon .mp3
│   ├── Peso Pluma x Alemán - Delivery   .mp3
│   ├── SepulturaArise.mp3
│   ├── Sepultura  Arise.ogg
│   ├── SepulturaArise.ogg
│   ├── Slipknot - Before I Forget.mp3
│   ├── Slipknot - Custer LIVE.mp3
│   ├── Slipknot - Eyeless.mp3
│   ├── Slipknot - Spit It Out.mp3
│   ├── Slipknot - Sulfur.mp3
│   ├── System Of A Down - Toxicity.mp3
│   └── YOVNGCHIMI ft Myke Towers Arcángel Ñengo Flow  Yeruza - BABY FATHER 2.0 .mp3
├── obj
├── pugixml-1.13.tar.gz
├── README.md
├── src
│   ├── BuclePlayer.cpp
│   ├── BuclePlayer.h
│   ├── main.cpp
│   ├── MusicDrivers.cpp
│   ├── MusicDrivers.h
│   ├── MusicPlayer.cpp
│   ├── MusicPlayer.h
│   ├── MusicReader.cpp
│   ├── MusicReader.h
│   ├── NormalPlayer.cpp
│   ├── NormalPlayer.h
│   ├── Player.h
│   ├── song.cpp
│   ├── song.h
│   ├── SongLibrary.cpp
│   └── SongLibrary.h
└── Test
    ├── test_text
    └── test.xml


```
En la ruta `Test/test.xml` se encuentra el archivo XML utilizado para pruebas por ende este es su path relativo a cololar al momento de la carga masiva.

En la ruta `Musica/` se encuentra toda la musica en varios formatos para poder ser reproducida si en caso se llegara a instertar manualmente musica podemos tomar este ruta copmo referencia de donde se encuentra toda la biblioteca.

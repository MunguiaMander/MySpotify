#Marco Jose Munguia Alva 201931804

#Instalamos lo necesario
sudo apt install g++
sudo apt install gcc
sudo apt install cmake

echo -e "\n\nInstallando Librerias mediante un script"

#Extraemos el archivo de FMOD (Libreria para la reproduccion de Musica)
echo -e "\n\nExtrayendo fmodstudioapi20213linux.tar.gz..."
tar -xzf "fmodstudioapi20213linux.tar.gz" --totals

#Creamos el directorio para alojar la API
sudo mkdir -p /usr/include/fmod/

#Movemos los Headers y las librerias al directorio anteriormente creado
sudo cp fmodstudioapi20213linux/api/core/inc/* /usr/include/fmod/
sudo cp fmodstudioapi20213linux/api/core/lib/x86_64/* /usr/lib/

# Verificar la instalación de FMOD
if find /usr/include/ | grep -q /usr/include/fmod/; then
  echo -e "\n\n\nHeaders FMOD instaladas!"

  if find /usr/lib/ | grep -q /usr/lib/libfmod; then
    echo "Librerías FMOD instaladas!"
    echo "FMOD instalado correctamente!"
    #Eliminamos los archivos que no serviran
    sudo rm -rf fmodstudioapi20213linux/
    echo "Libreria fmodstudioapi20213linux eliminada correctamente"
  else
    echo "Error: no se encontraron las librerías de FMOD."
    exit 1
  fi
  
else
  echo "Error: no se encontraron los headers de FMOD."
  exit 1
fi



#Etraemos la libreria PugiXML para facilitar la lectura de archivos XML

echo -e "\n\nExtrayendo pugixml-1.13.tar.gz..."
tar -xzf "pugixml-1.13.tar.gz" --totals

#Creamos un directorio de Compilacion
cd pugixml-1.13/
mkdir build
cd build

#Ejecutamos CMake
cmake ..

#Compilamos e Instalamos bibliotecas
make
sudo make install

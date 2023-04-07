#Marco Jose Munguia Alva 201931804
echo -e "\n\nInstallando FMOD mediante un script"

#Extraemos el archivo
echo -e "\n\nExtrayendo fmodstudioapi20213linux.tar.gz..."
tar -xzf "fmodstudioapi20213linux.tar.gz" --totals

#Creamos el directorio para alojar la API
sudo mkdir -p /usr/include/fmod/

#Movemos los Headers y las librerias al directorio anteriormente creado
sudo cp fmodstudioapi20213linux/api/core/inc/* /usr/include/fmod/
sudo cp fmodstudioapi20213linux/api/core/lib/x86_64/* /usr/lib/

#Condicionales para verificar instalacion
if find /usr/include/ | grep -q /usr/include/fmod/; then
  echo -e "\n\n\nHeaders FMOD Instaladas!"

  if find /usr/lib/ | grep -q /usr/lib/libfmod; then
    echo "Librerias FMOD Instaladas!"
    echo "FMOD instalado Correctamente!"
    exit 0
  fi
  
fi
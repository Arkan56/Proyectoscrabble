#Tomamos la imagen de gcc previamente instalada
FROM gcc 

#Creamos el directorio de trabajo en el contenedor  
WORKDIR /usr/src/project

#Copiamos los archivos necesarios del directorio actual al directorio del contenedor
COPY . .

#Especificamos los comandos que se ejecutara en el contenedor al correrlo
RUN g++ -std=c++11 -o scrabble main.cpp
CMD ["./scrabble"]
# Scrabble

Este proyecto implementa un sistema de apoyo para el juego Scrabble. La aplicación recibe comandos textuales y está compuesta por varios componentes que gestionan distintas funcionalidades del juego.

## Descripción del Proyecto

El objetivo del proyecto es construir un sistema interactivo para el juego Scrabble, que permite a los usuarios gestionar el diccionario del juego, buscar palabras por prefijos o sufijos, y generar posibles combinaciones de palabras a partir de un conjunto de letras.
Haciendo uso de las diferentes estructuras de datos que se pueden usar en un lenguaje de programación como c++

### Comandos Principales

- **`inicializar diccionario.txt`**: Inicializa el sistema con un diccionario de palabras.
- **`puntaje palabra`**: Muestra la puntuación de una palabra si es válida.
- **`palabras_por_prefijo prefijo`**: Muestra todas las palabras que empiezan con el prefijo dado.
- **`palabras_por_sufijo sufijo`**: Muestra todas las palabras que terminan con el sufijo dado.
- **`posibles_palabras letras`**: Genera todas las palabras válidas que se pueden construir con las letras dadas.

### Requisitos

- **g++**: Se requiere la versión 4.0.0 o superior para compilar el código fuente.
- **Docker**: Se puede utilizar Docker para construir y ejecutar el entorno del proyecto.

### Compilación y Ejecución

1. **Compilación con g++**:
   ```bash
   g++ -std=c++11 -o main main.cpp
   ```
2. **Ejecución**
   ```
   ./main
   ```
   
### Ejecución mediante docker (Linux)

1. **Verficar que se posee la herramienta**:
   ```
   sudo docker
   ```
   Si se cuenta con la herramienta se desplegara una lista de comandos.
2. **Obtener la imagen gcc**:
   ```
   sudo docker pull gcc
   ```
   Docker pull trae la imagen que necesitemos desde docker hub
4. **Construir el contenedor**:
   ```
   sudo docker -t scrabble
   ```
   Con este comando crearemos el contenedor con base a la estructura definida en el dockerfile y le definiremos el nombre de "scrabble".
5. **Correr el contenedor**
   ```
   sudo docker run -it scrabble
   ```
   Con run correremos el contenedor anteriormete construido. La bandera "-it" permite que el contenedor se ejecute de manera interactiva, es decir que nos permitira interactuar con nuestro programa.
   
   
   

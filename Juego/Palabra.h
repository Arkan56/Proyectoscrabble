#ifndef PALABRA_H
#define PALABRA_H

#include <unordered_map>
#include <unordered_set>

struct Palabra
{
    std::string contenido;
    int puntaje;
    bool inverso;
};

bool verificarPalabra(std::string palabra); //la funcion comprobara que la cadena de caracteres enviada no contenga valores invalidos
                                       //como lo pueden ser numeros, signos, guiones, etc.

std::string tolowercase(std::string cadena); //La funcion convertira todas las letras de la cadena ingresada a minusculas

void calcularPuntaje(Palabra *palabra); //La funcion recive un apuntador de palabra para referirce al diccionario del sistema
                                       //y segun la palabra recivida calcula su puntaje segun el esquema presentado en el enunciado

std::string invertirCadena(std::string cadena); //Dada una cadena la funcion invertira su orden (hola = aloh)

bool compararContenido(std::string contenido, std::string contenido2); //Compara los contenidos mandados como parametros, retornara verdadero 
                                                         //si y sólo sí difierenen un única letra (con las demás letras iguales y en las mismas posiciones)
bool operator==(const Palabra& a, const Palabra& b); //Sobrecargar el operador == para la estructura palabra

std::unordered_map<char, int> contarLetras(const std::string &cadena); // Función para contar las letras de una cadena.
                                                // Permite verificar la disponibilidad de letras necesarias para construir palabras específicas.

bool sePuedeConstruir(const std::string &palabra, std::unordered_map<char, int> letrasDisponibles, int comodines); 
                                                // Verifica si una palabra se puede construir con un conjunto de letras y comodines dados.

#include "Palabra.hxx"

#endif 
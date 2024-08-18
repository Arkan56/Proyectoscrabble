#ifndef MANEJOGRAFO_H
#define MANEJOGRAFO_H

#include "Grafo.h"
#include "../Juego/Palabra.h"

void iniciarGrafo(Grafo<Palabra, int> &grafo, std::vector<Palabra> diccionario);
std::vector<std::string> encontrarPalabrasValidas(Grafo<Palabra, int> &grafo, const std::string &letras);

#include "ManejoGrafo.hxx"

#endif
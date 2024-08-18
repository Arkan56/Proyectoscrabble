#ifndef MANEJOARBOL_H
#define MANEJOARBOL_H

#include <iostream>
#include <fstream>
#include <list>
#include "../Juego/Palabra.h"
#include "ArbolAVL.h"

bool inicializarArbol(ArbolAVL<Palabra> &arbol, std::string arch);
bool inicializarArbolInv(ArbolAVL<Palabra> &arbol, std::string arch);
std::list<std::string> prefijo(ArbolAVL<Palabra> &arbol, std::string pref);
std::list<std::string> subfijo(ArbolAVL<Palabra> &arbol, std::string subf);

#include "ManejoArbol.hxx"
#endif
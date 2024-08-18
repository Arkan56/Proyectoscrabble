#ifndef MANEJODICCIONARIO_H
#define MANEJODICCIONARIO_H

#include <iostream>
#include <fstream>
#include <list>
#include "Palabra.h"


std::list<Palabra> inicializarDiccionario(std::string arch); //La funcion recive el nombre del archivo con el cual inicializara el sistema
                                                        //y devolvera una lista con las palabras validas para su uso
                                                    

std::list<Palabra> inicializarInverso(std::string arch);     //La funcion recive el nombre del archivo con el cual inicializara el sistema
                                                        //y devolvera una lista con las palabras (leidas de izquiera a derecha) 
                                                        //validas para su uso

void imprimirDiccionario(std::list<Palabra> diccionario); //Segun un diccionario la funcion imprimira el contenido de este (contenido, puntaje, inverso) por
                                                          //cada palabra que se haya ingresado  

Palabra buscarPuntaje(std::list<Palabra> &diccionario, std::string cadena); //La funcion mediante una cadena buscara la palabra correspondiente y la retornara

#include "ManejoDiccionario.hxx"

#endif 
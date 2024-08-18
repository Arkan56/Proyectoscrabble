#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "Comando.h"
#include <iostream> //Libreria para poder mostrar los datos en la terminal y recivirlos
#include <fstream>  //Libreria para poder leer archivos
#include <string>   //libreria para el stoi
#include <iomanip>  //libreria para el setw
#include <vector>
#include <sstream>
#include <string>

void inicializarComnados (std::vector<Comando> &comandos);                           //Esta funcion nos sirve para obtener los datos del archivo comandos.txt para poder llenar un arreglo de la estructura Comando
void mostrarComandos(std::vector<Comando> &comandos);                      //Muestra los comandos en un formato que se parece al de windows cuando se teclea help en el cmd
void mostrarInvocacion(std::vector<Comando> &comandos, std::string comando);    //Muestra la invocacion de un comando como en una consola 
Comando buscarComando(std::vector<Comando> &comandos, std::string comando);    //Busca un comando por su nombre 
std::vector<std::string> dividirComandoEnPalabras(std::string comandoEntero);      //Segmenta un comando por palabras

#include "Interfaz.hxx"

#endif 
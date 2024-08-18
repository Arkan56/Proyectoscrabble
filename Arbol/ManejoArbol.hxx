#include "ManejoArbol.h"

bool inicializarArbol(ArbolAVL<Palabra> &arbol, std::string arch)
{
    std::ifstream entrada(arch);
    if(!entrada)
    {
        return false;
    }
    std::string linea;
    while(getline(entrada,linea))
    {
        linea = tolowercase(linea);
        if(verificarPalabra(linea))
        {
            Palabra palabra;
            palabra.contenido = linea;
            palabra.inverso = false;
            calcularPuntaje(&palabra);
            arbol.insert(palabra);
        }
    }
    entrada.close();
    return true;
}

bool inicializarArbolInv(ArbolAVL<Palabra> &arbol, std::string arch)
{
    std::ifstream entrada(arch);
    if(!entrada)
    {
        return false;
    }
    std::string linea;
    while(getline(entrada,linea))
    {
        linea = tolowercase(linea);
        if(verificarPalabra(linea))
        {
            Palabra palabra;
            palabra.contenido = invertirCadena(linea);
            calcularPuntaje(&palabra);
            palabra.inverso = true;
            arbol.insert(palabra);
        }
    }
    entrada.close();
    return true;
}

std::list<std::string> prefijo(ArbolAVL<Palabra> &arbol, std::string pref);
std::list<std::string> subfijo(ArbolAVL<Palabra> &arbol, std::string subf);
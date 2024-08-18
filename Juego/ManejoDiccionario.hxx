#include "ManejoDiccionario.h"

std::list<Palabra> inicializarDiccionario(std::string arch)
{
    std::list<Palabra> diccionario;
    std::ifstream entrada(arch);
    if(!entrada)
    {
        return diccionario;
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
            diccionario.push_back(palabra);
        }
    }
    entrada.close();
    return diccionario;
}

std::list<Palabra> inicializarInverso(std::string arch)
{
    std::list<Palabra> diccionario;
    std::ifstream entrada(arch);
    if(!entrada)
    {
        return diccionario;
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
            diccionario.push_back(palabra);
        }
    }
    entrada.close();
    return diccionario;
}


void imprimirDiccionario(std::list<Palabra> &diccionario)
{
    for(auto it = diccionario.begin(); it != diccionario.end(); it++ )
    {
        std::cout << it->contenido << std::endl;
        std::cout << it->puntaje << std::endl;
        std::cout << it->inverso << std::endl;
    }
}

Palabra buscarPuntaje(std::list<Palabra> &diccionario, std::string cadena)
{
    for(auto it = diccionario.begin(); it != diccionario.end(); it++)
    {
        if(it->contenido == cadena)
        {
            return *it;
        }
    }
    Palabra fake;
    fake.contenido = "NVLD";
    return fake;
}
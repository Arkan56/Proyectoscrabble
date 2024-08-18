#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <map>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

template <class T,class C>
class Grafo
{
    private:
    std::vector<T> vertices;
    std::vector<std::vector<C>> aristas;

    public:

    //Constructor
    Grafo();

    //Metodos de ayuda
    int buscarVertice(T vertice);
    int nVertices();

    //Metodos de insercion y eliminacion
    bool insertarVertice(T vertice);
    bool insertarArista(T origen, T destino, C peso);
    bool eliminarVertice(T vertice);
    bool eliminarArista(T origen, T destino);
    void iniciarMatrizAdy();

    //Metodos de impresion
    void imprimir();

    //Recorridos
    void dfs(int nodo, std::unordered_map<char, int> letrasDisponibles, int comodines, std::unordered_set<int> &visitados, std::vector<std::string> &resultado);

};

#include "Grafo.hxx"
#endif
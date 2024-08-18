#include "ManejoGrafo.h"

void iniciarGrafo(Grafo<Palabra, int> &grafo, std::vector<Palabra> diccionario)
{
    int n = diccionario.size();
    for (int i = 0; i < diccionario.size(); i++)
    {
        grafo.insertarVertice(diccionario[i]);
    }
    grafo.iniciarMatrizAdy();
    for(int i = 0; i < n; i++)
    {
        for(int j = i +1; j < n; j++)
        {
            if(compararContenido(diccionario[i].contenido, diccionario[j].contenido))
            {
                grafo.insertarArista(diccionario[i], diccionario[j], 1);
                grafo.insertarArista(diccionario[j], diccionario[i], 1);
            }
        }
    }
}

std::vector<std::string> encontrarPalabrasValidas(Grafo<Palabra, int> &grafo, const std::string &letras) {
    std::unordered_map<char, int> conteoLetras = contarLetras(letras);
    int comodines = conteoLetras['?'];
    conteoLetras.erase('?');

    std::unordered_set<int> visitados;
    std::vector<std::string> resultado;

    // Iniciar DFS desde cada nodo del grafo
    for (int i = 0; i < grafo.nVertices(); ++i) {
        grafo.dfs(i, conteoLetras, comodines, visitados, resultado);
    }
    return resultado;
}
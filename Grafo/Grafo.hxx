#include "Grafo.h"

//Constructos
template <class T, class C>
Grafo<T,C>::Grafo() {
    vertices.clear();
    aristas.clear();
}


//Metodos de ayuda
template <class T, class C>
int Grafo<T, C>::buscarVertice(T vertice)
{
    int pos = 0;
    //verificar que el vertice no exista ya
    for (const T& v : vertices) {
        if (v == vertice) {
            // El vértice ya existe, por lo que retornamos la posicion
            return pos;
        }
        pos ++;
    }
    //si no se encuentra retornamos -1
    return -1;
} 

template <class T, class C>
int Grafo<T, C>::nVertices()
{
    return this->vertices.size();
}


//Metodos de insercion y eliminacion
template <class T, class C>
bool Grafo<T, C>::insertarVertice(T vertice)
{
    //verificar que el vertice no exista ya
    if(buscarVertice(vertice) != -1)
    {
        return false;
    }

    //De lo contrario insertar el vertice con sus aristas
    vertices.push_back(vertice);
    std::vector<int> nuevasAristas(vertices.size(), 0); 
    aristas.push_back(nuevasAristas);
    // Insertar una columna vacía en cada fila de la matriz de aristas
    for (int i = 0; i < aristas.size() - 1; ++i) {
        aristas[i].push_back(0);
    }
    return true;
}


template <class T, class C>
bool Grafo<T, C>::insertarArista(T origen, T destino, C peso)
{
    int posOrg = buscarVertice(origen);
    int posDes = buscarVertice(destino);
    if(posOrg != -1 && posDes != -1)
    {
        aristas[posOrg][posDes] = peso;
        return true;         
    }
    return false;
}

template <class T, class C>
bool Grafo<T,C>::eliminarVertice(T vertice)
{
    int posV = buscarVertice(vertice);
    if(posV != -1)
    {
        std::cout << std::endl;
        vertices.erase(vertices.begin()+posV);
        aristas.erase(aristas.begin()+posV);
        for(std::vector<T>& fila : aristas)
        {
            fila.erase(fila.begin()+posV);
        }
        return true;
    }
    return false;
}

template <class T, class C>
bool Grafo<T, C>::eliminarArista(T origen, T destino)
{
    int posOrg = buscarVertice(origen);
    int posDes = buscarVertice(destino);
    if(posOrg != -1 && posDes != -1 )
    {
        aristas[posOrg][posDes] = 0;
        return true;
    }
    return false;
}

template<class T, class C>
void Grafo<T, C>::iniciarMatrizAdy() {
    int n = this->vertices.size();
    this->aristas.resize(n, std::vector<C>(n, 0));
}


template <class T, class C>
void Grafo<T, C>::imprimir()
{
    int tam = aristas.size();
    for(int i = 0; i < tam; i++)
    {
        std::cout << vertices[i] << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            std::cout << aristas[i][j] << " ";
        }
        std::cout << std::endl;
        
    }
}

template <class T, class C>
void Grafo<T, C>::dfs(int nodo, std::unordered_map<char, int> letrasDisponibles, int comodines, std::unordered_set<int> &visitados, std::vector<std::string> &resultado) {
    // Marcar el nodo como visitado
    visitados.insert(nodo);

    // Verificar si la palabra actual se puede construir
    if (sePuedeConstruir(this->vertices[nodo].contenido, letrasDisponibles, comodines)) {
        std::string linea = "Palabra: " + vertices[nodo].contenido + 
                        ", Longitud: " + std::to_string(vertices[nodo].contenido.length()) + 
                        ", Puntuación: " + std::to_string(vertices[nodo].puntaje);
        resultado.push_back(linea);
    }

    // Recorrer los nodos adyacentes
    for (int i = 0; i < this->aristas[nodo].size(); ++i) {
        if (this->aristas[nodo][i] == 1 && visitados.find(i) == visitados.end()) {
            // Actualizar las letras disponibles para la llamada recursiva
            std::unordered_map<char, int> nuevasLetrasDisponibles = letrasDisponibles;
            int nuevosComodines = comodines;
            for (char letra : this->vertices[nodo].contenido) {
                if (nuevasLetrasDisponibles[letra] > 0) {
                    nuevasLetrasDisponibles[letra]--;
                } else {
                    nuevosComodines--;
                }
            }
            dfs(i, nuevasLetrasDisponibles, nuevosComodines, visitados, resultado);
        }
    }

    // Desmarcar el nodo como visitado
    //visitados.erase(nodo);
}


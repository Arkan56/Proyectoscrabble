#include <iostream> //Libreria para poder mostrar los datos en la terminal y recivirlos
#include <fstream>  //Libreria para poder leer archivos
#include <string>   //libreria para el stoi
#include <iomanip>  //libreria para el setw
#include <vector>
#include <sstream>
#include <string>
#include "Sistema/Interfaz.h"
#include "Sistema/Comando.h"
#include "Juego/ManejoDiccionario.h"
#include "Arbol/ManejoArbol.h"
#include "Arbol/ArbolAVL.h"
#include "Grafo/Grafo.h"
#include "Grafo/ManejoGrafo.h"

bool procesarComando(std::vector<Comando> &comandos, std::string comando);    //Busca y gestina el procesamiento de los comandos

using namespace std; 

list<Palabra> diccionario;
list<Palabra> diccionarioinv;
ArbolAVL<Palabra> arbol;
ArbolAVL<Palabra> arbolinv;
Grafo<Palabra, int> grafo;

int cont = 0;

int main(int argc, char **argv)
{
    vector<Comando> comandos;                               //Esta parte es de prueba para ver que funcionaban las 3 funciones
    inicializarComnados(comandos);                          //pero es importante crear le apuntador de comandos aqui por que lo vamos a usar por referencia    
                                                              //o sea que cuando llamemos a una funcion y lo pasemos como parametro este se modifique para todo el codigo como una variable global
    string linea;
    bool bandera;
    do
    {
        cout << "$";
        getline(cin, linea);
        bandera = procesarComando(comandos, linea);
    }while(linea != "salir");
    return 0;
}

bool procesarComando(std::vector<Comando> &comandos, std::string comando)
{
    std::vector<std::string> comandoDividido = dividirComandoEnPalabras(comando);
    Comando veri;
    if(comandoDividido[0] == "salir")
    {
        return true;
    }
    if(comandoDividido[0] == "ayuda")
    {
        if(comandoDividido.size() > 2)
        {
            std::cout << "Numero de parametros invalido" <<std::endl;
            return false;
        }
        if(comandoDividido.size() == 2)
        {
            veri = buscarComando(comandos, comandoDividido[1]);
            if(veri.nombre == "null")
            {
                std::cout << "Comando no encontrado" <<std::endl;
                return false;
            }
            mostrarInvocacion(comandos, veri.nombre);
            return true;
        }
        mostrarComandos(comandos);
        return true;
    } 
    veri = buscarComando(comandos, comandoDividido[0]);
    if(veri.nombre == "null")
    {
        std::cout << "Comando no encontrado" <<std::endl;
        return false;
    }
    if(veri.nParametros == comandoDividido.size() -1)
    {
        if(veri.nombre == "inicializar")
        {
            if(!diccionario.empty())
            {
                cout << "Diccionario ya inicializado" <<endl;
                return false;
            }
            diccionario.clear();
            diccionario = inicializarDiccionario("Archivos/" + comandoDividido[1]);
            if(diccionario.empty())
            {
                std::cout << "Archivo no existe" << std::endl;
                return false;
            }
            std::cout << "Resultado exitoso" <<std::endl;
            return true;
        }
        if(veri.nombre == "iniciar_inverso")
        {
            if(!diccionarioinv.empty())
            {
                cout << "Diccionario ya inicializado" <<endl;
                return false;
            }
            diccionarioinv.clear();
            diccionarioinv = inicializarInverso("Archivos/" + comandoDividido[1]);
            if(diccionarioinv.empty())
            {
                std::cout << "Archivo no existe" << std::endl;
                return false;
            }
            std::cout << "Resultado exitoso" <<std::endl;
            return true;
        }
        if(veri.nombre == "puntaje")
        {
            Palabra palabra;
            comandoDividido[1] = tolowercase(comandoDividido[1]);
            if(!verificarPalabra(comandoDividido[1]))
            {
                cout << "Letras invalidas" << endl;
                return false;
            }
            palabra = buscarPuntaje(diccionario, comandoDividido[1]);
            if(palabra.contenido == "NVLD")
            {
                palabra = buscarPuntaje(diccionarioinv, comandoDividido[1]);
                if(palabra.contenido == "NVLD")
                {
                    cout << "Palabra no existe" << endl;
                    return false;
                }
            }
            std::cout << "Puntaje: "<<palabra.puntaje << std::endl;
            std::cout << "Resultado exitoso" <<std::endl;
            return true;
        }
        if(veri.nombre == "iniciar_arbol")
        {
            if(!arbol.esVacio())
            {
                cout << "Arbol ya inicializado" << endl;
                return false;
            }
            if(inicializarArbol(arbol,"Archivos/" + comandoDividido[1]))
            {
                cout << "Resultado exitoso" << endl;
            }
            else
            {
                cout << "Archivo no existe" << endl;
                return false;
            }
            return true;
        }
        if(veri.nombre == "iniciar_arbol_inverso")
        {
            if(!arbolinv.esVacio())
            {
                cout << "Arbol ya inicializado" << endl;
                return false;
            }
            if(inicializarArbolInv(arbolinv,"Archivos/" + comandoDividido[1]))
            {
                cout << "Resultado exitoso" << endl;
            }
            else
            {
                cout << "Archivo no existe" << endl;
                return false;
            }
            return true;
        }
        if(veri.nombre == "palabras_por_prefijo")
        {
            std::list<Palabra> p;
            std::string prefijo = comandoDividido[1];
            arbol.buscarPrefijo(prefijo, p);
            arbolinv.buscarPrefijo(prefijo, p);
            if(p.empty())
            {
                cout << "Prefijo invalido" << endl;
                return false;
            }
            cout << "Las palabras que inician con este prefijo son:" << endl;
            for(auto it = p.begin(); it != p.end(); it++)
            {
                cout << "Palabra: " << it->contenido << endl;
                cout << "Longitud: " << it->contenido.length() << endl;
                cout << "Puntaje: " << it->puntaje << endl;
            }
            cout << endl;
            return true;
        }
        if(veri.nombre == "palabras_por_sufijo")
        {
            std::list<Palabra> p;
            std::string subfijo = comandoDividido[1];
            arbol.buscarSubfijo(subfijo, p);
            arbolinv.buscarSubfijo(subfijo, p);
            if(p.empty())
            {
                cout << "Prefijo invalido" << endl;
                return false;
            }
            cout << "Las palabras que terminan con este sufijo son:" << endl;
            for(auto it = p.begin(); it != p.end(); it++)
            {
                cout << "Palabra: " << it->contenido << endl;
                cout << "Longitud: " << it->contenido.length() << endl;
                cout << "Puntaje: " << it->puntaje << endl;
            }
            return true;
        }
        if(veri.nombre == "grafo_de_palabras")
        {
            std::vector<Palabra> dic;
            if(diccionario.empty())
            {
                std::cout << "Diccionario vacio" << std::endl;
                return false; 
            }
            for(auto i = diccionario.begin(); i != diccionario.end(); i++)
            {
                dic.push_back(*i);
            }
            iniciarGrafo(grafo,dic);
            std::cout << "Resultado exitoso" << std::endl;
            return true;
        }
        if(veri.nombre == "posibles_palabras")
        {
            std::string letras = comandoDividido[1];
            letras = tolowercase(comandoDividido[1]);
            int cuentaInterrogacion = 0;
            for(char c : letras) {
                if (c == '?') {
                    cuentaInterrogacion++;
                    if (cuentaInterrogacion > 1) {
                        std::cout << "Letras invalidas" << std::endl;
                        return false;
                    }
                } else if (c < 'a' || c > 'z') {
                    std::cout << "Letras invalidas" << std::endl;
                    return false;
                }
            }
            std::vector<std::string> resultado = encontrarPalabrasValidas(grafo, letras);
            if(resultado.empty())
            {
                std::cout << "No hay posibles palabras para las letras: " << letras << std::endl;
                return false; 
            }
            std::cout << "Resultado exitoso" << std::endl;
            std::cout << "Las posibles palabras a construir con las letras: " << letras << " son:" << std::endl;
            return true;
        }

        else
        {
            cout << "Comando no disponible en estos momentos" << endl;
            return false;
        }
    }
    std::cout << "Numero de parametros invalido" <<std::endl;
    return false;
}

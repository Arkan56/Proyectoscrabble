#include "Interfaz.h"

void inicializarComnados (std::vector<Comando> &comandos)
{
    Comando comando;
    std::ifstream entrada ("Archivos/comandos.txt");                      //Se crea el flujo con el archivo comandos.txt para leerlo
    if(!entrada)                                            // Se verifica que haya encontrado el archivo, si no es asi se deja de ejecutar el programa
    {
        std::cout<<"El archivo no se encontro"<<std::endl;
        exit(1);
    }
    int tam;                                                // indica el numero de comandos que se van a leer
    std::string line;                                            // La usamos para obtener cada linea del texto y leerlo mas facil con el comando getline
    getline(entrada, line); 
    tam = stoi(line);                                       // se obtiene el tamaño atravez de la primera linea del archivo de comandos la cual nos indica el numero de comandos y lo convertimos de string a int                          
    int cont = 0;
    while(cont < tam)                                       //verificamos que aun queden comandos por leer, si no es asi dejamos de leer el archivo
    {
        getline(entrada, line);
        comando.nombre = line;
        getline(entrada, line);
        comando.nParametros = stoi(line);
        getline(entrada, line);
        comando.invocacion = line;                                               //En general en esta parte hacemos lectura del archivo
        getline(entrada, line);                                                         //y lo guardamos en el arreglo que creamos
        comando.nSalidas = stoi(line);
        comando.salidas = new std::string[comando.nSalidas];
        for(int i = 0; i<comando.nSalidas; i++)
        {
            getline(entrada, line);
            comando.salidas[i] = line;
        }
        getline(entrada, line);
        comando.descripcion = line;
        comandos.push_back(comando);
        cont++;
    }
    entrada.close();
    return;                                                                          //Retornamos el numero de comandos para que podamos saberlo en el resto del codigo
}

void mostrarComandos(std::vector<Comando> &comandos){
    int tam = comandos.size();
    for(int i = 0; i < tam; i++)
    {
        std::cout << std::setw(40) << std::left << comandos[i].nombre <<                          //Mostramos en la terminal de manera organizada mediante el setw que crea como el formato
                std::setw(40) << std::left << comandos[i].descripcion << std::endl;
    }
    std::cout << std::endl;
    return;
}

void mostrarInvocacion(std::vector<Comando> &comandos, std::string comando)
{
    int tam = comandos.size();
    for(int i = 0; i < tam; i++)
    {
        if(comandos[i].nombre == comando)
        {
            std::cout<<comandos[i].descripcion<<std::endl<<std::endl;
            std::cout<<comandos[i].invocacion<<std::endl;
        }
    }
    return;
}

Comando buscarComando(std::vector<Comando> &comandos, std::string comando)
{
    int tam = comandos.size();
    for(int i = 0; i < tam; i++)
    {
        if(comandos[i].nombre == comando)
        {
            return comandos[i];
        }
    }
    Comando fake;
    fake.nombre = "null";
    return fake;
}

std::vector<std::string> dividirComandoEnPalabras(std::string comandoEntero){
    std::vector<std::string> comandoDividido;
    std::stringstream ss(comandoEntero);
    std::string token;

    while (getline(ss, token, ' ')) {
        comandoDividido.push_back(token);
    }

    return comandoDividido;
}


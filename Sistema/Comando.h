#ifndef COMANDO_H
#define COMANDO_H

#include <string>
// La estructura comando nos ayuda a almacenar toda la infomacion que le corresponde a un comando segun el texto
struct Comando
{
    std::string nombre;
    std::string invocacion;
    int nSalidas;
    std::string *salidas;
    std::string descripcion;
    int nParametros;
};

#endif
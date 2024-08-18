#include "Palabra.h"

bool verificarPalabra(std::string palabra)
{
    for(char c : palabra)
    {
        if( c < 97 || c > 122 )
        {
            return false;
        }
    }
    return true;
}

std::string tolowercase(std::string cadena)
{
    for(char &c : cadena)
    {
        c = tolower(c);
    }
    return cadena;
}

void calcularPuntaje(Palabra *palabra)
{
    palabra->puntaje = 0;
    for(char &c : palabra->contenido)
    {
        if(c == 'e' || c == 'a' || c == 'i' || c == 'o' ||
           c == 'n' || c == 'r' || c == 't' || c == 'l' ||
           c == 's' || c == 'u' )
        {
            palabra->puntaje += 1;
        }
        else if(c == 'd' || c == 'g')
        {
            palabra->puntaje += 2;
        }
        else if(c == 'b' || c == 'c' || c == 'm' || c == 'p')
        {
            palabra->puntaje += 3;
        }
        else if(c == 'f' || c == 'h' || c == 'v' || c == 'w' || c == 'y')
        {
            palabra->puntaje += 4;
        }
        else if(c == 'k')
        {
            palabra->puntaje += 5;
        }
        else if(c == 'j' || c == 'x')
        {
            palabra->puntaje += 8;
        }
        else if(c == 'q' || c == 'z')
        {
            palabra->puntaje += 10;
        }
    }
}

std::string invertirCadena(std::string cadena)
{
    std::string cadenaInvertida;
    for (int i = cadena.length() - 1; i >= 0; i--) 
    {
        cadenaInvertida += cadena[i];
    }
    return cadenaInvertida;
}

bool compararContenido(std::string contenido, std::string contenido2)
{
    if (contenido.length() != contenido2.length()) {
        return false;
    }

    int contadorDiferencias = 0;
    for (int i = 0; i < contenido.length(); ++i) {
        if (contenido[i] != contenido2[i]) {
            ++contadorDiferencias;
            if (contadorDiferencias > 1) {
                return false;
            }
        }
    }

    return contadorDiferencias == 1;
}

bool operator==(const Palabra& a, const Palabra& b){
    return (a.contenido == b.contenido) && (a.contenido == b.contenido);
}  

std::unordered_map<char, int> contarLetras(const std::string &cadena) {
    std::unordered_map<char, int> conteo;
    for (char letra : cadena) {
        conteo[letra]++;
    }
    return conteo;
}

bool sePuedeConstruir(const std::string &palabra, std::unordered_map<char, int> letrasDisponibles, int comodines) {
    for (char letra : palabra) {
        if (letrasDisponibles[letra] > 0) {
            letrasDisponibles[letra]--;
        } else if (comodines > 0) {
            comodines--;
        } else {
            return false;
        }
    }
    return true;
}
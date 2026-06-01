#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <string>
#include "Tipos.h"

struct Elemento {
    TipoElemento tipo;
    double tamanio;
    std::string unidad;
    double x;
    double y;
    bool operator==(const Elemento& elemento) const;
    bool operator<(const Elemento& elemento) const;
    std::string info();
};

#endif
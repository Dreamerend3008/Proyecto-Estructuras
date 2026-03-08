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
};

#endif
#ifndef COMANDO_H
#define COMANDO_H

#include <string>
#include "Tipos.h"

struct Comando{
    TipoComando tipoComando;

    // Si es de movimiento
    TipoMovimiento tipoMovimiento;
    double magnitud;
    std::string unidad; 

    // Si es de análisis
    TipoAnalisis tipoAnalisis;
    std::string objeto;
    std::string comentario = "";
};

#endif
#ifndef DATOS_H
#define DATOS_H

#include <queue>
#include <vector>
#include <string>
#include "Comando.h"
#include "Elemento.h"

struct Estado {
    std::queue<Comando>   colaComandos;
    std::vector<Elemento> listaElementos;
};

int cargarComandos(Estado& estado, const std::string& nombreArchivo);
int cargarElementos(Estado& estado, const std::string& nombreArchivo);
int guardar(Estado& estado, const std::string& tipo, const std::string& nombreArchivo);

#endif

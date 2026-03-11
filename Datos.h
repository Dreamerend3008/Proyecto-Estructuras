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

int cmdCargarComandos(Estado& estado, const std::string& nombreArchivo);
int cmdCargarElementos(Estado& estado, const std::string& nombreArchivo);
int cmdGuardar(Estado& estado, const std::string& tipo, const std::string& nombreArchivo);

#endif

#ifndef SIMULACION_H
#define SIMULACION_H

#include <queue>
#include <vector>
#include <string>
#include "Elemento.h"
#include "Comando.h"

bool agregarMovimiento(std::queue<Comando>& comandos,
                     const std::string tipoMovimiento,
                     double magnitud,
                     const std::string& unidad);   

bool agregarAnalisis(std::queue<Comando>& comandos,
                    const std::string& tipoAnalisis,
                    const std::string& objeto,
                    const std::string& comentario);

bool agregarElemento(std::vector<Elemento>& elementos,
                     std::string tipoElem,
                     double tamanio,
                     std::string unidad,
                     double x,
                     double y);

bool simularComandos(std::queue<Comando> comandos,
                     double x, double y,
                     double &nuevo_x, double&nuevo_y);

#endif
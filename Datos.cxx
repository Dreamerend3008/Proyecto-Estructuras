#include "Datos.h"
#include "Utilidades.h"
#include <fstream>

int cargarComandos(Estado& estado, const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) return -1;

    estado.colaComandos = std::queue<Comando>();

    std::string linea;
    int n = 0;

    while (std::getline(archivo, linea)) {
        if (linea.empty()) continue;
        std::vector<std::string> partes = parser(linea);
        if (partes.empty()) continue;

        Comando cmd;

        if (partes[0] == "AVANZAR" || partes[0] == "GIRAR") {
            if (partes.size() < 3) continue;

            cmd.tipoComando = MOVIMIENTO;
            cmd.objeto = "";
            cmd.comentario = "";

            try {
                if (partes[0] == "AVANZAR") {
                    cmd.tipoMovimiento = AVANZAR;
                    double dist = convertirDistancia(std::stod(partes[1]), partes[2]);
                    if (dist < 0) continue; // unidad invalida
                    cmd.magnitud = dist;
                    cmd.unidad = "M";
                } else {
                    cmd.tipoMovimiento = GIRAR;
                    double ang = convertirAngulo(std::stod(partes[1]), partes[2]);
                    if (ang < 0) continue; // unidad invalida
                    cmd.magnitud = ang;
                    cmd.unidad = "GRD";
                }
            } catch (...) {
                continue; // stod fallo
            }

        } else {
            if (partes.size() < 2) continue;

            cmd.tipoComando = ANALISIS;
            cmd.magnitud = 0;
            cmd.unidad = "";
            cmd.objeto = partes[1];
            cmd.comentario = extraerComentario(linea);

            if      (partes[0] == "FOTOGRAFIAR") cmd.tipoAnalisis = FOTOGRAFIAR;
            else if (partes[0] == "COMPOSICION") cmd.tipoAnalisis = COMPOSICION;
            else                                  cmd.tipoAnalisis = PERFORAR;
        }

        estado.colaComandos.push(cmd);
        n++;
    }

    return n; 
}

int cargarElementos(Estado& estado, const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) return -1;

    estado.listaElementos.clear();

    std::string linea;
    int n = 0;

    while (std::getline(archivo, linea)) {
        if (linea.empty()) continue;
        std::vector<std::string> partes = parser(linea);
        if (partes.size() < 5) continue;

        Elemento el;
            try {
            double tam = convertirDistancia(std::stod(partes[1]), partes[2]);
            if (tam < 0) continue; // unidad invalida
            el.tamanio = tam;
            el.unidad = "M";
            el.x = std::stod(partes[3]);
            el.y = std::stod(partes[4]);
        } catch (...) {
            continue; // stod fallo
        }

        if      (partes[0] == "ROCA")      el.tipo = ROCA;
        else if (partes[0] == "CRATER")    el.tipo = CRATER;
        else if (partes[0] == "MONTICULO") el.tipo = MONTICULO;
        else if (partes[0] == "DUNA")      el.tipo = DUNA;
        else continue;

        estado.listaElementos.push_back(el);
        n++;
    }

    return n;
}

int guardar(Estado& estado, const std::string& tipo, const std::string& nombreArchivo) {

    if (tipo == "COMANDOS" && estado.colaComandos.empty()) return 0;
    if (tipo == "ELEMENTOS" && estado.listaElementos.empty()) return 0;

    std::ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) return -1;

    if (tipo == "COMANDOS") {
        std::queue<Comando> copia = estado.colaComandos;
        while (!copia.empty()) {
            Comando cmd = copia.front(); copia.pop();
            if (cmd.tipoComando == MOVIMIENTO) {
                std::string t = (cmd.tipoMovimiento == AVANZAR) ? "AVANZAR" : "GIRAR";
                archivo << t << " " << cmd.magnitud << " " << cmd.unidad << "\n";
            } else {
                std::string t;
                if      (cmd.tipoAnalisis == FOTOGRAFIAR) t = "FOTOGRAFIAR";
                else if (cmd.tipoAnalisis == COMPOSICION) t = "COMPOSICION";
                else                                       t = "PERFORAR";
                archivo << t << " " << cmd.objeto;
                if (!cmd.comentario.empty()) archivo << " '" << cmd.comentario << "'";
                archivo << "\n";
            }
        }
    } else {
        for (Elemento& el : estado.listaElementos) {
            std::string t;
                if      (el.tipo == ROCA)      t = "ROCA";
                else if (el.tipo == CRATER)    t = "CRATER";
                else if (el.tipo == MONTICULO) t = "MONTICULO";
                else                            t = "DUNA";
                archivo << t << " " << el.tamanio << " M "
                    << el.x << " " << el.y << "\n";
        }
    }

    return 1;
}
#include "Simulacion.h"
#include "Utilidades.h"
#include <cmath>
using namespace std;
int agregarMovimiento(std::queue<Comando>& comandos,
                     const std::string tipoMovimiento,
                     double magnitud,
                     const std::string& unidad){
    // 
    Comando c;
    c.tipoComando = MOVIMIENTO;
    c.unidad = unidad;
    c.objeto = "";
    c.comentario = "";
    if(tipoMovimiento == "AVANZAR"){
        double convertido = convertirDistancia(magnitud,unidad);
        if(convertido == -1)return -1;
        c.tipoMovimiento = AVANZAR;
        c.magnitud = convertido;
    }else if(tipoMovimiento == "GIRAR"){
        double convertido = convertirAngulo(magnitud, unidad);
        if(convertido == -1)return -1;
        c.tipoMovimiento = GIRAR;
        c.magnitud = convertido;
    }else{ return -1; }
    comandos.push(c);
    return 1;
} 

int agregarAnalisis(std::queue<Comando>& comandos,
                    const std::string& tipoAnalisis,
                    const std::string& objeto,
                    const std::string& comentario = ""){
    //
    if (objeto.empty()) return -1;

    Comando c;
    c.tipoComando = ANALISIS;
    c.magnitud = 0;
    c.unidad = "";
    c.objeto = objeto;
    c.comentario = comentario;

    if      (tipoAnalisis == "FOTOGRAFIAR") c.tipoAnalisis = FOTOGRAFIAR;
    else if (tipoAnalisis == "COMPOSICION") c.tipoAnalisis = COMPOSICION;
    else if (tipoAnalisis == "PERFORAR")    c.tipoAnalisis = PERFORAR;
    else return -1;

    comandos.push(c);
    return 1;
}

int agregarElemento(std::vector<Elemento>& elementos,
                     std::string tipoElem,
                     double tamanio,
                     std::string unidad,
                     double x,
                     double y) {
    double convertido = convertirDistancia(tamanio, unidad); // el enunciado menciona que las unidades de tamanio son las mismas que avanzar
    if (convertido < 0) return -1;
    Elemento e;
    e.tamanio = convertido;
    e.unidad = unidad;
    e.x = x;
    e.y = y;

    if      (tipoElem == "ROCA")      e.tipo = ROCA;
    else if (tipoElem == "CRATER")    e.tipo = CRATER;
    else if (tipoElem == "MONTICULO") e.tipo = MONTICULO;
    else if (tipoElem == "DUNA")      e.tipo = DUNA;
    else return -1;

    elementos.push_back(e);
    return 1;
}

int simularComandos(std::queue<Comando> comandos,
                     double x, double y,
                     double &nuevo_x, double&nuevo_y){
    double angulo = 0.0;

    while(!comandos.empty()){
        Comando nodo = comandos.front();comandos.pop();
        if(nodo.tipoComando != MOVIMIENTO)continue;

        if(nodo.tipoMovimiento == AVANZAR){
            double anguloRAD = grd_to_rad(angulo);
            x += nodo.magnitud * cos(anguloRAD);
            y += nodo.magnitud * sin(anguloRAD);            
        }else if(nodo.tipoMovimiento == GIRAR){
            angulo += nodo.magnitud;
        }
    }
    nuevo_x = x;
    nuevo_y = y;
    return 1;
}



#include "Elemento.h"
#include <string>
bool Elemento::operator==(const Elemento& elemento) const{
    return(this->tipo == elemento.tipo && this->tamanio == elemento.tamanio && this->unidad == elemento.unidad && this->x == elemento.x && this->y == elemento.y);
}
bool Elemento::operator<(const Elemento& elemento) const{//operador que asegura orden total dentro de los elementos que permite comparar los pares
    if(this->x != elemento.x) return this->x < elemento.x;
    if(this->y != elemento.y) return this->y < elemento.y;
    if(this->tipo != elemento.tipo) return this->tipo < elemento.tipo;
    if(this->tamanio != elemento.tamanio) return this->tamanio < elemento.tamanio;
    return this->unidad < elemento.unidad; 
}
std::string Elemento::info(){
    std::string info =  "(" + std::to_string(this->x) + ',' + std::to_string(this->y)  + ',';
    std::string nombres[] = {"Roca", "Crater", "Monticulo", "Duna"};// necesitamos pasar de numero a la palabra
    return info+ nombres[this->tipo] + ')';
}
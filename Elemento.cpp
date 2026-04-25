#include "Elemento.h"

bool Elemento::operator==(Elemento& elemento){
    return(this->tipo == elemento.tipo && this->tamanio == elemento.tamanio && this->unidad == elemento.unidad && this->x == elemento.x && this->y == elemento.y);
}
#ifndef QUADTREE_H
#define QUADTREE_H
#include "Elemento.h"
#include "Rectangulo.h"
#include <vector>
class QuadTree{
    private:
        Rectangulo* espacio;
    public:
        QuadTree(std::vector<Elemento> elementos,int capacidad);
        QuadTree();
        std::vector<Elemento> en_cuadrante(double x1, double x2, double y1, double y2, Rectangulo* rec);//recursiva
        std::vector<Elemento> en_cuadrante(double x1, double x2, double y1, double y2);
};

#endif

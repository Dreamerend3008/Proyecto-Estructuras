#ifndef GRAFO_H
#define GRAFO_H
#include "Elemento.h"
#include "QuadTree.h"
#include <vector>
#include <map>
class Grafo{
    private:
    std::vector<Elemento> elementos;
    std::map<Elemento,std::vector<std::pair<double, Elemento>>> ady;//"lista " de adyacencia
    void dijkstra(Elemento origen,std::map<Elemento, double>& dist, std::map<Elemento,Elemento>& previo);
    Elemento nodo_mas_lejano(std::map<Elemento,double>& dist);
    std::vector<Elemento> reconstruir_ruta(Elemento origen,Elemento destino,std::map<Elemento,Elemento>& previo);
    public:
    Grafo();
    Grafo(QuadTree arbol, std::vector<Elemento> elementos, int n);
    void ruta_mas_larga();
};
#endif
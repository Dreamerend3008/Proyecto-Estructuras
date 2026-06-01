#include "QuadTree.h"
#include <iostream>
#include <algorithm>
#include <cmath>
QuadTree::QuadTree(std::vector<Elemento> elementos,int capacidad){
    // primero obtenemos el maximo en x y y , el minimo en x y y de los elementos para dar dar el espacio inicial
    double maxX, maxY, minX, minY;
    minX = maxX = minY = maxY = elementos[0].x;
    for(std::vector<Elemento>::iterator it = elementos.begin();it!= elementos.end();it++){
        if (it->x < minX) minX = it->x;
        if (it->x > maxX) maxX = it->x;
        if (it->y < minY) minY = it->y;
        if (it->y > maxY) maxY = it->y;
    }
    this->espacio = new Rectangulo((maxX+minX)/2 ,(maxY+minY)/2,(maxY-minY)/2 + 0.001, (maxX-minX)/2 + 0.001,capacidad); // se le añade a las amplitudes una longitud pequeña por si los datos se distribuyen en una linea
    for(std::vector<Elemento>::iterator it = elementos.begin();it!= elementos.end();it++){
        this->espacio->insertar(*it);
    }

}
QuadTree::QuadTree(){
    this->espacio = NULL;
}

std::vector<Elemento> QuadTree::en_cuadrante(double x1, double x2, double y1, double y2,Rectangulo* rec){
    std::vector<Elemento> resultado;
    if(!rec->intersecta(x1,x2,y1,y2)){// si no intersecta no se tiene en cuenta
        return resultado;
    }
    if(rec->getNW() == NULL){// si es hoja se miran los puntos que tiene
        for(std::vector<Elemento>::iterator it = rec->getelementos().begin();it!=rec->getelementos().end();it++){
            if(it->x >= x1 && it->x <= x2 && it->y >= y1 && it->y <= y2){
                resultado.push_back(*it);
            }
        }
    }
    else{
        //se hace recursion con el resto de hijos
        std::vector<Elemento> resultadonw = en_cuadrante(x1,x2,y1,y2,rec->getNW());
        std::vector<Elemento> resultadone = en_cuadrante(x1,x2,y1,y2,rec->getNE());
        std::vector<Elemento> resultadosw = en_cuadrante(x1,x2,y1,y2,rec->getSW());
        std::vector<Elemento> resultadose = en_cuadrante(x1,x2,y1,y2,rec->getSE());
        resultado.insert(resultado.end(),resultadonw.begin(),resultadonw.end());
        resultado.insert(resultado.end(),resultadone.begin(),resultadone.end());
        resultado.insert(resultado.end(),resultadosw.begin(),resultadosw.end());
        resultado.insert(resultado.end(),resultadose.begin(),resultadose.end());
    }
    return resultado;
}
std::vector<Elemento> QuadTree::en_cuadrante(double x1, double x2, double y1, double y2){
    std::vector<Elemento> resultado;
    if(this->espacio == NULL) return resultado;  // Protección contra NULL pointer
    return this->en_cuadrante(x1,x2,y1,y2,this->espacio);
}

std::vector<Elemento> QuadTree::n_vecinos(Elemento elemento,int n){
    std::vector<Elemento> vecinos;
    int amplitud = 1;
    while(vecinos.size()<=n){
        vecinos = this->en_cuadrante(elemento.x+-amplitud,elemento.x+amplitud,
                                    elemento.y-amplitud,elemento.y+amplitud);
        amplitud *= 2;
    }// se obtienen un numero k> n de elementos cercanos al elemento central
    std::sort(vecinos.begin(), vecinos.end(),//se le da una operacion personalizada al sort 
        [&elemento](const Elemento& a, const Elemento& b) {

            double da = std::sqrt(
                (a.x - elemento.x) * (a.x - elemento.x) +
                (a.y - elemento.y) * (a.y - elemento.y));

            double db = std::sqrt(
                (b.x - elemento.x) * (b.x - elemento.x) +
                (b.y - elemento.y) * (b.y - elemento.y));

            return da < db;
        });
    vecinos.erase(vecinos.begin());//eliminar el elemento en si que tiene distancia 0 
    vecinos.resize(n);//quedarnos con los n elementos
    return vecinos;
}

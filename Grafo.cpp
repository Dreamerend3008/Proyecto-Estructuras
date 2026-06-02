#include "Grafo.h"
#include <queue>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
Grafo::Grafo(QuadTree arbol, std::vector<Elemento> elementos, int n){
    // Guardar copia de la lista de elementos en el grafo
    this->elementos = elementos;
    std::map<Elemento,bool> visitado;
    for(const auto& e : elementos) {
        std::vector<Elemento> vecinos = arbol.n_vecinos(e,n);
        for(const auto& v : vecinos) {
            double dx = e.x - v.x; //distancias en x & y
            double dy = e.y - v.y;
            double dist = sqrt(dx*dx + dy*dy);// se usa distancia euclidiana
            if(visitado[v]) continue; //si el vecino ya fue visitado, no se agrega la arista
            ady[e].push_back({dist,v});
            visitado[e] = true; //marcar el elemento actual como visitado para evitar agregar aristas duplicadas
        }
    }
    // Asegurar que todos los nodos sin vecinos también existen en la lista de adyacencia
    for(const auto& e : this->elementos) {
        if(ady.find(e) == ady.end()) ady[e] = {};
    }
}
void Grafo::dijkstra(Elemento origen, std::map<Elemento, double>& dist, std::map<Elemento,Elemento>& previo){
    for(const auto& e : elementos){
        dist[e] = -std::numeric_limits<double>::infinity();//poner las distancias iniciales en infinito
    }
    dist[origen] = 0;
    std::priority_queue<std::pair<double,Elemento>,std::vector<std::pair<double,Elemento>>> pq;
    pq.push({0,origen});
    while(!pq.empty()){
        Elemento actual = pq.top().second;
        double distancia_actual = pq.top().first;
        pq.pop();
        if(distancia_actual < dist[actual]) continue;
        for(const auto& vecino : ady[actual]){
            double peso = vecino.first;
            Elemento siguiente = vecino.second;
            double nueva = distancia_actual + peso;
            if(nueva > dist[siguiente]){
                dist[siguiente] = nueva; 
                previo[siguiente] = actual; //se guardan los siguientes en el mapa de previo para reconstruir la ruta despues
                pq.push({nueva,siguiente});
            }
        }
    }
}
Elemento Grafo::nodo_mas_lejano(std::map<Elemento,double>& dist){
    double mayor = -std::numeric_limits<double>::infinity();
    Elemento resultado;
    for(const auto& par : dist){
        if(par.second != -std::numeric_limits<double>::infinity() && par.second > mayor){//se busca la distancia finita mas larga
            mayor = par.second;
            resultado = par.first;
        }
    }
    return resultado;
}
std::vector<Elemento> Grafo::reconstruir_ruta(Elemento origen,Elemento destino,std::map<Elemento,Elemento>& previo){
    std::vector<Elemento> ruta;
    Elemento actual = destino;
    while(!(actual == origen)){
        ruta.push_back(actual);
        actual = previo[actual];
    }
    ruta.push_back(origen);
    std::reverse(
        ruta.begin(),
        ruta.end()
    );
    return ruta;
}

void Grafo::ruta_mas_larga(){
    if(this->ady.empty()){
        std::cout<< "(No hay información) "<< "El mapa no ha sido generado todavía\n";
        return;
    }
    double mayor = -std::numeric_limits<double>::infinity();
    Elemento inicio_final;
    Elemento destino_final;
    std::vector<Elemento> mejor_ruta;
    for(Elemento origen : this->elementos){
        std::map<Elemento,double> dist;
        std::map<Elemento,Elemento> previo;
        this->dijkstra(origen,dist,previo);
        Elemento destino =this->nodo_mas_lejano(dist);
        double distancia =dist[destino];
        if(distancia > mayor){
            mayor = distancia;
            inicio_final = origen;
            destino_final = destino;
            mejor_ruta =this->reconstruir_ruta(origen,destino,previo);
        }
    }
    std::cout<< "Los puntos de interes mas alejados entre si son "<< inicio_final.info()<< " y "<< destino_final.info()<< std::endl;
    std::cout<< "La ruta que los conecta tiene una longitud total de "<<mayor<< std::endl;
    std::cout<< "Ruta:"<<std::endl;
    for(Elemento elemento : mejor_ruta)
      std::cout<< "-"<< elemento.info() << std::endl;
}

Grafo::Grafo(){}
#include "Rectangulo.h"
#include <iostream>
#include <cmath>

//constructor
Rectangulo::Rectangulo(double centerx,double centery, double height, double width, int capacidad){
    this->centerx = centerx;
    this->centery = centery;
    this->height = height;
    this->width = width;
    this->elementos.clear();
    this->capacidad = capacidad;
    this->ne = NULL;
    this->nw = NULL;
    this->se = NULL;
    this->sw = NULL;
}
//get and set
double Rectangulo::getcenterx(){
     return this->centerx;
}
void Rectangulo::setcenterx(double centerx){
    this->centerx = centerx;
}
double Rectangulo::getcentery(){
    return this->centery;
}
void Rectangulo::setcentery(double centery){
    this->centery = centery;
}
double Rectangulo::getheight(){
    return this->height;
}
void Rectangulo::setheight(double height){
    this->height = height;
}
double Rectangulo::getwidth(){
    return this->width;
}
void Rectangulo::setwidth(double width){
        this->width = width;
}
std::vector<Elemento>& Rectangulo::getelementos(){
    return this->elementos;
}
void Rectangulo::setelementos(std::vector<Elemento> elementos){
    this->elementos = elementos;
}
Rectangulo* Rectangulo::getNW() {
    return nw;
}
Rectangulo* Rectangulo::getNE() {
    return ne;
}
Rectangulo* Rectangulo::getSW() {
    return sw;
}
Rectangulo* Rectangulo::getSE() {
    return se;
}
void Rectangulo::setNW(Rectangulo* nw) {
    this->nw = nw;
}
void Rectangulo::setNE(Rectangulo* ne) {
    this->ne = ne;
}
void Rectangulo::setSW(Rectangulo* sw) {
    this->sw = sw;
}
void Rectangulo::setSE(Rectangulo* se) {
    this->se = se;
}
void Rectangulo::setcapacidad(int capacidad){
    this->capacidad = capacidad;
}
int Rectangulo::getcapacidad(){
    return this->capacidad;
}
//funciones utiles


bool Rectangulo::buscarelemento(Elemento elemento){
    for(std::vector<Elemento>::iterator it = this->elementos.begin();it!= this->elementos.end();it++){
        if(*it == elemento) return true;
    }
    return false;
}

bool Rectangulo::comprende(double x, double y){
    return (x >= this->centerx - this->width && x <= this->centerx + this->width && 
            y >= this->centery - this->height && y <= this->centery + this->height);
}

void Rectangulo::subdividir(){
    this->nw = new Rectangulo(this->centerx-this->width/2,this->centery+this->height/2,this->height/2,this->width/2,this->capacidad);
    this->ne = new Rectangulo(this->centerx+this->width/2,this->centery+this->height/2,this->height/2,this->width/2,this->capacidad);
    this->sw = new Rectangulo(this->centerx-this->width/2,this->centery-this->height/2,this->height/2,this->width/2,this->capacidad);
    this->se = new Rectangulo(this->centerx+this->width/2,this->centery-this->height/2,this->height/2,this->width/2,this->capacidad);        
}

void Rectangulo::insertarenhijo(Elemento e){
    if (nw->comprende(e.x, e.y)){
     nw->insertar(e);
    }
    else if (ne->comprende(e.x, e.y)){
         ne->insertar(e);
    }
    else if (sw->comprende(e.x, e.y)) sw->insertar(e);
    else if (se->comprende(e.x, e.y)) se->insertar(e);
}
void Rectangulo::insertar(Elemento e){
   if(!this->comprende(e.x,e.y) || this->buscarelemento(e)) return;//si no lo comprende o ya lo tiene en su lista no se hace nada

   if(this->elementos.size()<this->capacidad && this->nw == NULL){//si lo comprende y tiene capacidad lo incluye
    this->elementos.push_back(e);
    return;
   }
   if(this->nw == NULL){// si no tiene capacidad y es hoja subdividimos el espacio y heredamos los elementos
    this->subdividir();
    for(std::vector<Elemento>::iterator it = this->elementos.begin();it!= this->elementos.end();it++){
        this->insertarenhijo(*it);
    }
    this->elementos.clear();//limpiar el vector
   }

   this->insertarenhijo(e); //dado que no tuvo capacidad y ya se crearon los hijos entonces se inserta el elemento en los hijos


}

//funcion de interseccion entre un rectangulo y un rango

bool Rectangulo::intersecta(double x1, double x2, double y1, double y2) {
    return !(
        (this->centerx + this->width  < x1) ||
        (this->centerx - this->width  > x2) ||
        (this->centery + this->height < y1) ||
        (this->centery - this->height > y2)
    );
}


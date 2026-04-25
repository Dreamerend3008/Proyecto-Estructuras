#ifndef RECTANGULO_H
#define RECTANGULO_H
#include<vector>
#include "Elemento.h"
class Rectangulo{
    protected:
        double centerx; // centro del rectangulo en x
        double centery; // centro del rectangulo en y
        double height; // distancia del cetro al borde en y 
        double width; // distancia del centro al borde en x
        std::vector<Elemento> elementos; // arreglo con los elementos que pertenecen al rectangulo
        int capacidad = 3;//cantidad de elementos que se aceptan antes de subdividir un rectangulo
        //hijos del rectangulo(si es que se necesitan)
        Rectangulo* nw = NULL;
        Rectangulo* ne = NULL;
        Rectangulo* sw = NULL;
        Rectangulo* se = NULL;
    public:
        // constructor
        Rectangulo(double centerx,double centery, double height, double width,int capacidad);


        // get and set
        double getcenterx();
        void setcenterx(double centerx);
        double getcentery();
        void setcentery(double centery);
        double getheight();
        void setheight(double height);
        double getwidth();
        void setwidth(double width);
        void setelementos(std::vector<Elemento> elementos);
        std::vector<Elemento>& getelementos();
        Rectangulo* getNW();
        Rectangulo* getNE();
        Rectangulo* getSW();
        Rectangulo* getSE();
        void setNW(Rectangulo* nw);
        void setNE(Rectangulo* ne);
        void setSW(Rectangulo* sw);
        void setSE(Rectangulo* se);
        void setcapacidad(int capacidad);
        int getcapacidad();

        //funciones utiles
        bool comprende(double x, double y);
        void subdividir();
        void insertarenhijo(Elemento elemento);

        //insertar elemento

        void insertar(Elemento elemento);

        bool buscarelemento(Elemento elemento);
        //operador de interseccion entre rectangulos
        bool intersecta(double x1,double x2,double y1,double y2);
        
};

#endif
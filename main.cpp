#include<iostream>
#include "ProcesadorComandos.h"
using namespace std;

int main() {
    string linea;
    bool running = true;
    while(running){
        cout<<"$ ";
        getline(cin, linea);
        
        if(linea.empty())continue;

        procesarComando(linea);
    } 
    return 0;
}
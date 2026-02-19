#include <iostream>
#include <string>

#include "ProcesadorComandos.h"
#include "Utilidades.h"

using namespace std;

void salir();
void cargarComandos(vector<string> comandos);
void cargarElementos(vector<string> comandos);
void guardar(vector<string> comandos);
void ayuda();


void procesarComando(const string& input) {
    vector<string> comandos = parser(input);    

    if (comandos.empty()) return;

    if (comandos[0] == "salir") {
        salir();
    }else if(comandos[0] == "cargar_comandos") {
        cargarComandos(comandos);
    }else if(comandos[0] == "cargar_elementos") {
        cargarElementos(comandos);
    }else if(comandos[0] == "guardar") {
        guardar(comandos);
    }else if(comandos[0] == "ayuda") {
        ayuda();
    }else {
        cout << "Comando no reconocido: " << comandos[0] <<" use 'ayuda' para ver los comandos disponibles."<< endl;
    }
}
void cargarComandos(vector<string> comandos) {
    // uso cargar_comandos <nombre_archivo>
    if(comandos.size() != 2 || comandos[1].empty()) {
        // unico tamano permitido es 2, el comando y el nombre del archivo
        cout << "Uso: cargar_comandos <nombre_archivo>" << endl;
        return;
    }
    cout << "Cargando comandos desde el archivo: " << comandos[1] << endl;
}
void cargarElementos(vector<string> comandos) {
    // uso cargar_elementos <nombre_archivo>
    if(comandos.size() != 2 || comandos[1].empty()) {
        // unico tamano permitido es 2, el comando y el nombre del archivo
        cout << "Uso: cargar_elementos <nombre_archivo>" << endl;
        return;
    }
    cout << "Cargando elementos desde el archivo: " << comandos[1] << endl;
}
void guardar(vector<string> comandos) {
    // uso guardar <comandos|elementos> <nombre_archivo>
    if(comandos.size() != 3 || comandos[1].empty() || comandos[2].empty() || (comandos[1] != "comandos" && comandos[1] != "elementos")) {
        // unico tamano permitido es 3, el comando, el tipo de dato y el nombre del archivo
        cout << "Uso: guardar <comandos|elementos> <nombre_archivo>" << endl;
        return;
    }
    cout << "Guardando " << comandos[1] << " en el archivo: " << comandos[2] << endl;
}

void ayuda() {
    cout << "Comandos disponibles:" << endl;
    cout << "  salir - Termina el programa." << endl;
    cout << "  cargar_comandos - Carga comandos desde un archivo." << endl;
    cout << "  cargar_elementos - Carga elementos desde un archivo." << endl;
    cout << "  guardar - Guarda el estado actual en un archivo." << endl;
    cout << "  ayuda - Muestra esta ventana de ayuda." << endl;
}

void salir() {
    cout << "Saliendo..." << endl;
    exit(0);
}
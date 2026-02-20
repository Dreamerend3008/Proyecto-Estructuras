#include <iostream>
#include <string>

#include "ProcesadorComandos.h"
#include "Utilidades.h"

using namespace std;

void salir();
void cargarComandos(vector<string> comandos);
void cargarElementos(vector<string> comandos);
void guardar(vector<string> comandos);
void agregarMovimiento(vector<string> comandos);
void agregarAnalisis(vector<string> comandos);
void agregarElemento(vector<string> comandos);
void simularComandos(vector<string> comandos);
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
        ayuda(comandos);
    }else if(comandos[0] == "agregar_movimiento") {
        agregarMovimiento(comandos);
    }else if(comandos[0] == "agregar_analisis") {
        agregarAnalisis(comandos);
    }else if(comandos[0] == "agregar_elemento") {
        agregarElemento(comandos);
    }else if(comandos[0] == "simular_comandos") {
        simularComandos(comandos);
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

void ayuda(vector<string> comandos) {
    if(comandos.size() == 1){
        cout << "Comandos disponibles:" << endl;
        cout << "  salir - Termina el programa." << endl;
        cout << "  cargar_comandos - Carga comandos desde un archivo." << endl;
        cout << "  cargar_elementos - Carga elementos desde un archivo." << endl;
        cout << "  guardar - Guarda el estado actual en un archivo." << endl;
        cout<<"  agregar_movimiento - El comando de movimiento ha sido agregado exitosamente."<<endl;
        cout<<"  agregar_analisis - El comando de analisis ha sido agregado exitosamente."<<endl;
        cout<<"  agregar_elemento - El elemento ha sido agregado exitosamente."<<endl;
        cout<<"  simular_comandos - La simulacion de los comandos deja al robot en la nueva posicion."<<endl;
        cout << "  ayuda - Muestra esta ventana de ayuda." << endl;
    }else{
        if(comandos[1] == "salir") {
            cout << "salir: Termina el programa." << endl;
        }else if(comandos[1] == "cargar_comandos") {
            cout << "cargar_comandos <nombre_archivo>: Carga comandos desde un archivo." << endl;
        }else if(comandos[1] == "cargar_elementos") {
            cout << "cargar_elementos <nombre_archivo>: Carga elementos desde un archivo." << endl;
        }else if(comandos[1] == "guardar") {
            cout << "guardar <comandos|elementos> <nombre_archivo>: Guarda el estado actual en un archivo." << endl;
        }else if(comandos[1] == "agregar_movimiento") {
            cout<<"agregar_movimiento <tipo> <magnitud> <unidad>: El comando de movimiento ha sido agregado exitosamente."<<endl;
        }else if(comandos[1] == "agregar_analisis") {
            cout<<"agregar_analisis <tipo> <objeto> <comentario>: El comando de analisis ha sido agregado exitosamente."<<endl;
        }else if(comandos[1] == "agregar_elemento") {
            cout<<"agregar_elemento <tipo> <tamano> <unidad> <x> <y>: El elemento ha sido agregado exitosamente."<<endl;
        }else if(comandos[1] == "simular_comandos") {
            cout<<"simular_comandos <coordX> <coordY>: La simulacion de los comandos, a partir de la posicion (coordX, coordY), deja al robot en la nueva posicion (nuevoX,nuevoY)."<<endl;
        }else {
            cout << "Comando no reconocido para ayuda: " << comandos[1] << endl;
        }
    }
}

void salir() {
    cout << "Saliendo..." << endl;
    exit(0);
}

void agregarMovimiento(vector<string> comandos) {

    if (comandos.size()!=4) {
        cout<<"La informacion del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)."<<endl;
        return;
    }

    if (comandos[1]!="avanzar" && comandos[1]!="girar") {
        cout<<"La informacion del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)."<<endl;
        return;
    }

    if (!stringDouble(comandos[2])) {
        cout<<"La informacion del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)."<<endl;
        return;
    }

    if (comandos[1] == "avanzar") {
        if (comandos[3]!="cm" && comandos[3]!="dm" && comandos[3]!="m") {
            cout<<"La informacion del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)."<<endl;
            return;
        }
    }

    if (comandos[1] == "girar") {
        if (comandos[3]!="grd" && comandos[3]!="rad") {
            cout<<"La informacion del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)."<<endl;
            return;
        }
    }

    cout << "El comando de movimiento ha sido agregado exitosamente." << endl;
}
void agregarAnalisis(vector<string> comandos) {

    if (comandos.size()<3 || comandos.size()>4) {
        cout<<"La informacion del analisis no corresponde a los datos esperados (tipo, objeto, comentario)."<<endl;
        return;
    }

    if (comandos[1]!="fotografiar" && comandos[1] !="composicion" && comandos[1]!="perforacion") {
        cout<<"La informacion del analisis no corresponde a los datos esperados (tipo, objeto, comentario)."<<endl;
        return;
    }

    if (comandos[2]!="roca" && comandos[2]!="crater" && comandos[2]!= "monticulo" && comandos[2]!= "duna") {
        cout<<"La informacion del analisis no corresponde a los datos esperados (tipo, objeto, comentario)."<<endl;
        return;
    }

    cout << "El comando de analisis ha sido agregado exitosamente." << endl;
}
void agregarElemento(vector<string> comandos) {

    if (comandos.size()!=6) {
        cout<<"La informacion del elemento no corresponde a los datos esperados (tipo, tamano, unidad, x, y)."<<endl;
        return;
    }

    if (comandos[1]!="roca" && comandos[1]!="crater" && comandos[1]!="monticulo" && comandos[1]!="duna") {
        cout<<"La informacion del elemento no corresponde a los datos esperados (tipo, tamano, unidad, x, y)."<<endl;
        return;
    }

    if (!stringDouble(comandos[2]) || stod(comandos[2])<=0) {
        cout<<"La informacion del elemento no corresponde a los datos esperados (tipo, tamano, unidad, x, y)."<<endl;
        return;
    }

    if (comandos[3]!="cm" && comandos[3]!="dm" && comandos[3]!="m") {
        cout<<"La informacion del elemento no corresponde a los datos esperados (tipo, tamano, unidad, x, y)."<<endl;
        return;
    }

    if (!stringDouble(comandos[4]) || !stringDouble(comandos[5])) {
        cout<<"La informacion del elemento no corresponde a los datos esperados (tipo, tamano, unidad, x, y)."<<endl;
        return;
    }
    cout<<"El elemento ha sido agregado exitosamente."<<endl;
}
void simularComandos(vector<string> comandos) {

    if (comandos.size()!=3) {
        cout<<"La informacion de la simulacion no corresponde a los datos esperados (coordX, coordY)."<<endl;
        return;
    }

    if (!stringDouble(comandos[1]) || !stringDouble(comandos[2])) {
        cout<<"La informacion de la simulacion no corresponde a los datos esperados (coordX, coordY)."<<endl;
        return;
    }
     cout<<"La simulacion de los comandos, a partir de la posicion ("<<comandos[1]<<","<<comandos[2]<<"), deja al robot en la nueva posicion (nuevoX,nuevoY)."<<endl;
}

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
void agregarAnalisis(vector<string> comandos, const string& lineaOriginal);
void agregarElemento(vector<string> comandos);
void simularComandos(vector<string> comandos);
void ayuda(vector<string> comandos);
void ubicarElementos(vector<string> comandos);
void enCuadrante(vector<string> comandos);
void crearMapa(vector<string> comandos);
void rutaMasLarga(vector<string> comandos);

// se uso inteligencia artificial para la estandarizacion de los mensajes del sistema
// su objetivo fue garantizar consistencia en los mensajes que recibe el usuario

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
    }else if(comandos[0] == "agregar_movimiento") {
        agregarMovimiento(comandos);
    }else if(comandos[0] == "agregar_analisis") {
        agregarAnalisis(comandos, input);
    }else if(comandos[0] == "agregar_elemento") {
        agregarElemento(comandos);
    }else if(comandos[0] == "simular_comandos") {
        simularComandos(comandos);
    }else if(comandos[0] == "ubicar_elementos") {
        ubicarElementos(comandos);
    }else if(comandos[0] == "en_cuadrante") {
        enCuadrante(comandos);
    }else if(comandos[0] == "crear_mapa") {
        crearMapa(comandos);
    }else if(comandos[0] == "ruta_mas_larga") {
        rutaMasLarga(comandos);
    }else if(comandos[0] == "ayuda") {
        ayuda(comandos);
    }
    else {
        cout << "(Error) Comando no reconocido: " << comandos[0] << ". Use 'ayuda' para ver los comandos disponibles." << endl;
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
        cout << "  agregar_movimiento - Agrega un comando de movimiento." << endl;
        cout << "  agregar_analisis - Agrega un comando de análisis." << endl;
        cout << "  agregar_elemento - Agrega un elemento al mapa." << endl;
        cout << "  simular_comandos - Simula la ejecución de comandos desde una posición." << endl;
        cout << "  ubicar_elementos - Ubica los elementos en estructura jerárquica." << endl;
        cout << "  en_cuadrante - Retorna elementos dentro del cuadrante dado." << endl;
        cout << "  crear_mapa - Crea un mapa de elementos con coeficiente de conectividad." << endl;
        cout << "  ruta_mas_larga - Encuentra la ruta más larga en el mapa." << endl;
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
            cout << "agregar_movimiento <tipo> <magnitud> <unidad>: Agrega un comando de movimiento (avanzar o girar)." << endl;
        }else if(comandos[1] == "agregar_analisis") {
            cout << "agregar_analisis <tipo> <objeto> <comentario>: Agrega un comando de análisis (fotografiar, composicion o perforar)." << endl;
        }else if(comandos[1] == "agregar_elemento") {
            cout << "agregar_elemento <tipo> <tamano> <unidad> <x> <y>: Agrega un elemento al mapa (roca, crater, monticulo o duna)." << endl;
        }else if(comandos[1] == "simular_comandos") {
            cout << "simular_comandos <coordX> <coordY>: Simula la ejecución de comandos desde la posición inicial (coordX, coordY)." << endl;
        }else if(comandos[1] == "ubicar_elementos") {
            cout << "ubicar_elementos: Ubica los elementos en memoria. No recibe parámetros." << endl;
        } else if(comandos[1] == "en_cuadrante") {
            cout << "en_cuadrante <x1> <x2> <y1> <y2>: Retorna los elementos dentro del cuadrante especificado." << endl;
        } else if(comandos[1] == "crear_mapa") {
            cout << "crear_mapa <coeficiente>: Crea un mapa de elementos con el coeficiente de conectividad (entre 0 y 1)." << endl;
        } else if(comandos[1] == "ruta_mas_larga") {
            cout << "ruta_mas_larga: Encuentra la ruta más larga en el mapa. No recibe parámetros." << endl;
        }else {
            cout << "(Error) Comando no reconocido: " << comandos[1] << endl;
        }
    }
}

void salir() {
    cout << "Saliendo..." << endl;
    exit(0);
}

void agregarMovimiento(vector<string> comandos) {

    if (comandos.size()!=4) {
        cout << "Uso: agregar_movimiento <tipo> <magnitud> <unidad>" << endl;
        return;
    }

    if (comandos[1]!="avanzar" && comandos[1]!="girar") {
        cout << "(Formato erroneo) El tipo debe ser 'avanzar' o 'girar'." << endl;
        return;
    }

    if (!stringDouble(comandos[2])) {
        cout << "(Formato erroneo) La magnitud debe ser un numero real." << endl;
        return;
    }

    if (comandos[1] == "avanzar") {
        if (comandos[3]!="cm" && comandos[3]!="dm" && comandos[3]!="m" && comandos[3]!="km") {
            cout << "(Formato erroneo) La unidad de distancia debe ser: cm, dm, m o km." << endl;
            return;
        }
    }

    if (comandos[1] == "girar") {
        if (comandos[3]!="grd" && comandos[3]!="rad") {
            cout << "(Formato erroneo) La unidad de angulo debe ser: grd o rad." << endl;
            return;
        }
    }

    cout << "(Resultado exitoso) El comando de movimiento ha sido agregado exitosamente." << endl;
}
void agregarAnalisis(vector<string> comandos, const string& lineaOriginal) {

    if (comandos.size() < 3) {
        cout << "Uso: agregar_analisis <tipo> <objeto> <comentario>" << endl;
        return;
    }

    if (comandos[1] != "fotografiar" && comandos[1] != "composicion" && comandos[1] != "perforar") {
        cout << "(Formato erroneo) El tipo debe ser 'fotografiar', 'composicion' o 'perforar'." << endl;
        return;
    }

    // verificar comentario si hay comillas
    if (lineaOriginal.find('\'')) {
        string comentario = extraerComentario(lineaOriginal);
        if (comentario.empty()) {
            cout << "(Formato erroneo) El comentario debe estar entre comillas simples." << endl;
            return;
        }
    }

    cout << "(Resultado exitoso) El comando de analisis ha sido agregado exitosamente." << endl;
}
void agregarElemento(vector<string> comandos) {

    if (comandos.size()!=6) {
        cout << "Uso: agregar_elemento <tipo> <tamano> <unidad> <x> <y>" << endl;
        return;
    }

    if (comandos[1]!="roca" && comandos[1]!="crater" && comandos[1]!="monticulo" && comandos[1]!="duna") {
        cout << "(Formato erroneo) El tipo debe ser 'roca', 'crater', 'monticulo' o 'duna'." << endl;
        return;
    }

    if (!stringDouble(comandos[2]) || stod(comandos[2])<=0) {
        cout << "(Formato erroneo) El tamano debe ser un numero real positivo." << endl;
        return;
    }

    if (comandos[3]!="cm" && comandos[3]!="dm" && comandos[3]!="m" && comandos[3]!="km") {
        cout << "(Formato erroneo) La unidad debe ser: cm, dm, m o km." << endl;
        return;
    }

    if (!stringDouble(comandos[4]) || !stringDouble(comandos[5])) {
        cout << "(Formato erroneo) Las coordenadas x e y deben ser numeros reales." << endl;
        return;
    }
    cout << "(Resultado exitoso) El elemento ha sido agregado exitosamente." << endl;
}
void simularComandos(vector<string> comandos) {

    if (comandos.size()!=3) {
        cout << "Uso: simular_comandos <coordX> <coordY>" << endl;
        return;
    }

    if (!stringDouble(comandos[1]) || !stringDouble(comandos[2])) {
        cout << "(Formato erroneo) Las coordenadas coordX y coordY deben ser numeros reales." << endl;
        return;
    }
    cout << "(Resultado exitoso) La simulacion de los comandos, a partir de la posicion (" << comandos[1] << "," << comandos[2] << "), deja al robot en la nueva posicion (nuevoX,nuevoY)." << endl;
}
void ubicarElementos(vector<string> comandos) {
    if (comandos.size() != 1) {
        cout << "Uso: ubicar_elementos" << endl;
        return;
     }
    cout << "(Resultado exitoso) Ubicando elementos en memoria... (Pendiente entrega 1)" << endl;
}
void enCuadrante(vector<string> comandos) {
    if (comandos.size() != 5) {
        cout << "Uso: en_cuadrante <x1> <x2> <y1> <y2>" << endl;
        return;
    }
    if (!stringDouble(comandos[1]) || !stringDouble(comandos[2]) || 
    !stringDouble(comandos[3]) || !stringDouble(comandos[4])) {
        cout << "(Formato erroneo) Los parametros x1, x2, y1, y2 deben ser numeros reales." << endl;
        return;
    }
    if(stod(comandos[1]) >= stod(comandos[2])){
        cout << "(Formato erroneo) Las coordenadas deben cumplir: x1 < x2." << endl;
        return;
    }
    if(stod(comandos[3]) >= stod(comandos[4])){
        cout << "(Formato erroneo) Las coordenadas deben cumplir: y1 < y2." << endl;
        return;
    }
    cout << "(Resultado exitoso) Elementos en cuadrante (Pendiente entrega 1)." << endl;
}
void crearMapa(vector<string> comandos) {
    if (comandos.size() != 2) {
        cout << "Uso: crear_mapa <coeficiente>" << endl;
        return;
    }
    if (!stringDouble(comandos[1])) {
        cout << "(Formato erroneo) El coeficiente debe ser un numero real." << endl;
        return;
    }
    double coef = stod(comandos[1]);
    if (coef < 0 || coef > 1) {
        cout << "(Formato erroneo) El coeficiente debe estar entre 0 y 1." << endl;
        return;
    }
    cout << "(Resultado exitoso) Mapa creado (Pendiente entrega 2)." << endl;
}
void rutaMasLarga(vector<string> comandos) {
    if (comandos.size() != 1) {
        cout << "Uso: ruta_mas_larga" << endl;
        return;
    }
    cout << "(Resultado exitoso) Ruta mas larga encontrada (Pendiente entrega 2)." << endl;
}

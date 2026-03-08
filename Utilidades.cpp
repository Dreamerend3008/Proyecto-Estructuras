#include "Utilidades.h"
#include <sstream>

const double PI = 3.14159265358979323846;

vector<string> parser(const string& linea) {
    vector<string> tokens;
    stringstream ss(linea);
    string token;
    while (ss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}
bool stringDouble(string input) {
    try {
        stod(input);
        return true;
    }
    catch (std::exception e) {
        return false;
    }
}

double convertirDistancia(double magnitud, std::string unidad){
    if(unidad == "cm") return magnitud * 0.01;
    if(unidad == "dm") return magnitud * 0.1;
    if(unidad == "m") return magnitud;
    if(unidad == "km") return magnitud * 1000.0;
    return -1.0;
}

double convertirAngulo(double magnitud, std::string unidad){
    if(unidad == "grd") return magnitud;
    if(unidad == "rad") return magnitud * (180.0/PI);
    return -1.0;
}

double grd_to_rad(double angulo){
    return angulo * (PI/180.0);
}
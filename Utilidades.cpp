#include "Utilidades.h"
#include <sstream>

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
string extraerComentario(const string& linea) {
    // busca el primer ' y el último '
    int inicio = linea.find('\'');
    int fin = linea.rfind('\'');
    if(inicio == string::npos || fin == string::npos || inicio == fin) {
        return "";
    }
    return linea.substr(inicio + 1, fin - inicio - 1);
}

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
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
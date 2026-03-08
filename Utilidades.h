#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <string>
#include <vector>
using namespace std;

vector<string> parser(const string& linea);
bool stringDouble(string input);
double convertirDistancia(double magnitud, std::string unidad);
double convertirAngulo(double magnitud, std::string unidad);
double grd_to_rad(double angulo);
#endif
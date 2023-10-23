#ifndef PREREGLAS_M1
#define PREREGLAS_M1

#include <iostream>
#include <fstream>
#include <exception>
using namespace std;

bool* pre_reglas(const char* file_name, unsigned long long& tam);   //llamar esta funcion para pre_reglas

char* leer_archivo(const char* file_name, unsigned long long& tamal);
bool* archivo_a_binario(const char* text, const unsigned long long& tam);

#endif //PREREGLAS_M1

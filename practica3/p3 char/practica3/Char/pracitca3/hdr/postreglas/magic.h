#ifndef POST_REGLAS_H
#define POST_REGLAS_H

#include <iostream>
#include <fstream>
#include <exception>
using namespace std;

void post_reglas(const char* file_name, const bool* bits, unsigned long long& tam);

char* binario_a_texto(const bool* bits, const unsigned long long& tam);
char byte2char(const bool* byte, unsigned long long actual_pos);
void guardar_archivo(const char* file_name, const char* text, const unsigned long long& tam);

#endif // !POST_REGLAS_H

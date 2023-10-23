#ifndef MAGIC_H
#define MAGIC_H


#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

char* unir_char(const char* text1, const char* text2);
unsigned long long count_letters(const char* text);
void post_reglas(const char* file_name, const bool* bits, unsigned long long& tam);
void guardar_archivo(const char* file_name, const char* text, const unsigned long long& tam);
char* binario_a_texto(const bool* bits, const unsigned long long& tam);
char byte2char(const bool* byte, unsigned long long actual_pos);
bool* pre_reglas(const char* file_name, unsigned long long& tam);
char* leer_archivo(const char* file_name, unsigned long long& tamal);
bool* archivo_a_binario(const char* text, const unsigned long long& tam);
void codificacion_metodo_1(bool* bits, const unsigned long long tam, const unsigned short n_raiz);
void comprobar_cero_uno_Cod(const bool* og, bool* cod, unsigned long long& index, const int raiz_n, const int cero, const int uno);
void decodificacion_metodo_1(bool* bits, const unsigned long long tam, const unsigned short n_raiz);
void comprobar_cero_uno_Deco(const bool* og, bool* deco, unsigned long long& index, const int raiz_n, const int cero, const int uno);
void contar_bits(const bool* bits, int& ceros, int& unos, const int n_raiz, const int index);
void codificacion_metodo_2(bool* bits, const unsigned long long tam, const unsigned short n_raiz);
void decodificacion_metodo_2(bool* bits, const unsigned long long tam, const unsigned short n_raiz);
void procesarInformacion(const char* id, const int n_raiz, const bool COD, const bool M1_2);









#endif // MAGIC_H

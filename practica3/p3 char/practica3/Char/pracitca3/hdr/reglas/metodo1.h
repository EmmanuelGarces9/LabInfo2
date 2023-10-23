#ifndef METODO1_H
#define METODO1_H

void codificacion_metodo_1(bool* bits, const unsigned long long tam, const unsigned short n_raiz);
void decodificacion_metodo_1(bool* bits, const unsigned long long tam, const unsigned short n_raiz);

void comprobar_cero_uno_Cod(const bool* og, bool* cod, unsigned long long& index, const int raiz_n, const int cero, const int uno);
void comprobar_cero_uno_Deco(const bool* og, bool* deco, unsigned long long& index, const int raiz_n, const int cero, const int uno);
void contar_bits(const bool* bits, int& ceros, int& unos, const int n_raiz, const int index);

#endif //METODO1_H

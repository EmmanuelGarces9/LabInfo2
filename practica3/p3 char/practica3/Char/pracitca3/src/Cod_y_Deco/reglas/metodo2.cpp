#include "../../../hdr/reglas/metodo2.h"

void codificacion_metodo_2(bool* bits, const unsigned long long tam, const unsigned short n_raiz) {
    unsigned short resto = tam % n_raiz;
    unsigned long long procesos = tam - resto;
    unsigned long long i;
    for(i = 1; i <= procesos; ++i) {
        unsigned long long seccion_bits = i * n_raiz;
        bool temp = bits[seccion_bits - 1];
        for(short j = 0; j < n_raiz; j++) {
            bits[seccion_bits - j - 1] = bits[seccion_bits - j - 2];
        }
    }
    if(resto > 0) {
        bool temp = bits[tam - 1];
        for(short j{}; j < resto; ++j) {
            bits[tam - j] = bits[tam - 1 - j];
        }
        bits[tam - resto] = temp;
    }
}

void decodificacion_metodo_2(bool* bits, const unsigned long long tam, const unsigned short n_raiz) {
    unsigned short resto = tam % n_raiz;
    unsigned long long procesos = tam - resto;
    unsigned long long i;
    for(i = 1; i <= procesos; ++i) {
        unsigned long long seccion_bits = i * n_raiz;
        bool temp = bits[seccion_bits - 1];
        for(short j = n_raiz; j > 0; j--) {
            bits[seccion_bits - j] = bits[seccion_bits - j + 1];
        }
        bits[seccion_bits - 1] = temp;
    }
    if(resto > 0) {
        bool temp = bits[tam - resto];
        for(short j = n_raiz; j > 0; j--) {
            bits[tam - i] = bits[tam - i + 1];
        }
        bits[tam - 1] = temp;
    }
}

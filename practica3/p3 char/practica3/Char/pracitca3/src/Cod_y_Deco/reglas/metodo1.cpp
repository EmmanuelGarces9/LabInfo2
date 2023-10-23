#include "../../../hdr/reglas/metodo1.h"

void codificacion_metodo_1(bool* bits, const unsigned long long tam, const unsigned short n_raiz) {
    bool* codificado = new bool[tam];
    int unos{}, ceros{};
    unsigned long long f{};

    for(int i{}; i < n_raiz; i++, f++) {
        !bits[f] ? ceros++ : unos++;
        codificado[f] = !(bits[f]);
    }

    while(f < tam) {
        comprobar_cero_uno_Cod(bits, codificado, f, n_raiz, ceros, unos);
        contar_bits(bits, ceros, unos, n_raiz, f);
    }

    for(f = 0; f < tam; f++) {
        bits[f] = codificado[f];
    }
    delete[] codificado;
}

void comprobar_cero_uno_Cod(const bool* og, bool* cod, unsigned long long& index, const int raiz_n, const int cero, const int uno) {
    if(uno == cero) {
        for(int i{}; i < raiz_n; i++, index++) {
            cod[index] = !(og[index]);
        }
    }
    else if(cero > uno) {
        bool caso = true;
        const unsigned long long cj = index;
        for(int i{}; i < raiz_n && index < cj + raiz_n; i++) {
            if(caso) {
                cod[index] = og[index];
                caso = false;
                index++;
                continue;
            }
            cod[index] = og[index] ? false : true;
            index++;
            caso = (index == cj + raiz_n) ? false : true;
        }
    }
    else {
        bool caso = true;
        const unsigned long long cj = index;
        for(int i{}; i < raiz_n && index < cj + raiz_n; i++) {
            if(caso) {
                cod[index] = og[index];
                if(index + 1 < cj + raiz_n) {
                    cod[++index] = og[index];
                }
                caso = false;
                index++;
                continue;
            }
            cod[index] = og[index] ? false : true;
            index++;
            caso = (index == cj + raiz_n) ? false : true;
        }
        index--;
    }
}

void decodificacion_metodo_1(bool* bits, const unsigned long long tam, const unsigned short n_raiz) {
    bool* decodificado = new bool[tam];
    int unos{}, ceros{};
    unsigned long long f{};

    for(int i{}; i < n_raiz; i++, f++) {
        bits[f] ? ceros++ : unos++;
        decodificado[f] = !(bits[f]);
    }

    while(f < tam) {
        comprobar_cero_uno_Deco(bits, decodificado, f, n_raiz, ceros, unos);
        contar_bits(decodificado, ceros, unos, n_raiz, f);
    }

    for(f = 0; f < tam; f++) {
        bits[f] = decodificado[f];
    }
    delete[] decodificado;
}

void comprobar_cero_uno_Deco(const bool* og, bool* deco, unsigned long long& index, const int raiz_n, const int cero, const int uno) {
    if(uno == cero) {
        for(int i{}; i < raiz_n; i++, index++) {
            deco[index] = !(og[index]);
        }
    }
    else if(cero > uno) {
        bool caso = true;
        const unsigned long long cj = index;
        for(int i{}; i < raiz_n && index < cj + raiz_n; i++) {
            if(caso) {
                deco[index] = og[index];
                caso = false;
                index++;
                continue;
            }
            deco[index] = og[index] ? false : true;
            index++;
            caso = (index == cj + raiz_n) ? false : true;
        }
    }
    else {
        bool caso = true;
        const unsigned long long cj = index;
        for(int i{}; i < raiz_n && index < cj + raiz_n; i++) {
            if(caso) {
                deco[index] = og[index];
                if(index + 1 < cj + raiz_n) {
                    deco[++index] = og[index];
                }
                caso = false;
                index++;
                continue;
            }
            deco[index] = og[index] ? false : true;
            index++;
            caso = (index == cj + raiz_n) ? false : true;
        }
        index--;
    }
}

void contar_bits(const bool* bits, int& ceros, int& unos, const int n_raiz, const int index) {
    unsigned long long bloque = index - n_raiz;
    unos = 0;
    ceros = 0;
    for (int i{}; i < n_raiz; i++, bloque++){
        bits[bloque] ? unos++ : ceros++;
    }
}

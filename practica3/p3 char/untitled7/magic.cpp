#include "magic.h"


char* unir_char(const char* text1, const char* text2) {
    unsigned long long letters1 = count_letters(text1);
    unsigned long long letters2 = count_letters(text2);

    if(letters1 == 0) return nullptr;

    unsigned long long i{};
    char* final = new char[letters1 + letters2 + 1];
    for(; i < letters1; ++i) {
        final[i] = text1[i];
    }
    for(unsigned long long j{}; j < letters2; ++j, ++i) {
        final[i] = text2[j];
    }
    final[i] = '\0';
    return final;
}

unsigned long long count_letters(const char* text) {
    unsigned long long count{};
    while(text[count] != '\0') {
        ++count;
    }
    return count;
}


void post_reglas(const char* file_name, const bool* bits, unsigned long long& tam) {
    const char* texto = nullptr;
    try{
        texto = binario_a_texto(bits, tam);

        if(texto == nullptr) {
            throw runtime_error("Error de conversion");
        }
        delete[] bits;
        bits = nullptr;

        tam /= 8;
        guardar_archivo(file_name, texto, tam);
        delete[] texto;
        texto = nullptr;
    }
    catch(const exception& e) {
        if(bits != nullptr) {
            delete[] bits;
        }
        if(texto != nullptr) {
            delete[] texto;
        }
        cerr << "Error: " << e.what() << endl;
    }
}

void guardar_archivo(const char* file_name, const char* text, const unsigned long long& tam) {
    fstream file;

    file.open(file_name, ios_base::out);
    if(!file.is_open()) {
        throw runtime_error("Error al escribir el archivo");
    }
    file << text;
    file.close();
    cout << "Proceso completado. :]" << endl;
}

char* binario_a_texto(const bool* bits, const unsigned long long& tam) {
    char* texto = new char[(tam/8) + 1];
    for(unsigned long long i=1; i <= (tam/8); i++) {
        texto[i-1] = byte2char(bits, i*8);
        texto[i] = '\0';
    }
    return texto;
}

char byte2char(const bool* byte, unsigned long long actual_pos) {
    char letra{};
    for(short position = 8, powDos = 128; position > 0; position--, powDos /= 2) {
        if(byte[actual_pos - position]) letra += powDos;
    }
    return letra;
}

bool* pre_reglas(const char* file_name, unsigned long long& tam) {
    bool* text_bits = nullptr;
    char* text = nullptr;
    try {
        text = leer_archivo(file_name, tam);
        if(text != nullptr) {
            text_bits = archivo_a_binario(text, tam);
            delete[] text;
            text = nullptr;
            tam *= 8;
            return text_bits;
        }
        throw runtime_error("Error al leer el archivo.");
    }
    catch(const exception& e) {
        if(text != nullptr) {
            delete[] text;
        }
        if(text_bits != nullptr) {
            delete[] text_bits;
        }
        cerr << "Error: " << e.what() << endl;
    }
    return nullptr;
}

char* leer_archivo(const char* file_name, unsigned long long& tamal) {
    fstream file;
    char* text;

    file.open(file_name, ios_base::in | ios_base::ate);
    if(!file.is_open()) {
        return nullptr;
    }
    tamal = file.tellg();
    text = new char[tamal + 1];
    file.seekg(0);
    file.read(text, tamal);
    file.close();
    text[tamal] = '\0';
    return text;
}

bool* archivo_a_binario(const char* text, const unsigned long long& tam) {
    const int BITS_PER_BYTE = 8;
    bool* booleans = new bool[tam * BITS_PER_BYTE];
    unsigned long long index = 0;
    for(const char* ptr = text; *ptr != '\0'; ++ptr) {
        char letter = *ptr;
        for(int j = BITS_PER_BYTE - 1; j >= 0; --j, ++index) {
            booleans[index] = (letter >> j) & 1;
        }
    }
    return booleans;
}


void codificacion_metodo_1(bool* bits, const unsigned long long tam, const unsigned short n_raiz) {
    bool* codificado = new bool[tam];
    int unos{}, ceros{};
    unsigned long long f{};

    for(int i{}; i < n_raiz; i++, f++) {    //negar el primer bloque
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
        for(int i{}; i < raiz_n; i++, index++) {        //negarlos todos
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
    else { //unos>ceros
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



void codificacion_metodo_2(bool* bits, const unsigned long long tam, const unsigned short n_raiz) {
    unsigned short resto = tam % n_raiz;    //cantidad de bits que faltan que no se hacen en procesos exactos
    unsigned long long procesos = tam - resto; //cantidad de veces exactas que se va a hacer con la raiz
    unsigned long long i;
    for(i = 1; i <= procesos; ++i) {
        unsigned long long seccion_bits = i * n_raiz; //calcula el final de cada bloque
        bool temp = bits[seccion_bits - 1]; //toma el ultimo bit de cada bloque y lo guarda
        for(short j = 0; j < n_raiz; j++) {
            bits[seccion_bits - j - 1] = bits[seccion_bits - j - 2]; //hace la operación de correr los bits
        }                     //una posicion hacia la derecha o de la forma en la que se explica en la practica
        bits[seccion_bits-n_raiz]=temp; //pone el ultimo bit de cada bloque en el principio de cada bloque codificado
    }
    if(resto > 0) {
        bool temp = bits[tam - 1];          //codifica el resto que no se hicieron arriba
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
//sk

void procesarInformacion(const char* id, const int n_raiz, const bool COD, const bool M1_2) {
    char* file_name = nullptr;
    try {
        unsigned long long tam = 0;
        file_name = unir_char(id, COD ? ".txt" : ".dat");
        bool* bytes = pre_reglas(file_name, tam);

        if(bytes == nullptr) {
            throw runtime_error("Error pre_reglas");
        }
        delete[] file_name;
        file_name = nullptr;

        if(M1_2) {
            COD ?
                codificacion_metodo_1(bytes, tam, n_raiz) :
                decodificacion_metodo_1(bytes, tam, n_raiz);
        }
        else {
            COD ?
                codificacion_metodo_2(bytes, tam, n_raiz) :
                decodificacion_metodo_2(bytes, tam, n_raiz);
        }

        file_name = unir_char(id, COD ? ".dat" : ".txt");
        post_reglas(file_name, bytes, tam);
        delete[] file_name;
        file_name = nullptr;
    }
    catch (const exception& e) {
        if(file_name != nullptr) {
            delete[] file_name;
        }
        cerr << "Error: " << e.what() << endl;
    }
}


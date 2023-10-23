#include "../../../hdr/postreglas/magic.h"

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

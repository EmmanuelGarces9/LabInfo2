#include "../../hdr/codYDeco.h"

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

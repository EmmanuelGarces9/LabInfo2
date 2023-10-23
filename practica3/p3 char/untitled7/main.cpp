#include "magic.h"

int main() {
    bool COD;
    bool M1_2;
    int n_raiz;
    int id_tam = 20;
    char id[id_tam] = "1245578";

    cout<<"elija: Codificacion(1) o decodificacion(0) ";
    cin>>COD;
    cout<<"elija: Metodo 1(1) o Metodo 2(0) ";
    cin>>M1_2;
    cout<<"Cual es la raiz? ";
    cin>>n_raiz;


    procesarInformacion(id, n_raiz, COD, M1_2);


    return 0;
}

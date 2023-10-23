// #include "../hdr/codYDeco.h"
#include "../src/Cod_y_Deco/codYDeco.cpp"

int main() {
    bool COD;
    bool M1_2;
    int n_raiz;
    int id_tam = 20;
    char id[id_tam] = "1245578";
    
    cout<<"elija: Codificación(1) o decodificación(0) ";
    cin>>COD;
    cout<<"elija: Método 1(1) o Metodo 2(0) ";
    cin>>M1_2;
    cout<<"Cuál es la raiz? ";
    cin>>n_raiz;


    procesarInformacion(id, n_raiz, COD, M1_2);


    return 0;
}

#ifndef COD_Y_DECO
#define COD_Y_DECO

 #include "./extra/unir_char.h"
 #include "./postreglas/magic.h"
 #include "./prereglas/funcionesparametodos.h"
 #include "./reglas/metodo1.h"
 #include "./reglas/metodo2.h"
/*
#include "./../src/Cod_y_Deco/extra/unir_char.cpp"
#include "./../src/Cod_y_Deco/postreglas/magic.cpp"
#include "./../src/Cod_y_Deco/prereglas/funcionesparametodos.cpp"
#include "./../src/Cod_y_Deco/reglas/metodo1.cpp"
#include "./../src/Cod_y_Deco/reglas/metodo2.cpp"
*/
#include <iostream>

using namespace std;

void procesarInformacion(const char* id, const int n_raiz, const bool COD, const bool M1_2);
void procesarInformacion(const char* file, const int n_raiz, const bool COD, const bool M1_2);
// COD true: Codificacion ; false: Decodificacion
// M1_2 true: Metodo 1 ; false: Metodo 2

#endif // !COD_Y_DECO

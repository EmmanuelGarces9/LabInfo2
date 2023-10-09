#include "magic.h"
//#include "magic.cpp"



int main(){



    short START;
    cout << "Que programa quiere revisar : ";
    cin >> START;

    while(START != 0){


         if (START == 2){
            //Problema 2
            /*
            Genera un arreglo de 200 letras mayúsculas aleatorias, imprime este arreglo y luego
            imprime cuantas veces se repita cada letra en el mismo
            */
            Problema_2();
        }

        else if(START == 4){
        //Problema 4
        //Recibe una cadena de caracteres numéricos, la convierta a un número entero y retorne dicho número
        char *a = new char [18];
        long long z;

        cout << "Ingrese una cadena de solo numeros (hasta 10 digitos) : ";
        cin >> a;

        z = Problema_4(a);
        delete[] a;

        if (z == -1) cout << "La cadena ingresada no es valida" << endl;
        else cout << z << endl;
        }

        else if(START == 6){
        //Problema 6
        /*
        Recibe una cadena de caracteres y cambie las letras minúsculas por mayúsculas,
        los demás caracteres no deben ser alterados
        */
        short nc = 199;
        char *pera = new char[nc];

        cout << "Ingrese una cadena de hasta " << nc+1 << " caracteres : ";
        cin >> pera;

        Problema_6(pera);
        cout << pera << endl;
        delete[] pera;
        }

        else if(START == 8){
        //Problema 8
        /*
        Recibe una cadena de caracteres y separe los números del resto de caracteres,
        generando una cadena que no tiene números y otra con los números que había en la cadena original
        */
        problema_8();

        }
        else if(START == 10){
        //Problema 10
        //Mete un numero romano, imprime un numero entero
             problema_10();
        }

        else if(START == 12){
        //Problema 12
        //Comprobar si la matriz ingresada es un cuadrado magico
        Problema_12();
        }
        else if(START == 14){
        //Problema 14
        //Coje una matriz 5x5, la llena con los numeros del 1 al 25 y la rota 90 grados 3 veces
        int ***conj_matrices;
        unsigned short dim = 5;

        //cout<<"Ingrese la dimension de la matriz: ";
        //cin >> dim;

        conj_matrices = generar_conj_matrices(dim);
        Print_Conj_Matrices(conj_matrices,dim);
        }


        else if(START == 16){
        //Problema 16
        /*
        Calcula la cantidad de caminos que puede haber para recorrer una cuadricula
        La cuadricula es de nxn
        Solo se puede hacer pasos hacia la derecha y hacia abajo
        */
        Problema_16();
        }

        else if(START==18){
            problema18();
         }

        cout << "Que programa quiere revisar : ";
        cin >> START;


    }
    return 0;
}


#include "magic.h"

//ejercicio 2 mejorado:
void fun_c(double *a, int n, double *promedio, double* suma){
    int i;
    *suma = 0.0;
    for (i = 0; i < n; i++){
        *suma += *(a + i);
    }
    *promedio = *suma / n;
}





//Contador digitos
int contadorDigitos(long long a){
    int c = 0;

    while (a > 0){
        c++;
        a /= 10;
    }

    return c;
}

//Problema 2
void Problema_2(){
    srand((unsigned) time(NULL));
    char may[199] = ""; //crea el arreglo de las 200 mayusculas
    char *pmay = &may[0];
    short numero, i, cmayus[26] = {}; //crea el arreglo donde se almacena la cantidad que cada letra aparece

    numero = 65 + (rand() % 26);

    for(i = 0; i < 200; i++){
        *(pmay + i) = (char) numero;  //se agrega una letra aleatoria al arreglo
        *(pmay + i + 1) = '\0';       //se agrega el caracter final de cadena
        *(cmayus + (numero - 65)) += 1;     //se va sumando en cada posicion del arreglo segun la letra que apareció

        cout << *(pmay + i);

        numero = 65 + (rand() % 26);
    }
    cout << endl;

    Aux_P2(&cmayus[0]);
}

void Aux_P2(short *cm){
    for (short i = 0; i < 26; i++){
        cout << ((char) (65 + i)) << " = " << *(cm + i) << endl;
    }
}

















//Problema 4
int Problema_4(char *a){
    long long num = 0;
    short b, i;
    bool comprobar;

    comprobar = Aux_P4(a);

    if (comprobar){
        for (i = 0; *(a + i) != '\0'; i++){     //recorre todo el arreglo hasta encontrar el caracter final de arreglo
            b = (*(a + i)) - 48;                //lo convierte a entero
            num = (num * 10) + b;               //se construye el numero
        }
        return num;
    }
    return -1;
}

bool Aux_P4(char *n){
    for (short i = 0; *(n + i) != '\0'; i++){
        if (*(n + i) < 47 || *(n + i) > 57)         //comprueba si cada caracter ingresado es un numero
            return false;

    }


    return true;
}



















//Problema 6
void Problema_6(char *a){
    bool k;
    short h;

    for (int i = 0; *(a + i) != '\0'; i++){
        k = Aux_P6((a + i));
        h = (short) *(a + i);

        if(k){
            *(a + i) = h - 32;          //si la letra es minuscula, se cambia por mayuscula 32 es la distancia entre minusculas y mayusculas en la tabla ascii
        }
    }
}

bool Aux_P6(char *aoA){
    short b = (short) *(aoA);               //comprueba si la letra que le ingresaron es minuscula
    if (b >= 97 && b <= 122) return 1;
    return 0;
}




















void problema_8() {
    const int MAX_LENGTH = 300;         //tamaño máximo de lo que puede ingresar el usuario
    char* input = new char[MAX_LENGTH]; //arreglo de lo que ingresa el usuario
    char* numbers = new char[MAX_LENGTH];   //arreglo de los números que contiene el input
    char* text = new char[MAX_LENGTH];      // arreglo de texto que contiene el input

    cout << "Ingrese un texto (de " << MAX_LENGTH << " caracteres maximo): ";
    cin >> input;
    for(int i{}, number{}, letter{}; input[i] != '\0'; i++) {  //ciclo que recorre todo el input caracter por caracter
        if(es_numero(input[i])) {                              //comprueba si el caracter es un numero
            numbers[number++] = input[i];                      //si es un numero se agrega al arreglo de numeros y se pone el final de input siempre al final
            numbers[number] = '\0';
            continue;                                          // continue para que no haga lo de abajo y siga en el ciclo (se hace para no poner un else abajo
        }
        text[letter++] = input[i];                             //al no entrar en el if de arriba, es una letra y se agrega al arreglo de letras se pone el final de input siempre al final
        text[letter] = '\0';
    }

    cout << "Original: ";
    print_string(input, true);

    cout << "Texto: ";
    print_string(text, true);

    cout << "Numero: ";
    print_string(numbers, true);

    delete[] input;
    delete[] numbers;
    delete[] text;
}

bool es_numero(const char letter) {
    if(letter >= 48 && letter <= 57) {                  //comprueba si el caracter es un numero con la tabla ascii
        return true;
    }
    return false;
}

void print_string(const char* text, const bool use_endl) {      // toma al arreglo que quiere imprimir y un bool si quiere un salto de linea al final
    for(int i{}; text[i] != '\0'; i++) {                        // recorre todo el arreglo y lo imprime
        cout << text[i];
    }
    if(use_endl) {                                              // salto de linea luego imprimir el texto
        cout << endl;
    }
}



























void problema_10() {
    const int tam = 13;
    char* romano = new char[tam];
    short numero;

    cout << "Ingrese un numero romano: ";
    cin >> romano;
    numero = conversion_romano_decimal(romano, contar_char(romano));
    if(numero != 0) {
        cout << "El numero es: " << numero << endl;
    }

    delete[] romano;
}

short conversion_romano_decimal(const char* romano, const int size) {
    //Arreglo ordenado con los valores que toma cada letra en los numeros romanos
    short roman[] = {
        1,
        5,
        10,
        50,
        100,
        500,
        1000
    };

    short number{};
    short temp{};

    for(int i = size - 1; i >= 0; i--) {
        //obtener el index del arreglo roman
        short index = obtener_index(romano[i]);
        if(index == -1) {
            //Para letras invalidas
            return 0;
        }
        //Se obtiene el valor de la letra usando roman
        short value = roman[index];
        if(value < temp) {
            //Si el valor de temp es menor que el valor actual se resta
            number -= value;
        }
        else {
            //Si el valor de temp es mayor o igual que el valor actual se suma
            number += value;
        }
        //Actualizar valor de temp
        temp = value;
    }
    return number;
}

short obtener_index(const char letra) {
    switch(letra) {
        case 'I':
            return 0;
        case 'V':
            return 1;
        case 'X':
            return 2;
        case 'L':
            return 3;
        case 'C':
            return 4;
        case 'D':
            return 5;
        case 'M':
            return 6;
        default:
            cout << "Numero romano no valido." << endl;
            return -1;
    }
}

short contar_char(const char* texto) {
    short i{};
    for(i = 0; texto[i] != '\0'; i++) {}
    return i;
}































bool** BFillMatrix(unsigned short fil, unsigned short col){
    //Crea una matriz desde la funcion dinamica_p2
    bool** matriz = BCreateMatrix(fil, col);

    //A cada posicion de la matriz se le asigna un valor (en este caso de 1 a (dim^2))
    for (unsigned short f = 0; f < fil; f++){
        for (unsigned short c = 0; c < col; c++) matriz[f][c] = 0;
    }

    return matriz;
}

bool** BCreateMatrix(unsigned short f, unsigned short c){
    //Crea una matriz de dim filas
    bool** a = new bool* [f];

    //A cada fila le crea dim columnas
    for (unsigned short i = 0; i < f; i++) a[i] = new bool [c];

    return a;
}
void BPrintMatrix(bool** matriz, unsigned short fil, unsigned short col){
    for (unsigned short f = 0; f < fil; f++){
        for (unsigned short c = 0; c < col; c++){
            if (matriz[f][c] == 0) cout << "-  ";
            else cout << "+  ";
        }
        cout << endl;
    }
}




















//Problema 12
void Problema_12(){
    unsigned short dimension;
    int** matrix;
    bool comproba;

    cout << "Ingrese el tamaño de la matriz cuadrada a (nxn): ";
    cin >> dimension;

    matrix = ISqFillMatrix(dimension);

    comproba = CMagico(matrix, dimension);

    ISqPrintMatrix(matrix, dimension);

    if (comproba) cout << "La matriz a es un cuadrado magico" << endl;
    else cout << "La matriz a NO es un cuadrado magico" << endl;
    delete matrix;
}

bool CMagico(int** m, unsigned short dim){
    int vac = 0, cn;
    unsigned short f, c;

    //Comprueba que no hayan repetidos
        for(int h{}; h < dim; h++) {
            for(int i{}; i < dim; i++) {
                for(int j = i + 1; j < dim; j++) {
                    if(m[h][i] == m[h][j]) return false;
                }
            }
        }

    //vac : La suma de los numeros de la fila 1 (fila posicion 0)
    for (unsigned short i = 0; i < dim; i++) vac += m[0][i];

    //Comprueba que la suma de los valores de las otras filas sea igual a vac
    for (f = 1; f < dim; f++){
        cn = 0;
        for (c = 0; c < dim; c++){
            cn += m[f][c];
        }
        if (cn != vac) return 0;
    }

    //Comprueba que la suma de los valores de las columnas sea igual a vac
    for (c = 0; c < dim; c++){
        cn = 0;
        for (f = 0; f < dim; f++){
            cn += m[f][c];
        }
        if (cn != vac) return 0;
    }

    //Comprueba que la suma de los valores de la diagonal principal sea igual a vac
    for (cn = 0, c = 0; c < dim; c++) cn += m[c][c];
    if (cn != vac) return 0;

    //Comprueba que la suma de los valores de la diagonal principal sea igual a vac
    for (cn = 0, c = 0; c < dim; c++) cn += m[c][dim-1-c];
    if (cn != vac) return 0;

    return 1;
}

int** ISqFillMatrix(unsigned short dim){
    //Crea una matriz desde la funcion Create
    int ** matriz = ISqCreateMatrix(dim), nu;

    //A cada posicion de la matriz se le asigna un valor (en este caso de 1 a (dim^2))
    for(unsigned short f = 0; f < dim; f++){
        for(unsigned short c = 0; c < dim; c++){
            cout << "Ingrese el numero en la posicion a" << f+1 << c+1 << " : ";
            cin >> nu;
            matriz[f][c] = nu;
        }
    }
//xd
    return matriz;
}

int** ISqCreateMatrix(unsigned short dim){
    //Crea una matriz de dim filas
    int ** a = new int* [dim];

    //A cada fila le crea dim columnas
    for(unsigned short i = 0; i < dim; i++) a[i] = new int [dim];

    return a;
}

void ISqPrintMatrix(int** matriz, unsigned short dim){
    for(unsigned short f = 0; f < dim; f++){
        for(unsigned short c = 0; c < dim; c++) cout << matriz[f][c] << '\t';
        cout << endl;
    }
}






















//Problema 14

int ** generar_matriz(unsigned short dim){
    //Crea una matriz desde la funcion Create
    int ** matriz = Create(dim);

    //A cada posicion de la matriz se le asigna un valor (en este caso de 1 a (dim^2))
    for(unsigned short f = 0, valor = 1; f < dim; f++){
        for(unsigned short c = 0;c < dim; c++, valor++) {
            matriz[f][c] = valor;                           //llenar la matriz desde 1 hasta 25
        }
    }

    return matriz;
}

int ** Create(unsigned short dim){    //crea una matriz cuadrada
    //Crea una matriz de dim filas
    int ** a = new int* [dim];

    //A cada fila le crea dim columnas
    for(unsigned short i=0;i<dim;i++) a[i] = new int [dim];

    return a;
}

void imprimir_matriz(int **matriz, unsigned short dim){
    for(unsigned short f=0;f<dim;f++){
        for(unsigned short c=0;c<dim;c++){
            cout << matriz[f][c] << '\t';
        }
        cout << endl << endl;
    }
}

int *** generar_conj_matrices(unsigned short dim){
    int ***conj_matrices = new int **[4];       //arreglo de matrices, 1 normal, 1 90 grados, 1 180 y así
    conj_matrices[0] = generar_matriz(dim);     //en la primera posicion tendrá la matriz normal
    for(unsigned short i=1;i<4;i++) conj_matrices[i] = Rotar_90(conj_matrices[i-1],dim);    //se agrega cada matriz rotada al arreglo de matrices
    return conj_matrices;
}

int ** Rotar_90(int ** matriz, unsigned short dim){
    int ** R_matriz = Create(dim);                  //crea una nueva matriz

    for(unsigned short f=0;f<dim;f++){
        for(unsigned short c=0;c<dim;c++){  //Itera sobre la matriz original
            //se llena la nueva matriz
            R_matriz[c][dim-f-1] = matriz[f][c];    // se toma cada valor de cada fila y se ponen como columnas de arriba hacia abajo (esto lo hace c) y luego de derecha a izquierda  (esto lo hace dim-f-1)
        }
    }
    return R_matriz;
}

void Print_Conj_Matrices(int ***conj_matrices, unsigned short dim){
    for(unsigned short i=0;i<4;i++){
        cout << "Matriz rotada " << i*90 << " grados" << endl << endl;      //imprime cada matriz del arreglo de matrices
        imprimir_matriz(conj_matrices[i],dim);
        cout << endl << endl;
    }
}



//Problema 16
void Problema_16(){
    unsigned short dim;
    long long f1 = 1, f2 = 1, dn;

    cout << "Ingrese el numero de la cuadricula : ";
    cin >> dim;

    dn = 2 * dim; //para calcular el factorial de la formula del coeficiente binomial

    for (int a = 1; a <= dn; a++) {   //calcula el factorial de dn
        f1 *= a;
    }

    for (int b = 1; b <= dim; b++) {  //calcula el factorial de n
        f2 *= b;
    }

    f2 *= f2;
    f1 /= f2;               //formula del coeficiente binomial de (2n, n)

    cout << "Para una cuadricula de " << dim << "x" << dim << " cuadros hay : " << f1 << " caminos" << endl;
}



//Problema 18

int factorial(int n);
string nth_permutation(int digits[], const int tam, int n);
void problema18();

// Función para calcular el factorial del numero que toma como parametro
int factorial(int n) {
    if (n == 0) return 1;

    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Función para encontrar la enésima permutación lexicográfica
string nth_permutation(int digits[], const int tam, int n) {
    string permutation;

    n -= 1;  // ya que los para sacar index's, siempre empiezan con 0
    int available_digits[tam];  // Crear available_digits
        // Llenar available_digits
        for(int i = 0; i < tam; ++i) available_digits[i] = digits[i];

        for(int i = tam - 1; i >= 0; --i) {
            int total_permutations = factorial(i);  // Permutaciones posibles con los digitos restantes
            int index = n / total_permutations;

            int digit = available_digits[index];    //Obtiene el digito para agregar
            permutation += to_string(digit);    // Agrega el digito a la permutacion

            // "Eliminar" el dígito utilizado
            // No se elimina realmente, solo se deja de tener ese valor disponible
            for(int j = index; j < i; ++j) {
                available_digits[j] = available_digits[j + 1];
            }

            n %= total_permutations;    // Se encuentra el numero de permutaciones disponibles que incluya los digitos anteriores agregados en la permutacion
        }

        return permutation;
    }

    void problema18() {
        const int tam = 10;
        int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int n;
        //n = 1000000;
        cout << "Ingrese el numero de permutacion que desee obtener: ";
        cin >> n;

        string nth_permutation_str = nth_permutation(digits, tam, n);

        cout << "La " << n << "-ésima permutación lexicográfica de los dígitos es: "
            << nth_permutation_str << endl;
    }



#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
        //Ejercicio 2
        /*int A;

        cout << "Ingrese el numero a analizar : ";
        cin >> A;

        if (A % 2 != 0){
            cout << A << " es impar";
        }
        else{
            cout << A << " es par";
        }
        */

        //Ejercicio 4
        /*int A, B;

        cout << "Ingrese el primer numero : ";
        cin >> A;

        cout << "Ingrese el segundo numero : ";
        cin >> B;

        if (A < B){
            cout << "El menor es " << A << endl;
        }
        else{
            cout << "El menor es " << B << endl;
        }
        */

        //Ejercicio 6
        /*int A, B, a = 0, b = 0;

        cout << "Ingrese la base : ";
        cin >> A;

        cout << "Ingrese el exponente : ";
        cin >> B;

        while (b < B){
            if (a == 0) a = A;
            else a *= A;
            b += 1;
        }
        cout << A << "^" << B << " = " << a << endl;
        */




        //Ejercicio 8
        /*int A, ac = 1, b = 0, c = 1;

        cout << "Ingrese el numero : ";
        cin >> A;

        while (b < A){
            ac *= c;
            c += 1;
            b += 1;
        }

        cout << A << "!=" << ac << endl;
        */


        //Ejercicio 10
        /*int A, b = 0, c = 1;

        cout << "Ingrese el numero : ";
        cin >> A;

        cout << "Multiplos de " << A << " menores que 100 :" << endl;

        while (b <= 100)
            b = A * c;
            if (b<100) cout << b << endl;
            c += 1;
        }
        */


        //Ejercicio 12
        /*int A, B = 5, a = 0, b = 0;

        cout << "Ingrese el numero : ";
        cin >> A;

        while (b < B){
            while (a == 0){
                a = A;
            }
            else{
            a *= A;
            }
            b += 1;
            cout << A << "^" << b << "=" << a << endl;
        }
        */

        //Ejercicio 14
        /*int A = 1, B = 50;

        while (A <= 50 && B >= 0) cout << A++ << "     " << B-- << endl;
        */


        //Ejercicio 16
        /*int a, b = 0, c = 0, d;

        cout << "Ingrese los números que desee para sacar su promedio(Si desea terminar de añadir numeros ingrese el 0) : ";
        cin >> a;

        while (a != 0){
            b += a;
            c += 1;
            cin >> a;
        }
        d = b / c;
        cout << "El promedio es : " << d << endl;
        */




        //Ejercicio 18
        /*int a = 1, cuadrado, e;
        bool verificar = true;

        cout << "Ingrese un numero para verificar si es cuadrado perfecto : ";
        cin >> e;

        while (verificar == true){
            cuadrado = a * a;

            if (cuadrado == e){
                verificar = false;
            }
            else{
                a += 1;
            }

            if (cuadrado > e){
                break;
            }
        }

        if (verificar == false){
            cout << e << " si es un cuadrado perfecto" << endl;
        }
        else{
            cout << e << " NO es un cuadrado perfecto" << endl;
        }
        */


        //Ejercicio 20
        /*int a, b, c = 0, d;

        cout << "Ingrese un numero entero: ";
        cin >> d;

        a = d;

        while (a > 0) {
            b = a % 10;
            c = (c * 10) + b;
            a /= 10;
        }

        if (d == c) {
            cout << "El numero es palindromo" << endl;
        }
        else {
            cout << "El numero no es palindromo" << endl;
        }
        */



        //Ejercicio 22
        /*long int seg, hora = 0, min = 0;

        cout << "Ingrese la cantidad de segundos: ";
        cin >> seg;

        if (seg >= 3600){
            hora = seg / 3600;
            seg -= hora * 3600;
        }

        if (seg >= 60){
            min = seg / 60;
            seg -= min * 60;
        }

        cout << hora << ":" << min << ":" << seg;
        */


        //Ejercicio 24
        /*long int num, esp;
        int a = 0, b = 0, c = 0;

        cout << "Ingrese el número: ";
        cin >> num;

        while (a < num){
            cout << "+";
            a += 1;
        }

        cout << endl;
        a = 0;

        while (a + 2 < num){
            cout << "+";
            esp = num - 2;
            while (b < esp){
                cout << " ";
                b += 1;
            }
            cout << "+" << endl;
            a += 1;
            b = 0;
        }

        a = 0;

        while (a < num){
            cout << "+";
            a += 1;
        }
        */


        //Ejercicio 26
        /*long int medida1, medida2, medida3, comprobar;

        bool si = true, isosceles = false, equilatero = false, escaleno = false;

        cout << "Ingrese la medida del primer lado: ";
        cin >> medida1;

        cout << "Ingrese la medida del segundo lado: ";
        cin >> medida2;

        cout << "Ingrese la medida del tercer lado: ";
        cin >> medida3;

        while (si == true) {
            comprobar = (medida1 * 2) - 1;

            if (medida1 == medida2 && comprobar == medida3){
                    cout << "Sus medidas forman un triangulo isosceles" << endl;
                    isosceles = true;
                    break;
            }

            if (medida1 == medida2 && medida1 == medida3){
                    cout << "Sus medidas forman un triangulo equilatero" << endl;
                    equilatero = true;
                    break;
            }

            if (medida1 != medida2 && medida1 != medida3){
                    cout << "Sus medidas forman un triangulo escaleno" << endl;
                    escaleno = true;
                    break;
            }

            if (isosceles == false && equilatero == false && escaleno == false){
                cout << "sus medidas no forman ningun triangulo" << endl;
                break;
            }
        }
        */





        //Ejercicio 28
        /*int c, d, deno = 1;
        bool mm = 0;
        float suma = 0;

        cout << "Ingrese el numero que determina la presicion del numero pi : ";
        cin >> c;

        while (d < c){
            if (mm == 0){
                suma += 1 / float(deno);
                mm = 1;
            }
            else{
                suma -= 1 / float(deno);
                mm = 0;
            }
            deno += 2;
            d += 1;
        }
        suma = suma * 4;
        cout << suma << endl;
        */


        //Ejercicio 30
        /*srand(time(NULL));
        int numero, c = 0, B;
        bool mmi = false;

        numero = 0 + rand() % 101;

        cout << "Adivina el numero que estoy pensando.";

        while (mmi == false){
            cout << " Ingresa tu candidato : ";
            cin >> B;

            if (B < numero){
                cout << "Su numero es menor al mio." << endl;
                c += 1;
            }
            else if (B > numero){
               cout << "Su numero es mayor al mio." << endl;
               c += 1;
            }
            else if (B == numero){
                c += 1;
                mmi = true;
            }
        }

        cout << "Adivinaste mi numero en " << c << " intentos." << endl;
        */

    //problemas----------------------------------------------------------------------------------


    //Problema 2
        /*
        int plata;
        int denominacion[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};


        cout << "Ingrese la cantidad de dinero que va a cambiar : ";
        cin >> plata;

        for(int i = 0; i < 10; i++) {
        cout << denominacion[i] << " : " << plata / denominacion[i] << '\n';
        plata %= denominacion[i]; // va reduciendo la cantidad de dinero para seguir con los otros billetes
        }

        if(plata > 0) cout << "Faltante : " << plata << endl;
        */




        //Problema 4
        /*short int a, b, suma, min, hora;

        cout << "Ingrese una de las horas que desee sumar : ";
        cin >> a;

        cout << "Ingrese la otra hora que desee sumar : ";
        cin >> b;

        if (a >= 2400 || b >= 2400){
            cout << "Se ingresó una hora invalida" << endl;
        }
        else if (a % 100 >= 60 || b % 100 >= 60){
            cout << "Se ingresó una hora invalida (los minutos no deben ser mayor que 60)" << endl;
        }
        else {
            hora = (a / 100) + (b / 100);
            min = (a % 100) + (b % 100);

            if (min >= 60){
                min -= 60;
                hora += 1;
            }

            if (hora >= 24) hora -= 24; //para que no se pase de las 24 y comience en la madrugada del formato militar

            suma = (hora * 100) + min; //para darle la forma del formato que nos piden multiplicamos por 100 y sumamos los minutos

            cout << suma << endl;
        }
        */

        //Problema 6
        /*short m = 2;
        int deno = 1, c, d = 0;
        float suma = 0;

        cout << "Ingrese un numero que dira la presicion del numero de euler : ";
        cin >> c;

        while (d < c){
            if (d < 2){
                suma += 1 / deno; //ya que las dos primeras iteraciones tienen denominador 1 por 0! y 1!
            }
            else{
                // el denominador ya empieza a incrementarse y más con sus factoriales, por lo que empieza en 2.
                deno *= m;
                suma += 1 / float(deno);
                m += 1;
            //deno almacena cada factorial anterior a m!, por lo que deno*m seria lo mismo que m! y por eso funciona: 2!*3=3!, 3!*4=4!, 4!*5=5! y así.
            }
            d += 1; //para que se repita c veces (lo ingresado por el usuario
        }
        cout << suma << endl;
        */


    //Problema 8
        /*
        int a, b, c, suma = 0;

        //Recibe un numero a
        cout << "Ingrese el numero a : ";
        cin >> a;

        //Recibe un numero b
        cout << "Ingrese el numero b : ";
        cin >> b;

        //Recibe un numero c para limitar la cantidad de multiplos
        cout << "Ingrese el numero c : ";
        cin >> c;

        //a y b tienen que ser menores que c para que hayan multiplos de estos menores que c
        if(a < c && b < c) {
        //Comprueba si hay multiplos menores que c
        for(int n = 1; n < c; n++) {
            bool v = false;
            if(n % a == 0 || n % b == 0){
            suma += n;
            cout << n;
            if(n+1 != c) {
                v = true;
            }
            }

            if(n != c && v == true){
            cout << "+";
            }
        }

        cout << " = " << suma << endl;
        }
        */

    //Problema 10
        /*
        int a = 2, posicion, contador = 0, tprimo;

        cout << "Ingrese un numero para ver que numero primo esta en esa posicion : ";
        cin >> posicion;

        //contador tiene que ser igual a posicion
        //De esta manera se tiene el primo en la posicion deseada
        while(contador < posicion){
        //Encontrar un numero primo
        bool es_primo = true;
        for(int i = 2; i < a; i++) {
            if(a % i == 0) {
            es_primo = false;
            break;
            }
        }

        //Si el numero es primo se aumenta el contador
            if (es_primo){
                contador += 1;
                tprimo = a;
            }
            ++a;
        }
        cout << "El primo en la posicion " << contador << " es : " << tprimo << endl;
        */



    //Problema 12
        /*
        int tprimo, b;

        cout << "Ingrese un numero para comprobar su factor primo mayor: ";
        cin >> b;

        for(int a = 2; a <= b; a++) {
            //Encontrar un numero primo
        bool es_primo = true;
        for(int i = 2; i < a; i++) {
                if (a % i == 0) {
                    es_primo = false;
                    break;
                }
        }

            //Encontrar si es multiplo de b
            //Como a va aumentando si se realiza el cambio siempre tprimo sera un numero mayor
            if (es_primo && b % a == 0){
                tprimo = a;
            }
        }
        cout << "El mayor factor primo de " << b << " es: " << tprimo << endl;
        */

    //Problema 14
        /*
        int temp, num;
        int j = 999, k = 999;
        bool turno = false;
        while(true) {
        //Se obtiene j * k
        int reverso = 0;
            num = j * k;
            temp = num;

        //Se encuentra el reverso de este numero
            while(temp > 0) {
                int digito = temp % 10;
                reverso = (reverso * 10) + digito;
                temp /= 10;
            }

        //Se comprueba que sean iguales
            if(num == reverso) {
                break;
            }

        //Si eran diferentes se va a restar 1 a j o a k
        //Esta resta se da por turnos
            if(turno) {
                --k;
                turno = false;
            }
            else {
                --j;
                turno = true;
            }
        }
        cout << "Numero palindromo mas grande encontrado en una multiplicacion de 2 numeros de 3 cifras\n";
        cout << j << " * " << k << " = " << num << endl;
        */



    //Problema 16
        /*
        int input, semilla = 1, comprobar, terminos = 1;

        cout << "Ingrese un numero : ";
        cin >> input;

        //Se realiza hasta que i sea igual a input
        //Esto hace que se mantenga dentro del rango deseado
        for(int i = 1; i < input; i++) {
            int tempTerminos = 1;
            comprobar = i;

        //Se comprueba serie de Collatz del numero comprobar
            while(comprobar != 1){
                if (comprobar % 2 == 0) comprobar /= 2;
                else comprobar = 3 * comprobar + 1;
            ++tempTerminos;
            }

        //Si los terminos guardados son mayores que los pasados
        //Se guardan la semilla y su cantidad de terminos
            if(tempTerminos > terminos){
                terminos = tempTerminos;
                semilla = i;
            }
        }

        cout << "La serie mas larga es con la semilla: " << semilla << ", teniendo " << terminos << " terminos" << endl;
        /*
    return 0;
}

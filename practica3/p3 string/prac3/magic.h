#ifndef MAGIC_H
#define MAGIC_H
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;


string lectura (string& nombre);
string codificacion (string& texto,int metodo,int semilla) ;
string decodificacion (string& texto, int metodo, int semilla);
string  binario_caracter (string& texto);
string caracter_binario(string& texto);
void escritura (string&nombre ,string& texto);
void menu_codificacion ();
void menu_decodificacion ();
void menu_app();
int inicio_sesion(string&);



#endif // MAGIC_H

#ifndef _MAGIC
#define _MAGIC
#include<string>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

//ejercicio 2
void fun_c(double *a, int n, double *promedio, double*suma);

//Menu
void MainMenu();
void P2();

void P4();

void P6();

void P8();

void problema_10();
short conversion_romano_decimal(const char* romano, const int size);
short obtener_index(const char letra);
short contar_char(const char* texto);


void P12();

void P14();
void P16();

void P18();

//Contador digitos
int contadorDigitos(long long);

//Problema_2
void Problema_2();
void Aux_P2(short *);


//Problema 4
int Problema_4(char*);
bool Aux_P4(char*);


//Problema 6
void Problema_6(char*);
bool Aux_P6(char*);

//Problema 8
void problema_8();
bool es_numero(const char letter);
void print_string(const char* text, const bool use_endl);

//Problema 10
void Problema_10(char*);
void Aux_P10(char, short*);
bool AP10(char*, short*);
short RomanoI(char*);
short RomanoV(char*);
short RomanoX(char*, bool);
short RomanoL(char*);
short RomanoC(char*, bool);
short RomanoD(char*);
short RomanoM(char*);

//Crear e imprimir matrices
    //Matriz de bool
bool** BFillMatrix(unsigned short, unsigned short);
bool** BCreateMatrix(unsigned short, unsigned short);
void BPrintMatrix(bool**, unsigned short, unsigned short);
    //Matriz de int cuadrada
int** ISqFillMatrix(unsigned short);
int** ISqCreateMatrix(unsigned short);
void ISqPrintMatrix(int**, unsigned short);
    //Matriz de short
void SFillMatrix(short**);
short** SCreateMatrix(short, short);

//Problema 12
void Problema_12();
bool CMagico(int**, unsigned short);


//Problema 14
int *** generar_conj_matrices(unsigned short);
int ** generar_matriz(unsigned short);
int ** Create(unsigned short);
int ** Rotar_90(int**, unsigned short);
void imprimir_matriz(int**, unsigned short);
void Print_Conj_Matrices(int***, unsigned short);



//Problema 16
void Problema_16();


int factorial(int );
string nth_permutation(int digits[], const int tam, int n);
void problema18();



#endif

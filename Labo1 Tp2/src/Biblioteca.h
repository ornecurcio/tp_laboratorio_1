/*
 * Biblioteca.h
 *
 *  Created on: 10 may. 2021
 *      Author: orne_
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
void getChar(char* mensaje, char* rta);
void inicializarArrayChar(char pArray[], int cantidadDeArray);
void inicializarArrayNumFlo(float pArray[], int cantidadDeArray);
void getString(char mensaje[], char imput[]);
void inicializarArrayCadena(char pArray[][20], int cantidadDeArray);
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getCaracterSexo(char* pResultado,char* mensaje,char* mensajeError, int reintentos);
int utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos);
int printDatos(char pArray[][20], int limite, char sex[], int leg[], int not1[], int not2[], float prom[]);
int utn_SwapAscendiente(int listaDeArray[],int cantidadDeArray);
int ordenar1ArrayStr(char pArrayApellido[][20], int limite, int nota1[], int nota2[], int legajo[], float promedio[], char sexo[]);
int promediar2Notas(float* pPromedioResultado, int num1, int num2);
int utn_getNumeroConDecimales(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);
int utn_getCaracterSN();


#endif /* BIBLIOTECA_H_ */

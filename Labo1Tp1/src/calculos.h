/*
 * calculos.h
 *
 *  Created on: 2 abr. 2021
 *      Author: orne_
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

int sumar(int* pResultado, int numUno, int numDos);
int restar(int* pResultado, int numUno, int numDos);
int multiplicar(int* pResultado, int numUno, int numDos);
int dividir(float* pResultado, int numUno, int numDos);
int promediarArray(float* pPromedioResultado, int array[], int cantidadArray);
void imprimirArray(int listaDeArray[], int cantidadDeArray);
int factorial(int* pResultado, int num);
int imprimirArrayResultados(int listaDeArray[], int resultadosArray[], float resultadoDiv);
#endif /* CALCULOS_H_ */

/*
 * calculos.h
 *
 *  Created on: 2 abr. 2021
 *      Author: orne_
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

int utn_sumar(int* pResultado, int numUno, int numDos);
int utn_restar(int* pResultado, int numUno, int numDos);
int utn_multiplicar(int* pResultado, int numUno, int numDos);
int utn_dividir(float* pResultado, int numUno, int numDos);
int utn_promediarArray(float* pPromedioResultado, int array[], int cantidadArray);
void utn_imprimirArray(int listaDeArray[], int cantidadDeArray);
int utn_factorial(int* pResultado, int num);
int imprimirArrayResultados(int listaDeArray[], int resultadosArray[], float resultadoDiv);
#endif /* CALCULOS_H_ */

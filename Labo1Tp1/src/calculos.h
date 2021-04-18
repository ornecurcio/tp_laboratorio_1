/*
 * calculos.h
 *
 *  Created on: 2 abr. 2021
 *      Author: orne_
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
// DEVUELVEN != 0 SI HAY ALGUN ERROR, DEVUELVE (0) SI NO HAY ERRORES
int utn_sumar(int* pResultado, int numUno, int numDos);
//toma dos parametros, numeros enteros por valor, pasa por referencia el resultado de la suma
int utn_restar(int* pResultado, int numUno, int numDos);
//toma dos parametros, numeros enteros por valor, pasa por referencia el resultado de la resta
int utn_multiplicar(int* pResultado, int numUno, int numDos);
//toma dos parametros, numeros enteros por valor, pasa por referencia el resultado de la multiplicacion
int utn_dividir(float* pResultado, int numUno, int numDos);
////toma dos parametros, numeros enteros por valor, pasa por referencia el resultado de la division, valida que numDos!=0.
int utn_promediarArray(float* pPromedioResultado, int array[], int cantidadArray);
//recorre un array de numeros enteros, realiza el promedio del mismo y pasa su resultado por referencia
void utn_imprimirArray(int listaDeArray[], int cantidadDeArray);
// recorre un array de numeros enteros, devuelve por consola los valor guardados en el array
int utn_factorial(int* pResultado, int num);
//toma por valor un numero entero positivo, realiza el factorial del mismo y pasa el resultado por referencia
int imprimirArrayResultados(int listaDeArray[], int resultadosArray[], float resultadoDiv);
//toma por referencia los arrays, muestra por consola los resultados

#endif /* CALCULOS_H_ */

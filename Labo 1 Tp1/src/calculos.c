/*
 * calculos.c
 *
 *  Created on: 2 abr. 2021
 *      Author: orne_
 */
#include <stdio.h>
#include <stdlib.h>

int sumar(int* pResultado, int numUno, int numDos)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado = numUno+numDos;
		retorno=0;
	}

	return retorno;
}
int restar(int* pResultado, int numUno, int numDos)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado = numUno-numDos;
		retorno=0;
	}

	return retorno;
}
int multiplicar(int* pResultado, int numUno, int numDos)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado = numUno*numDos;
		retorno=0;
	}

	return retorno;
}
int dividir(float* pResultado, int numUno, int numDos)
{
	int retorno = -1;

	if(pResultado != NULL && numDos!=0)
	{
		*pResultado = (float)numUno/numDos;
		retorno=0;
	}

	return retorno;
}
int promediarArray(float* pPromedioResultado, int array[], int cantidadArray)
{
	int retorno = -1;
	int i;
	int acumulador=0;

	if(pPromedioResultado != NULL)
	{
		for(i=0; i<cantidadArray; i++)

		{
		acumulador = acumulador + array[i];
		}

		*pPromedioResultado = (float)acumulador/cantidadArray;
	}
	return retorno;
}



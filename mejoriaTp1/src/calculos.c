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
void imprimirArray(int listaDeArray[], int cantidadDeArray)
	{	int i;
		for(i=0; i<cantidadDeArray; i++)
		{
			printf("%d ", listaDeArray[i]);
		}
	}
int factorial(int* pResultado, int num)
{
	int retorno= 0;
	*pResultado=0;
	return retorno;
}
int imprimirArrayResultados(int listaDeArray[], int resultadosArray[], float resultadoDiv)
	{
		int retorno = -1;
		do{
		if(listaDeArray[0]==0)
		{
			printf("\nEl resultado de la suma es %d\n", resultadosArray[0]);
		}
		else
		{
			printf("\nError, no se realizo la suma\n");
		}
		if(listaDeArray[1]==0)
		{
			printf("\nEl resultado de la resta es %d\n", resultadosArray[1]);
		}
		else
		{
			printf("\nError, no se realizo la resta\n");
		}
		if(listaDeArray[2]==0)
		{
			printf("\nEl resultado de la multiplicacion es %d\n", resultadosArray[2]);
		}
		else
		{
			printf("\nError, no se realizo la multiplicacion\n");
		}
		if(listaDeArray[3]==0)
		{
			printf("\nEl resultado de la division es %.2f\n", resultadoDiv);
		}
		else
		{
			printf("\nError, no se realizo la division\n");
		}
		retorno=0;
		}while(retorno==-1);

		return retorno;
	}



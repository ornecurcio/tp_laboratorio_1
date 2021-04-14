/*
 ============================================================================
 Name        : Labo1Tp1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "funcionesUTNyMenu.h"
#include "calculos.h"

#define RESULTADOS 6

	int main(void) {
		setbuf(stdout, NULL);
		int A;
		int B;
		int flighA=0;
		int flighB=0;
		int flighRetornos;
		int opcionPrincipal;
		int respuestaMenuPrincipal;
		int resultado[5];
		float resultadoDivision;
		int retornos[RESULTADOS];

		do{
			respuestaMenuPrincipal = utn_getNumero(&opcionPrincipal,"Seleccione una opcion\n1-Ingresar primer operando(A=x)\n2-Ingresar segundo operando(B=y)\n3-Calcular todas las operaciones\na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division (A/B)\nd) Calcular la multiplicacion (A*B)\ne) Calcular el factorial (A!)\n4-Informar resultado\n5-Salir\n","No es una opcion valida", 1, 5, 2);
			if(respuestaMenuPrincipal == 0)
			{
				switch(opcionPrincipal)
				{
				case 1:
					if(flighA==0 && flighB==0)
					{
						printf("Ingrese el primer operando A");
						scanf("%d", &A);
						flighA=1;
					}
					break;
				case 2:
					if(flighA==0)
					{
						printf("\nError, primero debe ingresar el operando A\n");
					}
					else
					{
						printf("Ingrese el primer operando B");
						scanf("%d", &B);
						flighB=1;
					}
					break;
				case 3:
					if(flighA==0 || flighB==0)
					{
						printf("\nError, falta que ingrese un operando\n");
					}
					else
					{
						retornos[0]=sumar(&resultado[0], A, B);
						retornos[1]=restar(&resultado[1], A, B);
						retornos[2]=multiplicar(&resultado[2], A, B);
						retornos[3]=dividir(&resultadoDivision, A, B);
						retornos[4]=factorial(&resultado[3], A);
						retornos[5]=factorial(&resultado[4], B);
					}
					break;
				case 4:
					if(flighA==0 || flighB==0 || retornos==0)
					{
						printf("Error, falta que ingrese un operando o que ejecute la opcion 3\n");
					}
					else
					{
						flighRetornos=imprimirArrayResultados(retornos, resultado, resultadoDivision);
						if(flighRetornos==0)
						{
							flighA=0;
							flighB=0;
						}
					}
					break;
				}
			}

		}while(opcionPrincipal!=5);

		return EXIT_SUCCESS;
	}


	/*a) “El resultado de A+B es: r”
	b) “El resultado de A-B es: r”
	c) “El resultado de A/B es: r” o “No es posible dividir por cero”
	d) “El resultado de A*B es: r”
	e) “El factorial de A es: r1 y El factorial de B es: r2”*/







/*
 ============================================================================
 Name        : Labo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "funcionesUTNyMenu.h"


int main(void) {
	setbuf(stdout, NULL);
	int A;
	int B;
	int flighA=0;
	int flighB=0;
	int opcionPrincipal;
	int respuestaMenuPrincipal;
	int resultado[3];
	float resultadoDivision;
	int retornos[4];

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
					printf("Error, primero debe ingresar el operando A");
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
					printf("Error, falta que ingrese un operando");
				}
				else
				{
					retornos[0]=sumar(&resultado[0], A, B);
					retornos[1]=restar(&resultado[1], A, B);
					retornos[2]=multiplicar(&resultado[2], A, B);
					retornos[3]=dividir(&resultadoDivision, A, B);
				}
				break;
			case 4:
				if(retornos[0]==0)
				{
					printf("\nEl resultado de la suma es %d\n", resultado[0]);
				}
				if(retornos[1]==0)
				{
					printf("\nEl resultado de la resta es %d\n", resultado[1]);
				}
				if(retornos[2]==0)
				{
					printf("\nEl resultado de la multiplicacion es %d\n", resultado[2]);
				}
				if(retornos[3]==0)
				{
					printf("\nEl resultado de la division es %.2f\n", resultadoDivision);
				}
				break;
			}

		}

	}while(opcionPrincipal!=5);

	return EXIT_SUCCESS;
}

/*a) �El resultado de A+B es: r�
b) �El resultado de A-B es: r�
c) �El resultado de A/B es: r� o �No es posible dividir por cero�
d) �El resultado de A*B es: r�
e) �El factorial de A es: r1 y El factorial de B es: r2�*/





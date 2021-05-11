/*
 ============================================================================
 Name        : Labo1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "Employee.h"

#define QTY_EMPLOYEE 5

int main(void) {
	setbuf(stdout, NULL);

	eEmployee vecEmpleados[QTY_EMPLOYEE];
	int contadorEmpleados=0;
	//int B;
	//int flighA=0;
	//int flighB=0;
	//int flighRetornos;
	int respuestaMenuPrincipal;

	do{
		if(utn_getNumero(&respuestaMenuPrincipal,"Seleccione una opcion\n1.Ingresar 1 Empleado\n2.Modificar\n3.Dar de baja\n4.Informes\n5.Salir",
				"Error ingrese: \n1.Ingresar un empleado\n2.Modificar\n3.Dar de baja\n4.Informes\n5.Salir", 1, 5, 2)==0)
		{
			initEmployees(vecEmpleados, QTY_EMPLOYEE);
			switch(respuestaMenuPrincipal)
			{
				case 1: //ALTA
					if(addEmployee(vecEmpleados, QTY_EMPLOYEE, &contadorEmpleados)==0)
					{
						printf("Carga exitosa\n");
					}
					break;
				case 2://MODIFICAR
					if(contadorEmpleados==0)
					{
						printf("Error, primero debe ingresar un empleado");
					}
					else
					{
						modify1Employee(vecEmpleados,findEmployeeById(vecEmpleados, QTY_EMPLOYEE));
					}
					break;
				case 3://BAJA
					if(contadorEmpleados==0)
					{
						printf("Error, primero debe ingresar un empleado");
					}
					else
					{

					}
					break;
				case 4:
					if(contadorEmpleados==0)
					{
						printf("Error, primero debe ingresar un empleado");
					}
					else
					{
						printEmployees(vecEmpleados, QTY_EMPLOYEE);
					}
					break;
			}
		}
	}while(respuestaMenuPrincipal!=5);

	return EXIT_SUCCESS;
}

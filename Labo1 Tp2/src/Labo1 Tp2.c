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
#include "Employee.h"
#include "UTN.h"

#define QTY_EMPLOYEE 1000

int main(void) {
	setbuf(stdout, NULL);

	eEmployee vecEmpleados[QTY_EMPLOYEE];
	int contadorEmpleados=0;
	int submenu;
	int auxInt;
	int respuestaMenuPrincipal;
	float auxFloat;
	int cantidad=0;

	inicializarEmpleado(vecEmpleados, QTY_EMPLOYEE);
	do{
		if(utn_getNumero(&respuestaMenuPrincipal,"Seleccione una opcion\n1.Ingresar 1 Empleado\n2.Modificar\n3.Dar de baja\n4.Informes\n5.Salir\n",
				"Error: \n", 1, 5, 2)==0)
		{
			switch(respuestaMenuPrincipal)
			{
				case 1: //ALTA
					if(altaEmployee(vecEmpleados, QTY_EMPLOYEE, &contadorEmpleados)==0)
					{
						printf("Carga exitosa\n");
					}
					break;
				case 2://MODIFICAR
					if(contadorEmpleados==0)
					{
						printf("Error, primero debe ingresar un empleado\n");
					}
					else
					{
						modifica1Employee(vecEmpleados,buscaEmployeeById(vecEmpleados, QTY_EMPLOYEE));
					}
					break;
				case 3://BAJA
					if(contadorEmpleados==0)
					{
						printf("Error, primero debe ingresar un empleado\n");
					}
					else
					{
						bajaEmployee(vecEmpleados, buscaEmployeeById(vecEmpleados, QTY_EMPLOYEE));
					}
					break;
				case 4:
					if(contadorEmpleados==0)
					{
						printf("Error, primero debe ingresar un empleado\n");
					}
					else
					{
						do{
							if(utn_getNumero(&submenu, "\n1.Informar empleados \n2.Listado de empleados con salario mayor al promedio\n3.Salir", "Error, Ingrese una opcion del 1 o 2.", 1, 3, 2)==0)
							{
									switch(submenu)
									{
										case 1:
											printf("Ingrese criterio ascendente 1 o descendente 0");
											scanf("%d", &auxInt);
											ordenarEmployees(vecEmpleados, QTY_EMPLOYEE,auxInt);
											imprimirEmployees(vecEmpleados, QTY_EMPLOYEE);
											break;
										case 2:
											eEmployeePromSalario(&auxFloat, vecEmpleados, QTY_EMPLOYEE);
											eEmployeesListaSalario(vecEmpleados, QTY_EMPLOYEE, auxFloat, &cantidad);
											printf("\nSuperan el promedio: %d", cantidad);
											break;
									 }
							  }
							}while(submenu!=3);
					}
					break;
			}
		}
	}while(respuestaMenuPrincipal!=5);

	return EXIT_SUCCESS;
}

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
#include <ctype.h>
#include "Biblioteca.h"
#include "Employee.h"

#define QTY_EMPLOYEE 5

int main(void) {
	setbuf(stdout, NULL);

	eEmployee vecEmpleados[QTY_EMPLOYEE];
	int contadorEmpleados=0;
	int submenu;
	//int B;
	//int flighA=0;
	//int flighB=0;
	//int flighRetornos;
	int auxInt;
	int respuestaMenuPrincipal;

	initEmployees(vecEmpleados, QTY_EMPLOYEE);
	do{
		if(utn_getNumero(&respuestaMenuPrincipal,"Seleccione una opcion\n1.Ingresar 1 Empleado\n2.Modificar\n3.Dar de baja\n4.Informes\n5.Salir",
				"Error ingrese: \n1.Ingresar un empleado\n2.Modificar\n3.Dar de baja\n4.Informes\n5.Salir", 1, 5, 2)==0)
		{

			switch(respuestaMenuPrincipal)
			{
				case 1: //ALTA
					if(addEmployee(vecEmpleados, QTY_EMPLOYEE, &contadorEmpleados)==0)
					{
						printf("Carga exitosa\n");
					}
					printEmployees(vecEmpleados, QTY_EMPLOYEE);
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
						removeEmployee(vecEmpleados, findEmployeeById(vecEmpleados, QTY_EMPLOYEE));
					}
					break;
				case 4:
					if(contadorEmpleados==0)
					{
						printf("Error, primero debe ingresar un empleado");
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
										while(auxInt!=1 || auxInt!=0 || isdigit(auxInt)==0)
										{
											printf("Ingrese criterio ascendente 1 o descendente 0");
											scanf("%d", &auxInt);
										}
										eEmployeesSort(vecEmpleados, QTY_EMPLOYEE,auxInt);
										printEmployees(vecEmpleados, QTY_EMPLOYEE);
										break;
									case 2:

										break;
								}
								retorno=0;
							}
						}while(submenu!=3);
					}
					break;
			}
		}
	}while(respuestaMenuPrincipal!=5);

	return EXIT_SUCCESS;
}

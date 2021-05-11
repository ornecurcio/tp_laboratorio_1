/*
 * Employee.h

 *      Author: Ornela Curcio
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#define ADMISION 1
#define SEGURIDAD 2
#define ADMINISTRACION 3

typedef struct
{
	int idEmployee;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}eEmployee;

int initEmployees(eEmployee pArray[], int cantidadDeArray);

int findLibre(eEmployee pArray[], int cantidadDeArray);

int addEmployee(eEmployee aEmployee[], int cantidadDeArray, int* contadorId);

void print1Employee(eEmployee aEmpleado);

int findEmployeeById(eEmployee aAuxiliar[], int cantidadDeArray);

int removeEmployee(eEmployee aAuxiliar[], int posicion);

int eEmployeesSort(eEmployee array[], int cantidadDeArray, int criterio);

int printEmployees(eEmployee array[], int cantidadDeArray);

int modify1Employee(eEmployee aAuxiliar[], int posicion);

int eEmployeePromSalary(float* pPromedioResultado, eEmployee array[], int cantidadDeArray);

int eEmployeesListSalary(eEmployee array[], int cantidadDeArray, float salary);

#endif /* EMPLOYEE_H_ */

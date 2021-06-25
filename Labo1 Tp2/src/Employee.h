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

/** \brief  inicializa en el campo isEmpty en 1, libre
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Returo (-1) si Error (0) si todo Ok
*/
int inicializarEmpleado(eEmployee pArray[], int cantidadDeArray);
/** \brief  busca en el campo isEmpty del array, un 1 para ingresar datos
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Retorno (-1) si Error, retorna un int de posicion si todo Ok
*/
int buscaLibre(eEmployee pArray[], int cantidadDeArray);
/** \brief alta un empleado, llama a otras funciones que valida los datos de cada campo a cargar
* \param aEmployee array donde se cargan los datos
* \param cantidadDeArray int, recorrer array
* \param contadorId int como puntero, donde se cargara el ID de manera autoincremental
* \return int Retorno (-1) si ERROR (0) SI TODO Ok
*/
int altaEmployee(eEmployee aEmployee[], int cantidadDeArray, int* contadorId);
/** \brief imprime un empleado
* \param aEmpleado, recibe por valor la estructura de un empleado
*/
void imprimir1Employee(eEmployee aEmpleado);

int buscaEmployeeById(eEmployee aAuxiliar[], int cantidadDeArray);

int bajaEmployee(eEmployee aAuxiliar[], int posicion);

int ordenarEmployees(eEmployee array[], int cantidadDeArray, int criterio);

int imprimirEmployees(eEmployee array[], int cantidadDeArray);

int modifica1Employee(eEmployee aAuxiliar[], int posicion);

int eEmployeePromSalario(float* pPromedioResultado, eEmployee array[], int cantidadDeArray);

int eEmployeesListaSalario(eEmployee array[], int cantidadDeArray, float salary, int* cantidad);

#endif /* EMPLOYEE_H_ */

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
/** \brief busca un empleado por ID
* \param aAuxiliar, array de empleados
* \param cantidadDeArray, cantidad de array a recorrer
*/
int buscaEmployeeById(eEmployee aAuxiliar[], int cantidadDeArray);
/** \brief da de baja un empleado
* \param aAuxiliar, array de empleados
* \param posicion, a bar de baja
*/
int bajaEmployee(eEmployee aAuxiliar[], int posicion);
/** \brief ordena los empleados
* \param aAuxiliar, array de empleados
* \param cantidadDeArray, cantidad de array a recorrer
* \param criterio de ordenamiento
*/
int ordenarEmployees(eEmployee array[], int cantidadDeArray, int criterio);
/** \brief imprime listado de empleados
* \param cantidadDeArray, cantidad de array a recorrer
*/
int imprimirEmployees(eEmployee array[], int cantidadDeArray);
/** \brief modifica un empleado
* \param posicion, a modificar
*/
int modifica1Employee(eEmployee aAuxiliar[], int posicion);
/** \brief calcula el total de todos los salarios y el salario promedio
* \param array
* \param cantidadDeArray
* \param puntero pPromedioResultado donde se guarda el salario promedio
*/
int eEmployeePromSalario(float* pPromedioResultado, eEmployee array[], int cantidadDeArray);
/** \brief lista y cuanta la cantida de salarios mayores al promedio
* \param array
* \param cantidadDeArray
* \param salary
* \param puntero cantidad donde se guarda la cantidad de empleados con salio superior al promedio
*/
int eEmployeesListaSalario(eEmployee array[], int cantidadDeArray, float salary, int* cantidad);

#endif /* EMPLOYEE_H_ */

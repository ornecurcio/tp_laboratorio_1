#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		FILE *pFile=fopen(path,"r");
		if(parser_EmployeeFromText(pFile,pArrayListEmployee)!=0)
		{
			printf("No se pudo leer el archivo\n");
		}
		else
		{
			printf("Archivo bien leido. Cerrado correctamente\n");
			retorno=0;
			fclose(pFile);
		}
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		FILE *pFile=fopen(path,"rb");
		if(parser_EmployeeFromBinary(pFile,pArrayListEmployee)!=0)
		{
			printf("No se pudo leer el archivo\n");
		}
		else
		{
			printf("Archivo bien leido. Cerrado correctamente\n");
			retorno=0;
			fclose(pFile);
		}
	}
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* pAuxEmpleado=NULL;
	int cantidadLinkedList;
	if(ll_isEmpty(pArrayListEmployee)==0)
	{
		cantidadLinkedList=ll_len(pArrayListEmployee);
	}
	if(pArrayListEmployee != NULL)
	{
		for(int i=0; i<cantidadLinkedList ; i++)
		{
			pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
			printf("Id: %d - Nombre: %s - Horas Trabajadas: %d - Sueldo: %d\n",(*(pAuxEmpleado)).id, (*(pAuxEmpleado)).nombre,
					(*(pAuxEmpleado)).horasTrabajadas, (*(pAuxEmpleado)).sueldo);
		}
		retorno = 0;
	}

	return retorno;

}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}


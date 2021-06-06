#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "UTN.h"

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
	int retorno=-1;
	Employee* pAuxEmpleado=NULL;
	int cantidadLinkedList;
	int id;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;
	int numMax=0;
	if(pArrayListEmployee!=NULL)
	{
		if(ll_isEmpty(pArrayListEmployee)==0)
		{
			cantidadLinkedList=ll_len(pArrayListEmployee);
			for(int i=0; i<cantidadLinkedList ; i++)
			{
				pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(pAuxEmpleado, &id);
				if(id>numMax)
				{
					numMax=id;
				}
			}
		}
		else
		{
			printf("Desea crear una nueva lista inicializando el ID en 1\n");
			if(utn_getCaracterSN()==0)
			{
				id=0;
			}
			else
			{
				utn_getNumero(&id, "En que numero quiere inicializar el ID?", "Error, ingrese valor numerico", 1, 100000000, 2);
			}
		}
		pAuxEmpleado=employee_new();
		if(pAuxEmpleado!=NULL)
		{
			if(utn_getNombre(auxNombre, "Ingrese nombre del empleado", "Error, muy largo", 2, 128)==0 &&
			   utn_getNumero(&auxHoras, "Ingrese horas trabajadas", "Error, maximo 100000", 0, 100000, 2)==0 &&
			   utn_getNumero(&auxSueldo, "Ingrese sueldo", "Error, maximo 999999", 0, 999999, 2)==0)
			{
					if(employee_setId(pAuxEmpleado, (id+1))==0 &&
					   employee_setNombre(pAuxEmpleado, auxNombre)==0 &&
					   employee_setHorasTrabajadas(pAuxEmpleado, auxHoras)==0 &&
					   employee_setSueldo(pAuxEmpleado, auxSueldo)==0)
					{
						ll_add(pArrayListEmployee, pAuxEmpleado);
						printf("Carga exitosa\n");
						retorno=0;
					}
					else
					{
						printf("Error al cargar empleado\n");
					}
			}
		}

	}
    return retorno;
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


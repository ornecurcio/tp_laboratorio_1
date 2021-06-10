#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
		int retorno = -1;
		int retornoLeido;
		char buffer[4][128];
		Employee* pAuxEmpleado=NULL;

		if(pFile!=NULL && pArrayListEmployee!=NULL)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
			do
			{
				retornoLeido = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
				if(retornoLeido<4)
				{
					employee_delete(pAuxEmpleado);
					retorno=-1;
					break;
				}
				else
				{
					pAuxEmpleado = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
					if(pAuxEmpleado!=NULL)
					{
						ll_add(pArrayListEmployee,pAuxEmpleado);
						retorno=0;
					}
				}
			}while(!feof(pFile));
		}

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int retornoLeido;
	Employee* pAuxEmpleado=NULL;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		do
		{
			pAuxEmpleado=employee_new();
			if(pAuxEmpleado!=NULL)
			{
				retornoLeido = fread(pAuxEmpleado,sizeof(Employee),1,pFile);
				if(retornoLeido!=1)
				{
					employee_delete(pAuxEmpleado);
					break;
				}
				else
				{
					ll_add(pArrayListEmployee,pAuxEmpleado);
					retorno=0;
				}
			}
		}while(!feof(pFile));
	}
	return retorno;
}

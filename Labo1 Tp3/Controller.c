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
		retorno=0;
		if(ll_isEmpty(pArrayListEmployee)==1)
		{
			FILE *pFile=fopen(path,"r");
			if(parser_EmployeeFromText(pFile,pArrayListEmployee)!=0)
			{
				printf("No se pudo leer el archivo\n");
			}
			else
			{
				printf("Archivo bien leido. Cerrado correctamente\n");
			}
			fclose(pFile);
		}
		else
		{
			printf("\t###########################################################################################################\n");
			printf("\t#\t Atencion! Se detectaron datos en su LinkedList                                                   #\n");
			printf("\t#\t Si procede con la apertura del archivo se borraran los datos actuales cargados en memoria        #\n");
			printf("\t#\t Desea continuar y borrar los archivos guardados en memoria presione SI                           #\n");
			printf("\t#\t Desea continuar usando la LinkedList actual presione NO                                          #\n");
			printf("\t###########################################################################################################\n");
			if(utn_getCaracterSN()==0 && ll_clear(pArrayListEmployee)==0)
			{
				FILE *pFile=fopen(path,"r");
				if(parser_EmployeeFromText(pFile,pArrayListEmployee)!=0)
				{
					printf("No se pudo leer el archivo\n");
				}
				else
				{
					printf("Archivo bien leido. Cerrado correctamente\n");
				}
				fclose(pFile);
			}
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
		retorno=0;
		if(ll_isEmpty(pArrayListEmployee)==1)
		{
			FILE *pFile=fopen(path,"rb");
			if(pFile!=NULL)
			{
				if(parser_EmployeeFromBinary(pFile,pArrayListEmployee)!=0)
				{
					printf("No se pudo leer el archivo\n");
				}
				else
				{
					printf("Archivo bien leido. Cerrado correctamente\n");
				}
			}
			fclose(pFile);
		}
		else
		{
			printf("\t###########################################################################################################\n");
			printf("\t#\t Atencion! Se detectaron datos en su LinkedList                                                   #\n");
			printf("\t#\t Si procede con la apertura del archivo se borraran los datos actuales cargados en memoria        #\n");
			printf("\t#\t Desea continuar y borrar los archivos guardados en memoria presione SI                           #\n");
			printf("\t#\t Desea continuar usando la LinkedList actual presione NO                                          #\n");
			printf("\t###########################################################################################################\n");
			if(utn_getCaracterSN()==0 && ll_clear(pArrayListEmployee)==0)
			{
				FILE *pFile=fopen(path,"rb");
				if(pFile!=NULL)
				{
					if(parser_EmployeeFromBinary(pFile,pArrayListEmployee)!=0)
					{
						printf("No se pudo leer el archivo\n");
					}
					else
					{
						printf("Archivo bien leido. Cerrado correctamente\n");
					}
				}
				fclose(pFile);
			}
		}
	}
	return retorno;
}

/** \brief Busca Id Maximo
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_getMaxId(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int cantidadLinkedList;
	int id;

	Employee* pAuxEmpleado=NULL;
	if(pArrayListEmployee!=NULL && ll_isEmpty(pArrayListEmployee)==0)
	{
		cantidadLinkedList=ll_len(pArrayListEmployee);
		for(int i=0; i<cantidadLinkedList ; i++)
		{
			pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(pAuxEmpleado, &id);
			if(id>retorno)
			{
				retorno=id;
			}
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
	int auxId;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;
	int respuesta;
	if(pArrayListEmployee!=NULL)
	{
		if(ll_isEmpty(pArrayListEmployee)==1)
		{
			printf("\t########################################################################################\n");
			printf("\t#\t Atencion! Esta por cargar datos en una nueva LinkedList                       #\n");
			printf("\t#\t Recuerde que luego debe guardar estos datos en un archivo                     #\n");
			printf("\t#\t Desea continuar e inicializar un Id o generar un Id propio presione SI        #\n");
			printf("\t#\t Desea salir y abrir volver al menu para abrir un archivo presione NO          #\n");
			printf("\t########################################################################################\n");
			if(utn_getCaracterSN()==0)
			{
				utn_getNumero(&respuesta, "Desea\n1. Crear una nueva lista inicializando el ID en 1\n2. Inicializar el ID en otro numero\n",
						                   "Error, opcion no valida", 1, 2, 1);
					switch(respuesta)
					{
						case 1:
							auxId=1;
							break;
						case 2:
							utn_getNumero(&auxId, "En que numero quiere inicializar el ID?\n", "Error, ingrese valor numerico\n", 1, 100000000, 2);
							break;
					}
					pAuxEmpleado=employee_new();
					if(pAuxEmpleado!=NULL)
					{
						if(utn_getApellido(auxNombre, "Ingrese nombre del empleado", "Error ingrese nombre valido\n", 2, 128)==0 &&
						   utn_getNumero(&auxHoras, "Ingrese horas trabajadas", "Error ingrese numero valido, maximo 745\n", 0, 745, 2)==0 &&
						   utn_getNumero(&auxSueldo, "Ingrese sueldo", "Error ingrese numero valido, maximo 999999\n", 0, 999999, 2)==0)
						{
							if(employee_setId(pAuxEmpleado, auxId)==0 &&
							   employee_setNombre(pAuxEmpleado, auxNombre)==0 &&
							   employee_setHorasTrabajadas(pAuxEmpleado, auxHoras)==0 &&
							   employee_setSueldo(pAuxEmpleado, auxSueldo)==0)
							{
								ll_add(pArrayListEmployee, pAuxEmpleado);
								employee_print(pAuxEmpleado);
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
		}
		else
		{
			auxId=controller_getMaxId(pArrayListEmployee);
			pAuxEmpleado=employee_new();
			if(pAuxEmpleado!=NULL)
			{
				if(utn_getNombre(auxNombre, "Ingrese nombre del empleado", "Error, ingrese nombre valido\n", 2, 128)==0 &&
				   utn_getNumero(&auxHoras, "Ingrese horas trabajadas", "Error ingrese numero valido, maximo 745\n", 0, 745, 2)==0 &&
				   utn_getNumero(&auxSueldo, "Ingrese sueldo", "Error numero valido, maximo 999999", 0, 999999, 2)==0)
				{
						if(employee_setId(pAuxEmpleado, (auxId+1))==0 &&
						   employee_setNombre(pAuxEmpleado, auxNombre)==0 &&
						   employee_setHorasTrabajadas(pAuxEmpleado, auxHoras)==0 &&
						   employee_setSueldo(pAuxEmpleado, auxSueldo)==0)
						{
							ll_add(pArrayListEmployee, pAuxEmpleado);
							employee_print(pAuxEmpleado);
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
	int retorno=-1;
	Employee* pAuxEmpleado=NULL;
	int cantidadLinkedList;
	int auxId, auxHoras, auxSueldo, id, auxInt;
	int numMax=0;
	char auxNombre[128];

	if(pArrayListEmployee!=NULL && ll_isEmpty(pArrayListEmployee)==0)
	{
		cantidadLinkedList=ll_len(pArrayListEmployee);
		for(int i=0; i<cantidadLinkedList ; i++)
		{
			pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(pAuxEmpleado, &auxId);
			if(auxId>numMax)
			{
				numMax=auxId;
			}
		}
		utn_getNumero(&id, "Ingrese Id de persona a modificar\n", "Error, ingrese valor numerico\n", 0, auxId, 2);
		for(int i=0; i<cantidadLinkedList ; i++)
		{
			pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(pAuxEmpleado, &auxId);
			if(auxId==id)
			{
				printf("Desea modificar este empleado?\n");
				employee_print(pAuxEmpleado);
				if(utn_getCaracterSN()==0)
				{
					utn_getNumero(&auxInt, "------Modificar-------\n1. Nombre \n2. Horas trabajadas \n3. Sueldo", "Error, opcion incorrecta\n", 1, 3, 2);
					switch(auxInt)
					{
						case 1:
							if((utn_getApellido(auxNombre, "Ingrese nombre del empleado", "Error, ingrese Nombre valido\n", 2, 128)==0) &&
							  (employee_setNombre(pAuxEmpleado, auxNombre)==0))
							{
								printf("Datos modificados correctamente\n");
								employee_print(pAuxEmpleado);
							}
							break;
						case 2:
							if((utn_getNumero(&auxHoras, "Ingrese horas trabajadas", "Error ingrese numero valido, maximo 745\n", 0, 100000, 2)==0) &&
							   (employee_setHorasTrabajadas(pAuxEmpleado, auxHoras)==0))
							{
								printf("Datos modificados correctamente\n");
								employee_print(pAuxEmpleado);
							}
							break;
						case 3:
							if((utn_getNumero(&auxSueldo, "Ingrese sueldo", "Error, maximo 999999\n", 0, 999999, 2)==0) &&
							   (employee_setSueldo(pAuxEmpleado, auxSueldo)==0))
							{
								printf("Datos modificados correctamente\n");
								employee_print(pAuxEmpleado);
							}
							break;
					}//FIN SWITCH
					retorno=0;
				}
			}
		 }//FIN FOR
		}
	return retorno;
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
	int retorno=-1;
	Employee* pAuxEmpleado=NULL;
	int cantidadLinkedList;
	int auxId, id, i;
	int numMax;

	if(pArrayListEmployee!=NULL && ll_isEmpty(pArrayListEmployee)==0)
	{
		numMax=controller_getMaxId(pArrayListEmployee);
		cantidadLinkedList=ll_len(pArrayListEmployee);
		utn_getNumero(&id, "Ingrese Id de persona a borrar", "Error, ingrese valor numerico\n", 0, numMax, 2);
		for(i=0; i<cantidadLinkedList ; i++)
		{
			pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(pAuxEmpleado, &auxId);
			if(auxId==id)
			{
				printf("Desea borrar este empleado?\n");
				employee_print(pAuxEmpleado);
				if(utn_getCaracterSN()==0)
				{
					if(ll_remove(pArrayListEmployee, i)==0)
					{
						printf("Operacion exitosa\n");
						retorno=0;
						break;
					}
				}
			}
		}
		if(retorno==-1)
		{
			printf("Empleado no encontrado\n");
		}
	}
    return retorno;
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
	int auxId, auxHoras, auxSueldo;
	char auxNombre[128];
	Employee* pAuxEmpleado=NULL;
	int cantidadLinkedList;
	if(pArrayListEmployee != NULL)
	{
		if(ll_isEmpty(pArrayListEmployee)==0)
		{
			cantidadLinkedList=ll_len(pArrayListEmployee);
			printf("------------------------------------------------------------------------------\n");
			printf("ID		NOMBRE		  HORAS TRABAJADAS	        SUELDO\n");
			printf("------------------------------------------------------------------------------\n");
			for(int i=0; i<cantidadLinkedList ; i++)
			{
				pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
				if(employee_getId(pAuxEmpleado, &auxId)!=0 ||
				   employee_getNombre(pAuxEmpleado, auxNombre)!=0 ||
				   employee_getHorasTrabajadas(pAuxEmpleado, &auxHoras)!=0 ||
				   employee_getSueldo(pAuxEmpleado, &auxSueldo)!=0)
				{
					retorno=-1;
					printf("Error, al imprimir lista");
					break;
				}
				else
				{
					printf("%-5d		%-15s		%4d			%-10d\n",auxId, auxNombre, auxHoras, auxSueldo);
				}
			}
			retorno = 0;
		}
		else
		{
			printf("No hay lista para imprimir\n");
		}
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
	int retorno=-1;
	int option;
	int(*pOrden)(void*,void*);

	if(pArrayListEmployee!=NULL)
	{
		utn_getNumero(&option, "-----ORDENAMIENTO POR-----\n1. Nombre \n2. Horas Trabajadas \n3. Sueldo\n4. ID", "Error, opcion incorrecta\n", 1, 4, 2);
		switch(option)
		{
			case 1:
				pOrden=employee_sortNombre;
				break;
			case 2:
				pOrden=employee_sortHoras;
				break;
			case 3:
				pOrden=employee_sortSueldo;
				break;
			case 4:
				pOrden=employee_sortId;
				break;
		}
		utn_getNumero(&option, "-----CRITERIO-----\n1. Ascendente(A-Z)\n0. Descendente(Z-A)\n", "Error, opcion incorrecta\n", 0, 1, 2);
		ll_sort(pArrayListEmployee, pOrden, option);
	}
    return retorno;
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
	int retorno = -1;
	int auxCantLink, auxId, auxHoras, auxSueldo;
	char auxNombre[128];
	FILE* pFile;
	Employee* pAuxEmpleado=NULL;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		if((pFile=fopen(path,"w"))==NULL)
		{
			printf("No se pudo escribir el archivo\n");
		}
		else
		{
			auxCantLink=ll_len(pArrayListEmployee);
			fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
			for(int i=0; i<auxCantLink; i++)
			{
				pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
				if(employee_getId(pAuxEmpleado, &auxId)==0 &&
				   employee_getNombre(pAuxEmpleado, auxNombre)==0 &&
				   employee_getHorasTrabajadas(pAuxEmpleado, &auxHoras)==0 &&
				   employee_getSueldo(pAuxEmpleado, &auxSueldo)==0)
				{
				   fprintf(pFile,"%d,%s,%d,%d\n",auxId, auxNombre, auxHoras, auxSueldo);
				   retorno=0;
				}
			}
			printf("Archivo bien escrito. Guardado correctamente\n");
		}
		fclose(pFile);
	}
	return retorno;
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
	int retorno = -1;
	int auxCantLink, retornoLeido;
	FILE* pFile=NULL;
	Employee* pAuxEmpleado=NULL;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		if((pFile=fopen(path,"wb"))==NULL)
		{
			printf("No se pudo escribir el archivo\n");
		}
		else
		{
			auxCantLink=ll_len(pArrayListEmployee);
			for(int i=0; i<auxCantLink; i++)
			{
				pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
				retornoLeido=fwrite(pAuxEmpleado, sizeof(Employee),1,pFile);
				if(retornoLeido!=1)
				{
					employee_delete(pAuxEmpleado);
					break;
					retorno=-1;
				}
				else
				{
					retorno=0;
				}
			}
			if(retorno==0)
			{
				printf("Archivo bien escrito. Guardado correctamente\n");
			}
		}
		fclose(pFile);
	}
    return retorno;
}
/** \brief Borra la LinkedList
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_deleteLinkedList(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	if(pArrayListEmployee!=NULL)
	{
		if(ll_deleteLinkedList(pArrayListEmployee)==0)
		{
			printf("-----------------------------------------------");
			printf("/ PROGRAMA FINALIZADO, HASTA PRONTO /");
			printf("-----------------------------------------------");
			retorno=0;
		}
	}
	return retorno;

}

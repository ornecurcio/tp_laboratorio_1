#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "UTN.h"

void employee_delete(Employee* this)
{
	free(this);
}
Employee* employee_new()
{
	return (Employee*)malloc(sizeof(Employee));
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* pAuxEmpleado = employee_new();
	if(pAuxEmpleado!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{
		if((employee_setId(pAuxEmpleado,atoi(idStr))!=0) ||
		(employee_setNombre(pAuxEmpleado,nombreStr)!=0) ||
		(employee_setHorasTrabajadas(pAuxEmpleado,atoi(horasTrabajadasStr))!=0) ||
		(employee_setSueldo(pAuxEmpleado,atoi(sueldoStr))!=0))
		{
			free(pAuxEmpleado);
			pAuxEmpleado=NULL;
		}
	}
	return pAuxEmpleado;
}
int employee_setId(Employee* this,int id)
{
	int retorno=-1;
	if(this!=NULL && id>0)
	{
		this->id=id;
		retorno=0;
	}
	return retorno;
}
int employee_getId(Employee* this,int* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		retorno=0;
	}
	return retorno;
}
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		retorno=0;
 	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=0;
	}
	return retorno;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno=-1;
	if(this!=NULL)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno=0;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno=-1;
	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=0;
	}
	return retorno;
}
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno=-1;
	if(this!=NULL)
	{
		this->sueldo=sueldo;
		retorno=0;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno=-1;
	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		retorno=0;
	}
	return retorno;
}

void employee_print(Employee* this)
{
	int auxId, auxHoras, auxSueldo;
	char auxNombre[128];
	if(employee_getId(this, &auxId)==0 && employee_getNombre(this, auxNombre)==0 &&
	   employee_getHorasTrabajadas(this, &auxHoras)==0 && employee_getSueldo(this, &auxSueldo)==0)
	{
		printf("Id: %d - Nombre: %s - Horas Trabajadas: %d - Sueldo: %d\n",auxId, auxNombre,auxHoras,auxSueldo);
	}
	//printf("Id: %d - Nombre: %s - Horas Trabajadas: %d - Sueldo: %d\n",(*(this)).id, (*(this)).nombre,(*(this)).horasTrabajadas, (*(this)).sueldo);
}
int employee_sortId(void* thisOne, void* thisTwo)
{
	int retorno=0;
	int auxId1, auxId2;

	if(thisOne!=NULL && thisTwo!=NULL)
	{
		if(employee_getId((Employee*)thisOne, &auxId1)==0 && employee_getId((Employee*)thisTwo, &auxId2)==0)
		{
			if(auxId1 > auxId2)
			{
				retorno=1;
			}
			if( auxId1 < auxId2 )
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}
int employee_sortSueldo(void* thisOne, void* thisTwo)
{
	int retorno=0;
	int auxSueldo1, auxSueldo2;

	if(thisOne!=NULL && thisTwo!=NULL)
	{
		if(employee_getSueldo((Employee*)thisOne, &auxSueldo1)==0 && employee_getSueldo((Employee*)thisTwo, &auxSueldo2)==0)
		{
			if(auxSueldo1 > auxSueldo2)
			{
				retorno=1;
			}
			if(auxSueldo1 < auxSueldo2)
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}
int employee_sortHoras(void* thisOne, void* thisTwo)
{
	int retorno=0;

	int auxHoras1, auxHoras2;
	if(thisOne!=NULL && thisTwo!=NULL)
	{
		if(employee_getHorasTrabajadas((Employee*)thisOne, &auxHoras1)==0 && employee_getHorasTrabajadas((Employee*)thisTwo, &auxHoras2)==0)
		{	if(auxHoras1 > auxHoras2)
			{
				retorno=1;
			}
			if(auxHoras1 < auxHoras2)
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}
int employee_sortNombre(void* thisOne, void* thisTwo)
{
	int retorno=0;
	char auxNombre1[128],auxNombre2[128];
	if(thisOne!=NULL && thisTwo!=NULL)
	{
		if(employee_getNombre((Employee*)thisOne, auxNombre1)==0 && employee_getNombre((Employee*)thisTwo, auxNombre2)==0)
		{
			if(strcmp(auxNombre1,auxNombre2)>0)
			{
				retorno=1;
			}
			if(strcmp(auxNombre1,auxNombre2)<0)
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}


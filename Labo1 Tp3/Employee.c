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


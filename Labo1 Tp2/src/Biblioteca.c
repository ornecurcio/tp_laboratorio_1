/*
 * Biblioteca.c
 *
 *  Created on: 10 may. 2021
 *      Author: orne_
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void getChar(char* mensaje, char* rta)
{
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", rta);
}

void inicializarArrayChar(char pArray[], int cantidadDeArray)
{
	int i;

	for(i=0; i<cantidadDeArray; i++)
	{
		pArray[i]=' ';
	}
}
void inicializarArrayNumFlo(float pArray[], int cantidadDeArray)
{
	int i;

	for(i=0; i<cantidadDeArray; i++)
	{
		pArray[i]=0;
	}
}
void getString(char mensaje[], char imput[])
{
	printf("%s", mensaje);
	gets(imput);
}
void inicializarArrayCadena(char pArray[][20], int cantidadDeArray)
{
	int i;

	for(i=0; i<cantidadDeArray; i++)
	{
		strcpy(pArray[i],"");
	}
}
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInterno;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			scanf("%d", &bufferInterno);
			if(bufferInterno>=minimo && bufferInterno<=maximo && isdigit(bufferInterno)==0)
			{
				*pResultado=bufferInterno;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getCaracterSexo(char* pResultado,char* mensaje,char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if(bufferChar=='f'|| bufferChar=='m' || bufferChar=='o')
			{
				*pResultado=bufferChar;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[60];

	if(aux != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%s", bufferString);

			if(strlen(bufferString)<20)
			{
				strcpy(aux, bufferString);
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int printDatos(char pArray[][20], int limite, char sex[], int leg[], int not1[], int not2[], float prom[])
{
	int retorno = -1;
	int i;

	if(pArray != NULL && sex != NULL && leg != NULL && not1 != NULL && not2 != NULL && prom != NULL  && limite>0)
	{
		for(i=0; i<limite; i++)
		{
			printf("%s %c %d %d %d %.2f ", pArray[i], sex[i], leg[i], not1[i], not2[i], prom[i]);
			printf("\n");
		}
		retorno = 0;
	}
	return retorno;
}
int utn_SwapAscendiente(int listaDeArray[],int cantidadDeArray)
{
	int i;
	int j;
	int aux;
	int retorno = -1;
	for(i=0; i<cantidadDeArray-1; i++)
	{
		for(j=i+1; j<cantidadDeArray; j++)
		{
			if(listaDeArray[i]>listaDeArray[j])
			{
				aux=listaDeArray[i];
				listaDeArray[i]=listaDeArray[j];
				listaDeArray[j]=aux;
			}

		}
		retorno=0;
	}
	return retorno;
}
int ordenar1ArrayStr(char pArrayApellido[][20], int limite, int nota1[], int nota2[], int legajo[], float promedio[], char sexo[])
{
	int flagDesordenado = -1;
	int i;
	char auxiliarApellidoStr[20];
	char auxChar;
	int auxInt;
	float auxFloat;



	while(flagDesordenado==-1)
	{
		flagDesordenado=0;
		for(i=0; i<limite-1; i++)
		{
			if(strcmp(pArrayApellido[i],pArrayApellido[i+1])>0)// compara los array.
			{
				strcpy(auxiliarApellidoStr,pArrayApellido[i]);
				strcpy(pArrayApellido[i],pArrayApellido[i+1]);
				strcpy(pArrayApellido[i+1],auxiliarApellidoStr);

				auxInt=nota1[i];
				nota1[i]=nota1[i+1];
				nota1[i+1]=auxInt;

				auxInt=nota2[i];
				nota2[i]=nota2[i+1];
				nota2[i+1]=auxInt;

				auxInt=legajo[i];
				legajo[i]=legajo[i+1];
				legajo[i+1]=auxInt;

				auxFloat=promedio[i];
				promedio[i]=promedio[i+1];
				promedio[i+1]=auxFloat;

				auxChar=sexo[i];
				sexo[i]=sexo[i+1];
				sexo[i+1]=auxChar;

				flagDesordenado = -1;
			}
		}
	}
	return 0;
}

int promediar2Notas(float* pPromedioResultado, int num1, int num2)
{
	int retorno = -1;

	if(pPromedioResultado != NULL)
	{
		*pPromedioResultado = ((float)num1+num2)/2;
		retorno=0;
	}
	return retorno;
}
/*int cargar1Alumno(Alumno aAlumno[], int cantidadDeArray, int* contadorId)
{
	Alumno aAuxiliar;
	int retorno = -1;
	int posicion;
	if(aAlumno!=NULL && cantidadDeArray>0 && contadorId!=NULL)
	{
		posicion=buscarLibre(aAlumno, cantidadDeArray);
		if(posicion==-1)
		{
			printf("\nNo hay lugares libres");
		}
		else
		{
			if((utn_getString(aAuxiliar.apellido, "Ingrese Apellido", "Error, ingrese Apellido", 2)==0)&&
			(utn_getNumero(&aAuxiliar.idCarrera, "Ingrese Carrera: 1.TYO, 2.ENDO, 3.NEURO","Error, ingrese Carrera: 1.TYO, 2.ENDO, 3.NEURO", 1, 3, 2)==0)&&
			(utn_getCaracterSexo(&aAuxiliar.sexo, "Ingrese Sexo: f, m, o", "Error, ingrese f, m, o", 2)==0) &&
			(utn_getNumero(&aAuxiliar.edad, "Ingrese edad", "Error, ingrese edad entre 18 y 70", 18, 70, 2)==0)&&
			(utn_getNumero(&aAuxiliar.nota1, "Ingrese nota 1", "Error, ingrese nota entre 1 y 10", 1, 10, 2)==0)&&
			(utn_getNumero(&aAuxiliar.nota2, "Ingrese nota 2", "Error, ingrese nota entre 1 y 10", 1, 10, 2)==0)&&
			(promediar2Notas(&aAuxiliar.promedio,aAuxiliar.nota1 ,aAuxiliar.nota2)==0))
			{
				aAuxiliar.legajo=*contadorId;
				aAuxiliar.isEmpty=0;
				aAlumno[posicion]=aAuxiliar;
				(*contadorId)++;
				retorno=0;
			}
		}
	}
		return retorno;
}
void mostrarAlumno(Alumno unAlumno, char* desCarrera)
{
	printf("\n %-5d   %-5d  %-10s %-15d %-10s %-5d %-5d %-5.2f", unAlumno.legajo, unAlumno.edad, unAlumno.apellido, unAlumno.idCarrera, desCarrera, unAlumno.nota1, unAlumno.nota2, unAlumno.promedio);
}
int mostrarAlumnos(Alumno aAuxiliar[], int cantidadDeArray, eCarrera aCarrera[], int cantidadCarrera)
{
	int retorno = -1;
	int i;
	char desCarrera[20];

	if(aAuxiliar!=NULL && cantidadDeArray>0 && cantidadCarrera>0 && aCarrera !=NULL)
	{
		printf("\nId      Edad       Apellido       IdCarrera       Carrera     Nota1   Nota2   Promedio");

		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAuxiliar[i].isEmpty==1)
			{
				continue;
			}
			else
			{
				getDescripcionCarrera(aCarrera, cantidadCarrera, aAuxiliar[i].idCarrera, desCarrera);
				mostrarAlumno(aAuxiliar[i], desCarrera);
				//printf("\nLegajo: %d, Sexo: %c, Edad: %d,",aAuxiliar[i].legajo, aAuxiliar[i].sexo, aAuxiliar[i].edad);
				//printf("Nota 1: %d, Nota 2: %d, Promedio: %.2f, Apellido: %s",aAuxiliar[i].nota1, aAuxiliar[i].nota2, aAuxiliar[i].promedio, aAuxiliar[i].apellido);
				retorno = 0;
			}
		}
	}
	return retorno;
}*/

/*
int getDescripcionCarrera(eCarrera aCarrera[], int cantidadDeArray, int buscar, char* descripcion)
{
	int i;
	int retorno = -1;

	for(i=0; i<cantidadDeArray; i++)
	{
		if(aCarrera[i].idCarrera==buscar && aCarrera[i].isEmpty==0)
		{
			strcpy(descripcion, aCarrera[i].descripCarrera);
			retorno=0;
		}
	}
	return retorno;
}
int buscaIdCarreraXdescripcion(eCarrera aCarrera[], char* descripcion, int* buscar, int cantidadDeArray)
{
	int i;
	int retorno=-1;

	for(i=0; i<cantidadDeArray; i++)
	{
		if((strcmp(descripcion,aCarrera[i].descripCarrera)==0) && aCarrera[i].isEmpty==0)
		{
			*buscar=aCarrera[i].idCarrera;
			retorno=0;
		}
	}
	return retorno;
}
int lista1Carrera(Alumno aAlumnos[],int cantidadDeArray, int idCarrera, eCarrera aCarrera[], int cantidadCarrera)
{
	int retorno=-1;
	int i;
	char desCarrera[20];

	for(i=0; i<cantidadDeArray; i++)
	{
		if(aAlumnos[i].idCarrera==idCarrera && aAlumnos[i].isEmpty==0)
		{
			getDescripcionCarrera(aCarrera, cantidadCarrera, idCarrera, desCarrera);
			mostrarAlumno(aAlumnos[i],desCarrera);
			retorno=0;
		}
	}
	return retorno;
}
int alumnosMasGrandes(Alumno aAlumnos[], int cantidadDeArray, eCarrera aCarreras[], int cantidadCarreras)
{
	int retorno = -1;
	int i;
	int mayor=0;
	int flagMayor=0;

	if(aAlumnos!=NULL && aCarreras!=NULL && cantidadDeArray>0 && cantidadCarreras>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAlumnos[i].isEmpty==1)
				continue;
			else
			{
				if(aAlumnos[i].edad>mayor || flagMayor==0)
				{
					flagMayor=1;
					mayor=aAlumnos[i].edad;
					retorno=0;
				}
			}
		}
		if(mayor!=0)
		{
			Informes_listarAlumnosMasGrandes(aAlumnos, cantidadDeArray, aCarreras, cantidadCarreras, mayor);
		}
	}

	return retorno;
}
int alumnosMasJovenes(Alumno aAlumnos[], int cantidadDeArray, eCarrera aCarreras[], int cantidadCarreras)
{
	int retorno = -1;
	int i;
	int menor=0;
	int flagMenor=0;

	if(aAlumnos!=NULL && aCarreras!=NULL && cantidadDeArray>0 && cantidadCarreras>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAlumnos[i].isEmpty==1)
				continue;
			else
			{
				if(aAlumnos[i].edad<menor || flagMenor==0)
				{
					flagMenor=1;
					menor=aAlumnos[i].edad;
					retorno=0;
				}
			}
		}
		if(menor!=0)
		{
			Informes_listarAlumnosMasJovenes(aAlumnos, cantidadDeArray, aCarreras, cantidadCarreras, menor);
		}
	}
	return retorno;
}
int mostrarAlumnosXCarrera(Alumno aAlumno[], int cantidadDeArray,eCarrera aCarreras[], int cantidadCarreras)
{
	int i;
	int j;
	char descripcion[20];
	int retorno = -1;

	for(i=0; i<cantidadCarreras; i++)
	{
		printf("%4d %15s\n", aCarreras[i].idCarrera, aCarreras[i].descripCarrera);

		for(j=0; j<cantidadDeArray; j++)
		{
			if(aAlumno[j].idCarrera==aCarreras[i].idCarrera)
			{
				getDescripcionCarrera(aCarreras, cantidadCarreras, aAlumno[j].idCarrera, descripcion);
				mostrarAlumnos(aAlumno, cantidadDeArray, aCarreras, cantidadCarreras);
				//printf("\t'%s %4.2f\n", lista)
			}

		}
	}

	return retorno;
	switch(aAuxiliar.sector)
			{
				case ADMISION:
					aAuxiliar.sector = ADMISION;
					break;
				case SEGURIDAD:
					aAuxiliar.sector = SEGURIDAD;
					break;
				case ADMINISTRACION:
					aAuxiliar.sector = ADMINISTRACION;
					break;
			}
}
*/
int utn_getNumeroConDecimales(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
	int retorno = -1;
	float bufferInterno;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			scanf("%f", &bufferInterno);
			if(bufferInterno>=minimo && bufferInterno<=maximo)
			{
				*pResultado=bufferInterno;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if(bufferChar>=minimo && bufferChar<=maximo)
			{
				*pResultado=bufferChar;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getCaracterSN()
{
	int retorno = -1;
	char c;

	//utn_getCaracter(&c, "Ingrese Si 'S' o No 'N'", "Ingrese Si 'S' o No 'N'", A, z, 0);
	getChar("Ingrese Si 's' o No 'n'", &c);
	//c= toupper(c);

	while (c != 's' && c != 'n')
	{
		puts("ERROR. OPCION NO VALIDA");
		getChar("Ingrese Si 's' o No 'n'", &c);
		//c = toupper(c);
	}
			if (c == 's')
			{
				retorno = 0;
			}
	return retorno;
}

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "UTN.h"
int menu(void)
{
		int option;
	    int flag=0;
	    int flag2=0;
	    LinkedList* listaEmpleados = ll_newLinkedList();
	    printf("------------ /BIENVENIDO/ -------------\n");
	    do{
	    	if(utn_getNumero(&option,"-------- Seleccione una opcion --------\n"
	    			"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
	    			"2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n"
	    			"3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n"
	    			"8. Guardar los datos de los empleados en archivo tipo .csv (modo texto)\n"
	    			"9. Guardar los datos de los empleados en archivo tipo .bin (modo binario)\n10. Salir",
	    					"------- Error ingrese ------ \n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
	    			"2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n"
	    			"3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n"
	    			"8. Guardar los datos de los empleados en archivo tipo .csv (modo texto)\n"
	    			"9. Guardar los datos de los empleados en archivo tipo .bin (modo binario)\n10. Salir\n", 1, 10, 2)==0){
				switch(option)
				{
					case 1:
						if(flag==0)
						{
							utn_getNumero(&flag, "Desea abrir: \n1. data.csv \n2. Chequeo.csv", "Error, opcion incorrecta", 1, 2, 1);
							switch(flag)
							{
							case 1:
								controller_loadFromText("data.csv",listaEmpleados);
								break;
							case 2:
								controller_loadFromText("Chequeo.csv",listaEmpleados);
								break;
							}
						}
						else
						{
							printf("El archivo ya fue cargado");
						}
						break;
					case 2:
						if(flag==0)
						{
							utn_getNumero(&flag, "Desea abrir: \n1. data.bin \n2.Chequeo.bin", "Error, opcion incorrecta", 1, 2, 1);
							switch(flag)
							{
							case 1:
								controller_loadFromBinary("data.bin",listaEmpleados);
								break;
							case 2:
								controller_loadFromBinary("Chequeo.bin",listaEmpleados);
								break;
							}
						}
						else
						{
							printf("El archivo ya fue cargado\n");
						}

						break;
					case 3:
						controller_addEmployee(listaEmpleados);
						break;
					case 4:
						controller_editEmployee(listaEmpleados);
						break;
					case 5:
						controller_removeEmployee(listaEmpleados);
						break;
					case 6:
						controller_ListEmployee(listaEmpleados);
						break;
					case 7:
						controller_sortEmployee(listaEmpleados);
						printf("Desea imprimir lista ordenada. ");
						if(utn_getCaracterSN()==0)
						{
							controller_ListEmployee(listaEmpleados);
						}
						break;
					case 8:
						utn_getNumero(&flag2, "Desea guardar en: \n1. data.csv \n2. Chequeo.csv", "Error, opcion incorrecta", 1, 2, 1);
						switch(flag2)
						{
						case 1:
							controller_saveAsText("data.csv",listaEmpleados);
							break;
						case 2:
							controller_saveAsText("Chequeo.csv",listaEmpleados);
							break;
						}
						break;
					case 9:
						utn_getNumero(&flag2, "Desea guardar en: \n1. data.bin \n2. Chequeo.bin", "Error, opcion incorrecta", 1, 2, 1);
						switch(flag2)
						{
						case 1:
							controller_saveAsBinary("data.bin",listaEmpleados);
							break;
						case 2:
							controller_saveAsBinary("Chequeo.bin",listaEmpleados);
							break;
						}
						break;
					case 10:
						if(ll_isEmpty(listaEmpleados)==0 && flag2==0)
						{
							printf("Se encuentra una lista con datos en ejecucion, desea salir sin guardar? ");
							if(utn_getCaracterSN()==0)
							{
								controller_deleteLinkedList(listaEmpleados);
							}
							else
							{
								option=11;
							}
						}
						else
						{
							controller_deleteLinkedList(listaEmpleados);
						}
						break;
				}
	    	}
	    }while(option != 10);
	return 0;
}



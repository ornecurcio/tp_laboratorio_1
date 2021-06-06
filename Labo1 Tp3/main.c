#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "UTN.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option;
    int flag=0;
    Employee* pAuxEmpleado;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	if(utn_getNumero(&option,"Seleccione una opcion\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
    			"2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n"
    			"3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n"
    			"8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
    			"9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n10. Salir",
    					"Error ingrese: \n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
    			"2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n"
    			"3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n"
    			"8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
    			"9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n10. Salir", 1, 10, 2)==0){
			switch(option)
			{
				case 1:
					if(flag==0)
					{
						controller_loadFromText("data.csv",listaEmpleados);
						flag=1;
					}
					else
					{
						printf("El archivo ya fue cargado");
					}
					break;
				case 2:
					if(flag==0)
					{
						controller_loadFromBinary("data.bin",listaEmpleados);
					}
					else
					{
						printf("El archivo ya fue cargado\n");
					}
//					auxCantLink=ll_len(listaEmpleados);
//					f2=fopen("data.bin","wb");
//					for(int i=0; i<auxCantLink; i++)
//					{
//						pAuxEmpleado = (Employee*)ll_get(listaEmpleados, i);
//					 fwrite(pAuxEmpleado, sizeof(Employee),1,f2);
//					}
//					fclose(f2);
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
					//controller_sortEmployee(listaEmpleados);
					break;
				case 8:
					//controller_saveAsText("data2.csv",listaEmpleados);
					break;
				case 9:
					//controller_saveAsBinary("data2.bin",listaEmpleados);
					break;
			}
    	}
    }while(option != 10);

    return 0;
}



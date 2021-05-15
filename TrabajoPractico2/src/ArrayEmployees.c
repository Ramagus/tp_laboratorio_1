#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "Input.h"

int initEmployees(Employee* list, int len)
{
    int auxReturn = -1;
    int i;

    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            list[i].isEmpty = TRUE;
        }

        auxReturn = 0;
    }

    return auxReturn;
}

int getEmptyIndex(Employee* list, int len)
{
    int index = -1;
    int i;

    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == TRUE)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}

int arrayIsEmpty(Employee* list, int len)
{
    int auxReturn = -1;
    int i;

    if(list != NULL && len > 0)
    {
        auxReturn = 1;

        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == FALSE)
            {
                auxReturn = 0;
                break;
            }
        }
    }

    return auxReturn;
}

int hardCodeEmployees(Employee* list, int len, int* id)
{
    int auxReturn = -1;
    int i = 0;
    int index;
    int quantity;
    int flag = FALSE;

    Employee auxEmployees[] = {{1, "Jorge", "Diaz", 40000.50, 4, FALSE},
							   {2, "Hector", "Fernandez", 50000.50, 5, FALSE},
							   {3, "Juan", "Gomez", 60000.50, 6, FALSE},
							   {4, "Ricardo", "Alvarez", 70000.50, 7, FALSE},
							   {5, "Martin", "Gomez", 80000.50, 8, FALSE},
							   {6, "Jose", "Diaz", 90000.50, 9, FALSE}};

    if(list != NULL && len > 0 && id != NULL)
    {
    	quantity = sizeof(auxEmployees) / sizeof(Employee);

    	if(quantity <= len)
    	{
			while(i < quantity)
			{
				index = getEmptyIndex(list, len);

				if(index > -1)
				{
					if(auxEmployees[i].id > *id)
					{
						*id = auxEmployees[i].id;
					}

					list[index] = auxEmployees[i];

					flag = TRUE;
				}

				else
				{
					break;
				}

				i++;
			}

			if(flag)
			{
				auxReturn = 0;
			}
    	}
    }

    return auxReturn;
}

int loadEmployee(Employee* list, int len, int* id)
{
	int auxReturn = -1;

	char auxName[NAME_LEN];
	char auxLastName[LAST_NAME_LEN];
	float auxSalary;
	int auxSector;

	if(list != NULL && len > 0 && id != NULL &&
	   !utn_getAlfabetico(auxName, "\nIngrese su nombre: ", "Error. Ingrese solo letras: ", 3, NAME_LEN, 2) &&
	   !utn_formatearCadena(auxName, NAME_LEN) &&
	   !utn_getAlfabetico(auxLastName, "\nIngrese su apellido: ", "Error. Ingrese solo letras: ", 3, LAST_NAME_LEN, 2) &&
	   !utn_formatearCadena(auxLastName, LAST_NAME_LEN) &&
	   !utn_getNumeroFlotante(&auxSalary, "\nIngrese su salario entre 1 y 500000: ", "Error. Ingrese solo numeros flotantes dentro del rango: ", 1, 500000, 2) &&
	   !utn_getNumero(&auxSector, "\nIngrese su sector entre 1 y 10: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 10, 2) &&
	   !addEmployee(list, len, *id + 1, auxName, auxLastName, auxSalary, auxSector))
	{
		(*id)++;

		auxReturn = 0;
	}

    return auxReturn;
}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int auxReturn = -1;
    int index;

    if(list != NULL && len > 0)
    {
        index = getEmptyIndex(list, len);

        if(index > -1)
        {
            list[index].id = id;

            strncpy(list[index].name, name, NAME_LEN);
            strncpy(list[index].lastName, lastName, LAST_NAME_LEN);
            list[index].salary = salary;
            list[index].sector = sector;

            list[index].isEmpty = FALSE;

            auxReturn = 0;
        }
    }

    return auxReturn;
}

int findEmployeeById(Employee* list, int len, int id)
{
    int index = -1;
    int i;

    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == FALSE && list[i].id == id)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}

int modifyEmployee(Employee* list, int len, int id)
{
    int auxReturn = -1;
    int index;
    char reply;

    if(list != NULL && len > 0)
    {
        index = findEmployeeById(list, len, id);

        if(index > -1)
        {
        	printf("\n");
			system("pause");
			system("cls");

			printf("\tMODIFICACION DE EMPLEADO\n\n");

			printf("ID\tNOMBRE\t\tAPELLIDO\tSALARIO\t\tSECTOR\n\n");
			printAnEmployee(&list[index]);

			if(verificarRespuesta(&reply, "\nEsta seguro que desea modificar a este empleado? (S/N): ", "\nError. Solo S o N: ") == 1 &&
			   !showModificationsMenu(list, len, index))
			{
				auxReturn = 0;
			}
        }
    }

    return auxReturn;
}

int showModificationsMenu(Employee* list, int len, int index)
{
	int auxReturn = -1;

	char auxName[NAME_LEN];
	char auxLastName[LAST_NAME_LEN];
	float auxSalary;
	int auxSector;

	char option;

	int flag = FALSE;

    if(list != NULL && len > 0 && index >= 0 && index < len)
    {
        do
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tMENU DE MODIFICACION DE EMPLEADO\n\n");
            printf("A. Nombre\n");
            printf("B. Apellido\n");
            printf("C. Salario\n");
            printf("D. Sector\n");
            printf("E. Salir\n");

            if(!utn_getCaracter(&option, "\nQue desea modificar?: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'E', 2))
            {
                switch(option)
                {
                    case 'A':

                        if(!utn_getAlfabetico(auxName, "\nIngrese nuevo nombre: ", "Error. Ingrese solo letras: ", 3, 51, 2) &&
                           !utn_formatearCadena(auxName, NAME_LEN))
                        {
                            strncpy(list[index].name, auxName, NAME_LEN);

                            flag = TRUE;
                        }

                        break;

                    case 'B':

                        if(!utn_getAlfabetico(auxLastName, "\nIngrese nuevo apellido: ", "Error. Ingrese solo letras: ", 3, 51, 2) &&
                           !utn_formatearCadena(auxLastName, LAST_NAME_LEN))
                        {
                            strncpy(list[index].lastName, auxLastName, LAST_NAME_LEN);

                            flag = TRUE;
                        }

                        break;

                    case 'C':

                        if(!utn_getNumeroFlotante(&auxSalary, "\nIngrese nuevo salario entre 1 y 500000: ", "Error. Ingrese solo numeros flotantes dentro del rango: ",
                                                  1, 500000, 2))
                        {
                            list[index].salary = auxSalary;

                            flag = TRUE;
                        }

                        break;

                    case 'D':

                        if(!utn_getNumero(&auxSector, "\nIngrese nuevo sector entre 1 y 10: ", "Error. Ingrese solo numeros enteros dentro del rango: ",
                           1, 10, 2))
                        {
                            list[index].sector = auxSector;

                            flag = TRUE;
                        }

                        break;

                    case 'E':

                    	printf("\nHa salido del menu de modificacion\n");

                    	break;
                }
            }

        } while(option != 'E');

        if(flag)
        {
        	auxReturn = 0;
        }
    }

    return auxReturn;
}

int removeEmployee(Employee* list, int len, int id)
{
    int auxReturn = -1;
    int index;
    char reply;

    if(list != NULL && len > 0)
    {
        index = findEmployeeById(list, len, id);

        if(index > -1)
        {
			printf("\n");
			system("pause");
			system("cls");

			printf("\tBAJA DE EMPLEADO\n\n");

			printf("ID\tNOMBRE\t\tAPELLIDO\tSALARIO\t\tSECTOR\n\n");
			printAnEmployee(&list[index]);

        	if(verificarRespuesta(&reply, "\nEsta seguro que desea eliminar a este empleado? (S/N): ", "\nError. Solo S o N: ") == 1)
        	{
        		list[index].isEmpty = TRUE;
        		auxReturn = 0;
        	}
        }
    }

    return auxReturn;
}

int sortEmployees(Employee* list, int len, int order)
{
    int auxReturn = -1;
    int i;
    int flagSwap;
    int auxCmp;

    Employee auxEmp;

    if(list != NULL && len > 0)
    {
        do
        {
            flagSwap = FALSE;

            for(i = 0; i < len - 1; i++)
            {
                if(list[i].isEmpty == FALSE && list[i + 1].isEmpty == FALSE)
                {
					auxCmp = strncmp(list[i].lastName, list[i + 1].lastName, LAST_NAME_LEN);

					if(((auxCmp > 0 || (auxCmp == 0 && list[i].sector > list[i + 1].sector)) && order == 1) ||
					   ((auxCmp < 0 || (auxCmp == 0 && list[i].sector < list[i + 1].sector)) && order == 0))
					{
						auxEmp = list[i];
						list[i] = list[i + 1];
						list[i + 1] = auxEmp;

						flagSwap = TRUE;
					}
                }
            }

            len--;

        } while(flagSwap);

        auxReturn = 0;
    }

    return auxReturn;
}

int showSortMenu(Employee* list, int len)
{
	int auxReturn = -1;
	char option;
    int order;

    if(list != NULL && len > 0)
    {
        do
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tMENU DE ORDENAMIENTO\n\n");
            printf("A. Orden Ascendente\n");
            printf("B. Orden Descendente\n");

            if(!utn_getCaracter(&option, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'B', 2))
            {
                switch(option)
                {
                    case 'A':

                        order = 1;

                        break;

                    case 'B':

                        order = 0;

                        break;
                }
            }

        } while(option != 'A' && option != 'B');

        if(!sortEmployees(list, len, order))
        {
        	auxReturn = 0;
        }
    }

    return auxReturn;
}

int printAnEmployee(Employee* anEmployee)
{
    int auxReturn = -1;

    if(anEmployee != NULL)
    {
        printf("%d\t%-8s\t%-8s\t%-8.2f\t%-d\n", (*anEmployee).id, (*anEmployee).name, (*anEmployee).lastName, (*anEmployee).salary, (*anEmployee).sector);

        auxReturn = 0;
    }

    return auxReturn;
}

int printEmployees(Employee* list, int len)
{
    int auxReturn = -1;
    int i;

    if(list != NULL && len > 0)
    {
    	printf("\n");
		system("pause");
		system("cls");

		printf("\tLISTA DE EMPLEADOS\n\n");
        printf("ID\tNOMBRE\t\tAPELLIDO\tSALARIO\t\tSECTOR\n\n");

        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == FALSE && printAnEmployee(&list[i]))
            {
                break;
            }
        }

        if(i == len)
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int accumulateEmployeeSalaries(Employee* list, int len, float* accumulator)
{
    int auxReturn = -1;
    int i;

    if(list != NULL && len > 0 && accumulator != NULL)
    {
        *accumulator = 0;

        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == FALSE)
            {
                *accumulator += list[i].salary;
            }
        }

        auxReturn = 0;
    }

    return auxReturn;
}

int countEmployeeSalaries(Employee* list, int len, int* counter)
{
    int auxReturn = -1;
    int i;

    if(list != NULL && len > 0 && counter != NULL)
    {
        *counter = 0;

        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == FALSE)
            {
                (*counter)++;
            }
        }

        auxReturn = 0;
    }

    return auxReturn;
}

int getAverageSalary(Employee* list, int len, float* average)
{
    int auxReturn = -1;
    float accumulator;
    int counter;

    if(list != NULL && len > 0 && average != NULL &&
       !accumulateEmployeeSalaries(list, len, &accumulator) && !countEmployeeSalaries(list, len, &counter) && counter > 0)
    {
		*average = accumulator / counter;

		auxReturn = 0;
    }

    return auxReturn;
}

int countExceededSalariesFromAverage(Employee* list, int len, int* counter)
{
    int auxReturn = -1;
    float average;
    int i;

    if(list != NULL && len > 0 && counter != NULL && !getAverageSalary(list, len, &average))
    {
        *counter = 0;

		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].salary > average)
			{
				(*counter)++;
			}
		}

		auxReturn = 0;
    }

    return auxReturn;
}

int showEmployeesMenu(int* option)
{
	int auxReturn = -1;

	if(option != NULL)
	{
		printf("\tMENU DE EMPLEADOS\n\n");
		printf("1. Altas\n");
		printf("2. Modificar\n");
		printf("3. Baja\n");
		printf("4. Informar\n");
		printf("5. Salir\n");

		if(!utn_getNumero(option, "\nElija una opcion: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 5, 2))
		{
			auxReturn = 0;
		}
	}

	return auxReturn;
}

int showReportsMenu(Employee* list, int len)
{
	int auxReturn = -1;

    float salaryAccumulator;
    int salaryCounter;
    float averageSalary;
    int employeeCounter;
    int flagLista = FALSE;
    int flagSalarios = FALSE;

    int option;

    if(list != NULL && len > 0)
    {
        do
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tMENU DE INFORMES\n\n");
            printf("1. Lista ordenada de empleados\n");
            printf("2. Promedio de salarios\n");
            printf("3. Salir\n");

            if(!utn_getNumero(&option, "\nElija una opcion: ", "Error. Solo numeros enteros dentro del rango: ", 1, 3, 2))
            {
                switch(option)
                {
                    case 1:

                        if(!showSortMenu(list, len))
                        {
                            if(!printEmployees(list, len))
                            {
                                printf("\nLista mostrada correctamente\n");

                                flagLista = TRUE;
                            }

                            else
                            {
                                printf("\nNo se pudo mostrar la lista\n");
                            }
                        }

                        else
                        {
                            printf("\nNo se pudo mostrar el menu\n");
                        }

                        break;

                    case 2:

                    	printf("\n");
                    	system("pause");
                    	system("cls");

                    	if(!accumulateEmployeeSalaries(list, len, &salaryAccumulator) && !countEmployeeSalaries(list, len, &salaryCounter) &&
                           !getAverageSalary(list, len, &averageSalary) && !countExceededSalariesFromAverage(list, len, &employeeCounter))
                        {
                            printf("\tINFORME DE SALARIOS\n");

                    		printf("\nSuma de salarios: %.2f - Cantidad de salarios: %d\n", salaryAccumulator, salaryCounter);
                            printf("\nEl promedio de salarios es: %.2f\n", averageSalary);
                            printf("\nCantidad de empleados que superan el salario promedio: %d\n", employeeCounter);

                            flagSalarios = TRUE;
                        }

                        else
                        {
                            printf("\nNo se pudo calcular el salario\n");
                        }

                        break;

                    case 3:

                        if(flagLista && flagSalarios)
                        {
                            printf("\nHa salido del menu de informes\n");
                        }

                        else if(!flagLista && flagSalarios)
                        {
                            printf("\nError. Primero elija el informe de la lista para mostrar\n");
                        }

                        else if(flagLista && !flagSalarios)
                        {
                            printf("\nError. Primero elija el informe de salarios para mostrar\n");
                        }

                        else
                        {
                            printf("\nError. Primero elija un informe para mostrar\n");
                        }

                        break;
                }
            }

        } while(option != 3 || (!flagLista || !flagSalarios));

        auxReturn = 0;
    }

    return auxReturn;
}

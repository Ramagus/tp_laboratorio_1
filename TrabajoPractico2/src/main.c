#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Input.h"

#define ELEMENTS 1000

int main()
{
    setbuf(stdout, NULL);

    Employee arrayEmployees[ELEMENTS];
    int option;
    int auxId;

    int id = 0;

    if(!initEmployees(arrayEmployees, ELEMENTS))
    {
    	hardCodeEmployees(arrayEmployees, ELEMENTS, &id);

		do
		{
			if(!showEmployeesMenu(&option))
			{
				switch(option)
				{
					case 1:

						printf("\n");
						system("pause");
						system("cls");

						printf("\tALTA DE EMPLEADO\n");

						if(!loadEmployee(arrayEmployees, ELEMENTS, &id))
						{
							printf("\nDatos cargados\n");
						}

						else
						{
							printf("\nNo hay lugar o no se pudieron cargar los datos\n");
						}

						break;

					case 2:

						if(!arrayIsEmpty(arrayEmployees, ELEMENTS))
						{
							if(!printEmployees(arrayEmployees, ELEMENTS) &&
							   !utn_getNumero(&auxId, "\nIngrese el ID del empleado a modificar entre 1 y 10000: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 10000, 2) &&
							   !modifyEmployee(arrayEmployees, ELEMENTS, auxId))
							{
								printf("\nEl empleado ha sido modificado\n");
							}

							else
							{
								printf("\nError en la modificacion\n");
							}
						}

						else
						{
							printf("\nNo hay empleados para modificar\n");
						}

						break;

					case 3:

						if(!arrayIsEmpty(arrayEmployees, ELEMENTS))
						{
							if(!printEmployees(arrayEmployees, ELEMENTS) &&
							   !utn_getNumero(&auxId, "\nIngrese el ID del empleado a eliminar entre 1 y 10000: ", "Error. Solo numeros enteros dentro del rango: ", 1, 10000, 2) &&
							   !removeEmployee(arrayEmployees, ELEMENTS, auxId))
							{
								printf("\nEl empleado ha sido eliminado\n");
							}

							else
							{
								printf("\nError en la baja\n");
							}
						}

						else
						{
							printf("\nNo hay empleados para eliminar\n");
						}

						break;

					case 4:

						if(!arrayIsEmpty(arrayEmployees, ELEMENTS))
						{
							if(!showReportsMenu(arrayEmployees, ELEMENTS))
							{
								printf("\nInformes mostrados correctamente\n");
							}

							else
							{
								printf("\nNo se pudo mostrar el menu\n");
							}
						}

						else
						{
							printf("\nNo hay empleados para mostrar\n");
						}

						break;

					case 5:

						printf("\nHa salido del menu de empleados\n");

						break;
				}
			}

			printf("\n");
			system("pause");
			system("cls");

		} while(option != 5);
    }

    else
    {
        printf("No se pudo inicializar el array correctamente\n");
    }

    return EXIT_SUCCESS;
}

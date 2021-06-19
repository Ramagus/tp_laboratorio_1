#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)
     2. Cargar los datos de los empleados desde el archivo data2.csv (modo binario)
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto)
     9. Guardar los datos de los empleados en el archivo data2.csv (modo binario)
    10. Salir
*****************************************************/


int main()
{
    setbuf(stdout, NULL);

	LinkedList* listEmployees;
    int option;
    int flag = 0;

    int id = 0;

    listEmployees = ll_newLinkedList();

    if(listEmployees != NULL)
    {
        do
        {
            if(!employee_optionsMenu(&option))
            {
                switch(option)
                {
                    case 1:

                    	if(!flag)
                    	{
							if(!controller_loadFromText("data.csv", listEmployees, &id))
							{
								printf("\nEl archivo se ha leido correctamente en modo texto\n");

								flag = 1;
							}

							else
							{
								printf("\nNo se pudo leer el archivo en modo texto\n");
							}
                    	}

                    	else
                    	{
                    		printf("\nEl archivo en modo texto ya ha sido cargado\n");
                    	}

                        break;

                    case 2:

                    	if(!flag)
                    	{
							if(!controller_loadFromBinary("data2.csv", listEmployees, &id))
							{
								printf("\nEl archivo se ha leido correctamente en modo binario\n");

								flag = 1;
							}

							else
							{
								printf("\nNo se pudo leer el archivo en modo binario\n");
							}
                    	}

						else
						{
							printf("\nEl archivo en modo binario ya ha sido cargado\n");
						}

                        break;

                    case 3:

						printf("\n");
						system("pause");
						system("cls");

						printf("\tALTA DE EMPLEADO\n");

						if(!controller_addEmployee(listEmployees, &id))
						{
							printf("\nEmpleado cargado correctamente\n");
						}

						else
						{
							printf("\nNo se pudo cargar al empleado\n");
						}

                        break;

                    case 4:

						if(!ll_isEmpty(listEmployees))
						{
							if(!controller_editEmployee(listEmployees))
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
							printf("\nNo hay empleados cargados para poder modificar\n");
						}

                        break;

                    case 5:

						if(!ll_isEmpty(listEmployees))
						{
							if(!controller_removeEmployee(listEmployees))
							{
								printf("\nEl empleado ha sido eliminado\n");
							}

							else
							{
								printf("\nError en la eliminacion\n");
							}
						}

						else
						{
							printf("\nNo hay empleados cargados para poder eliminar\n");
						}

                        break;

                    case 6:

						if(!ll_isEmpty(listEmployees))
						{
							if(!controller_listEmployee(listEmployees))
							{
								printf("\nLista mostrada correctamente\n");
							}

							else
							{
								printf("\nNo se pudo mostrar la lista\n");
							}
						}

						else
						{
							printf("\nNo hay empleados cargados para mostrar\n");
						}

                        break;

                    case 7:

						if(!ll_isEmpty(listEmployees))
						{
							if(!controller_sortEmployee(listEmployees))
							{
								printf("\n\nOrdenamiento realizado correctamente\n");
							}

							else
							{
								printf("\nNo se pudo realizar el ordenamiento\n");
							}
						}

						else
						{
							printf("\nNo hay empleados cargados para ordenar\n");
						}

                        break;

                    case 8:

                        if(!ll_isEmpty(listEmployees))
                        {
                            if(!controller_saveAsText("data.csv", listEmployees))
                            {
                                printf("\nEl archivo se ha guardado correctamente en modo texto\n");
                            }

                            else
                            {
                                printf("\nNo se pudo guardar el archivo en modo texto\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay empleados cargados para guardar en el archivo en modo texto\n");
                        }

                        break;

                    case 9:

                        if(!ll_isEmpty(listEmployees))
                        {
                            if(!controller_saveAsBinary("data2.csv", listEmployees))
                            {
                                printf("\nEl archivo se ha guardado correctamente en modo binario\n");
                            }

                            else
                            {
                                printf("\nNo se pudo guardar el archivo en modo binario\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay empleados cargados para guardar en el archivo en modo binario\n");
                        }

                        break;

                    case 10:

                        printf("\nHa salido del menu\n");

                        break;
                }
            }

            printf("\n");
            system("pause");
            system("cls");

        } while(option != 10);

        employee_clear(listEmployees);
        ll_deleteLinkedList(listEmployees);
    }

    else
    {
        printf("No se pudo generar el LinkedList\n");
    }

    return 0;
}

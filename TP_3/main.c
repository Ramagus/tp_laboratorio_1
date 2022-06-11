#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Input.h"
#define PATH_TXT "data.csv"
#define PATH_BIN "data.bin"


/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)
     2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario)
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)
     9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario)
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);

    LinkedList* listaPasajeros = NULL;

    int option;
    int flagAnswer;
    int flagClear;
    int flagSave = 0;
    int flagExit = 0;
    int id = 1;

    listaPasajeros = ll_newLinkedList();

    if(listaPasajeros != NULL)
    {
		do
		{
			if(!Passenger_optionsMenu(&option))
			{
				switch(option)
				{
					case 1:
					case 2:

						flagAnswer = 0;
						flagClear = 0;

						if(!ll_isEmpty(listaPasajeros))
						{
							flagAnswer = 1;

							if(utn_respuestaEsAfirmativa("\nCiudado, se van a sobrescribir los datos. Desea continuar? (S/N): ", "Error. Solo S o N: ") == 1)
							{
								if(!Passenger_clear(listaPasajeros))
								{
									flagClear = 1;
								}
							}

							else
							{
								printf("\nAccion cancelada\n");
							}
						}

						if(!flagAnswer || flagClear)
						{
							if(option == 1)
							{
								if(!controller_loadFromText(PATH_TXT, listaPasajeros, &id))
								{
									printf("\nEl archivo de texto se ha leido correctamente\n");
								}

								else
								{
									printf("\nNo se pudo leer el archivo de texto\n");
								}
							}

							else
							{
								if(!controller_loadFromBinary(PATH_BIN, listaPasajeros, &id))
								{
									printf("\nEl archivo binario se ha leido correctamente\n");
								}

								else
								{
									printf("\nNo se pudo leer el archivo binario\n");
								}
							}
						}

						else
						{
							printf("\nError en la carga\n");
						}

						break;

					case 3:

						printf("\n");
						system("pause");
						system("cls");

						printf("\tALTA DE EMPLEADO\n");

						if(!controller_addPassenger(listaPasajeros, &id))
						{
							printf("\nPasajero cargado correctamente\n");
						}

						else
						{
							printf("\nNo se pudo cargar al pasajero\n");
						}

						break;

					case 4:

						if(!ll_isEmpty(listaPasajeros))
						{
							if(!controller_editPassenger(listaPasajeros))
							{
								printf("\nEl pasajero ha sido modificado\n");
							}

							else
							{
								printf("\nError en la modificacion\n");
							}
						}

						else
						{
							printf("\nNo hay pasajeros cargados para poder modificar\n");
						}

						break;

					case 5:

						if(!ll_isEmpty(listaPasajeros))
						{
							if(!controller_removePassenger(listaPasajeros))
							{
								printf("\nEl pasajero ha sido eliminado\n");
							}

							else
							{
								printf("\nError en la eliminacion\n");
							}
						}

						else
						{
							printf("\nNo hay pasajeros cargados para poder eliminar\n");
						}

						break;

					case 6:

						if(!ll_isEmpty(listaPasajeros))
						{
							if(!controller_listPassenger(listaPasajeros))
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
							printf("\nNo hay pasajeros cargados para mostrar\n");
						}

						break;

					case 7:

						if(!ll_isEmpty(listaPasajeros))
						{
							if(!controller_sortPassenger(listaPasajeros))
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
							printf("\nNo hay pasajeros cargados para ordenar\n");
						}

						break;

					case 8:

						if(!ll_isEmpty(listaPasajeros))
						{
							if(!controller_fileExists(PATH_TXT, "r") ||
							   utn_respuestaEsAfirmativa("\nCiudado, se va a sobrescribir el archivo de texto. Desea continuar? (S/N): ", "Error. Solo S o N: ") == 1)
							{
								if(!controller_saveAsText(PATH_TXT, listaPasajeros))
								{
									printf("\nEl archivo de texto se ha escrito correctamente\n");

									flagSave = 1;
								}

								else
								{
									printf("\nNo se pudo escribir el archivo de texto\n");
								}
							}
						}

						else
						{
							printf("\nNo hay pasajeros cargados para guardar en el archivo de texto\n");
						}

						break;

					case 9:

						if(!ll_isEmpty(listaPasajeros))
						{
							if(!controller_fileExists(PATH_BIN, "rb") ||
							   utn_respuestaEsAfirmativa("\nCiudado, se va a sobrescribir el archivo binario. Desea continuar? (S/N): ", "Error. Solo S o N: ") == 1)
							{
								if(!controller_saveAsBinary(PATH_BIN, listaPasajeros))
								{
									printf("\nEl archivo binario se ha escrito correctamente\n");

									flagSave = 1;
								}

								else
								{
									printf("\nNo se pudo escribir el archivo binario\n");
								}
							}
						}

						else
						{
							printf("\nNo hay pasajeros cargados para guardar en el archivo binario\n");
						}

						break;

					case 10:

						if(flagSave)
						{
							if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
							{
								printf("\nHa salido del menu\n");

								flagExit = 1;
							}
						}

						else
						{
							printf("\nDebe guardar la lista en algun modo\n");
						}

						break;
				}
			}

			printf("\n");
			system("pause");
			system("cls");

		} while(option != 10 || !flagExit);

		Passenger_clear(listaPasajeros);
		ll_deleteLinkedList(listaPasajeros);
    }

    else
    {
    	printf("No se pudo generar el LinkedList\n");
    }

    return 0;
}

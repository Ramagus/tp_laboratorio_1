#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Nexus.h"
#include "Input.h"

int loadPassenger(Passenger* listPass, int lenPass, FlightCode* listFlightCode, int lenFlightCode, TypePassenger* listTypePassenger, int lenTypePassenger, FlightStatus* listFlightStatus, int lenFlightStatus, int* idPass)
{
	int auxReturn = -1;

	char auxName[NAME_LEN];
	char auxLastName[LAST_NAME_LEN];
	float auxPrice;
	int auxIdCode;
	int auxTypePassenger;
	int index;

	if(listPass != NULL && lenPass > 0 && listFlightCode != NULL && lenFlightCode > 0 && listTypePassenger != NULL && lenTypePassenger > 0 && listFlightStatus != NULL && lenFlightStatus > 0 && idPass != NULL &&
	   !utn_getAlfabetico(auxName, "\nIngrese su nombre: ", "Error. Ingrese solo letras: ", 3, NAME_LEN, 2) &&
	   !utn_formatearCadena(auxName, NAME_LEN) &&
	   !utn_getAlfabetico(auxLastName, "\nIngrese su apellido: ", "Error. Ingrese solo letras: ", 3, LAST_NAME_LEN, 2) &&
	   !utn_formatearCadena(auxLastName, LAST_NAME_LEN) &&
	   !utn_getNumeroFlotante(&auxPrice, "\nIngrese precio de pasaje entre 1 y 500000: ", "Error. Ingrese solo numeros flotantes dentro del rango: ", 1, 500000, 2) &&
	   !printFlightCodes(listFlightCode, lenFlightCode, listFlightStatus, lenFlightStatus) &&
	   !utn_getNumero(&auxIdCode, "\nIngrese el ID del codigo de vuelo: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 8, 2))
	{
		index = findFlightCodeById(listFlightCode, lenFlightCode, auxIdCode);

		if(index > -1 && !printTypePassengers(listTypePassenger, lenTypePassenger) &&
		   !utn_getNumero(&auxTypePassenger, "\nIngrese el ID del tipo de pasajero: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 4, 2) &&
		   findTypePassengerById(listTypePassenger, lenTypePassenger, auxTypePassenger) > -1 &&
		   !addPassenger(listPass, lenPass, *idPass, auxName, auxLastName, auxPrice, listFlightCode[index].code, auxTypePassenger))
		{
			(*idPass)++;

			auxReturn = 0;
		}
	}

    return auxReturn;
}

int modifyPassenger(Passenger* listPass, int lenPass, FlightCode* listFlightCode, int lenFlightCode, TypePassenger* listTypePassenger, int lenTypePassenger, FlightStatus* listFlightStatus, int lenFlightStatus, int idPass)
{
    int auxReturn = -1;
    int indexPass;
    int indexType;

    if(listPass != NULL && lenPass > 0 && listFlightCode != NULL && lenFlightCode > 0 && listTypePassenger != NULL && lenTypePassenger > 0 && listFlightStatus != NULL && lenFlightStatus > 0 && idPass > 0)
    {
        indexPass = findPassengerById(listPass, lenPass, idPass);

        if(indexPass > -1)
        {
        	indexType = findTypePassengerById(listTypePassenger, lenTypePassenger, listPass[indexPass].typePassenger);

        	if(indexType > -1)
        	{
				printf("\n");
				system("pause");
				system("cls");

				printf("\tMODIFICACION DE PASAJERO\n\n");

				printf("*----------*--------------------*--------------------*----------*--------------------*--------------------*\n");
				printf("|%-10s|%-20s|%-20s|%-10s|%-20s|%-20s|\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "CODIGO DE VUELO", "TIPO DE PASAJERO");
				printf("*----------*--------------------*--------------------*----------*--------------------*--------------------*\n");
				printAPassenger(&listPass[indexPass], &listTypePassenger[indexType]);
				printf("*----------*--------------------*--------------------*----------*--------------------*--------------------*\n");

				if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar a este pasajero? (S/N): ", "\nError. Solo S o N: ") == 1 &&
				   !showModificationsMenu(listPass, lenPass, listFlightCode, lenFlightCode, listTypePassenger, lenTypePassenger, listFlightStatus, lenFlightStatus, indexPass))
				{
					auxReturn = 0;
				}
        	}
        }
    }

    return auxReturn;
}

int showModificationsMenu(Passenger* listPass, int lenPass, FlightCode* listFlightCode, int lenFlightCode, TypePassenger* listTypePassenger, int lenTypePassenger, FlightStatus* listFlightStatus, int lenFlightStatus, int indexPass)
{
	int auxReturn = -1;

	char auxName[NAME_LEN];
	char auxLastName[LAST_NAME_LEN];
	float auxPrice;
	int auxIdCode;
	int auxTypePassenger;
	int indexCode;
	char option;
	int flagMod = FALSE;
	int flagExit = FALSE;

    if(listPass != NULL && lenPass > 0 && listFlightCode != NULL && lenFlightCode > 0 && listTypePassenger != NULL && lenTypePassenger > 0 && listFlightStatus != NULL && lenFlightStatus > 0 && indexPass >= 0 && indexPass < lenPass)
    {
        do
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tMENU DE MODIFICACION DE EMPLEADO\n\n");
            printf("A. Nombre\n");
            printf("B. Apellido\n");
            printf("C. Precio\n");
            printf("D. Codigo de Vuelo\n");
            printf("E. Tipo de Pasajero\n");
            printf("F. Salir\n");

            if(!utn_getCaracter(&option, "\nQue desea modificar?: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'F', 2))
            {
                switch(option)
                {
                    case 'A':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el nombre del pasajero? (S/N): ", "\nError. Solo S o N: ") == 1 &&
                           !utn_getAlfabetico(auxName, "\nIngrese nuevo nombre: ", "Error. Ingrese solo letras: ", 3, NAME_LEN, 2) && !utn_formatearCadena(auxName, NAME_LEN))
                        {
                            strncpy(listPass[indexPass].name, auxName, NAME_LEN);

                            flagMod = TRUE;
                        }

                        break;

                    case 'B':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el apellido del pasajero? (S/N): ", "\nError. Solo S o N: ") == 1 &&
                           !utn_getAlfabetico(auxLastName, "\nIngrese nuevo apellido: ", "Error. Ingrese solo letras: ", 3, LAST_NAME_LEN, 2) && !utn_formatearCadena(auxLastName, LAST_NAME_LEN))
                        {
                            strncpy(listPass[indexPass].lastName, auxLastName, LAST_NAME_LEN);

                            flagMod = TRUE;
                        }

                        break;

                    case 'C':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el precio de pasaje del pasajero? (S/N): ", "\nError. Solo S o N: ") == 1 &&
                           !utn_getNumeroFlotante(&auxPrice, "\nIngrese nuevo precio de pasaje entre 1 y 500000: ", "Error. Ingrese solo numeros flotantes dentro del rango: ", 1, 500000, 2))
                        {
                            listPass[indexPass].price = auxPrice;

                            flagMod = TRUE;
                        }

                        break;

                    case 'D':

                    	if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el codigo de vuelo del pasajero? (S/N): ", "\nError. Solo S o N: ") == 1 &&
                    	   !printFlightCodes(listFlightCode, lenFlightCode, listFlightStatus, lenFlightStatus) &&
                    	   !utn_getNumero(&auxIdCode, "\nIngrese el ID del codigo de vuelo: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 8, 2))
                    	{
                    		indexCode = findFlightCodeById(listFlightCode, lenFlightCode, auxIdCode);

                    	    if(indexCode > -1)
                    	    {
								strncpy(listPass[indexPass].flightCode, listFlightCode[indexCode].code, FLIGHT_CODE_LEN);

								flagMod = TRUE;
                    	    }
                    	}

                    	break;

                    case 'E':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el tipo de pasajero de este pasajero? (S/N): ", "\nError. Solo S o N: ") == 1 &&
                           !printTypePassengers(listTypePassenger, lenTypePassenger) &&
                           !utn_getNumero(&auxTypePassenger, "\nIngrese el ID del tipo de pasajero: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 4, 2) &&
						   findTypePassengerById(listTypePassenger, lenTypePassenger, auxTypePassenger) > -1)
                        {
							listPass[indexPass].typePassenger = auxTypePassenger;

							flagMod = TRUE;
                        }

                        break;

                    case 'F':

                    	if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "\nError. Solo S o N: ") == 1)
                    	{
                    		printf("\nHa salido del menu de modificacion\n");

                    		flagExit = TRUE;
                    	}

                    	break;
                }
            }

        } while(option != 'F' || !flagExit);

        if(flagMod)
        {
        	auxReturn = 0;
        }
    }

    return auxReturn;
}

int removePassenger(Passenger* listPass, int lenPass, TypePassenger* listTypePassenger, int lenTypePassenger, int idPass)
{
    int auxReturn = -1;
    int indexPass;
    int indexType;

    if(listPass != NULL && lenPass > 0 && listTypePassenger != NULL && lenTypePassenger > 0 && idPass > 0)
    {
        indexPass = findPassengerById(listPass, lenPass, idPass);

        if(indexPass > -1)
        {
        	indexType = findTypePassengerById(listTypePassenger, lenTypePassenger, listPass[indexPass].typePassenger);

        	if(indexType > -1)
        	{
				printf("\n");
				system("pause");
				system("cls");

				printf("\tBAJA DE PASAJERO\n\n");

				printf("*----------*--------------------*--------------------*----------*--------------------*--------------------*\n");
				printf("|%-10s|%-20s|%-20s|%-10s|%-20s|%-20s|\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "CODIGO DE VUELO", "TIPO DE PASAJERO");
				printf("*----------*--------------------*--------------------*----------*--------------------*--------------------*\n");
				printAPassenger(&listPass[indexPass], &listTypePassenger[indexType]);
				printf("*----------*--------------------*--------------------*----------*--------------------*--------------------*\n");

				if(utn_respuestaEsAfirmativa("\nEsta seguro que desea eliminar a este pasajero? (S/N): ", "\nError. Solo S o N: ") == 1)
				{
					listPass[indexPass].isEmpty = TRUE;
					auxReturn = 0;
				}
        	}
        }
    }

    return auxReturn;
}

int sortPassengersByCode(Passenger* listPass, int lenPass, FlightCode* listFlightCode, int lenFlightCode, FlightStatus* listFlightStatus, int lenFlightStatus, int order)
{
    int auxReturn = -1;
    int indexCode1;
    int indexCode2;
    int indexStatus1;
    int indexStatus2;
    int i;
    int auxLen;
    int flagSwap;

    if(listPass != NULL && lenPass > 0 && listFlightCode != NULL && lenFlightCode > 0 && listFlightStatus != NULL && lenFlightStatus > 0 && (order == UP || order == DOWN))
    {
    	auxLen = lenPass;

        do
        {
            flagSwap = FALSE;

            for(i = 0; i < auxLen - 1; i++)
            {
                if(!listPass[i].isEmpty && !listPass[i + 1].isEmpty)
                {
					if(compareString(listPass[i].flightCode, listPass[i + 1].flightCode, FLIGHT_CODE_LEN) == order - !order)
					{
						indexCode1 = findFlightCodeByCode(listFlightCode, lenFlightCode, listPass[i].flightCode);
						indexCode2 = findFlightCodeByCode(listFlightCode, lenFlightCode, listPass[i + 1].flightCode);

						if(indexCode1 > -1 && indexCode2 > -1)
						{
							indexStatus1 = findFlightStatusById(listFlightStatus, lenFlightStatus, listFlightCode[indexCode1].status);
							indexStatus2 = findFlightStatusById(listFlightStatus, lenFlightStatus, listFlightCode[indexCode2].status);

							if(indexStatus1 > -1 && indexStatus2 > -1 && listFlightStatus[indexStatus1].id == 1 && listFlightStatus[indexStatus2].id == 1 &&
							   !swapPassengers(&listPass[i], &listPass[i + 1]))
							{
								flagSwap = TRUE;
							}
						}
					}
                }
            }

            auxLen--;

        } while(flagSwap);

        auxReturn = 0;
    }

    return auxReturn;
}

int printAPassenger(Passenger* aPassenger, TypePassenger* aTypePassenger)
{
    int auxReturn = -1;

    if(aPassenger != NULL && aTypePassenger != NULL)
    {
        printf("|%-10d|%-20s|%-20s|%-10.2f|%-20s|%-20s|\n", aPassenger->id, aPassenger->name, aPassenger->lastName, aPassenger->price, aPassenger->flightCode, aTypePassenger->description);

        auxReturn = 0;
    }

    return auxReturn;
}

int printPassengers(Passenger* listPass, int lenPass, TypePassenger* listTypePassengers, int lenTypePassenger)
{
    int auxReturn = -1;
    int index;
    int i;

    if(listPass != NULL && lenPass > 0 && listTypePassengers != NULL && lenTypePassenger > 0)
    {
    	printf("\n");
		system("pause");
		system("cls");

		printf("\tLISTA DE PASAJEROS\n\n");

		printf("*----------*--------------------*--------------------*----------*--------------------*--------------------*\n");
        printf("|%-10s|%-20s|%-20s|%-10s|%-20s|%-20s|\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "CODIGO DE VUELO", "TIPO DE PASAJERO");
        printf("*----------*--------------------*--------------------*----------*--------------------*--------------------*\n");

        for(i = 0; i < lenPass; i++)
        {
            if(!listPass[i].isEmpty)
            {
            	index = findTypePassengerById(listTypePassengers, lenTypePassenger, listPass[i].typePassenger);

                if(index > -1 && printAPassenger(&listPass[i], &listTypePassengers[index]))
                {
                	break;
                }
            }
        }

        printf("*----------*--------------------*--------------------*----------*--------------------*--------------------*\n");

        if(i == lenPass)
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int printPassengersByStatus(Passenger* listPass, int lenPass, FlightCode* listFlightCode, int lenFlightCode, TypePassenger* listTypePassenger, int lenTypePassenger, FlightStatus* listFlightStatus, int lenFlightStatus, int status)
{
	int auxReturn = -1;
	int indexCode;
	int indexType;
	int i;
	int flag = FALSE;

	if(listPass != NULL && lenPass > 0 && listFlightCode != NULL && lenFlightCode > 0 && listTypePassenger != NULL && lenTypePassenger > 0 && listFlightStatus != NULL && lenFlightStatus > 0 && status > 0)
	{
		printf("\n");
		system("pause");
		system("cls");

		for(i = 0; i < lenPass; i++)
		{
			if(!listPass[i].isEmpty)
			{
				indexCode = findFlightCodeByCode(listFlightCode, lenFlightCode, listPass[i].flightCode);

				if(indexCode > -1 && listFlightCode[indexCode].status == status)
				{
					indexType = findTypePassengerById(listTypePassenger, lenTypePassenger, listPass[i].typePassenger);

					if(indexType > -1)
					{
						if(!flag)
						{
							printf("\tLISTA DE PASAJEROS\n\n");

							printf("*----------*--------------------*--------------------*----------*--------------------*--------------------*\n");
							printf("|%-10s|%-20s|%-20s|%-10s|%-20s|%-20s|\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "CODIGO DE VUELO", "TIPO DE PASAJERO");
							printf("*----------*--------------------*--------------------*----------*--------------------*--------------------*\n");
						}

						if(!printAPassenger(&listPass[i], &listTypePassenger[indexType]))
						{
							flag = TRUE;
						}

						else
						{
							break;
						}
					}
				}
			}
		}

		if(i == lenPass)
		{
			if(flag)
			{
				printf("*----------*--------------------*--------------------*----------*--------------------*--------------------*\n");
			}

			else
			{
				printf("\tNo hay vuelos activos\n");
			}

			auxReturn = 0;
		}
	}

	return auxReturn;
}

int printAFlightCode(FlightCode* aFlightCode, FlightStatus* aFlightStatus)
{
    int auxReturn = -1;

    if(aFlightCode != NULL && aFlightStatus != NULL)
    {
        printf("|%-10d|%-20s|%-20s|\n", aFlightCode->id, aFlightCode->code, aFlightStatus->description);

        auxReturn = 0;
    }

    return auxReturn;
}

int printFlightCodes(FlightCode* listFlightCode, int lenFlightCode, FlightStatus* listFlightStatus, int lenFlightStatus)
{
    int auxReturn = -1;
    int index;
    int i;

    if(listFlightCode != NULL && lenFlightCode > 0 && listFlightStatus != NULL && lenFlightStatus > 0)
    {
    	printf("\n");
		system("pause");
		system("cls");

		printf("\tLISTA DE VUELOS\n\n");

		printf("*----------*--------------------*--------------------*\n");
        printf("|%-10s|%-20s|%-20s|\n", "ID", "CODIGO", "ESTADO");
        printf("*----------*--------------------*--------------------*\n");

        for(i = 0; i < lenFlightCode; i++)
        {
        	index = findFlightStatusById(listFlightStatus, lenFlightStatus, listFlightCode[i].status);

            if(index > -1 && printAFlightCode(&listFlightCode[i], &listFlightStatus[index]))
            {
                break;
            }
        }

        printf("*----------*--------------------*--------------------*\n");

        if(i == lenFlightCode)
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int showReportsMenu(Passenger* listPass, int lenPass, FlightCode* listFlightCode, int lenFlightCode, TypePassenger* listTypePassenger, int lenTypePassenger, FlightStatus* listFlightStatus, int lenFlightStatus)
{
	int auxReturn = -1;

	int order;
    float priceAccumulator;
    int priceCounter;
    float averagePrice;
    int passengerCounter;
    int option;
    int flagReport = FALSE;
    int flagExit = FALSE;

    if(listPass != NULL && lenPass > 0 && listFlightCode != NULL && lenFlightCode > 0 && listTypePassenger != NULL && lenTypePassenger > 0 && listFlightStatus != NULL && lenFlightStatus > 0)
    {
        do
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tMENU DE INFORMES\n\n");
            printf("1. Lista de pasajeros ordenados por Apellido y Tipo de Pasajero\n");
            printf("2. Promedio de precios de pasajes\n");
            printf("3. Lista de pasajeros ordenados por Codigo de Vuelo y Estado de Vuelo ACTIVO\n");
            printf("4. Salir\n");

            if(!utn_getNumero(&option, "\nElija una opcion: ", "Error. Solo numeros enteros dentro del rango: ", 1, 4, 2))
            {
                switch(option)
                {
                    case 1:

                        if(!chooseSortOrder(&order) && !sortPassengers(listPass, lenPass, order))
                        {
                        	printf("\nOrdenamiento realizado correctamente\n");

                            if(!printPassengers(listPass, lenPass, listTypePassenger, lenTypePassenger))
                            {
                                printf("\nLista mostrada correctamente\n");

                                flagReport = TRUE;
                            }

                            else
                            {
                                printf("\nNo se pudo mostrar la lista\n");
                            }
                        }

                        else
                        {
                            printf("\nError en el ordenamiento\n");
                        }

                        break;

                    case 2:

                    	printf("\n");
                    	system("pause");
                    	system("cls");

                    	if(!accumulatePassagePrices(listPass, lenPass, &priceAccumulator) && !countPassagePrices(listPass, lenPass, &priceCounter) &&
                           !getAveragePrice(priceAccumulator, priceCounter, &averagePrice) && !countExceededPricesFromAverage(listPass, lenPass, averagePrice, &passengerCounter))
                        {
                            printf("\tINFORME DE PRECIOS DE PASAJES\n");

                    		printf("\nSuma de precios: %.2f - Cantidad de precios: %d\n", priceAccumulator, priceCounter);
                            printf("\nEl promedio de precios es: %.2f\n", averagePrice);

                            if(passengerCounter > 0)
                            {
                            	printf("\nCantidad de pasajeros que superan el precio promedio: %d\n", passengerCounter);
                            }

                            else
                            {
                            	printf("\nNo hay pasajeros que superen el precio promedio\n");
                            }

                            flagReport = TRUE;
                        }

                        else
                        {
                            printf("\nNo se pudo calcular el salario\n");
                        }

                        break;

                    case 3:

                    	if(!chooseSortOrder(&order) && !sortPassengersByCode(listPass, lenPass, listFlightCode, lenFlightCode, listFlightStatus, lenFlightStatus, order))
						{
							printf("\nOrdenamiento realizado correctamente\n");

							if(!printPassengersByStatus(listPass, lenPass, listFlightCode, lenFlightCode, listTypePassenger, lenTypePassenger, listFlightStatus, lenFlightStatus, 1))
							{
								printf("\nLista mostrada correctamente\n");

								flagReport = TRUE;
							}

							else
							{
								printf("\nNo se pudo mostrar la lista\n");
							}
						}

						else
						{
							printf("\nError en el ordenamiento\n");
						}

                    	break;

                    case 4:

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "\nError. Solo S o N: ") == 1)
                        {
                            printf("\nHa salido del menu de informes\n");

                            flagExit = TRUE;
                        }

                        break;
                }
            }

        } while(option != 4 || !flagExit);

        if(flagReport)
        {
        	auxReturn = 0;
        }
    }

    return auxReturn;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "Input.h"

int initPassengers(Passenger* list, int len)
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

int getEmptyIndex(Passenger* list, int len)
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

int arrayIsEmpty(Passenger* list, int len)
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

int hardCodePassengers(Passenger* list, int len, int* id)
{
    int auxReturn = -1;
    int index;
    int i;
    int quantity;
    int flag = FALSE;

    Passenger auxPassengers[] =
    {
		{0, "Jorge", "Diaz", 40000.50, "BD1200", 3, FALSE},
		{0, "Hector", "Fernandez", 50000.50, "BD1201", 2, FALSE},
		{0, "Juan", "Gomez", 60000.50, "BD1202", 2, FALSE},
		{0, "Ricardo", "Alvarez", 70000.50, "BD1203", 4, FALSE},
		{0, "Martin", "Gomez", 80000.50, "BD1202", 1, FALSE},
		{0, "Jose", "Diaz", 90000.50, "BD1203", 3, FALSE},
		{0, "Lautaro", "Martinez", 100000.50, "BD1204", 3, FALSE},
		{0, "Roberto", "Suarez", 200000.50, "BD1206", 4, FALSE}
    };

    if(list != NULL && len > 0 && id != NULL)
    {
    	quantity = sizeof(auxPassengers) / sizeof(Passenger);

    	if(quantity <= len)
    	{
			for(i = 0; i < quantity; i++)
			{
				index = getEmptyIndex(list, len);

				if(index > -1)
				{
					list[index] = auxPassengers[i];
					list[index].id = *id;

					(*id)++;

					flag = TRUE;
				}

				else
				{
					break;
				}
			}

			if(flag)
			{
				auxReturn = 0;
			}
    	}
    }

    return auxReturn;
}

int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, char flightCode[], int typePassenger)
{
    int auxReturn = -1;
    int index;

    if(list != NULL && len > 0 && id > 0 && name != NULL && lastName != NULL && price > 0 && flightCode != NULL && typePassenger > 0)
    {
        index = getEmptyIndex(list, len);

        if(index > -1)
        {
            list[index].id = id;

            strncpy(list[index].name, name, NAME_LEN);
            strncpy(list[index].lastName, lastName, LAST_NAME_LEN);
            list[index].price = price;
            strncpy(list[index].flightCode, flightCode, FLIGHT_CODE_LEN);
            list[index].typePassenger = typePassenger;

            list[index].isEmpty = FALSE;

            auxReturn = 0;
        }
    }

    return auxReturn;
}

int findPassengerById(Passenger* list, int len, int id)
{
    int index = -1;
    int i;

    if(list != NULL && len > 0 && id > 0)
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

int compareString(char* a, char* b, int length)
{
    int auxReturn = -2;
    int auxCmp;

    if(a != NULL && b != NULL && length > 0)
    {
        auxCmp = strncmp(a, b, length);

        if(auxCmp < 0)
        {
            auxReturn = -1;
        }

        else if(auxCmp == 0)
        {
            auxReturn = 0;
        }

        else
        {
            auxReturn = 1;
        }
    }

    return auxReturn;
}

int compareInt(int a, int b)
{
    int auxReturn = -2;

    if(a > 0 && b > 0)
    {
        if(a < b)
        {
            auxReturn = -1;
        }

        else if(a == b)
        {
            auxReturn = 0;
        }

        else
        {
            auxReturn = 1;
        }
    }

    return auxReturn;
}

int swapPassengers(Passenger* a, Passenger* b)
{
    int auxReturn = -1;
    Passenger temp;

    if(a != NULL && b != NULL)
    {
        temp = *a;
        *a = *b;
        *b = temp;

        auxReturn = 0;
    }

    return auxReturn;
}

int sortPassengers(Passenger* list, int len, int order)
{
    int auxReturn = -1;
    int i;
    int auxLen;
    int auxCmp;
    int flagSwap;

    if(list != NULL && len > 0 && (order == UP || order == DOWN))
    {
    	auxLen = len;

        do
        {
            flagSwap = FALSE;

            for(i = 0; i < auxLen - 1; i++)
            {
                if(list[i].isEmpty == FALSE && list[i + 1].isEmpty == FALSE)
                {
					auxCmp = compareString(list[i].lastName, list[i + 1].lastName, LAST_NAME_LEN);

					if((auxCmp == order - !order || (!auxCmp && compareInt(list[i].typePassenger, list[i + 1].typePassenger) == order - !order)) &&
					   !swapPassengers(&list[i], &list[i + 1]))
					{
						flagSwap = TRUE;
					}
                }
            }

            auxLen--;

        } while(flagSwap);

        auxReturn = 0;
    }

    return auxReturn;
}

int chooseSortOrder(int* order)
{
	int auxReturn = -1;
	char option;

    if(order != NULL)
    {
		printf("\n");
		system("pause");
		system("cls");

		printf("\tSENTIDO DE ORDENAMIENTO\n\n");
		printf("A. Orden Ascendente\n");
		printf("B. Orden Descendente\n");

		if(!utn_getCaracter(&option, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'B', 2))
		{
			switch(option)
			{
				case 'A':

					*order = 1;

					break;

				case 'B':

					*order = 0;

					break;
			}

			auxReturn = 0;
		}
    }

    return auxReturn;
}

int accumulatePassagePrices(Passenger* list, int len, float* accumulator)
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
                *accumulator += list[i].price;
            }
        }

        auxReturn = 0;
    }

    return auxReturn;
}

int countPassagePrices(Passenger* list, int len, int* counter)
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

int getAveragePrice(float accumulator, int counter, float* average)
{
    int auxReturn = -1;

    if(accumulator > 0 && counter > 0 && average != NULL)
    {
		*average = accumulator / counter;

		auxReturn = 0;
    }

    return auxReturn;
}

int countExceededPricesFromAverage(Passenger* list, int len, float average, int* counter)
{
    int auxReturn = -1;
    int i;

    if(list != NULL && len > 0 && average > 0 && counter != NULL)
    {
        *counter = 0;

		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].price > average)
			{
				(*counter)++;
			}
		}

		auxReturn = 0;
    }

    return auxReturn;
}

int showPassengersMenu(int* option)
{
	int auxReturn = -1;

	if(option != NULL)
	{
		printf("\tMENU DE PASAJEROS\n\n");
		printf("1. Altas\n");
		printf("2. Modificar\n");
		printf("3. Baja\n");
		printf("4. Informar\n");
		printf("5. Alta Forzada de Pasajeros\n");
		printf("6. Salir\n");

		if(!utn_getNumero(option, "\nElija una opcion: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 6, 2))
		{
			auxReturn = 0;
		}
	}

	return auxReturn;
}

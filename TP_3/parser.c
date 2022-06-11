#include <stdio.h>
#include <stdlib.h>
#include "Passenger.h"
#include "parser.h"

int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger, int* id)
{
	int auxReturn = -1;
	int flag = 0;

	char idStr[BUFFER_LEN_PAR];
	char nombreStr[BUFFER_LEN_PAR];
	char apellidoStr[BUFFER_LEN_PAR];
	char precioStr[BUFFER_LEN_PAR];
	char codigoVueloStr[BUFFER_LEN_PAR];
	char tipoPasajeroStr[BUFFER_LEN_PAR];
	char estadoVueloStr[BUFFER_LEN_PAR];

	Passenger* this = NULL;
	int auxId;

	if(pFile != NULL && pArrayListPassenger != NULL && id != NULL)
	{
		do
		{
			if(fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, estadoVueloStr) == 7)
			{
				this = Passenger_newParametrosTxt(idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, estadoVueloStr);

				if(this != NULL)
				{
					auxId = atoi(idStr);

					if(auxId > *id)
					{
						*id = auxId + 1;
					}

					ll_add(pArrayListPassenger, this);

					flag = 1;
				}
			}

		} while(!feof(pFile));

		if(flag)
		{
			auxReturn = 0;
		}
	}

	return auxReturn;
}


int parser_PassengerFromBinary(FILE* pFile, LinkedList* pArrayListPassenger, int* id)
{
	int auxReturn = -1;
	int flag = 0;

	Passenger* this = NULL;
	int auxId;

	if(pFile != NULL && pArrayListPassenger != NULL && id != NULL)
	{
		do
		{
			this = Passenger_new();

			if(this != NULL)
			{
				if(fread(this, sizeof(Passenger), 1, pFile) == 1)
				{
					if(!Passenger_getId(this, &auxId) && auxId > *id)
					{
						*id = auxId + 1;
					}

					ll_add(pArrayListPassenger, this);

					flag = 1;
				}

				else
				{
					Passenger_delete(this);
				}
			}

		} while(!feof(pFile));

		if(flag)
		{
			auxReturn = 0;
		}
	}

	return auxReturn;
}

#include <stdio.h>
#include <stdlib.h>
#include "Passenger.h"
#include "Serializer.h"

int serializer_PassengerToText(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int auxReturn = -1;
	int length;
	int i;

	Passenger* this = NULL;

	char buffer[7][BUFFER_LEN_SER];

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		length = ll_len(pArrayListPassenger);

		if(length > 0)
		{
			fprintf(pFile, "id,name,lastName,price,flightCode,typePassenger,statusFlight\n");

			for(i = 0; i < length; i++)
			{
				this = (Passenger*) ll_get(pArrayListPassenger, i);

				if(this != NULL && !Passenger_getIdTxt(this, buffer[0]) && !Passenger_getNombre(this, buffer[1]) &&
				   !Passenger_getApellido(this, buffer[2]) && !Passenger_getPrecioTxt(this, buffer[3]) &&
				   !Passenger_getCodigoVuelo(this, buffer[4]) && !Passenger_getTipoPasajero(this, buffer[5]) &&
				   !Passenger_getEstadoVuelo(this, buffer[6]))
				{
					fprintf(pFile, "%s,%s,%s,%s,%s,%s,%s\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);
				}

				else
				{
					break;
				}
			}

			if(i == length)
			{
				auxReturn = 0;
			}
		}
	}

	return auxReturn;
}

int serializer_PassengerToBinary(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int auxReturn = -1;
	int length;
	int i;

	Passenger* this = NULL;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		length = ll_len(pArrayListPassenger);

		if(length > 0)
		{
			for(i = 0; i < length; i++)
			{
				this = (Passenger*) ll_get(pArrayListPassenger, i);

				if(this == NULL || fwrite(this, sizeof(Passenger), 1, pFile) != 1)
				{
					break;
				}
			}

			if(i == length)
			{
				auxReturn = 0;
			}
		}
	}

	return auxReturn;
}

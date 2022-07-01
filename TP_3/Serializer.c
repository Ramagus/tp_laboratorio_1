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

	char auxId[BUFFER_LEN_SER];
	char auxNombre[BUFFER_LEN_SER];
	char auxApellido[BUFFER_LEN_SER];
	char auxPrecio[BUFFER_LEN_SER];
	char auxCodigoVuelo[BUFFER_LEN_SER];
	char auxTipoPasajero[BUFFER_LEN_SER];
	char auxEstadoVuelo[BUFFER_LEN_SER];

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		length = ll_len(pArrayListPassenger);

		if(length > 0)
		{
			fprintf(pFile, "id,name,lastName,price,flightCode,typePassenger,statusFlight\n");

			for(i = 0; i < length; i++)
			{
				this = (Passenger*) ll_get(pArrayListPassenger, i);

				if(this != NULL && !Passenger_getIdTxt(this, auxId) && !Passenger_getNombre(this, auxNombre) &&
				   !Passenger_getApellido(this, auxApellido) && !Passenger_getPrecioTxt(this, auxPrecio) &&
				   !Passenger_getCodigoVuelo(this, auxCodigoVuelo) && !Passenger_getTipoPasajero(this, auxTipoPasajero) &&
				   !Passenger_getEstadoVuelo(this, auxEstadoVuelo))
				{
					fprintf(pFile, "%s,%s,%s,%s,%s,%s,%s\n", auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxTipoPasajero);
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

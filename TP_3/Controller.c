#include <stdio.h>
#include <stdlib.h>
#include "Passenger.h"
#include "parser.h"
#include "Serializer.h"
#include "Controller.h"

int controller_loadFromText(char* path, LinkedList* pArrayListPassenger, int* id)
{
	int auxReturn = -1;

	FILE* pFile = NULL;

	if(path != NULL && pArrayListPassenger != NULL && id != NULL)
	{
		pFile = fopen(path, "r");

		if(pFile != NULL)
		{
			if(!parser_PassengerFromText(pFile, pArrayListPassenger, id))
			{
				auxReturn = 0;
			}

			fclose(pFile);
		}
	}

    return auxReturn;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListPassenger, int* id)
{
	int auxReturn = -1;

	FILE* pFile = NULL;

	if(path != NULL && pArrayListPassenger != NULL && id != NULL)
	{
		pFile = fopen(path, "rb");

		if(pFile != NULL)
		{
			if(!parser_PassengerFromBinary(pFile, pArrayListPassenger, id))
			{
				auxReturn = 0;
			}

			fclose(pFile);
		}
	}

	return auxReturn;
}

int controller_addPassenger(LinkedList* pArrayListPassenger, int* id)
{
	int auxReturn = -1;

	if(pArrayListPassenger != NULL && id != NULL && !Passenger_add(pArrayListPassenger, id))
	{
		auxReturn = 0;
	}

    return auxReturn;
}

int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int auxReturn = -1;

	if(pArrayListPassenger != NULL && !Passenger_edit(pArrayListPassenger))
	{
		auxReturn = 0;
	}

	return auxReturn;
}

int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int auxReturn = -1;

	if(pArrayListPassenger != NULL && !Passenger_remove(pArrayListPassenger))
	{
		auxReturn = 0;
	}

	return auxReturn;
}

int controller_listPassenger(LinkedList* pArrayListPassenger)
{
	int auxReturn = -1;

	if(pArrayListPassenger != NULL && !Passenger_listPassenger(pArrayListPassenger))
	{
		auxReturn = 0;
	}

	return auxReturn;
}

int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int auxReturn = -1;

	if(pArrayListPassenger != NULL && !Passenger_sort(pArrayListPassenger))
	{
		auxReturn = 0;
	}

	return auxReturn;
}

int controller_saveAsText(char* path, LinkedList* pArrayListPassenger)
{
	int auxReturn = -1;

	FILE* pFile = NULL;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "w");

		if(pFile != NULL)
		{
			if(!serializer_PassengerToText(pFile, pArrayListPassenger))
			{
				auxReturn = 0;
			}

			fclose(pFile);
		}
	}

	return auxReturn;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListPassenger)
{
	int auxReturn = -1;

	FILE* pFile = NULL;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "wb");

		if(pFile != NULL)
		{
			if(!serializer_PassengerToBinary(pFile, pArrayListPassenger))
			{
				auxReturn = 0;
			}

			fclose(pFile);
		}
	}

	return auxReturn;
}

int controller_fileExists(char* path, char* mode)
{
    int auxReturn = -1;

    FILE* pFile = NULL;

    if(path != NULL && mode != NULL)
    {
        auxReturn = 0;

        pFile = fopen(path, mode);

        if(pFile != NULL)
        {
            auxReturn = 1;

            fclose(pFile);
        }
    }

    return auxReturn;
}

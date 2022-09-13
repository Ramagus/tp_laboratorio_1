#include <stdio.h>
#include <stdlib.h>
#include "Passenger.h"
#include "parser.h"

int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger, int* id)
{
	int auxReturn = -1;
	int flag = 0;
	int auxId;

	char buffer[7][BUFFER_LEN_PAR];

	Passenger* this = NULL;

	if(pFile != NULL && pArrayListPassenger != NULL && id != NULL)
	{
		do
		{
			this = Passenger_new();

			if(!Passenger_delete(this))
			{
				this = NULL;

				if(fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]) == 7)
				{
					this = Passenger_newParametrosTxt(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);

					if(this != NULL)
					{
						if(!ll_add(pArrayListPassenger, this))
						{
							auxId = atoi(buffer[0]);

							if(auxId > *id)
							{
								*id = auxId + 1;
							}

							flag = 1;
						}

						else
						{
							Passenger_delete(this);
							this = NULL;

							break;
						}
					}
				}
			}

			else
			{
				break;
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
	int flagParse = 0;
	int flagRead;
	int auxId;

	Passenger* this = NULL;

	if(pFile != NULL && pArrayListPassenger != NULL && id != NULL)
	{
		do
		{
			this = Passenger_new();

			if(this != NULL)
			{
				flagRead = 0;

				if(fread(this, sizeof(Passenger), 1, pFile) == 1)
				{
					flagRead = 1;
				}

				if(flagRead && !ll_add(pArrayListPassenger, this))
				{
					if(!Passenger_getId(this, &auxId) && auxId > *id)
					{
						*id = auxId + 1;
					}

					flagParse = 1;
				}

				else
				{
					Passenger_delete(this);
					this = NULL;

					if(flagRead)
					{
						break;
					}
				}
			}

			else
			{
				break;
			}

		} while(!feof(pFile));

		if(flagParse)
		{
			auxReturn = 0;
		}
	}

	return auxReturn;
}

#include <stdio.h>
#include <stdlib.h>
#include "FlightStatus.h"

int hardCodeFlightStatus(FlightStatus* list, int len, int* id)
{
    int auxReturn = -1;
    int i;
    int quantity;

    FlightStatus auxFlightStatus[] =
    {
		{0, "ACTIVO"},
		{0, "CANCELADO"},
		{0, "DEMORADO"},
		{0, "POSTERGADO"}
    };

    if(list != NULL && len > 0 && id != NULL)
    {
    	quantity = sizeof(auxFlightStatus) / sizeof(FlightStatus);

    	if(quantity <= len)
    	{
			for(i = 0; i < quantity; i++)
			{
				list[i] = auxFlightStatus[i];
				list[i].id = *id;

				(*id)++;
			}

			auxReturn = 0;
    	}
    }

    return auxReturn;
}

int findFlightStatusById(FlightStatus* list, int len, int id)
{
    int index = -1;
    int i;

    if(list != NULL && len > 0 && id > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].id == id)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FlightCode.h"

int hardCodeFlightCodes(FlightCode* list, int len, int* id)
{
    int auxReturn = -1;
    int i;
    int quantity;

    FlightCode auxFlightCodes[] =
    {
		{0, "BD1200", 2},
		{0, "BD1201", 2},
		{0, "BD1202", 1},
		{0, "BD1203", 1},
		{0, "BD1204", 4},
		{0, "BD1205", 4},
		{0, "BD1206", 3},
		{0, "BD1207", 3}
    };

    if(list != NULL && len > 0 && id != NULL)
    {
    	quantity = sizeof(auxFlightCodes) / sizeof(FlightCode);

    	if(quantity <= len)
    	{
			for(i = 0; i < quantity; i++)
			{
				list[i] = auxFlightCodes[i];
				list[i].id = *id;

				(*id)++;
			}

			auxReturn = 0;
    	}
    }

    return auxReturn;
}

int findFlightCodeById(FlightCode* list, int len, int id)
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

int findFlightCodeByCode(FlightCode* list, int len, char code[])
{
    int index = -1;
    int i;

    if(list != NULL && len > 0 && code != NULL)
    {
        for(i = 0; i < len; i++)
        {
            if(strncmp(list[i].code, code, CODE_LEN) == 0)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}

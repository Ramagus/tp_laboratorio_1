#include <stdio.h>
#include <stdlib.h>
#include "TypePassenger.h"

int hardCodeTypePassengers(TypePassenger* list, int len, int* id)
{
    int auxReturn = -1;
    int i;
    int quantity;

    TypePassenger auxTypePassengers[] =
    {
		{0, "Primera clase"},
		{0, "Clase ejecutiva"},
		{0, "Clase premium"},
		{0, "Clase turista"}
    };

    if(list != NULL && len > 0 && id != NULL)
    {
    	quantity = sizeof(auxTypePassengers) / sizeof(TypePassenger);

    	if(quantity <= len)
    	{
			for(i = 0; i < quantity; i++)
			{
				list[i] = auxTypePassengers[i];
				list[i].id = *id;

				(*id)++;
			}

			auxReturn = 0;
    	}
    }

    return auxReturn;
}

int findTypePassengerById(TypePassenger* list, int len, int id)
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

int printATypePassenger(TypePassenger* aTypePassenger)
{
    int auxReturn = -1;

    if(aTypePassenger != NULL)
    {
        printf("%d %19s\n", aTypePassenger->id, aTypePassenger->description);

        auxReturn = 0;
    }

    return auxReturn;
}

int printTypePassengers(TypePassenger* list, int len)
{
    int auxReturn = -1;
    int i;

    if(list != NULL && len > 0)
    {
    	printf("\n");
		system("pause");
		system("cls");

		printf("\tLISTA DE TIPOS DE VUELOS\n\n");
        printf("%s %18s\n\n", "ID", "DESCRIPCION");

        for(i = 0; i < len; i++)
        {
            if(printATypePassenger(&list[i]))
            {
                break;
            }
        }

        if(i == len)
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}

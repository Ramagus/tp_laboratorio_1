#include <stdio.h>
#include <stdlib.h>
#include "Nexus.h"
#include "Input.h"

#define PASS_ELEMENTS 2000
#define CODE_ELEMENTS 8
#define TYPE_ELEMENTS 4
#define STATUS_ELEMENTS 4

int main()
{
    setbuf(stdout, NULL);

    Passenger arrayPassengers[PASS_ELEMENTS];
    FlightCode arrayFlightCodes[CODE_ELEMENTS];
    TypePassenger arrayTypePassengers[TYPE_ELEMENTS];
	FlightStatus arrayFlightStatus[STATUS_ELEMENTS];

    int option;
    int auxId;
    char reply;

    int idPass = 1;
    int idCode = 1;
    int idType = 1;
    int idStatus = 1;

    if(!initPassengers(arrayPassengers, PASS_ELEMENTS) && !hardCodeFlightCodes(arrayFlightCodes, CODE_ELEMENTS, &idCode) &&
       !hardCodeTypePassengers(arrayTypePassengers, TYPE_ELEMENTS, &idType) && !hardCodeFlightStatus(arrayFlightStatus, STATUS_ELEMENTS, &idStatus))
    {
		do
		{
			if(!showPassengersMenu(&option))
			{
				switch(option)
				{
					case 1:

						printf("\n");
						system("pause");
						system("cls");

						printf("\tALTA DE PASAJERO\n");

						if(!loadPassenger(arrayPassengers, PASS_ELEMENTS, arrayFlightCodes, CODE_ELEMENTS, arrayTypePassengers, TYPE_ELEMENTS, arrayFlightStatus, STATUS_ELEMENTS, &idPass))
						{
							printf("\nPasajero cargado\n");
						}

						else
						{
							printf("\nError en alta de pasajero\n");
						}

						break;

					case 2:

						if(!arrayIsEmpty(arrayPassengers, PASS_ELEMENTS))
						{
							if(!printPassengers(arrayPassengers, PASS_ELEMENTS, arrayTypePassengers, TYPE_ELEMENTS) &&
							   !utn_getNumero(&auxId, "\nIngrese el ID del pasajero a modificar entre 1 y 10000: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 10000, 2) &&
							   !modifyPassenger(arrayPassengers, PASS_ELEMENTS, arrayFlightCodes, CODE_ELEMENTS, arrayTypePassengers, TYPE_ELEMENTS, arrayFlightStatus, STATUS_ELEMENTS, auxId))
							{
								printf("\nEl pasajero ha sido modificado\n");
							}

							else
							{
								printf("\nError en la modificacion\n");
							}
						}

						else
						{
							printf("\nNo hay pasajeros para modificar\n");
						}

						break;

					case 3:

						if(!arrayIsEmpty(arrayPassengers, PASS_ELEMENTS))
						{
							if(!printPassengers(arrayPassengers, PASS_ELEMENTS, arrayTypePassengers, TYPE_ELEMENTS) &&
							   !utn_getNumero(&auxId, "\nIngrese el ID del pasajero a eliminar entre 1 y 10000: ", "Error. Solo numeros enteros dentro del rango: ", 1, 10000, 2) &&
							   !removePassenger(arrayPassengers, PASS_ELEMENTS, arrayTypePassengers, TYPE_ELEMENTS, auxId))
							{
								printf("\nEl pasajero ha sido eliminado\n");
							}

							else
							{
								printf("\nError en la baja\n");
							}
						}

						else
						{
							printf("\nNo hay pasajeros para eliminar\n");
						}

						break;

					case 4:

						if(!arrayIsEmpty(arrayPassengers, PASS_ELEMENTS))
						{
							if(!showReportsMenu(arrayPassengers, PASS_ELEMENTS, arrayFlightCodes, CODE_ELEMENTS, arrayTypePassengers, TYPE_ELEMENTS, arrayFlightStatus, STATUS_ELEMENTS))
							{
								printf("\nMuestra correcta\n");
							}

							else
							{
								printf("\nError en la muestra de informes\n");
							}
						}

						else
						{
							printf("\nNo hay pasajeros para informar\n");
						}

						break;

					case 5:

						if(!hardCodePassengers(arrayPassengers, PASS_ELEMENTS, &idPass))
						{
							printf("\nAlta forzada realizada correctamente\n");
						}

						else
						{
							printf("\nError en el alta forzada\n");
						}

						break;

					case 6:

						if(verificarRespuesta(&reply, "\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
						{
							printf("\nHa salido del menu de pasajeros\n");
						}

						break;
				}
			}

			printf("\n");
			system("pause");
			system("cls");

		} while(option != 6 || reply == 'N');
    }

    else
    {
        printf("Error en la inicializacion\n");
    }

    return EXIT_SUCCESS;
}

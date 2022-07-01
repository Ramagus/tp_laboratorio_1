#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Input.h"

int main(void)
{
	setbuf(stdout, NULL);

	double kilometros;
	double precioAero;
	double precioLatam;
	double tarDebAero;
	double tarCredAero;
	double bitcoinAero;
	double unitarioAero;
	double tarDebLatam;
	double tarCredLatam;
	double bitcoinLatam;
	double unitarioLatam;
	double difPrecios;
	int flagKm = 0;
	int flagAero = 0;
	int flagLatam = 0;
	int flagCostos = 0;
	int flagExit = 0;
	int opcion;

	do
	{
		if(!mostrarMenuOpciones(kilometros, precioAero, precioLatam, flagKm, flagAero, flagLatam, &opcion))
		{
			switch(opcion)
			{
				case 1:

					if(!utn_getNumeroDouble(&kilometros, "\nIngrese kilometros entre 1 y 1000000: ", "Error. Solo numeros enteros dentro del rango: ", 1, 1000000, 2))
					{
						printf("\nKilometros cargados\n");

						flagKm = 1;
					}

					else
					{
						printf("\nNo se pudo cargar los kilometros\n");
					}

					break;

				case 2:

					if(flagKm)
					{
						if(!utn_getNumeroDouble(&precioAero, "\nIngrese precio de vuelo de Aerolineas entre 1 y 1000000: ", "Error. Solo numeros enteros dentro del rango: ", 1, 1000000, 2))
						{
							printf("\nPrecio de Aerolineas cargado\n");

							flagAero = 1;
						}

						else
						{
							printf("\nNo se pudo cargar el precio de Aerolineas\n");
						}

						if(flagAero)
						{
							if(!utn_getNumeroDouble(&precioLatam, "\nIngrese precio de vuelo de Latam entre 1 y 1000000: ", "Error. Solo numeros enteros dentro del rango: ", 1, 1000000, 2))
							{
								printf("\nPrecio de Latam cargado\n");

								flagLatam = 1;
							}

							else
							{
								printf("\nNo se pudo cargar el precio de Latam\n");
							}
						}

						else
						{
							printf("\nError en el ingreso de precios\n");
						}
					}

					else
					{
						printf("\nDebe ingresar los kilometros\n");
					}

					break;

				case 3:

					if(flagKm && flagAero && flagLatam)
					{
						if(!flagCostos)
						{
							if(!calcularCostosTodos(kilometros, precioAero, &tarDebAero, &tarCredAero, &bitcoinAero, &unitarioAero,
								                    precioLatam, &tarDebLatam, &tarCredLatam, &bitcoinLatam, &unitarioLatam, &difPrecios))
							{
								printf("\nCalculos realizados correctamente\n");

								flagCostos = 1;
							}

							else
							{
								printf("\nNo se pudo calcular los costos\n");
							}
						}

						else
						{
							printf("\nLos calculos ya se han realizado\n");
						}
					}

					else if(!flagKm && flagAero && flagLatam)
					{
						printf("\nDebe ingresar los kilometros\n");
					}

					else if(flagKm && !flagAero && !flagLatam)
					{
						printf("\nDebe ingresar los precios\n");
					}

					else
					{
						printf("\nDebe ingresar los kilometros y los precios\n");
					}

					break;

				case 4:

					if(flagCostos)
					{
						if(!informarResultados(kilometros, precioAero, tarDebAero, tarCredAero, bitcoinAero, unitarioAero,
								               precioLatam, tarDebLatam, tarCredLatam, bitcoinLatam, unitarioLatam, difPrecios))
						{
							flagKm = 0;
							flagAero = 0;
							flagLatam = 0;
							flagCostos = 0;
						}

						else
						{
							printf("\nNo se pudo informar los resultados\n");
						}
					}

					else
					{
						printf("\nDebe calcular los costos\n");
					}

					break;

				case 5:

					if(!hardcodearVuelos())
					{
						printf("\nCarga forzada correcta\n");
					}

					else
					{
						printf("\nNo se pudo realizar la carga forzada\n");
					}

					break;

				case 6:

					if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
					{
						printf("\nUsted ha salido del menu\n");

						flagExit = 1;
					}

					break;
			}

			printf("\n");
			system("pause");
			system("cls");
		}

		else
		{
			printf("No se pudo mostrar el menu\n");
			break;
		}

	} while(opcion != 6 || !flagExit);

	return EXIT_SUCCESS;
}

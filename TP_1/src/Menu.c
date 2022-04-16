#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Input.h"

#define KM 7090
#define PRECIO_AERO 162965
#define PRECIO_LATAM 159339

int mostrarMenuOpciones(float kilometros, float precioAero, float precioLatam, int flagKm, int flagAero, int flagLatam, int* opcion)
{
    int ret = -1;

    if(opcion != NULL)
    {
        printf("\tAGENCIA DE VIAJES\n");
        printf("\n1. Ingresar Kilometros (km = ");

        if(!flagKm)
        {
            printf("x)");
        }

        else
        {
            printf("%.2f)", kilometros);
        }

        printf("\n2. Ingresar Precio de Vuelos (Aerolineas = ");

        if(!flagAero)
        {
            printf("y");
        }

        else
        {
            printf("%.2f", precioAero);
        }

        printf(", Latam = ");

        if(!flagLatam)
        {
        	printf("z)");
        }

        else
        {
        	printf("%.2f)", precioLatam);
        }

        printf("\n3. Calcular todos los costos");
        printf("\n4. Informar resultados");
        printf("\n5. Carga forzada de datos");
        printf("\n6. Salir\n");

        if(!utn_getNumero(opcion, "\nElija una opcion: ", "Error. Solo numeros enteros dentro del rango: ", 1, 6, 2))
        {
            ret = 0;
        }
    }

    return ret;
}

int calcularCostosVuelo(float kilometros, float precio, float* tarDeb, float* tarCred, double* bitcoin, float* unitario)
{
	int ret = -1;
	float desc;
	float interes;

	if(kilometros > 0 && precio > 0 && tarDeb != NULL && tarCred != NULL && bitcoin != NULL && unitario != NULL)
	{
		desc = precio * 10 / 100;
		*tarDeb = precio - desc;

		interes = precio * 25 / 100;
		*tarCred = precio + interes;

		*bitcoin = precio / 4606954.55;

		*unitario = precio / kilometros;

		ret = 0;
	}

	return ret;
}

int calcularCostosTodos(float kilometros, float precioAero, float* tarDebAero, float* tarCredAero, double* bitcoinAero, float* unitarioAero,
                        float precioLatam, float* tarDebLatam, float* tarCredLatam, double* bitcoinLatam, float* unitarioLatam, float* difPrecios)
{
	int ret = -1;

	if(kilometros > 0 && precioAero > 0 && tarDebAero != NULL && tarCredAero != NULL && bitcoinAero != NULL && unitarioAero != NULL &&
	   precioLatam > 0 && tarDebLatam != NULL && tarCredLatam != NULL && bitcoinLatam != NULL && unitarioLatam != NULL && difPrecios != NULL &&
	   !calcularCostosVuelo(kilometros, precioAero, tarDebAero, tarCredAero, bitcoinAero, unitarioAero) &&
	   !calcularCostosVuelo(kilometros, precioLatam, tarDebLatam, tarCredLatam, bitcoinLatam, unitarioLatam))
	{
		*difPrecios = precioLatam - precioAero;

		if(*difPrecios < 0)
		{
			(*difPrecios) *= -1;
		}

		ret = 0;
	}

	return ret;
}

int mostrarCalculosVuelo(char* nombre, float precio, float tarDeb, float tarCred, double bitcoin, float unitario)
{
	int ret = -1;

	if(nombre != NULL && precio > 0 && tarDeb > 0 && tarCred > 0 && bitcoin > 0 && unitario > 0)
	{
		printf("\nPrecio %s: $%.2f\n", nombre, precio);

		printf("a) Precio con tarjeta de debito: $%.2f\n", tarDeb);
		printf("b) Precio con tarjeta de credito: $%.2f\n", tarCred);
		printf("c) Precio pagando con Bitcoin: %.8lf BTC\n", bitcoin);
		printf("d) Mostrar precio unitario: $%.2f\n", unitario);

		ret = 0;
	}

	return ret;
}

int informarResultados(float kilometros, float precioAero, float tarDebAero, float tarCredAero, double bitcoinAero, float unitarioAero,
		               float precioLatam, float tarDebLatam, float tarCredLatam, double bitcoinLatam, float unitarioLatam, float difPrecios)
{
	int ret = -1;

	if(kilometros > 0 && precioAero > 0 && tarDebAero > 0 && tarCredAero > 0 && bitcoinAero > 0 && unitarioAero > 0 &&
	   precioLatam > 0 && tarDebLatam > 0 && tarCredLatam > 0 && bitcoinLatam > 0 && unitarioLatam > 0)
	{
		printf("\n");
		system("pause");
		system("cls");

		printf("\tRESULTADOS\n\n");
		printf("KMs ingresados: %.2f\n", kilometros);

		if(!mostrarCalculosVuelo("Aerolineas", precioAero, tarDebAero, tarCredAero, bitcoinAero, unitarioAero) &&
		   !mostrarCalculosVuelo("Latam", precioLatam, tarDebLatam, tarCredLatam, bitcoinLatam, unitarioLatam))
		{
			printf("\nLa diferencia de precio es: $%.2f\n", difPrecios);

			ret = 0;
		}
	}

	return ret;
}

int hardcodearVuelos(void)
{
	int ret = -1;

	float tarDebAero;
	float tarCredAero;
	double bitcoinAero;
	float unitarioAero;
	float tarDebLatam;
	float tarCredLatam;
	double bitcoinLatam;
	float unitarioLatam;
	float difPrecios;

	if(!calcularCostosTodos(KM, PRECIO_AERO, &tarDebAero, &tarCredAero, &bitcoinAero, &unitarioAero,
			                PRECIO_LATAM, &tarDebLatam, &tarCredLatam, &bitcoinLatam, &unitarioLatam, &difPrecios) &&
	   !informarResultados(KM, PRECIO_AERO, tarDebAero, tarCredAero, bitcoinAero, unitarioAero,
						   PRECIO_LATAM, tarDebLatam, tarCredLatam, bitcoinLatam, unitarioLatam, difPrecios))
	{
		ret = 0;
	}

	return ret;
}

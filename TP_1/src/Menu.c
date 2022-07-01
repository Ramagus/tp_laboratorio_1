#include <stdio.h>
#include <stdlib.h>
#include "Calculadora.h"
#include "Input.h"
#include "Menu.h"

#define KM 7090
#define PRECIO_AERO 162965
#define PRECIO_LATAM 159339

int mostrarMenuOpciones(double kilometros, double precioAero, double precioLatam, int flagKm, int flagAero, int flagLatam, int* opcion)
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
            printf("%.2lf)", kilometros);
        }

        printf("\n2. Ingresar Precio de Vuelos (Aerolineas = ");

        if(!flagAero)
        {
            printf("y");
        }

        else
        {
            printf("%.2lf", precioAero);
        }

        printf(", Latam = ");

        if(!flagLatam)
        {
        	printf("z)");
        }

        else
        {
        	printf("%.2lf)", precioLatam);
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

int calcularCostosVuelo(double kilometros, double precio, double* tarDeb, double* tarCred, double* bitcoin, double* unitario)
{
	int ret = -1;
	double valorPorcentaje;
	double desc;
	double interes;

	if(kilometros > 0 && precio > 0 && tarDeb != NULL && tarCred != NULL && bitcoin != NULL && unitario != NULL &&
	   !dividir(10, 100, &valorPorcentaje) && !multiplicar(precio, valorPorcentaje, &desc) && !restar(precio, desc, tarDeb) &&
	   !dividir(25, 100, &valorPorcentaje) && !multiplicar(precio, valorPorcentaje, &interes) && !sumar(precio, interes, tarCred) &&
	   !dividir(precio, 4606954.55, bitcoin) && !dividir(precio, kilometros, unitario))
	{
		ret = 0;
	}

	return ret;
}

int calcularCostosTodos(double kilometros, double precioAero, double* tarDebAero, double* tarCredAero, double* bitcoinAero, double* unitarioAero,
                        double precioLatam, double* tarDebLatam, double* tarCredLatam, double* bitcoinLatam, double* unitarioLatam, double* difPrecios)
{
	int ret = -1;

	if(kilometros > 0 && precioAero > 0 && tarDebAero != NULL && tarCredAero != NULL && bitcoinAero != NULL && unitarioAero != NULL &&
	   precioLatam > 0 && tarDebLatam != NULL && tarCredLatam != NULL && bitcoinLatam != NULL && unitarioLatam != NULL && difPrecios != NULL &&
	   !calcularCostosVuelo(kilometros, precioAero, tarDebAero, tarCredAero, bitcoinAero, unitarioAero) &&
	   !calcularCostosVuelo(kilometros, precioLatam, tarDebLatam, tarCredLatam, bitcoinLatam, unitarioLatam) &&
	   !restar(precioLatam, precioAero, difPrecios))
	{
		if(*difPrecios < 0)
		{
			multiplicar(*difPrecios, -1, difPrecios);
		}

		ret = 0;
	}

	return ret;
}

int mostrarCalculosVuelo(char* nombre, double precio, double tarDeb, double tarCred, double bitcoin, double unitario)
{
	int ret = -1;

	if(nombre != NULL && precio > 0 && tarDeb > 0 && tarCred > 0 && bitcoin > 0 && unitario > 0)
	{
		printf("\nPrecio %s: $%.2lf\n", nombre, precio);

		printf("a) Precio con tarjeta de debito: $%.2lf\n", tarDeb);
		printf("b) Precio con tarjeta de credito: $%.2lf\n", tarCred);
		printf("c) Precio pagando con Bitcoin: %.8lf BTC\n", bitcoin);
		printf("d) Mostrar precio unitario: $%.2lf\n", unitario);

		ret = 0;
	}

	return ret;
}

int informarResultados(double kilometros, double precioAero, double tarDebAero, double tarCredAero, double bitcoinAero, double unitarioAero,
		               double precioLatam, double tarDebLatam, double tarCredLatam, double bitcoinLatam, double unitarioLatam, double difPrecios)
{
	int ret = -1;

	if(kilometros > 0 && precioAero > 0 && tarDebAero > 0 && tarCredAero > 0 && bitcoinAero > 0 && unitarioAero > 0 &&
	   precioLatam > 0 && tarDebLatam > 0 && tarCredLatam > 0 && bitcoinLatam > 0 && unitarioLatam > 0)
	{
		printf("\n");
		system("pause");
		system("cls");

		printf("\tRESULTADOS\n\n");
		printf("KMs ingresados: %.2lf\n", kilometros);

		if(!mostrarCalculosVuelo("Aerolineas", precioAero, tarDebAero, tarCredAero, bitcoinAero, unitarioAero) &&
		   !mostrarCalculosVuelo("Latam", precioLatam, tarDebLatam, tarCredLatam, bitcoinLatam, unitarioLatam))
		{
			printf("\nLa diferencia de precio es: $%.2lf\n", difPrecios);

			ret = 0;
		}
	}

	return ret;
}

int hardcodearVuelos(void)
{
	int ret = -1;

	double tarDebAero;
	double tarCredAero;
	double bitcoinAero;
	double unitarioAero;
	double tarDebLatam;
	double tarCredLatam;
	double bitcoinLatam;
	double unitarioLatam;
	double difPrecios;

	if(!calcularCostosTodos(KM, PRECIO_AERO, &tarDebAero, &tarCredAero, &bitcoinAero, &unitarioAero,
			                PRECIO_LATAM, &tarDebLatam, &tarCredLatam, &bitcoinLatam, &unitarioLatam, &difPrecios) &&
	   !informarResultados(KM, PRECIO_AERO, tarDebAero, tarCredAero, bitcoinAero, unitarioAero,
						   PRECIO_LATAM, tarDebLatam, tarCredLatam, bitcoinLatam, unitarioLatam, difPrecios))
	{
		ret = 0;
	}

	return ret;
}

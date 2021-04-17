#include <stdio.h>
#include <math.h>
#include "Menu.h"
#include "Input.h"
#include "Calculadora.h"

int mostrarMenuOpciones(float numero1, float numero2, int flagNumero1, int flagNumero2, int* opcion)
{
    int ret = -1;

    if(opcion != NULL)
    {
        printf("\tCALCULADORA\n");
        printf("\n1. Ingresar 1er operando (A = ");

        if(flagNumero1 == 0)
        {
            printf("x)");
        }

        else
        {
            printf("%g)", numero1);
        }

        printf("\n2. Ingresar 2do operando (B = ");

        if(flagNumero2 == 0)
        {
            printf("y)");
        }

        else
        {
            printf("%g)", numero2);
        }

        printf("\n3. Calcular todas las operaciones");
        printf("\n4. Informar resultados");
        printf("\n5. Salir\n");

        if(utn_getNumero(opcion, "\nElija una opcion: ", "Error. Solo numeros enteros: ") == 0)
        {
            ret = 0;
        }
    }

    return ret;
}

int esEntero(float numero)
{
    int ret = 0;

    if(fmod(numero, 1) == 0)
    {
        ret = 1;
    }

    return ret;
}

int realizarOperaciones(float* numero1, float* numero2, float* resultSuma, float* resultResta,
						float* resultDivision, float* resultMultiplicacion, unsigned long int* resultFact1,
						unsigned long int* resultFact2, int* flagDiv, int* flagFact1, int* flagFact2)
{
    int ret = -1;

    int numFact1;
    int numFact2;

    if(numero1 != NULL && numero2 != NULL && resultSuma != NULL && resultResta != NULL &&
       resultDivision != NULL && resultMultiplicacion != NULL && resultFact1 != NULL &&
	   resultFact2 != NULL && flagDiv != NULL && flagFact1 != NULL && flagFact2 != NULL)
    {
        printf("\nSe realizaran las siguientes operaciones:\n\n");

        printf("a) Suma (A + B)\n");
        printf("b) Resta (A - B)\n");
        printf("c) Division (A / B)\n");
        printf("d) Multiplicacion (A * B)\n");
        printf("e) Factorial (A!)\n");
        printf("f) Factorial (B!)\n");

        sumar(*numero1, *numero2, resultSuma);
        restar(*numero1, *numero2, resultResta);

        if(!dividir(*numero1, *numero2, resultDivision))
        {
        	*flagDiv = 1;
        }

		multiplicar(*numero1, *numero2, resultMultiplicacion);

		if(esEntero(*numero1))
		{
			numFact1 = (int) *numero1;

			if(!factorial(numFact1, resultFact1))
			{
				*flagFact1 = 1;
			}
		}

		else
		{
			*flagFact1 = -1;
		}

		if(esEntero(*numero2))
		{
			numFact2 = (int) *numero2;

			if(!factorial(numFact2, resultFact2))
			{
				*flagFact2 = 1;
			}
		}

		else
		{
			*flagFact2 = -1;
		}

		ret = 0;
    }

    return ret;
}

void informarResultados(float resultSuma, float resultResta, float resultDivision, float resultMultiplicacion,
		                unsigned long int resultFact1, unsigned long int resultFact2,
                        int flagDiv, int flagFact1, int flagFact2)
{
    printf("\nSUMA (A + B): ");
    printf("El resultado de la suma es: %g\n", resultSuma);

    printf("\nRESTA (A - B): ");
    printf("El resultado de la resta es: %g\n", resultResta);

    printf("\nDIVISION (A / B): ");

    if(flagDiv == 0)
    {
    	printf("No se puede dividir por 0\n");
    }

    else
    {
    	printf("El resultado de la division es: %g\n", resultDivision);
    }

    printf("\nMULTIPLICACION (A * B): ");
    printf("El resultado de la multiplicacion es: %g\n", resultMultiplicacion);

    printf("\nFACTORIAL (A!): ");

    if(flagFact1 == -1)
    {
        printf("No se puede calcular el factorial de un numero decimal\n");
    }

    else if(flagFact1 == 0)
    {
    	printf("No se puede calcular el factorial de un numero entero negativo\n");
    }

	else
	{
		printf("El resultado del factorial de A es: %lu\n", resultFact1);
	}

    printf("\nFACTORIAL (B!): ");

    if(flagFact2 == -1)
    {
        printf("No se puede calcular el factorial de un numero decimal\n\n");
    }

    else if(flagFact2 == 0)
    {
        printf("No se puede calcular el factorial de un numero entero negativo\n\n");
    }

	else
	{
		printf("El resultado del factorial de B es: %lu\n\n", resultFact2);
	}
}

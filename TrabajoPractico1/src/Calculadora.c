#include <stdio.h>
#include "Calculadora.h"

int sumar(float x, float y, float* pResultado)
{
    int ret = -1;

    if(pResultado != NULL)
    {
        *pResultado = x + y;

        ret = 0;
    }

    return ret;
}

int restar(float x, float y, float* pResultado)
{
    int ret = -1;

    if(pResultado != NULL)
    {
        *pResultado = x - y;

        ret = 0;
    }

    return ret;
}

int dividir(float x, float y, float* pResultado)
{
    int ret = -1;

    if(y != 0 && pResultado != NULL)
    {
        *pResultado = x / y;

        ret = 0;
    }

    return ret;
}

int multiplicar(float x, float y, float* pResultado)
{
    int ret = -1;

    if(pResultado != NULL)
    {
        *pResultado = x * y;

        ret = 0;
    }

    return ret;
}

int factorial(int n, unsigned long int* pResultado)
{
    int ret = -1;
    int i;

    if(n >= 0 && pResultado != NULL)
    {
        *pResultado = 1;

        for(i = n; i >= 1; i--)
        {
        	(*pResultado) *= i;
        }

        ret = 0;
    }

    return ret;
}

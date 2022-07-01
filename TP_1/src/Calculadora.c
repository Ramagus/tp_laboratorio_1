#include <stdio.h>
#include "Calculadora.h"

int sumar(double x, double y, double* pResultado)
{
    int ret = -1;

    if(pResultado != NULL)
    {
        *pResultado = x + y;

        ret = 0;
    }

    return ret;
}

int restar(double x, double y, double* pResultado)
{
    int ret = -1;

    if(pResultado != NULL)
    {
        *pResultado = x - y;

        ret = 0;
    }

    return ret;
}

int dividir(double x, double y, double* pResultado)
{
    int ret = -1;

    if(y != 0 && pResultado != NULL)
    {
        *pResultado = x / y;

        ret = 0;
    }

    return ret;
}

int multiplicar(double x, double y, double* pResultado)
{
    int ret = -1;

    if(pResultado != NULL)
    {
        *pResultado = x * y;

        ret = 0;
    }

    return ret;
}

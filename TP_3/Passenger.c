#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "Passenger.h"
#define BUFFER_LEN 20


/** \brief Verifica si la cadena ingresada es numérica
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad máxima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es numérica, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int isInt(char* cadena, int limite);


/** \brief Verifica si la cadena ingresada es flotante
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad máxima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es flotante, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int isFloat(char* cadena, int limite);


/** \brief Verifica si la cadena ingresada es alfabética
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad máxima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es alfabética, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int isAlphabetical(char* cadena, int limite);


/** \brief Verifica si la cadena ingresada es alfanumérica
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad máxima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es alfanumérica, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int isAlphaNumerical(char* cadena, int limite);


/** \brief Verifica si el id es válido
 *
 * \param horasTrabajadas int Atributo a ser analizado
 *
 * \return int Retorna 1 si es válido, 0 si no lo es
 *
 */
static int isValidId(int id);


/** \brief Verifica si el precio es válido
 *
 * \param precio float Atributo a ser analizado
 *
 * \return int Retorna 1 si es válido, 0 si no lo es
 *
 */
static int isValidPrice(float precio);


/** \brief Establece el tipo de pasajero elegido
 *
 * \param tipoPasajero char* Lugar donde se guardará el tipo de pasajero elegido
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
static int chooseTypePassenger(char* tipoPasajero);


/** \brief Establece el estado de vuelo elegido
 *
 * \param estadoVuelo char* Lugar donde se guardará el estado de vuelo elegido
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
static int chooseFlightStatus(char* estadoVuelo);


/** \brief Imprime las opciones a elegir del menú de modificaciones
 *
 * \param this Passenger* Puntero al pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
static int showModificationsMenu(Passenger* this);


/** \brief Imprime los datos de un pasajero
 *
 * \param this Passenger* Puntero al pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
static int printAPassenger(Passenger* this);


/** \brief Compara los valores de dos int
 *
 * \param a int Primer int
 * \param b int Segundo int
 *
 * \return int (-2) si hubo un error
 *             (-1) si el primer int es menor al segundo int
 *             ( 0) si ambos int son iguales
 *             ( 1) si el primer int es mayor al segundo int
 *
 */
static int compareInt(int a, int b);


/** \brief Compara los valores de dos float
 *
 * \param a float Primer float
 * \param b float Segundo float
 *
 * \return int (-2) si hubo un error
 *             (-1) si el primer float es menor al segundo float
 *             ( 0) si ambos float son iguales
 *             ( 1) si el primer float es mayor al segundo float
 *
 */
static int compareFloat(float a, float b);


/** \brief Compara los valores de dos string
 *
 * \param a char* Primer string
 * \param b char* Segundo string
 * \param length int Longitud de String
 *
 * \return int (-2) si hubo un error
 *             (-1) si el primer string es menor al segundo string en su valor
 *             ( 0) si ambos string son iguales
 *             ( 1) si el primer string es mayor al segundo string en su valor
 *
 */
static int compareString(char* a, char* b, int length);


Passenger* Passenger_new(void)
{
	Passenger* this = NULL;

	this = (Passenger*) malloc(sizeof(Passenger));

	return this;
}

Passenger* Passenger_newParametros(int id, char* nombre, char* apellido, float precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo)
{
	Passenger* this = NULL;

	if(nombre != NULL && apellido != NULL && codigoVuelo != NULL && tipoPasajero != NULL && estadoVuelo != NULL)
	{
		this = Passenger_new();

		if(this != NULL && (Passenger_setId(this, id) || Passenger_setNombre(this, nombre) ||
		   Passenger_setApellido(this, apellido) || Passenger_setPrecio(this, precio) ||
		   Passenger_setCodigoVuelo(this, codigoVuelo) || Passenger_setTipoPasajero(this, tipoPasajero) ||
		   Passenger_setEstadoVuelo(this, estadoVuelo)))
		{
			Passenger_delete(this);
			this = NULL;
		}
	}

	return this;
}

Passenger* Passenger_newParametrosTxt(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
	Passenger* this = NULL;

	if(idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && codigoVueloStr != NULL && tipoPasajeroStr != NULL && estadoVueloStr != NULL)
	{
		this = Passenger_new();

		if(this != NULL && (Passenger_setIdTxt(this, idStr) || Passenger_setNombre(this, nombreStr) ||
		   Passenger_setApellido(this, apellidoStr) || Passenger_setPrecioTxt(this, precioStr) ||
		   Passenger_setCodigoVuelo(this, codigoVueloStr) || Passenger_setTipoPasajero(this, tipoPasajeroStr) ||
		   Passenger_setEstadoVuelo(this, estadoVueloStr)))
		{
			Passenger_delete(this);
			this = NULL;
		}
	}

	return this;
}

int Passenger_delete(Passenger* this)
{
	int auxReturn = -1;

	if(this != NULL)
	{
		free(this);

		auxReturn = 0;
	}

	return auxReturn;
}

int Passenger_setId(Passenger* this, int id)
{
	int auxReturn = -1;

	if(this != NULL && isValidId(id))
	{
		this->id = id;
		auxReturn = 0;
	}

	return auxReturn;
}

int Passenger_setIdTxt(Passenger* this, char* id)
{
	int auxReturn = -1;
	int auxId;

	if(this != NULL && id != NULL && isInt(id, BUFFER_LEN) == 1)
	{
		auxId = atoi(id);

		if(isValidId(auxId))
		{
			this->id = auxId;
			auxReturn = 0;
		}
	}

	return auxReturn;
}

int Passenger_setNombre(Passenger* this, char* nombre)
{
	int auxReturn = -1;

	if(this != NULL && nombre != NULL && isAlphabetical(nombre, NAME_LEN) == 1)
	{
		strncpy(this->nombre, nombre, NAME_LEN);
		auxReturn = 0;
	}

	return auxReturn;
}

int Passenger_setApellido(Passenger* this, char* apellido)
{
	int auxReturn = -1;

	if(this != NULL && apellido != NULL && isAlphabetical(apellido, LAST_NAME_LEN) == 1)
	{
		strncpy(this->apellido, apellido, LAST_NAME_LEN);
		auxReturn = 0;
	}

	return auxReturn;
}

int Passenger_setPrecio(Passenger* this, float precio)
{
	int auxReturn = -1;

	if(this != NULL && isValidPrice(precio))
	{
		this->precio = precio;
		auxReturn = 0;
	}

	return auxReturn;
}

int Passenger_setPrecioTxt(Passenger* this, char* precio)
{
	int auxReturn = -1;
	float auxPrecio;

	if(this != NULL && precio != NULL && isFloat(precio, BUFFER_LEN) == 1)
	{
		auxPrecio = atof(precio);

		if(isValidPrice(auxPrecio))
		{
			this->precio = auxPrecio;
			auxReturn = 0;
		}
	}

	return auxReturn;
}

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int auxReturn = -1;

	if(this != NULL && codigoVuelo != NULL && isAlphaNumerical(codigoVuelo, FLIGHT_CODE_LEN) == 1)
	{
		strncpy(this->codigoVuelo, codigoVuelo, FLIGHT_CODE_LEN);
		auxReturn = 0;
	}

	return auxReturn;
}

int Passenger_setTipoPasajero(Passenger* this, char* tipoPasajero)
{
	int auxReturn = -1;

	if(this != NULL && tipoPasajero != NULL && isAlphabetical(tipoPasajero, TYPE_LEN) == 1)
	{
		strncpy(this->tipoPasajero, tipoPasajero, TYPE_LEN);
		auxReturn = 0;
	}

	return auxReturn;
}

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo)
{
	int auxReturn = -1;

	if(this != NULL && estadoVuelo != NULL && isAlphabetical(estadoVuelo, STATUS_LEN) == 1)
	{
		strncpy(this->estadoVuelo, estadoVuelo, STATUS_LEN);
		auxReturn = 0;
	}

	return auxReturn;
}

int Passenger_getId(Passenger* this, int* id)
{
	int auxReturn = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		auxReturn = 0;
	}

	return auxReturn;
}

int Passenger_getIdTxt(Passenger* this, char* id)
{
	int auxReturn = -1;

	if(this != NULL && id != NULL)
	{
		snprintf(id, BUFFER_LEN, "%d", this->id);
		auxReturn = 0;
	}

	return auxReturn;
}

int Passenger_getNombre(Passenger* this, char* nombre)
{
	int auxReturn = -1;

	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre, NAME_LEN);
		auxReturn = 0;
	}

	return auxReturn;
}

int Passenger_getApellido(Passenger* this, char* apellido)
{
	int auxReturn = -1;

	if(this != NULL && apellido != NULL)
	{
		strncpy(apellido, this->apellido, LAST_NAME_LEN);
		auxReturn = 0;
	}

	return auxReturn;
}

int Passenger_getPrecio(Passenger* this, float* precio)
{
	int auxReturn = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		auxReturn = 0;
	}

	return auxReturn;
}

int Passenger_getPrecioTxt(Passenger* this, char* precio)
{
	int auxReturn = -1;

	if(this != NULL && precio != NULL)
	{
		snprintf(precio, BUFFER_LEN, "%.2f", this->precio);
		auxReturn = 0;
	}

	return auxReturn;
}

int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int auxReturn = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strncpy(codigoVuelo, this->codigoVuelo, FLIGHT_CODE_LEN);
		auxReturn = 0;
	}

	return auxReturn;
}

int Passenger_getTipoPasajero(Passenger* this, char* tipoPasajero)
{
	int auxReturn = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		strncpy(tipoPasajero, this->tipoPasajero, TYPE_LEN);
		auxReturn = 0;
	}

	return auxReturn;
}

int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo)
{
	int auxReturn = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		strncpy(estadoVuelo, this->estadoVuelo, STATUS_LEN);
		auxReturn = 0;
	}

	return auxReturn;
}

static int isInt(char* cadena, int limite)
{
    int retorno = -1;
    int i;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isdigit(cadena[i]))
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int isFloat(char* cadena, int limite)
{
    int retorno = -1;
    int i;
    int tienePunto = 0;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isdigit(cadena[i]))
            {
                if(cadena[i] == '.' && tienePunto == 0)
                {
                    tienePunto = 1;
                    continue;
                }

                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int isAlphabetical(char* cadena, int limite)
{
    int retorno = -1;
    int i;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isalpha(cadena[i]) && !isspace(cadena[i]) && cadena[i] != '-')
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int isAlphaNumerical(char* cadena, int limite)
{
    int retorno = -1;
    int i;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isalnum(cadena[i]) && !isspace(cadena[i]) && cadena[i] != '-')
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int isValidId(int id)
{
    int retorno = 0;

    if(id >= 1 && id <= 10000)
    {
        retorno = 1;
    }

    return retorno;
}

static int isValidPrice(float precio)
{
    int retorno = 0;

    if(precio >= 10000 && precio <= 500000)
    {
        retorno = 1;
    }

    return retorno;
}

static int chooseTypePassenger(char* tipoPasajero)
{
	int auxReturn = -1;
	int opcion;

	if(tipoPasajero != NULL)
	{
		printf("\n");
		system("pause");
		system("cls");

		printf("\t\tTIPOS DE PASAJERO\n\n");
		printf("1. First Class\n");
		printf("2. Executive Class\n");
		printf("3. Economy Class\n");

		if(!utn_getNumero(&opcion, "\nIngrese numero de tipo de pasajero: ", "Error. Solo numeros enteros dentro del rango: ", 1, 3, 2))
		{
			switch(opcion)
			{
				case 1:

					strncpy(tipoPasajero, "First Class", TYPE_LEN);

					break;

				case 2:

					strncpy(tipoPasajero, "Executive Class", TYPE_LEN);

					break;

				case 3:

					strncpy(tipoPasajero, "Economy Class", TYPE_LEN);

					break;
			}

			auxReturn = 0;
		}
	}

	return auxReturn;
}

static int chooseFlightStatus(char* estadoVuelo)
{
	int auxReturn = -1;
	int opcion;

	if(estadoVuelo != NULL)
	{
		printf("\n");
		system("pause");
		system("cls");

		printf("\t\tESTADOS DE VUELO\n\n");
		printf("1. Aterrizado\n");
		printf("2. En Horario\n");
		printf("3. En Vuelo\n");
		printf("4. Demorado\n");

		if(!utn_getNumero(&opcion, "\nIngrese numero de estado de vuelo: ", "Error. Solo numeros enteros dentro del rango: ", 1, 4, 2))
		{
			switch(opcion)
			{
				case 1:

					strncpy(estadoVuelo, "Aterrizado", STATUS_LEN);

					break;

				case 2:

					strncpy(estadoVuelo, "En Horario", STATUS_LEN);

					break;

				case 3:

					strncpy(estadoVuelo, "En Vuelo", STATUS_LEN);

					break;

				case 4:

					strncpy(estadoVuelo, "Demorado", STATUS_LEN);

					break;
			}

			auxReturn = 0;
		}
	}

	return auxReturn;
}

static int showModificationsMenu(Passenger* this)
{
    int auxReturn = -1;

    char auxNombre[NAME_LEN];
    char auxApellido[LAST_NAME_LEN];
    float auxPrecio;
    char auxCodigoVuelo[FLIGHT_CODE_LEN];
    char auxTipoPasajero[TYPE_LEN];
    char auxEstadoVuelo[STATUS_LEN];

    char option;

    int flagMod = 0;
    int flagExit = 0;

    if(this != NULL)
    {
        do
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tMENU DE MODIFICACION DE PASAJERO\n\n");
            printf("A. Nombre\n");
            printf("B. Apellido\n");
            printf("C. Precio de Pasaje\n");
            printf("D. Codigo de Vuelo\n");
            printf("E. Tipo de Pasajero\n");
            printf("F. Estado de Vuelo\n");
            printf("G. Salir\n");

            if(!utn_getCaracter(&option, "\nQue desea modificar?: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'G', 2))
            {
                switch(option)
                {
                    case 'A':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el nombre del pasajero? (S/N): ", "\nError. Solo S o N: ") == 1 &&
                           !utn_getAlfabetico(auxNombre, "\nIngrese nuevo nombre: ", "Error. Solo letras: ", 3, NAME_LEN, 2) &&
                           !utn_formatearCadena(auxNombre, NAME_LEN) && !Passenger_setNombre(this, auxNombre))
                        {
                            flagMod = 1;
                        }

                        break;

                    case 'B':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el apellido del pasajero? (S/N): ", "\nError. Solo S o N: ") == 1 &&
                           !utn_getAlfabetico(auxApellido, "\nIngrese nuevo apellido: ", "Error. Solo letras: ", 3, LAST_NAME_LEN, 2) &&
                           !utn_formatearCadena(auxApellido, LAST_NAME_LEN) && !Passenger_setApellido(this, auxApellido))
                        {
                            flagMod = 1;
                        }

                        break;

                    case 'C':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el precio de pasaje del pasajero? (S/N): ", "\nError. Solo S o N: ") == 1 &&
                           !utn_getNumeroFlotante(&auxPrecio, "\nIngrese nuevo precio de pasaje entre 10000 y 500000: ", "Error. Solo numeros flotantes dentro del rango: ", 10000, 500000, 2) &&
                           !Passenger_setPrecio(this, auxPrecio))
                        {
                            flagMod = 1;
                        }

                        break;

                    case 'D':

                    	if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar codigo de vuelo del pasajero? (S/N): ", "\nError. Solo S o N: ") == 1 &&
                    	   !utn_getAlfaNumerico(auxCodigoVuelo, "\nIngrese nuevo codigo de vuelo: ", "Error. Solo letras y/o numeros: ", 3, FLIGHT_CODE_LEN, 2) &&
                    	   strupr(auxCodigoVuelo) != NULL && !Passenger_setCodigoVuelo(this, auxCodigoVuelo))
                    	{
                    		flagMod = 1;
                    	}

                    	break;

                    case 'E':

                    	if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el tipo del pasajero? (S/N): ", "\nError. Solo S o N: ") == 1 &&
                    	   !chooseTypePassenger(auxTipoPasajero) && !Passenger_setTipoPasajero(this, auxTipoPasajero))
                    	{
                    		flagMod = 1;
                    	}

                    	break;

                    case 'F':

                    	if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el estado de vuelo del pasajero? (S/N): ", "\nError. Solo S o N: ") == 1 &&
                    	   !chooseFlightStatus(auxEstadoVuelo) && !Passenger_setEstadoVuelo(this, auxEstadoVuelo))
                    	{
                    		flagMod = 1;
                    	}

                    	break;

                    case 'G':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
                        {
                            printf("\nHa salido del menu de modificacion\n");

                            flagExit = 1;
                        }

                        break;
                }
            }

        } while(option != 'G' || !flagExit);

        if(flagMod)
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}

static int printAPassenger(Passenger* this)
{
    int auxReturn = -1;

    int auxId;
    char auxNombre[NAME_LEN];
    char auxApellido[LAST_NAME_LEN];
    float auxPrecio;
    char auxCodigoVuelo[FLIGHT_CODE_LEN];
    char auxTipoPasajero[TYPE_LEN];
    char auxEstadoVuelo[STATUS_LEN];

    if(this != NULL && !Passenger_getId(this, &auxId) && !Passenger_getNombre(this, auxNombre) &&
       !Passenger_getApellido(this, auxApellido) && !Passenger_getPrecio(this, &auxPrecio) &&
       !Passenger_getCodigoVuelo(this, auxCodigoVuelo) && !Passenger_getTipoPasajero(this, auxTipoPasajero) &&
	   !Passenger_getEstadoVuelo(this, auxEstadoVuelo))
    {
        printf("|%-10d|%-14s|%-14s|%-16.2f|%-16s|%-16s|%-16s|\n", auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);

        auxReturn = 0;
    }

    return auxReturn;
}

static int compareInt(int a, int b)
{
	int auxReturn = -2;

	if(a > 0 && b > 0)
	{
		if(a < b)
		{
			auxReturn = -1;
		}

		else if(a == b)
		{
			auxReturn = 0;
		}

		else
		{
			auxReturn = 1;
		}
	}

	return auxReturn;
}

static int compareFloat(float a, float b)
{
	int auxReturn = -2;

	if(a > 0 && b > 0)
	{
		if(a < b)
		{
			auxReturn = -1;
		}

		else if(a == b)
		{
			auxReturn = 0;
		}

		else
		{
			auxReturn = 1;
		}
	}

	return auxReturn;
}

static int compareString(char* a, char* b, int length)
{
	int auxReturn = -2;
	int auxCmp;

	if(a != NULL && b != NULL && length > 0)
	{
		auxCmp = strncmp(a, b, length);

		if(auxCmp < 0)
		{
			auxReturn = -1;
		}

		else if(auxCmp == 0)
		{
			auxReturn = 0;
		}

		else
		{
			auxReturn = 1;
		}
	}

	return auxReturn;
}

int Passenger_findPassengerById(LinkedList* pArrayListPassenger, int id, int* index)
{
    int auxReturn = -1;

    int length;
    int auxId;
    int i;

    Passenger* this = NULL;

    if(pArrayListPassenger != NULL && index != NULL)
    {
        length = ll_len(pArrayListPassenger);

        for(i = 0; i < length; i++)
        {
            this = (Passenger*) ll_get(pArrayListPassenger, i);

            if(this != NULL && !Passenger_getId(this, &auxId) && auxId == id)
            {
                *index = i;
                auxReturn = 0;
                break;
            }
        }
    }

    return auxReturn;
}

int Passenger_add(LinkedList* pArrayListPassenger, int* id)
{
    int auxReturn = -1;

    char auxNombre[NAME_LEN];
    char auxApellido[LAST_NAME_LEN];
    float auxPrecio;
    char auxCodigoVuelo[FLIGHT_CODE_LEN];
    char auxTipoPasajero[TYPE_LEN];
    char auxEstadoVuelo[STATUS_LEN];

    Passenger* this = NULL;

    if(pArrayListPassenger != NULL && id != NULL &&
       !utn_getAlfabetico(auxNombre, "\nIngrese nombre: ", "Error. Solo letras: ", 3, NAME_LEN, 2) &&
       !utn_formatearCadena(auxNombre, NAME_LEN) &&
	   !utn_getAlfabetico(auxApellido, "\nIngrese apellido: ", "Error. Solo letras: ", 3, LAST_NAME_LEN, 2) &&
	   !utn_formatearCadena(auxApellido, LAST_NAME_LEN) &&
	   !utn_getNumeroFlotante(&auxPrecio, "\nIngrese precio de pasaje entre 10000 y 500000: ", "Error. Solo numeros flotantes dentro del rango: ", 10000, 500000, 2) &&
	   !utn_getAlfaNumerico(auxCodigoVuelo, "\nIngrese codigo de vuelo: ", "Error. Solo letras y/o numeros: ", 3, FLIGHT_CODE_LEN, 2) &&
	   strupr(auxCodigoVuelo) != NULL && !chooseTypePassenger(auxTipoPasajero) && !chooseFlightStatus(auxEstadoVuelo))
    {
        this = Passenger_newParametros(*id, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);

        if(this != NULL && !ll_add(pArrayListPassenger, this))
        {
            (*id)++;

            auxReturn = 0;
        }
    }

    return auxReturn;
}

int Passenger_edit(LinkedList* pArrayListPassenger)
{
    int auxReturn = -1;
    int auxId;
    int index;

    Passenger* this = NULL;

    if(pArrayListPassenger != NULL && !Passenger_listPassenger(pArrayListPassenger) &&
       !utn_getNumero(&auxId, "\nIngrese el ID del pasajero a modificar entre 1 y 10000: ",
                              "Error. Solo numeros enteros dentro del rango: ", 1, 10000, 2) &&
       !Passenger_findPassengerById(pArrayListPassenger, auxId, &index))
    {
        this = (Passenger*) ll_get(pArrayListPassenger, index);

        if(this != NULL)
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tMODIFICACION DE PASAJERO\n\n");

            printf("*----------*----------------*------------*----------*------------------*------------------*------------------*\n");
			printf("|%-10s|%-16s|%-12s|%-10s|%-18s|%-18s|%-18s|\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "CODIGO DE VUELO", "TIPO DE PASAJERO", "ESTADO DE VUELO");
			printf("*----------*----------------*------------*----------*------------------*------------------*------------------*\n");
            printAPassenger(this);
            printf("*----------*----------------*------------*----------*------------------*------------------*------------------*\n");

            if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar a este pasajero? (S/N): ", "Error. Solo S/N: ") == 1 && !showModificationsMenu(this))
            {
                auxReturn = 0;
            }
        }
    }

    return auxReturn;
}

int Passenger_remove(LinkedList* pArrayListPassenger)
{
    int auxReturn = -1;
    int auxId;
    int index;

    Passenger* this = NULL;

    if(pArrayListPassenger != NULL && !Passenger_listPassenger(pArrayListPassenger) &&
       !utn_getNumero(&auxId, "\nIngrese el ID del pasajero a eliminar entre 1 y 10000: ",
                              "Error. Solo numeros enteros dentro del rango: ", 1, 10000, 2) &&
       !Passenger_findPassengerById(pArrayListPassenger, auxId, &index))
    {
        this = (Passenger*) ll_get(pArrayListPassenger, index);

        if(this != NULL)
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tBAJA DE PASAJERO\n\n");

            printf("*----------*----------------*------------*----------*------------------*------------------*------------------*\n");
			printf("|%-10s|%-16s|%-12s|%-10s|%-18s|%-18s|%-18s|\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "CODIGO DE VUELO", "TIPO DE PASAJERO", "ESTADO DE VUELO");
			printf("*----------*----------------*------------*----------*------------------*------------------*------------------*\n");
            printAPassenger(this);
            printf("*----------*----------------*------------*----------*------------------*------------------*------------------*\n");

            if(utn_respuestaEsAfirmativa("\nEsta seguro que desea eliminar a este pasajero? (S/N): ", "Error. Solo S/N: ") == 1)
            {
                Passenger_delete(this);
                this = NULL;

                ll_remove(pArrayListPassenger, index);

                auxReturn = 0;
            }
        }
    }

    return auxReturn;
}

int Passenger_listPassenger(LinkedList* pArrayListPassenger)
{
    int auxReturn = -1;
    int length;
    int i;

    Passenger* this = NULL;

    if(pArrayListPassenger != NULL)
    {
        length = ll_len(pArrayListPassenger);

        if(length > 0)
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tLISTA DE PASAJEROS\n\n");

            printf("*----------*--------------*--------------*----------------*----------------*----------------*----------------*\n");
            printf("|%-10s|%-14s|%-14s|%-16s|%-16s|%-16s|%-16s|\n", "ID", "NOMBRE", "APELLIDO", "PRECIO DE PASAJE", "CODIGO DE VUELO", "TIPO DE PASAJERO", "ESTADO DE VUELO");
            printf("*----------*--------------*--------------*----------------*----------------*----------------*----------------*\n");

            for(i = 0; i < length; i++)
            {
                this = (Passenger*) ll_get(pArrayListPassenger, i);

                if(printAPassenger(this))
                {
                    break;
                }
            }

            printf("*----------*--------------*--------------*----------------*----------------*----------------*----------------*\n");

            if(i == length)
            {
                auxReturn = 0;
            }
        }
    }

    return auxReturn;
}

int Passenger_clear(LinkedList* pArrayListPassenger)
{
    int auxReturn = -1;
    int length;
    int i;

    Passenger* this = NULL;

    if(pArrayListPassenger != NULL)
    {
        length = ll_len(pArrayListPassenger);

        for(i = 0; i < length; i++)
        {
            this = (Passenger*) ll_get(pArrayListPassenger, i);

            if(!Passenger_delete(this))
            {
                this = NULL;
            }

            else
            {
            	break;
            }
        }

        if(i == length)
        {
            ll_clear(pArrayListPassenger);
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int Passenger_chooseCriterionOrder(int (**pFunc)(void*, void*))
{
    int auxReturn = -1;
    char option;

    if(pFunc != NULL)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\t\tCRITERIO DE ORDENAMIENTO\n\n");
        printf("A. ID\n");
        printf("B. Nombre\n");
        printf("C. Apellido\n");
        printf("D. Precio de Pasaje\n");
        printf("E. Codigo de Vuelo\n");
        printf("F. Tipo de Pasajero\n");
        printf("G. Estado de Vuelo\n");

        if(!utn_getCaracter(&option, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'G', 2))
        {
            switch(option)
            {
                case 'A':

                    *pFunc = Passenger_compareById;

                    break;

                case 'B':

                    *pFunc = Passenger_compareByName;

                    break;

                case 'C':

                    *pFunc = Passenger_compareByLastName;

                    break;

                case 'D':

                    *pFunc = Passenger_compareByPrice;

                    break;

                case 'E':

                	*pFunc = Passenger_compareByFlightCode;

                	break;

                case 'F':

                	*pFunc = Passenger_compareByTypePassenger;

                	break;

                case 'G':

                	*pFunc = Passenger_compareByFlightStatus;

                	break;
            }

            auxReturn = 0;
        }
    }

    return auxReturn;
}

int Passenger_chooseSortOrder(int* order)
{
    int auxReturn = -1;
    char option;

    if(order != NULL)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\t\tSENTIDO DE ORDENAMIENTO\n\n");
        printf("A. Orden Ascendente\n");
        printf("B. Orden Descendente\n");

        if(!utn_getCaracter(&option, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'B', 2))
        {
            switch(option)
            {
                case 'A':

                    *order = 1;

                    break;

                case 'B':

                    *order = 0;

                    break;
            }

            auxReturn = 0;
        }
    }

    return auxReturn;
}

int Passenger_sort(LinkedList* pArrayListPassenger)
{
    int auxReturn = -1;

    int (*pFunc)(void*, void*) = NULL;
    int order;

    if(pArrayListPassenger != NULL && !Passenger_chooseCriterionOrder(&pFunc) && !Passenger_chooseSortOrder(&order))
    {
        printf("\nOrdenando... ");

        ll_sort(pArrayListPassenger, pFunc, order);

        auxReturn = 0;
    }

    return auxReturn;
}

int Passenger_compareById(void* pElement1, void* pElement2)
{
    int auxReturn = -3;

    Passenger* pPass1 = NULL;
    Passenger* pPass2 = NULL;

    int id1;
    int id2;

    if(pElement1 != NULL && pElement2 != NULL)
    {
        pPass1 = (Passenger*) pElement1;
        pPass2 = (Passenger*) pElement2;

        if(!Passenger_getId(pPass1, &id1) && !Passenger_getId(pPass2, &id2))
        {
            auxReturn = compareInt(id1, id2);
        }
    }

    return auxReturn;
}

int Passenger_compareByName(void* pElement1, void* pElement2)
{
    int auxReturn = -3;

    Passenger* pPass1 = NULL;
    Passenger* pPass2 = NULL;

    char nombre1[NAME_LEN];
    char nombre2[NAME_LEN];

    if(pElement1 != NULL && pElement2 != NULL)
    {
        pPass1 = (Passenger*) pElement1;
        pPass2 = (Passenger*) pElement2;

        if(!Passenger_getNombre(pPass1, nombre1) && !Passenger_getNombre(pPass2, nombre2))
        {
            auxReturn = compareString(nombre1, nombre2, NAME_LEN);
        }
    }

    return auxReturn;
}

int Passenger_compareByLastName(void* pElement1, void* pElement2)
{
    int auxReturn = -3;

    Passenger* pPass1 = NULL;
    Passenger* pPass2 = NULL;

    char apellido1[LAST_NAME_LEN];
    char apellido2[LAST_NAME_LEN];

    if(pElement1 != NULL && pElement2 != NULL)
    {
        pPass1 = (Passenger*) pElement1;
        pPass2 = (Passenger*) pElement2;

        if(!Passenger_getApellido(pPass1, apellido1) && !Passenger_getApellido(pPass2, apellido2))
        {
            auxReturn = compareString(apellido1, apellido2, LAST_NAME_LEN);
        }
    }

    return auxReturn;
}

int Passenger_compareByPrice(void* pElement1, void* pElement2)
{
    int auxReturn = -3;

    Passenger* pPass1 = NULL;
    Passenger* pPass2 = NULL;

    float precio1;
    float precio2;

    if(pElement1 != NULL && pElement2 != NULL)
    {
        pPass1 = (Passenger*) pElement1;
        pPass2 = (Passenger*) pElement2;

        if(!Passenger_getPrecio(pPass1, &precio1) && !Passenger_getPrecio(pPass2, &precio2))
        {
            auxReturn = compareFloat(precio1, precio2);
        }
    }

    return auxReturn;
}

int Passenger_compareByFlightCode(void* pElement1, void* pElement2)
{
    int auxReturn = -3;

    Passenger* pPass1 = NULL;
    Passenger* pPass2 = NULL;

    char codigoVuelo1[FLIGHT_CODE_LEN];
    char codigoVuelo2[FLIGHT_CODE_LEN];

    if(pElement1 != NULL && pElement2 != NULL)
    {
        pPass1 = (Passenger*) pElement1;
        pPass2 = (Passenger*) pElement2;

        if(!Passenger_getCodigoVuelo(pPass1, codigoVuelo1) && !Passenger_getCodigoVuelo(pPass2, codigoVuelo2))
        {
            auxReturn = compareString(codigoVuelo1, codigoVuelo2, FLIGHT_CODE_LEN);
        }
    }

    return auxReturn;
}

int Passenger_compareByTypePassenger(void* pElement1, void* pElement2)
{
    int auxReturn = -3;

    Passenger* pPass1 = NULL;
    Passenger* pPass2 = NULL;

    char tipoPasajero1[TYPE_LEN];
    char tipoPasajero2[TYPE_LEN];

    if(pElement1 != NULL && pElement2 != NULL)
    {
        pPass1 = (Passenger*) pElement1;
        pPass2 = (Passenger*) pElement2;

        if(!Passenger_getTipoPasajero(pPass1, tipoPasajero1) && !Passenger_getTipoPasajero(pPass2, tipoPasajero2))
        {
            auxReturn = compareString(tipoPasajero1, tipoPasajero2, TYPE_LEN);
        }
    }

    return auxReturn;
}

int Passenger_compareByFlightStatus(void* pElement1, void* pElement2)
{
    int auxReturn = -3;

    Passenger* pPass1 = NULL;
    Passenger* pPass2 = NULL;

    char estadoVuelo1[STATUS_LEN];
    char estadoVuelo2[STATUS_LEN];

    if(pElement1 != NULL && pElement2 != NULL)
    {
        pPass1 = (Passenger*) pElement1;
        pPass2 = (Passenger*) pElement2;

        if(!Passenger_getEstadoVuelo(pPass1, estadoVuelo1) && !Passenger_getEstadoVuelo(pPass2, estadoVuelo2))
        {
            auxReturn = compareString(estadoVuelo1, estadoVuelo2, STATUS_LEN);
        }
    }

    return auxReturn;
}

int Passenger_optionsMenu(int* option)
{
    int auxReturn = -1;

    if(option != NULL)
    {
        printf("\t\tMENU\n\n");
        printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n");
        printf("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario)\n");
        printf("3. Alta de pasajero\n");
        printf("4. Modificar datos de pasajero\n");
        printf("5. Baja de pasajero\n");
        printf("6. Listar pasajeros\n");
        printf("7. Ordenar pasajeros\n");
        printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n");
        printf("9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario)\n");
        printf("10. Salir\n");

        if(!utn_getNumero(option, "\nElija una opcion: ", "Error. Solo numeros enteros dentro del rango: ", 1, 10, 2))
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}

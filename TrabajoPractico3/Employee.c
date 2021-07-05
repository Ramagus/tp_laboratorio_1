#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "Controller.h"
#include "Employee.h"

#define BUFFER_LEN 10


/**
 * \brief Verifica si la cadena ingresada es numérica
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad máxima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es numérica, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int isInt(char* cadena, int limite);


/**
 * \brief Verifica si la cadena ingresada es flotante
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad máxima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es flotante, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int isFloat(char* cadena, int limite);


/**
 * \brief Verifica si la cadena ingresada es alfabética
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad máxima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es alfabética, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int isAlphabetical(char* cadena, int limite);


/**
 * \brief Verifica si el id es válido
 *
 * \param horasTrabajadas int Atributo a ser analizado
 *
 * \return int Retorna 1 si es válido, 0 si no lo es
 *
 */
static int isValidId(int id);

/**
 * \brief Verifica si las horas trabajadas son válidas
 *
 * \param horasTrabajadas int Atributo a ser analizado
 *
 * \return int Retorna 1 si es válido, 0 si no lo es
 *
 */
static int isValidWorkedHours(int horasTrabajadas);


/**
 * \brief Verifica si el sueldo es válido
 *
 * \param sueldo float Atributo a ser analizado
 *
 * \return int Retorna 1 si es válido, 0 si no lo es
 *
 */
static int isValidSalary(float sueldo);


/** \brief Imprime las opciones a elegir del menú de modificaciones
 *
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 * \param this Employee* Puntero al empleado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
static int showModificationsMenu(LinkedList* pArrayListEmployee, Employee* this);


/** \brief Imprime los datos de un empleado
 *
 * \param this Employee* Puntero al empleado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
static int printAnEmployee(Employee* this);


Employee* employee_new(void)
{
    Employee* this;

    this = (Employee*) malloc(sizeof(Employee));

    return this;
}

Employee* employee_newParametros(int id, char* nombre, int horasTrabajadas, float sueldo)
{
    Employee* this = NULL;

    if(nombre != NULL)
    {
        this = employee_new();

        if(this != NULL && (employee_setId(this, id) || employee_setNombre(this, nombre) ||
           employee_setHorasTrabajadas(this, horasTrabajadas) || employee_setSueldo(this, sueldo)))
        {
        	employee_delete(this);
        	this = NULL;
        }
    }

    return this;
}

Employee* employee_newParametrosTxt(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this = NULL;

    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        this = employee_new();

        if(this != NULL && (employee_setIdTxt(this, idStr) || employee_setNombre(this, nombreStr) ||
           employee_setHorasTrabajadasTxt(this, horasTrabajadasStr) || employee_setSueldoTxt(this, sueldoStr)))
        {
            employee_delete(this);
            this = NULL;
        }
    }

    return this;
}

int employee_delete(Employee* this)
{
    int auxReturn = -1;

    if(this != NULL)
    {
        free(this);

        auxReturn = 0;
    }

    return auxReturn;
}

int employee_setId(Employee* this, int id)
{
    int auxReturn = -1;

    if(this != NULL && isValidId(id))
    {
        this->id = id;
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_setIdTxt(Employee* this, char* id)
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

int employee_getId(Employee* this, int* id)
{
    int auxReturn = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_getIdTxt(Employee* this, char* id)
{
    int auxReturn = -1;

    if(this != NULL && id != NULL)
    {
        snprintf(id, BUFFER_LEN, "%d", this->id);
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_setNombre(Employee* this, char* nombre)
{
    int auxReturn = -1;

    if(this != NULL && nombre != NULL && isAlphabetical(nombre, NOMBRE_LEN) == 1)
    {
        strncpy(this->nombre, nombre, NOMBRE_LEN);
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int auxReturn = -1;

    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre, this->nombre, NOMBRE_LEN);
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int auxReturn = -1;

    if(this != NULL && isValidWorkedHours(horasTrabajadas))
    {
        this->horasTrabajadas = horasTrabajadas;
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas)
{
    int auxReturn = -1;
    int auxHorasTrabajadas;

    if(this != NULL && horasTrabajadas != NULL && isInt(horasTrabajadas, BUFFER_LEN) == 1)
    {
        auxHorasTrabajadas = atoi(horasTrabajadas);

        if(isValidWorkedHours(auxHorasTrabajadas))
        {
            this->horasTrabajadas = auxHorasTrabajadas;
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int auxReturn = -1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_getHorasTrabajadasTxt(Employee* this, char* horasTrabajadas)
{
    int auxReturn = -1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        snprintf(horasTrabajadas, BUFFER_LEN, "%d", this->horasTrabajadas);
        auxReturn = 0;
    }

    return auxReturn;
}


int employee_setSueldo(Employee* this, float sueldo)
{
    int auxReturn = -1;

    if(this != NULL && isValidSalary(sueldo))
    {
        this->sueldo = sueldo;
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_setSueldoTxt(Employee* this, char* sueldo)
{
    int auxReturn = -1;
    float auxSueldo;

    if(this != NULL && sueldo != NULL && isFloat(sueldo, BUFFER_LEN) == 1)
    {
        auxSueldo = atof(sueldo);

        if(isValidSalary(auxSueldo))
        {
            this->sueldo = auxSueldo;
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int employee_getSueldo(Employee* this, float* sueldo)
{
    int auxReturn = -1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_getSueldoTxt(Employee* this, char* sueldo)
{
    int auxReturn = -1;

    if(this != NULL && sueldo != NULL)
    {
        snprintf(sueldo, BUFFER_LEN, "%.2f", this->sueldo);
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
                if(i == 0 && cadena[i] == '+')
                {
                    continue;
                }

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
                if(i == 0 && cadena[i] == '+')
                {
                    continue;
                }

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

static int isValidId(int id)
{
    int retorno = 0;

    if(id >= 1 && id <= 10000)
    {
        retorno = 1;
    }

    return retorno;
}

static int isValidWorkedHours(int horasTrabajadas)
{
    int retorno = 0;

    if(horasTrabajadas >= 50 && horasTrabajadas <= 500)
    {
        retorno = 1;
    }

    return retorno;
}

static int isValidSalary(float sueldo)
{
    int retorno = 0;

    if(sueldo >= 10000 && sueldo <= 500000)
    {
        retorno = 1;
    }

    return retorno;
}

static int showModificationsMenu(LinkedList* pArrayListEmployee, Employee* this)
{
    int auxReturn = -1;

    char auxNombre[NOMBRE_LEN];
    int auxHorasTrabajadas;
    float auxSueldo;

    char option;

    int flag = 0;

    if(pArrayListEmployee != NULL && this != NULL)
    {
        do
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tMENU DE MODIFICACION DE EMPLEADO\n\n");
            printf("A. Nombre\n");
            printf("B. Horas Trabajadas\n");
            printf("C. Sueldo\n");
            printf("D. Salir\n");

            if(!utn_getCaracter(&option, "\nQue desea modificar?: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'D', 2))
            {
                switch(option)
                {
                    case 'A':

                        if(!utn_getAlfabetico(auxNombre, "\nIngrese nuevo nombre: ", "Error. Solo letras: ", 4, NOMBRE_LEN, 2) &&
                           !utn_formatearCadena(auxNombre, NOMBRE_LEN) && !employee_setNombre(this, auxNombre))
                        {
                        	flag = 1;
                        }

                        break;

                    case 'B':

                        if(!utn_getNumero(&auxHorasTrabajadas, "\nIngrese nuevas horas trabajadas entre 50 y 500: ",
                        		          "Error. Solo numeros enteros dentro del rango: ", 50, 500, 2) &&
                           !employee_setHorasTrabajadas(this, auxHorasTrabajadas))
                        {
                        	flag = 1;
                        }

                        break;

                    case 'C':

                        if(!utn_getNumeroFlotante(&auxSueldo, "\nIngrese nuevo sueldo entre 10000 y 500000: ",
                        		                  "Error. Solo numeros flotantes dentro del rango: ", 10000, 500000, 2) &&
                           !employee_setSueldo(this, auxSueldo))
                        {
                        	flag = 1;
                        }

                        break;

                    case 'D':

                    	printf("\nHa salido del menu de modificacion\n");

                    	break;
                }
            }

        } while(option != 'D');

        if(flag)
        {
        	auxReturn = 0;
        }
    }

    return auxReturn;
}

static int printAnEmployee(Employee* this)
{
    int auxReturn = -1;

    int auxId;
    char auxNombre[NOMBRE_LEN];
    int auxHorasTrabajadas;
    float auxSueldo;

    if(this != NULL && !employee_getId(this, &auxId) && !employee_getNombre(this, auxNombre) &&
       !employee_getHorasTrabajadas(this, &auxHorasTrabajadas) && !employee_getSueldo(this, &auxSueldo))
    {
        printf("%d\t%-8s\t\t%-d\t\t\t%.2f\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

        auxReturn = 0;
    }

    return auxReturn;
}

int employee_findEmployeeById(LinkedList* pArrayListEmployee, int id, int* index)
{
    int auxReturn = -1;

    int length;
    int auxId;
    int i;

    Employee* this;

    if(pArrayListEmployee != NULL && index != NULL)
    {
        length = ll_len(pArrayListEmployee);

        if(length > 0)
        {
            for(i = 0; i < length; i++)
            {
                this = (Employee*) ll_get(pArrayListEmployee, i);

                if(this != NULL && !employee_getId(this, &auxId) && auxId == id)
                {
                    *index = i;
                	auxReturn = 0;
                	break;
                }
            }
        }
    }

    return auxReturn;
}

int employee_add(LinkedList* pArrayListEmployee, int* id)
{
    int auxReturn = -1;

    char auxNombre[NOMBRE_LEN];
    int auxHorasTrabajadas;
    float auxSueldo;

    Employee* this;

	if(pArrayListEmployee != NULL && id != NULL &&
	   !utn_getAlfabetico(auxNombre, "\nIngrese nombre: ", "Error. Solo letras: ", 4, NOMBRE_LEN, 2) &&
	   !utn_formatearCadena(auxNombre, NOMBRE_LEN) &&
	   !utn_getNumero(&auxHorasTrabajadas, "\nIngrese horas trabajadas entre 50 y 500: ",
							  "Error. Solo numeros enteros dentro del rango: ", 50, 500, 2) &&
	   !utn_getNumeroFlotante(&auxSueldo, "\nIngrese sueldo entre 10000 y 500000: ",
									  "Error. Solo numeros flotantes dentro del rango: ", 10000, 500000, 2))
	{
		this = employee_newParametros(*id + 1, auxNombre, auxHorasTrabajadas, auxSueldo);

		if(this != NULL)
		{
			ll_add(pArrayListEmployee, this);

			(*id)++;

			auxReturn = 0;
		}
	}

    return auxReturn;
}

int employee_edit(LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;
    int auxId;
    char reply;
    int index;

    Employee* this;

	if(pArrayListEmployee != NULL && !controller_listEmployee(pArrayListEmployee) &&
	   !utn_getNumero(&auxId, "\nIngrese el ID del empleado a modificar entre 1 y 10000: ",
							  "Error. Solo numeros enteros dentro del rango: ", 1, 10000, 2) &&
	   !employee_findEmployeeById(pArrayListEmployee, auxId, &index))
	{
		this = (Employee*) ll_get(pArrayListEmployee, index);

		if(this != NULL)
		{
			printf("\n");
			system("pause");
			system("cls");

			printf("\tMODIFICACION DE EMPLEADO\n");

			printf("\nID\tNOMBRE\t\t\tHORAS TRABAJADAS\tSUELDO\n\n");
			printAnEmployee(this);

			if(verificarRespuesta(&reply, "\nEsta seguro que desea modificar a este empleado? (S/N): ", "Error. Solo S/N: ") == 1 &&
			   !showModificationsMenu(pArrayListEmployee, this))
			{
				auxReturn = 0;
			}
		}
	}

    return auxReturn;
}

int employee_remove(LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;
    int auxId;
    char reply;
    int index;

    Employee* this;

	if(pArrayListEmployee != NULL && !controller_listEmployee(pArrayListEmployee) &&
	   !utn_getNumero(&auxId, "\nIngrese el ID del empleado a eliminar entre 1 y 10000: ",
							  "Error. Solo numeros enteros dentro del rango: ", 1, 10000, 2) &&
	   !employee_findEmployeeById(pArrayListEmployee, auxId, &index))
	{
		this = (Employee*) ll_get(pArrayListEmployee, index);

		if(this != NULL)
		{
			printf("\n");
			system("pause");
			system("cls");

			printf("\tBAJA DE EMPLEADO\n");

			printf("\nID\tNOMBRE\t\t\tHORAS TRABAJADAS\tSUELDO\n\n");
			printAnEmployee(this);

			if(verificarRespuesta(&reply, "\nEsta seguro que desea eliminar a este empleado? (S/N): ", "Error. Solo S/N: ") == 1)
			{
				employee_delete(this);
				ll_remove(pArrayListEmployee, index);

				auxReturn = 0;
			}
		}
	}

    return auxReturn;
}

int employee_listEmployee(LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;
    int length;
    int i;

    Employee* this;

    if(pArrayListEmployee != NULL)
    {
        length = ll_len(pArrayListEmployee);

        if(length > 0)
        {
        	printf("\n");
			system("pause");
			system("cls");

			printf("\tLISTA DE EMPLEADOS\n\n");
            printf("ID\tNOMBRE\t\t\tHORAS TRABAJADAS\tSUELDO\n\n");

            for(i = 0; i < length; i++)
            {
                this = (Employee*) ll_get(pArrayListEmployee, i);

                if(printAnEmployee(this))
                {
                    break;
                }
            }

            if(i == length)
            {
                auxReturn = 0;
            }
        }
    }

    return auxReturn;
}

int employee_clear(LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;
    int length;
    int i;

    Employee* this;

    if(pArrayListEmployee != NULL)
    {
        length = ll_len(pArrayListEmployee);

        if(length > 0)
        {
            for(i = 0; i < length; i++)
            {
                this = (Employee*) ll_get(pArrayListEmployee, i);

                if(this != NULL)
                {
                    employee_delete(this);
                }

                else
                {
                    break;
                }
            }

            if(i == length)
            {
                auxReturn = 0;
            }
        }
    }

    return auxReturn;
}

int showSortMenu(LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;
    int criterionOption;
    char orderOption;
    int order;

    int (*pFunc)(void*, void*);

    if(pArrayListEmployee != NULL)
    {
        do
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\t\tMENU DE ORDENAMIENTO\n");
            printf("\n1. Ordenar por ID");
            printf("\n2. Ordenar por nombre");
            printf("\n3. Ordenar por horas trabajadas");
            printf("\n4. Ordenar por sueldo");

            if(!utn_getNumero(&criterionOption, "\n\nIngrese una opcion: ", "Error. Solo numeros enteros dentro del rango: ", 1, 4, 2))
            {
                switch(criterionOption)
                {
                    case 1:

                        pFunc = employee_compareById;

                        printf("\nCriterio por ID elegido correctamente\n");

                        break;

                    case 2:

                        pFunc = employee_compareByName;

                        printf("\nCriterio por nombre elegido correctamente\n");

                        break;

                    case 3:

                        pFunc = employee_compareByWorkedHours;

                        printf("\nCriterio por cantidad de horas trabajadas elegido correctamente\n");

                        break;

                    case 4:

                        pFunc = employee_compareBySalary;

                        printf("\nCriterio por sueldo elegido correctamente\n");

                        break;
                }
            }

        } while(criterionOption < 1 || criterionOption > 4);

        do
        {
			printf("\n");
			system("pause");
			system("cls");

			printf("\t\tSENTIDO DE ORDENAMIENTO\n\n");
			printf("A. Orden Descendente\n");
			printf("B. Orden Ascendente\n");

			if(!utn_getCaracter(&orderOption, "\nIngrese una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'B', 2))
			{
				switch(orderOption)
				{
					case 'A':

						order = 0;

						break;

					case 'B':

						order = 1;

						break;
				}
			}

        } while(orderOption != 'A' && orderOption != 'B');

        printf("\nOrdenando... ");

        ll_sort(pArrayListEmployee, pFunc, order);

        auxReturn = 0;
    }

    return auxReturn;
}

int employee_compareById(void* pElement1, void* pElement2)
{
    int auxReturn = -2;

    int id1;
    int id2;

    Employee* pEmp1;
    Employee* pEmp2;

    if(pElement1 != NULL && pElement2 != NULL)
    {
        pEmp1 = (Employee*) pElement1;
        pEmp2 = (Employee*) pElement2;

        if(!employee_getId(pEmp1, &id1) && !employee_getId(pEmp2, &id2))
        {
            if(id1 > id2)
            {
                auxReturn = 1;
            }

            else if(id1 == id2)
            {
                auxReturn = 0;
            }

            else
            {
                auxReturn = -1;
            }
        }
    }

    return auxReturn;
}

int employee_compareByName(void* pElement1, void* pElement2)
{
    int auxReturn = -2;

    char name1[NOMBRE_LEN];
    char name2[NOMBRE_LEN];
    int auxComp;

    Employee* pEmp1;
    Employee* pEmp2;

    if(pElement1 != NULL && pElement2 != NULL)
    {
        pEmp1 = (Employee*) pElement1;
        pEmp2 = (Employee*) pElement2;

        if(!employee_getNombre(pEmp1, name1) && !employee_getNombre(pEmp2, name2))
        {
            auxComp = strncmp(name1, name2, NOMBRE_LEN);

            if(auxComp > 0)
            {
                auxReturn = 1;
            }

            else if(auxComp == 0)
            {
                auxReturn = 0;
            }

            else
            {
                auxReturn = -1;
            }
        }
    }

    return auxReturn;
}

int employee_compareByWorkedHours(void* pElement1, void* pElement2)
{
    int auxReturn = -2;

    int hours1;
    int hours2;

    Employee* pEmp1;
    Employee* pEmp2;

    if(pElement1 != NULL && pElement2 != NULL)
    {
        pEmp1 = (Employee*) pElement1;
        pEmp2 = (Employee*) pElement2;

        if(!employee_getHorasTrabajadas(pEmp1, &hours1) && !employee_getHorasTrabajadas(pEmp2, &hours2))
        {
            if(hours1 > hours2)
            {
                auxReturn = 1;
            }

            else if(hours1 == hours2)
            {
                auxReturn = 0;
            }

            else
            {
                auxReturn = -1;
            }
        }
    }

    return auxReturn;
}

int employee_compareBySalary(void* pElement1, void* pElement2)
{
    int auxReturn = -2;

    float salary1;
    float salary2;

    Employee* pEmp1;
    Employee* pEmp2;

    if(pElement1 != NULL && pElement2 != NULL)
    {
        pEmp1 = (Employee*) pElement1;
        pEmp2 = (Employee*) pElement2;

        if(!employee_getSueldo(pEmp1, &salary1) && !employee_getSueldo(pEmp2, &salary2))
        {
            if(salary1 > salary2)
            {
                auxReturn = 1;
            }

            else if(salary1 == salary2)
            {
                auxReturn = 0;
            }

            else
            {
                auxReturn = -1;
            }
        }
    }

    return auxReturn;
}

int employee_optionsMenu(int* option)
{
    int auxReturn = -1;

    if(option != NULL)
    {
        printf("\t\tMENU\n\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
        printf("2. Cargar los datos de los empleados desde el archivo data2.csv (modo binario)\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
        printf("9. Guardar los datos de los empleados en el archivo data2.csv (modo binario)\n");
        printf("10. Salir\n");

        if(!utn_getNumero(option, "\nElija una opcion: ", "Error. Solo numeros enteros dentro del rango: ", 1, 10, 2))
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}

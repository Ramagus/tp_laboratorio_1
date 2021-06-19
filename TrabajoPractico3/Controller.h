#ifndef CONTROLLER_H_
#define CONTROLLER_H_


#include "LinkedList.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto)
 *
 * \param path char* Ruta donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 * \param id int* Employee ID to load
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee, int* id);


/** \brief Carga los datos de los empleados desde el archivo data2.csv (modo binario)
 *
 * \param path char* Ruta donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 * \param id int* Employee ID to load
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee, int* id);


/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 * \param id int* Employee ID to load
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id);


/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_listEmployee(LinkedList* pArrayListEmployee);


/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto)
 *
 * \param path char* Ruta donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data2.csv (modo binario)
 *
 * \param path char* Ruta donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee);


#endif /* CONTROLLER_H_ */

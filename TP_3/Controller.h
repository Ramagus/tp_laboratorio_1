#include "LinkedList.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto)
 *
 * \param path char* Ruta donde se encuentra el archivo
 * \param pArrayListPassenger LinkedList* Puntero al LinkedList
 * \param id int* ID de pasajero a asignar
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListPassenger, int* id);


/** \brief Carga los datos de los pasajeros desde el archivo data.bin (modo binario)
 *
 * \param path char* Ruta donde se encuentra el archivo
 * \param pArrayListPassenger LinkedList* Puntero al LinkedList
 * \param id int* ID de pasajero a asignar
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListPassenger, int* id);


/** \brief Alta de pasajero
 *
 * \param pArrayListPassenger LinkedList* Puntero al LinkedList
 * \param id int* ID de pasajero a asignar
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int* id);


/** \brief Modificar datos de pasajero
 *
 * \param pArrayListPassenger LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);


/** \brief Baja de pasajero
 *
 * \param pArrayListPassenger LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);


/** \brief Listar pasajeros
 *
 * \param pArrayListPassenger LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_listPassenger(LinkedList* pArrayListPassenger);


/** \brief Ordenar pasajeros
 *
 * \param pArrayListPassenger LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto)
 *
 * \param path char* Ruta donde se encuentra el archivo
 * \param pArrayListPassenger LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListPassenger);


/** \brief Guarda los datos de los pasajeros en el archivo data.bin (modo binario)
 *
 * \param path char* Ruta donde se encuentra el archivo
 * \param pArrayListPassenger LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListPassenger);


/** \brief Comprueba si un archivo existe
 *
 * \param path char* Ruta donde se encuentra el archivo
 * \param mode char* Modo de acceso al archivo
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_fileExists(char* path, char* mode);


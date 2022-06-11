#include "LinkedList.h"

#define BUFFER_LEN_PAR 100

/** \brief Parsea los datos de los pasajeros desde el archivo data.csv (modo texto)
 *
 * \param pFile FILE* Puntero al Archivo
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 * \param id int* ID de pasajero a asignar
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger, int* id);


/** \brief Parsea los datos de los pasajeros desde el archivo data.bin (modo binario)
 *
 * \param pFile FILE* Puntero al Archivo
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 * \param id int* ID de pasajero a asignar
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int parser_PassengerFromBinary(FILE* pFile, LinkedList* pArrayListPassenger, int* id);

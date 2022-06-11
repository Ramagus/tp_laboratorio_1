#ifndef SERIALIZER_H_
#define SERIALIZER_H_


#include "LinkedList.h"

#define BUFFER_LEN_SER 100


/** \brief Serializa los datos de los pasajeros al archivo data.csv (modo texto)
 *
 * \param pFile FILE* Puntero al Archivo
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int serializer_PassengerToText(FILE* pFile, LinkedList* pArrayListEmployee);


/** \brief Serializa los datos de los pasajeros al archivo data.bin (modo binario)
 *
 * \param pFile FILE* Puntero al Archivo
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int serializer_PassengerToBinary(FILE* pFile, LinkedList* pArrayListEmployee);


#endif /* SERIALIZER_H_ */

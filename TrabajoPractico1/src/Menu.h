#ifndef MENU_H_
#define MENU_H_


/** \brief Imprime las opciones a elegir del menú
 *
 * \param numero1 float Es el primer número
 * \param numero2 float Es el segundo número
 * \param flagNumero1 int Bandera que cambia de estado si el primer número está cargado
 * \param flagNumero2 int Bandera que cambia de estado si el segundo número está cargado
 * \param opcion int* Lugar donde se cargará la opción ingresada por el usuario
 *
 * \return int 0 si está todo Ok o -1 si hubo un error
 *
 */
int mostrarMenuOpciones(float numero1, float numero2, int flagNumero1, int flagNumero2, int* opcion);


/** \brief Verifica si un número recibido como flotante es un número entero
 *
 * \param numero float Es el número a analizar
 *
 * \return int 1 Si el número es entero o 0 si no lo es
 *
 */
int esEntero(float numero);


/** \brief Calcula las operaciones aritméticas
 *
 * \param numero1 float* Es el primer número
 * \param numero2 float* Es el segundo número
 * \param resultSuma float* Lugar donde se guardará el resultado de la suma
 * \param resultResta float* Lugar donde se guardará el resultado de la resta
 * \param resultDivision float* Lugar donde se guardará el resultado de la división
 * \param resultMultiplicacion float* Lugar donde se guardará el resultado de multiplicación
 * \param resultFact1 unsigned long int* Lugar donde se guardará el resultado del factorial del primer número
 * \param resultFact2 unsigned long int* Lugar donde se guardará el resultado del factorial del segundo número
 * \param flagDiv int* Bandera de la división que cambia de estado si el segundo número no es 0
 * \param flagFact1 int* Bandera del primer factorial que cambia de estado si el primer número es entero positivo
 * \param flagFact2 int* Bandera del segundo factorial que cambia de estado si el segundo número es entero positivo
 *
 * \return int 0 si está todo Ok o -1 si hubo un error
 *
 */
int realizarOperaciones(float* numero1, float* numero2, float* resultSuma, float* resultResta,
						float* resultDivision, float* resultMultiplicacion, unsigned long int* resultFact1,
						unsigned long int* resultFact2, int* flagDiv, int* flagFact1, int* flagFact2);


/** \brief Imprime por pantalla los resultados de las operaciones aritméticas
 *
 * \param resultSuma float Es el resultado de la suma
 * \param resultResta float Es el resultado de la resta
 * \param resultDivision float Es el resultado de la división
 * \param resultMultiplicacion float Es el resultado de la multiplicación
 * \param resultFact1 unsigned long int Es el resultado del factorial del primer número
 * \param resultFact2 unsigned long int Es el resultado del factorial del segundo número
 * \param flagDiv int Bandera de la división
 * \param flagFact1 int Bandera del factorial del primer número
 * \param flagFact2 int Bandera del factorial del segundo número
 *
 * \return void
 *
 */
void informarResultados(float resultSuma, float resultResta, float resultDivision, float resultMultiplicacion,
		                unsigned long int resultFact1, unsigned long int resultFact2,
                        int flagDiv, int flagFact1, int flagFact2);


#endif /* MENU_H_ */

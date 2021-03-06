#ifndef MENU_H_
#define MENU_H_


/** \brief Imprime las opciones a elegir del men?
 *
 * \param numero1 float Es el primer n?mero
 * \param numero2 float Es el segundo n?mero
 * \param flagNumero1 int Bandera que cambia de estado si el primer n?mero est? cargado
 * \param flagNumero2 int Bandera que cambia de estado si el segundo n?mero est? cargado
 * \param opcion int* Lugar donde se cargar? la opci?n ingresada por el usuario
 *
 * \return int 0 si est? todo Ok o -1 si hubo un error
 *
 */
int mostrarMenuOpciones(float numero1, float numero2, int flagNumero1, int flagNumero2, int* opcion);


/** \brief Verifica si un n?mero recibido como flotante es un n?mero entero
 *
 * \param numero float Es el n?mero a analizar
 *
 * \return int 1 Si el n?mero es entero o 0 si no lo es
 *
 */
int esEntero(float numero);


/** \brief Calcula las operaciones aritm?ticas
 *
 * \param numero1 float Es el primer n?mero
 * \param numero2 float Es el segundo n?mero
 * \param resultSuma float* Lugar donde se guardar? el resultado de la suma
 * \param resultResta float* Lugar donde se guardar? el resultado de la resta
 * \param resultDivision float* Lugar donde se guardar? el resultado de la divisi?n
 * \param resultMultiplicacion float* Lugar donde se guardar? el resultado de multiplicaci?n
 * \param resultFact1 unsigned long int* Lugar donde se guardar? el resultado del factorial del primer n?mero
 * \param resultFact2 unsigned long int* Lugar donde se guardar? el resultado del factorial del segundo n?mero
 * \param flagDiv int* Bandera de la divisi?n que cambia de estado si el segundo n?mero no es 0
 * \param flagFact1 int* Bandera del primer factorial que cambia de estado si el primer n?mero es entero positivo
 * \param flagFact2 int* Bandera del segundo factorial que cambia de estado si el segundo n?mero es entero positivo
 *
 * \return int 0 si est? todo Ok o -1 si hubo un error
 *
 */
int realizarOperaciones(float numero1, float numero2, float* resultSuma, float* resultResta,
						float* resultDivision, float* resultMultiplicacion, unsigned long int* resultFact1,
						unsigned long int* resultFact2, int* flagDiv, int* flagFact1, int* flagFact2);


/** \brief Imprime por pantalla los resultados de las operaciones aritm?ticas
 *
 * \param resultSuma float Es el resultado de la suma
 * \param resultResta float Es el resultado de la resta
 * \param resultDivision float Es el resultado de la divisi?n
 * \param resultMultiplicacion float Es el resultado de la multiplicaci?n
 * \param resultFact1 unsigned long int Es el resultado del factorial del primer n?mero
 * \param resultFact2 unsigned long int Es el resultado del factorial del segundo n?mero
 * \param flagDiv int Bandera de la divisi?n
 * \param flagFact1 int Bandera del factorial del primer n?mero
 * \param flagFact2 int Bandera del factorial del segundo n?mero
 *
 * \return void
 *
 */
void informarResultados(float resultSuma, float resultResta, float resultDivision, float resultMultiplicacion,
		                unsigned long int resultFact1, unsigned long int resultFact2,
                        int flagDiv, int flagFact1, int flagFact2);


#endif /* MENU_H_ */

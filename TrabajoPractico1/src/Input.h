#ifndef INPUT_H_
#define INPUT_H_


/** \brief Solicita un n?mero entero al usuario y devuelve el resultado
 *
 * \param pResultado int* Puntero al espacio de memoria donde se dejar? el resultado de la funci?n
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 *
 * \return int Retorna 0 si se obtuvo el n?mero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError);


/** \brief Solicita un n?mero flotante al usuario y devuelve el resultado
 *
 * \param pResultado float* Puntero al espacio de memoria donde se dejar? el resultado de la funci?n
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 *
 * \return int Retorna 0 si se obtuvo el n?mero y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError);


#endif /* INPUT_H_ */

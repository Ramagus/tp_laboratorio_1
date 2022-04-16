/** \brief Solicita un n�mero entero al usuario y devuelve el resultado
 *
 * \param pResultado int* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo int Es el n�mero m�nimo a ser aceptado
 * \param maximo int Es el n�mero m�ximo a ser aceptado
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo el n�mero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** \brief Solicita un n�mero flotante al usuario y devuelve el resultado
 *
 * \param pResultado float* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo float Es el n�mero m�nimo a ser aceptado
 * \param maximo float Es el n�mero m�ximo a ser aceptado
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo el n�mero y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


/** \brief Se encarga de validar que la respuesta s�lo sea s/n
 *
 * \param pResp char* Puntero al espacio de memoria donde se guardar� el dato validado ingresado
 * \param mensaje char* Texto que pide el valor
 * \param mensajeError char* Texto en caso de error
 *
 * \return int Retorna 1 si la respuesta es 'S', 0 si la respuesta es 'N' o -1 si hubo un error
 *
 */
int verificarRespuesta(char* pResp, char* mensaje, char* mensajeError);


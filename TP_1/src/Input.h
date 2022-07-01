/** \brief Solicita un número entero al usuario y devuelve el resultado
 *
 * \param pResultado int* Puntero al espacio de memoria donde se dejará el resultado de la función
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo int Es el número mínimo a ser aceptado
 * \param maximo int Es el número máximo a ser aceptado
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo el número y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** \brief Solicita un número double al usuario y devuelve el resultado
 *
 * \param pResultado double* Puntero al espacio de memoria donde se dejará el resultado de la función
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo double Es el número mínimo a ser aceptado
 * \param maximo double Es el número máximo a ser aceptado
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo el número y -1 si no
 *
 */
int utn_getNumeroDouble(double* pResultado, char* mensaje, char* mensajeError, double minimo, double maximo, int reintentos);


/** \brief Verifica si la respuesta es afirmativa
 *
 * \param mensaje char* Texto que pide el valor
 * \param mensajeError char* Texto en caso de error
 *
 * \return int Retorna 1 si la respuesta es 'S', 0 si la respuesta es 'N' o -1 si hubo un error
 *
 */
int utn_respuestaEsAfirmativa(char* mensaje, char* mensajeError);


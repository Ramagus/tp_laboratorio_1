#ifndef MENU_H_
#define MENU_H_


/** \brief Imprime las opciones a elegir del men�
 *
 * \param kilometros double Es la cantidad de kil�metros de Vuelo
 * \param precioAero double Es el precio de Aerol�neas
 * \param precioLatam double Es el precio de Latam
 * \param flagKm int Bandera que verifica si los kil�metros est�n cargados
 * \param flagAero int Bandera que verifica si el precio de Aerol�neas est� cargado
 * \param flagLatam int Bandera que verifica si el precio de Latam est� cargado
 * \param opcion int* Lugar donde se cargar� la opci�n ingresada por el usuario
 *
 * \return int 0 si est� todo Ok o -1 si hubo un error
 *
 */
int mostrarMenuOpciones(double kilometros, double precioAero, double precioLatam, int flagKm, int flagAero, int flagLatam, int* opcion);


/** \brief Realiza los c�lculos de los costos de Vuelo
 *
 * \param kilometros double Es la cantidad de kil�metros de Vuelo
 * \param precio double Es el precio de Vuelo
 * \param tarDeb double* Lugar donde se guardar� el c�lculo de tarjeta de d�bito de Vuelo
 * \param tarCred double* Lugar donde se guardar� el c�lculo de tarjeta de cr�dito de Vuelo
 * \param bitcoin double* Lugar donde se guardar� el c�lculo de bitcoin de Vuelo
 * \param unitario double* Lugar donde se guardar� el c�lculo de precio unitario de Vuelo
 *
 * \return int 0 si est� todo Ok o -1 si hubo un error
 *
 */
int calcularCostosVuelo(double kilometros, double precio, double* tarDeb, double* tarCred, double* bitcoin, double* unitario);


/** \brief Realiza los c�lculos de todos los costos de Aerol�neas y Latam
 *
 * \param kilometros double Es la cantidad de kil�metros de Vuelo
 * \param precioAero double Es el precio de Aerol�neas
 * \param tarDebAero double* Lugar donde se guardar� el c�lculo de tarjeta de d�bito de Aerol�neas
 * \param tarCredAero double* Lugar donde se guardar� el c�lculo de tarjeta de cr�dito de Aerol�neas
 * \param bitcoinAero double* Lugar donde se guardar� el c�lculo de bitcoin de Aerol�neas
 * \param unitarioAero double* Lugar donde se guardar� el c�lculo de precio unitario de Aerol�neas
 * \param precioLatam double Es el precio de Latam
 * \param tarDebLatam double* Lugar donde se guardar� el c�lculo de tarjeta de d�bito de Latam
 * \param tarCredLatam double* Lugar donde se guardar� el c�lculo de tarjeta de cr�dito de Latam
 * \param bitcoinLatam double* Lugar donde se guardar� el c�lculo de bitcoin de Latam
 * \param unitarioLatam double* Lugar donde se guardar� el c�lculo de precio unitario de Latam
 * \param difPrecios double* Lugar donde se guardar� el c�lculo de diferencia de precios entre Latam y Aerol�neas
 *
 * \return int 0 si est� todo Ok o -1 si hubo un error
 *
 */
int calcularCostosTodos(double kilometros, double precioAero, double* tarDebAero, double* tarCredAero, double* bitcoinAero, double* unitarioAero,
                        double precioLatam, double* tarDebLatam, double* tarCredLatam, double* bitcoinLatam, double* unitarioLatam, double* difPrecios);


/** \brief Imprime los resultados de los c�lculos de costos de Vuelo
 *
 * \param nombre char* Es el nombre de Vuelo
 * \param precio double Es el precio de Vuelo
 * \param tarDeb double Es el resultado del c�lculo de tarjeta de d�bito de Vuelo
 * \param tarCred double Es el resultado del c�lculo de tarjeta de cr�dito de Vuelo
 * \param bitcoin double Es el resultado del c�lculo de bitcoin de Vuelo
 * \param unitario double Es el resultado del c�lculo de precio unitario de Vuelo
 *
 * \return int 0 si est� todo Ok o -1 si hubo un error
 *
 */
int mostrarCalculosVuelo(char* nombre, double precio, double tarDeb, double tarCred, double bitcoin, double unitario);


/** \brief Imprime los resultados de los c�lculos de todos los costos de Aerol�neas y Latam
 *
 * \param kilometros double Es la cantidad de kil�metros de Vuelo
 * \param precioAero double Es el precio de Aerol�neas
 * \param tarDebAero double Es el resultado del c�lculo de tarjeta de d�bito de Aerol�neas
 * \param tarCredAero double Es el resultado del c�lculo de tarjeta de cr�dito de Aerol�neas
 * \param bitcoinAero double Es el resultado del c�lculo de bitcoin de Aerol�neas
 * \param unitarioAero double Es el resultado del c�lculo de precio unitario de Aerol�neas
 * \param precioLatam double Es el precio de Latam
 * \param tarDebLatam double Es el resultado del c�lculo de tarjeta de d�bito de Latam
 * \param tarCredLatam double Es el resultado del c�lculo de tarjeta de cr�dito de Latam
 * \param bitcoinLatam double Es el resultado del c�lculo de bitcoin de Latam
 * \param unitarioLatam double Es el resultado del c�lculo de precio unitario de Latam
 * \param difPrecios double Es el resultado del c�lculo de diferencia de precios entre Latam y Aerol�neas
 *
 * \return int 0 si est� todo Ok o -1 si hubo un error
 *
 */
int informarResultados(double kilometros, double precioAero, double tarDebAero, double tarCredAero, double bitcoinAero, double unitarioAero,
		               double precioLatam, double tarDebLatam, double tarCredLatam, double bitcoinLatam, double unitarioLatam, double difPrecios);


/** \brief Realiza una carga forzada de datos, calcula todos los costos y
 *         muestra los resultados de los mismos
 *
 * \param void
 *
 * \return int 0 si est� todo Ok o -1 si hubo un error
 *
 */
int hardcodearVuelos(void);


#endif /* MENU_H_ */

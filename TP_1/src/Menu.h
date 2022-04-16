#ifndef MENU_H_
#define MENU_H_


/** \brief Imprime las opciones a elegir del men�
 *
 * \param kilometros float Es la cantidad de kil�metros de Vuelo
 * \param precioAero float Es el precio de Aerol�neas
 * \param precioLatam float Es el precio de Latam
 * \param flagKm int Bandera que verifica si los kil�metros est�n cargados
 * \param flagAero int Bandera que verifica si el precio de Aerol�neas est� cargado
 * \param flagLatam int Bandera que verifica si el precio de Latam est� cargado
 * \param opcion int* Lugar donde se cargar� la opci�n ingresada por el usuario
 *
 * \return int 0 si est� todo Ok o -1 si hubo un error
 *
 */
int mostrarMenuOpciones(float kilometros, float precioAero, float precioLatam, int flagKm, int flagAero, int flagLatam, int* opcion);


/** \brief Realiza los c�lculos de los costos de Vuelo
 *
 * \param kilometros float Es la cantidad de kil�metros de Vuelo
 * \param precio float Es el precio de Vuelo
 * \param tarDeb float* Lugar donde se guardar� el c�lculo de tarjeta de d�bito de Vuelo
 * \param tarCred float* Lugar donde se guardar� el c�lculo de tarjeta de cr�dito de Vuelo
 * \param bitcoin double* Lugar donde se guardar� el c�lculo de bitcoin de Vuelo
 * \param unitario float* Lugar donde se guardar� el c�lculo de precio unitario de Vuelo
 *
 * \return int 0 si est� todo Ok o -1 si hubo un error
 *
 */
int calcularCostosVuelo(float kilometros, float precio, float* tarDeb, float* tarCred, double* bitcoin, float* unitario);


/** \brief Realiza los c�lculos de todos los costos de Aerol�neas y Latam
 *
 * \param kilometros float Es la cantidad de kil�metros de Vuelo
 * \param precioAero float Es el precio de Aerol�neas
 * \param tarDebAero float* Lugar donde se guardar� el c�lculo de tarjeta de d�bito de Aerol�neas
 * \param tarCredAero float* Lugar donde se guardar� el c�lculo de tarjeta de cr�dito de Aerol�neas
 * \param bitcoinAero double* Lugar donde se guardar� el c�lculo de bitcoin de Aerol�neas
 * \param unitarioAero float* Lugar donde se guardar� el c�lculo de precio unitario de Aerol�neas
 * \param precioLatam float Es el precio de Latam
 * \param tarDebLatam float* Lugar donde se guardar� el c�lculo de tarjeta de d�bito de Latam
 * \param tarCredLatam float* Lugar donde se guardar� el c�lculo de tarjeta de cr�dito de Latam
 * \param bitcoinLatam double* Lugar donde se guardar� el c�lculo de bitcoin de Latam
 * \param unitarioLatam float* Lugar donde se guardar� el c�lculo de precio unitario de Latam
 * \param difPrecios float* Lugar donde se guardar� el c�lculo de diferencia de precios entre Latam y Aerol�neas
 *
 * \return int 0 si est� todo Ok o -1 si hubo un error
 *
 */
int calcularCostosTodos(float kilometros, float precioAero, float* tarDebAero, float* tarCredAero, double* bitcoinAero, float* unitarioAero,
                        float precioLatam, float* tarDebLatam, float* tarCredLatam, double* bitcoinLatam, float* unitarioLatam, float* difPrecios);


/** \brief Imprime los resultados de los c�lculos de costos de Vuelo
 *
 * \param nombre char* Es el nombre de Vuelo
 * \param precio float Es el precio de Vuelo
 * \param tarDeb float Es el resultado del c�lculo de tarjeta de d�bito de Vuelo
 * \param tarCred float Es el resultado del c�lculo de tarjeta de cr�dito de Vuelo
 * \param bitcoin double Es el resultado del c�lculo de bitcoin de Vuelo
 * \param unitario float Es el resultado del c�lculo de precio unitario de Vuelo
 *
 * \return int 0 si est� todo Ok o -1 si hubo un error
 *
 */
int mostrarCalculosVuelo(char* nombre, float precio, float tarDeb, float tarCred, double bitcoin, float unitario);


/** \brief Imprime los resultados de los c�lculos de todos los costos de Aerol�neas y Latam
 *
 * \param kilometros float Es la cantidad de kil�metros de Vuelo
 * \param precioAero float Es el precio de Aerol�neas
 * \param tarDebAero float Es el resultado del c�lculo de tarjeta de d�bito de Aerol�neas
 * \param tarCredAero float Es el resultado del c�lculo de tarjeta de cr�dito de Aerol�neas
 * \param bitcoinAero double Es el resultado del c�lculo de bitcoin de Aerol�neas
 * \param unitarioAero float Es el resultado del c�lculo de precio unitario de Aerol�neas
 * \param precioLatam float Es el precio de Latam
 * \param tarDebLatam float Es el resultado del c�lculo de tarjeta de d�bito de Latam
 * \param tarCredLatam float Es el resultado del c�lculo de tarjeta de cr�dito de Latam
 * \param bitcoinLatam double Es el resultado del c�lculo de bitcoin de Latam
 * \param unitarioLatam float Es el resultado del c�lculo de precio unitario de Latam
 * \param difPrecios float Es el resultado del c�lculo de diferencia de precios entre Latam y Aerol�neas
 *
 * \return int 0 si est� todo Ok o -1 si hubo un error
 *
 */
int informarResultados(float kilometros, float precioAero, float tarDebAero, float tarCredAero, double bitcoinAero, float unitarioAero,
		               float precioLatam, float tarDebLatam, float tarCredLatam, double bitcoinLatam, float unitarioLatam, float difPrecios);


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

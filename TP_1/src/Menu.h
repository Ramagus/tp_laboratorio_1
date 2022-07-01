#ifndef MENU_H_
#define MENU_H_


/** \brief Imprime las opciones a elegir del menú
 *
 * \param kilometros double Es la cantidad de kilómetros de Vuelo
 * \param precioAero double Es el precio de Aerolíneas
 * \param precioLatam double Es el precio de Latam
 * \param flagKm int Bandera que verifica si los kilómetros están cargados
 * \param flagAero int Bandera que verifica si el precio de Aerolíneas está cargado
 * \param flagLatam int Bandera que verifica si el precio de Latam está cargado
 * \param opcion int* Lugar donde se cargará la opción ingresada por el usuario
 *
 * \return int 0 si está todo Ok o -1 si hubo un error
 *
 */
int mostrarMenuOpciones(double kilometros, double precioAero, double precioLatam, int flagKm, int flagAero, int flagLatam, int* opcion);


/** \brief Realiza los cálculos de los costos de Vuelo
 *
 * \param kilometros double Es la cantidad de kilómetros de Vuelo
 * \param precio double Es el precio de Vuelo
 * \param tarDeb double* Lugar donde se guardará el cálculo de tarjeta de débito de Vuelo
 * \param tarCred double* Lugar donde se guardará el cálculo de tarjeta de crédito de Vuelo
 * \param bitcoin double* Lugar donde se guardará el cálculo de bitcoin de Vuelo
 * \param unitario double* Lugar donde se guardará el cálculo de precio unitario de Vuelo
 *
 * \return int 0 si está todo Ok o -1 si hubo un error
 *
 */
int calcularCostosVuelo(double kilometros, double precio, double* tarDeb, double* tarCred, double* bitcoin, double* unitario);


/** \brief Realiza los cálculos de todos los costos de Aerolíneas y Latam
 *
 * \param kilometros double Es la cantidad de kilómetros de Vuelo
 * \param precioAero double Es el precio de Aerolíneas
 * \param tarDebAero double* Lugar donde se guardará el cálculo de tarjeta de débito de Aerolíneas
 * \param tarCredAero double* Lugar donde se guardará el cálculo de tarjeta de crédito de Aerolíneas
 * \param bitcoinAero double* Lugar donde se guardará el cálculo de bitcoin de Aerolíneas
 * \param unitarioAero double* Lugar donde se guardará el cálculo de precio unitario de Aerolíneas
 * \param precioLatam double Es el precio de Latam
 * \param tarDebLatam double* Lugar donde se guardará el cálculo de tarjeta de débito de Latam
 * \param tarCredLatam double* Lugar donde se guardará el cálculo de tarjeta de crédito de Latam
 * \param bitcoinLatam double* Lugar donde se guardará el cálculo de bitcoin de Latam
 * \param unitarioLatam double* Lugar donde se guardará el cálculo de precio unitario de Latam
 * \param difPrecios double* Lugar donde se guardará el cálculo de diferencia de precios entre Latam y Aerolíneas
 *
 * \return int 0 si está todo Ok o -1 si hubo un error
 *
 */
int calcularCostosTodos(double kilometros, double precioAero, double* tarDebAero, double* tarCredAero, double* bitcoinAero, double* unitarioAero,
                        double precioLatam, double* tarDebLatam, double* tarCredLatam, double* bitcoinLatam, double* unitarioLatam, double* difPrecios);


/** \brief Imprime los resultados de los cálculos de costos de Vuelo
 *
 * \param nombre char* Es el nombre de Vuelo
 * \param precio double Es el precio de Vuelo
 * \param tarDeb double Es el resultado del cálculo de tarjeta de débito de Vuelo
 * \param tarCred double Es el resultado del cálculo de tarjeta de crédito de Vuelo
 * \param bitcoin double Es el resultado del cálculo de bitcoin de Vuelo
 * \param unitario double Es el resultado del cálculo de precio unitario de Vuelo
 *
 * \return int 0 si está todo Ok o -1 si hubo un error
 *
 */
int mostrarCalculosVuelo(char* nombre, double precio, double tarDeb, double tarCred, double bitcoin, double unitario);


/** \brief Imprime los resultados de los cálculos de todos los costos de Aerolíneas y Latam
 *
 * \param kilometros double Es la cantidad de kilómetros de Vuelo
 * \param precioAero double Es el precio de Aerolíneas
 * \param tarDebAero double Es el resultado del cálculo de tarjeta de débito de Aerolíneas
 * \param tarCredAero double Es el resultado del cálculo de tarjeta de crédito de Aerolíneas
 * \param bitcoinAero double Es el resultado del cálculo de bitcoin de Aerolíneas
 * \param unitarioAero double Es el resultado del cálculo de precio unitario de Aerolíneas
 * \param precioLatam double Es el precio de Latam
 * \param tarDebLatam double Es el resultado del cálculo de tarjeta de débito de Latam
 * \param tarCredLatam double Es el resultado del cálculo de tarjeta de crédito de Latam
 * \param bitcoinLatam double Es el resultado del cálculo de bitcoin de Latam
 * \param unitarioLatam double Es el resultado del cálculo de precio unitario de Latam
 * \param difPrecios double Es el resultado del cálculo de diferencia de precios entre Latam y Aerolíneas
 *
 * \return int 0 si está todo Ok o -1 si hubo un error
 *
 */
int informarResultados(double kilometros, double precioAero, double tarDebAero, double tarCredAero, double bitcoinAero, double unitarioAero,
		               double precioLatam, double tarDebLatam, double tarCredLatam, double bitcoinLatam, double unitarioLatam, double difPrecios);


/** \brief Realiza una carga forzada de datos, calcula todos los costos y
 *         muestra los resultados de los mismos
 *
 * \param void
 *
 * \return int 0 si está todo Ok o -1 si hubo un error
 *
 */
int hardcodearVuelos(void);


#endif /* MENU_H_ */

#ifndef MENU_H_
#define MENU_H_


/** \brief Imprime las opciones a elegir del menú
 *
 * \param kilometros float Es la cantidad de kilómetros de Vuelo
 * \param precioAero float Es el precio de Aerolíneas
 * \param precioLatam float Es el precio de Latam
 * \param flagKm int Bandera que verifica si los kilómetros están cargados
 * \param flagAero int Bandera que verifica si el precio de Aerolíneas está cargado
 * \param flagLatam int Bandera que verifica si el precio de Latam está cargado
 * \param opcion int* Lugar donde se cargará la opción ingresada por el usuario
 *
 * \return int 0 si está todo Ok o -1 si hubo un error
 *
 */
int mostrarMenuOpciones(float kilometros, float precioAero, float precioLatam, int flagKm, int flagAero, int flagLatam, int* opcion);


/** \brief Realiza los cálculos de los costos de Vuelo
 *
 * \param kilometros float Es la cantidad de kilómetros de Vuelo
 * \param precio float Es el precio de Vuelo
 * \param tarDeb float* Lugar donde se guardará el cálculo de tarjeta de débito de Vuelo
 * \param tarCred float* Lugar donde se guardará el cálculo de tarjeta de crédito de Vuelo
 * \param bitcoin double* Lugar donde se guardará el cálculo de bitcoin de Vuelo
 * \param unitario float* Lugar donde se guardará el cálculo de precio unitario de Vuelo
 *
 * \return int 0 si está todo Ok o -1 si hubo un error
 *
 */
int calcularCostosVuelo(float kilometros, float precio, float* tarDeb, float* tarCred, double* bitcoin, float* unitario);


/** \brief Realiza los cálculos de todos los costos de Aerolíneas y Latam
 *
 * \param kilometros float Es la cantidad de kilómetros de Vuelo
 * \param precioAero float Es el precio de Aerolíneas
 * \param tarDebAero float* Lugar donde se guardará el cálculo de tarjeta de débito de Aerolíneas
 * \param tarCredAero float* Lugar donde se guardará el cálculo de tarjeta de crédito de Aerolíneas
 * \param bitcoinAero double* Lugar donde se guardará el cálculo de bitcoin de Aerolíneas
 * \param unitarioAero float* Lugar donde se guardará el cálculo de precio unitario de Aerolíneas
 * \param precioLatam float Es el precio de Latam
 * \param tarDebLatam float* Lugar donde se guardará el cálculo de tarjeta de débito de Latam
 * \param tarCredLatam float* Lugar donde se guardará el cálculo de tarjeta de crédito de Latam
 * \param bitcoinLatam double* Lugar donde se guardará el cálculo de bitcoin de Latam
 * \param unitarioLatam float* Lugar donde se guardará el cálculo de precio unitario de Latam
 * \param difPrecios float* Lugar donde se guardará el cálculo de diferencia de precios entre Latam y Aerolíneas
 *
 * \return int 0 si está todo Ok o -1 si hubo un error
 *
 */
int calcularCostosTodos(float kilometros, float precioAero, float* tarDebAero, float* tarCredAero, double* bitcoinAero, float* unitarioAero,
                        float precioLatam, float* tarDebLatam, float* tarCredLatam, double* bitcoinLatam, float* unitarioLatam, float* difPrecios);


/** \brief Imprime los resultados de los cálculos de costos de Vuelo
 *
 * \param nombre char* Es el nombre de Vuelo
 * \param precio float Es el precio de Vuelo
 * \param tarDeb float Es el resultado del cálculo de tarjeta de débito de Vuelo
 * \param tarCred float Es el resultado del cálculo de tarjeta de crédito de Vuelo
 * \param bitcoin double Es el resultado del cálculo de bitcoin de Vuelo
 * \param unitario float Es el resultado del cálculo de precio unitario de Vuelo
 *
 * \return int 0 si está todo Ok o -1 si hubo un error
 *
 */
int mostrarCalculosVuelo(char* nombre, float precio, float tarDeb, float tarCred, double bitcoin, float unitario);


/** \brief Imprime los resultados de los cálculos de todos los costos de Aerolíneas y Latam
 *
 * \param kilometros float Es la cantidad de kilómetros de Vuelo
 * \param precioAero float Es el precio de Aerolíneas
 * \param tarDebAero float Es el resultado del cálculo de tarjeta de débito de Aerolíneas
 * \param tarCredAero float Es el resultado del cálculo de tarjeta de crédito de Aerolíneas
 * \param bitcoinAero double Es el resultado del cálculo de bitcoin de Aerolíneas
 * \param unitarioAero float Es el resultado del cálculo de precio unitario de Aerolíneas
 * \param precioLatam float Es el precio de Latam
 * \param tarDebLatam float Es el resultado del cálculo de tarjeta de débito de Latam
 * \param tarCredLatam float Es el resultado del cálculo de tarjeta de crédito de Latam
 * \param bitcoinLatam double Es el resultado del cálculo de bitcoin de Latam
 * \param unitarioLatam float Es el resultado del cálculo de precio unitario de Latam
 * \param difPrecios float Es el resultado del cálculo de diferencia de precios entre Latam y Aerolíneas
 *
 * \return int 0 si está todo Ok o -1 si hubo un error
 *
 */
int informarResultados(float kilometros, float precioAero, float tarDebAero, float tarCredAero, double bitcoinAero, float unitarioAero,
		               float precioLatam, float tarDebLatam, float tarCredLatam, double bitcoinLatam, float unitarioLatam, float difPrecios);


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

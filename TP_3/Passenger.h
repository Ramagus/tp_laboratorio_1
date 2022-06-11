#ifndef PASSENGER_H_
#define PASSENGER_H_


#include "LinkedList.h"
#define NAME_LEN 50
#define LAST_NAME_LEN 50
#define FLIGHT_CODE_LEN 10
#define TYPE_LEN 20
#define STATUS_LEN 20
#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0


typedef struct
{
	int id;
	char nombre[NAME_LEN];
	char apellido[LAST_NAME_LEN];
	float precio;
	char codigoVuelo[FLIGHT_CODE_LEN];
	char tipoPasajero[TYPE_LEN];
	char estadoVuelo[STATUS_LEN];

} Passenger;


/** \brief Reserva espacio en memoria para un nuevo pasajero
 *
 * \param void
 *
 * \return Passenger* Retorna un puntero al pasajero o NULL en caso de error
 *
 */
Passenger* Passenger_new(void);


/** \brief Reserva espacio en memoria para un nuevo pasajero y setea sus campos
 *         con los valores recibidos como parámetros
 *
 * \param id int ID del pasajero
 * \param nombre char* Nombre del pasajero
 * \param apellido char* Apellido del pasajero
 * \param precio float Precio del pasajero
 * \param codigoVuelo char* Código de vuelo del pasajero
 * \param tipoPasajero char* Tipo de pasajero
 * \param estadoVuelo char* Estado de vuelo del pasajero
 *
 * \return Passenger* Retorna un puntero al pasajero o NULL en caso de error
 *
 */
Passenger* Passenger_newParametros(int id, char* nombre, char* apellido, float precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo);


/** \brief Reserva espacio en memoria para un nuevo pasajero y setea sus campos como cadena
 *         con los valores recibidos como parámetros
 *
 * \param idStr char* ID del pasajero
 * \param nombreStr char* Nombre del pasajero
 * \param apellidoStr char* Apellido del pasajero
 * \param precioStr char* Precio del pasajero
 * \param codigoVueloStr char* Código de vuelo del pasajero
 * \param tipoPasajeroStr char* Tipo de pasajero
 * \param estadoVueloStr char* Estado de vuelo del pasajero
 *
 * \return Passenger* Retorna un puntero al pasajero o NULL en caso de error
 *
 */
Passenger* Passenger_newParametrosTxt(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);


/** \brief Libera el espacio ocupado por un pasajero recibido como parámetro
 *
 * \param this Passenger* Puntero al pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_delete(Passenger* this);


/** \brief Setea el ID de un pasajero
 *
 * \param this Passenger* Puntero al pasajero
 * \param id int ID del pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_setId(Passenger* this, int id);


/** \brief Setea el ID de un pasajero recibiendolo como cadena
 *
 * \param this Passenger* Puntero al pasajero
 * \param id char* ID del pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_setIdTxt(Passenger* this, char* id);


/** \brief Setea el nombre de un pasajero
 *
 * \param this Passenger* Puntero al pasajero
 * \param nombre char* Nombre del pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_setNombre(Passenger* this, char* nombre);


/** \brief Setea el apellido de un pasajero
 *
 * \param this Passenger* Puntero al pasajero
 * \param apellido char* Apellido del pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_setApellido(Passenger* this, char* apellido);


/** \brief Setea el precio de un pasajero
 *
 * \param this Passenger* Puntero al pasajero
 * \param precio float Precio del pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_setPrecio(Passenger* this, float precio);


/** \brief Setea el precio de un pasajero recibiendolo como cadena
 *
 * \param this Passenger* Puntero al pasajero
 * \param precio char* Precio del pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_setPrecioTxt(Passenger* this, char* precio);


/** \brief Setea el código de vuelo de un pasajero
 *
 * \param this Passenger* Puntero al pasajero
 * \param codigoVuelo char* Código de vuelo del pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo);


/** \brief Setea el tipo de un pasajero
 *
 * \param this Passenger* Puntero al pasajero
 * \param tipoPasajero char* Tipo de pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_setTipoPasajero(Passenger* this, char* tipoPasajero);


/** \brief Setea el estado de vuelo de un pasajero
 *
 * \param this Passenger* Puntero al pasajero
 * \param estadoVuelo char* Estado de vuelo del pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo);


/** \brief Obtiene el ID de un pasajero
 *
 * \param this Passenger* Puntero al pasajero
 * \param id int* Puntero donde se guardará el ID del pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_getId(Passenger* this, int* id);


/** \brief Obtiene el ID de un pasajero como cadena
 *
 * \param this Passenger* Puntero al pasajero
 * \param id char* Puntero donde se guardará el ID del pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_getIdTxt(Passenger* this, char* id);


/** \brief Obtiene el nombre de un pasajero
 *
 * \param this Passenger* Puntero al pasajero
 * \param nombre char* Puntero donde se guardará el nombre del pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_getNombre(Passenger* this, char* nombre);


/** \brief Obtiene el apellido de un pasajero
 *
 * \param this Passenger* Puntero al pasajero
 * \param apellido char* Puntero donde se guardará el apellido del pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_getApellido(Passenger* this, char* apellido);


/** \brief Obtiene el precio de un pasajero
 *
 * \param this Passenger* Puntero al pasajero
 * \param precio float* Puntero donde se guardará el precio del pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_getPrecio(Passenger* this, float* precio);


/** \brief Obtiene el precio de un pasajero como cadena
 *
 * \param this Passenger* Puntero al pasajero
 * \param precio char* Puntero donde se guardará el precio del pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_getPrecioTxt(Passenger* this, char* precio);


/** \brief Obtiene el código de vuelo de un pasajero
 *
 * \param this Passenger* Puntero al pasajero
 * \param codigoVuelo char* Puntero donde se guardará el código de vuelo del pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo);


/** \brief Obtiene el tipo de un pasajero
 *
 * \param this Passenger* Puntero al pasajero
 * \param tipoPasajero char* Puntero donde se guardará el tipo de pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_getTipoPasajero(Passenger* this, char* tipoPasajero);


/** \brief Obtiene el estado de vuelo de un pasajero
 *
 * \param this Passenger* Puntero al pasajero
 * \param estadoVuelo char* Puntero donde se guardará el estado de vuelo del pasajero
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo);


/** \brief Encuentra un pasajero por ID
 *
 * \param pArrayListPassenger LinkedList* Puntero al LinkedList
 * \param id int ID del pasajero a buscar
 * \param index int* Índice del pasajero encontrado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_findPassengerById(LinkedList* pArrayListPassenger, int id, int* index);


/** \brief Agrega un pasajero a la lista
 *
 * \param pArrayListPassenger LinkedList* Puntero al LinkedList
 * \param id int* ID de pasajero a asignar
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_add(LinkedList* pArrayListPassenger, int* id);


/** \brief Modifica los datos de un pasajero de la lista
 *
 * \param pArrayListPassenger LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_edit(LinkedList* pArrayListPassenger);


/** \brief Elimina un pasajero de la lista
 *
 * \param pArrayListPassenger LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_remove(LinkedList* pArrayListPassenger);


/** \brief Muestra la lista de pasajeros
 *
 * \param pArrayListPassenger LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_listPassenger(LinkedList* pArrayListPassenger);


/** \brief Elimina la lista de pasajeros
 *
 * \param pArrayListPassenger LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_clear(LinkedList* pArrayListPassenger);


/** \brief Establece el criterio de ordenamiento elegido
 *
 * \param pFunc (**pFunc) Puntero a la función criterio
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_chooseCriterionOrder(int (**pFunc)(void*, void*));


/** \brief Establece el sentido de ordenamiento elegido
 *
 * \param order int* Lugar donde se guardará el sentido elegido
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_chooseSortOrder(int* order);


/** \brief Ordena a los pasajeros según el criterio y el sentido elegidos
 *
 * \param pArrayListPassenger LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_sort(LinkedList* pArrayListPassenger);


/** \brief Función criterio que compara dos pasajeros por ID
 *
 * \param pElement1 void* Primer pasajero a comparar
 * \param pElement2 void* Segundo pasajero a comparar
 *
 * \return int Retorna (-3) si hubo un error
 *                     (-2) si hubo un error en la comparación
 *                     (-1) si el ID del primer pasajero es menor al ID del segundo pasajero
 *                     ( 0) si ambos ID son iguales
 *                     ( 1) si el ID del primer pasajero es mayor al ID del segundo pasajero
 *
 */
int Passenger_compareById(void* pElement1, void* pElement2);


/** \brief Función criterio que compara dos pasajeros por nombre
 *
 * \param pElement1 void* Primer pasajero a comparar
 * \param pElement2 void* Segundo pasajero a comparar
 *
 * \return int Retorna (-3) si hubo un error
 *                     (-2) si hubo un error en la comparación
 *                     (-1) si el nombre del primer pasajero es menor alfabéticamente al nombre del segundo pasajero
 *                     ( 0) si ambos nombres son iguales
 *                     ( 1) si el nombre del primer pasajero es mayor alfabéticamente al nombre del segundo pasajero
 *
 */
int Passenger_compareByName(void* pElement1, void* pElement2);


/** \brief Función criterio que compara dos pasajeros por apellido
 *
 * \param pElement1 void* Primer pasajero a comparar
 * \param pElement2 void* Segundo pasajero a comparar
 *
 * \return int Retorna (-3) si hubo un error
 *                     (-2) si hubo un error en la comparación
 *                     (-1) si el apellido del primer pasajero es menor alfabéticamente al apellido del segundo pasajero
 *                     ( 0) si ambos apellidos son iguales
 *                     ( 1) si el apellido del primer pasajero es mayor alfabéticamente al apellido del segundo pasajero
 *
 */
int Passenger_compareByLastName(void* pElement1, void* pElement2);


/** \brief Función criterio que compara dos pasajeros por precio
 *
 * \param pElement1 void* Primer pasajero a comparar
 * \param pElement2 void* Segundo pasajero a comparar
 *
 * \return int Retorna (-3) si hubo un error
 *                     (-2) si hubo un error en la comparación
 *                     (-1) si el precio del primer pasajero es menor al precio del segundo pasajero
 *                     ( 0) si ambos precios son iguales
 *                     ( 1) si el precio del primer pasajero es mayor al precio del segundo pasajero
 *
 */
int Passenger_compareByPrice(void* pElement1, void* pElement2);


/** \brief Función criterio que compara dos pasajeros por codigo de vuelo
 *
 * \param pElement1 void* Primer pasajero a comparar
 * \param pElement2 void* Segundo pasajero a comparar
 *
 * \return int Retorna (-3) si hubo un error
 *                     (-2) si hubo un error en la comparación
 *                     (-1) si el codigo de vuelo del primer pasajero es menor alfabéticamente al codigo de vuelo del segundo pasajero
 *                     ( 0) si ambos codigos son iguales
 *                     ( 1) si el codigo de vuelo del primer pasajero es mayor alfabéticamente al codigo de vuelo del segundo pasajero
 *
 */
int Passenger_compareByFlightCode(void* pElement1, void* pElement2);


/** \brief Función criterio que compara dos pasajeros por tipo
 *
 * \param pElement1 void* Primer pasajero a comparar
 * \param pElement2 void* Segundo pasajero a comparar
 *
 * \return int Retorna (-3) si hubo un error
 *                     (-2) si hubo un error en la comparación
 *                     (-1) si el tipo del primer pasajero es menor al tipo del segundo pasajero
 *                     ( 0) si ambos tipos son iguales
 *                     ( 1) si el tipo del primer pasajero es mayor al tipo del segundo pasajero
 *
 */
int Passenger_compareByTypePassenger(void* pElement1, void* pElement2);


/** \brief Función criterio que compara dos pasajeros por estado de vuelo
 *
 * \param pElement1 void* Primer pasajero a comparar
 * \param pElement2 void* Segundo pasajero a comparar
 *
 * \return int Retorna (-3) si hubo un error
 *                     (-2) si hubo un error en la comparación
 *                     (-1) si el estado de vuelo del primer pasajero es menor al estado de vuelo del segundo pasajero
 *                     ( 0) si ambos estados son iguales
 *                     ( 1) si el estado de vuelo del primer pasajero es mayor al estado de vuelo del segundo pasajero
 *
 */
int Passenger_compareByFlightStatus(void* pElement1, void* pElement2);


/** \brief Imprime las opciones a elegir del menú de pasajeros
 *
 * \param option int* Espacio de memoria donde se guardará el dato ingresado por el usuario
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int Passenger_optionsMenu(int* option);


#endif /* PASSENGER_H_ */

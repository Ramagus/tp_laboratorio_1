#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_


#define TYPE_DESC_LEN 20

typedef struct
{
	int id;
	char description[TYPE_DESC_LEN];

} TypePassenger;


/** \brief Load some type passengers data to testing
 *
 * \param list TypePassenger* Pointer to array of type passengers
 * \param len int Array length
 * \param id int* Type passenger ID to load
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int hardCodeTypePassengers(TypePassenger* list, int len, int* id);


/** \brief Find a type passenger by ID
 *
 * \param list Flight* Pointer to array of type passengers
 * \param len int Array length
 * \param id int Type passenger ID to search
 *
 * \return int (-1) if [Invalid length or NULL pointer received or type passenger not found] or type passenger index position
 *
 */
int findTypePassengerById(TypePassenger* list, int len, int id);


/** \brief Print the content of type passenger
 *
 * \param aFlightCode TypePassenger* Pointer to one type passenger
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printATypePassenger(TypePassenger* aTypePassenger);


/** \brief Print the content of type passengers array
 *
 * \param list FlightCode* Pointer to array of type passengers
 * \param len int Array length
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printTypePassengers(TypePassenger* list, int len);


#endif /* TYPEPASSENGER_H_ */

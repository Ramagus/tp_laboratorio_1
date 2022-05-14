#ifndef FLIGHT_H_
#define FLIGHT_H_


#define CODE_LEN 10

typedef struct
{
	int id;
	char code[CODE_LEN];
	int status;

} FlightCode;


/** \brief Load some flight codes data to testing
 *
 * \param list FlightCode* Pointer to array of flight codes
 * \param len int Array length
 * \param id int* Flight code ID to load
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int hardCodeFlightCodes(FlightCode* list, int len, int* id);


/** \brief Find a Flight code by ID
 *
 * \param list Flight* Pointer to array of flight codes
 * \param len int Array length
 * \param id int Flight code ID to search
 *
 * \return int (-1) if [Invalid length or NULL pointer received or flight code not found] or flight code index position
 *
 */
int findFlightCodeById(FlightCode* list, int len, int id);


/** \brief Find a Flight code by Code
 *
 * \param list Flight* Pointer to array of flight codes
 * \param len int Array length
 * \param code[] char Flight Code to search
 *
 * \return int (-1) if [Invalid length or NULL pointer received or flight code not found] or flight code index position
 *
 */
int findFlightCodeByCode(FlightCode* list, int len, char code[]);


#endif /* FLIGHT_H_ */

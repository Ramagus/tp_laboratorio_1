#ifndef FLIGHTSTATUS_H_
#define FLIGHTSTATUS_H_


#define STATUS_DESC_LEN 20

typedef struct
{
	int id;
	char description[STATUS_DESC_LEN];

} FlightStatus;


/** \brief Load some flight status data to testing
 *
 * \param list FlightStatus* Pointer to array of flight status
 * \param len int Array length
 * \param id int* Flight status ID to load
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int hardCodeFlightStatus(FlightStatus* list, int len, int* id);


/** \brief Find a Flight status by ID
 *
 * \param list FlightStatus* Pointer to array of flight codes
 * \param len int Array length
 * \param id int Flight code ID to search
 *
 * \return int (-1) if [Invalid length or NULL pointer received or flight status not found] or flight status index position
 *
 */
int findFlightStatusById(FlightStatus* list, int len, int id);


#endif /* FLIGHTSTATUS_H_ */

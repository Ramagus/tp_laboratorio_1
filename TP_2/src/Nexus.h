#ifndef NEXUS_H_
#define NEXUS_H_


#include "ArrayPassenger.h"
#include "FlightCode.h"
#include "TypePassenger.h"
#include "FlightStatus.h"


/** \brief Load a passenger data
 *
 * \param listPass Passenger* Pointer to array of passengers
 * \param lenPass int Array of passengers length
 * \param listFlightCode FlightCode* Pointer to array of flight codes
 * \param lenFlightCode int Array of flight codes length
 * \param listTypePassenger TypePassenger* Pointer to array of type passengers
 * \param lenTypePassenger int Array of type passengers length
 * \param listFlightStatus FlightStatus* Pointer to array of flight status
 * \param lenFlightStatus int Array of flight status length
 * \param idPass int* Passenger ID to load
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int loadPassenger(Passenger* listPass, int lenPass, FlightCode* listFlightCode, int lenFlightCode, TypePassenger* listTypePassenger, int lenTypePassenger, FlightStatus* listFlightStatus, int lenFlightStatus, int* idPass);


/** \brief Modify a Passenger by ID
 *
 * \param list Passenger* Pointer to array of passengers
 * \param len int Array length
 * \param idPass int Passenger ID to modify
 *
 * \return int (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
 *
 */
int modifyPassenger(Passenger* listPass, int lenPass, FlightCode* listFlightCode, int lenFlightCode, TypePassenger* listTypePassenger, int lenTypePassenger, FlightStatus* listFlightStatus, int lenFlightStatus, int idPass);


/** \brief Modify the Passenger chosen data
 *
 * \param list Passenger* Pointer to array of passengers
 * \param len int Array length
 * \param indexPass int Passenger index position to modify
 *
 * \return int (-1) if Error [Invalid length or NULL pointer or invalid index or if can't modify the Passenger] - (0) if Ok
 *
 */
int showModificationsMenu(Passenger* listPass, int lenPass, FlightCode* listFlightCode, int lenFlightCode, TypePassenger* listTypePassenger, int lenTypePassenger, FlightStatus* listFlightStatus, int lenFlightStatus, int indexPass);


/** \brief Remove a Passenger by ID (put isEmpty flag in TRUE)
 *
 * \param listPass Passenger* Pointer to array of passengers
 * \param lenPass int Array of passengers length
 * \param listTypePassenger TypePassenger* Pointer to array of type passengers
 * \param lenTypePassenger int Array of type passengers length
 * \param idPass int Passenger ID to remove
 *
 * \return int (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
 *
 */
int removePassenger(Passenger* listPass, int lenPass, TypePassenger* listTypePassenger, int lenTypePassenger, int idPass);


/** \brief Sort the elements in the array of passengers by code. The order argument indicate UP or DOWN order
 *
 * \param listPass Passenger* Pointer to array of passengers
 * \param lenPass int Array of passengers length
 * \param listFlightCode FlightCode* Pointer to array of flight codes
 * \param lenFlightCode int Array of flight codes length
 * \param listFlightStatus FlightStatus* Pointer to array of flight status
 * \param lenFlightStatus int Array of flight status length
 * \param order int [1] indicate UP - [0] indicate DOWN
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortPassengersByCode(Passenger* listPass, int lenPass, FlightCode* listFlightCode, int lenFlightCode, FlightStatus* listFlightStatus, int lenFlightStatus, int order);


/** \brief Print the content of passenger
 *
 * \param aPassenger Passenger* Pointer to one passenger
 * \param aTypePassenger TypePassenger* Pointer to passenger related type
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printAPassenger(Passenger* aPassenger, TypePassenger* aTypePassenger);


/** \brief Print the content of passengers array
 *
 * \param listPass Passenger* Pointer to array of passengers
 * \param lenPass int Array of passengers length
 * \param listTypePassenger TypePassenger* Pointer to array of type passengers
 * \param lenTypePassenger int Array of type passengers length
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printPassengers(Passenger* listPass, int lenPass, TypePassenger* listTypePassenger, int lenTypePassenger);


/** \brief Print the passengers by Status
 *
 * \param listPass Passenger* Pointer to array of passengers
 * \param lenPass int Array of passengers length
 * \param listFlightCode FlightCode* Pointer to array of flight codes
 * \param lenFlightCode int Array of flight codes length
 * \param listTypePassenger TypePassenger* Pointer to array of type passengers
 * \param lenTypePassenger int Array of type passengers length
 * \param listFlightStatus FlightStatus* Pointer to array of flight status
 * \param lenFlightStatus int Array of flight status length
 * \param status int Flight status
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printPassengersByStatus(Passenger* listPass, int lenPass, FlightCode* listFlightCode, int lenFlightCode, TypePassenger* listTypePassenger, int lenTypePassenger, FlightStatus* listFlightStatus, int lenFlightStatus, int status);


/** \brief Print the content of flight code
 *
 * \param aFlightCode FlightCode* Pointer to one flight code
 * \param aFlightStatus FlightStatus* Pointer to flight code related status
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printAFlightCode(FlightCode* aFlightCode, FlightStatus* aFlightStatus);


/** \brief Print the content of flight codes array
 *
 * \param listFlightCode FlightCode* Pointer to array of flight codes
 * \param lenFlightCode int Array of flight codes length
 * \param listFlightStatus FlightStatus* Pointer to array of flight status
 * \param lenFlightStatus int Array of flight status length
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printFlightCodes(FlightCode* listFlightCode, int lenFlightCode, FlightStatus* listFlightStatus, int lenFlightStatus);


/** \brief Print the info chosen
 *
 * \param listPass Passenger* Pointer to array of passengers
 * \param lenPass int Array of passengers length
 * \param listFlightCode FlightCode* Pointer to array of flight codes
 * \param lenFlightCode int Array of flight codes length
 * \param listTypePassenger TypePassenger* Pointer to array of type passengers
 * \param lenTypePassenger int Array of type passengers length
 * \param listFlightStatus FlightStatus* Pointer to array of flight status
 * \param lenFlightStatus int Array of flight status length
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int showReportsMenu(Passenger* listPass, int lenPass, FlightCode* listFlightCode, int lenFlightCode, TypePassenger* listTypePassenger, int lenTypePassenger, FlightStatus* listFlightStatus, int lenFlightStatus);


#endif /* NEXUS_H_ */

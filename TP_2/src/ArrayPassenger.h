#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_


#define NAME_LEN 51
#define LAST_NAME_LEN 51
#define FLIGHT_CODE_LEN 10
#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0

typedef struct
{
    int id;
    char name[NAME_LEN];
    char lastName[LAST_NAME_LEN];
    float price;
    char flightCode[FLIGHT_CODE_LEN];
    int typePassenger;
    int isEmpty;

} Passenger;


/** \brief To indicate that all position in the array are empty,
 *         this function put the flag (isEmpty) in TRUE in all position of the array
 *
 * \param list Passenger* Pointer to array of passengers
 * \param len int Array length
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initPassengers(Passenger* list, int len);


/** \brief Find the first free position
 *
 * \param list Passenger* Pointer to array of passengers
 * \param len int Array length
 *
 * \return int (-1) if [Invalid length or NULL pointer received or free space not found] or free space index position
 *
 */
int getEmptyIndex(Passenger* list, int len);


/** \brief Check if the array is empty
 *
 * \param list Passenger* Pointer to array of passengers
 * \param len int Array length
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (1) if True - (0) if False
 *
 */
int arrayIsEmpty(Passenger* list, int len);


/** \brief Load some passenger data to testing
 *
 * \param list Passenger* Pointer to array of passengers
 * \param len int Array length
 * \param id int* Passenger ID to load
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int hardCodePassengers(Passenger* list, int len, int* id);


/** \brief Add in a existing list of passengers the values received as parameters in the first empty position
 *
 * \param list Passenger* Pointer to array of passengers
 * \param len int Array length
 * \param id int Passenger ID to add
 * \param name[] char Passenger name to add
 * \param lastName[] char Passenger last name to add
 * \param price float Passenger price to add
 * \param flightCode[] char Passenger flight code to add
 * \param typePassenger int Passenger type passenger to add
 *
 * \return int (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, char flightCode[], int typePassenger);


/** \brief Find a Passenger by ID
 *
 * \param list Passenger* Pointer to array of passengers
 * \param len int Array length
 * \param id int Passenger ID to search
 *
 * \return int (-1) if [Invalid length or NULL pointer received or passenger not found] or passenger index position
 *
 */
int findPassengerById(Passenger* list, int len, int id);


/** \brief Compares the values of two string
 *
 * \param a char* First string
 * \param b char* Second string
 * \param length int String length
 *
 * \return int (-2) if Error
 *             (-1) if First string is less than Second string in value
 *             ( 0) if both string are equal
 *             ( 1) if First string is greater than Second string in value
 *
 */
int compareString(char* a, char* b, int length);


/** \brief Compares the values of two int
 *
 * \param a int First int
 * \param b int Second int
 *
 * \return int (-2) if Error
 *             (-1) if First int is less than Second int in value
 *             ( 0) if both int are equal
 *             ( 1) if First int is greater than Second int in value
 *
 */
int compareInt(int a, int b);


/** \brief Exchange the values of two passengers
 *
 * \param a Passenger* First Passenger
 * \param b Passenger* Second Passenger
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int swapPassengers(Passenger* a, Passenger* b);


/** \brief Sort the elements in the array of passengers. The order argument indicate UP or DOWN order
 *
 * \param list Passenger* Pointer to array of passengers
 * \param len int Array length
 * \param order int [1] indicate UP - [0] indicate DOWN
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortPassengers(Passenger* list, int len, int order);


/** \brief Set the chosen sort order
 *
 * \param option int* Memory space where the chosen order will be saved
 *
 * \return int (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
int chooseSortOrder(int* order);


/** \brief Calculate the passages prices sum
 *
 * \param list Passenger* Pointer to array of passengers
 * \param len int Array length
 * \param accumulator float* Pointer where the result is saved
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int accumulatePassagePrices(Passenger* list, int len, float* accumulator);


/** \brief Calculate the passages prices quantity
 *
 * \param list Passenger* Pointer to array of passengers
 * \param len int Array length
 * \param counter int* Pointer where the result is saved
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int countPassagePrices(Passenger* list, int len, int* counter);


/** \brief Calculate the passages prices average
 *
 * \param accumulator float Passages prices sum
 * \param counter int Passages prices quantity
 * \param average float* Pointer where the result is saved
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int getAveragePrice(float accumulator, int counter, float* average);


/** \brief Calculate how many passengers exceed the passage price average
 *
 * \param list Passenger* Pointer to array of passengers
 * \param len int Array length
 * \param average float Passage price average
 * \param counter int* Pointer where the result is saved
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int countExceededPricesFromAverage(Passenger* list, int len, float average, int* counter);


/** \brief Print options menu to choose
 *
 * \param option int* Memory space where the data entered by the user will be saved
 *
 * \return int (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
int showPassengersMenu(int* option);


#endif /* ARRAYPASSENGER_H_ */

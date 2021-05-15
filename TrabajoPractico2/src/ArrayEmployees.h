#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_


#define NAME_LEN 51
#define LAST_NAME_LEN 51
#define TRUE 1
#define FALSE 0

typedef struct
{
    int id;
    char name[NAME_LEN];
    char lastName[LAST_NAME_LEN];
    float salary;
    int sector;
    int isEmpty;

} Employee;


/** \brief To indicate that all position in the array are empty,
 *         this function put the flag (isEmpty) in TRUE in all position of the array
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);


/** \brief Find the first free position
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return int (-1) if [Invalid length or NULL pointer received or free space not found] or free space index position
 *
 */
int getEmptyIndex(Employee* list, int len);


/** \brief Check if the array is empty
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (1) if True - (0) if False
 *
 */
int arrayIsEmpty(Employee* list, int len);


/** \brief Load some employee data to testing
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int* Employee ID to load
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int hardCodeEmployees(Employee* list, int len, int* id);


/** \brief Load an employee data
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int* Employee ID to load
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int loadEmployee(Employee* list, int len, int* id);


/** \brief Add in a existing list of employees the values received as parameters in the first empty position
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int Employee ID to add
 * \param name[] char Employee name to add
 * \param lastName[] char Employee last name to add
 * \param salary float Employee salary to add
 * \param sector int Employee sector to add
 *
 * \return int (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);


/** \brief Find an Employee by ID
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int Employee ID to search
 *
 * \return int (-1) if [Invalid length or NULL pointer received or employee not found] or employee index position
 *
 */
int findEmployeeById(Employee* list, int len, int id);


/** \brief Modify an Employee by ID
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int Employee ID to modify
 *
 * \return int (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int modifyEmployee(Employee* list, int len, int id);


/** \brief Modify the Employee chosen data
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param index int Employee index position to modify
 *
 * \return int (-1) if Error [Invalid length or NULL pointer or invalid index or if can't modify the Employee] - (0) if Ok
 *
 */
int showModificationsMenu(Employee* list, int len, int index);


/** \brief Remove an Employee by ID (put isEmpty flag in TRUE)
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int Employee ID to remove
 *
 * \return int (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);


/** \brief Sort the elements in the array of employees. The order argument indicate UP or DOWN order
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param order int [1] indicate UP - [0] indicate DOWN
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);


/** \brief Sort employees according to chosen order
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int showSortMenu(Employee* list, int len);


/** \brief Print the content of employee
 *
 * \param anEmployee Employee* Pointer to an employee
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printAnEmployee(Employee* anEmployee);


/** \brief Print the content of employees array
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printEmployees(Employee* list, int len);


/** \brief Calculate the employee salaries sum
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param accumulator float* Pointer where the result is saved
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int accumulateEmployeeSalaries(Employee* list, int len, float* accumulator);


/** \brief Calculate the employee salaries quantity
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param counter int* Pointer where the result is saved
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int countEmployeeSalaries(Employee* list, int len, int* counter);


/** \brief Calculate the salaries average
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param average float* Pointer where the result is saved
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int getAverageSalary(Employee* list, int len, float* average);


/** \brief Calculate how many employees exceed the salary average
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param counter int* Pointer where the result is saved
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int countExceededSalariesFromAverage(Employee* list, int len, int* counter);


/** \brief Print options menu to choose
 *
 * \param option int* Memory space where the data entered by the user will be saved
 *
 * \return int (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
int showEmployeesMenu(int* option);


/** \brief Print the info chosen
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int showReportsMenu(Employee* list, int len);


#endif /* ARRAYEMPLOYEES_H_ */

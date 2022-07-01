#ifndef CALCULADORA_H_
#define CALCULADORA_H_


/** \brief Se calcula la suma entre 2 números
 *
 * \param x double Es el primer número
 * \param y double Es el segundo número
 * \param pResultado double* Lugar donde se guardará el resultado de la suma
 *
 * \return int Devuelve 0 si está todo Ok, o -1 si hubo un error
 *
 */
int sumar(double x, double y, double* pResultado);


/** \brief Se calcula la resta entre 2 números
 *
 * \param x double Es el primer número
 * \param y double Es el segundo número
 * \param pResultado double* Lugar donde se guardará el resultado de la resta
 *
 * \return int Devuelve 0 si está todo Ok, o -1 si hubo un error
 *
 */
int restar(double x, double y, double* pResultado);


/** \brief Se calcula la división entre 2 números
 *
 * \param x double Es el primer número
 * \param y double Es el segundo número
 * \param pResultado double* Lugar donde se guardará el resultado de la división
 *                           en caso de que el divisor no sea cero
 *
 * \return int Devuelve 0 si el segundo número (divisor) es distinto de cero,
 *             o -1 si el segundo número es igual a cero
 *
 */
int dividir(double x, double y, double* pResultado);


/** \brief Se calcula la multiplicación entre 2 números
 *
 * \param x double Es el primer número
 * \param y double Es el segundo número
 * \param pResultado double* Lugar donde se guardará el resultado de la multiplicación
 *
 * \return int Devuelve 0 si está todo Ok, o -1 si hubo un error
 *
 */
int multiplicar(double x, double y, double* pResultado);


#endif /* CALCULADORA_H_ */

#ifndef CALCULADORA_H_
#define CALCULADORA_H_


/** \brief Se calcula la suma entre 2 números
 *
 * \param x float Es el primer número
 * \param y float Es el segundo número
 * \param pResultado float* Lugar donde se guardará el resultado de la suma
 *
 * \return int Devuelve 0 si está todo Ok, o -1 si hubo un error
 *
 */
int sumar(float x, float y, float* pResultado);


/** \brief Se calcula la resta entre 2 números
 *
 * \param x float Es el primer número
 * \param y float Es el segundo número
 * \param pResultado float* Lugar donde se guardará el resultado de la resta
 *
 * \return int Devuelve 0 si está todo Ok, o -1 si hubo un error
 *
 */
int restar(float x, float y, float* pResultado);


/** \brief Se calcula la división entre 2 números
 *
 * \param x float Es el primer número
 * \param y float Es el segundo número
 * \param pResultado float* Lugar donde se guardará el resultado de la división
 *                          en caso de que el divisor no sea cero
 *
 * \return int Devuelve 0 si el segundo número (divisor) es distinto de cero,
 *             o -1 si el segundo número es igual a cero
 *
 */
int dividir(float x, float y, float* pResultado);


/** \brief Se calcula la multiplicación entre 2 números
 *
 * \param x float Es el primer número
 * \param y float Es el segundo número
 * \param pResultado float* Lugar donde se guardará el resultado de la multiplicación
 *
 * \return int Devuelve 0 si está todo Ok, o -1 si hubo un error
 *
 */
int multiplicar(float x, float y, float* pResultado);


/** \brief Se calcula el factorial de un número
 *
 * \param n int Es el número a calcular
 * \param pResultado unsigned long int* Lugar donde se guardará el resultado del factorial
 *                                      en caso de que el número sea mayor o igual a cero
 *
 * \return int Devuelve 0 si el número es mayor o igual a cero, o -1 si hubo un error
 *
 */
int factorial(int n, unsigned long int* pResultado);


#endif /* CALCULADORA_H_ */

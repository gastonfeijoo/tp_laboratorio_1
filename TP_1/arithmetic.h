/** \brief Calcula la suma de dos numeros
 *
 * \param firstOperand float Primer numero a sumar
 * \param secondOperand float Segundo Numero a sumar
 * \return float Resultado de la suma
 *
 */
float AddTwoNumbers(float firstOperand,float secondOperand);
/** \brief Calcula la resta de dos numeros
 *
 * \param firstOperand float Primer numero a restar
 * \param secondOperand float Segundo numero a restar
 * \return float Resultado de la resta
 *
 */
float SubstractTwoNumbers(float firstOperand,float secondOperand);
/** \brief Calcula la multiplicacion de dos numeros
 *
 * \param firstOperand float Primer numero a multiplicar
 * \param secondOperand float Segundo numero a multiplicar
 * \return float Resultado de la numtiplicacion
 *
 */
float MultiplyTwoNumbers(float firstOperand,float secondOperand);
/** \brief Divide dos numeros (tiene proteccion contra division por cero)
 *
 * \param firstOperand float El numerador
 * \param secondOperand float El divisor
 * \return float Resultado de la division (Devuelve cero si el divisor es cero)
 *
 */
float DivideTwoNumbers(float firstOperand,float secondOperand);
/** \brief Calcula el factorial de un numero positivo y entero (devuelve cero si tiene parte fraccionaria)
 *
 * \param number float El numero a calcular el factorial
 * \return unsigned long int El resultado factorial (devuelve cero si tiene parte fraccionaria)
 *
 */
unsigned long int CalculateFactorial(float number);

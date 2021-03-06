#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Pide el ingreso por teclado de un n�mero al usuario, mostrandole un mensaje personalizado.
 *
 * \param char[] Mensaje a mostrar al usuario.
 * \return float El n�mero ingresado por el usuario.
 *
 */
float pedirFlotante(char[], float, float);

/** \brief Pide un n�mero flotante al usuario
 *
 * \param Mensaje a mostrar al usuario
 * \return El n�mero ingresado por el usuario
 *
 */
float pedirFlotanteSinValidar(char[]);

/** \brief Pide un n�mero entero al usuario y lo valida
 *
 * \param Mensaje a mostrar al usuario
 * \param Valor m�nimo del intervalo de validaci�n
 * \param Valor m�ximo del intervalo de validaci�n
 * \return El n�mero ingresado por el usuario validado
 *
 */
int pedirEntero(char[], int, int);

/** \brief Pide un n�mero entero al usuario y lo valida
 *
 * \param Mensaje a mostrar al usuario
 * \param Valor m�nimo del intervalo de validaci�n
 * \param Valor m�ximo del intervalo de validaci�n
 * \return El n�mero ingresado por el usuario validado
 *
 */
int validarEntero(int, int, int);

/** \brief Pide un n�mero entero al usuario
 *
 * \param Mensaje a mostrar al usuario
 * \return El n�mero ingresado por el usuario
 *
 */
int pedirEnteroSinValidar(char[]);

/** \brief Pide un n�mero flotante al usuario y lo valida
 *
 * \param Mensaje a mostrar al usuario
 * \param Valor m�nimo del intervalo de validaci�n
 * \param Valor m�ximo del intervalo de validaci�n
 * \return El n�mero ingresado por el usuario validado
 *
 */
float validarFlotante(float, float, float);

/** \brief Pide un n�mero doble al usuario y lo valida
 *
 * \param Mensaje a mostrar al usuario
 * \param Valor m�nimo del intervalo de validaci�n
 * \param Valor m�ximo del intervalo de validaci�n
 * \return El n�mero ingresado por el usuario validado
 *
 */
double pedirDoble(char[], double, double);

/** \brief Pide un n�mero doble al usuario y lo valida
 *
 * \param Mensaje a mostrar al usuario
 * \param Valor m�nimo del intervalo de validaci�n
 * \param Valor m�ximo del intervalo de validaci�n
 * \return El n�mero ingresado por el usuario validado
 *
 */
double validarDoble(double, double, double);

/** \brief Pide un n�mero entero largo al usuario y lo valida
 *
 * \param Mensaje a mostrar al usuario
 * \param Valor m�nimo del intervalo de validaci�n
 * \param Valor m�ximo del intervalo de validaci�n
 * \return El n�mero ingresado por el usuario validado
 *
 */
long pedirLargo(char[], long, long);

/** \brief Pide un n�mero entero largo al usuario y lo valida
 *
 * \param Mensaje a mostrar al usuario
 * \param Valor m�nimo del intervalo de validaci�n
 * \param Valor m�ximo del intervalo de validaci�n
 * \return El n�mero ingresado por el usuario validado
 *
 */
long validarLargo(long, long, long);

/** \brief Pide una cadena de caracteres al usuario validando que no supere el tama�o definido
 *         para evitar desbordamiento
 *
 * \param char[] Mensaje a mostrar al usuario
 * \param char[] La cadena ingresada por el usuario y validada
 * \param int Longitud m�xima de la cadena de caracteres
 * \return void
 *
 */
void pedirString(char[], char[], int);

/** \brief Valida que una cadena de caracteres no supere el tama�o definido para evitar desbordamiento
 *
 * \param char[] La cadena ingresada por el usuario
 * \param int Longitud m�xima de la cadena de caracteres
 * \return void
 *
 */
void validarString(char[], int);

/** \brief Calcula la suma de dos n�meros.
 *
 * \param float Primer t�rmino de la suma.
 * \param float Segundo t�rmino de la suma.
 * \return float Resultado de la suma de ambos t�rminos.
 *
 */
float calcularSuma(float, float);

/** \brief Calcula la resta de dos n�meros.
 *
 * \param float Primer t�rmino de la resta.
 * \param float Segundo t�rmino de la resta.
 * \return float Resultado de la resta de ambos t�rminos.
 *
 */
float calcularResta(float, float);

/** \brief Calcula la divisi�n de dos n�meros.
 *
 * \param float Primer t�rmino de la divisi�n.
 * \param float Segundo t�rmino de la divisi�n.
 * \return float Resultado de la divisi�n de ambos t�rminos.
 *
 */
float calcularCociente(float, float);

/** \brief Valida los dos t�rminos de una divisi�n.
 *         Devuelve error si el segundo t�rmino de la divisi�n (o divisor) es cero.
 *         Si el primer t�rmino (o dividendo) tambi�n es cero especifica en el error que se trata de una indeterminaci�n.
 *
 * \param float Primer t�rmino de la divisi�n.
 * \param float Segundo t�rmino de la divisi�n.
 * \return int Resultado de la validaci�n:
 *             0 -> Validaci�n OK.
 *             1 -> ERROR. Divisi�n por cero sin indeterminaci�n.
 *             2 -> ERROR. Divisi�n por cero con indeterminaci�n.
 *
 */
int validarCociente(float, float);

/** \brief Calcula la multiplicaci�n de dos n�meros.
 *
 * \param float Primer t�rmino de la multiplicaci�n.
 * \param float Segundo t�rmino de la multiplicaci�n.
 * \return float Resultado de la multiplicaci�n de ambos t�rminos.
 *
 */
float calcularProducto(float, float);

/** \brief Calcula el factorial de un n�mero.
 *
 * \param float N�mero al cual se le va a calcular el factorial.
 * \return int Factorial del n�mero ingresado por par�metro.
 *
 */
int calcularFactorial(float);

/** \brief Valida si es posible calcular el factorial de un n�mero.
 *         Devuelve error para los casos en que el n�mero es negativo o no es entero.
 *
 * \param float N�mero que se va a validar para la operaci�n factorial.
 * \return int Resultado de la validaci�n:
 *             0 -> Validaci�n OK.
 *             1 -> ERROR. Factorial de n�mero decimal.
 *             2 -> ERROR. Factorial de n�mero negativo.
 *
 */
int validarFactorial(float);

/** \brief Llama a la rutina de Windows que limpia la pantalla de la consola.
 *
 * \param void
 * \return void
 *
 */
void limpiarPantalla(void);

/** \brief Llama a la rutina de Windows que pausa la ejecuci�n.
 *
 * \param void
 * \return void
 *
 */
void pausarEjecucion(void);

/** \brief Valida si un n�mero pasado por par�metro es entero o decimal.
 *
 * \param float N�mero que se va a validar.
 * \return int Resultado de la validaci�n:
 *             0 -> El n�mero es entero.
 *             1 -> El n�mero es decimal.
 *
 */
int validarEnteroDecimal(float);

/** \brief Valida si un n�mero pasado por par�metro es entero largo o decimal.
 *
 * \param float N�mero que se va a validar.
 * \return int Resultado de la validaci�n:
 *             0 -> El n�mero es entero.
 *             1 -> El n�mero es decimal.
 *
 */
int validarLargoDecimal(float);

/** \brief --> Qu� hace la funci�n, por ejemplo "Permite sumar dos n�meros enteros".
 *
 * \param --> Primer n�mero a sumar
 * \param --> Segundo n�mero a sumar
 * \return --> El resultado de la suma de los n�meros
 *
 */
int sumarNumeros (int, int);

void mostrarVector(int[], int);
void cargarVector(int[], int);
void cargarVectorAleatorio(int[], int, char[]);
void ordenarVectorMayorMenor(int[], int);
void ordenarVectorMenorMayor(int[], int);
int buscarMaximo(int[], int);
int buscarMinimo(int[], int);
int buscarPosicionElemento(int[], int, int);
void transformarApellidoNombre(const char[], const char[], char[]);

#endif // FUNCIONES_H_INCLUDED

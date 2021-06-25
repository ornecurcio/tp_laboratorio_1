/*
 *
 *  Created on: 1 abr. 2021
 *      Author: orne_
 */

#ifndef UTN_H_
#define UTN_H_

void getString(char mensaje[], char imput[]);
void getChar(char* mensaje, char* rta);
/**
 * \brief
 * \param char* cadena es un puntero donde se va a guardar el string
 * \param longitud, la longitud del cadena de caracteres
 * return Retorna 0 si se valido con exito la toma del string.
 */
int myGets(char* cadena, int longitud);
/**
 * \brief OBTIENE UN NUMERO ENTERO
 * \param pResultado es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * return Retorna 0 si se valido con exito o -1, si es error.
 */
int getInt(int* pResultado);
/**
 * \brief valida que la cadena obtenida sea numerica
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud es la longitud maxima de la cadena de caracteres
 * return Retorna 1 si los caracteres son todos numericos, tomando en cuenta que puede haber
 * un signo + o menos en la posicion cero,  o 0, SI ES ERROR.
 */
int esNumerica(char* cadena, int longitud);

/*obtiene un numero entero, asigno el resultado a un espacio de memoria,
 * muestra un mensaje de ingreso de dato, un mensaje de error si la validacion esta mal,
 * valida contra minimo y maximo
 * estable cantidad de reintentos de error.
 * */
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

/**
 * \brief valida que la cadena obtenida es FLOTANTE
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * return Retorna 0 si el numero es flotante, -1, SI ES ERROR.
 */
int getFloat(float* pResultado);
/**
 * \brief valida que la cadena obtenida sea flotante
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud es la longitud maxima de la cadena de caracteres
 * return Retorna 1 si la cadena es flotante,o 0, SI ES ERROR.
 */
int esFlotante(char* cadena, int longitud);
/**
 * \brief Solicita un numero FLOTANTE al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje es el mensaje a ser mostrado al usuario
 * \param mensajeError es el mensaje a ser mostrado al usuario cuando lo ingresado es incorrecto
 * \param minimo es el numero minimo a ser aceptado
 * \param maximo es el numero maximo a ser aceptado
 *  \return Retorna 0 si se obtuvo el numero o, 1 SI ES ERROR.
 */
int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);

int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);

int inicializarArrayFlotante(float pArray[], int cantidadDeArray);
int imprimirArrayFlotante(float pArray[], int cantidadDeArray);
int inicializarArrayCadena(char pArray[][20], int cantidadDeArray);
int utn_SwapAscendiente(int listaDeArray[],int cantidadDeArray);
int utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos);
/**
 * \brief 	Verifica una cadena recibida como parametro para determinir
 * 			si es un nombre valido
 * \param char* cadena, Cadena a analizar
 * \param int longitud, indica la cantidad de letras maxima de la cadena
 * \return (0) Indicar que no es un nombre valido / (1) Indica que que es un nombre valido
 *
 */
int esNombre(char* cadena,int longitud);
/**
 * \brief valida que la cadena obtenida es Nombre
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * return Retorna 0 si el numero es flotante, -1, SI ES ERROR.
 */
int getNombre(char* pResultado, int longitud);
/**
 * \brief Solicita un nombre al usuario
 * \param char* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int limite, indica la cantidad de letras maxima del nombre
 * \return (-1) Error / (0) Ok
 */
int utn_getNombre(char* pResultado, char* mensaje, char* mensajeError,int reintentos, int longitud);
/**
 * \brief valida que la cadena son solo letras
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * return Retorna 1 si todo ok, 0, SI ES ERROR.
 */
int esSoloLetra(char *pResultado) ;
/**
 * \brief valida que la cadena son solo letras y espacio en el medio
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * return Retorna 1 si todo ok, 0, SI ES ERROR.
 */
int esLetraConEspacio(char *pResultado);
/**
 * \brief valida numero de telefono se acepta - y espacio
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * return Retorna 1 si todo ok, 0, SI ES ERROR.
 */
int esTelefonoValido(char* cadena);
/**
 * \brief Solicita un telefono al usuario
 * \param char* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param minSize, cantidad minima de numero
 * \param maxSize, cantidad maxima de numero
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int min, numero minimo,
 * \param int max, numero maximo,
 * \return (-1) Error / (0) Ok
 */
int utn_getTelefono(char* pResultado, char* mensaje, char* mensajeError, int minSize, int maxSize, int min, int max, int reintentos);
/**
 * \brief valida apellido con caracter especial y espacio
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud maxima
 * return Retorna 1 si todo ok, 0, SI ES ERROR.
 */
int esApellido(char* cadena,int longitud);
/**
 * \brief valida apellido con caracter especial y espacio y da formato
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud maxima
 * return Retorna 0 si todo ok, -1, SI ES ERROR.
 */
int getApellido(char* pResultado, int longitud);
/**
 * \brief Solicita un apellido al usuario
 * \param char* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int limite, indica la cantidad de letras maxima del nombre
 * \return (-1) Error / (0) Ok
 */
int utn_getApellido(char* pResultado, char* mensaje, char* mensajeError,int reintentos, int longitud);
/**
 * \brief da formato a un apellido/nombre, coloca la primer letra en mayuscula
 * \param puntero a string
 */
void daFormaApellido(char* pResultado);
/**
 * \brief da formato a un apellido/nombre, y concatena
 * \param puntero a string
 * \param puntero a string
 * \param puntero a guardar nombre y apellido con formato
 */
void FormaApellidoNombre(char *pNombre, char *pApellido, char *pCompleto);
/**
 * \brief valida cuit especial -
 * \param cadena
 * return Retorna 0 si todo ok, -1, SI ES ERROR.
 */
int esCUIT(char* cadena);
/**
 * \brief Solicita un cuit al usuario
 * \param char* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \return (-1) Error / (0) Ok
 */
int utn_getCUIT(char* pResultado, char* mensaje, char* mensajeError, int reintentos);
/**
 * \brief pregunta de validacion si/no al usuario
 * return Retorna 0 si si.
 */
int utn_getCaracterSN(void);
/**
 * \brief da formato a un apellido/nombre, coloca la primer letra en mayuscula
 * \param puntero a string
 */
void daFormaNombre(char *pResultado);
#endif /* UTN_H_ */

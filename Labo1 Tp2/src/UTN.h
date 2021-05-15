

#ifndef UTN_H_
#define UTN_H_
//====LAS FUNCIONES esALGO devuelve 1 si todo ok, resto 0 si todo OK
/**
 * \brief
 * \param char* mensaje es un puntero para mostrar un mensaje al usuario
 * \param imput, array donde se guarda el mensaje
 * return sin retorno.
 */
void getString(char mensaje[], char imput[]);
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
 * \brief valida que la cadena obtenida es FLOTANTE
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * return Retorna 0 si el numero es flotante, -1, SI ES ERROR.
 */
int getFloat(int* pResultado);
/**
 * \brief valida que la cadena obtenida es Nombre
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * return Retorna 0 si es todo bien, (-1 SI ES ERROR).
 */
int getNombre(char* pResultado, int longitud);
/**
 * \brief valida que la cadena obtenida sea numerica
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud es la longitud maxima de la cadena de caracteres
 * return Retorna 1 si los caracteres son todos numericos, tomando en cuenta que puede haber
 * un signo + o menos en la posicion cero,  o 0, SI ES ERROR.
 */
int esNumerica(char* cadena, int longitud);
/**
 * \brief valida que la cadena obtenida sea flotante
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud es la longitud maxima de la cadena de caracteres
 * return Retorna 1 si todo ok=la cadena es flotante,o --0, SI ES ERROR--
 */
int esFlotante(char* cadena, int longitud);
/**
 * \brief 	Verifica una cadena recibida como parametro para determinar si es un nombre valido
 * \param char* cadena, puntero cadena a verificar
 * \param int longitud, indica la cantidad de letras maxima de la cadena
 * \return Retorna 1 si todo ok=la cadena es un nombre --0, SI ES ERROR--
 */
int esNombre(char* cadena,int longitud);
/**
 * \brief 	Verifica una cadena recibida como parametro para determinar si tiene solo letras
 * \param char* cadena, puntero cadena a verificar
 * \return Retorna 1 si todo ok=la cadena es un nombre --0, SI ES ERROR--
 */
int esSoloLetra(char *pResultado) ;
/**
 * \brief 	Verifica una cadena recibida como parametro para determinar si tiene solo letras con algun espacio
 * \param char* cadena, puntero cadena a verificar
 * \return Retorna 1 si todo ok=la cadena es un nombre --0, SI ES ERROR--
 * DE LEJOS PARECE QUE DICE ES SOLTERA, PERO NO!
 */
int esLetraConEspacio(char *pResultado);
/*
 * \brief obtiene un numero entero, asigno el resultado a un espacio de memoria,
 * \param mensaje muestra un mensaje de ingreso de dato, un mensaje de error si la validacion esta mal,
 * \param mensaje error, muestra mensaje cuando no esta bien
 * \param minimo valida contra el minimo num que queramos usar
 * \param maximo valida contra el maximo num que queramos usar
 * \param reintentos estable cantidad de reintentos de error.
 * \retun 0 si todo ok, -1 ERROR
 * */
utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
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
/**
 * \brief Solicita un nombre al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int limite, indica la cantidad de letras maxima del nombre
 * \return (-1) Error / (0) Ok
 *
 */
int utn_getNombre(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int longitud);
/**
 * \brief Solicita un caracter al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param char* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param max y minimo, son el limite entre las letras que quiero usar
 * \return (-1) Error / (0) Ok
 * NO PUEDO CRRER Q LLEGASTE HASTA ACA! APLAUSOS! TE MERECES UN CAFE
 */
int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);

int utn_getCaracterSexo(char* pResultado,char* mensaje,char* mensajeError, char string[][20], int cantidadArray, int reintentos);
//======== SORRY aca ya me canse de escribir, pero tienen nombre claro mis funciones :)
int inicializarArrayFlotante(float pArray[], int cantidadDeArray);
int imprimirArrayFlotante(float pArray[], int cantidadDeArray);
int inicializarArrayCadena(char pArray[][20], int cantidadDeArray);
int utn_SwapAscendiente(int listaDeArray[],int cantidadDeArray);
int utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos);
void FormaApellidoNombre(char *pNombre, char *pApellido, char *pCompleto);

#endif /* UTN_H_ */

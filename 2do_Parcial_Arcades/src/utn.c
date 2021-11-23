/*
 * utn.c
 *
 *
 *      Author: Eduard Brito
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int getInt(int *pResultado);
static int esNumero(char cadena[]);
static float getFloat(float *pResultado);
static float esNumeroConComa(char cadena[]);
static char getChar(char Resultado[], int tamano);
static char esCaracter(char cadena[]);
static int myGets(char cadena[], int longitud);

/**
 *\brief
 *\param
 *\return 0 si salio todo BIEN, si no devuelve un -1
 *
 */
static int myGets(char cadena[], int longitud) {
	int retorno = -1;

	if (cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)
	{
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n')
		{
			cadena[strlen(cadena) - 1] = '\0';
			retorno = 0;
		}
	}
	return retorno;
}
/**
 *\brief
 *\param
 *\return 0 si salio todo BIEN, si no devuelve un -1.
 *
 */
static int getInt(int *pResultado) {
	int retorno = -1;
	char buffer[64];


	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumero(buffer) == 0)
		{
			retorno = 0;
			*pResultado = atoi(buffer);
		}
	}

	return retorno;
}
/**
 *\brief  Valida que la cadena que recibe sea un numero entero.
 *\param  char cadena[] la variable que se recibe para analizar
 *\return 0 si salio todo BIEN, si no devuelve un 1.
 *
 */
static int esNumero(char cadena[]) {
	int i = 0;
	int retorno = -1;

	if (cadena != NULL && strlen(cadena) > 0)
	{
		retorno = 0;
		if (cadena[0] == '-')
		{
			i = 1;
		}

		for (; cadena[i] != '\0'; i++)
		{
			if (cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 1;
				break;
			}

			i++;
		}
	}
	return retorno;
}

/**
 *\brief  Valida que la cadena que recibe sea un numero entero.
 *\param  char cadena[] la variable que se recibe para analizar
 *\return 0 si salio todo BIEN, si no devuelve un 1.
 *
 */
int esNumeroValidacion(char* cadena) {
	int i = 0;
	int retorno = -1;
	if (cadena != NULL && strlen(cadena) > 0) {
		retorno = 0;
		if (cadena[0] == '-') {
			i = 1;
		}
		for (; cadena[i] != '\0'; i++) {
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 1;
				break;
			}
			i++;
		}
	}
	return retorno;
}

/**
 *\brief
 *\param
 *\return 0 si salio todo BIEN, si no devuelve un -1
 *
 */
static float getFloat(float *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0
				&& esNumeroConComa(buffer) == 0) {
			retorno = 0;
			*pResultado = atof(buffer);
		}
	}
	return retorno;
}
/**
 *\brief Valida que la cadena que recibe sea un numero decimal.
 *\param char cadena[] la variable que se recibe para analizar
 *\return Un 0 si salio todo bien, si no devuelve un 1.
 *
 */
static float esNumeroConComa(char cadena[]) {
	int i = 0;
	int retorno = -1;
	int punto = 0;

	if (cadena != NULL && strlen(cadena) > 0) {
		retorno = 0;
		if (cadena[0] == '-') {
			i = 1;
		}
		for (; cadena[i] != '\0'; i++) {

			if (punto == 0 && cadena[i] == '.') {
				punto = 1;
				continue;
			}
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 1;
				printf("INGRESO AL ERROR ");
				break;
			}
			i++;
		}
	}
	return retorno;
}
/**
 *\brief
 *\param
 *\return 0 si salio todo BIEN, si no devuelve un -1.
 *
 */
static char getChar(char Resultado[], int tamano) {
	int retorno = -1;
	char buffer[100];

	if (Resultado != NULL && tamano > 0) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esCaracter(buffer) == 0) {
			retorno = 0;
			strncpy(Resultado, buffer, tamano);
		}
	}
	return retorno;
}
/**
 *\brief Valida que la cadena que recibe sea un String.
 *\param char cadena[] la variable que se recibe para analizar.
 *\return Un 0 si salio todo bien, si no devuelve un 1.
 *
 */
static char esCaracter(char cadena[]) {
	int i = 0;
	int retorno = -1;
	if (cadena != NULL && strlen(cadena) > 0) {
		retorno = 0;
		for (i = 0;/*strlen(cadena) > i &&*/cadena[i] != '\0'; i++) {
			if ((cadena[i] < 'a' || cadena[i] > 'z')
					&& (cadena[i] < 'A' || cadena[i] > 'Z')
					&& cadena[i] != ' ') {
				retorno = 1;
				//printf("INGRESE AL ERROR DE esCaracter\n");
				break;
			}
			i++;
			//printf("INGRESO AL FOR DE ESCARACTER\n");
		}

	}
	return retorno;
}
/**
 *\brief Recibe una cadena la valida y la devuelve.
 *\param Char[] recibe la cadena.
 *\param tamano recibe el tamano de la cadena.
 *\param reintento recibe la cantidad de veces que se puede reintentar.
 *\param pTexto recibe la direccion de memoria de un mensaje.
 *\param pTextoError recibe la direccion de memoria del mensaje de error.
 *\return 1 si salio todo BIEN, si no devuelve 0.
 */
char pedirCadena(char Char[], int tamano, int reintento, char *pTexto,
		char *pTextoError) {
	int auxRetorno = -1;
	int retorno;
	char auxChar[100];

	if (Char != NULL && reintento >= 0 && pTexto != NULL && pTextoError != NULL) {
		for (int i = 0; i < reintento; i++) {
			printf("%s", pTexto);
			fflush(stdin);
			if (getChar(auxChar, sizeof(auxChar)) == 0) {
				strncpy(Char, auxChar, tamano);
				auxRetorno = 1;
				break;
			} else {
				printf("%s\n", pTextoError);
				reintento--;
				auxRetorno = 0;
			}
			fflush(stdin);
		}

	}
	retorno = auxRetorno;
	return retorno;
}
/**
 *\brief Recibe un numero y valida que sea entero y lo devuelve.
 *\param pInt recibe el puntero de un int.
 *\param min numero minimo que puede recibir la funcion.
 *\param max numero maximo que puede recibir la fucion.
 *\param reintento recibe la cantidad de veces que se puede reintentar.
 *\param pTexto recibe la direccion de memoria de un mensaje.
 *\param pTextoError recibe la direccion de memoria del mensaje de error.
 *\return 1 si salio todo BIEN, si no devuelve 0.
 *
 */
int pedirEntero(int *pInt, int min, int max, int reintento,
		char *pTexto, char *pTextoError)
{
	int auxRetorno;
	int retorno;
	int auxInt;

	if (pInt != NULL && min < max && reintento>=0 &&
		pTexto != NULL && pTextoError != NULL)
	{
		for (int i = 0; i < reintento; i++)
		{
			printf("%s", pTexto);
			fflush(stdin);


				if (getInt(&auxInt) == 0 && auxInt >= min && auxInt <= max)
				{
					*pInt = auxInt;
					auxRetorno = 1;
					break;

				} else {
					printf("%s\n", pTextoError);
					reintento--;
					auxRetorno = 0;
					}

			fflush(stdin);
		}
	}

	retorno = auxRetorno;
	return retorno;
}
/**
 *\brief Recibe un numero y valida que sea decimal y lo devuelve.
 *\param pFloat recibe el puntero de un float.
 *\param min numero minimo que puede recibir la funcion.
 *\param max numero maximo que puede recibir la fucion.
 *\param reintento recibe la cantidad de veces que se puede reintentar.
 *\param pTexto recibe la direccion de memoria de un mensaje.
 *\param pTextoError recibe la direccion de memoria del mensaje de error.
 *\return 1 si salio todo BIEN, si no devuelve 0.
 *
 */
float pedirFlotante(float *pFloat /*int min, int max*/, int reintento,
		char *pTexto, char *pTextoError) {
	int auxRetorno;
	int retorno;
	float auxFloat;

	if (pFloat != NULL /*&& min<max*/
	&& reintento >= 0 && pTexto != NULL && pTextoError != NULL) {
		for (int i = 0; i < reintento; i++) {
			printf("%s", pTexto);

			if (getFloat(&auxFloat) == 0) {
				//if(auxFloat >= min && auxFloat <= max)
				//{
				*pFloat = auxFloat;
				auxRetorno = 1;
				break;
			} else {
				printf("%s\n", pTextoError);
				reintento--;
				auxRetorno = 0;
			}
			//}
			fflush(stdin);
		}

	}
	retorno = auxRetorno;
	return retorno;
}
/**
 *\brief Recibe una cadena valida que sea un CUIT y lo devuelve.
 *\param auxiliar[] recibe la cadena.
 *\param mensaje recibe la direccion de memoria de un mensaje.
 *\param mensajeError recibe la direccion de memoria del mensaje de error.
 *\param reintento recibe la cantidad de veces que se puede reintentar.
 *\return 1 si salio todo BIEN, si no devuelve 0.
 */
int utn_pedirCuit(char auxiliar[], char *mensaje, char *mensajeError,
		int reintentos) {

	int retorno = 0;
	char bufferString[14];

	if (auxiliar != NULL && mensaje != NULL && mensajeError != NULL
			&& reintentos > 0) {
		do {
			printf("%s", mensaje);
			fflush(stdin);
			if (fgets(bufferString, 14, stdin) != NULL) {

				if (strlen(bufferString) == 13) {
					if (bufferString[2] == '-' && bufferString[11] == '-') {

						for (int i = 0; bufferString[i] != '\0'; i++) {

							if (bufferString[i] == '-'
									|| isdigit(bufferString[i]) == 1) {
								continue;
							} else {
								reintentos--;
								printf("%s", mensajeError);
								break;
							}
						}
						strcpy(auxiliar, bufferString);
						retorno = 1;
						break;

					} else {
						reintentos--;
						printf("%s", mensajeError);
					}

				} else {
					reintentos--;
					printf("%s", mensajeError);
				}
			} else {
				reintentos--;
				printf("%s", mensajeError);
			}

		} while (reintentos > 0);
	}
	return retorno;
}
/**
 *\brief Muestra el menu y escribe en la direccion de memoria de una variable el numero de la opcion ingresada.
 *\param opcion recibe el puntero de un Int.
 *\return void.
 */
void mostrarMenu(int *opcion) {
	int auxOpcion;


	printf(
			" \n _____________________ _MENU___________________________");
	printf( "\n |                                                      |"
			"\n | 1. LEER ARCADES DESDE ARCHIVO CSV.                   |"
			"\n | 2. INCORPORAR ARCADE.                                |"
			"\n | 3. MODIFICAR ARCADE.                                 |"
			"\n | 4. ELIMINAR ARCADE.                                  |"
			"\n | 5. IMPRIMIR ARCADES (Ordenados por nombre de juego). |"
			"\n | 6. Generar archivo con JUEGOS                        |"
			"\n | 7. Generar un archivo con arcades (Multijugador).    |"
			"\n | 8. Actualizar cantidad de fichas.                    |"
			"\n | 9. SALIR.                                            |"
			"\n |______________________________________________________|\n"

			);

	if(pedirEntero(&auxOpcion, 1, 9, 3, "\n Ingrese una opcion: ",
			"\n Error, ingrese una opcion del 1 al 9: \n\n")==1){
		*opcion = auxOpcion;
	}

	return;
}

int utn_getCharRespSoN(char *variableChar, char *mensaje, char *mensajeError, int reintentos){
	int rtn = -1;
	char bufferChar;

	if(variableChar != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{
		do
		{
			printf("%s \n", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);

			if(bufferChar == 's' || bufferChar == 'n')
			{
				*variableChar = bufferChar;
				rtn = 0;
				break;
			}
			else
				{
					printf("%s", mensajeError);
					reintentos--;
					printf("%d", reintentos);
				}

		}while(reintentos>0);

	}
	return rtn;
}

void mostrarSubMenu(int *opcion) {
	int auxOpcion;


	printf(
			" \n ____________________________________***MENU INFORMES*** ________________________________________________");
	printf(
			"\n |                                                                                                        |"
			"\n | 	1) Listar los salones con mas de 4 arcades. Indicando ID de salon, nombre, direccion y tipo de salon.|"
			"\n |                                                                                                    	 |"
			"\n |	2) Listar los arcades para mas de 2 jugadores, indicando ID de arcade, cantidad de jugadores,        |"
			"\n |	nombre del juego y nombre del salon al que pertenece.                                                |"
			"\n |                                                                                                        |"
			"\n |	3) Listar toda la informacion de un salon en especifico ingresando su ID. Imprimir nombre,           |"
			"\n |	tipo y direccion y cantidad de arcades que posee.                                                    |"
			"\n |                                                                                                        |"
			"\n |	4) Listar todos los arcades de un salon determinado ingresando su ID. Informar nombre y tipo         |"
			"\n |	de salon, listar todos los arcades con sus datos junto con el nombre del juego que lo compone.       |"
			"\n |                                                                                                        |"
			"\n |	5) Imprimir el salón con mas cantidad de arcades, indicando todos los datos del salon y la           |"
			"\n |	cantidad de arcades que posee.                                                                       |"
			"\n |                                                                                                        |"
			"\n |	6) Ingresar el ID de un salon, y el valor en pesos de una ficha, e imprimir el monto maximo          |"
			"\n |	en pesos que puede recaudar el salon.                                                                |"
			"\n |                                                                                                        |"
			"\n |	7) Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen.                           |"
			"\n |                                                                                                        |"
			"\n |	8) Un salón se encuentra equipado por completo si posee al menos 8 arcades de mas de 2 jugadores.    |"
			"\n |		Listar los salones que cumplan con este mínimo de requisito.                                     |"
			"\n |                                                                                                        |"
			"\n |	9) Imprimir el promedio de arcades por salón.                                                        |"
			"\n |                                                                                                        |"
			"\n |   10) SALIR                                                                                            |"
			"\n |________________________________________________________________________________________________________|\n"

			);

	if(pedirEntero(&auxOpcion, 1, 10, 3, "\n Ingrese una opcion: ",
			"\n Error, ingrese una opcion del 1 al 10: \n\n")==1){
		*opcion = auxOpcion;
	}

	return;
}

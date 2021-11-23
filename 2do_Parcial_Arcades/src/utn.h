/*
 * utn.h
 *Biblioteca de validaciones UTN
 *
 *      Author: Eduard Brito
 */

#ifndef UTN_H_
#define UTN_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char pedirCadena(char Char[],int tamano, int reintento, char* pTexto, char* pTextoError);
int pedirEntero(int* pInt, int min, int max, int reintento, char* pTexto, char* pTextoError);
float pedirFlotante(float* pFloat /*int min, int max*/, int reintento, char* pTexto, char* pTextoError);
int utn_pedirCuit(char auxiliar[], char *mensaje, char *mensajeError, int reintentos);
int utn_getCharRespSoN(char *variableChar, char *mensaje, char *mensajeError, int reintentos);
void mostrarMenu(int *opcion);
void mostrarSubMenu(int *opcion);
int esNumeroValidacion(char cadena[]);


#endif /* UTN_H_ */

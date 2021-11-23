/*
 * eArcade.h
 *Agrupa funciones que permiten trabajar con los datos almacenados en la estructura Arcade,
 *la cual representa los datos de una empresa.
 *
 */

#ifndef EARCADE_H_
#define EARCADE_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"

#define NOMBRE_SALON_LEN 50
#define NACIONALIDAD_LEN 50
#define NOMBRE_DE_JUEGO_LEN 63
#define TIPO_MONO 1
#define TIPO_STEREO 2

typedef struct {
	int id;
	char nombreDelSalon[NOMBRE_SALON_LEN];
	char nacionalidad[NACIONALIDAD_LEN];
	char nombreDelJuego[NOMBRE_DE_JUEGO_LEN];
	int cantidadDeJugadores;
	int cantidadMaxDeFichas;
	int tipoDeSonido;   //1-Mono / 2-Estereo//
} eArcade;

eArcade*arcade_new();

eArcade* arcade_newParametros(char* idStr,char* nombreDelSalonStr,char* nacionalidadStr,char* nombreDelJuegoStr,
		char* catidadDeJugadoresStr,char* catidadMaxDeFichasStr,char* tipoDeSonidoStr);

void arcade_delete(eArcade* this);

int arcade_setId(eArcade* this,int id);
int arcade_getId(eArcade* this,int* id);

int arcade_setNombreDelSalon(eArcade* this,char* nombreDelSalon);
int arcade_getNombreDelSalon(eArcade* this,char* nombreDelSalon);

int arcade_setNacionalidad(eArcade* this,char* nacionalidad);
int arcade_getNacionalidad(eArcade* this,char* nacionalidad);

int arcade_setNombreDelJuego(eArcade* this,char* nombreDelJuego);
int arcade_getNombreDelJuego(eArcade* this,char* nombreDelJuego);

int arcade_setCantidadDeJugadores(eArcade* this,int cantidadDeJugadores);
int arcade_getCantidadDeJugadores(eArcade* this,int* cantidadDeJugadores);

int arcade_setCantidadMaxDeFichas(eArcade* this,int cantidadMaxDeFichas);
int arcade_getCantidadMaxDeFichas(eArcade* this,int* cantidadMaxDeFichas);

int arcade_setTipoDeSonido(eArcade* this,int tipoDeSonido);
int arcade_getTipoDeSonido(eArcade* this,int* tipoDeSonido);

int arcade_findById(LinkedList* plist, int id);
void arcade_ImprimirUno(eArcade* this);

int arcade_sortID(void* thisA, void* thisB);
int arcade_sortNombreDelJuego(void* thisA, void* thisB);
int arcade_sortcantidadDeJugadores(void* thisA, void* thisB);
int arcade_sortcantidadMaxDeFichas(void* thisA, void* thisB);
void arcade_ImprimirJuego(void* this);

#endif /* EARCADE_H_ */

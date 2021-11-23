/*
 * eArcade.c
 *Desarrollo de funciones de la biblioteca eArcade.h
 */
#include "eArcade.h"


eArcade* arcade_new() {
	return (eArcade*) malloc(sizeof(eArcade));
}

void arcade_delete(eArcade* this){

	if(this != NULL)
	{
		free(this);
	}
}

eArcade* arcade_newParametros(char* idStr,char* nacionalidadStr,char* tipoDeSonidoStr,char* catidadDeJugadoresStr,
		char* catidadMaxDeFichasStr, char* nombreDelSalonStr,char* nombreDelJuegoStr)
{
	void *rtn = NULL;

	eArcade* pArcade = arcade_new();

	if( idStr != NULL && nombreDelSalonStr != NULL &&  nacionalidadStr != NULL && nombreDelJuegoStr != NULL &&
			catidadDeJugadoresStr !=NULL && catidadMaxDeFichasStr !=NULL && tipoDeSonidoStr !=NULL)
	{
		if((arcade_setId(pArcade, atoi(idStr))==0) &&
			(arcade_setNombreDelSalon(pArcade, nombreDelSalonStr)==0) &&
			(arcade_setNacionalidad(pArcade, nacionalidadStr)==0) &&
			(arcade_setNombreDelJuego(pArcade, nombreDelJuegoStr)==0) &&
			(arcade_setCantidadDeJugadores(pArcade, atoi(catidadDeJugadoresStr))==0) &&
			(arcade_setCantidadMaxDeFichas(pArcade, atoi(catidadMaxDeFichasStr))==0) &&
			(arcade_setTipoDeSonido(pArcade, atoi(tipoDeSonidoStr))==0))
		{
			rtn= pArcade;

		}else
			{
				arcade_delete(pArcade);
			}
	}
	return rtn;
}

int arcade_setId(eArcade* this, int id){
	int rtn=-1;

		if(this != NULL && id > 0)
		{
			this->id = id;
			rtn = 0;
		}
	return rtn;
}

int arcade_getId(eArcade* this, int* id){
	int rtn=-1;

		if(this != NULL && id != NULL)
		{
			*id = this->id;
			rtn = 0;
		}
	return rtn;
}

int arcade_setNombreDelSalon(eArcade* this, char* nombreDelSalon){
	int rtn=-1;

		if(this != NULL && nombreDelSalon != NULL)
		{
			if(isalpha(*nombreDelSalon)!=0)
			{
				strcpy(this->nombreDelSalon, nombreDelSalon);
				rtn = 0;
			}
		}
	return rtn;
}

int arcade_getNombreDelSalon(eArcade* this, char* nombreDelSalon){
	int rtn=-1;

		if(this != NULL && nombreDelSalon != NULL)
		{
			strcpy(nombreDelSalon, this->nombreDelSalon);
			rtn = 0;
		}
	return rtn;
}

int arcade_setNacionalidad(eArcade* this, char* nacionalidad){
	int rtn=-1;

		if(this != NULL && nacionalidad != NULL)
		{
			if(isalpha(*nacionalidad)!=0)
			{
				strcpy(this->nacionalidad,nacionalidad);
				rtn = 0;
			}
		}
	return rtn;
}

int arcade_getNacionalidad(eArcade* this, char* nacionalidad){
	int rtn=-1;

		if(this != NULL && nacionalidad != NULL)
		{
			strcpy(nacionalidad, this->nacionalidad);
			rtn = 0;
		}
	return rtn;
}

int arcade_setNombreDelJuego(eArcade* this, char* nombreDelJuego){
	int rtn=-1;

		if(this != NULL &&  nombreDelJuego != NULL)
		{
			if(isalpha(*nombreDelJuego)!=0)
			{
				strcpy(this-> nombreDelJuego, nombreDelJuego);
				rtn = 0;
			}
		}
	return rtn;
}

int arcade_getNombreDelJuego(eArcade* this, char* nombreDelJuego){
	int rtn=-1;

		if(this != NULL && nombreDelJuego != NULL)
		{
			strcpy(nombreDelJuego, this->nombreDelJuego);
			rtn = 0;
		}
	return rtn;
}

int arcade_setCantidadDeJugadores(eArcade* this, int cantidadDeJugadores){
	int rtn=-1;

		if(this != NULL && cantidadDeJugadores > 0)
		{
			this->cantidadDeJugadores = cantidadDeJugadores;
			rtn = 0;
		}
	return rtn;
}

int arcade_getCantidadDeJugadores(eArcade* this, int* cantidadDeJugadores){
	int rtn=-1;

		if(this != NULL && cantidadDeJugadores != NULL)
		{
			*cantidadDeJugadores = this->cantidadDeJugadores;
			rtn = 0;
		}
	return rtn;
}

int arcade_setCantidadMaxDeFichas(eArcade* this, int cantidadMaxDeFichas){
	int rtn=-1;

		if(this != NULL && cantidadMaxDeFichas > 0)
		{
			this->cantidadMaxDeFichas = cantidadMaxDeFichas;
			rtn = 0;
		}
	return rtn;
}

int arcade_getCantidadMaxDeFichas(eArcade* this, int* cantidadMaxDeFichas){
	int rtn=-1;

		if( this != NULL &&  cantidadMaxDeFichas != NULL)
		{
			*cantidadMaxDeFichas = this->cantidadMaxDeFichas;
			rtn = 0;
		}
	return rtn;
}

int arcade_setTipoDeSonido(eArcade* this, int tipoDeSonido){
	int rtn=-1;

		if(this != NULL && tipoDeSonido > 0)
		{
			this->tipoDeSonido = tipoDeSonido;
			rtn = 0;
		}
	return rtn;
}

int arcade_getTipoDeSonido(eArcade* this, int* tipoDeSonido){
	int rtn=-1;

		if( this != NULL &&  tipoDeSonido != NULL)
		{
			*tipoDeSonido = this->tipoDeSonido;
			rtn = 0;
		}
	return rtn;
}

int arcade_findById(LinkedList* pList, int id) {

	int rtn = -1;
	int lenLista;
	int i;
	int idAux;

	if (id > 0 && pList != NULL)
	{
		lenLista = ll_len(pList);
		for (i = 0; i < lenLista; i++)
		{
			eArcade *aux = ll_get(pList, i);
			arcade_getId(aux, &idAux);

			if (id == idAux)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

void arcade_ImprimirUno(eArcade* this)
{
	eArcade* auxArcade = (eArcade*)this;
	int auxId;
	char auxNacionalidad[NACIONALIDAD_LEN];
	int auxTipoDeSonido;
	int auxCantidadDeJugadores;
	int auxCantidadMaxDeFichas;
	char auxNombreDelSalon[NOMBRE_SALON_LEN];
	char auxNombreDelJuego[NOMBRE_DE_JUEGO_LEN];

	if(auxArcade != NULL)
	{
		arcade_getId(auxArcade, &auxId);
		arcade_getNacionalidad(auxArcade, auxNacionalidad);
		arcade_getTipoDeSonido(auxArcade, &auxTipoDeSonido);
		arcade_getCantidadDeJugadores(auxArcade, &auxCantidadDeJugadores);
		arcade_getCantidadMaxDeFichas(auxArcade, &auxCantidadMaxDeFichas);
		arcade_getNombreDelSalon(auxArcade, auxNombreDelSalon);
		arcade_getNombreDelJuego(auxArcade, auxNombreDelJuego);

		switch(auxTipoDeSonido)
		{
			case TIPO_MONO:

				printf("\n  *******************************************  DATOS DEL ARCADE  ********************************************************* ");
				printf("\n Id %2d. Nacionalidad: %-10s |  Tipo_Sonido: MONO |  Cant_Jugadores: %-5d | Fichas_Max: %-5d | Salon: %-10s | Juego: %-10s\n",
						auxId,
						auxNacionalidad,
						auxCantidadDeJugadores,
						auxCantidadMaxDeFichas,
						auxNombreDelSalon,
						auxNombreDelJuego);

					break;

			case TIPO_STEREO:

				printf("\n  *******************************************  DATOS DEL ARCADE  *********************************************************  ");
				printf("\n Id %2d. Nacionalidad: %-10s |  Tipo_Sonido: STEREO |  Cant_Jugadores: %-8d | Fichas_Max: %-8d | Salon: %-16s | Juego: %-16s\n",
						auxId,
						auxNacionalidad,
						auxCantidadDeJugadores,
						auxCantidadMaxDeFichas,
						auxNombreDelSalon,
						auxNombreDelJuego);

					break;
		}
	}
	return;
}

int arcade_sortID(void* thisA, void* thisB){
	int rtn=0;
	int auxIdA;
	int auxIdB;

		if(thisA!=NULL && thisB!=NULL)
		{
			if(arcade_getId(thisA, &auxIdA)==0 &&
			   arcade_getId(thisB, &auxIdB)==0)
			{
				if(auxIdA > auxIdB)
				{
					rtn=1;
				}
				if(auxIdA < auxIdB)
				{
					rtn=-1;
				}
			}
		}
	return rtn;
}

int arcade_sortNombreDelJuego(void* thisA, void* thisB){
	int rtn=0;
	char auxNombreDelJuegoA[NOMBRE_DE_JUEGO_LEN];
	char auxNombreDelJuegoB[NOMBRE_DE_JUEGO_LEN];

		if(thisA!=NULL && thisB!=NULL)
		{
			if(arcade_getNombreDelJuego(thisA, auxNombreDelJuegoA)==0 &&
			   arcade_getNombreDelJuego(thisB, auxNombreDelJuegoB)==0)
			{
				if(strcmp (auxNombreDelJuegoA, auxNombreDelJuegoB) > 0)
				{
					rtn=1;
				}
				if(strcmp (auxNombreDelJuegoA, auxNombreDelJuegoB) < 0)
				{
					rtn=-1;
				}
			}
		}
	return rtn;
}

int arcade_sortCantidadDeJugadores(void* thisA, void* thisB){
	int rtn=0;
	int auxCantidadDeJugadoresA;
	int auxCantidadDeJugadoresB;

		if(thisA!=NULL && thisB!=NULL)
		{
			if(arcade_getCantidadDeJugadores(thisA, &auxCantidadDeJugadoresA)==0 &&
			   arcade_getCantidadDeJugadores(thisB, &auxCantidadDeJugadoresB)==0)
			{
				if(auxCantidadDeJugadoresA > auxCantidadDeJugadoresB)
				{
					rtn=1;
				}
				if(auxCantidadDeJugadoresA < auxCantidadDeJugadoresB)
				{
					rtn=-1;
				}
			}
		}
	return rtn;
}

int arcade_sortCantidadMaxDeFichas(void* thisA, void* thisB){
	int rtn=0;
	int auxCantidadMaxDeFichasA;
	int auxCantidadMaxDeFichasB;

		if(thisA!=NULL && thisB!=NULL)
		{
			if(arcade_getCantidadMaxDeFichas(thisA, &auxCantidadMaxDeFichasA)==0 &&
			   arcade_getCantidadMaxDeFichas(thisB, &auxCantidadMaxDeFichasB)==0)
			{
				if(auxCantidadMaxDeFichasA > auxCantidadMaxDeFichasB)
				{
					rtn=1;
				}
				if(auxCantidadMaxDeFichasA < auxCantidadMaxDeFichasB)
				{
					rtn=-1;
				}
			}
		}
	return rtn;
}

/* Brief Imprime un elemento de la LinkedList
 *  \param void this
 *  \return void
 */
void arcade_ImprimirJuego(void* this)
{
	eArcade* aux = (eArcade*)this;
	char auxNombreDelJuego[NOMBRE_DE_JUEGO_LEN];

	if(aux != NULL)
	{
		if(arcade_getNombreDelJuego(aux, auxNombreDelJuego)== 0)
		{
			printf("%s\n", auxNombreDelJuego);
		}

	}
}

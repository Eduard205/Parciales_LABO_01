#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eArcade.h"

/** \brief Parsea los datos los datos de los ARCADES desde el archivo arcades.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayListArcade)
{
	int rtn = -1;
	char id[256];
	char nacionalidad[256];
	char tipoDeSonido[256];
	char cantidadDeJugadores[256];
	char cantidadMaxDeFichas[256];
	char nombreDelSalon[256];
	char nombreDelJuego[256];
	char auxTipoDeSonido[10];
	int auxInt;


		eArcade* pAuxAracade=NULL;

		if(pFile != NULL && pArrayListArcade != NULL)
		{

			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nacionalidad, tipoDeSonido, cantidadDeJugadores,
					cantidadMaxDeFichas, nombreDelSalon,  nombreDelJuego);

			while(!feof(pFile))
			{

				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nacionalidad, tipoDeSonido, cantidadDeJugadores,
						cantidadMaxDeFichas, nombreDelSalon,  nombreDelJuego);

				if(stricmp(tipoDeSonido, "STEREO") == 0)
				{
					auxInt = TIPO_STEREO;
					sprintf(auxTipoDeSonido, "%d", auxInt);

				}else if(stricmp(tipoDeSonido, "MONO") == 0)
					{
						auxInt = TIPO_MONO;
						sprintf(auxTipoDeSonido, "%d", auxInt);
					}

				pAuxAracade = arcade_newParametros(id, nacionalidad, auxTipoDeSonido, cantidadDeJugadores,
						cantidadMaxDeFichas, nombreDelSalon,  nombreDelJuego);

				if(pAuxAracade != NULL)
				{
					ll_add(pArrayListArcade,pAuxAracade); //Se agregan todos los arcades de la lista a la linkedlist
					rtn=0;

				}
			}
		}

    return rtn;
}

/** \brief Parsea los datos los datos de los ARCADES desde el archivo arcades.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int parser_ArcadeFromBinary(FILE* pFile , LinkedList* pArrayListArcade)
{
	int rtn=-1;
	int rtnLeido;
	eArcade* pAuxArcade=NULL;
	eArcade auxArcade;


		if(pFile!=NULL && pArrayListArcade!=NULL)
		{
			while(!feof(pFile))
			{
				rtnLeido = fread(&auxArcade,sizeof(eArcade),1,pFile);
				pAuxArcade = arcade_new();

				if (pAuxArcade != NULL)
				{
					if(rtnLeido== 1)
					{
						if((arcade_setId(pAuxArcade, auxArcade.id)== 0) &&
						(arcade_setNombreDelSalon(pAuxArcade, auxArcade.nombreDelSalon)== 0) &&
						(arcade_setNacionalidad(pAuxArcade, auxArcade.nacionalidad)==0) &&
						(arcade_setNombreDelJuego(pAuxArcade, auxArcade.nombreDelJuego)==0) &&
						(arcade_setCantidadDeJugadores(pAuxArcade, auxArcade.cantidadDeJugadores)== 0) &&
						(arcade_setCantidadMaxDeFichas(pAuxArcade, auxArcade.cantidadMaxDeFichas)== 0) &&
						(arcade_setTipoDeSonido(pAuxArcade, auxArcade.cantidadMaxDeFichas)==0))
						{
							ll_add(pArrayListArcade, pAuxArcade);
							rtn = 0;
						}
					}
				}
			}
		}

    return rtn;
}

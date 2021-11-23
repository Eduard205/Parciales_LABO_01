#include "Controller.h"
#include <stdio.h>
#include "eArcade.h"
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los ARCADES desde el archivo arcade.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListArcade)
{
	int rtn = -1;
	char validacionSoN = 's';

		if (path != NULL && pArrayListArcade != NULL)
		{
			if(ll_isEmpty (pArrayListArcade) == 1)
			{
				FILE *pFile=fopen(path,"r");

				if(pFile != NULL && parser_ArcadeFromText(pFile, pArrayListArcade)== 0)
				{
					printf("\nArchivo leido con éxito");
					rtn = 0;
				}else{
						printf("\nNo se pudo leer el archivo");
						}

				fclose(pFile);

			}else{

				utn_getCharRespSoN(&validacionSoN, "\nYa hay datos cargados, desea guardarlos? (s/n): ","\n Error, ingrese nuevamente", 3);

				switch (validacionSoN)
				{
					case 'n':
						printf("\nSe han borrado los datos cargados.");
						ll_clear(pArrayListArcade);
						FILE *pFile=fopen(path,"r");

						if(pFile != NULL && parser_ArcadeFromText(pFile, pArrayListArcade)== 0 )
						{
							printf("\nArchivo nuevo leido con éxito");
							fclose(pFile);
							rtn = 0;
						}
						break;

					case 's':
						if(controller_saveAsText("back.csv", pArrayListArcade)== 0)
						{
							ll_clear(pArrayListArcade);
							FILE *pFile=fopen(path,"r");

								if(pFile != NULL && parser_ArcadeFromText(pFile, pArrayListArcade)== 0)
								{
									printf("\nArchivo nuevo leido con éxito");
									fclose(pFile);
									rtn = 0;
								}
						}
						break;
				}
				}
		}
	return rtn;
}

/** \brief Carga los datos de los ARCADES desde el archivo arcade.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListArcade)
{
	int rtn= -1;
	char validacionSoN;

		if (path != NULL && pArrayListArcade != NULL)
		{

			if(ll_isEmpty (pArrayListArcade )== 1)
			{
				FILE *pFile=fopen(path,"rb");

				if(pFile != NULL && parser_ArcadeFromBinary(pFile, pArrayListArcade)== 0)
				{
					printf("\nArchivo leido con éxito");
					rtn = 0;

				}else{
						printf("\nNo se pudo leer el archivo");
						}

				fclose(pFile);

			}else{

				utn_getCharRespSoN(&validacionSoN, "\nHay datos cargados en el sistema, desea guardarlos? (s/n)","\n Error, ingrese nuevamente", 3);

				switch (validacionSoN)
				{
					case 'n':
						printf("\nSe han borrado los datos cargados");
						ll_clear(pArrayListArcade);
						FILE *pFile=fopen(path,"rb");

						if(pFile != NULL && parser_ArcadeFromBinary(pFile, pArrayListArcade)== 0)
						{
							printf("\nArchivo nuevo leido con éxito");
							fclose(pFile);
							rtn = 0;
						}
					break;

					case 's':
						if (controller_saveAsBinary("back.bin",pArrayListArcade)== 0)
						{
							ll_clear(pArrayListArcade);
							FILE *pFile=fopen(path,"rb");

							if(pFile != NULL && parser_ArcadeFromBinary(pFile, pArrayListArcade)== 0)
							{
								printf("\nArchivo nuevo leido con éxito");
								fclose(pFile);
								rtn = 0;
							}
						}
					break;
				}
				}
		}
	return rtn;
}

/** \brief Alta de ARCADE
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int controller_addArcade(LinkedList* pArrayListArcade)
{
	int rtn = -1;
    eArcade *auxArcade = NULL;
	char auxNacionalidad[NACIONALIDAD_LEN];
	int auxTipoDeSonido;
	int auxCantidadDeJugadores;
	int auxCantidadMaxDeFichas;
	char auxNombreDelSalon[NOMBRE_SALON_LEN];
	char auxNombreDelJuego[NOMBRE_DE_JUEGO_LEN];

	int lenListaArcades;
	int i;
	int idMax=0;

    	if (pArrayListArcade != NULL)
    	{

    		printf("\n---------------- Alta de un nuevo ARCADE -------------\n");
    		if ((pedirCadena(auxNacionalidad, NACIONALIDAD_LEN, 3, "Ingrese Nacionalidad: ","Error, reingrese Nacionalidad: ")== 1) &&
    			(pedirEntero(&auxTipoDeSonido, 1, 2, 3, "Ingrese Tipo de Sonido (1-MONO/2-STEREO): ","Error, reingrese Tipo de Sonido (1-MONO/2-STEREO): ")== 1) &&
				(pedirEntero(&auxCantidadDeJugadores, 1, 5, 3, "Ingrese Cantidad de Jugadores: ","Error, reingrese Cantidad de Jugadores: ")== 1) &&
				(pedirEntero(&auxCantidadMaxDeFichas, 1, 500, 3, "Ingrese Cantidad Max de Fichas: ", "Error, reingrese Cantidad Max de Fichas: ")== 1) &&
    			(pedirCadena(auxNombreDelSalon, NOMBRE_SALON_LEN, 3, "Ingrese Nombre Del Salon: ","Error, reingrese Nombre Del Salon: ")== 1) &&
				(pedirCadena(auxNombreDelJuego, NOMBRE_DE_JUEGO_LEN, 3, "Ingrese Nombre Del Juego: ","Error, reingrese Nombre Del Juego: ")== 1))
    		{

    			if( ll_isEmpty(pArrayListArcade) == 0)
    			{

    				lenListaArcades = ll_len(pArrayListArcade);

					for(i=0; i<lenListaArcades ; i++)
					{
						auxArcade =ll_get(pArrayListArcade, i);

						arcade_getId(auxArcade, &idMax);

					}
    			 }
    					idMax++;

    				    auxArcade = arcade_new();

    					if( arcade_setId(auxArcade, idMax)== 0 &&
    						arcade_setNacionalidad(auxArcade, auxNacionalidad)== 0 &&
							arcade_setTipoDeSonido(auxArcade, auxTipoDeSonido)== 0 &&
							arcade_setCantidadDeJugadores(auxArcade, auxCantidadDeJugadores)== 0 &&
							arcade_setCantidadMaxDeFichas(auxArcade, auxCantidadMaxDeFichas)== 0 &&
    						arcade_setNombreDelSalon(auxArcade, auxNombreDelSalon)== 0 &&
							arcade_setNombreDelJuego(auxArcade, auxNombreDelJuego)== 0)
    					{
    						ll_add(pArrayListArcade, auxArcade);

							printf("\nEl ARCADE cargado es: \n");
							arcade_ImprimirUno(auxArcade);
							rtn=0;

    					}else{
    							printf("\nError al cargar el ARCADE \n");
    						 }
    		}
    	}
    return rtn;
}

/** \brief Modificar datos de ARCADE
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int controller_editArcade(LinkedList* pArrayListArcade)
{
	int rtn = -1;
	eArcade *auxArcade = NULL;
	char auxNombreDelJuego[NOMBRE_DE_JUEGO_LEN];
	int auxCantidadDeJugadores;
	int datoAMod;
	int idArcadeAMod;
	int lenArcades;
	int idMax;
	int i;
	int indexArcade;

		if(ll_isEmpty(pArrayListArcade)== 0 && pArrayListArcade != NULL)
		{
			controller_ListArcade(pArrayListArcade);

			printf("\n--------------- Modificacion de un ARCADE ------------- \n");

			lenArcades = ll_len(pArrayListArcade);


			for(i=0; i<lenArcades ; i++)
			{
				auxArcade = ll_get(pArrayListArcade, i);
				arcade_getId(auxArcade, &idMax);
			}

			if(pedirEntero(&idArcadeAMod, 0, idMax, 3, "\nIngrese el id del ARCADE a modificar: ","\nError, ingrese un Id valido: ")== 1)
			{
				if(arcade_findById(pArrayListArcade, idArcadeAMod)!= -1)
				{

				indexArcade = arcade_findById(pArrayListArcade, idArcadeAMod);

				auxArcade = ll_get(pArrayListArcade, indexArcade);

				printf("\nARCADE encontrado");
				arcade_ImprimirUno(auxArcade);

				}else{
					printf("\n\nID no encontrado");
					}


				do{
					pedirEntero(&datoAMod, 1, 3, 3, "\n INGRESE UNA OPCION \n1- Modificar Cantidad de Jugadores. \n2- Modificar Nombre del Juego. \n3- Volver al menu principal.\n","\n Error, ingrese nuevamente");

					switch (datoAMod)
					{

						case 1:
							if (pedirEntero(&auxCantidadDeJugadores, 1, 5, 3, "\n Ingrese Cantidad de Jugadores: ","\n Error, reingrese Cantidad de Jugadores: ")== 1 &&
								arcade_setCantidadDeJugadores(auxArcade, auxCantidadDeJugadores)== 0)
								{
									printf("\n DATOS MODIFICADOS------------------------------- \n");
									arcade_ImprimirUno(auxArcade);
									rtn=0;
								}else{
									puts("Error al cargar Cantidad de Jugadores");
								}
						break;

						case 2:
							controller_imprimirJuegos(pArrayListArcade);
							printf("return %d", arcade_setNombreDelJuego(auxArcade, auxNombreDelJuego));
							if (pedirCadena(auxNombreDelJuego, NOMBRE_DE_JUEGO_LEN, 3, "\n Ingrese Nombre Del Juego: ","\n Error, reingrese Nombre Del Juego: ")== 1 &&
								arcade_setNombreDelJuego(auxArcade, auxNombreDelJuego)== 0)
								{
									printf("\n DATOS MODIFICADOS------------------------------- \n");
									arcade_ImprimirUno(auxArcade);
									rtn=0;
								}else{
									puts("Error al cargar Nombre Del Juego");
								}
						break;

						case 3:
						break;
					}

				}while(datoAMod != 3);
			}

		}else{
			printf("No hay ARCADES cargados");
			}

    return rtn;
}

/** \brief Baja de ARCADE
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int controller_removeArcade(LinkedList* pArrayListArcade)
{
	int rtn = -1;
	eArcade *auxArcade = NULL;
	char datoAValidar;
	int idArcadeAMod;
	int lenArcades;
	int idMax;
	int i;
	int indexArcade;

			if(ll_isEmpty(pArrayListArcade)== 0 && pArrayListArcade != NULL)
			{

				controller_ListArcade(pArrayListArcade);

				printf("\n--------------- Baja de un ARCADE ------------- \n");

				lenArcades = ll_len(pArrayListArcade);

				for(i=0; i<lenArcades ; i++)
				{
					auxArcade = ll_get(pArrayListArcade, i);
					arcade_getId(auxArcade, &idMax);
				}

				if(pedirEntero(&idArcadeAMod, 0, idMax, 3, "\nIngrese el id del ARCADE a dar de baja: ","\nError, ingrese un Id valido: ")== 1)
				{
					if(arcade_findById(pArrayListArcade, idArcadeAMod)!= -1)
					{

					indexArcade = arcade_findById(pArrayListArcade, idArcadeAMod);

					auxArcade = ll_get(pArrayListArcade, indexArcade);

					printf("\nARCADE encontrado");
					arcade_ImprimirUno(auxArcade);

					}else{
						printf("\n\nID no encontrado");
						}

					utn_getCharRespSoN(&datoAValidar,"\n¿Esta seguro que desea dar de baja este ARCADE? (s/n): ","Error, ingrese 's' o 'n': ",3);

					switch(datoAValidar)
						{
							case 's':
									ll_remove(pArrayListArcade, indexArcade);
									printf("\n Se dio de baja al ARCADE");
									rtn=0;
							break;

							case 'n':
									printf("\n Se cancelo la baja del ARCADE");
									rtn=0;
							break;

						}
				}

			}else{
				printf("No hay ARCADES cargados");
				}

    return rtn;
}

/** \brief Listar ARCADES
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int controller_ListArcade(LinkedList* pArrayListArcade)
{
	int rtn=-1;
	eArcade* pAuxArcade;
	int i;
	int auxId;
	char auxNacionalidad[NACIONALIDAD_LEN];
	int auxTipoDeSonido;
	int auxCantidadDeJugadores;
	int auxCantidadMaxDeFichas;
	char auxNombreDelSalon[NOMBRE_SALON_LEN];
	char auxNombreDelJuego[NOMBRE_DE_JUEGO_LEN];


	int lenArcades= ll_len(pArrayListArcade);

	if(pArrayListArcade != NULL && lenArcades>0)
	{
		for(i=0; i < lenArcades; i++)
	    {
			pAuxArcade = ll_get(pArrayListArcade,i);

			if(pAuxArcade != NULL)
			{
				arcade_getId(pAuxArcade, &auxId);
				arcade_getNacionalidad(pAuxArcade, auxNacionalidad);
				arcade_getTipoDeSonido(pAuxArcade, &auxTipoDeSonido);
				arcade_getCantidadDeJugadores(pAuxArcade, &auxCantidadDeJugadores);
				arcade_getCantidadMaxDeFichas(pAuxArcade, &auxCantidadMaxDeFichas);
				arcade_getNombreDelSalon(pAuxArcade, auxNombreDelSalon);
				arcade_getNombreDelJuego(pAuxArcade, auxNombreDelJuego);

					switch(auxTipoDeSonido)
					{
						case TIPO_MONO:

							printf("\n  *******************************************  DATOS DEL ARCADE  ***************************************************************************************** ");
							printf("\n Id %d. Nacionalidad: %s | Tipo_Sonido: MONO | Cant_Jugadores: %d | Fichas_Max: %d | Salon: %s | Juego: %s\n",
									auxId,
									auxNacionalidad,
									auxCantidadDeJugadores,
									auxCantidadMaxDeFichas,
									auxNombreDelSalon,
									auxNombreDelJuego);

								break;

						case TIPO_STEREO:

							printf("\n  *******************************************  DATOS DEL ARCADE  *********************************************************  ");
							printf("\n Id %d. Nacionalidad: %s |  Tipo_Sonido: STEREO |  Cant_Jugadores: %d | Fichas_Max: %d | Salon: %s | Juego: %s\n",
									auxId,
									auxNacionalidad,
									auxCantidadDeJugadores,
									auxCantidadMaxDeFichas,
									auxNombreDelSalon,
									auxNombreDelJuego);

								break;
					}
	        rtn=i;
			}
	    }
	}
    return rtn;
}

/** \brief Ordenar ARCADES
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int controller_sortArcade(LinkedList* pArrayListArcade)
{
	int rtn = -1;
	int(*funcionTipoOrden)(void*,void*);
	int tipoDeSort;
	int lenArcades;

		lenArcades = ll_len(pArrayListArcade);

		if (pArrayListArcade != NULL && lenArcades > 0)
		{
			do{
			pedirEntero(&tipoDeSort, 1, 3, 3,"\n Ingrese una opcion (1-3): "
						"\n1- Ordenar Arcades por nombre de juego de forma ascendente "
						"\n2- Ordenar Arcades por nombre de juego de forma descendente "
						"\n3- Volver al menu principal", "\n Error, ingrese nuevamente");

						switch (tipoDeSort)
						{
							case 1:
									funcionTipoOrden = arcade_sortNombreDelJuego;
									if(ll_sort(pArrayListArcade, funcionTipoOrden, 1)==0)
									{
										puts("** Lista ordenada por nombre de juego de forma ascendente **");
										controller_ListArcade(pArrayListArcade);
									}
								break;

							case 2:
									funcionTipoOrden = arcade_sortNombreDelJuego;
									if(ll_sort(pArrayListArcade, funcionTipoOrden, 0)==0)
									{
										puts("** Lista ordenada por nombre de juego de forma descendente **");
										controller_ListArcade(pArrayListArcade);
									}
								break;

							case 3:
									puts("Regreso al menu principal");
								break;

						}

				printf("\n     ** Lista Ordenada ** ");
				rtn = 0;

			}while(tipoDeSort != 3);

		}else{
			printf("No hay ARCADES cargados");
			}

    return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo arcades.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListArcade)
{
	int rtn = -1;
	int auxId;
	char auxNacionalidad[NACIONALIDAD_LEN];
	int auxTipoDeSonido;
	int auxCantidadDeJugadores;
	int auxCantidadMaxDeFichas;
	char auxNombreDelSalon[NOMBRE_SALON_LEN];
	char auxNombreDelJuego[NOMBRE_DE_JUEGO_LEN];


		if(ll_isEmpty(pArrayListArcade) == 0)
		{
		FILE *pFile = fopen(path,"w");

			if (path != NULL && pArrayListArcade != NULL && pFile != NULL)
			{

				fprintf( pFile,"id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game\n");

				for(int i = 0; i < ll_len(pArrayListArcade); i++)
				{

					eArcade  *pAuxArcade = ll_get(pArrayListArcade, i);

					if(pAuxArcade != NULL)
					{

						if(arcade_getId(pAuxArcade, &auxId)== 0 &&
						arcade_getNacionalidad(pAuxArcade, auxNacionalidad)== 0 &&
						arcade_getTipoDeSonido(pAuxArcade, &auxTipoDeSonido)== 0 &&
						arcade_getCantidadDeJugadores(pAuxArcade, &auxCantidadDeJugadores)== 0 &&
						arcade_getCantidadMaxDeFichas(pAuxArcade, &auxCantidadMaxDeFichas)== 0 &&
						arcade_getNombreDelSalon(pAuxArcade, auxNombreDelSalon)== 0 &&
						arcade_getNombreDelJuego(pAuxArcade, auxNombreDelJuego)==0)
						{

							switch(auxTipoDeSonido)
							{
								case TIPO_MONO:
									fprintf(pFile,"%d, %s, MONO, %d, %d, %s, %s\n", auxId, auxNacionalidad, auxCantidadDeJugadores,
											auxCantidadMaxDeFichas, auxNombreDelSalon, auxNombreDelJuego);
								break;

								case TIPO_STEREO:
									fprintf(pFile,"%d, %s, STEREO, %d, %d, %s, %s\n", auxId, auxNacionalidad, auxCantidadDeJugadores,
											auxCantidadMaxDeFichas, auxNombreDelSalon, auxNombreDelJuego);
								break;
							}

						}
					}
				}
				fclose(pFile);
				printf("\nDatos guardados en %s", path);
				rtn = 0;

			}else{
				printf("Error, No hay datos para guardar");
				}
		}
	return rtn;
}

/** \brief Guarda los datos de los ARCADES en el archivo arcades.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListArcade)
{
	int rtn = -1;
	int cantEscrita;
	int lenArcades;
	int i;

		if(ll_isEmpty(pArrayListArcade)== 0)
		{
			if (path != NULL && pArrayListArcade != NULL)
			{
				FILE *pFile=fopen(path,"wb");

				lenArcades = ll_len(pArrayListArcade);

				for(i = 0; i < lenArcades; i++ )
				{

					eArcade* auxArcade= ll_get(pArrayListArcade, i);

					if(pFile != NULL)
					{
						cantEscrita = fwrite(auxArcade, sizeof(eArcade),1, pFile);
					}
				}

				if (cantEscrita < 1)
				{
					printf("\nError al escribir el archivo");

				}else{
					printf("\nDatos guardados en %s", path);
					rtn = 0;
					}

				fclose(pFile);
			}

		}else{
			printf("Error, No hay datos para guardar");
			}

    return rtn;
}

/* Brief Lista los elementos de una LinkedList
 *  \param LinkedList* this
 *  \return int retorno -1 Error
 *  					 0 OK
 */
int controller_imprimirJuegos(LinkedList* this)
{
	int rtn = -1;

		if(this != NULL)
		{
			puts("***LISTA DE JUEGOS***");
			rtn = ll_map(this, arcade_ImprimirJuego);
		}

	return rtn;
}

/* Brief Guarda un archivo de texto
 *  \param char* path
 *  \param LinkedList* this
 *  \return int status -1 Falso
 *  					0 Verdadero
 */
int controller_GenerarArchivoJuegos(char* path, LinkedList* list)
{
	int rtn;
	int flag;

	FILE* pFile = NULL;
	eArcade* auxArcadeA;
	eArcade* auxArcadeB;

	char auxNombreDelJuegoA[NOMBRE_DE_JUEGO_LEN];
	char auxNombreDelJuegoB[NOMBRE_DE_JUEGO_LEN];

	if(list != NULL)
	{
		pFile = fopen(path, "w+");

		if(pFile != NULL && path  != NULL)
		{

			for(int i = 0; i < ll_len(list); i++)
			{
				flag = -1;

				auxArcadeA = ll_get(list, i);

				if(auxArcadeA != NULL)
				{
					arcade_getNombreDelJuego(auxArcadeA, auxNombreDelJuegoA);

					for(int j = i+1; j < ll_len(list); j++)
					{
						auxArcadeB = ll_get(list, j);

						if(auxArcadeB != NULL)
						{
							arcade_getNombreDelJuego(auxArcadeB, auxNombreDelJuegoB);

							if(stricmp(auxNombreDelJuegoA, auxNombreDelJuegoB)== 0)
							{
								flag = 0;
								break;
							}
						}
					}

					if(flag == -1)
					{
						fprintf(pFile,"%s\n", auxNombreDelJuegoA);
						rtn=0;
					}

				}else
					{
						rtn = -1;
						break;
					}
			}

			fclose(pFile);

		}else
			{
				rtn = -1;
			}

	}else
		{
			rtn = -1;
		}

	return rtn;
}

/* Brief Filtra una linkedList
 *  \param void* list
 *  \return int status -1 FALSO
 *  					0 VERDADERO
 */
int filterMultiJugador(void* this)
{
	int rtn = -1;
	eArcade* auxArcade = (eArcade*) this;
	int AuxCantidadDeJugadores;

	if(auxArcade != NULL)
	{
		arcade_getCantidadDeJugadores(auxArcade, &AuxCantidadDeJugadores);

		if(AuxCantidadDeJugadores > 1)
		{
			rtn = 0;
		}
	}

	return rtn;
}

/* Brief Filtra una linkedList
 *  \param LinkedList* this
 *  \return int status -1 FAlSO
 *  					0 VERDADERO
 */
int controller_filterMultiplayer(LinkedList* this)
{
	int rtn = -1;
	LinkedList* pAuxlist;

	if(this != NULL)
	{
		pAuxlist = ll_filter(this, filterMultiJugador);

		if(pAuxlist != NULL)
		{
			if(controller_saveAsText("multijugador.csv", pAuxlist) != -1)
			{
				rtn = 0;
			}
		}
	}

	return rtn;
}

/* Brief Duplica un campo de un elemento
 *  \param void* this
 *  \return void
 */
void duplicarCantidadMaxDeFichas(void* this)
{

	eArcade* auxArcade;
	auxArcade = (eArcade*) this;
	int auxCantidadMaxDeFichas;

	if(auxArcade != NULL)
	{
		arcade_getCantidadMaxDeFichas(auxArcade, &auxCantidadMaxDeFichas);
		auxCantidadMaxDeFichas = auxCantidadMaxDeFichas * 2;
		arcade_setCantidadMaxDeFichas(auxArcade, auxCantidadMaxDeFichas);
	}

}

/* Brief Duplica un campo (cantidadMaxDeFichas) de todos los elementos de la lista
 *  \param LinkedList* this
 *  \return int rtn -1 FALSO
 *  				 0 VERDADERO
 */
int controller_duplicarCantidadMaxDeFichas(LinkedList* this)
{
	int rtn = -1;

	if(ll_isEmpty (this) == 0)
	{
		rtn = ll_map(this, duplicarCantidadMaxDeFichas);
	}else
		{
			puts("Error, NO hay ARCADES cargados");
		}

	if(rtn==0)
	{
		puts("Se duplico la CantidadMaxDeFichas de los ARCADES");
	}

	return rtn;
}

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "eArcade.h"
#include "utn.h"

/****************************************************
 Nombre: Eduard Brito Hernandez - Division: 1H
    Menu:
     1. LEER ARCADES DESDE ARCHIVO CSV.
     2. INCORPORAR ARCADE.
     3. MODIFICAR ARCADE.
     4. ELIMINAR ARCADE.
     5. IMPRIMIR ARCADES (Ordenados por nombre de juego).
     6. Generar archivo con JUEGOS
     7. Generar un archivo con arcades "Multijugador".
     8. Actualizar cantidad de fichas.
     9. SALIR.
*****************************************************/



int main()
{
setbuf(stdout, NULL);

    int opcion=0;

    LinkedList* listaArcades = ll_newLinkedList();


    do{
    	mostrarMenu(&opcion);

        switch(opcion)
        {
            case 1:
                if(controller_loadFromText("arcades.csv",listaArcades)== -1)
                {
                	printf("\nError, intente nuevamente");
                }
                break;

            case 2:
                if(controller_addArcade(listaArcades)== -1)
                {
                	printf("\nError, intente nuevamente");
                }
                break;

            case 3:
                if(controller_editArcade(listaArcades)== 0)
                {
                	controller_saveAsText("arcades.csv",listaArcades);

                }else{
                	printf("\nError, intente nuevamente");
                	}
                break;

            case 4:
            	if(controller_removeArcade(listaArcades)== 0)
                {
            		controller_saveAsText("arcades.csv",listaArcades);

                }else{
                		printf("\nError, intente nuevamente");
                	 }
                break;

            case 5:
            	 controller_sortArcade(listaArcades);

                break;

            case 6:
            	if(controller_GenerarArchivoJuegos("Juegos.txt",listaArcades)== 0)
            	{
            		puts("Se genero un archivo txt con la lista de juegos");

            	}else{
                     	 printf("\nError, intente nuevamente");
                     }
                break;

            case 7:
            	if(controller_filterMultiplayer(listaArcades)== -1)
                {
            		printf("\nError, intente nuevamente");
                }
            	break;

            case 8:
            	if(controller_duplicarCantidadMaxDeFichas(listaArcades)== -1)
                {
            		printf("\nError, intente nuevamente");
                }
            	break;

            case 9:
            	ll_deleteLinkedList(listaArcades);
            	printf("\n  **************** PROGRAMA CERRADO ***************** ");
            	break;
        }

    }while(opcion != 9);
    return 0;
}

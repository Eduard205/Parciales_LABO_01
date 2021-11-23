#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListArcade);
int controller_loadFromBinary(char* path , LinkedList* pArrayListArcade);
int controller_addArcade(LinkedList* pArrayListArcade);
int controller_editArcade(LinkedList* pArrayListArcade);
int controller_removeArcade(LinkedList* pArrayListArcade);
int controller_ListArcade(LinkedList* pArrayListArcade);
int controller_sortArcade(LinkedList* pArrayListArcade);
int controller_saveAsText(char* path , LinkedList* pArrayListArcade);
int controller_saveAsBinary(char* path , LinkedList* pArrayListArcade);
int controller_imprimirJuegos(LinkedList* this);
int controller_GenerarArchivoJuegos(char* path, LinkedList* list);
int filterMultiJugador(void* this);
int controller_filterMultiplayer(LinkedList* this);
void duplicarCantidadMaxDeFichas(void* this);
int controller_duplicarCantidadMaxDeFichas(LinkedList* this);



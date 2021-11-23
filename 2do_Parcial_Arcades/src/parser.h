/*
 * parser.h
 *
 *
 *      Author: Eduard Brito
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayListArcade);
int parser_ArcadeFromBinary(FILE* pFile , LinkedList* pArrayListArcade);

#endif /* PARSER_H_ */

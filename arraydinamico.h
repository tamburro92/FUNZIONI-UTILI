/*
 * arraydinamico.h
 *
 *  Created on: 26/mar/2013
 *      Author: Gennaro w/ Busillo
 */

#ifndef ARRAYDINAMICO_H_
#define ARRAYDINAMICO_H_
#include "info.h"

struct SArray {
	int size; /* Dimensione Fisica */
	int length; /* Dimensione Logica */
	TInfo *item; /* Elemento dell'array */
};

typedef struct SArray TArray;

TArray array_create(int initial_length); /* Crea l'array */

void array_destroy(TArray *a); /* Lo distrugge */

void array_resize(TArray *a, int new_length);

#endif /* ARRAYDINAMICO_H_ */

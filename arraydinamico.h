//
//  arraydinamico.h
//
//  Created by Francesco Grauso 
//  Copyright (c) 2013 Francesco Grauso. All rights reserved.
//

#ifndef ARRAYDINAMICO_H_
#define ARRAYDINAMICO_H_

typedef int TInfo;

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

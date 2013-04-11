//
//  arraydinamico.c
//
//  Created by Francesco Grauso 
//  Copyright (c) 2013 Francesco Grauso. All rights reserved.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "arraydinamico.h"
#define GROWING_DELTA 10
#define SHRINKING_DELTA 20

TArray array_create(int initial_length){ /* Crea l'array */
	TArray a;
	a.length = initial_length;
	a.size = initial_length;
	a.item = (TInfo *)malloc(sizeof(TInfo)*initial_length);
	assert(initial_length == 0 || a.item!=NULL);

	return a;
}

void array_destroy(TArray *a){ /* Lo distrugge */
	a->size = 0; /* Puntatore a struttura */
	a->length = 0; /* IDEM */
	free(a->item);
	a->item = NULL;
}

void array_resize(TArray *a, int new_length){
	if( (new_length > a->size) || (new_length < a->size - SHRINKING_DELTA) ){
		int new_size = new_length + GROWING_DELTA;
		a->item = (TInfo *)realloc(a->item, new_size*sizeof(TInfo));
		assert( (new_size==0) || (a->item!=NULL) );
		a->size = new_size;
	}
	a->length = new_length;
}

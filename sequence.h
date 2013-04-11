//
//  sequence.h
//  TDA sequence
//
//  Created by Francesco Grauso on 11/04/13.
//  Copyright (c) 2013 Francesco Grauso. All rights reserved.
//


#include "arraydinamico.h"
#include "stdbool.h"

#ifndef TDA_sequence_sequence_h
#define TDA_sequence_sequence_h


struct SSequence
{
    TArray array;

};

typedef struct SSequence TSequence;

TSequence* sequence_create();
void sequence_destroy(TSequence*);
int sequence_length(TSequence*);
bool sequence_is_empty(TSequence*);
TInfo sequence_get(TSequence*, int);
void sequence_insert(TSequence*, int, TInfo);
TInfo sequence_remove(TSequence*, int);
void sequence_set(TSequence*, int, TInfo);

#endif

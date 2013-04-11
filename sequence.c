//
//  sequence.c
//  TDA sequence
//
//  Created by Francesco Grauso on 11/04/13.
//  Copyright (c) 2013 Francesco Grauso. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stdbool.h"
#include "sequence.h"


TSequence* sequence_create()
{

    TSequence* seq=malloc(sizeof (TSequence));
    assert(seq!=NULL);
    seq->array=array_create(0);
    return seq;
    

}
void sequence_destroy(TSequence* q)
{
    array_destroy(&q->array);
    free(q);
}

int sequence_length(TSequence* q)
{
    return q->array.length;
}

bool sequence_is_empty(TSequence* q)
{

    return q->array.length==0;

}

TInfo sequence_get(TSequence* q, int pos)
{
    return q->array.item[pos];

}

void sequence_insert(TSequence* q , int pos, TInfo info)
{
    int j;
    array_resize(&q->array, q->array.length+1);
    for (j=q->array.length; j>pos; j--)
    {
        q->array.item[pos]=q->array.item[j-1];
    }
    q->array.item[pos]=info;

}

TInfo sequence_remove(TSequence* q, int pos)
{
    int j;
    for (j=pos; j<q->array.length-1; j++)
        q->array.item[j]=q->array.item[j+1];
    array_resize(&q->array, q->array.length-1);

}
void sequence_set(TSequence* q, int pos, TInfo info)
{
    q->array.item[pos]=info;

}
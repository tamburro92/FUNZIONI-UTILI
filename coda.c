//
//  coda.c
//  CODA lezione 9.4.13
//
//  Created by Francesco Grauso on 09/04/13.
//  Copyright (c) 2013 Francesco Grauso. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "struct.h"
#include "coda.h"
#include "stdbool.h"


TQueue queue_create (int capacity)
{
    TQueue s;
    s.n=0;
    s.front=0;
    s.back=0;
    s.capacity=capacity;
    s.a=malloc(sizeof(TInfo)*capacity);
    assert(s.a!=NULL);
    return s;
    
}


void queue_destroy(TQueue* queue)
{
    queue->n=0;
    queue->capacity=0;
    free(queue->a);
    queue->a=NULL;

}


void queue_add(TQueue* queue, TInfo x)
{
    queue->a[queue->back]=x;
    queue->back=(queue->back+1)%queue->capacity;
    queue->n++;

}


TInfo queue_remove(TQueue* queue)
{
    TInfo x=queue->a[queue->front];
    queue->front=(queue->front+1)%queue->capacity;
    queue->n--;
    return x;
}


TInfo queue_front(TQueue* queue)
{
    return queue->a[queue->front];
}


bool queue_is_empty(TQueue* queue)
{
    return queue->n == 0;
}


bool queue_is_full(TQueue* queue)
{
return queue->n == queue->capacity;
}
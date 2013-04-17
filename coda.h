//
//  coda.h
//  FUNZIONI per CODA
//
//  Created by Francesco Grauso
//  Copyright (c) 2013 Francesco Grauso. All rights reserved.
//

//prototipi delle funzioni per la gestione di una coda

#include "struct.h"
#include "stdbool.h"

#ifndef coda_h
#define coda_h

#define MAXCAR 50

//STRUTTURA DI INFO
struct SInfo
{
    char cliente[MAXCAR];
    char prestazione[MAXCAR];
    float prezzo;
    
    
};

typedef struct SInfo TInfo;


//STRUTTURA CODA

struct SQueue{
    int n;
    int front;
    int back;
    int capacity;
    TInfo *a;
    
};

typedef struct SQueue TQueue;

TQueue queue_create (int);
void queue_destroy(TQueue*);
void queue_add(TQueue*, TInfo);
TInfo queue_remove(TQueue*);
TInfo queue_front(TQueue*);
bool queue_is_empty(TQueue*);
bool queue_is_full(TQueue*);

#endif

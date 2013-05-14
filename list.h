//
//  coda.h
//  FUNZIONI per LISTA
//
//  Created by Francesco Grauso
//  Copyright (c) 2013 Francesco Grauso. All rights reserved.
//

//prototipi delle funzioni per la gestione di una lista

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "struct.h"
#include "stdbool.h"


typedef int TInfo;

struct SNode {
    TInfo info;
    struct SNode *link;
};

typedef struct SNode TNode;
typedef TNode *TList;

bool greater(TInfo, TInfo);
bool equal(TInfo, TInfo);
TNode *node_create(TInfo);
void node_destroy(TNode *);
TList list_create();
TList list_destroy(TList);
TInfo read_info();
void print_info(TInfo);
void list_print(TList);
TNode *list_search(TList, TInfo);
TList list_insert(TList, TInfo);
TList list_delete(TList, TInfo);
int list_is_empty(TList);
int count_nodes(TList, TInfo );
TList delete_node(TList list, TInfo x);


#ifndef list_h
#define list_h







#endif

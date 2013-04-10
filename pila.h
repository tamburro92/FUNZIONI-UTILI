//
//  pila.h
//  Lezione 5-4-13
//
//  Created by Francesco Grauso on 06/04/13.
//  Copyright (c) 2013 Francesco Grauso. All rights reserved.
//

#ifndef Lezione_5_4_13_pila_h
#define Lezione_5_4_13_pila_h

#include "info.h"
#include "stdbool.h"

//Definiamo i prototipi

T_stack Stack_Create();    //CREATE
void Stack_Destroy(T_stack *); //DISTRUZIONE STACK (tramite riferimento)
void Stack_Push(T_stack*, T_Info); //PUSH ALLO STACK
T_Info Stack_Pop (T_stack *);
T_Info Stack_Top(T_stack *);
bool Stack_IsEmpty(T_stack *stack);
bool Stack_IsFull(T_stack *stack);

#endif

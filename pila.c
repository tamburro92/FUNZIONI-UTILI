//
//  pila.c
//  FUNZIONI per PILA
//
//  Created by Francesco Grauso
//  Copyright (c) 2013 Francesco Grauso. All rights reserved.
//

#include <stdio.h>
#include "pila.h"
#include "stdbool.h"
#include "info.h"

T_stack Stack_Create()
{
    T_stack newstack;
    newstack.sp=0;
    return newstack;
    
}
void Stack_Destroy(T_stack *s)
{
    s->sp=0;
}
void Stack_Push(T_stack* s, T_Info info)
{
    //s-> equivale a scrivere (*s)
    s->a[s->sp]=info;
    (s->sp)++;
    
}
T_Info Stack_Pop (T_stack *s)
{
    T_Info x=s->a[(s->sp)-1];
    (s->sp)--;
    return x;
    
}

T_Info Stack_Top(T_stack * s)
{
    T_Info x = s->a[(s->sp)-1];
    return x;
    
}

bool Stack_IsEmpty(T_stack *stack) {
    return stack->sp == 0;
}

bool Stack_IsFull(T_stack *stack) {
    return stack->sp == 0;
}


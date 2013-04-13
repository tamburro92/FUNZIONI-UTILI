//
//  recursive.c
//  FindMin recursive
//
//  Created by Francesco Grauso on 12/04/13.
//  Copyright (c) 2013 Francesco Grauso. All rights reserved.
//

#include <stdio.h>
#include "recursive.h"


int findMin(int *v, int dim)
{
    int min;    
    if (dim==0)
    {
     return v[0];
    }    
    else
    {
        min=findMin(v, dim-1);
       
        if(min<v[dim])
            return min;
        else
            return v[dim];
    }
}

long fattoriale(long num)
{
if (num==1)
    return 1;
else
    return num*fattoriale(num-1);
}

long fibonacci(long n)
//dato un n restituisce il numero alla posizione n-esima della sequenza di fibonacci!
{
    if (n<=0) return 0;
    if (n==1) return 1;
    if (n==2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);

}

void hanoi(int n, int a, int b, int c)
{
    /* Questa funzione (ricorsiva) descrive le mosse da fare per poter
     trasferire n dischi dal piolo a al piolo c, usando eventualmente
     b come piolo per gli spostamenti intermedi.
     Ovviamente, questi spostamenti vengono fatti tenendo conto del
     vincolo espresso nel problema delle "torri di Hanoi": ciascun
     disco non puo' mai essere poggiato su un disco piu' piccolo. */
    if(n == 1) {
        printf("Muovi il disco dal piolo %d al piolo %d\n", a, c);
    }
    else {
        hanoi(n-1, a, c, b);
        hanoi(1, a, b, c);
        hanoi(n-1, b, a, c);
    }
}
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
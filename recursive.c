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
    
    if (dim==1)
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
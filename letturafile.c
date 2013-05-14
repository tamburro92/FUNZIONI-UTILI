//
//  letturafile.c
//  LETTURAFILE
//
//  Created by Francesco Grauso on 12/04/13.
//  Copyright (c) 2013 Francesco Grauso. All rights reserved.
//

#include <stdio.h>

int LeggiVettore( float *v, int riemp )
{
	int i, n;
    FILE *fp;
    char nomefile[MAXCAR];
	
    printf("Digita il nome del file da cui leggere i dati\n");
    printf("File  --> ");
    scanf("%s",nomefile);
    
    if((fp=fopen(nomefile,"r"))==NULL){
        printf("Errore di apertura del file %s\n", nomefile);
        exit(0);
    }
    i = 0;
    while( fscanf(fp, "%f", v+i) != EOF ) {
        if( (i >= 0) && (i < riemp) ) {
            i++;
			printf("%d %d\n", i, riemp);
        }
    }
    n = i--;
    fclose( fp );
	
	return n;
}
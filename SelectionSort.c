/*
 **  SelectionSort.c
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 50

struct SInfo
{
	char name[N];
	char surname[N];
	int age;
};
typedef struct SInfo TInfo;

TInfo *AllocateMemory(int typesize, int n)
{
    TInfo *vector;

    vector = (TInfo *)malloc(n * typesize);
    if( !vector )
		return NULL;

    return vector;
}

/*
 * Legge in input il numero n ed n numeri interi
 * che memorizza nell'array. Restituisce il numero
 * di elementi letti (n).
 */
void read_info(TInfo *x, int i, int n) {
	if (i < n) {
		printf("Inserisci Cognome Nome Eta': \n");
		scanf("%s %s %d", x[i].surname, x[i].name, &(x[i].age));
		//scanf("%s %s %d", (x+i)->surname, (x+i)->name, &((x+i)->age));
		i++;
		read_info(x, i, n);
	}
}

/*
 * Stampa in output l'array.
 */
void print_info(TInfo *x, int i, int n) {
	if (i < n) {
		printf("%s %s %d\n", (x+i)->surname, (x+i)->name, (x+i)->age);
		//printf("%s %s %d\n", x->name, x->surname, x->age);
		i++;
		print_info(x, i, n);
	}
}

bool less(TInfo *x, TInfo *y)
{
	int comp;

	comp = strcmp(x->surname, y->surname);

	if(comp < 0)
		return true;
	else
		if (comp == 0)
			return strcmp(x->name, y->name) < 0;
		else
			return false;
}

int search_min(TInfo *x, int n) {
	int i, imin;

	imin = 0;
	for (i=0; i<n; i++)
		if (less(x+i, x+imin))
			imin = i;

	return imin;
}

/*
 * Scambia il contenuto delle due variabili
 * indirizzate dai puntatori x e y.
 */

void swap(TInfo *x, TInfo *y) {
	TInfo z;

	z = *x;
	*x = *y;
	*y = z;

	return;
}

/* Ordina l'array a con l'algoritmo di ordinamento per selezione
 */
void selection_sort(TInfo a[], int n) {
    int i, imin;
    for(i=0; i<n-1; i++) {
        imin=i+search_min(a+i, n-i);
        if (imin!=i)
            swap(&a[i], &a[imin]);
    }
}

/*
 *  Funzione principale
 */

int main(void) {
	TInfo *v;
	int n;

	printf("Inserire il numero di elementi del vettore: ");
	scanf("%d", &n);

	/* Alloca il vettore di n elementi */
	v = AllocateMemory(sizeof(TInfo), n);
	if(v == NULL){
		fprintf(stderr, "ERROR: bad allocation memory.\n");
		exit(EXIT_FAILURE);
	}

	read_info(v, 0, n);

	printf("Vettore inserito:\n");
	print_info(v, 0, n);
	printf("\n");

	merge_sort(v, 0, n-1);

	printf("Vettore ordinato:\n");
	print_info(v, 0, n);
	printf("\n");

	free(v);

	return EXIT_SUCCESS;
}

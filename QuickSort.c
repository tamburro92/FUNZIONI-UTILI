/*
 **  QuickSort.c
 */


//ordinamento di vettore tramite quicksort in base ai cognomi.
#include <stdlib.h>
#include <stdio.h>

#include <stdbool.h>
#include <string.h>

struct SInfo
{
	char name[50];
	char surname[50];
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


/* Suddivide l'array a in tre parti:
 * - nella prima ci sono tutti elementi minori  del pivot;
 * - nella seconda c'e' solo il pivot;
 * - nella terza ci sono tutti elementi maggiori o uguali
 * del pivot.
 * Come pivot viene scelto il primo elemento dell'array
 * iniziale.
 * VALORE DI RITORNO
 *    L'indice della parte centrale (che contiene il
 *    solo pivot)
 * PRE
 *    L'array contiene almeno un elemento
 */
int partition(TInfo *a, int n) {
    int i, j=1;
    for(i=1; i<n; i++)
        if (less(a+i, a))
            swap(&a[i], &a[j++]);
    swap(&a[0], &a[j-1]);
    return j-1;
}


void QuickSort(TInfo *a, int n)
{
	int k;
    
	if(n < 2)
		return;
	k = partition(a,n);
	QuickSort(a,k);
	QuickSort(a+k+1,n-k-1);
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
    
	QuickSort(v, n);
    
	printf("Vettore ordinato:\n");
	print_info(v, 0, n);
	printf("\n");
    
	free(v);
    
	return EXIT_SUCCESS;
}


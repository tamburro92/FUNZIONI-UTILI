/*
 **  MergeSort.c
 */

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

/* Fonde due array ordinati in un nuovo
 * array che conserva l'ordinamento.
 */
void merge(TInfo *a, int low, int high, int mid)
{
	int i, j, k;
	TInfo *c;

	/* Alloca il vettore di n elementi */
	c = AllocateMemory(sizeof(TInfo), high-low);
	if(c == NULL){
		fprintf(stderr, "ERROR: bad allocation memory.\n");
		exit(EXIT_FAILURE);
	}

	i=low;
	j=mid+1;
	k=low;
	while((i<=mid)&&(j<=high)) {
		if(less(a+i,a+j))
			c[k++]=a[i++];
		else
			c[k++]=a[j++];
	}
	while(i<=mid) 
		c[k++]=a[i++];
	while(j<=high)
		c[k++]=a[j++];

	for(i=low;i<k;i++)
		a[i]=c[i];
		
	free(c);
}

/* Ordinamento con l'algoritmo Merge Sort
 */
void merge_sort(TInfo a[], int low, int high) {
	int mid;

	if(low<high) {
		mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,high,mid);
	}
	else
		printf("Error: low > high\n");
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

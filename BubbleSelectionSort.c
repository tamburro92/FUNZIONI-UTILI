
void selection_sort(TInfo a[], int n);
void BubbleSort(TInfo *array, int n);
void BubbleSortMod(TInfo *array, int n);

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

void BubbleSort(TInfo *array, int n) {
	int i, k;

	for(k=0; k<n-1; k++) {
		for(i=0; i<n-k-1; i++)
			if (greater(array+i, array+i+1))
				swap(array+i, array+i+1);
	}
 }

void BubbleSortMod(TInfo *array, int n) {
	int i, k;
	bool modified;

	modified=true;
	for(k=0; k<n-1 && modified; k++) {
		modified=false;
		for(i=0; i<n-k-1; i++)
			if (greater(array+i, array+i+1)) {
				swap(array+i, array+i+1);
				modified=true;
			}
	}
}


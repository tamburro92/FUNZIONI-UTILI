int count_both_son_node(TBinaryTree bt)
{
    int right, left;
    if(bt == NULL)
        return 0;

    else
    {

     if(bt->right == NULL && bt->left == NULL)
    {
        return 0;
    }

    if(bt->right != NULL && bt->left != NULL)
    {
        left = count_both_son_node(bt->left);
        right = count_both_son_node(bt->right);

        return 1+left+right;
    }
    if(bt->right != NULL && bt->left == NULL)
    {
        return count_both_son_node(bt->right);
    }
    if(bt->right == NULL && bt->left != NULL)
    {
        return count_both_son_node(bt->left);
    }
    
        
    }
}

/////////////

int count_both_son_node(TBinaryTree bt)
{
    int right, left;
    if(bt == NULL)
        return 0;

    else
    {

     if(bt->right == NULL && bt->left == NULL)
    {
        return;
    }

    if(bt->right != NULL && bt->left != NULL)
    {
        left = count_both_son_node(bt->left);
        right = count_both_son_node(bt->right);

        printinfo(bt->info);
    }
    if(bt->right != NULL && bt->left == NULL)
    {
        return count_both_son_node(bt->right);
    }
    if(bt->right == NULL && bt->left != NULL)
    {
        return count_both_son_node(bt->left);
    }
    
        
    }
}

///////////////

int count_right_node(TBinaryTree bt)
{
    int right, left;
    if(bt == NULL)
        return 0;

    else
    {

     if(bt->right == NULL && bt->left == NULL)
    {
        return 0;
    }

    if(bt->right != NULL && bt->left != NULL)
    {
        left = count_right_node(bt->left);
        right = count_right_node(bt->right);

        return left+right;
    }
    if(bt->right != NULL && bt->left == NULL)
    {
        return 1+count_right_node(bt->right);
    }
    if(bt->right == NULL && bt->left != NULL)
    {
        return count_right_node(bt->left);
    }
    
        
    }
}

////////

int list_count_element(TList list, int n)
{
    if(list == NULL)
        return 0;
    else 
    {

    if (list->info % n == 0)
        return 1+list_count_element(list->link, n);

    else
        return list_count_element(list->link, n);
    }
}



//////

Tinfo findmedia(TBinaryTree bt)
{
    Tinfo info_l, info_r, info;
    if(bt == NULL)
        return;

    else
    {

     if(bt->right == NULL && bt->left == NULL)
    {
        return bt->info;
    }

    if(bt->right != NULL && bt->left != NULL)
    {
        info_l = findmedia(bt->left);
        info_r = findmedia(bt->right);
       if(info_l<info_r)
        info=info_l;
        else
        info=info_r;

    if(info<bt->info.media)
        return info
    else
        return bt->info.media

    }
    if(bt->right != NULL && bt->left == NULL)
    {
        info = findmedia(bt->right);
if(info<bt->info.media)
        return info
    else
        return bt->info.media
    }
    if(bt->right == NULL && bt->left != NULL)
    {
           info = findmedia(bt->left);
if(info<bt->info.media)
        return info
    else
        return bt->info.media
    }
    
        
    }
}



void exchange(int *array, int i, int j)
{
    int tmp = array[j];

    array[j] = array[i];
    array[i] = tmp;
}


///////////

int vectorinvert (v[], i,n)
{
    if(n-i<=2){
        exchange(v, i, n);
        return;
}
    else
    {
vectorinvert(v, i+1, n-1);
exchange(v, i, n);
return;
    }
}


bool isordred (v[], n)
{
    if(n==0){
        return true;

}
    else
    {

if (isordred(v, n-1) && (v[n-1]<v[n]))
    return true;
else
    return false;
    }
}

////////////////////


void list_print_recursive(TList list) {
    if (list != NULL){
        list_print_recursive(list->link));
        print_info(list->info);
    }
}

void list_print_pari_recursive(TList list) {
    if (list != NULL){
          print_info(list->info);
          if(list->link!=NULL)
            list_print_pari_recursive((list->link)->link);
          else
            return;
    }
    else return;
}

//////////////////


int list_find_min(TList list) {
    if (list != NULL){
        int min = list_find_min(list->link);
        if(min!=NULL && (min<list->info.key)
            return min;
        else
            return list->info.key
    }
else
    return;
}


//////////////


/* Ordina un array con il Quick Sort
 */
void quick_sort(TInfo a[], int n) {
    int k;
    if (n<2)
        return;
    k=partition(a, n);
    quick_sort(a, k);
    quick_sort(a+k+1, n-k-1);
}

int partition(TInfo a[], int n) {
    int i, k=1;
    for(i=1; i<n; i++)
        if (less(a[i], a[0]))
            swap(&a[i], &a[k++]);
    swap(&a[0], &a[k-1]);
    return k-1;
}


/* Ordinamento con l'algoritmo Merge Sort
 * Nota:
 *    temp e' un array di appoggio delle stesse
 *    dimensioni di a
 */
void merge_sort(TInfo a[], int n, TInfo temp[]) {
    int i, m=n/2;
    if (n<2)
        return;
    merge_sort(a, m, temp);
    merge_sort(a+m, n-m, temp);
    merge(a, m, a+m, n-m, temp);
    for(i=0; i<n; i++)
        a[i]=temp[i];
}

void merge(TInfo a1[], int n1, TInfo a2[], int n2, 
           TInfo dest[]) {
    int pos1=0, pos2=0, k=0;

    while (pos1<n1 && pos2<n2) {
        if (less(a2[pos2], a1[pos1]))
            dest[k++] = a2[pos2++];
        else
            dest[k++] = a1[pos1++];
    }

    while (pos1<n1)
        dest[k++] = a1[pos1++];

    while (pos2<n2)
        dest[k++] = a2[pos2++];
}


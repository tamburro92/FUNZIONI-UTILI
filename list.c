/*
 **  lista_ordinata.c
 **
 **  Letta in input una sequenza di numeri interi la memorizza
 **  in una lista in ordine crescente.
 **
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"

/*
 * struttura per la rappresentazione dei nodi della lista
 */



bool greater (TInfo a, TInfo b){
     if(a > b)
    	 return true;
     else
    	 return false;
}

bool equal (TInfo a, TInfo b){
    if(a == b)
   	 return true;
    else
   	 return false;
}

/* Crea ed alloca un nodo */
TNode *node_create(TInfo info) {
	TNode *new;

	new=(TNode *) malloc(sizeof(TNode));
	if (new==NULL) {
		printf("errore allocazione memoria.\n");
		return NULL;
	}
	new->info = info;
	new->link = NULL;
	return new;
}

/* Distrugge e dealloca un nodo */
void node_destroy(TNode *node) {
    free(node);
}

// cancellazione di tutti gli elementi con prezzo uguale ad un dato valore letto da tastiera
TList delete_node(TList list, int x){
	TNode *corr, *alias, *prec;
    corr=list;
    prec=NULL;

    while(corr!=NULL){
    	prec=corr;
    	if(equal(corr->info, x)){
    		alias=corr->link;
    		prec->link=alias;
    		list=list_delete(list, corr->info);
    	}
    	corr=corr->link;
    }
    return list;
}

/* Crea e restituisce una lista vuota */
TList list_create() {
    return NULL;
}

/* Distrugge la lista list, deallocandone tutti gli elementi
 * NOTA: consuma il parametro list
 */
TList list_destroy(TList list) {
    TNode *curr, *succ;
    curr = list;
    while (curr != NULL) {
        succ = curr->link;
        node_destroy(curr);
        curr = succ;
    }
    return NULL;
}

/*
 * Legge info
 */
TInfo read_info(){
      TInfo info;

      printf("\nInserire il dato:\n");
      scanf("%d",&info);

      return info;
}

/*
 * Stampa info
 */
void print_info(TInfo info){

     printf("%d\n",info);
}

/* Visita la lista list dalla testa alla coda stampando gli elementi */
void list_print(TList list) {
    TNode *curr;
    curr = list;
    while (curr != NULL) {
        print_info(curr->info);
        curr = curr->link;
    }
}

/* Ricerca l'elemento di valore info nella lista list, preservando
 * l'ordinamento; restituisce la lista risultante.
 * PRE: list e' ordinata
 * NOTA: consuma il parametro list; inoltre se l'elemento da inserire
 e' gia' presente, esso viene duplicato.
 */
TNode *list_search_ordered(TList list, TInfo info) {

    /* PRE: la lista list e' ordinata */
    TNode * curr;
    curr = list;

    /*P1: l'elemento da cercare ha un valore info inferiore a quello
     *    dell'elemento di testa della lista
     *P2: l'elemento da cercare ha un valore info compreso tra quello
     *    della testa e quello della coda della lista
     *P3: l'elemento da cercare ha un valore info maggiore di tutti
     *    quelli degli elementi della lista
     */

    while ((curr != NULL) && greater(info,curr->info)) {
        curr = curr->link;
    }

    /* Analisi delle post-condizioni
	 C1: valore da cercare piu' piccolo della Testa
	 C2: valore da cercare maggiore della Coda
	 C3: valore da cercare compreso tra quello di Testa e quello di
	 Coda
     */
    if ((curr != NULL) && equal(curr->info, info))
	/* Elemento trovato */
        return curr;
    else
        return NULL;
}

/* Inserisce l'elemento di valore info nella lista list, preservando
 * l'ordinamento; restituisce la lista risultante.
 * PRE: list e' ordinata
 * NOTA: consuma il parametro list; inoltre se l'elemento da inserire
 * e' gia' presente, esso viene duplicato.
 */
TList list_insert(TList list, TInfo info) {
    TNode * prec, *succ, *new;
    prec = NULL;
    succ = list;

    /*P1: prec==NULL e succ==NULL, la lista e' vuota*/
    /*P2: prec==NULL e succ!=NULL, l'elemento da inserire e' non
     *    maggiore del primo elemento della lista */
    /*P3: prec!=NULL e succ==NULL, l'elemento da inserire e' maggiore
     *    dell'ultimo elemento della lista */
    /*P4: prec!=NULL e succ!=NULL, l'elemento da inserire e' maggiore
     *    del nodo di testa e minore di quello di coda.*/

    /* F1: ricerca della posizione di inserimento */
    while ((succ != NULL) && greater(info, succ->info)) {
        prec = succ;
        succ = succ->link;
    }

    /* F2: allocazione del nuovo nodo */
    new = node_create(info);
    if (new == NULL){           /* Errore: allocazione fallita */
        printf("Errore di allocazione della memoria");
        exit(1);
    }
    /* F3: aggiornamento della catena dei collegamenti */
    if (prec == NULL) {
        /* C1: inserimento in Testa */
        new->link = list;
        return new;
    } else {

        /* C2: inserimento in posizione centrale o in coda */
        new->link = succ;
        prec->link = new;
        return list;
    }
}

/* Cancella un elemento di valore info dalla lista list, preservando
 * l'ordinamento; restituisce la lista risultante.
 * PRE: list e' ordinata
 * NOTA: consuma il parametro list; inoltre se l'elemento da inserire
 *       e' duplicato cancella la prima occorrenza.*/
TList list_delete(TList list, TInfo info) {
    TNode *prec, *curr, *alias;
    prec = NULL;
    curr = list;

    /*P1: curr==NULL o info!=curr->info, l'elemento da cancellare
     *    non e' presente
     *P2: la condizione P1 non e' verificata, e prec==NULL va
     *    cancellato l'elemento di testa
     *P3: la condizione P1 non e' verificata, e prec!=NULL e
     *    curr!=NULL va cancellato un elemento in posizione
     *    intermedia della lista */

    /* F1: ricerca dell'elemento da cancellare */
    while ((curr != NULL) && greater(info, curr->info)) {
        prec = curr;
        curr = curr->link;
    }

    /* Analisi delle post-condizioni */
    if ((curr != NULL) && equal(curr->info, info)) {    /* Elemento trovato */

        /* F2: aggiornamento della catena dei collegamenti */
        if (prec == NULL) {
            /* CASO C2: Cancellazione della Testa */
            list = curr->link;
        }
        else {
            /* CASO C3: Cancellazione da una posizione intermedia */
            alias = curr->link;
            prec->link = alias;
        }

        /* F3: Deallocazione del Nodo cancellato logicamente */
        node_destroy(curr);
        return list;
    }
    return list;
}

/* Visita la lista list dalla testa alla coda stampando gli elementi
 * PRE: nessuna
 */
void list_print_recursive(TList list) {
    if (list != NULL){
        print_info(list->info);
        list_print_recursive(list->link);
    }
}

/* Cerca l'elemento di valore info nella Lista list. Ritorna il
 * riferimento all'elemento se e' presente, altrimenti ritorna NULL.
 * PRE: list e' ordinata
 */
TNode *list_search_recursive(TList list, TInfo info) {

	if (list == NULL || greater(list->info, info))
        return NULL;

    else {
        if (equal(list->info, info))
            return list;

        else
            return list_search_recursive(list->link, info);
    }
}

/* Inserisce l'elemento di valore info nella lista list, preservando
 * l'ordinamento; restituisce la lista risultante.
 * PRE: list e' ordinata
 * NOTA: consuma il parametro list; inoltre se l'elemento da inserire
 e' gia' presente, esso viene duplicato.
 */
TList list_insert_recursive(TList list, TInfo info) {


	if (list==NULL || greater(list->info,info) )
	{
		TNode* newnode;
		newnode = node_create(info);
		if (newnode==NULL){
			printf ("Errore di allocazione della memoria\n");
			exit(1);
		}
		newnode->link = list;
		return newnode;
	}
	else {
		TList l2;
		l2 = list_insert_recursive(list->link,info);
		list->link = l2;
		return list;
	}
}

/* Cancella l'elemento di valore info nella lista list, preservando
 * l'ordinamento; restituisce la lista risultante.
 * PRE: list e' ordinata
 * NOTA: consuma il parametro list; se l'elemento da cancellare non
 e' presente,   la lista resta inalterata.
 */
TList list_delete_recursive(TList list, TInfo info) {
    if (list == NULL || greater(list->info, info))
        return list;

    else
	{
        if (equal(list->info, info)) { /* cancellazione in testa */
            TNode *alias = list->link;
            node_destroy(list);
            return alias;
        }

        else {
            TList l2;
            l2 = list_delete_recursive(list->link, info);
            list->link = l2;
            return list;
        }
    }
}

// conteggio degli elementi appartententi ad una data marca

int count_nodes(TList list, TInfo x){
    TNode *corr;
    int cont=0;

    corr=list;
    while(corr!=NULL){
    	if(equal(corr->info, x))
    		cont++;
    	corr=corr->link;
    }
    return cont;
}



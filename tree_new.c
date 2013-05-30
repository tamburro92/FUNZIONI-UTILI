//
//  tree.c
//
//  Created by Antonio Della Cioppa on 16/09/11.
//  Copyright 2011 Università di Salerno. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int TInfo;

struct SNode {
    TInfo info;
    struct SNode *right;
    struct SNode *left;
};
typedef struct SNode TNode;

typedef TNode *TBinaryTree;

// Prototypes

/* Crea ed alloca un nodo
 * PRE: nessuna
 */
TNode *node_create(TInfo value);

/* Distrugge e dealloca un nodo
 * PRE: nessuna
 */
void node_destroy(TNode *node);

/* Crea e restituisce un albero binario vuoto
 * PRE: nessuna
 */
TBinaryTree binarytree_create();

/* Distrugge l'albero binario, deallocandone tutti gli elementi
 * PRE: nessuna
 * NOTA: consuma il parametro bt
 */
TBinaryTree binarytree_destroy(TBinaryTree bt);

/* Visita l'albero binario in ordine
 * PRE: nessuna
 */
void binarytree_visit(TBinaryTree bt);

/* Cerca l'elemento di valore info nell'albero binario. Ritorna il
 * riferimento all'elemento se e' presente, altrimenti ritorna NULL.
 * PRE: bt e' ordinato
 */
TNode *binarytree_search(TBinaryTree bt, TInfo info);

/* Inserisce l'elemento di valore info nell'albero binario,
 * preservando l'ordinamento; restituisce l'albero binario risultante.
 * PRE: bt e' ordinato
 * NOTA: consuma il parametro bt; inoltre se l'elemento da
 *       inserire e' gia' presente, esso viene duplicato.
 */
TBinaryTree binarytree_insert(TBinaryTree bt, TInfo info);

/* Cancella l'elemento di valore info nell'albero binario, preservando
 * l'ordinamento; restituisce l'albero binario risultante.
 * PRE: bt e' ordinato
 * NOTA: consuma il parametro bt; se l'elemento da cancellare
 *       non e' presente, l'albero binario resta inalterato.
 */
TBinaryTree binarytree_delete(TBinaryTree bt, TInfo info);

/* Ritorna il valore true se l'albero binario non contiene elementi
 * PRE: nessuna
 */
bool binarytree_is_empty(TBinaryTree bt);

/* Cerca il minimo nell'albero binario. Ne ritorna il riferimento
 * se presente, altrimenti ritorna NULL.
 * PRE: binarytree e' ordinato
 */
TNode *binarytree_search_min(TBinaryTree bt);

/* Cerca il massimo nell'albero binario. Ne ritorna il riferimento
 * se presente, altrimenti ritorna NULL.
 * PRE: binarytree e' ordinato
 */
TNode *binarytree_search_max(TBinaryTree bt);


/* Visita l'albero binario in pre-ordine
 * PRE: nessuna
 */
void binarytree_visit_pre_order(TBinaryTree bt);

/* Visita l'albero binario in post-ordine
 * PRE: nessuna
 */
void binarytree_visit_post_order(TBinaryTree bt);

// Functions

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

/*
 * Stampa info
 */
void print_info(TInfo info){
    printf("%d\n",info);
}

/* Crea ed alloca un nodo
 * PRE: nessuna
 */
TNode *node_create(TInfo info){
    TNode *new;
    
    new=(TNode *) malloc(sizeof(TNode));
    if (new==NULL)
        return NULL;
    new->info = info;
    new->left = NULL;
    new->right = NULL;
    return new;
}

/* Distrugge e dealloca un nodo
 * PRE: nessuna
 */
void node_destroy(TNode *node){
    free(node);
}

/* Distrugge l'albero binario, deallocandone tutti gli elementi
 * PRE: nessuna
 * NOTA: consuma il parametro bt
 */
TBinaryTree binarytree_destroy(TBinaryTree bt){
    /*Caso base: Albero vuoto oppure con un solo elemento*/
    if (bt == NULL)
        return NULL;
    else if ((bt->left == NULL) && (bt->right == NULL)) {
        node_destroy(bt);
        return NULL;
    }
    
    else {
        /*Fase di divide at impera*/
        bt->left = binarytree_destroy(bt->left);
        
        /*Fase di divide at impera*/
        bt->right = binarytree_destroy(bt->right);
        
        /*Fase di combina*/
        node_destroy(bt);
        return NULL;
    }
}

/* Crea e restituisce un albero binario vuoto
 * PRE: nessuna
 */
TBinaryTree binarytree_create(){
    return NULL;
}

/* Visita l'albero binario in ordine
 * PRE: nessuna
 */
void binarytree_visit(TBinaryTree bt){
    if (bt != NULL){
        binarytree_visit(bt->left);
        print_info(bt->info);
        binarytree_visit(bt->right);
    }
}

/* Visita l'albero binario in post-ordine
 * PRE: nessuna
 */
void binarytree_visit_post_order(TBinaryTree bt){
    if (bt != NULL){
        binarytree_visit(bt->left);
        binarytree_visit(bt->right);
        print_info(bt->info);
    }
}

/* Visita l'albero binario in pre-ordine
 * PRE: nessuna
 */
void binarytree_visit_pre_order(TBinaryTree bt){
    if (bt != NULL){
        print_info(bt->info);
        binarytree_visit(bt->left);
        binarytree_visit(bt->right);
    }
}

/* Cerca l'elemento di valore info nell'albero binario. Ritorna il
 * riferimento all'elemento se e' presente, altrimenti ritorna NULL.
 * PRE: bt e' ordinato
 */
TNode *binarytree_search(TBinaryTree bt, TInfo info){
    /*Caso base: Albero vuoto oppure la root è l'elemento cercato*/
    if ((bt == NULL) || equal(bt->info, info))
        return bt;
    else {
        if (greater(info, bt->info))
        /*Fase di divide at impera*/
            return binarytree_search(bt->right, info);
        else
        /*Fase di divide at impera*/
            return binarytree_search(bt->left, info);
    }
}

TNode* binarytree_min(TBinaryTree bt) {
    /*Caso base: sottoalbero vuoto*/
	if (bt->left == NULL)
		return bt;
    
    /*Fase di divide at impera*/
    TBinaryTree min = binarytree_min(bt->left);
    
    /*Fase di combina*/
    return min;
}

TNode* binarytree_max(TBinaryTree bt) {
    /*Caso base: sottoalbero vuoto*/
	if (bt->right == NULL)
		return bt;
    
    /*Fase di divide at impera*/
    TBinaryTree max = binarytree_max(bt->right);
    
    /*Fase di combina*/
    return max;
}

/* Inserisce l'elemento di valore info nell'albero binario,
 * preservando l'ordinamento; restituisce l'albero binario risultante.
 * PRE: bt e' ordinato
 * NOTA: consuma il parametro bt; inoltre se l'elemento da
 *       inserire e' gia' presente, esso viene duplicato.
 */
TBinaryTree binarytree_insert(TBinaryTree bt, TInfo info){
    /*Caso base: Albero vuoto*/
    if (bt == NULL) {
        TNode *new;
        new = node_create(info);
        if (new == NULL) {
            printf("Errore di allocazione della memoria\n");
            exit(1);
        }
        return new;
    }
    
    else if (!greater(info, bt->info)) {
        /*Fase di divide at impera*/
        bt->left = binarytree_insert(bt->left, info);
        
        /*Fase di combina*/
        return bt;
    }
    
    else {
        /*Fase di divide at impera*/
        bt->right = binarytree_insert(bt->right, info);
        
        /*Fase di combina*/
        return bt;
    }
}

/* Cancella l'elemento di valore info nell'albero binario, preservando
 * l'ordinamento; restituisce l'albero binario risultante.
 * PRE: bt e' ordinato
 * NOTA: consuma il parametro bt; se l'elemento da cancellare
 *       non e' presente, l'albero binario resta inalterato.
 */
TBinaryTree binarytree_delete(TBinaryTree bt, TInfo info){
    /*Caso base: Albero vuoto*/
    if (bt == NULL)
        return NULL;
    
    else if (greater(bt->info, info)) {
        /*Fase di divide at impera*/
        bt->left = binarytree_delete(bt->left, info);
        return bt;
    }
    
    else if (greater(info, bt->info)) {
        /*Fase di divide at impera*/
        bt->right = binarytree_delete(bt->right, info);
        return bt;
    }
    /*Fase di combina*/
    else {                      // bt->info==info
        TBinaryTree min_right;
        if ((bt->right == NULL) && (bt->left == NULL)) {
            node_destroy(bt);        // Cancellazione di una foglia
            return NULL;
        }
        if (bt->right == NULL) {     // Cancellazione di un nodo con
            // il solo figlio sinistro
            TBinaryTree alias;
            alias = bt->left;
            node_destroy(bt);
            return alias;
        }
        if (bt->left == NULL) {     // Cancellazione di un nodo con
            // il solo figlio destro
            TBinaryTree alias;
            alias = bt->right;
            node_destroy(bt);
            return alias;
        }
        //Cancellazione di un nodo con entrambi i figli
        min_right = binarytree_min(bt->right);      // Ricerca del minimo del
        // sottoalbero destro
        bt->info = min_right->info;   // Copia del minimo
        // nel campo info
        // del nodo da eliminare
        //Eliminazione del nodo da cui è stato copiato il minimo
        bt->right = binarytree_delete(bt->right, min_right->info);
        return bt;
    }
}

int binarytree_sum_nodes(TBinaryTree bt){
    int count_left, count_right;
    /*Caso base: Albero vuoto*/
    if (bt==NULL)
        return 0;
    
    /*Fase di divide at impera*/
    count_left = binarytree_sum_nodes(bt->left);
    
    /*Fase di divide at impera*/
    count_right = binarytree_sum_nodes(bt->right);
    
    /*Fase di combina*/
    return bt->info+count_left+count_right;
}

int binarytree_count_nodes(TBinaryTree bt){
    int count_left, count_right;
    /*Caso base: Albero vuoto*/
    if (bt == NULL)
        return 0;
    
    /*Fase di divide at impera*/
    count_left = binarytree_count_nodes(bt->left);
    
    /*Fase di divide at impera*/
    count_right = binarytree_count_nodes(bt->right);
    
    /*Fase di combina*/
    return 1+count_left+count_right;
}

int binarytree_count_leaves (TBinaryTree bt)
{
    int count_left, count_right;
    /*Caso base: Albero vuoto oppure albero con un solo elemento*/
    if(bt==NULL)
        return 0;
    else if((bt->left==NULL)&&(bt->right==NULL))
        return 1;
    
    else{
        /*Fase di divide et impera*/
        count_left=binarytree_count_leaves(bt->left);
        
        /*Fase di divide et impera*/
        count_right=binarytree_count_leaves(bt->right);
        
        /*Fase di combina*/
        return count_left+count_right;
    }
}

/* PRE: l'albero non e' vuoto
 */
int binarytree_depth(TBinaryTree tree) {
    assert(tree!=NULL);
    
    /* Caso base: foglia */
    if (tree->left==NULL && tree->right==NULL)
        return 0;
    else if (tree->left==NULL) /* Solo sottoalbero destro */
        return 1+binarytree_depth(tree->right);
    else if (tree->right==NULL) /* Solo sottoalbero sinistro */
        return 1+binarytree_depth(tree->left);
    else {   /* Nodo completo */
        /* Fase di divide et impera */
        int depth_left=binarytree_depth(tree->left);
        int depth_right=binarytree_depth(tree->right);
        /* Fase di combina */
        if (depth_left>depth_right)
            return 1+depth_left;
        else
            return 1+depth_right;
    }
}

int main(){
    int i, n, num;
    char tmp;
    TInfo info;
    TBinaryTree tree;
    
    printf("inserisci il numero di nodi: ");
    scanf("%d", &n);
    
    tree = binarytree_create(); // inizializzo l'albero vuoto
    
    i = 0;
    while(i < n){
    	printf("inserisci il valore: ");
        scanf("%d", &num);
        tree = binarytree_insert(tree, num);
        i++;
    }
    printf("Ho costruito l'albero binario\n\n");
    printf("Cosa vuoi fare adesso?\n[s]tampare l'albero.\n");
    printf("[i]nserire un nuovo nodo.\n");
    printf("cercare il [m]inimo.\n");
    printf("cercare il [M]assimo\n");
    printf("stampa [p]rofondita'\n");
    printf("[r]imuove un nodo dall'albero\n");
    printf("[d]istrubbe l'albero\n[u]scire.\n\n");
    
    
    printf(">");
    fflush(stdin);
    while((tmp = getchar()) != 'u'){
        switch (tmp){
        	case 'i':
        		printf("inserisci il valore: ");
        		scanf("%d", &num);
        		tree = binarytree_insert(tree, num);
        		break;
            case 's':                                    // serve a mostrare l'albero
            	binarytree_visit(tree);
                printf("\n");
                break;
            case 'm':                                    // stampa a video il valore minimo
            	print_info(binarytree_min(tree)->info);
                break;
            case 'M':                                    // stampa a video il valore massimo
            	print_info(binarytree_max(tree)->info);
            	break;
            case 'p':                                    // stampa a video la profondità
            	print_info(binarytree_depth(tree));
                break;
            case 'r':       							// rimuove un nodo
            	printf("inserisci il valore: ");
            	scanf("%d", &info);
            	tree = binarytree_delete(tree, info);
                break;
            case 'd':                                    // distrugge l'albero
            	tree = binarytree_destroy(tree);
                break;
            default:
                printf(">");
                break;
        }
    }
    return EXIT_SUCCESS;
}

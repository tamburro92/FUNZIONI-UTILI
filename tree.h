//
//  tree.h
//  tree
//
//  Created by Francesco Grauso on 25/05/13.
//  Copyright (c) 2013 Francesco Grauso. All rights reserved.
//

#ifndef tree_tree_h
#define tree_tree_h

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


#endif

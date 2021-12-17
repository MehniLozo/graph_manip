#include <stdlib.h>
#include <stdio.h>
#include "list.h"
struct noeud_tete* sans_pred_list(struct noeud_tete* tete){ 
    //look for all the predecessors in your list,put them aside in a list alone
    struct noeud_tete* t = NULL; // this to be returned
    struct noeud_tete* p = tete;
    while(p){ 
        if(p->cp == 0){ 
            if(t)
                t->suiv = p;
            else 
                t = p;
            
        }
        p = p->suiv; 
    } 
    return t;
}
int main(){ 
   return 0; 
}

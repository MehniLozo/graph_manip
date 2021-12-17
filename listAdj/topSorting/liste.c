#include <stdlib.h>
#include <stdio.h>
#include "list.h"

#define SIZE 6
unsigned mat[SIZE][SIZE]{
      {0,0,0,0,0,0},
      {0,0,1,1,0,1},
      {0,0,0,0,1,0},
      {0,0,0,0,1,0},
      {0,0,0,0,0,0},
      {0,0,0,0,0,0},
}
struct noeud_tete* return_node(unsigned x,struct noeud_tete* tete){ 
    //returns a node holding the cle=x 
    //recherche dichotmique
    struct noeud_tete* p = tete;
    while(p && p->cle != x) p=p->suivant; 
    return p;
}
struct noeud_tete* mat_to_list(unsigned mat[][SIZE]){
   struct noeud_tete* tete = NULL,*p,*q,*t;
   unsigned i,j,cp = 0;
   //list architecture initialisation tho
   for( i = SIZE;i>0;i--){ 
        cp = 0;
        p = (struct noeud_tete*)malloc(sizeof(struct noeud_tete)); 
        p->cle=i;
        p->suivant = tete;
        tete = p; //execu in both cases tho
        //count how many predecessors it has
        for(j = 0;j<SIZE;j++)
          if(mat[j][i])
            cp ++;
        p->cp = cp;
   }  
   for( i = 1;i<SIZE;i++){ 
     p = return_node(i,tete);
     for(j = 1;j<SIZE;j++){ 
        if(mat[i][j]){ 
          q = (struct noeud_queue*)malloc(sizeof(struct noeud_queue)); 
          q->id = return_node(j,tete); 
          assert(q->id); //we don't want to link to NULL lol
          //succ list handling
          if(p->succ)
          {
            q->suivant = p->succ;
          }else
            q->suivant = NULL;

          p->succ = q;
        }  

     }
      
   }
   /*
     for(unsigned i = SIZE;i>=0;i--){ 
        p = (struct noeud_tete*)malloc(sizeof(struct noeud_tete)); 
        p->cle=i;
       else
         p->suivant = tete;
       tete = p; //execu in both cases tho
       for(unsigned j= 0;j<SIZE;j++){ 

         if(mat[i][j]){ 
          q = (struct noeud_queue*)malloc(sizeof(struct noeud_queue)); 
          q->id = 
         } 
        }
     }*/
}
struct noeud_tete* sans_p(struct noeud_tete* tete){ 
     struct noeud_tete* p;  
     struct noeud_tete* q;  
     p = tete;
     tete = NULL;
     while(p)
     {
       q = p;
       p = q->suivant;
       if(q->cp== 0)
       {
         q->suivant = tete;
         tete = q;
       }
     }
     return tete;
 }
void ordre_lineaire(struct noeud_tete *sans_p){ 
  //sans_p was supposed to be holding the sans_pred nodes i guess...
  //for looping the succs
  struct noeud_tete* t;
  struct noeud_tete* q;

  while(sans_p){ 
    t = sans_p;
    printf("%d\t",p->cle);
   q = sans_p->succ; 
   //decrementing in-coming edge count for each succ node
   while(q){  
     q->id->cp --; 
     if(q->id->cp == 0)
     {
          q->id->suiv = sans_p;
          sans_p= q->id;
     }
     q = q->suivant;
   }
   //delete the current node
   supprimer_queue(t->succ); 
   free(t);
  }
}
/*
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
void linear_order(struct noeud_tete* origi){ 
    struct noeud_tete* sans_pred = sans_pred_list(origi);
    while(sans_pred){ */

       /* go to all of its sucessors and decrease their in-coming edge counter because we're gonna remove this predecessor node after printing it and move on to the next predecessor and also do the same
   */
/*      struct noeud_queue* p = sans_pred->succ;
      while(p){ 
         p->id->cp --; 
       }
      delete_from_list(&(sans_pred));
      sans_pred = sans_pred->suivant;
    }
}*/
int main(){ 
   struct noeud_tete* l; // l for holding nodes in linear order
   struct noeud_tete* s; // s for holding nodes with no predecessors
   struct noeud_tete* oigi; //original list holding the "original" graph
   s = sans_pred_list(
   return 0; 
}

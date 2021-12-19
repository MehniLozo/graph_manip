#include <stdlib.h>
#include <stdio.h>
#include "liste.h"
#include <assert.h>

#define SIZE 6

struct noeud_tete* return_node(unsigned x,struct noeud_tete* tete){ 
    //returns a node holding the cle=x 
    //recherche dichotmique
    struct noeud_tete* p = tete;
    while(p && p->cle != x) p=p->suiv; 
    return p;
}
struct noeud_tete* mat_to_list(unsigned mat[][SIZE]){
   struct noeud_tete* tete = NULL,*p;
   struct noeud_queue* q;
   unsigned i,j,cp = 0;
   //list architecture initialisation tho
   for( i = SIZE;i>0;i--){ 
        cp = 0;
        p = (struct noeud_tete*)malloc(sizeof(struct noeud_tete)); 
        p->cle=i;
        p->suiv = tete;
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
     return tete;
}
struct noeud_tete* sans_p(struct noeud_tete* tete){ 
     struct noeud_tete* p;  
     struct noeud_tete* q;  
     p = tete;
     tete = NULL;
     while(p)
     {
       q = p;
       p = q->suiv;
       if(q->cp== 0)
       {
         q->suiv = tete;
         tete = q;
       }
     }
     return tete;
 }
//Topological sorting
void ordre_lineaire(struct noeud_tete *sans_p){ 
  //sans_p holds nodes that dont have any predecessors 
  struct noeud_tete* t;
  struct noeud_queue* q;

  while(sans_p){ 
    t = sans_p;
    printf("%d\t",sans_p->cle);
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
   //supprimer_queue(t->succ); 
   //free(t->succ);
   free(t);
   sans_p = sans_p->suiv;
  }
  printf("\n");
}

int main(){ 
    unsigned mat[SIZE][SIZE]={
      {0,0,0,0,0,0},
/*1*/ {0,0,1,1,0,1},
 /*2*/{0,0,0,0,1,0},
/*3*/ {0,0,0,0,1,0},
/*4*/ {0,0,0,0,0,0},
 /*5*/{0,0,0,0,0,0}
    };
  // struct noeud_tete* l; // l for holding nodes in linear order
   struct noeud_queue* s; // s for holding nodes with no predecessors
   struct noeud_tete* origi; //original list holding the "original" graph
   origi = mat_to_list(mat);
   struct noeud_tete* p = origi;
   struct noeud_tete* sansp;
   while(p){ 
    //printf("cle = %d\n",p->cle);
    s = p->succ;
    printf("%d precede : ",p->cle) ;
    while(s){ 
        printf("%d\t",s->id->cle);
        s = s->suivant;
    }
    printf("\n");
    p = p->suiv;
   }
   printf("\n");
   printf("\n*******BEFORE SORTING*******\n");
    p = origi;
    while(p){ 
        printf("%d\t",p->cle);
        p = p->suiv;
    }
   printf("\n*******WITHOUT PREDECESSORS*******\n");
   sansp = sans_p(origi);
   while(sansp){ 
        printf("%d\t",sansp->cle);
        sansp = sansp->suiv;
    }
   printf("\n*******TOPOLOGICAL SORTING*******\n");
   ordre_lineaire(sans_p(origi));
   return 0; 
}

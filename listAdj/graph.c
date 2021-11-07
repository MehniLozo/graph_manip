/*
 *  NOTE:
        -While executing the following script you can only insert 
            specific node values(unsigned values) which each one of them 
            should not surpass the list_adj length-1 
        ex:
            p->s < nb_sommets-1;
        Each of node succ REPRESENT an INDEX of the ARRAY
        -Use the "remplir" function to describe your graph inside the 
            ajacent list
        -Use 'display_checker' function in order to verify your 
            graph input rightness
 * */

#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "file_tda_chaine.c"

#define nb_sommets 6

struct noeud* liste_adj[nb_sommets];
//struct noeud* liste_adj2[nb_sommets]; //for matrix-->liste conversion
unsigned mat_adj[nb_sommets][nb_sommets];//for liste-->matrix conversion
int val[nb_sommets]; //variable pour memoriser l'etat d'un sommet visité ou non

unsigned id; //ordre de la visite


void remplir()
{
    struct noeud* p;
    int ok = 1;
    for(int i = 1;i<nb_sommets;i++)
    {
        //add elements for the first time tho     
    
        do{
            do{
                 printf("\nvoulez vous inserer un succ de %d (1:OUI,0:NON)\n",i);
                scanf("%d",&ok);
            }while(!(ok == 0 || ok == 1));
            if(ok)
            {
                p = (struct noeud*)malloc(sizeof(struct noeud));
                if(liste_adj[i])
                {
                    p->suivant = liste_adj[i]->suivant;
                    liste_adj[i]->suivant = p;    
                }else{
                    p->suivant = NULL;
                    liste_adj[i] = p;
                }
               
                    printf("\ninside the node?\t");
                    scanf("%u",&(p->s));
                    while(p->s > nb_sommets -1)
                    {
    printf("\nvous devez insere un elt que son 'indice' existe deja dans la liste adj\n");
                        scanf("%u",&(p->s));
                    }
             }
        }while(ok);
    }

}
void display_checker(){
    struct noeud* p;
    for(int i = 0;i<nb_sommets;i++){
        p = liste_adj[i];
        while(p){
            printf("%d--->\t",i);
            printf("%u\t",p->s);
            p = p->suivant;
        }
        printf("\n");
    }
    
}
        /*******************************Parcours***********************/

void explorer_prof(unsigned k){
    //Recursive
   struct noeud* t;
    id ++;
    val[k] = id; 

    t = liste_adj[k];
    while(t){
       if(val[t->s] == 0)
       {
          printf("%u\t",t->s);
          explorer_prof(t->s);
       }
       t=t->suivant; 
    }
}
void profondeur()
{
    unsigned k;
    id = 0;
    for(k = 0;k<nb_sommets;k++) val[k] = 0;

    for(k = 0;k<nb_sommets;k++)
        if(val[k] == 0)
        {
            printf("%d\t",k);
            explorer_prof(k);
        }
}
void explorer_larg(unsigned k){
    struct noeud* t;
    enfiler(k);
    while(!file_vide())
    {
        k = premier();
        printf("%u\t",k);
        id++;
         val[k] = id;
         defiler();
         t=liste_adj[k];
         while(t)
         {
            if(val[t->s] == 0)
            {
                enfiler(t->s);
                val[t->s] = -1;
            }
            t = t->suivant;
         }

    }
}
void largeur()
{
    unsigned k;
    id = 0;
    /*ENTERED HERE THO*/
    creer_file();
    for(k = 0;k<nb_sommets;k++) val[k] = 0;
    for(k = 0;k<nb_sommets;k++)
        if(val[k] == 0)
            explorer_larg(k);
}
        /****************************************************************/
unsigned deg_int(unsigned s){
   unsigned nb = 0,j = 0; struct noeud* p= liste_adj[j];
    for(int i = 0;i<nb_sommets;i++) 
    { while(p && p->s !=s) p=p->suivant;    
      if(p) nb ++;  
    }
    return nb;
    /*Compléxité O(N*P) avec N le nombre de sommets et P le nombre d'arc 
      d'un sommet particulier*/
}
unsigned ieme_succ(unsigned i,unsigned s)
{
    unsigned nb = 0;
    struct noeud* p = liste_adj[s];
    while(p && nb < i )
    {
        p = p->suivant;
        nb++;
    }
    if(p)
        return p->s;
    //return error();
    return 00;
}
    /************************COMPOSANT CONNEXE**************************/
void explorer_connexe(unsigned k)
{
    /*
     *explorer_connexe : function that checks all the nodes that the current node 
     can get connected to whether thats directly or inderectly
     (via other nodes)
    TODO: FUNC still under maintenance
     * */
    struct noeud* t;
    //printf("%c  ",nom(k));
    id++;
    val[k]=id;
    t=liste_adj[k];
    while(t)
    {
        if(val[t->s]==0)
        {   printf("%d\t",k);
            explorer_connexe(t->s);
        }
        t =t->suivant; 
    }
}
void composant_connexe()
{
    /*Cost of Complexity : n*(cost of exploring) with n : number of nodes
     *  n+p : cost of exploring
     *  --> O(n*(n+p))
     *  NOTE: if the graph is represented via an adjacent matrix --> O(pow(n,3))
     * */
   for(int i = 1;i<nb_sommets;i++)
   {
        id = 0;
        printf("\nRound %d\n\n",i);
        for(int j = 1;j<nb_sommets;j++) val[j] = 0;
        explorer_connexe(i);
   } 
}
    /***********************Transitive_Closure***************************/
//void ajouter_arc(sommet x,sommet y){ //for sake of simplicity
void ajouter_arc(unsigned x,unsigned y){ 
    //TODO : STILL BUDDY
    struct noeud* p= (struct noeud*)malloc(sizeof(struct noeud));
    p->s = y;//in reality numero(sommet y);
    
    p->suivant = liste_adj[x];
    
    liste_adj[x] = p;
    
    /*
     *  The Header-insertion(entéte) doesn't depend on the length
     *  of the list  ---> O[1]
     * */ 
   /* 
     //We dont care about order that is why we dont implement the following
    p->s = y;
    p->suivant = liste_adj[x]->suivant;
    if(liste_adj[x]) 
        liste_adj[x]->suivant = p;
    else 
        liste_adj[x] = p;
    */
}  

void transitive_closure(){  
    /*  So basically we're gonna look through each node and see all of the nodes
     *  that it connects indirectly,each two nodes that are connected 
     *  indirectly should be connected with "ajouter_arc" operation
     * */
    struct noeud* p ; 
    for(int i = 0;i<nb_sommets;i++){ 
       p = liste_adj[i]; 
       while(p){ 
            
           //TODO:TO BE COMPLETED
           p = p->suivant;
       }
     }
}
    /********************************************************************/

    /**************************CONVERSION********************************/

void print_matrix(){ 
    for(int i = 1;i<nb_sommets;i++){ 
        if(i==1){
            for(int k = 1;k<nb_sommets;k++)
                printf("%d\t",k); 
        }
        printf("\n");
        printf("\n");
        for(int j = 1;j<nb_sommets;j++){ 
           printf("%d\t",mat_adj[i][j]); 
        }
        printf("\n");
    }
}
void list_to_mat(){
    struct noeud* p ;
   for(int i = 1;i<nb_sommets;i++){
         p  = liste_adj[i]; 
        while(p){
            mat_adj[i][p->s]  =1; 
            p = p->suivant;
        }
   } 
}
void mat_to_list(){  
   struct noeud* p ; 
   /*
    for(int i = 0;i<nb_sommets;i++){ 
        for(int j = 0;j<nb_sommets;j++){ 
            if(mat_adj[i][j] == 1){ 
                p = (struct noeud*)malloc(sizeof(struct noeud));
                p->s = j;
                p->suivant = NULL;
            }
            if(liste_adj[i]){ 
                liste_adj[i]->suivant = p;
            }else{ 
                liste_adj[i] = p;
            }
        }
    }
    */
    for(int i = 1;i<nb_sommets;i++){ 
       for(int j = 1;j<nb_sommets;j++){  
           if(mat_adj[i][j]){
                p = (struct noeud*)malloc(sizeof(struct noeud));  
                p->s = j;
                p->suivant = liste_adj[i]->suivant; 
                liste_adj[i]->suivant = p;
           }
       }
   }
}

int main(){
  struct noeud* t ;
    remplir();
    //display_checker();
    //largeur();
    printf("\n");
    printf("\nDepth-first display:\n");
    profondeur();
    printf("\n-------------------\n");
    printf("\n");
    printf("\n");
    list_to_mat();
    printf("\nConversion list --> MATRIX\n");
    print_matrix();
    printf("\n--------------------------");
    printf("\n");
    printf("\n");
    //You can call mat_to_list only after calling liste_to_mat bcuz 
    //we dont have the matrix intialized from the beginning
    /*mat_to_list();

    printf("\nDepth-first display AFTER MATRIX---> LIST CONVERSION:\n");
    profondeur();
    printf("\n");
    printf("\n");
    printf("\n");
    printf("Largeur\n");
    largeur();
    printf("\n");
    */

    printf("Composants connexe\n");
    composant_connexe();
    printf("------------------\n");
   /* 
    printf("\nAjout arc 1-->5");
    printf("\nSommets directs de 1\n");
    while(t){ 
        t = liste_adj[1];
        printf("%u\t",t->s);
        t = t->suivant;
    }
    printf("\n-------------------\n");
*/
    return 0;
}

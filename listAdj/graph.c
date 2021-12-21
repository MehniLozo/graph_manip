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
            graph input architecture
 * */

#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "file_tda_chaine.c"
//#include "../MatAdj/graph.c"

#define nb_sommets 7
#define nb_edges 100

struct noeud* liste_adj[nb_sommets];
//struct noeud* liste_adj2[nb_sommets]; //for matrix-->liste conversion
//unsigned mat_adj[nb_sommets][nb_sommets];//for liste-->matrix conversion
/*
unsigned mat_adj[nb_sommets][nb_sommets] = {
                        {0,0,0,0,0,0,0},
                        {0,0,1,0,1,0,0},
                        {0,0,0,0,0,0,0},
                        {0,0,0,0,1,0,0},
                        {0,1,0,1,0,0,1},
                        {0,0,0,1,1,0,0},
                        {0,0,0,0,0,1,0}
};
*/

/*
unsigned mat_adj[nb_sommets][nb_sommets] = {
              {0,0,0,0,0,0,0,0},
              {0,0,1,0,1,0,0,1},
              {0,0,0,0,0,0,0,0},
              {0,0,0,0,1,0,0,0},
              {0,0,0,1,0,0,1,0},
              {0,0,0,0,1,0,0,0},
              {0,0,0,0,0,1,0,0},
              {0,0,0,0,0,0,0,0}
 };
 */
/*unsigned mat_adj[nb_sommets][nb_sommets] = { //weighted graph
              {0,0,0,0,0,0,0,0},
              {0,0,3,0,1,0,0,5},
              {0,0,0,0,0,4,0,0},
              {0,0,0,0,4,0,0,0},
              {0,0,0,2,0,0,2,0},
              {0,0,0,0,8,0,0,0},
              {0,0,0,0,0,5,0,0},
              {0,0,0,0,0,0,0,0}
 };*/

/*unsigned mat_adj[nb_sommets][nb_sommets] = {
                        {0,0,0,0,0,0,0},
                        {0,0,1,1,0,0,0},
                        {0,0,0,1,0,0,1},
                        {0,0,0,0,0,0,1},
                        {0,0,1,0,0,1,0},
                        {0,0,1,0,0,0,0},
                        {0,0,0,0,0,0,0}

};
*/
/*
unsigned mat_adj[nb_sommets][nb_sommets] = { //weighted graph matrix
                        {0,0,0,0,0,0,0},
                        {0,0,8,0,0,0,0},
                        {0,0,0,0,0,0,0},
                        {0,0,0,0,3,0,7},
                        {0,0,0,4,0,5,0},
                        {0,0,0,0,7,0,0},
                        {0,0,0,0,0,6,0}
};
*/
unsigned mat_adj[nb_sommets][nb_sommets] = { //undirected & weighted graph
    {0,0,0,0,0,0,0},
    {0,0,1320,0,0,0,2640},
    {0,1320,0,1160,850,835,920},
    {0,0,1160,0,0,780,2880},
    {0,0,850,0,0,0,0},
    {0,0,835,780,0,0,750},
    {0,2640,920,2880,0,750,0}
};

int val[nb_sommets]; //variable pour memoriser l'etat d'un sommet visité ou non
unsigned T[nb_sommets]; //T for MST
unsigned id; //ordre de la visite
int circuit; //In order to detect if there is a circuit in our graph
int found;


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
 printf("\n");

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
//unsigned deg_int(sommet s) REPLACED FOR SAKE OF SIMPLICITY
unsigned deg_int(unsigned s){
    //calculate the sum of arcs entering the s node tho
   unsigned nb = 0; struct noeud* p;
    for(int i = 0;i<nb_sommets;i++) 
    {
        p = liste_adj[i]; 
        while(p && p->s !=s) p=p->suivant;    
      if(p) nb ++;  
    }
    return nb;
    /*Compléxité O(N*P) avec N le nombre de sommets et P le nombre d'arc 
      d'un sommet particulier*/
}

unsigned arc(unsigned s1,unsigned s2){
    struct noeud* p = liste_adj[s1];
    while(p && p->s!= s2) p = p->suivant;
    if(p) return 1;

    return 0;
}
//unsigned deg_ext(sommet s)
//unsigned ieme_succ(unsigned i,sommet s) replaced it for sake of SIMPLCITY

unsigned ieme_succ(unsigned i,unsigned s)
{
    unsigned nb = 0;
    struct noeud* p = liste_adj[s];//s as the node ,could've been numero(s),just for simplicity's sake
    while(p && nb < i )
    {
        p = p->suivant;
        nb++;
    }
    if(p)
        return p->s;
    //return error();
    //returned zero supposedly that we don't have 0 as a node tho
    return 0;
}
    /************************COMPOSANT CONNEXE**************************/
void explorer_connexe(unsigned k)
{
    /*
     *explorer_connexe : function that checks all the nodes that 
     can get connected to each others whether thats directly or inderectly
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
        //every set of node is gonna have its own val array in order
        //to keep track 
        for(int j = 1;j<nb_sommets;j++) val[j] = 0; 
        explorer_connexe(i);
   } 
   printf("\n");
}
        /***********************PATH******************/
void explorer_largeur_path(unsigned k,unsigned y){ 
   id++;
   enfiler(k);
   struct noeud*t ;  
   while(!file_vide()){ 
       k = premier();
       val[k] = id;
       defiler();
       t = liste_adj[k];
       if(k == y){ found = 1; return; }
       while(t){ 
           if(val[t->s] == 0){ 
               enfiler(t->s);
               val[t->s] = -1;
           }
           t = t->suivant;
       }
     }
}
void path(unsigned x,unsigned y){ 
   //determins if there exists a way from x --> y 
   //We'll use the Breadth first search technique
   creer_file();
   unsigned cout = 0;
   found = 0;
   id = 0;
   for(int i = 0;i<nb_sommets;i++) val[i] = 0;
   struct noeud* p = liste_adj[x];
   while(p){ 
     printf("Here tho id = %d\n",id);
    if(val[p->s] == 0)
        explorer_largeur_path(p->s,y);
    if(found){ 
            for(int j = 0;j<nb_sommets;j++)
              cout += j;
            printf("\nIl existe un moyen d'aller de %d vers %d avec cout = %d\n",x,y,cout);
            return;
        }
    p = p->suivant;
   }
   printf("\nIl n'existe pas un moyen de %d --> %d\n",x,y);
}

//TODO:
/*
void shortest_path(unsigned x,unsigned y){ 
    //look for the shortest path x--->y

}*/
    /***********************Transitive_Closure***************************/
//void ajouter_arc(sommet x,sommet y){ //for sake of simplicity
unsigned numero(unsigned x){
    return x; //just for now tho
}
void ajouter_arc(unsigned x,unsigned y){ 
    //TODO : STILL BUDDY
    //We didn't specify that much,bcyz we'd know exactly when to call
    //thats why we didn't conditionize alot :)
    struct noeud* p= (struct noeud*)malloc(sizeof(struct noeud));
    p->s = numero(y);
    
    p->suivant = liste_adj[numero(x)]; 
    
    liste_adj[numero(x)] = p;
    
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
unsigned nom(unsigned x)
{
    return x; //just for now
}
void transitive_closure(){  
    /*  So basically we're gonna look through each node and see all of the nodes
     *  that it connects indirectly,each two nodes that are connected 
     *  indirectly should be connected with "ajouter_arc" operation
     * */
    unsigned k,j,s;
    for(k = 0;k<nb_sommets;k++){
        id = 0;
        for(j = 0;j<nb_sommets;j++) val[j] = 0;
        explorer_prof(k);
        for(s = 0;s<nb_sommets;s++)
            if(s!= k){
                if(val[s] != 0 && !arc(nom(k),nom(s)))
                    ajouter_arc(nom(k),nom(s));
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
        printf("\n");
        printf("\n");
        }
        printf("\n");
        printf("\n");
        for(int j = 1;j<nb_sommets;j++){ 
           printf("%d\t",mat_adj[i][j]); 
        }
        printf("\n");
        printf("\n");
    }
}
                            /*CONVERSIONS*/
void list_to_mat(){
    struct noeud* p ;
    unsigned i,j;
    //initialisation
    for(i = 0;i<nb_sommets;i++)
        for(j = 0;j<nb_sommets;j++)
            mat_adj[i][j] = 0;
   for(i = 1;i<nb_sommets;i++){
         p  = liste_adj[i]; 
        while(p){
            mat_adj[i][p->s]  =1; 
            p = p->suivant;
        }
   } 
}
void mat_to_list(){  
   struct noeud* p ; 
  
  //erroneous version tho
  ///*
  /*
    for(int i = 0;i<nb_sommets;i++){ 
        for(int j = 0;j<nb_sommets;j++){ 
            if(mat_adj[i][j] == 1){ 
                p = (struct noeud*)malloc(sizeof(struct noeud));
                p->s = j;
            }
            if(liste_adj[i]){ 
                p->suivant = liste_adj[i];
            }else{ 
                 p->suivant = NULL;
            }
            liste_adj[i] = p;

        }
    }
  */
   
   for(int i = 1;i<nb_sommets;i++){ 
       for(int j = 1;j<nb_sommets;j++){  
           if(mat_adj[i][j]){
                p = (struct noeud*)malloc(sizeof(struct noeud));  
                p->s = j;
                p->val = mat_adj[i][j];
                if(liste_adj[i]){
                    p->suivant = liste_adj[i]->suivant; 
                    liste_adj[i]->suivant = p;}
                else {
                    liste_adj[i] = p; p->suivant = NULL;
                }
           }
       }
   }
}
                    /*************Warshall applied to adjacency list*************/
void Warshall_list(){
    /*
    Well,the act in here is to transform your current adjacency list graph into a matrix graph
    so as a result you can exploit the original Warshall's algorithm
    */
   list_to_mat();
   for(int i = 0;i<nb_sommets;i++){
       for(int j = 0;j<nb_sommets;j++){
           if(mat_adj[i][j])
            for(int k = 0;k<nb_sommets;k++)
                mat_adj[i][k] = 1;
       }
   }
   mat_to_list();
}
                    /************************************/
                    /*Depth-first parcours MATRICE*/
void explorer_prof_mat(unsigned k){
    printf("\n");
    id++;
    val[k] = id;
    printf("\t%d",k);

    for(int s = 1;s<nb_sommets;s++){
        if(mat_adj[k][s] && !val[s]){
                    explorer_prof_mat(s);
            }
        }
    }

void profondeur_mat(){
    int i;
    id = 0;
    for(i = 1;i<nb_sommets;i++) val[i] = 0;
    for(i = 1;i<nb_sommets;i++){
        if(val[i] == 0)
            explorer_prof_mat(i);

    }
    printf("\n");
}
    /*Largeur matrice*/
void explorer_larg_mat(unsigned k){
    int j;
    id++;
    val[k] = id;
    enfiler(k);
    printf("%d\t",k);
    while(!file_vide()){
        k = premier();
        defiler();
        
        for(j = 1;j<nb_sommets;j++)
            if(mat_adj[k][j] && !val[j])
            {   
                val[k] = -1;
                enfiler(j);
            }
    }
    printf("\n");
}
void largeur_mat(){
     creer_file();

    int i;
    for(i = 0;i<nb_sommets;i++) val[i] = 0;
    for(i = 0;i<nb_sommets;i++)
         //printf("\nRound %d",i);
        if(val[i] == 0){
            explorer_larg_mat(i);
        }
}

            /******************************************************/
             /******************************************************/




            /***********************Circuit*********************/
void error(){ 
    printf("\nIl n'yavait aucun circuit\n");
}
void explorer_circuit(unsigned k){ 
    printf("%d\n",k);
   struct noeud* t = liste_adj[k];
   id ++;
   val[k] = id;
   while(t){ 
    if(val[t->s] == 0) explorer_circuit(t->s);
    else {circuit = 1; return;}
    t = t->suivant;
   } 
}
void detect_circuit(){ 
    //We're gonna use depth-first parcours (profondeur) in order to detect
    //if our graph contains a circuit(at least one,if we find one --> quit)
 
    circuit = 0;
    id = 0;
   for(int i = 1;i<nb_sommets;i++) val[i] = 0;

    for(int i = 1;i<nb_sommets;i++){ 
        if(val[i] == 0) explorer_circuit(i);
        if(circuit){ printf("\nIl existe un circuit pour %d\n",i); return;}
        else error();
     }
   
}
                /*Spanning tree*/
void minimum_spanning_tree(){
    //Kruskal implementation with Matrix
    //Sort the edges of the graph G (give each one of them a number)
    //allocate randomly in case of equality
    unsigned k = 1; unsigned i = 0; unsigned j = 0;
    /*T represents the Tree subset of Graph G acyclic and connexe
      T should be an array thats gonna hold the nodes in order
      based on their costs(each edge has a cost and that edge is 
      integrated with the node tho)
        T is initially empty tho
    */
   //First Step sorting edges:
    for(i;i<nb_sommets;i++){
        for(j;j<nb_sommets;j++){
            if(mat_adj[i][j] != 0)
            {
               /* unsigned p = 0;
                while(mat_adj[i][j] > edges[p] && p<nb_edges)
                    p++;
                edges[p] = mat_adj[i][j]; //put it in the right pos
            */
           }
        }
    }

}

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define nb_sommets 7
unsigned mat_adj[nb_sommets][nb_sommets] = {
                        {0,0,0,0,0,0,0},
                        {0,0,1,0,0,0,0},
                        {0,0,0,0,0,0,0},
                        {0,0,0,0,1,0,0},
                        {0,0,0,0,0,0,1},
                        {0,0,0,0,1,0,0},
                        {0,0,0,0,0,1,0}

};
unsigned val[nb_sommets];
unsigned id;

    /*****************Depth-first parcours aka profondeur**********/

void explorer_prof(unsigned k){
    id++;
    val[k] = id;
    printf("\t%d",k);

    for(int s = 1;s<nb_sommets;s++){
        if(mat_adj[k][s] && !val[s]){
                    explorer_prof(s);
            }
        }
    }

void profondeur(){
    int i;
    id = 0;
    for(i = 1;i<nb_sommets;i++) val[i] = 0;
    for(i = 1;i<nb_sommets;i++){
        if(val[i] == 0)
            explorer_prof(i);

    }
    printf("\n");
}

void transitive_closure_walshman(){
  int x,y,z;
  for(x = 1;x<nb_sommets;x++)
    for(y = 1;y<nb_sommets;y++)
      if(mat_adj[x][y])
        for(z = 1;z<nb_sommets;z++)
          if(mat_adj[y][z])
            mat_adj[x][z] = 1;//We dont care whether about the initial state of mat[x][z] whether x & z initially connected or not
}
/*

void error(){
    printf("\nça n'existe pas\n");
}
unsigned deg_ext(unsigned s){
    //on fixe la ligne
    //in the right manner int ligne = numero(s)
    unsigned nb = 0;
    for(int j = 0;j<nb_sommets;j++){
       if(mat_adj[s][j] == 1) nb++;
    }
    return nb;
}
unsigned deg_int(unsigned s){
    //on fixe la colonne
    int i;
    unsigned nb=0;
    for(i =0;i<nb_sommet;i++){
        if(mat_adj[i][s] == 1)
            nb++;
    }
   return nb; 
}
unsigned ieme_succ(unsigned s,unsigned i)
{
    //Complexité O(P) avec P le nombre d'arc 
    unsigned nb = 0,j = 0;
    while(j<nb_sommet && nb <i) 
        if(mat_adj[s][j] == 1)
            nb ++;
    if(j =< nb_sommets)
        return j;
    else error();
}
*/
    /*******************OP_Parcours**************/
//Parcours en profondeur
    /******************Transitive_closure*******/
//unsigned numero(sommet x){
   /*This functions configuration is temporary and just for
    * ease of implementation*/
  // return x.succ;
                
//}

/*void ajouter_arc(sommet x,sommet y){ 
    mat_adj[numero(x)][numero(y)] = 1;
}
*/


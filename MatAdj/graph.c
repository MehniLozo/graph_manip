#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define nb_sommets 8
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

unsigned mat_adj[nb_sommets][nb_sommets] = {
              {0,0,0,0,0,0,0,0},
              {0,0,1,0,1,0,0,1},
              {0,0,0,0,0,1,0,0},
              {0,0,0,0,1,0,0,0},
              {0,0,0,1,0,0,1,0},
              {0,0,0,0,1,0,0,0},
              {0,0,0,0,0,1,0,0},
              {0,0,0,0,0,0,0,0}
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

void transitive_closure_warshall(){
  int x,y,z;
  for(x = 1;x<nb_sommets;x++)
    for(y = 1;y<nb_sommets;y++)
      if(mat_adj[x][y])
        for(z = 1;z<nb_sommets;z++)
          if(mat_adj[y][z])
            mat_adj[x][z] = 1;//We dont care whether about the initial state of mat[x][z] whether x & z initially connected or not
  //Complexity of the previous algo is O(n^3) with n = number of nodes
}
                /************************Shortest Path**************/
void shortest_paths_WarshallFloyd(){
 /*WalshmanFloyd algorithm is applied only on adjacency matrix and specifically weighted-graphs  
  The following algorithm uses almost the same concept of Transitive closure Washall algorithm 
  Mat[i][j] != 0 :
        -Warshall : there exists a way from x -> y
        -Floyd : Its the shortest known way at this current moment to go from x -> y
  Both Philosophies Combined :
 if mat[x][y] = 0 : doesn't exist a path from x -> y
            v != 0 : There exists a path from x -> y with mat[x][y] represents the cost of transition for node x to y 
    By definition mat[x][y] should always represents the shortest discovered path tho
 */
  //NOTE : TODO STILL FACING A MISFUNCTIONNING
  unsigned x,y,z;
  for(x = 0;x<nb_sommets;x++)
    for(y = 0;y<nb_sommets;y++)
      //if(mat_adj[x][y]) //necessary instead of looping wastefully in case of [x][y] = 0
        for(z = 0;z<nb_sommets;z++)
          if((mat_adj[x][y]*mat_adj[y][z] != 0 && x!= z))
              if((mat_adj[x][y] + mat_adj[y][z] < mat_adj[x][z]) || mat_adj[x][z] == 0)
                mat_adj[x][z] = mat_adj[x][y] + mat_adj[y][z];
  }
                /*****************************************************/
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
    }
}



/*
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
}*/

int ieme_succ(unsigned s,unsigned i)
{
    //Complexité O(P) avec P le nombre d'arc 
    unsigned nb = 0,j = 0;
    while(j<nb_sommets && nb <i) 
        if(mat_adj[s][j] == 1)
            nb ++;
    if(j <=nb_sommets)
        return j;
    return -1;
}
unsigned numero(unsigned x){ 
    return x;
}
//void ajouter_arc(sommet x,sommet y){ 
void ajouter_arc(unsigned x,unsigned y){ 
    mat_adj[numero(x)][numero(y)] = 1;
}



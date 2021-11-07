//Matrice adjacente
//In the following script we'll ignore the "numero(s)" function in order 
//to get it up and working , we'll just pass in a normal number 
//NO SOMMET STRUCTURE AT THE MOMENT --> type of s --> unsigned
#nb_sommet 6
unsigned mat_adj[nb_sommet][nb_sommet] = { 
                                             {0,1,1,0,0,0},
                                             {0,0,1,0,0,1},
                                             {0,0,0,0,0,1},
                                             {0,1,0,0,1,0},
                                             {0,0,0,0,0,0}
};
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
/*******************OP_Parcours**************/
//Parcours en profondeur

void main(){
    
}


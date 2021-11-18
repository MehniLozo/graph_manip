#include <stdlib.h>
#include <stdio.h>
#include "graph.c"

int main(){
  //struct noeud* t ;
    //display_checker();
    //largeur();
    /*printf("\n");
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
    mat_to_list();

    printf("\nDepth-first display AFTER MATRIX---> LIST CONVERSION:\n");
    profondeur();
    printf("\n");
    printf("\n");
    printf("\n");
    printf("Largeur\n");
    largeur();
    printf("\n");
    printf("\n**********Circuit********\n");
    detect_circuit();
    */
/*
    printf("Composants connexe\n");
    composant_connexe();
    printf("------------------\n");
  */
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
    remplir();
    //detect_circuit();
    list_to_mat();
    mat_to_list();
    print_matrix();
    //path(1,3);
    //composant_connexe();
    return 0;
}

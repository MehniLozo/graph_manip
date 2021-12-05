#include <stdlib.h>
#include <stdio.h>
#include "graph.c"

int main(){
    mat_to_list();
    print_matrix();
    path(4,1);
    path(4,7);
    path(5,3);
    path(2,1);
    path(2,6);
    printf("\nParcours profondeur\n");
    profondeur();
    //transitive_closure();
    //list_to_mat();
    //print_matrix();
   return 1;
}

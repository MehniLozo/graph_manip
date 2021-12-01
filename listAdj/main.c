#include <stdlib.h>
#include <stdio.h>
#include "graph.c"

int main(){
    mat_to_list();
    print_matrix();
    path(1,6);
    //transitive_closure();
    //list_to_mat();
    //print_matrix();
   return 1;
}

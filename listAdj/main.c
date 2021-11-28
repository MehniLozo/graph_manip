#include <stdlib.h>
#include <stdio.h>
#include "graph.c"

int main(){
    mat_to_list();
    print_matrix();
    transitive_closure();
    list_to_mat();
    print_matrix();
   return 1;
}

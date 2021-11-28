#include <stdlib.h>
#include "graph.c"
#include <stdio.h>


int main(){
    print_matrix();  
    transitive_closure_warshall();
    printf("\n---------------TRANSITIVE_CLOSURE_WARSHALL---------------\n");
    printf("\n\n");
    print_matrix();  
  /*
    print_matrix();
    printf("\nShortest path application\n");
    shortest_paths_WarshallFloyd();
    print_matrix();*/
    
    return 1;
}


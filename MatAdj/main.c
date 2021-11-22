#include <stdlib.h>
#include "graph.c"
#include <stdio.h>


int main(){
    print_matrix();
    printf("\nShortest path application\n");
    shortest_paths_WalshmanFloyd();
    print_matrix();
    return 1;
}


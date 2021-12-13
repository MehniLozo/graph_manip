                          /*Krushkal & Prim for MST*/
  /*
   * Both Krushkal and Prim algorithms make a locally optimal choice intending to find the global optimal solution --> Greedy Algorithms
 *The major difference between Krushkal's and Prim's way
    Krushkal chooses the lowest edge to go through globally unlike Prims it takes the minimum decision from a certain reached node (only local view)
 * */

void Krushkal(){
  /*
   *  Informal Description:
   *    step 1 : 
   *      Sort all edges growingly {u1,u2....un}
   *    step 2:
   *      U = {}
   *      start adding edges into U in a way that the old edges and the newest added 
   *      dont form a cycle
   *      Loop until  we've added all possible edges 
   * */ 
}

void Prim(){
  /*
   * Informal Description
   *    Start from the chosen node
   *    at each step choose the cheapest connected node
   * */
}

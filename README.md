# Graph
## What is It?
This Repo has a set of a collection of various Graph representations and operations that are possible on the graph
## Representations
### Adjacency Matrix
### Adjacency List

## Operations
###  Transitive Closure
Each vertex that could be connected "indirectly" to other vertices ,shall be connected directly to those.
#### Warshall on adjacency matrix
#### Adjacency-list Transitive Closure
### Warshall-Floyd Algorithm for finding shortest path
Warshall-Floyd Algorithm combines both Warshall and Floyd philosphies together.
Warshall-Floyd algorithm is applied only on adjacency matrix and specifically weighted-graphs  
  The following algorithm uses almost the same concept of Transitive closure Warshall algorithm 
  Mat[i][j] != 0 :
        -Warshall : there exists a way from x -> y
        -Floyd : Its the shortest known way at this current moment to go from x -> y
  Both Philosophies Combined :
 if mat[x][y] = 0 : doesn't exist a path from x -> y ; at least till this moment
             != 0 : There exists a path from x -> y with mat[x][y] represents the cost of transition for node x to y 
    By definition mat[x][y] should always represents the shortest discovered path tho
### Topological Sorting
#### Philosophy
What Topological sorting is all about :
Having a graph that each node represent a task and edges represent the order
That being said,a vertex (task) precedes other task (other vertex) if the first vertex has an arc towards the next vertex
So, in order to have a basic sorting we'd need a special type of list to represent a graph
why a list?
Because lists are the best data-structures for manipulating orders
Reasoning is based on lists.
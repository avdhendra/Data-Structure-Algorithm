/*
A spanning tree is a subset of Graph G, which has all 
the vertices covered with minimum possible number of 
edges. Hence, a spanning tree does not have cycles 
and it cannot be disconnected..

A complete undirected graph can have maximum n^n-2
number of spanning trees, where n is the number 
of nodes.


*****General Properties of Spanning Tree****


* A connected graph G can have more than one spanning 
tree.

* All possible spanning trees of graph G, have the 
same number of edges and vertices.

*The spanning tree does not have any cycle (loops).

*Removing one edge from the spanning tree will make 
the graph disconnected, i.e. the spanning tree is 
minimally connected.
 
 *Adding one edge to the spanning tree will create a 
circuit or loop, i.e. the spanning tree is maximally
acyclic.

*******Mathematical Properties of Spanning Tree*******

*Spanning tree has n-1 edges, where n is the number of nodes (vertices).

*From a complete graph, by removing maximum e - n + 1 edges, we can
construct a spanning tree.

*A complete graph can have maximum n^n-2 number of spanning trees.




      Graph:-          ( 1 )
                        /|\
                  (1)  / | \  (2)
                      / (2) \
                   ( 2 )---( 3 )
                     \   |   /
                ( 3 ) \(2)|  / ( 3 )
                       \ | /
                       ( 4 )
      
      Number of Spaning Tree= number of Edge=number of Node -1
                                            =7-4+1 =4
                                              Edge-Node+1
        
      ( 1 )
      /   (1)
     /   (2)
  ( 2 )------(3)           Spanning Tree 1 
             /
            / (3)
        ( 4 )               Total cost=6

 
     ( 1 )
      / 
     /  (1)
 ( 2 )    ( 3 )           Spanning Tree 2
   \       /
(3) \     / (3)           Total Cost=7
     \   /
     ( 4 )
 

      ( 1 )               Spanning Tree 3
 (1) /  |  \ ( 2 )                         This is Minimum spanning tree
    /(2)|   \             Total cost=5
 ( 2 )( 3 )( 4 )

     ( 1 )              Spanning Tree 4
 (1)/    \ ( 2 )
   /      \             Total Cost=6
( 2 )    ( 3 )
          /  ( 3 )
         /
      ( 4 )



and Minimum Spanning Tree is those whose edge weight is Less








PRIMS ALGORITHM

* It starts to build the Minimum Spanning Tree 
from any vertex in the graph.	

*It traverses one node more than one time to get the 
minimum distance.	

*Prim’s algorithm has a time complexity of O(V^2), 
V being the number of vertices and can be improved
up to O(E + log V) using Fibonacci heaps.

*Prim’s algorithm gives connected component as well 
as it works only on connected graph.	

*Prim’s algorithm runs faster in dense graphs.	



KRUKSHAL ALGORITHM


*It starts to build the Minimum Spanning Tree from 
the vertex carrying minimum weight in the graph.

*It traverses one node only once.

*Kruskal’s algorithm’s time complexity is 
O(E log V), V being the number of vertices.

*Kruskal’s algorithm can generate 
forest(disconnected components) at any 
instant as well as it can work on disconnected 
components

*Kruskal’s algorithm runs faster in sparse graphs.






















*/
/*
         Single Source Shortest Path Algorithm
          __________|______________
         |          |              |
        BFS     Dijkstra      BellmanFord
   0(V+E)       0(E log v)     0(V E)


BFS use when U have Unweighted Graph

Dijkstra use when u have weighted(+ve Weighted) Graph

Bellman Ford
use when u have weighted (-ve Weighted Graph)
    

     ( 2 )
 2  /  |
   /   |               (Directed Graph)
( 1 )  | (-3)
   \   |
  4 \  |       so the Sortest path will be
    ( 3 ) 


    4+(-3)=1   (1)  (2)  this the sortest path
                \   /
                 \ /
                 (3)
*/
/*

Bellman Ford
Works:-
Step 1: Initialise dist[vertices]=INT_MAX,dist[Src]=0
Step 2: Relax all edges V-1 time[MOst Important]
Step 3:Negative Weight Cycle Detection

      Inifinity
     ( 2 )
 2  /  |
   /   |               (Directed Graph)
( 1 )  | (-3)
0  \   |
  4 \  |       so the Sortest path will be
    ( 3 ) 
Inifinity



Edge(3,2),(1,3)(1,2)


what is Relaxation

    wt
(U)------->(V)

dist[u]     dist[v]

Update
if(dis[v]>dist[u]+wt)
{
    dist[V]=dist[U]+wt
}
 
 for example let say
     dist[A]=5
   ......(A) 
           \
            \ 1
             \
......(B)----(V) dist[V]=Infinity
dist[B]=3 -2 /
            /
           / 3
  ......(C)
     dist[C]=6


since distance of v is Infinity Update the dist[V]=dist[A]+wt
                                           dist[V]=5+1=6
since distance of V is 6 and distance of B+wt is less so we update 
 dist[V]=dist[B]+wt=3-2=1

 but here distance of v is 1 which is Not greater than the 
 distance[C]+wt=6+3=9 so we dont update the Distance of V and it is =1

we have to do this relaxation to all v-1  


Infinity =I

lets Take and Example 

  _________3___________        __________10___________
 |                    |        |                     |
 |                    |        |                     |
 |                    V        |                     V
(1)------->(2)------>(3)----->(4)------->(5)------->(6)
 |  2       |    2    |    5   |     6    |   7      |
 V          V         V        V          V          V 
 Src        I         I        I          I          I
 0        

EdgeList first we Take it by Some Specific Order but Not all the time
we have Given the Graph as order
we choose the Edge In Such a Order so that we Can minimize distance in First Iteration
discard =X

Edge List
A - B
B - C
A - C
C - D
D - E
E - F
D - F

Updation
if(dist[v]>dist[u]+wt)
{
    dist[v]=dist[u]+wt
}

 Iteration     |  A  |   B   |   C   |   D   |   E   |  F    |
  Initial      |  0  |   I       I       I       I       I
     
 Operation     |     | 0 + 2 |  2+2  |  3+5  |  8+6  |  14+7  |  
                             | 0+3   |               |  8+10  |
 
  Ist          |  0  |   2   |  4 X  |   8   |  14   |  21 X   |  
                             |   3   |               |  18     |

Best possible  |  0  | 2     | 3     | 8     |  14   |   18     |





but if The Edge Not Given In any Specific Order
we Take reverse of Edge List

if(dist[v]>dist[u]+wt)
{
    dist[v]=dist[u]+wt
}




 _________3___________        __________10___________
 |                    |        |                     |
 |                    |        |                     |
 |                    V        |                     V
(A)------->(B)------>(C)----->(D)------->(E)------->(F)
 |  2       |    2    |    5   |     6    |  - 7     |
 V          V         V        V          V          V 
 Src        I         I        I          I          I
 0        






Edge List

D - F    after first Observation u will always the part that has 1 edge between them
E - F
D - E
C - D
A - C
B - C
A - B



 Iteration     |  A  |   B   |   C   |   D   |   E   |  F    |
  Initial      |  0  |   I   |   I   |   I   |   I   |  I    |
     
 Operation           | 0+2   |  0+3  |               |I+10=I=I|  
                             |I+2!<3 |     
                             No update
  Ist          |  0  |   2  |  3    |   I   |  I   |   I     |  
                                            
  
  Operation                         |3+5=8 |
   
  IInd        |  0  |   2  |  3    |   I X |  I   |   I     |
                                   |  8    |
Operation                                  |8+6   | 10+8    |

  IIIrd       |  0  |   2  |  3    |   8   |  I X |   I  X   |
                                           | 14   |  18      |

 Operation                                        |  14-7    |

  IV         |  0  |   2  |  3    |   8   |  14   |   18 X   |
                                                  |   7      |


               if you have V Nodes in Graph 
               you habe v-1 edges so you Have to Iterate over it V-1
               times





Negative Cycle
       ( 2 )
      /   |
  2  /    |   
    /     |
( 1 )     |  -4               they all are directed Graph
   \      |
    \     |
  1  \    |
      ( 3 ) 
                         here vertex is 3 so the number of iteration will be 3-1=2
                         and if in the 3rd iteration distance change it is -ve weight cycle
1:Cycle

1  to  2 = dist[2]=2

2 to 3 =dist[3]=2-4=-2

3 to 1= dist[1]=0 (prev)
       dist[1]= -2+1 = -1

2:Cycle

1 to 2 = dist[2]=-1+2=1

2 to 3 =dist[3]=1-4=-3

3 to 1= dist[1]=-1(prev)
        dist[1]=-2
........
........
|
|
V
Till Infinity this distance keep Change(To infinity) so here it is Negative weight Cycle is present

so we have to iterate till V-1 time and after if distance keep change it has -ve weight cycle







*/
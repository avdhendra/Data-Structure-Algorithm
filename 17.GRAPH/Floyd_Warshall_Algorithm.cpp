/***
 ****** Floyd Warshall Algorithm****

 -All Pair Shortest path
 -Shortest Betwenn All pair of Vertices
 -Works with negative edges
 -Can detect negative Cycle Too with on extra Step


you can shortest path from any node 

you can use bellman and Dijsktra to find shortest path
but it act on single src node 
but this node give sortest path between 1,2,3,4 in one go

                 (1)->(2,3,4)
                 (2)->(1,3,4)
                 (3)->(1,2,4)
                 (4)->(1,2,3)

It is Dp Based 0(N^3) time complexity N:-verticess
     1  2    3  4
   ________________                 distance between 1 and 1 is 0  distance betweem 1 and 2 is 4
1 |_0_|_I_|_-2|_I_|                        . ( 1 )
2 |_4_|_0_|_3_|_I_|                     4  /     \  -2
3 |_I_|_I_|_0_|_2_|  <===                 /   3   \ .
4 |_I_|_-1_|_I_|_0|                  ( 2 )---------( 3 )
                                       .  \        /     
                                        -1 \      / 2
                                             ( 4 ).

we show distance between node in form of adjacency matrix
. = represent the arrow (<,>,V,^) 


    1  2    3  4
   ________________ 
1 |_0_|_I_|_-2|_I_|
2 |_4_|_0_|_3_|_I_|
3 |_I_|_I_|_0_|_2_|  
4 |_I_|_-1_|_I_|_0|


D[i][j]=min(d[i][j],d[i][k]+d[k][j]);
this method use in algorithm

we take order of v^2 space and V^3 time
*/
#include<bits/stdc++.h>
using namespace std;
//we define this because we dont want overflow of program
#define INF 10000
vector<vector<int>>floyd_Warshall(vector<vector<int>>Graph)
{
    vector<vector<int>>Dist(Graph);
    int V=Graph.size();

    //Phases in Kth Phase we Included Vertices (1,2,3....k) as intermediate Vertices 
    for(int k=0;k<V;k++)
    {//Iterate Over Entire 2D Matrix
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                //If Vertex k is Included and can we Minimize the Dist
                if(Dist[i][j]>Dist[i][k]+Dist[k][j])  //this could lead to Overflow when you add int_max with some thing so we take Int_max and 10000
                {
                   Dist[i][j]=Dist[i][k]+Dist[k][j];
                }
            }
        }
    }


    //To check it contain Negative Weight cycle
    for(int k=0;k<V;k++)
    {//Iterate Over Entire 2D Matrix
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                //If Vertex k is Included and can we Minimize the Dist
                if(Dist[i][j]>Dist[i][k]+Dist[k][j])  //this could lead to Overflow when you add int_max with some thing so we take Int_max and 10000
                {
     cout<<"Negative Weight Cycle Contain "<<endl;
     exit(0);
                }
            }
        }
    }
    return Dist;

}
int main(){
vector<vector<int>>Graph={{0,2,INF},
                          {INF,0,-4},
                          {1,INF,0},
                          };
        
auto Floyed=floyd_Warshall(Graph);
for(int i=0;i<Floyed.size();i++)
{
    for(int j=0;j<Floyed.size();j++)
    {
        cout<<Floyed[i][j]<<"  ";
    }
    cout<<endl;
}
return 0;
}
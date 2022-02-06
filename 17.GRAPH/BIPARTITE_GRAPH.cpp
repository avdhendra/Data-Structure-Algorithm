/*

*******  BIPARTITE GRAPH *******
                       1
                     ( 0 )
                    /     \
                   /       \
          2     ( 1 )       ( 3 )    2
                 |           |
                 |           |
          1    ( 2 )       ( 4 )     1


          we have to in else if case that nbr us Node me na Jaye jise wo aya hai
          mean nbr !=parent because wo already visited hai and uska color hume change nahi karna hai

Test Case:1

                       1
                     ( 0 )
                    /     \
                   /       \
          2     ( 1 )       ( 3 )    1
                 |           |
                 |           |
          1    ( 2 )--------( 4 )     2

when we call first Node is 0 which nbrs are 1 and 3
so

*/
#include<bits/stdc++.h>
using namespace std;
bool Dfs_Helper(vector<vector<int>>Graph,int Node,int*visited,int parent,int color)
{
    //Come to Node
    visited[Node]=color;  // 1 or 2 both Mean Visited
    
    for(auto nbr:Graph[Node])
    {
        if(visited[nbr]==0)
        { /*
            if the color is 1 current then we can do either if case or
            we can do 
            3-color if current is 1 then next color should be 3-1=2
            and if current color  is 2 then next color should be 3-2=1 
        */
                    int SubProb=Dfs_Helper(Graph,nbr,visited,Node,3-color);
                    if(SubProb==false)
                    {
                        return false;  //this graph is bipartite
                    }
        }
        else if(nbr!=parent and color==visited[nbr])
        {
            return false;  //this graph is bipartite
        }
    
    }
    return true;
}
bool dfs(vector<vector<int>> Graph,int n) //int n is Number of Vertices
{
    int visited[n]={0};  //0- Not visited ,1-visited color is 1 2-visited color 2
    //This Array Serve the Purpose of two array  1: color 2: visited 
    //Let the First Color be
    int color=1; 
    
   bool result= Dfs_Helper(Graph,0,visited,0,color);
   //color
   for(int i=0;i<n;i++)
   {
       cout<<i<<" color is -"<<visited[i]<<endl;
   }
   return result;
}
int main(){
int N,M; //Number Node:N,Number of Edge M
cin>>N>>M;
vector<vector<int>> Graph(N); //intialise 2d vector as this or
//vector<int>Graph[N] both will be same
while(M--)
{
    int x,y;
    cin>>x>>y;
    Graph[x].push_back(y);
    Graph[y].push_back(x);
}

//BFS or DFS by coloring the Node at Each Step if current node has color1
//Then Nbr should Have a color 2

int n=Graph.size();
if(dfs(Graph,n))
{
    cout<<"This is Bipartite Graph"<<endl;
}
else{
    cout<<"This is Not Bipartite Graph"<<endl;
}

return 0;
}
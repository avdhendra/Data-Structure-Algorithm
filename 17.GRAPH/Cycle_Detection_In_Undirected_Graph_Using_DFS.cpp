/*
     (0)-------------(1)
     /                |
    /                 | 
   /                  |
(4)                   |
  \                   |
   \                  |
    \                 |
     \                |
     (3)-------------(2)


BFS or DFS can we Used
cycle in graph- if there is more than 1 way to visit any Node

the Only case we Need to See is if nbr not same as parent during checking visites

*/

#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Graph{
    public:
    map<T,list<T>>l;
    void addEdge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);

    }
bool Cycle_helper(T src,map<T,bool>&visited,int parent)
{
if(visited[src]==false)
{
    // Mark the current node as visited
    visited[src]=true;
}

// Recur for all the vertices
    // adjacent to this vertex

for(auto nbr:l[src])
{
    if(visited[nbr]!=true)
    {
        //Go and Recursively Visit the Nbr
      bool Cycle_mila=Cycle_helper(nbr,visited,src);
      if(Cycle_mila)
      return true;

    }
     // If an adjacent vertex is visited and
        // is not parent of current vertex,
        // then there exists a cycle in the graph.
    else if(nbr!=parent)
    {
        return true;

    }

}
return false;
}
bool Contain_Cycle(T src)
{
    map<T,bool>visited;
    int parent=-1;
    for(auto i:l)
    {
        T Node=i.first;
        visited[Node]=false;
    }
    return Cycle_helper(src,visited,parent);
}

};
int main(){
Graph <int> G;
G.addEdge(0,1);
G.addEdge(1,2);
G.addEdge(2,3);
G.addEdge(3,4);
G.addEdge(4,0);

G.Contain_Cycle(0);

return 0;
}
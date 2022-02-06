//Forest of DFS
//Connnected component in undirected Graph
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
public:
map<T,list<T>>l;
void AddEdge(int x,int y)
{
    l[x].push_back(y);
    l[y].push_back(x);
}
void Bfs_helper(T src,map<T,bool>&visited)
{
    cout<<src<<" ,";
    visited[src]=true;
    for(auto i:l[src])
    {
        if(!visited[i])
         Bfs_helper(i,visited);
    }
}
void Bfs()
{
    map<T,bool>visited;
    //Mark all the Nodes As Not Visited in the Begining
    for(auto i:l)
    {
        T Node=i.first;
        visited[Node]=false;
    }
    //Iterate Over all the Vertices and init a dfs call
    
    int count=0;  //for found the Number of Graph of DFS
    for(auto it:l)
    {
        T Node=it.first;
        
        if(!visited[Node])
        {
            cout<<"Component "<<count<<" ---> ";
        Bfs_helper(Node,visited);
        count++;
        cout<<endl;
        }

    }
    
}
};

int main(){
Graph<int>G;
G.AddEdge(0,1);
G.AddEdge(1,2);
G.AddEdge(2,3);
G.AddEdge(0,3);
G.AddEdge(0,4);
G.AddEdge(5,6);
G.AddEdge(6,7);
G.AddEdge(8,8);
G.Bfs();
return 0;
}
/*
Topological Sorting

Topological sorting for Directed Acyclic Graph (DAG) 
is a linear ordering of vertices such that for every
directed edge u v, vertex u comes before v in the 
ordering. Topological Sorting for a graph is not 
possible if the graph is not a DAG.

For example, a topological sorting of the following 
graph is “5 4 2 3 1 0”. There can be more than one 
topological sorting for a graph. For example, 
another topological sorting of the following graph 
is “4 5 2 3 1 0”. The first vertex in topological 
sorting is always a vertex with in-degree as 0 
(a vertex with no incoming edges).

*/

/*

        (1)          Linear Sorting will be
        /  \          1 2 3 4
       /    \         1 3 2 4
     (2)    (3)
      \      /
       \    / 
        (4)
*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>

class Graph{
public:
map<T,list<T>>l;
void AddEdge(string x,string y)
{
    l[x].push_back(y);  //unidirectional insert
}
//useful for topological sorting
void Dfs_Helper(T src,map<T,bool>&visited,list<T>&ordering)
{
 //mark the current Node as Visited
    visited[src]=true;
//Recur for all the Vertices
//Adjacent to This Vertex
    for(auto i:l[src])
    {
        if(!visited[i])
       Dfs_Helper(i,visited,ordering);
    }
    //push the current vertex to List
    //which Stores result
    ordering.push_front(src);
}
void Bfs()
{
    map<T,bool>visited;
    list<T>ordering;  
    //Mark all the Vertices as Not Visited
    for(auto i:l)
    {
        T Node=i.first;
        visited[Node]=false;
    }
    
    // Call the recursive helper function
    // to store Topological
    // Sort starting from all
    // vertices one by one
    for(auto i:l)
    {
        T Node=i.first;
        if(!visited[Node])
        {
            Dfs_Helper(Node,visited,ordering);
        }
    }
    //Print Contents of List
    for(auto Node:ordering)
    {
        cout<<Node<<" ---> ";
    }
}

};
int main(){
     Graph<string> g;
    g.AddEdge("Python","Data Processing");
    g.AddEdge("Python", "PyTorch");
    g.AddEdge("Python","ML");
    g.AddEdge("Data Processing","ML");
    g.AddEdge("PyTorch","DL");
    g.AddEdge("DL","FaceRecogn");
    g.AddEdge("DataSet","FaceRecogn");
 
    cout << "Following is a Topological Sort of the given "
            "graph \n";
 
    // Function Call
    g.Bfs();
 
    return 0;

return 0;
}
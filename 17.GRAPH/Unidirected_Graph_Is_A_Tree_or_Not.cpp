#include<bits/stdc++.h>
using namespace std;
//Check If a Unidirected Graph is A Tree Or Not
//If cycle is Present In Graph then it is Not Tree
/*
Check If we Are Visited a Node by More Than One Path

*/
template <typename T>
class Graph{
    public:
    map<T,list<T>>l;
    map<T,T>parent;
    void AddEdge(int x,int y)
    {
        //Unidirectional
        l[x].push_back(y);
        l[y].push_back(x);

    }
    bool isTree(T src)
    {
        map<int,bool>Visited;
        queue<T>Q;
        for(auto i:l)
        {
            T Node=i.first;
            Visited[Node]=false;
            parent[Node]=Node; //store the parent of list
        }
        Q.push(src);
        Visited[src]=true;
        //Pop out Each Node and
        while(!Q.empty())
        {
             T Node=Q.front();
             Q.pop();
             for(int nbr:l[Node])
             {
                 if(Visited[nbr]==true and parent[Node]!=nbr)
                 {
                     return false;
                 }
                 else if(!Visited[nbr])
                 {
                     Visited[nbr]=true;
                     parent[nbr]=Node;
                     Q.push(nbr);
                 }
             }
        }
        return true;

    }


};
int main(){
    Graph<int> G;
    G.AddEdge(0,1);
    G.AddEdge(0,3);
    
    if(G.isTree(0))
    {
        cout<<"This is Tree";

    }
    else{
        cout<<"This Is Graph ";
    }

return 0;
}
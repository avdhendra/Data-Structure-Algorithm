/*
we dont create adjacency list
edge list we implement
(1)---------(2)
             |
             |
             |
( 4 )----- ( 3 )

(1,2),(2,3),(3,4) edge list

*/

#include<bits/stdc++.h>
using namespace std;
//Cycle Detection in a Undirected Graph Using DSU
class Graph{
public:
int V;
list<pair<int,int>>l;
Graph(int V)
{
    this->V=V;
}
int addEdge(int u,int v)
{
    l.push_back(make_pair(u,v));
}
//Find
int FindSet(int i,int parent[])
{
    //Base Case
    if(parent[i]==-1)
    {
        return i;
    }
    return FindSet(parent[i],parent);
}
void Union_Set(int x,int y,int parent[])
{
    int s1=FindSet(x,parent);
    int s2=FindSet(y,parent);
    if(s1!=s2)
    {
        parent[s1]=s2;

    }
}
bool Contain_Cycle()
{
    //DSU Logic to Check if Graph Contain Cycle or Not
    int *parent=new int [V];
    for(int i=0;i<V;i++)
    {
        parent[i]=-1;
    }
    //Iterate Over The Edge List
    for(auto edge:l)
    {
        int i=edge.first;
        int j=edge.second;
        int s1=FindSet(i,parent);
        int s2=FindSet(j,parent);
        if(s1!=s2)
        {
            Union_Set(s1,s2,parent);
        }
        else{
            cout<<s1<<"is  Same  as "<<s2<<endl;
            
            return true;
        }
    }
    delete [] parent; //because it take dynamically
    return false;

}
};
int main(){
    Graph G(4);
    G.addEdge(0,1);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(3,0);
    cout<<G.Contain_Cycle()<<endl;

return 0;
}
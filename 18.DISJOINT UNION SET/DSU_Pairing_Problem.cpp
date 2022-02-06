/*
There are N Cities number from 0 to N-1 you habe to Choose
two cities such that there is No path from City
to Second City You are Given Information in the Form
of M pair(X,Y) i.e there is an Undirected Road Between City X
and City Y

Find out the Number of ways in which cities can be Choosen

For Ex:=

           ( A )                (D)
           /   \                /
          /     \              /
       ( B )----( C )       ( E )


Total ways Such city X is not Connect city Y by any Path

So mean both have Different Set

like city A and City D and City A and City E like More....

so the Total Number of Ways is 3^C2=6

but wat if there is more diconnected graph

Total Number of Ways =
Total number of Node in all Graphs^C 2 -sum for all K graph(size of Graph^C2)

*/
#include<bits/stdc++.h>
using namespace std;
class Graph{
public:
int V;
list<pair<int,int>>D;
Graph(int V)
{
    this->V=V;
}
void AddEdge(int x,int y)
{
    D.push_back(make_pair(x,y));

}
int Find_Set(int i,int parent[])
{
    if(parent[i]==-1)
    {
        return i;
    }
    return parent[i]=Find_Set(parent[i],parent);
}
void Union_Set(int x,int y,int parent[],int rank[])
{
    int S1=Find_Set(x,parent);
    int S2=Find_Set(y,parent);
    if(S1!=S2)
    {
        if(rank[S1]<rank[S2])
        {
            parent[S1]=S2;
            rank[S2]+=rank[S1];

        }
        else{
            parent[S2]=S1;
            rank[S1]+=rank[S2];
        }
    }

}
int  pairing()
{
    int*parent=new int[V];
    int *rank=new int [V];
    for(int i=0;i<V;i++)
    {
        parent[i]=-1;
        rank[i]=1;
    }
    for(auto edge:D)
    {
        int i=edge.first;
        int j=edge.second;
        int S1=Find_Set(i,parent);
        int S2=Find_Set(j,parent);
        if(S1!=S2)
        {
            Union_Set(S1,S2,parent,rank);

        }
    }
        //Code Logic For Upper Problem
        int ans=0;
        for(int i=0;i<V;i++)
        {
             ans+=V-rank[Find_Set(i,parent)];     //N^C2=N
        }
    
    
    delete[] parent;
    delete[] rank;
    return ans/2;


}
};
int main(){
    int n,m;
    cin>>n>>m;
Graph G(n);
while(m--)
{
    int x,y;
    cin>>x>>y;
    G.AddEdge(x,y);
}
cout<<G.pairing();
return 0;
}
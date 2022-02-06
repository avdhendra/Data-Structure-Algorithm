//Union By Rank()
/*     Rank = No of Nodes
          (4 Nodes)       ( 2 Nodes)
             ( 1 )-------->\
             /             ( 5 ) 
          ( 2 )              \
           /                 ( 6 )
        ( 3 )
         /
      ( 4 )

Attach the Smaller Tree With Bigger One

on First Optimisation in DSU
Path Compression Optimisation time Complexity is 0(Log n) in worst
but by second Optimisation Union by Rank time complexity further reduce to
0(1)








*/ #include<bits/stdc++.h>
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
            if(rank[S1]<rank[S2])  //if Number of Node of Set S1 is less than S2
           {
                parent[S1]=S2;         //Than S2 is Parent of S1
               rank[S2]+=rank[S1];  //we add number of Node of S1 to S2
          }
          else{
              parent[S2]=S1;
              rank[S1]+=rank[S2];  //We add Number of Node of S2 to S1 node
          }
    }

    }
    bool Contain_Cycle()
    {
        //DSU Logic to Check if Graph Contain Cycle or Not
        int *parent=new int[V];
        //Rank optimisation
        int*rank=new int[V];
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
            else{
                return true;
            }
        }
        return false;
    }
};
int main(){
Graph G(4);
G.AddEdge(0,1);
G.AddEdge(1,2);
G.AddEdge(2,3);
G.AddEdge(3,0);

cout<<G.Contain_Cycle()<<endl;
return 0;
}
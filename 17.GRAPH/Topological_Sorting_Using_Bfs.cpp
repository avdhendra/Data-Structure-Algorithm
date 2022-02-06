#include<bits/stdc++.h>
using namespace std;

/*
push the element in queue whose indegree is 0 
Indegree is I(0)
   I(0)     I(0)
   ( 0 )   ( 1 )
     |      /|
     |     / |
     |    /  |
     V   /   V
   ( 2 )   ( 4 ) 
     | \     |
     |  \    |
     |   \   |
     V    \  V
   ( 3 )--->(5) 



*/
class Graph{
    public:
   list<int>*l;
   int v;
   Graph(int v)
   {
       this->v=v;
       l=new list<int>[v];
   }
    void AddEdge(int x,int y)
    {  //Directed Graph
        l[x].push_back(y);
    }
    void Topological_Sort()
    {
        //Indegree
        int *Indegree=new int[v];
        //0 Indegree
        for(int i=0;i<v;i++)
        {
            Indegree[i]=0;
        }
        //Update indegree by Traversing edges x->y
        //indegree[y] +=
        for(int i=0;i<v;i++)
        {
            
            for(auto y:l[i])
            {
                Indegree[y]++;
            }
        }
        //bfs
        queue<int>Q;
        //1. Step find Nodes with 0 Indegree
        for(int i=0;i<v;i++)
        {
            if(Indegree[i]==0)
            {
                Q.push(i);
            }
        }
        //Start Removing Element from The Queue
        while(!Q.empty())
        {
            int Node=Q.front();
            cout<<Node<<" ";
            Q.pop();
            //Iterate Over Nbr of that Node and Reduce their Indegree
            for(auto nbr:l[Node])
            {
                Indegree[nbr]--;
                if(Indegree[nbr]==0)
                Q.push(nbr);
            }
        }
        
        
    }
    
};
int main(){
Graph G(6);
G.AddEdge(0,2);
G.AddEdge(1,2);
G.AddEdge(1,4);
G.AddEdge(4,5);
G.AddEdge(2,3);
G.AddEdge(2,5);
G.AddEdge(3,5);
G.Topological_Sort();

return 0;
}
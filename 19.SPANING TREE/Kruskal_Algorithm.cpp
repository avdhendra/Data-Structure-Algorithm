/*
Kruskal Algorithm (Greedy Algorithm )

 Graph:-          ( 1 )
                        /|\
                  (1)  / | \  (2)
                      / (2) \
                   ( 2 )---( 3 )
                     \   |   /
                ( 3 ) \(2)|  / ( 3 )
                       \ | /
                       ( 4 )
                    (6)/
                      /
                   ( 5 ) 


MST

(1) (2) (3) (4) since each Node represent single set

 Step 1: Sort All Edges Based Upon Weight                      

edge     weight
 1--2        1    since 1 and 2 are different disjoint set we make union
 1--3        2     since 1 and 3 are different disjoint set we make union              
 1--4        2     since 1 and 4 are different disjoint set we make union of both                   
 
 2--3        2 X but in here 2 and 3 belong to same set which leader is 1 so if we union them it make a cycle
                 which we dont want in mst so we Discard it 
 3--4        3 X
 2--4        3 X
 4--5        6 but this not make any cycle


                        ( 1 )
                (1)    /  |  \  (2)
                      /   |   \
                   ( 2 )  |(2)( 3 )
                        ( 4 )
                        /
                       /(6)
                    ( 5 )


*/
#include<bits/stdc++.h>
using namespace std;
//DSU Data Structure
//Path Compression+Union by Rank
class DSU{
    public:
    int*parent;
    int *rank;
    int D;
    DSU(int D)
    {
        this->D=D;
    parent=new int[D];
    rank=new int[D];
    
    for(int i=0;i<D;i++)
    {
        parent[i]=-1;
        rank[i]=1;
    }
    }

    int Find(int i)
    {
        if(parent[i]==-1)
        {
            return i;
        }
        return parent[i]=Find(parent[i]);
    }
    void Union_Set(int x,int y)
    {
        int S1=Find(x);
        int S2=Find(y);
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
    
};
class Spanning{                 //    N1,N2,weight  
    vector<vector<int>>Edgelist;   // { { 1 , 2 , 3,...},..}
   //
   int V;
   public:
   Spanning(int V)
   {
       this->V=V;
   }
   void addEdge(int x,int y,int w)
   {
       Edgelist.push_back({w,x,y});  //we put w first because we want to sort the vector according to weight
   }
   int Krushal_Mst()
   {
       //1. Sort all The Edge based upon weight
       sort(Edgelist.begin(),Edgelist.end());
       DSU D(V);
       int ans=0;
       for(auto edge:Edgelist)
       {
           int w=edge[0];
           int x=edge[1];
           int y=edge[2];
           if(D.Find(x)!=D.Find(y))
           {
               D.Union_Set(x,y);
               ans+=w;
           }
           
       }
       return ans;

   }


};
int main(){
    Spanning S(4);
    S.addEdge(0,1,1);
    S.addEdge(1,3,3);
    S.addEdge(3,2,4);
    S.addEdge(2,0,2);
    S.addEdge(0,3,2);
    S.addEdge(1,2,2);
    cout<<S.Krushal_Mst()<<endl;


return 0;
}
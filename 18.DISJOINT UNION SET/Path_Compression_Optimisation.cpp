/*
this Optimisation is reduce the Time Complexity  


             ( 1 )
               |
               |
             ( 2 )
             /   \
            /     \
           /     ( 4 )
        ( 3 )
        /  \
       /    \
    ( 5 )  ( 6 )
     /       |
 ( 7  )    ( 8 )

 find( 7 ) optimisition is that we connect all element
 direct to the parent node
   
                     ( 1 )-----(7)
                     / |  \
                    /  |   (5)
                  (3) ( 2 )
                  /    |
                (6)    |
                /    ( 4 )
              (8)

again find(8) we do optimaization again
     
                 (8)
                   \
           (6)----- ( 1 )----(7)
                   / | \
               ( 3 ) (2)(5)
                      |
                      |
                    ( 4 )

*/
#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<pair<int,int>>l;
  Graph(int V)
  {
      this->V=V;
  }
    void addEdge(int x,int y)
    {
        l.push_back(make_pair(x,y));
    }
int Find_Set(int i,int parent[])
{
    if(parent[i]==-1)
    {
        return i;
    }

    //path Compression Optimisation
   return parent[i]=Find_Set(parent[i],parent);

}
void Union_Set(int x,int y,int parent[])
{int S1=Find_Set(x,parent);
int S2=Find_Set(y,parent);
if(S1!=S2)
{

parent[S1]=S2;
}
else{
    return Union_Set(S1,S2,parent);
}

}
bool Contain_Cycle()
{
    int *parent=new int[V];
    for(int i=0;i<V;i++)
    {
        parent[i]=-1;
    }
    for(auto edge:l)
    {
        int i=edge.first;
        int j=edge.second;
        int S1=Find_Set(i,parent);
        int S2=Find_Set(j,parent);
        if(S1!=S2)
        {
            Union_Set(S1,S2,parent);
        }
        else{
            return true;
        }
    }
    return false;
}
};
int main(){

return 0;
}
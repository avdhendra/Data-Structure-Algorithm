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
  
  void bfs(T src){
      map<T,int>Distance;
      queue<T>Q;
     map<T,T>parent;
      
      //All other Node will Have int_max
      for(auto Node_pair:l)
      {
          T Node=Node_pair.first;
          Distance[Node]=INT_MAX;
      }
      Q.push(src);
      Distance[src]=0;
      parent[src]=src;
      while(!Q.empty())
      {
          T Node=Q.front();
          Q.pop();
          for(int nbr:l[Node])
          {
            if(Distance[nbr]==INT_MAX)//that means that node visited first time

          {
              Q.push(nbr);                 
              //change that neighbour  Distance as Dist[node]+1  distance of parent +1
              Distance[nbr]=Distance[Node]+1;
              parent[nbr]=Node;
          }
          }
          
      }
      //Print the Dist to Every Node
      for(auto Node_pair:l)
      {
          T Node=Node_pair.first;
          int d=Distance[Node];
          cout<<"Node "<<Node<<" Dist From Src "<<d<<endl;
      }
  }

};
int main(){
    Graph<int> G;
G.addEdge(0,1);
G.addEdge(0,3);
G.addEdge(1,2);
G.addEdge(2,3);
G.addEdge(3,4);
G.addEdge(4,5);
G.bfs(0);
return 0;
}
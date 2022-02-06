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
  void single(T src)
  {
      map<T,int>dist;
      queue<T>Q;
      for(auto i:l)
      {
          T Node=i.first;
         dist[Node]=INT_MAX;
      }
      Q.push(src);
      dist[src]=0;
      while(!Q.empty())
      {
          T Node=Q.front();
          Q.pop();
          for(int nbr:l[Node])
          {
          if(dist[nbr]==INT_MAX)
          {
              Q.push(nbr);
              dist[nbr]=dist[Node]+1;
          }
          }
      }
      for(auto i:l)
      {
          T Node=i.first;
          int d=dist[Node];
          cout<<"Node"<<Node<<" Dist From Src "<<d<<endl;
      }
  }
};
int main(){
Graph<int> G;
G.AddEdge(0,1);
G.AddEdge(0,3);
G.AddEdge(1,2);
G.AddEdge(2,3);
G.AddEdge(3,4);
G.AddEdge(4,5);
G.single(0);
return 0;
}
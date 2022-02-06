/*
BFS give Level order traversal


*/


#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    public:
    map<T,list<T>>l;
    void addEdge(int x,int y)
    {
     l[x].push_back(y);
     l[y].push_back(x);
    }
    void bfs(T src)
    {
        map<T,bool>visited;
        queue<T>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            cout<<node<<" , ";
            for(auto i:l[node])
            {
                if(visited[i]!=true)
                {
                    q.push(i);
                    visited[i]=true;
                }
                
            }
        }
    }
};
int main(){
Graph <int> G;
G.addEdge(0,1);
G.addEdge(1,3);
G.addEdge(2,1);
G.addEdge(2,3);
G.addEdge(2,4);
G.bfs(0);
return 0;
}
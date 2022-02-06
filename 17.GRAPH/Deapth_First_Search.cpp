 #include<bits/stdc++.h>
 using namespace std;
 template<typename T>
 class Graph{
    map<T,list<T>>l;
    public:
    void addEdge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void Dfs_helper(T src,map<T,bool>&visited)
    { //Recursive function that will traverse the Graph
        cout<<src<<" ,";
        visited[src]=true;
        //Go to all nbr of that Node that is Not visited

        for(auto i:l[src])
        {
            if(!visited[i])
            {
               Dfs_helper(i,visited);
            }
        }


    }  
    
    void dfs(T src)
    {
        map<T,bool>visited;
        //Mark all the Nodes as Not Visited in The Begining
        for(auto i:l)
        {
            T Node=i.first;
            
            {
                visited[Node]=false;
            }
        }

        
        Dfs_helper(src,visited);

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

G.dfs(0);
 return 0;
 }
#include<iostream>
#include<list>
using namespace std;
/*
* Adjacency list representation
*l
^
|
|
|           list
|0| -->1,2   (L1)     0 is connect with two nodes(1,2)
|1| -->2,0   (L2)
|2| -->3,0,1 (L3)
|3| -->2     (L4)

we create Array of list of Size V
*/
class Graph{
    public:
    int V; 
    list<int>*l; //l is pointer to the array of list
    Graph(int V)
    {
        this->V=V;
        l=new list<int>[V];
    }
    //Edge are bidirectional
    void addEdge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void PrintAdjustList();
};
void Graph:: PrintAdjustList(){
    //Iterator Over All the Vertices
    for(int i=0;i<V;i++)
    {cout<<"| "<<i<<" | ";
       for(auto nbr:l[i])
       {
           cout<<nbr<<" , ";
       }
       cout<<endl;
    }
}
int main()
{
Graph G(10);
G.addEdge(0,1);
G.addEdge(1,3);
G.addEdge(2,1);
G.addEdge(2,3);
G.addEdge(2,4);
G.PrintAdjustList();



}
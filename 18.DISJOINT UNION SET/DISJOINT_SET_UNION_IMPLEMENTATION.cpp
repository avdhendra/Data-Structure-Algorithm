/*

( 1 )    ( 2 )   ( 3 )    ( 4 )


where -1 represent independent set
array we Represent parent | -1 | -1 | -1 | -1 |
                             1    2    3    4

Union-( 1,2 )      Union(3,4)
   
   (1)                (3)
   /                    \
  (2)                   (4)
|_______|           |________|
  root Leader       root Leader
    =1                 =3
reprentation in array
| -1 | 1 | -1 | 3 |
  1    2   3     4

Union(1,4)
find Set In Which 1 is Present

S1=1=find(1)(return Root Leader)
S2=3=find(4)(return Root Leader)

if(S1!=S2)  //if both element is Not Present in a Set then We change it
{
  parent[S2]=S1;
}
      ( 1 )
      /   \ 
     /     \
  ( 2 )   ( 3 )
             \
            ( 4 )

            how to Detect the Cycle

    S1=find(2)=[1
    S2=Find(3)= 1] both have Same set then Cycle is present


*/
#include<bits/stdc++.h>
using namespace std;
class DisJoinSet{
    public:
    int*rank,*parent,n;
    //Constructor To Create and 
    //Initialize Set of N items
    DisJoinSet(int n)
    {
        rank=new int[n];
        parent=new int[n];
        this->n=n;
        makeSet();
    }
    //create n Single Set
    void makeSet()
    {
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            
        }

    }
    //Find Set of Given item x
    int find(int x)
    {
        //Find The Representation of the Set
        //That x is an element of
        if(parent[x]!=x)
        {
            //if x is not the Parent of Itself 
            //Then x is Not the representative of 
            //His Set
            parent[x]=find(parent[x]);
            //so we Recursively call find on its parents
            //and Move i's Node directly Under the 
            //representative of this Set

        }
        return parent[x];
    }
    void Union(int x,int y)
    {
        //Find current Sets of X and Y
        int xset=find(x);
        int yset=find(y);
        //If they are Already in Same Set
        if(xset==yset)
        return;
        //Put Smaller Ranked Item Under
        //Bigger Ranked Item if Rank are
        //Different 
        if(rank[xset]<rank[yset])
        {
            parent[xset]=yset;
        }
        else if(rank[xset]>rank[yset])
        {
            parent[yset]=xset;
        }
        //If ranks are Same then Increment
        //Rank
        else{
            parent[yset]=xset;
            rank[xset]=rank[xset]+1;
        }
    }
};
int main(){
DisJoinSet obj(5);
obj.Union(0,2);
obj.Union(4,2);
obj.Union(3,1);
if(obj.find(4)==obj.find(0))
{
    cout<<"Yes\n";

}
else
cout<<"NO\n";

return 0;
}
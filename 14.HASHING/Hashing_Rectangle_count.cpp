#include<bits/stdc++.h>
using namespace std;
class Point{
    public:
    int x,y;
  
    Point(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
};
class Compare{
    public:
    bool operator()(Point p1,Point p2)
    {
       if(p1.x==p2.x)
       {
           return p1.y<p2.y;
       }
       return p1.x<p2.x;
    }
};
int count_rects(vector<Point>coords)
{
int n=coords.size(); //number of points

//Insert all the point in set
set<Point,Compare>s(coords.begin(),coords.end());
/*for(auto p: coords)
{
    s.insert(p);
}*/
//Run 2 Loops 
//it make sense if container is linear but its not so we
//it is binary we have to use next and prev in it
int ans=0;
for(auto it=s.begin();it!=prev(s.end());it++)
{
    for(auto it2=next(it);it2!=s.end();it2++)
    {
        Point p1=*it;
        Point p2=*it2;
        if(p2.x==p1.x || p2.y==p1.y)
        {
           continue;
        }
        Point p3(p2.x,p1.y);
        Point p4(p1.x,p2.y);
        if(s.find(p3)!=s.end() and s.find(p4)!=s.end())
        {
            ans++;
        }
    }
}

return ans/2;  //remove the symmetric case
}

int main(){
int n_Point;
cout<<"enter number of Points : "<<endl;
cin>>n_Point;
vector<Point>coords;
while(n_Point--)
{
    int x,y;
    cin>>x>>y;
    Point p(x,y);
   coords.push_back(p);
}
cout<<"Number of Rectangle Formed : "<<count_rects(coords)<<endl;
return 0;
}
//A C++ program to find convex hull of a set of Point 
#include<bits/stdc++.h>
using namespace std;
struct Point{
    int x,y;

};
bool ToChange(Point p,Point q,Point r)
{
    //PQ vector
    int x1=q.x-p.x;
    int y1=q.y-p.y;
 
 //QR Vector
 int x2=r.x-q.x;
 int y2=r.y-q.y;

 int value=x1*y2-y1*x2;
 return value>0;
}
void convexHull(Point p[],int n)
{
    //There must be at least 3 point 
if(n<3)
return ;
//Initialize Result
vector<Point>hull;

//Find the left most Point in x Point
int left=0;
for(int i=1;i<n;i++)
{
    if(p[i].x<p[left].x)
    {
        left=i;
    }
}
//Start from Left most Point ,Keep moving counterClockwise
//Until reach the start Point again .this Loop run o(h)
//Time where h is number of Point in result orOutPut
int first_Point=left,q;
do{
    //add current Point to result
    hull.push_back(p[first_Point]);
    //Search for a Point 'q' such that crossproduct is counterclock wise=+ve for all Point x 
    //the idea is to keep track of last visited most counterclock 
    //wise Point in q then update
    q=(first_Point+1)%n;  //so that q is stay in number of pOint
    for(int i=0;i<n;i++)
    {
        //if i means r is more counterclockwise than current q then update q
        if(ToChange(p[first_Point],p[q],p[i]))
        {
            q=i;  //means q become i=r
        }
    }
    first_Point=q;
}
while(first_Point!=left); //again


for(int i=0;i<hull.size();i++)
{
    cout<<"("<<hull[i].x<<","<<hull[i].y<<")"<<endl;
}

}



int main(){
Point point []={{0,4},{1,1},{2,2},{4,0},{4,4},{0,0},{3,3}};
convexHull(point,sizeof(point)/sizeof(point[0])); 
return 0;
}
#include<bits/stdc++.h>
using namespace std;
struct Point
{
    int x,y;
};
/***
 * Given three colinear Points p,q,r the function checks if
 * Point q lies on Line segment 'pr'
*/
bool onSegment(Point p,Point q,Point r)
{
    if(q.x<=max(p.x,r.x) && q.x>=min(p.x,r.x) && q.y<=max(p.y,r.y) && q.y>=min(p.y,r.y))
    {
        return true;
    }

    return false;
}
/***
 * To find orientation of ordered triplet(p,q,r)
 * the function return following values
 * 0-->p,q,r are collinear
 * 1-->Clockwise
 * 2-->CounterClockwise
*/
int orientation(Point p,Point q,Point r)
{
    int val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if(val==0)
    return 0; //collinear
    return (val>0)?1:2; //Clock or CounterClockWise
}

//The main function that returns true if line segment 'p1q1'
//and 'p2q2'
bool doIntersect(Point p1,Point q1,Point p2,Point q2){
    //Find the four orientation needed for general and 
int o1=orientation(p1,q1,p2);
int o2=orientation(p1,q1,q2);
int o3=orientation(p2,q2,p1);
int o4=orientation(p2,q2,q1);

//General Case
if(o1!=o2 &&o3!=o4)
return true;
//Special Cases
//p1,q1,and p2 are collinear and p2 lies on segment p1q1
if(o1==0 && onSegment(p1,p2,q1))
{
    return true;
}
//p1 ,q1 and q2 are collinear and q2 lies on segment p1q1
if(o2==0 &&onSegment(p1,q2,q1))
{
    return true;
}
//p2,p2,and p1 are collinear and p1 lies on segment p2q2
if(o3==0 && onSegment(p2,p1,q2))
{
    return true;
}
//p2,q2,and q1 are collinear and q1 lies on segment p2q2
if(o4==0 && onSegment(p2,q1,q2))
{
    return true;
}

    return false; //Doesnt fall in any of the above cases

}
int main(){
struct Point p1={1,1},q1={10,1};
struct Point p2 {1,2},q2={10,2};


doIntersect(p1,q1,p2,q2)?cout<<"YES\n":cout<<"No\n";

return 0;
}
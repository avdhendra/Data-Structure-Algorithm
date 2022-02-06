/*
Orientation of an ordered triplet of points in the plane can be

counterclockwise
clockwise
collinear


If orientation of (p1, p2, p3) is collinear, then orientation of (p3, p2, p1) is also collinear

If orientation of (p1, p2, p3) is clockwise, then orientation of (p3, p2, p1) is counterclockwise and vice versa is also true.
*/
/*
Slope of line segment (p1, p2): σ = (y2 - y1)/(x2 - x1)

Slope of line segment (p2, p3): τ = (y3 - y2)/(x3 - x2)

If  σ > τ, the orientation is clockwise (right turn)


Using above values of σ and τ, we can conclude that, 
the orientation depends on sign of  below expression: 

(y2 - y1)*(x3 - x2) - (y3 - y2)*(x2 - x1)

Above expression is negative when σ < τ, i.e.,  counterclockwise

**/

#include<bits/stdc++.h>
using namespace std;
struct Point{
    int x,y;
};
/***
 * To find orientation of ordered triplet (p1,p2,p3).
 * the function return following  values
 * 0---> p,q,r are collinear
 * 1->> Clockwise
 * 2-->CounterClockwise
*/
int orientation(Point p1,Point p2,Point p3)
{
    /*Formula*/
    int val=(p2.y-p1.y)*(p3.x-p2.x)-
             (p2.x-p1.x)*(p3.y-p2.y);
if(val==0)
return 0; //collinear
return(val>0)?1:2; //clock or counterclock wise

}
int main(){
Point p1={0,0},p2={4,4},p3={1,2};
int o=orientation(p1,p2,p3);
if(o==0)
{
    cout<<"Linear";
}
else if(o==1)
{
    cout<<"Clockwise";
}
else{
    cout<<"CounterClockwise";
}
return 0;
}
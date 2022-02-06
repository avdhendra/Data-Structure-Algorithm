#include<bits/stdc++.h>
using namespace std;
class Point{
    public:
    double x,y;
};
class polygon{
public:
Point* point;
polygon(int numPoints)
{
point=new Point[numPoints];
}
};
double area(polygon p,int n)
{
    double final_Area=0;
    for(int i=1;i<n-1;i++)
    {
        double x1=p.point[i].x-p.point[0].x;
        double y1=p.point[i].y-p.point[0].y;

        double x2=p.point[i+1].x-p.point[0].x;
        double y2=p.point[i+1].y-p.point[0].y;

        double cross_p=x1*y2-y1*x2;

        final_Area+=cross_p;
    }
    return abs(final_Area/2);
}
int main(){
    cout<<"Enter the number of points for polygon"<<endl;
    int n;
    cin>>n;
    polygon p(n);
    cout<<"Enter the coordinates of Polygon : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>p.point[i].x;
        cin>>p.point[i].y;
    }
    cout<<"Area of given Polygon is : "<<area(p,n)<<endl;

return 0;
}
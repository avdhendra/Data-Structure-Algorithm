#include<bits/stdc++.h>
using namespace std;

class Point{
    public:
    double x;
    double y;
};

class mindist{
    public:
    Point*point;
    mindist(int n)
    {
        point=new Point[n];
    }
    
};
double MinDistance(mindist D)
{
    //Vector AB
    pair<double,double>AB;
    AB.first=D.point[1].x-D.point[0].x;
    AB.second=D.point[1].y-D.point[0].y;

//Vector BE
pair <double ,double>BE;
BE.first=D.point[2].x-D.point[1].x;
BE.second=D.point[2].y-D.point[1].y;

//Vector AE
pair<double,double>AE;
AE.first=D.point[2].x-D.point[0].x;
AE.second=D.point[2].y-D.point[0].y;

//Variable to store dot product
double AB_BE,AB_AE;

//Calculating the DOt Product

AB_BE=(AB.first*BE.first+AB.second*BE.second);
AB_AE=(AB.first*AE.first+AB.second*AE.second);

//Minimum distance from 
//Point E to The line segment

double reqAns=0;
//case when point is near the B
if(AB_BE>0)
{
    double x=D.point[2].x-D.point[1].x;
    double y=D.point[2].y-D.point[1].y;
    reqAns=sqrt(x*x+y*y);
}
// case when point is near the A
else if(AB_AE<0)
{
    double x=D.point[2].x-D.point[0].x;
    double y=D.point[2].y-D.point[0].y;

    reqAns=sqrt(x*x+y*y);


}
//when the point is in the middle
else
{
    double x1=AB.first;
    double y1=AB.second;
    double x2=AE.first;
    double y2=AE.second;
    double mod=sqrt(x1*x1+y1*y2);
    reqAns=abs(x1*y2-y1*x2)/mod;       //cross product of |ABxAC|/|AB|
    /*
    ixi=jxj=kxk=0
    use determinant of AXB=|i j z|
                           |x y z|
                           |a b c|
    
    */
   return reqAns;

}
    
}
int main(){

mindist d(3);
cout<<"Enter the three point coordination : "<<endl;
for(int i=0;i<3;i++)
{
    cin>>d.point[i].x;
    cin>>d.point[i].y;
}
cout<<"Minimum distance of Point from Line  : "<<MinDistance(d)<<endl;

return 0;
}
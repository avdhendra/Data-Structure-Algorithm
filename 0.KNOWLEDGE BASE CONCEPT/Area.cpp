#include<iostream>
using namespace std;
class Area{
    public:
    double length;
    double breadth;
    public:
    Area()
    {
        length=0;
        breadth=0;
    }
    Area(double length,double breadth)
    {
        this->length=length;
        this->breadth=breadth;        
    }
    Area(int common)
    {
        length=common;
        breadth=common;
    }
friend double calculateArea();

~Area()
{
    
}
friend istream & operator >> (istream &in,  Area&A1)
{
    cout<<"enter length : ";
    in>>A1.length;
    cout<<"enter breadth : ";
    in>>A1.breadth;
    return in;
}


};
 double calculateArea(Area b1)
{
    int area=b1.length*b1.breadth;     //(length*Breadth)
    return area;



}



int main()
{
Area A1,A2,A3;
cin>>A1;
cout<<"Area of Rectangle : "<<calculateArea(A1)<<endl;
cin>>A2;

cout<<"Area of Rectangle : "<<calculateArea(A2)<<endl;
cin>>A3;
cout<<"Area of Rectangle  : "<<calculateArea(A3)<<endl;




}
#include<iostream>
using namespace std;
class Binary{
private:
int A;
int B;
public:
Binary()
{

}
Binary(int a,int b)
{
    A=a;
    B=b;
}
friend istream &operator >>(istream &cin,Binary&source);
friend ostream &operator <<(ostream &cout,Binary &source);

 Binary operator +(const Binary &source)
{
       Binary I;
    I.A=A+source.A;
    I.B=B+source.B;
    return I;
}

 Binary operator -(const Binary&source)
 {
Binary I2;
I2.A=A-source.A;
I2.B=B-source.B;
return I2;

 }
 Binary operator *(const Binary&source)
 {
     Binary I3;
     I3.A=A*source.A;
     I3.B=B*source.B;
     return I3;

 }
 Binary operator /(const Binary &source1)
 {
Binary I4;
I4.A=A/source1.A;
I4.B=B/source1.B;
return I4;
 }
};
istream &operator >>(istream &cin,Binary&source)
{
    cout<<"enter first number : ";
    cin>>source.A;
    cout<<"Enter second Number : ";
    cin>>source.B;
    return cin;
}
ostream &operator <<(ostream &cout,Binary&source)
{
cout<<"First number : "<<source.A<<" Second Number : " <<source.B;
}

 
int main()
{
    Binary A1,A2,A3;
    cout<<"enter number for A1 and A2 object : ";
    cin>>A1>>A2;
    A3=A1+A2;
    cout<<" Added Number are : "<<A3<<endl;
    A3=A1*A2;
    cout<<" Multiplied Number are : "<<A3<<endl;;

    A3=A1-A2;
    cout<<" Subtracted number are : "<<A3<<endl;
    A3=A1/A2;
    cout<<" Divided number are : "<<A3<<endl;;



}
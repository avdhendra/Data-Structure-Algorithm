#include<iostream>
#include<string>
using namespace std;
double func(double c)
{
            cout<<c<<"is largest"<<endl;
    
}
void func(char b,double c)
{//convert char to int
int i=b-48;
    if(static_cast<double>(i)>c)
    {
       cout<<i<<"is largest"<<endl;
       return;
    }
    func(c);
}

void func(int a,char b,double c)

{
    

if(a>c && a >static_cast<int>(b))
    cout<<a<<"is the largest number"<<endl;
   

else
{
    func(b,c);
}

}

int main()
{
    int a;
    char b;
    double c;
    cout<<"Enter three number : "<<endl;
   cin>>a>>b>>c;
  func(a,b,c);
}
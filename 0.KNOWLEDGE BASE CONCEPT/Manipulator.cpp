#include<iostream>
#include<cstring>
using namespace std;
istream &set(istream &is)
{
 cout<<"enter Your Name: ";
 return is;
}
ostream &off(ostream &os)
{
return os<<'\n';
}
int main ()
{
char A[25];
cin>>set>>A;
cout<<A<<off;
}

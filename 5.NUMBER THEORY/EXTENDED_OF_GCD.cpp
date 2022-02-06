/*
as we learn gcd(a,b)=gcd(b,a%b)
but also
according to him
ax+by=gcd(a,b);

bx1+(a%b)y1=gcd(b,a%b)=gcd(a,b)

but we know that
a%b=a-b*[a/b]
bx1+(a-b*[a/b])y1=gcd(a,b)
b(x1-[a/b]y1)+ay1=ax+by=gcd(a,b)
so 
compare 
x=y1
y=x1-[a/b]y1
so from this way we can find the x and y value



*/


#include<iostream>
using namespace std;
//we return three thing so we need to make class
class Triplet{
    public:
    int gcd;
    int x;
    int y;
};
Triplet gcdExtentedEuclid(int a,int b)
{
//Base case
if(b==0)
{
    Triplet myans;
    myans.gcd=a;
    myans.x=1;
    myans.y=0;
    return myans;
}
Triplet smallAns=gcdExtentedEuclid(b,a%b);
//Extended euclid says;
Triplet myans;
myans.gcd=smallAns.gcd;
myans.x=smallAns.y;
myans.y=(smallAns.x-((a/b)*(smallAns.y)));
return myans;

}

int main()
{
    int a,b;
    cin>>a>>b;
    Triplet ans=gcdExtentedEuclid(a,b);
    cout<<ans.gcd<<endl;
    cout<<ans.x<<endl;
    cout<<ans.y<<endl;

}
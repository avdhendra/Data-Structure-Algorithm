#include<iostream>
using namespace std;
class Triplet {
    public:
    int gcd;
    int x;
    int y;

};
Triplet extended_Euclid_Gcd(int a,int b)
{
    if(b==0)
    {
        Triplet myans;
        myans.gcd=a;
        myans.x=1;
        myans.y=0;
        return myans;
    }
    Triplet smallAns=extended_Euclid_Gcd(b,a%b);
    Triplet myans;
    myans.gcd=smallAns.gcd;
    myans.x= smallAns.y;
    myans.y=(smallAns.x-((a/b)*(smallAns.y)));
     return myans;
}

void multiplicative_mod_Inverse(int a,int mod)
{
    Triplet ans=extended_Euclid_Gcd(a,mod);
    cout<<"Multiplicative modulo inverse : "<<ans.x<<endl;
}

int main()
{
    int A;
    int mod;
    cin>>A>>mod;
    multiplicative_mod_Inverse(A,mod);

}
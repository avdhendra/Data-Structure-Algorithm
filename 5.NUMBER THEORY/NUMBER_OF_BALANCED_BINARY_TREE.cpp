/*
total possiblity :- X*X + 2 X * Y
h-1 and h-1 ke liye : X*X
h-1 and h-2 ke liye : X*Y
h-2 and h-1 ke liye : X*Y

*/



#include<bits/stdc++.h>
using namespace std;
int balanceBST(int h)
{
    if(h==0 || h==1)
    {
        return 1;
    }
    //we dont want that the exceed the value of int
    int m=pow(10,9)+7;

    int x=balanceBST(h-1);
    int y=balanceBST(h-2);
    
    long long res1 = (long long) x*x;   //int *int =int but if that value exceed 32 bit space we get wrong output
    //so we type cast it to long ,long*int=long
    long long res2 = (long long) x*y*2;
    
    int ans1=(int)(res1%m);
    int ans2=(int)(res2%m);
    int ans=(ans1+ans2)%m;
    return ans;

}
int main()
{
    int height;
    cout<<"Enter height : ";
    cin>>height;
    cout<<balanceBST(height)<<endl;
    return 0;


}
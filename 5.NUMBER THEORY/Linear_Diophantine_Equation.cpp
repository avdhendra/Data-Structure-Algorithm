/*
A Diophantine equation is a polynomial equation, usually in two or more unknowns, such that only the integral solutions are required. An Integral solution is a solution such that all the unknown variables take only integer values.
Given three integers a, b, c representing a linear equation of the form : ax + by = c. Determine if the equation has a solution such that x and y are both integral values.

Input : a = 3, b = 6, c = 9
Output: Possible
Explanation : The Equation turns out to be, 
3x + 6y = 9 one integral solution would be 
x = 1 , y = 1

//Find GCD of a and b
Check if c % GCD(a ,b) ==0
If yes then print Possible
Else print Not Possible


*/
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
return(a%b==0)?abs(b):gcd(b,a%b);
}
bool isPossible(int a,int b,int c)
{
    return (c%gcd(a,b)==0);
}
int main(){
int a=3,b=6,c=9;
isPossible(a,b,c)?cout<<"Possible\n":cout<<"Not possible"<<endl;
return 0;
}
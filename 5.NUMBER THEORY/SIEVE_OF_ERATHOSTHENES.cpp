/*
When the algorithm terminates, all the numbers
 in the list that are not marked are prime. 



Let us take an example when n = 50. So we need to print all prime numbers smaller than or equal to 50. 
We create a list of all numbers from 2 to 50. 


According to the algorithm we will mark all the numbers which are divisible by 2 and are greater than or equal to the square of it. 

*/
/*
 // by definition, 1 is not prime number
*/


/*
time complexity-0(n logn)
*/

#include<bits/stdc++.h>
using namespace std;
int  SieveOfErathosthenes(int n)
{
    //create a boolean array
    //prime[0...n] and intiallized
    //all entries are true
    //A value in prime[i] will
    //finally be false if i is 
    //not a prime else true.
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    for(int p=2;p*p<=n;p++)
    {
        //If prime[p] is not changed
        //then it is  a prime
        if(prime[p]==true)
        {
            /*
            update all multiples 
            of p greater than or
            equal to the square of it
            number which are muliptle 
            of p and are less than p^2
            are already been marked
            */
           for(int i=p*p;i<=n;i+=p)
           {
               prime[i]=false;
           }        }
    }
    //print all prime number
    //here we dont start by 0 because it is not prime

    for(int p=2;p<=n;p++)
    {
        if(prime[p])
        {
            cout<<p<<" ";
        }
    }
    cout<<endl;
    int count=0;
    //print number of prime
    for(int i=2;i<n;i++)

    {
        if(prime[i]==true)
        {
            count++;
        }
    }
    return count;


}

int main()
{
    int n;
    cin>>n;
    cout<<"following are the prime number smaller than or equal to "<<n<<endl;
cout<<"number of prime number : "<<SieveOfErathosthenes(n)<<endl;

}

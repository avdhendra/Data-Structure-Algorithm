/*
Count of Right-Angled Triangle formed from given N 
points whose base or perpendicular are parallel to 
X or Y axis

*/
/*

Approach:
The idea is to store the count of each
co-ordinate’s having the same X and Y co-ordinates 
respectively. Now traverse each given points and 
the count of a right-angled triangle formed by 
each coordinate (X, Y) is given by:


Count of right-angled triangles =
(frequencies of X coordinates – 1) * (frequencies of Y coordinates – 1)


*/
/*
Time Complexity: O(N)
Auxiliary Space: O(1)

*/
#include<bits/stdc++.h>
using namespace std;
//Function to Find the number of right
//angled triangle that are fromed from
//given N Points whose perpendicular or
//Base is Parrllel to X and Y
int RightAngled(int A[][2],int n)
{
    //To store the number of Points 
    //Has same X or Y coordinates
    unordered_map<int,int>xPoints; //one store coordinate and other store the count(frequency)
    unordered_map<int,int>yPoints;

    for(int i=0;i<n;i++)
    {
        xPoints[A[i][0]]++;
        yPoints[A[i][1]]++;
    }
    //Store the total count for triangle
    //Of possible triangle
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(xPoints[A[i][0]]>1 && yPoints[A[i][1]]>1)
        {
            //Add the count of triangles
            //formed
            count=(xPoints[A[i][0]]-1)*(yPoints[A[i][1]]-1);  //we subtract one because we dont take the pivot point


        }
    }
    return count;
}
int main(){
int N = 5;
 
    // Given N points
    int arr[][2] = { { 1, 2 }, { 2, 1 },
                     { 2, 2 }, { 2, 3 },
                     { 3, 2 } };
 
    // Function Call
    cout << RightAngled(arr, N);
return 0;
}
#include<bits/stdc++.h>
using namespace std;
//A pair of pair ,first element in going to 
//store value second element index of array
//and third element index in the array

/*

pair1- first-value
       second -pair2
       
       pair2- first- arr index
              second - element index


*/
typedef pair<int,pair<int,int>> node;
//This function takes an array of arrays as an
//argument and all arrray are assumed to be sorted
//it merges them together and prints the final sorted output


vector<int> mergeKSortArrays(vector<vector<int>>arr)
{
    vector<int> result;
    //Create a min heap with k heap nodes,Every
    //Heap node has first element of an array
    priority_queue<node,vector<node>,greater<node>>pq;

//Insert the 0th element of every array in 

    for(int i=0;i<arr.size();i++)
    {     
     /*    
        arr[i][0]-Insert the 0th element of every array in
        {i, 0} - and the array index, element index
     */


        pq.push({arr[i][0],{i,0}});
        //Now One by one get the minimum element
        //from min heap and replace it with next
        //element of its array
    }

/*  remove the element one by one from the min heap and add to result vector*/

        while(pq.empty()==false)
        {
            node curr=pq.top();  //from node we take value
            pq.pop();
          
          int element=curr.first; //value of that node
            //i ==> Array Number
            //j==> Index in the array Number

            int i=curr.second.first;
            int j=curr.second.second;
            
            //add the elemen value
            
            result.push_back(element);


            //The next element belong to same array as current

            if(j+1<arr[i].size()) //see the particular array arr[0],arr[1],arr[2]
            {
                pq.push({arr[i][j+1],{i,j+1}});
            }
           
        }
        return result;
    }
     

int main()
{
    //Change n at the top to change number
    //of element in an array

    vector<vector<int>> arr{{10,20,30,40},
    {15,25,35,45},
    {24,29,37,48},
    {32,33,39,50}};

    vector<int>output=mergeKSortArrays(arr);
    cout<<"  Merged array is : "<<endl;
    int k;
    cin>>k;
    cout<<"Kth smallest element in a row & col wise "<<output[k]<<endl;


}
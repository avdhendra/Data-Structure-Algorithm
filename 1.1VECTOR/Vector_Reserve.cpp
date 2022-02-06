/*
In C++ vectors are dynamic arrays. Unlike arrays, 
They don’t have a fixed size. They can grow or shrink
as required. Vectors are assigned memory in blocks 
of contiguous locations. When the memory allocated 
for the vector falls short of storing new elements, 
a new memory block is allocated to vector and all 
elements are copied from the old location to the new 
location. This reallocation of elements helps 
vectors to grow when required. However, it is a 
costly operation and time complexity is involved in 
this step is linear.

std::vector class provides a useful function reserve 
which helps user specify the minimum size of the 
vector.It indicates that the vector is created such 
that it can store at least the number of the 
specified elements without having to reallocate 
memory.


*/
#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;
int main()
{ 
    int n=1e6;
    vector<int> v1,v2;
    //here we reserve n space if the space exceed that space than 
    //new location is allocated to the vector

    v2.reserve(n);
    //start filling up element in v1
    //to measure execution time in c++ refer below
    auto start=high_resolution_clock::now();
    for(int i=0;i<n;i++)
    {
        v1.push_back(i);

    }
    auto stop=high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(stop-start);
    cout<<" Method I Took "<<duration.count()<<"Microsecond\n";
    //Start Filling up element in v2
    start=high_resolution_clock::now();
    for(int i=0;i<n;i++)
    {
        v2.push_back(i);
    }
    stop=high_resolution_clock::now();
    duration=duration_cast<microseconds>(stop-start);
    cout<<" Method II Took "<<duration.count()<<" MicroSecond \n";
    return 0;
    

}
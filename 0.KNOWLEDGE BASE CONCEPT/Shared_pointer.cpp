/*
Shared Pointer
*Provides shared ownerShip of heap objects
*Shared_ptr<T>
*points to an Object of type T on the Heap
*it is not unique -there can Many shared_ptr pointing to the same object on the heap
*Establishes shared Ownership relationship
*Can be Assigned and copied
*can be Moved
*Doesn't Support managing array by default
*When the use count is zero the managed object on the heap is destroyed
  
shared_ptr<int>p1{new int{100}};
cout<<*p1<<endl;
*p1=200;
cout<<*p1<<endl;
//automatically deleted


//use_count-The number of shared_ptr Object managing the heap object


shared_ptr<int>p1{new int{100}};
cout<<p1.use_count()<<endl; //1
shared_ptr<int>p2{p1};  //Shared ownership  
cout<<p1.use_count()<<endl; //2

p1.reset(); //decrement the use_count; p1 is nulled out
cout<<p1.use_count<<endl; //0
cout<<p2.use_count<<endl; //1

vector<shared_ptr<int>>vec;

shared_ptr<int>ptr{new int {100}};
vec.push_back(ptr); //ok -copy Is Allowed
cout<<ptr.use_count()<<endl; //2


shared_ptr<int>p1=make_shared<int>(100); //use_count:1
shared_ptr<int>p2{p1};  //use_count:2

shared_ptr<int>p3;  
p3=p1;               //Use_count:3

//Use make_shared-it more efficient
//All 3 Pointer point to the same Object on the heap
//When the use_count becomes 0 the heap object is deallocated



use_count is use for count how many object point to a same location of memory


*/
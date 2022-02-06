/*

Seperate Chaining 

Implement Using Linked List
Key K is Stored in List a A[h[k]]

**E.g TableSize=10
h[k]=k mod 10
Insert first 10 Special Square
insert Square of number
0,1,4,9,16,25,36,49,64,81
this table is of  pointer(Node) 

Node**
|    
-->  Node* Node
    0 -> |0|
    1 -> |1| ->|81|
    2
    3
    4 -> |4| ->|64|
    5 
    6
    7
    8
    9
as Long  the linked list the time should take according to the linked list 
length

if the entry is N=20000 so we have to take list limited

length Should be l<20 or very small so that complexity become constant almost
*/

/*
Node<T> contain

key-string
value-T (generic)
next - Node<T> *next



*/
#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Node{
public:
string key;
T value;
Node<T>*next;
Node(string key,T val)
{
    this->key=key;
    value=val;
    next=NULL;
}
//recursive destructor
/*
4 -> |1| -> |3| ->|5|
      |
      ---> delete and  node* point to next of deleted Node other wise it is 
      memory leak
      */
~Node()
{
    if(next!=NULL)
    {
        delete next;
    }
}
};

template<typename T>
class HashTable{
    Node<T>**Table;   //pointer to an array of pointer
    int current_Size;
    int table_Size;

    int hashFunction(string Key)
    {
        int idx=0;
        int pow=1;
        for(int j=0;j<Key.length();j++)
        {
            idx=idx+(Key[j]*pow)%table_Size;
            idx=idx%table_Size;
            pow=(pow*27)%table_Size;
        }
        return idx;

    }

public:
HashTable(int ts=7)
{
    table_Size=ts;
    Table=new Node<T>*[table_Size];  //we create memory for Node<t> pointer
    /*
    ex student *s=new student[10] this is pointer  pointing to the array of student of size 10
     student ** s= new student*[10] this is pointer pointing to the pointer of array of student of size 10 


     (the table contain pointer of student type)   
    */
   current_Size=0; // new hash table current size is 0

   for(int i=0;i<table_Size;i++)
   {
       // we should initialize table with null pointer
       Table[i]=NULL;
   }
}

void Insert(string key,T value)
{
    int idx=hashFunction(key);
    Node<T>*n= new Node<T>(key,value);
    //Insert at head of the linked List with id=idx
    n->next=Table[idx];
    Table[idx]=n;
    //increment the size
    current_Size++;
}

void print()
{
    for(int i=0;i<table_Size;i++)
    {
        cout<<" Bucket "<<i<<"->";
        Node<T>*Temp=Table[i];
        while(Temp!=NULL)
        {
            cout<<"-->"<<Temp->key<<"-->";
            Temp=Temp->next;
        }
        cout<<"NULL"<<endl;
    }

}



};


int main(){
HashTable<int> h;
h.Insert("banana",50);
h.Insert("Apple",100);
h.Insert("Mango",40);
h.Insert("musk",25);
h.Insert("coconut",20);
h.Insert("blackberry",50);
h.print();

return 0;
}
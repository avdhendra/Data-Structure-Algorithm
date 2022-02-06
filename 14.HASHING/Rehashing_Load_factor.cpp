/*
Rehashing ->
Increase the table size as number of element increase
when load factor cross the certain thresold


LoadFactor=Current_Size/TableSize

load-factor>0.75 (thresold)

if load factor cross the thresold increase the table size by double it

and again hash all the element in table
 
 and delete old table

 rehashing is expensive operation it 0(N) where n is number of element



*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Node{
    
    public:
    string key;
    T value;
    Node<T>*next;
    Node(string key,T value )
    {
        this->value=value;
        this->key=key;
        next=NULL;
    }

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
    Node<T>**Table;
    int  Table_size;
    int  currentSize;
    
    //Hash function return idx
    int HashFunction(string key)
    {
         int pow=1;
    
         int idx=0;
    
    for(int i=0;i<key.length();i++)
    {
         idx=idx+(key[i]*pow)%Table_size;
       
        idx=idx%Table_size;
       
        pow=(pow*27)%Table_size;
    }

    return idx;
    }

    void rehash(){
        //we create the pointer pointing to the old table before create one
        Node<T>**oldTable=Table; //we delete static pointer
       
        int oldTableSize=Table_size; //store old table size before change it to double
        
        Table_size=2*Table_size;  //new Table size is double of previous
        
        Table= new Node<T>*[Table_size]; //create new table of double size
        
        for(int i=0;i<Table_size;i++) //insert null in table array and iterator over new size of table
        {
            Table[i]=NULL;
        }
        
        currentSize=0;

        for(int i=0;i<oldTableSize;i++)    
        {
            Node<T>*temp=oldTable[i];
            while(temp!=NULL)
            {
                Insert(temp->key,temp->value);
                temp=temp->next;
            }
            //Now first we have to delete the linked list in all array index
        if(oldTable[i]!=NULL)
        {
            delete oldTable[i]; //destructor help to delete the linked list
            //it delete linked list
        }
        //delete old table 
        
        
        
        }

         delete[] oldTable;

    }
    public:
    
    HashTable(int ts=7)
{
        Table_size=ts;
     Table=new Node<T>*[Table_size];
   
   currentSize=0;

   for(int i=0;i<Table_size;i++)
   {
       Table[i]=NULL;
   }
   
}




    void Insert(string key ,T value)
    {
    
    int idx=HashFunction(key);
    Node<T>*n=new Node<T>(key,value);
    
    //Insert at head of the Linked list
    
    n->next=Table[idx];
    Table[idx]=n;
    
    //Increment the size
    
    currentSize++;


    //rehash function
  
  /*  float Load_factor=currentSize/(1.0*Table_size);

    if(Load_factor>0.7)
    {
        rehash();  //it should be private 
    }


    */
    }


T* search(string key)
{
    
    int idx =HashFunction(key);
    Node<T>*temp=Table[idx];
        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                return &temp->value;  //return the address of the value
            }
            temp=temp->next;
        }
        return NULL;
    
    
}
void Delete(string Key)
{
 if(search(Key)==NULL)return;
        int idx=HashFunction(Key);
        Node<T>*ptr=Table[idx];
        if(ptr->key==Key){
            Table[idx]=ptr->next;
            ptr->next=NULL;
            currentSize--;
            delete(ptr);
            return;
        }
        while(ptr->next!=NULL){
            if(ptr->next->key==Key&&currentSize>0){
                Node<T>*temp=ptr->next;
                ptr->next=temp->next;
                temp->next=NULL;
                currentSize--;
                delete(temp);
                return;
            }
            ptr=ptr->next;
        }
        return;



}

void Print()
{
    for(int i=0;i<Table_size;i++)
    {
    Node<T> *temp=Table[i];
    cout<<"Bucket "<<i<<"->";
    while(temp!=NULL)
    {
        cout<<temp->key<<"->";
        temp=temp->next;
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
h.Insert("Milk",53);
h.Insert("Mangn",85);
h.Insert("lolipop",20);
h.Print();
int *price=h.search("Apple");
if(price==NULL)
{
    cout<<"not found"<<endl;
}
else{
    cout<<"Price is : "<<*price<<endl;
}
cout<<endl;
h.Delete("Milk");
h.Print();
return 0;
}
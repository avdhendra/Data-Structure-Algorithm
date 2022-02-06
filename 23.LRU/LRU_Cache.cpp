#include<bits/stdc++.h>
using namespace std;
//Node to Store the Data (Linked List)
class Node{
    public:
string key;
int value;
Node(string key,int value)
{
    this->key=key;
    this->value=value;
}
};

class LRUCache{
    public:
    int maxSize;
    list<Node>l ;
    unordered_map<string,list<Node>::iterator>m;
    LRUCache(int maxSize)
    {
        this->maxSize=maxSize>1?maxSize:1;
    }
    void InsertKeyValue(string key,int value){
       //if the Key already exist in the cache,then simple the value of the 

       //key can be update with the new value
       if(m.count(key)!=0)
       {
           //replace the old value and Update 
           auto it=m[key]; //m[key] return address auto it is pointer
           //(*it).value=value;
              it->value=value;
       }
       else{
           //check if cache is full or not
           //remove the least recently used item from cache
          
           if(l.size()==maxSize)
           {
                cout<<"Overflow !!! "<<endl;
               Node last=l.back();
               m.erase(last.key); //remove from hashmap
               l.pop_back(); //remove from linked list
           }
           Node n(key,value);
           l.push_front(n);
           m[key]=l.begin(); //l.begin() is return address of first node in linked in hashmap

       }
    }
    int* getValue(string key) {
        //...
        if(m.count(key)!=0)
        {
            auto it=m[key];
            //int value=it->value;  //this value also come up to the top
             l.push_front(*it); //it place the value in top of linked list
             l.erase(it); //where the previous value present before taking it to top delete it 
             m[key]=l.begin();
             return &l.begin()->value;

        }
        return NULL;

    }
    string mostRecentKey()
    {
        return l.front().key;
        
    }
};
int main(){
LRUCache lru(3);
lru.InsertKeyValue("mango",18);
lru.InsertKeyValue("Apple",20);
lru.InsertKeyValue("Guava",30);
lru.InsertKeyValue("Kiwi",40);
cout<<"LRU Most Recent : "<<lru.mostRecentKey()<<endl;


if(lru.getValue("Mango")==NULL)
{
    cout<<"Apple doesnt exist"<<endl;
} 
int *order=lru.getValue("Guava");
if(order!=NULL)
{
    cout<<"Order of Guava "<<*order<<endl;
}

return 0;
}
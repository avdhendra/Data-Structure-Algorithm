#include <bits/stdc++.h>
using namespace std;
template<typename T>
class node{
    public:
    string key;
    T value;
    node<T>*next;

    node(string k,int val){
        this->key=k;
        this->value=val;
        this->next=NULL;
    }
    ///Destructor
    ~node(){
        if(next!=NULL)delete next;
    }
};

template<typename T>
class HashTable{
    node<T>**table;
    int curr_size;
    int table_size;
    int hashfn(string key){
        int l=key.length();
        int p=1;
        int ans=0;
        for(int i=0;i<l;i++){
            ans=ans+(key[l-i-1]*p)%table_size;
            ans%=table_size;
            p=(p*37)%table_size;            
        }
        return ans;
    }

    void rehash(){
        node<T>**oldtable=table;
        int oldtable_size=table_size;
        table_size*=2;
        table=new node<T>*[table_size];
        for(int i=0;i<table_size;i++){
            table[i]=NULL;
        }
        curr_size=0;
        for(int i=0;i<oldtable_size;i++){
            node<T>*temp= oldtable[i];
            while(temp!=NULL){
                insert(temp->key,temp->value);
                temp=temp->next;
            }
            if(oldtable[i]!=NULL)delete oldtable[i];
        }
        delete [] oldtable;
    }

    public:
    HashTable(int ts=7){
        this->table_size=ts;
        table=new node<T>*[table_size];
        curr_size=0;
    for(int i=0;i<table_size;i++){
        table[i]=NULL;
    }        
    }
    void insert(string key,T val){
        int idx=hashfn(key);
        node<T>*n=new node<T>(key,val);
        n->next=table[idx];
        table[idx]=n;
        curr_size++;
        ///rehashing 
        float load_factor=(curr_size)/(1.0*table_size);
        if(load_factor>0.7)rehash();
    }

    void print(){
        for(int i=0;i<table_size;i++){
            cout<<"Bucket "<<i<<"-> ";
            node<T>*temp = table[i];
            while(temp!=NULL){
                cout<<temp->key<<"->";
                temp=temp->next;
            }
            cout<<"\n";
        }
    }
    
    T* search(string key){
        int idx=hashfn(key);
        node<T>*temp=table[idx];
        while(temp!=NULL){
            if(temp->key==key)return &temp->value;
            temp=temp->next;
        }
        return NULL;
    }

    void erase(string key){
        if(search(key)==NULL)return;
        int idx=hashfn(key);
        node<T>*ptr=table[idx];
        if(ptr->key==key){
            table[idx]=ptr->next;
            ptr->next=NULL;
            curr_size--;
            delete(ptr);
            return;
        }
        while(ptr->next!=NULL){
            if(ptr->next->key==key&&curr_size>0){
                node<T>*temp=ptr->next;
                ptr->next=temp->next;
                temp->next=NULL;
                curr_size--;
                delete(temp);
                return;
            }
            ptr=ptr->next;
        }
        return;
    }

    T& operator[](string key){
        T * f=search(key);
        if(f==NULL){
            T garbage;
            insert(key,garbage);
            f=search(key);
        }
        return *f;
    }
};

int main(){

    HashTable<int>price_menu;
    price_menu.insert("Chowmein",125);
    price_menu.insert("Burger",155);
    price_menu.insert("Chocolate",200);
    price_menu.insert("Pizza",225);
    price_menu.insert("Bhujiya",500);
    price_menu.insert("kulfi",125);
   int *price= price_menu.search("Pizza");
   //cout<<*price<<endl;
   price_menu.insert("Noodles",50);
   //price_menu.print();
   price_menu.erase("Burger");
   price_menu.erase("kulfi");
   //Insert
   price_menu["Dosa"]=50;
   //Update
   price_menu["Dosa"]+=55;
   price_menu.print();
   //Search
   cout<<price_menu["Dosa"]<<endl;
    return 0;
}



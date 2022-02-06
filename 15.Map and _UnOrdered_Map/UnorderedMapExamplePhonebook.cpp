#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<string ,vector<int>>PhoneBook;
    PhoneBook["Rahul"].push_back(9504134);
    PhoneBook["Jackie"].push_back(54164);
    PhoneBook["Rahul"].push_back(1244745);
    PhoneBook["Jackie"].push_back(145124);

    for(auto it:PhoneBook)
    {
       cout<<"Name : "<<it.first<<"->";
       for(auto f:it.second)
       {
           cout<<f<<"->";
       }
       cout<<endl;
    }
    cout<<endl;
    string name;
    cin>>name;
    if(PhoneBook.count(name)==0)
    {
        cout<<"Absent";
    }
    else{
        for(auto s:PhoneBook[name])
        {
            cout<<s<<endl;
        }
    }
    
}
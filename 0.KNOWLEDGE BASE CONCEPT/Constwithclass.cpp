/*const method 
class Player{
    priavte:
    ...
    public:
    string get_name() const;
    //error /if code in get_name modifies this object
    ...
};
*/
#include<bits/stdc++.h>
using namespace std;
class Player{
    private:
   string Name;
   int  health;
   int xp;
    public:
    string get_name(){
        return Name;
    }
    void set_name(string name_val){
        Name=name_val;
    }
    Player(string name_val):Player(name_val,0,0){
        cout<<"one args"<<endl;
        cout<<Name<<endl;
    }
    Player(string name_val,int health_val,int xp_val)
    :Name{name_val},health{health_val},xp{xp_val}{
cout<<"Three args"<<endl;
cout<<"Name : "<<Name<<endl;
cout<<"health_val : "<<health<<endl;
cout<<"xp_val"<<xp<<endl;
    }




};



int main()
{
const Player villian {"villian",100,55};
Player hero{"hero",100,515};
}
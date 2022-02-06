/*static class member
*class data member can be declared as static
*A single data member that belongs to the class not the object
useful to store class wide information 
class Function can be declared as static
*Independent of any objects
*can be called using the class name 
**/
/*static data member is only accessible in static member function*/
#include<bits/stdc++.h>
using namespace std;
class Player
{
    private:
    static int num_player;
    string name;
    int health;
    int xp;
    public:
    static int get_num_player();
    string get_name(){
        return name;
    }
    int get_health(){
        return health;
    }
    int get_xp(){
        return xp;
    }
    Player(string name_val="none",int health_val=0,int xp_val=0)
    { name=name_val;
    health=health_val;
    xp=xp_val;
    ++num_player;

    }
    Player(const Player &source)
    {
      name=source.name;
      health=source.health;
      xp=source.health;
    }
    ~Player(){
        --num_player;
    }
};
int Player::num_player{0};
int Player::get_num_player(){
    return num_player;
}
void display_active_player(){
    cout<<"Active Player : "<<Player::get_num_player()<<endl;
}
int main()
{
    Player hero{"hero"};
    display_active_player();
    return 0;
}
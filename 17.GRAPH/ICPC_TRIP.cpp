/*

               ICPC Trip
               (using Dijhkstra Algorithm)


                 (T5,P4)            (T6,P5)        (T11,P6)
    (Amritsar)---------------(Jaipur)-------(pune)--------(Goa)
        \                  /                  |              |
         \                /                   |              |
          \              /(T2,P6)             |              |(T13,P12)
           \ (T3,P8)    /                     |              |
            \          / (7,14)       (T6,P3) |    (T8,P9)   |
               (Delhi)--------(Bhopal)-----(Mumbai)-------- (Amritapuri)
                                |                               |       
                                |                               |
                                |-------------------------------|

Minimize the Total Fare 
U can Take Atmost 1 Flight in Your Trip
atleast 0 flight
atleast 1 flight
    (Train)     (plane)       (Train)
(0)-----------x.............y------------Dest
S1
ans={
   (case1):when You take Atmost 1 flight
   dist is take as money
 minimum for x and y      {
          apply reverse dikjstra dist["x"]+flightcost(x,y)+dist2[y]
               src--->x               x---->y         y-->dest 
      }
Case2: when You Take no flight
 apply reverse dikjstra dist["Dest"]

}


*/
#include<bits/stdc++.h>
using namespace std;

int main(){

return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
static int i=5;
if(--i){
    main();
    printf("%d",i);

}
return 0;
}
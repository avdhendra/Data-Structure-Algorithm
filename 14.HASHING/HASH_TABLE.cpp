/*
1. To support insertion deletion and search in 
   average-case constant time

2. Assumming ordering of element is irrelevant



** Hash function
hash["string key"] ==> Integer value

ex A["burger"]==> 100  (price)

**
array that we use in hash table is dynamic we can change it size according to
need(but the size if fixed)

//Array element indexed by a key which is mapped to and array index
(0 to tablesize -1)

**


*** Key component 
*Hash function 
*Hash Table 
*Collision Handling Scheme


**Hash Table -> Burger - 120
                 |
                 |
                 ---> Hash function- (int) --> search that (int) in array as index
                                                     |
                                                     |
and store that element with pair in that array   <---

*/


/*
**operation 
Insert -A[h(key)]=value  menu['burger]=120

Delete -A[h(key)]=NULL  menu['burger']=NULL

Search- return A[h(key)] return menu['burger'] (value)


*/
/*

**Hash function
collison cannot be avoided but its chances can be reduced
using a good hash function


**what good hash function need

*reduced chance of collision -Distribute keys uniformly over table
**Should be fast compute



*/

/*
note the Things

1. that integer index must lie in range of table array ex-(x%20)

2. collision has happen when two or more integer index genrate by 
hash function have same value    


(so how we handle it)




** Hash Function example

simple hash function
 Simple Hash Function (assume integer Keys)

 h[key]=key%tableSize
 for random key h() distribute key evenly over table
 *what if table size =100 and key are all multiple of 10(collision chance is great here)


 *Better if table Size is a prime number(17,11,19) it will make less collision





*/



/*
How to handle String
"abcd" take there ascii value
abcd = 97+98+99+100=394
h["abcd"]=394% table size


problem :
Anagrams will maps to same index
h["abcd"]=h["bcda"] there index collide

and also if the string is small they may not take 
whole size of table so some part of memory is wasted


**So Lets try something else
*Treat first 3 character of string as base 27 integer
it can be any number but it should be prime number

key=S[0]+(27*S[1])+(27^2*S[2])%table size


but in english some string prefix is same ex- bat,batman

Another Attempt

*use All N character of string as an N digit base k number

choose K to be prime number larger than number of different digits

K=29,31,37

batman =(b+37*a+37^2*t+37^3*m..)%TableSize

*/

/*
**collision handle technique

1. Open hashing-Seperate Chaining

2. Closed Hashing -Open Addressing
                  -Linear Probing
                  -Quadratic Probing

3.Double Hashing
 

*/



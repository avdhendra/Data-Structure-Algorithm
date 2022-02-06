/*

a b c
d e f
g h i


prefix sum matrix

column wise

a a+b a+b+c
d d+e d+e+f
g g+h g+h+i



row wise

a     a+b      a+b+c
a+d   a+b+d+e  a+b+c+d+e+f
g+a+d g+h+a+b+d+e a+b+c+d+e+f+g+h+i


top left =a+b+d+e
bottom right =a+b+c+d+e+f+g+h+i
Br-tl= c+f+g+h+i
is the sum of that submatrix







*/
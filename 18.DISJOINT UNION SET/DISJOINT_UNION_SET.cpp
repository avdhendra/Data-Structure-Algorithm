/*
Disjoin_Union_Set


A disjoint-set data structure is a data structure 
that keeps track of a set of elements partitioned 
into a number of disjoint (non-overlapping) subsets.
A union-find algorithm is an algorithm that performs

two useful operations on such a data structure:

Find: Determine which subset a particular 
element is in. This can be used for determining 
if two elements are in the same subset.

Union: Join two subsets into a single subset.
disjoint is Non overlapping

S1 : 1,2,3,4

S2 : 5,6,7

S3 : 8,9 

this operation return set
Find(8) ---->S3
Find(6) ---->S2

this operation merge two set into one
union(S2,S3)->{5,6,7,8,9}
Union(6,8) -->merge Those two Set in which 6 and 8 is Present

Goal is to Implement Union and Find funtion
timeComplexity
O(N) (first do this)->Union and Find
 |
 | by Optimisation 
 |
 |
 V
O(1) -->Path Compression,Union by Rank


*/
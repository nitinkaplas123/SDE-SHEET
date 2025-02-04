Given a random array our task is to make the array as minHeap.

arr[]=>  [10,5,20,2,4,8].
output-> [2,4,8,5,10,20].

Draw it its follow min heap.


Steps-:
1)calling minHeapify from the index. 
  where index=bottom_most + right_most +internalNode.   -> this is the last index which has childrens at left and right.

How to calculate it ?

size=11 
last element index is -> (size-1).
now call its parent -> ((size-1)-1)/2.  

Index=(size-2)/2.  -> 4.

2) if i=4.
   we call minHeapify(4) now all the children of it is minHeapify.

then i=3. 
(all make minHeapify).

similarily going till i=0.


Time->O(Nlog(N)) which n is the index of bottom most right most -> which calls minHeapify which takes O(log(n)) -> O(nlog(n))
Code-:
#include <bits/stdc++.h> 
using namespace std; 

class MinHeap{
    int *arr;
    int size;
    int capacity;
    
    public:
    
    MinHeap(int c){
    size = 0; 
    capacity = c; 
    arr = new int[c];
    }

    int left(int i) { return (2*i + 1); } 
    int right(int i) { return (2*i + 2); } 
    int parent(int i) { return (i-1)/2; } 
    
    void minHeapify(int i) 
    { 
    int lt = left(i); 
    int rt = right(i); 
    int smallest = i; 
    if (lt < size && arr[lt] < arr[i]) 
        smallest = lt; 
    if (rt < size && arr[rt] < arr[smallest]) 
        smallest = rt; 
    if (smallest != i) 
    { 
        swap(arr[i],arr[smallest]); 
        minHeapify(smallest); 
    } 
    }
    
    void buildHeap(){
        for(int i=(size-2)/2;i>=0;i--)
            minHeapify(i);
    }
    
};

int main() 
{ 
    MinHeap h(11);
    return 0;
} 

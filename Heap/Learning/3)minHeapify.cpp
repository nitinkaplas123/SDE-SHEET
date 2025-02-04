1)Min Heapify function is helpful for us to make tree looks like min heap.
2)If at any point its not working fine so we compare with its left and right value.

     10
  5       15

actualIndex=0 -> 10 value.
left=5.
right=15

min-> 5 its index is 1.
which means index!=actualIndex 

1)swap(arr[i],arr[0]) 

     5 
 10       15 
 here actualIndex=1 

This is doing till the curr index will be the min value among its left and right value.


Time->O(log(N))
Space->O(H) -> for recursive callStack.
Code-:
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
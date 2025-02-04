Question-:
1)here we are given min heap and our task is to extract the min value from the heap and delete it from the heap.
2) Make sure after extracting our heap will follows the property of min heap.


Steps-:
1)Swap the first value with last value of heap and then reduce the size of heap by 1.
2)Which makes min value is deleted from the heap.
3)but issue is largest value is at top of heap now.
4)solution for this is call minHeapify function for that.


Time->O(1) + O(log(n)) -> O(log(n)) ->because we are calling minHeapify.
Code-:
int extractMin() 
{ 
    if (size <= 0) 
        return INT_MAX; 
    if (size == 1) 
    { 
        size--; 
        return arr[0]; 
    }  
    swap(arr[0],arr[size-1]);
    size--; 
    minHeapify(0); 
  
    return arr[size]; 
} 




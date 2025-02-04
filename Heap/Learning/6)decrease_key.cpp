1)Here we are given heap and index i and value x. 
our task is to chnage the value at index as x. 

means -> arr[i]=x;

2)Now make sure after changing its follows minHeap.


Steps-:
1)Add the value x at index i.
2)now using insert method we change the values so that its follows minHeap.


Time->O(log(N))
Code-:
void decreaseKey(int i, int x) 
{ 
    arr[i] = x; 
    while (i != 0 && arr[parent(i)] > arr[i]) 
    { 
       swap(arr[i], arr[parent(i)]); 
       i = parent(i); 
    } 
}




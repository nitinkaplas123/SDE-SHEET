https://www.geeksforgeeks.org/problems/heap-sort/1 

1)If we want to sort the array in increasing order -> use Max Heap.
2)If in decreasing order => use Min Heap.

eg, [4,1,3,9,7]
Steps-:
1)Convert the Complete binary tree into  Max heap.
  1. For this convertion -> we are using buildHeap.
  2. Now max element is at the top. its correct position is at last index.
  [9,7,3,1,4]

2)so we we run the loop from n-1 to 1.
  i=4. (i=n-1).
  we know that arr[0] which is top element in maxHeap has the largest value.
  so we swap it will -> swap(arr[i],arr[n-1]).   
  which makes largest element at its correct place.
   [4,7,3,1,9]
  
  but its disturb from the as max heap
  1. first i reduce the size.
  2. call again maxHeapify(0,i) -> where from 0 we have to apply maxHeapify and its size is i which means its reduce from 5 to 4.


Time->O(nlog(n)) 
Space->O(log(n)) -> recursive call stack.

Code-:
void maxHeapify(vector<int>&arr,int i,int n)
{
        int largest=i;
        int left=(2*i+1);
        int right=(2*i+2);
        
        if(left<n and arr[left]>arr[largest])
        largest=left;
        if(right<n and arr[right]>arr[largest])
        largest=right;
        
        if(largest!=i)
        {
            swap(arr[largest],arr[i]);
            maxHeapify(arr,largest,n);
        }
}
void buildMaxHeap(vector<int>&arr,int n)
{
        for(int i=(n-2)/2;i>=0;i--)
        {
            maxHeapify(arr,i,n);
        }
}
void heapSort(vector<int>& arr) {
        int n=arr.size();
        buildMaxHeap(arr,n);
        
        for(int i=n-1;i>=1;i--)
        {
            swap(arr[i],arr[0]);
            maxHeapify(arr,0,i);
        }
}
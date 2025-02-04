Steps-:
1) if the size of the heap is equal to capacity then we cannot insert the value.
2) else 
   1. add the new value at the end of tree or end of the array. 
3) Now min heap means minimum value will be at the top.
   Which means if parent of inserted element is greater it means my inserted value is not at its correct place.
   So we swap with parent value until we are not reach at the root or inserted value>its parent.


Time->O(log(n)) where n is the size of the heap/array.
Code-:
void MinHeap::insertKey(int k) 
{
    if(heap_size==capacity)
    return ;
    heap_size++;
    harr[heap_size-1]=k;
    
    for(int i=heap_size-1;i!=0 && harr[parent(i)]>harr[i];)
    {
        swap(harr[i],harr[parent(i)]);
        i=parent(i);
    }
}
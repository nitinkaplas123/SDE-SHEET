Task-:
1)Here we are given index as i. 
2)Our task is to delete the value at index i.

Take Care-:
1)AFter deleting it should follows the complete binary tree.
2)After deleting it should look like min heap.


For eg. 
At index=3 value we want to delete.

Steps-:
1. DecreaseKey(i,-INT_MIN)
  1)Calling decreaseKey at (index=3, x=-INT_MIN)
  this means first replace the value at index3 as INT_MIN.
  2)By using insert we compare with parent value and if parent is greater then we swap it.
  3)This make INT_MIN as root at top of minHeap.

2. Calling ExtractMin()  
   1. Now my task is to remove the element which is at top which is INT_MIN.
   2. it swap the root or say first index value with last index value and size--.
   3. now call minHeapify at the top so that its follow minHeap property.


Code-:
void deleteKey(int i) 
{ 
        decreaseKey(i, INT_MIN); 
        extractMin(); 
}


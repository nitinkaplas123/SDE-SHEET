Solution 1-:
Steps-:
1)Compare the element of array from starting with last element
  if(arr[start]>arr[last])
  count++


Code-: Time->O(N)
int findKRotation(int arr[], int n) {
	    int count=0;
	    for(int i=0;i<n-1;i++)
	    {
	        if(arr[i]>arr[n-1])
	        count++;
	        else
	        break;
	    }
	    return count;
	}



Solution 2-:
Steps-:
1)Idea is same as we find the min element in sorted rotated array.
2)where we find the min element so here we return the index of min element which is our starting point of
  sorted array and left side of starting or min element is the elements which is rotated.

eg.

1.[3,4,5,1,2]
here min element is 1 which is at index 3 
means 3 elements are greater than 1 which is at left side so 
3 times its rotated.

2. [1,2,3,4,5]
min element is 1 which is at index 0.

3. [5,1,2,3,4]
min element is 1 which is at index 1 
so 1 is the answer.

Idea-:
while finding the min element every time we update the index of it.

Code-:
int findKRotation(int arr[], int n) {
	   int ans=INT_MAX;
	   int low=0;
	   int high=n-1;
	   int index=-1;
	   while(low<=high)
	   {
	       int mid=(low+high)/2;
	       if(arr[low]<=arr[mid])
	       {
	          if(ans>arr[low])
	          {
	              ans=arr[low];
	              index=low;
	          }
	          low=mid+1;
	       }
	       else
	       {
	           if(ans>arr[mid+1])
	           {
	               ans=arr[mid+1];
	               index=mid+1;
	           }
	           high=mid;
	       }
	   }
	   return index;
	}



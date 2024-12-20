Solution 1-:
Steps-:
1)Corner case -:
  1. when n==1                   return 0
  2. when arr[0]>arr[1]          return 0
  3. when arr[n-1]>arr[n-2]      return n-1
2) rest cases we checked using for loop

Code-: Time->O(N)
int findPeakElement(vector<int>& nums) {
       int n=nums.size();
       if(n==1) return 0;
       for(int i=0;i<n;i++)
       {
           if((i==0 || nums[i]>nums[i-1]) and (i==n-1 || nums[i]>nums[i+1]))
           return i;
       }
       return -1;
}


Solution 2-: Using binary search
It should be observed that the given array is not sorted but there we use binary search


Steps-:
1)Here low=0 high=n-1
2)finding mid 
  1. if we need (mid==0 || nums[mid]>nums[mid-1])  and (mid==n-1 || nums[mid]>nums[mid+1])
     then mid is the peak element 
  2. if mid>0 and nums[mid-1]>nums[mid]
     which means left side we have peak element
  3. else  mid<n-1  and nums[mid]<nums[mid+1]
     means right side we have peak element

Note -:
nums[i]!=nums[i+1]

Code-: Time->O(logN)  
int findPeakElement(vector<int>& nums)
{
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if((mid==0 || nums[mid]>nums[mid-1]) && 
                (mid==n-1 || nums[mid]>nums[mid+1]))
            return mid;
            else if(mid>0 and nums[mid]<nums[mid-1])
            high=mid-1;
            else
            low=mid+1;
        }
        return -1;
}

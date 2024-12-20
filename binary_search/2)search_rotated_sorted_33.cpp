Solution 1-:
Steps-:
1)using normal traversal

Code-: Time->O(N)
int search(vector<int>& nums, int target) 
{
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            return i;
        }
        return -1;
}


Solution 2-:
Steps-:
1)Here we know that given array is sorted at pivot means we can use binary search.
2)There are 3 cases-:
  1)If arr[mid]==target
    return mid;

  2)If left half is sorted (arr[mid]>=arr[low])
    if(target>=arr[low] and target<=arr[mid]) //means here our target is present then go to left side
    high=mid-1;
    else   //means here our target is not present  then go to right side
    low=mid+1

  3)If right half is sorted
    if(target>=arr[mid] and target<=arr[high])
    low=mid+1;
    else
    high=mid-1;
    

Code-: Time->O(logn)

 int search(vector<int>& nums, int target) {
        int n=nums.size();
       
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            return mid;
            else if(nums[low]<=nums[mid])
            {
                if(target>=nums[low] and target<=nums[mid])
                high=mid;
                else
                low=mid+1;
            }
            else
            {
                if(target>=nums[mid+1] and target<=nums[high])
                low=mid+1;
                else
                high=mid;
            }
        }
        return -1;
    }
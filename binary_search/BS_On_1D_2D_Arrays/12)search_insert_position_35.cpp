Solution 1-:
Steps-:
1)Using binary search

Code-:
int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            return mid;
            else if(nums[mid]>target)
            high=mid-1;
            else
            {
                ans=mid+1;
                low=mid+1;
            }
        }
        return ans;
    }
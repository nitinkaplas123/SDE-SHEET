Code-:
vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>v;
        int n=nums.size();

        int low=0;
        int high=n-1;
        int first=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
              first=mid;
              high=mid-1;
            }
            else if(nums[mid]<target)
            low=mid+1;
            else
            high=mid-1;
        }
        
        low=0;
        high=n-1;
        int second=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
              second=mid;
              low=mid+1;
            }
            else if(nums[mid]<target)
            low=mid+1;
            else
            high=mid-1;
        }
        return {first,second};
    }
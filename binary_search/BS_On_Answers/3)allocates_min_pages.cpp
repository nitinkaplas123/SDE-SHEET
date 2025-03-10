https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

Code-:
bool helper(vector<int>&nums,int k,int target)
{
        int val=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            val+=nums[i];
            if(val>target)
            {
                count++;
                val=nums[i];
            }
        }
        return (count<=k);
}
int findPages(vector<int> &nums, int k) {
        int n=nums.size();
        if(k>n) return -1;
        int maxxVal=nums[0];
        int sum=nums[0];

        for(int i=1;i<n;i++)
        {
            maxxVal=max(maxxVal,nums[i]);
            sum+=nums[i];
        }

        int low=maxxVal;
        int high=sum;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(helper(nums,k,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
}
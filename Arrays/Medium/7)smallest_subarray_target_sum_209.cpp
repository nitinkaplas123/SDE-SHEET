Solution 1:

Code:
int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();

        int low=0;
        int high=0;
        int sum=0;
        int ans=INT_MAX;
        while(high<n)
        {
           sum+=nums[high];
           while(sum>=target)
           {
               ans=min(ans,high-low+1);
               sum-=nums[low++];
           }
           high++;
        }
        return (ans==INT_MAX)?0:ans;
}
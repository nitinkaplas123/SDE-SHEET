Solution 1-:
Steps:
1)Same idea as previous questions.


Time->O(N)
Space ->O(K)
Code-:
long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();

        unordered_map<int,int>m;
        long long sum=0;
        int low=0;
        int high=0;
        while(high<n)
        {
            sum+=nums[high];
            m[nums[high]]++;
            high++;

            if(high>=k)
            {
               if(m.size()==k)
               ans=max(ans,sum);

               m[nums[low]]--;
               sum-=nums[low];
              
               if(m[nums[low]]==0)
               m.erase(nums[low]);

               low++;
            }
        }
        return ans;
}
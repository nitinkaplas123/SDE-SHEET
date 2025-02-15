Solution 1-:
Steps-:
1)all possible.

Code-:
int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;

        for(int i=0;i<n;i++)
        {
            int val=1;
            for(int j=i;j<n;j++)
            {
                val*=nums[j];
                ans=max(ans,val);
            }
        }
        return ans;
}



Solution 2-:
Steps-:
1)using kadane algo 

Time->O(N)
Space->O(1)
Code-:
int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int mini=nums[0];
        int maxi=nums[0];

        for(int i=1;i<n;i++)
        {
            if(nums[i]<0)
            {
                int temp=mini;
                mini=maxi;
                maxi=temp;
            }

            mini=min(mini*nums[i],nums[i]);
            maxi=max(maxi*nums[i],nums[i]);

            ans=max(ans,maxi);
        }
        return ans;
}
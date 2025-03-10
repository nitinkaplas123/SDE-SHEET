Solution 1-:
Steps-:
1)Using 2 for loop outer loop run n-k times.
2)Inner loop run k times if len=k stores the nums[j] in ans vector.



Code-: Time->O(N*K)
vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>ans(n-k+1,-1);
        if(k==1)
        return nums;
        int i=0;
        
        for(int i=0;i<=n-k;i++)
        {
            int j=i+1;
            while(j<n and (nums[j]==nums[j-1]+1))
            {
                int len=j-i+1;
                if(len==k)
                {
                   ans[i]=nums[j];
                   break;
                }
                else
                {
                    j++;
                }
            }
        }
        return ans;
}


Solution 2-:

Steps-:
1)Run the loop and do dry run.
Code-:  Time->O(N)
vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        if(k==1) return nums;
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1]==1)
            count++;
            else
            count=1;

            if(i+1>=k)
            {
                if(count>=k)
                ans.push_back(nums[i]);
                else
                ans.push_back(-1);
            }
        }
        return ans;
}
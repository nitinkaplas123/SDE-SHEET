Explantion -: Check notebook -> java

Solution 1:

Steps:
1)Using recursion 

Code:
int helper(vector<int>&nums,int i,int j)
{
        if(i>j) return 0;
        int ans=INT_MIN;
        for(int k=i;k<=j;k++)
        {
            int coins=nums[k]*nums[i-1]*nums[j+1];
            int left=helper(nums,i,k-1);
            int right=helper(nums,k+1,j);
            ans=max(ans,coins+left+right);
        }
        return ans;
}
int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return helper(nums,1,n);
}


Solution 2: 
Steps:
1)using memo 


Code-:Time -> O(N^3)
      Space ->O(N^2)
int helper(vector<vector<int>>&memo,vector<int>&nums,int i,int j)
{
        if(i>j) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int ans=INT_MIN;
        for(int k=i;k<=j;k++)
        {
            int coins=nums[k]*nums[i-1]*nums[j+1];
            int left=helper(memo,nums,i,k-1);
            int right=helper(memo,nums,k+1,j);
            ans=max(ans,coins+left+right);
        }
        return memo[i][j]=ans;
}
int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>memo(n+2,vector<int>(n+2,-1));
        return helper(memo,nums,1,n);
}



Solution 3:

Steps:
1)Using tabulation 

Time -> O(N^3)
Space ->O(N^2)

Code:
int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        // return helper(memo,nums,1,n);

        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=n;j++)
            {
                if(i>j) continue;
                int ans=INT_MIN;
                for(int k=i;k<=j;k++)
                {
                   int coins=nums[k]*nums[i-1]*nums[j+1];
                   int left=dp[i][k-1];
                   int right=dp[k+1][j];
                   ans=max(ans,coins+left+right);
                 }
                 dp[i][j]=ans;
            }
        }
        return dp[1][n];
}
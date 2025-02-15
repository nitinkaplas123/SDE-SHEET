Solution 1-:
Steps-:
1)Using recursion.
2)max we have i*i<=target. we cannot go beyond.



Code-:
int helper(int target)
{
        if(target==0)
        return 0;
        //if(target<0) return 1e9;
        int ans=INT_MAX;
        for(int i=1;i*i<=target;i++)
        {
            ans = min(ans, 1 + helper(target - i * i));
        }
        return ans;
}
int numSquares(int n) {
        int ans=helper(n);
        return (ans==1e9)?-1:ans;
}


Solution 2-:
Steps-:
1)using memo 

Time->O(N * sqrt(N))
Code-:
int helper(int memo[10001],int target)
{
        if(target==0)
        return 0;
        if(memo[target]!=-1) return memo[target];
        int ans=INT_MAX;
        for(int i=1;i*i<=target;i++)
        {
            ans = min(ans, 1 + helper(memo,target - i * i));
        }
        return memo[target]=ans;
}
int numSquares(int n) {
        int memo[10001];
        memset(memo,-1,sizeof(memo));
        int ans=helper(memo,n);
        return ans;
}



Solution 3-:
Steps-:
1)Tabulation.

Time->O(N*sqrt(N))
Code-:
int numSquares(int n) 
{
    vector<int>dp(n+1);
    for(int i=1;i<=n;i++)
    {
        int ans=INT_MAX;
        for(int j=1;j*j<=i;j++)
        {
            ans=min(ans,1+dp[i-j*j]);
        }
        dp[i]=ans;
    }
    return dp[n];
}
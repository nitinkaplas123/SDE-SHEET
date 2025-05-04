Solution 1: 
Steps:
1)Using same idea of palindrome partitioning.
2)Find the maxx element. 
3)find total no. of elements in subarray) * maxxElement + f(i+1,n).
4)store the maxx sum value in ans variable.


Time -> O(2^N)
Code: 
int helper(vector<int>& arr,int k,int index,int n)
{ 
    if(index==n) return 0;
    int maxx=INT_MIN;
    int ans=0;
    for(int i=index;i<n && i<index+k;i++)
    {
        maxx=max(maxx,arr[i]);
        int sum=(maxx*(i-index+1)) + helper(arr,k,i+1,n);
        ans=max(ans,sum);
    }
    return ans;
}
int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n=arr.size();
    return helper(arr,k,0,n);
}


Solution 2:
Steps: 
1)Using memo array.

Code:
int helper(int memo[501],vector<int>& arr,int k,int index,int n)
{ 
    if(index==n) return 0;
    if(memo[index]!=-1) return memo[index];

    int maxx=INT_MIN;
    int ans=0;
    for(int i=index;i<n && i<index+k;i++)
    {
        maxx=max(maxx,arr[i]);
        int sum=(maxx*(i-index+1)) + helper(memo,arr,k,i+1,n);
        ans=max(ans,sum);
    }
    return memo[index]=ans;
}
int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n=arr.size();
    int memo[501];
    memset(memo,-1,sizeof(memo));
    return helper(memo,arr,k,0,n);
}



Solution 3:

Steps:
1)Using tabulation 

Code: 
Time  ->  O(N*k)
Space ->  O(N)
int maxSumAfterPartitioning(vector<int>& arr, int k) 
{
    int n=arr.size();
    // int memo[501];
    // memset(memo,-1,sizeof(memo));
    // return helper(memo,arr,k,0,n);
    vector<int>dp(n+1,0);

    for(int i=n-1;i>=0;i--)
    {
        int maxx=INT_MIN;
        int ans=0;
        for(int j=i;j<n && j<i+k;j++)
        {
            maxx=max(maxx,arr[j]);
            int sum=(maxx*(j-i+1)) + dp[j+1];
            ans=max(ans,sum);
        }
        dp[i]=ans;
    }
    return dp[0];
}
Solution 1-:
Steps-:
1)Same idea as previous.


Code-:
int helper(vector<int>&arr,int k,int n)
{
        if(n==0 || n==1) return 0;
        if(n==2) return abs(arr[1]-arr[0]);
        
        int ans=INT_MAX;
        for(int i=1;i<=k;i++)
        {
            if(n-i<=0) 
            break;
            int val=abs(arr[n-1]-arr[n-1-i]) + helper(arr,k,n-i);
            ans=min(ans,val);
        }
        return ans;
}
int minimizeCost(int k, vector<int>& arr) {
        int n=arr.size();
        return helper(arr,k,n);
}




Solution 2-:
Steps-:
1)using memo 

int helper(int memo[101][10001],vector<int>&arr,int k,int n)
{
        if(n==0 || n==1) return 0;
        if(n==2) return abs(arr[1]-arr[0]);
        if(memo[k][n]!=-1) return memo[k][n];
        
        int ans=INT_MAX;
        for(int i=1;i<=k;i++)
        {
            if(n-i<=0) 
            break;
            int val=abs(arr[n-1]-arr[n-1-i]) + helper(memo,arr,k,n-i);
            ans=min(ans,val);
        }
        return memo[k][n]=ans;
}
int minimizeCost(int k, vector<int>& arr) {
        int n=arr.size();
        int memo[101][10001];
        memset(memo,-1,sizeof(memo));
        return helper(memo,arr,k,n);
}


Solution 3-:
Steps-:
1)using tabulation 

Code-:
int minimizeCost(int k, vector<int>& arr) 
{
        int n=arr.size();
        vector<int>dp(n+1,0);
        for(int i=2;i<=n;i++)
        {
            int ans=INT_MAX;
            for(int j=1;j<=k;j++)
            {
                if(i-j<=0) break;
                int val=abs(arr[i-1]-arr[i-1-j]) + dp[i-j];
                ans=min(ans,val);
            }
            dp[i]=ans;
        }
        return dp[n];
}
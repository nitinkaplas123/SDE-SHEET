https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem

Solution 1-:
int perfectSum(int arr[], int n, int sum)
{
        if(n==0)
        {
            if(sum==0)
            return 1;
            else
            return 0;
        }
        else if(sum>=arr[n-1])
        return perfectSum(arr,n-1,sum-arr[n-1]) + perfectSum(arr,n-1,sum);
        else
        return perfectSum(arr,n-1,sum);
}

Solution 2-:

Code-:
int mod=1e9+7;
int helper(int memo[1001][1001],int arr[], int sum,int n)
{
        if(n==0)
        {
            if(sum==0) return 1;
            else
            return 0;
        }
        
        if(memo[n][sum]!=-1) return memo[n][sum];
        
        int res;
        if(sum>=arr[n-1])
        res= helper(memo,arr,sum-arr[n-1],n-1)%mod + helper(memo,arr,sum,n-1)%mod;
        else
        res= helper(memo,arr,sum,n-1)%mod;
        return memo[n][sum]=res%mod;
}

int perfectSum(int arr[], int n, int sum)
{
        int memo[1001][1001];
        memset(memo,-1,sizeof(memo));
        return helper(memo,arr,sum,n);
}
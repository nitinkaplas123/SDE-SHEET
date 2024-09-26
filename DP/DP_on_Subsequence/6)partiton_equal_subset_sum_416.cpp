Solution 
Steps-:
1)if sum is odd we cannot split into two equal half
2)if sum is even may be pass (sum/2) to subset sum problem code.

Code-:
bool helper(int memo[101][10001],int arr[], int sum,int n)
{
        if(sum==0) return 1;
        if(n==0) return 0;
        
        if(memo[n][sum]!=-1) return memo[n][sum];
        
        int res;
        if(sum>=arr[n-1])
        res= helper(memo,arr,sum-arr[n-1],n-1) || helper(memo,arr,sum,n-1);
        else
        res= helper(memo,arr,sum,n-1);
        return memo[n][sum]=res;
}

bool isSubsetSum(int arr[], int sum,int n)
{
        int memo[101][10001];
        memset(memo,-1,sizeof(memo));
        return helper(memo,arr,sum,n);
}

int equalPartition(int N, int arr[])
{
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        
        if(sum%2!=0) return 0;
        else
        return isSubsetSum(arr,sum/2,N);
}
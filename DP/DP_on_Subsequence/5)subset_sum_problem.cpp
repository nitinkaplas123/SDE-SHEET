https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

Solution 1-:
Code-:
bool helper(vector<int>arr, int sum,int n)
{
        if(n==0)
        {
            if(sum==0) return 1;
            else return 0;
        }
        
        if(sum>=arr[n-1])
        return helper(arr,sum-arr[n-1],n-1) || helper(arr,sum,n-1);
        else
        return helper(arr,sum,n-1);
}

bool isSubsetSum(vector<int>arr, int sum)
{
        int n=arr.size();
        return helper(arr,sum,n);
}



Solution 2-:
Code-:
bool helper(int memo[101][10001],vector<int>arr, int sum,int n)
{
        if(n==0)
        {
            if(sum==0)
            return 1;
            else
            return 0;
        }
        
        if(memo[n][sum]!=-1) return memo[n][sum];
        
        int res;
        if(sum>=arr[n-1])
        res= helper(memo,arr,sum-arr[n-1],n-1) || helper(memo,arr,sum,n-1);
        else
        res= helper(memo,arr,sum,n-1);
        return memo[n][sum]=res;
}

bool isSubsetSum(vector<int>arr, int sum)
{
        int n=arr.size();
        int memo[101][10001];
        memset(memo,-1,sizeof(memo));
        return helper(memo,arr,sum,n);
}
https://www.geeksforgeeks.org/problems/rod-cutting0840/1

Solution 1-:
Steps-:
1)using recursion 
2)we want rod is length=n (sum=n)
3)infinite number of value.
4)if sum==0 || n==0 (we cannot do anything).


int helper(int price[],int n,int sum)
{
        if(n==0 || sum==0) return 0;
        if(sum>=n)
        return max(price[n-1]+helper(price,n,sum-n),
                              helper(price,n-1,sum));
        else
        return helper(price,n-1,sum);
}

int cutRod(int price[], int n) 
{
        return helper(price,n,n);
}


Solution 2-:
Steps-:
1)Memo 
Time->O(N^2)   Space->O(N^2)
int helper(int memo[1001][1001],int price[],int n,int sum)
{
        if(n==0 || sum==0) return 0;
        
        if(memo[n][sum]!=-1) return memo[n][sum];
        int res;
        if(sum>=n)
        res= max(price[n-1]+helper(memo,price,n,sum-n),
                              helper(memo,price,n-1,sum));
        else
        res= helper(memo,price,n-1,sum);
        return memo[n][sum]=res;
}

int cutRod(int price[], int n) 
{
        int memo[1001][1001];
        memset(memo,-1,sizeof(memo));
        return helper(memo,price,n,n);
}


Solution 3-:  Time->O(N^2) Space->O(N)
Steps-:

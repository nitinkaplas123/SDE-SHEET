
1)Fractional knapsack.   -> Greedy 
2)0/1 knapsack           -> 0 means add kro and 1 means add kro (multiple occurence not allowed)
3)unbounded knapsack     -> (multiple occurence of same value allowed)


Solution 1-:
Steps-:
using recursion

Code-:
int helper(int wt[],int val[],int W,int n)
{
        if(W==0 || n==0) return 0;
        if(W>=wt[n-1])
        return max(val[n-1] +helper(wt,val,W-wt[n-1],n-1),helper(wt,val,W,n-1));
        else
        return helper(wt,val,W,n-1);
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
        return helper(wt,val,W,n);
}


Solution 2-:
Using memo

Code-:
int helper(int memo[1001][1001],int wt[],int val[],int W,int n)
{
        if(W==0 || n==0) return 0;
        
        if(memo[n][W]!=-1) return memo[n][W];
        
        int res;
        if(W>=wt[n-1])
        res= max(val[n-1] +helper(memo,wt,val,W-wt[n-1],n-1),
                             helper(memo,wt,val,W,n-1));
        else
        res= helper(memo,wt,val,W,n-1);
        return memo[n][W]=res;
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
        int memo[1001][1001];
        memset(memo,-1,sizeof(memo));
        return helper(memo,wt,val,W,n);
}
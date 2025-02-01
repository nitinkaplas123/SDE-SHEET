Solution 0-:
Steps-:
1)using recursion. 


Code-:
int helper(int n)
{
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        else
        return helper(n-1) + helper(n-2) + helper(n-3);
}
int tribonacci(int n) {
        return helper(n);
}


Soluton 1.1-:
1)using memo 

Code-:
int helper(int memo[38],int n)
{
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        if(memo[n]!=-1) return memo[n];
        else
        return memo[n]=helper(memo,n-1) + helper(memo,n-2) + helper(memo,n-3);
}
int tribonacci(int n) {
        int memo[38];
        memset(memo,-1,sizeof(memo));
        return helper(memo,n);
}



Solution 1-:
Steps-:
1)same as fibonacci series 

Time->O(N)
Space->O(N)
Code-:
int tribonacci(int n) {
        if(n==0 || n==1)
        return n;
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++)
        {
            dp[i]=(dp[i-1]+dp[i-2]+dp[i-3]);
        }
        return dp[n];
}


Solution 2-:
Code-:
int tribonacci(int n) {
        if(n==0 || n==1)
        return n;
        
        int a=0;
        int b=1;
        int c=1;
        for(int i=3;i<=n;i++)
        {
            int d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return c;
}